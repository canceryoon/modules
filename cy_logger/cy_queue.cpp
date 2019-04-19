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
	cy_queue *dummy;
	while(q_->next != q_&& q_ != q_->parent)
	{
		dummy = q_;
		q_ = dummy->next;
		q_->parent = dummy->parent;
		FreeCyqueue(dummy);
		used_size_--;
	}
	FreeCyqueue(q_);
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
		printf("%d : [%s]\n", cnt++, tmp->qdata->data);
		tmp = tmp->next;
	}
	printf("%d : [%s]\n", cnt++, tmp->qdata->data);
}
