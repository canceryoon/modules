#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cy_queue.h"


CYQueue::CYQueue(uint _total_size, void *_data, size_t _data_len)
{
	total_size_ = _total_size;

	cy_data *dummy = (cy_data*)malloc(sizeof(cy_data));
	dummy->data = _data;
	dummy->data_size = _data_len;

	q_ = (cy_queue*)malloc(sizeof(cy_queue));
	q_->qdata = dummy;
	q_->next = q_;
	q_->parent = q_;

	used_size_++;
}

CYQueue::~CYQueue()
{
	printf("Destructor\n");
	cy_queue *dummy;
	while(q_->next != q_&& q_ != q_->parent)
	{
		dummy = q_;
		q_ = dummy->next;
		q_->parent = dummy->parent;
		FreeCyqueue(dummy);
		used_size_--;
	}
	printf("End Destructor\n");
	FreeCyqueue(q_);
	printf("End Destructor\n");
}

void CYQueue::FreeCydata(cy_data *rm)
{
	free(rm->data);
	free(rm);
}
void CYQueue::FreeCyqueue(cy_queue *rm)
{
	FreeCydata(rm->qdata);
	free(rm);
}

void CYQueue::InsertQueue(void* _data, size_t _data_len)
{
	cy_queue *newNode = NULL;
	newNode = (cy_queue*)malloc(sizeof(cy_queue));

	newNode->qdata = (cy_data*)malloc(sizeof(cy_data));
	memcpy(newNode->qdata->data, _data, _data_len);
	newNode->qdata->data_size = _data_len;

	cy_queue *head_parent = q_->parent;
	cy_queue *parent_next = q_->parent->next;

	parent_next = newNode;
	newNode->next = q_;
	newNode->parent = head_parent;
}

void CYQueue::PrintQueue()
{
	if(0 == used_size_)
	{
		printf("[CYQUEUE::INFO] Queue is empty.\n");
		return ;
	}

	printf("[CYQUEUE::INFO] Print queue.\n");
	unsigned int cnt = 1;
	cy_queue *tmp = q_;
	while(tmp->next != q_ && q_ != tmp)
	{
		printf("%d : [%s]\n", cnt++, (char*)tmp->qdata->data);
		tmp = tmp->next;
	}
	printf("%d : [%s]\n", cnt++, (char*)tmp->qdata->data);
}
