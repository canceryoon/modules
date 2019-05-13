#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cy_queue.h"

CYQueue::CYQueue(uint _total_size):total_size_(_total_size), used_size_(0)
{
	q_ = (cy_queue*)malloc(sizeof(cy_queue));
	q_->qdata = NULL;
	q_->next = NULL;
	q_->parent = NULL;
}

CYQueue::CYQueue(uint _total_size, void *_data, size_t _data_len)
{
	total_size_ = _total_size;

	cy_data *dummy = (cy_data*)malloc(sizeof(cy_data));
	dummy->data = (void*)malloc(sizeof(char)*_data_len);
	memcpy(dummy->data, _data, _data_len);
	dummy->data_size = _data_len;

	q_ = (cy_queue*)malloc(sizeof(cy_queue));
	q_->qdata = dummy;
	q_->next = q_;
	q_->parent = q_;

	used_size_++;
}

CYQueue::~CYQueue()
{
	cy_queue *dummy;
	while((q_->next != q_&& q_ != q_->parent) 
			&&!(q_->next == NULL && q_->qdata == NULL && q_->parent == NULL && used_size_ == 0))
	{
		dummy = q_;
		q_ = dummy->next;
		q_->parent = dummy->parent;
		FreeCyqueue(dummy);
		used_size_--;
	}
	if(!(q_->next == NULL && q_->qdata == NULL && q_->parent == NULL && used_size_ == 0))
		FreeCyqueue(q_);

}

CYQueue& CYQueue::operator = (const CYQueue &T)
{
	this->total_size_ = T.total_size_;
	this->used_size_ = used_size_;
	this->q_ = T.q_;

	return *this;
}

void CYQueue::FreeCydata(cy_data *rm)
{
	free(rm->data);
	free(rm);
}
void CYQueue::FreeCyqueue(cy_queue *rm)
{
	if(q_->next == NULL && q_->qdata == NULL && q_->parent == NULL && used_size_ == 0)
	{
		free(q_);
		return ;
	}
	FreeCydata(rm->qdata);
	free(rm);
}

void CYQueue::PushQueue(void* _data, size_t _data_len)
{
	cy_queue *newNode = NULL;
	newNode = (cy_queue*)malloc(sizeof(cy_queue));

	newNode->qdata = (cy_data*)malloc(sizeof(cy_data));
	newNode->qdata->data = (void*)malloc(sizeof(char)*_data_len);
	memcpy(newNode->qdata->data, _data, _data_len);
	newNode->qdata->data_size = _data_len;


	if( 0 == used_size_ )
	{
		q_=newNode;
		q_->next = q_;
		q_->parent = q_;
	}
	else
	{
		q_->parent->next = newNode;
		q_->parent = newNode;
		newNode->next = q_;
	}

	used_size_++;
}

void *CYQueue::PopQueue(size_t *outLen)
{
	char *data = (char*)malloc(sizeof(char)*q_->qdata->data_size);
	memcpy(data, q_->qdata->data, q_->qdata->data_size);
	*outLen = q_->qdata->data_size;

	cy_queue *_rm = q_;

	q_->parent->next = q_->next;
	q_->next->parent = q_->parent;
	q_ = q_->next;

	FreeCyqueue(_rm);
	used_size_--;

	return (void*)data;
}

void CYQueue::PrintQueue()
{
	if(0 == used_size_)
	{
		printf("[CYQUEUE::INFO] Queue is empty.\n");
		return ;
	}

	printf("[CYQUEUE::INFO] Print queue.\n");
	uint cnt = 1;
	cy_queue *tmp = q_;
	while(tmp->next != q_ && q_ != tmp->parent)
	{
		printf("%d : [%s]\n", cnt++, (char*)tmp->qdata->data);
		tmp = tmp->next;
	}
	printf("%d : [%s]\n", cnt++, (char*)tmp->qdata->data);
}
