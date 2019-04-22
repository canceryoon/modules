#include <stdio.h>

#include "common.h"

typedef struct _cy_data{
	size_t data_size;
	void *data;
}cy_data;

typedef struct _cy_queue{
	cy_data *qdata;
	_cy_queue *next;
	_cy_queue *parent;
}cy_queue;


class CYQueue{
private:
	uint total_size_;
	int used_size_;
	cy_queue *q_; //head

protected:
	void FreeCyqueue(cy_queue *rm);
	void FreeCydata(cy_data *rm);

public:
	CYQueue(uint _total_size): total_size_(_total_size), used_size_(0){q_ = NULL;}
	CYQueue(uint _total_size, void *_data, size_t _data_len);

	~CYQueue();
	
	void PushQueue(void* _data, size_t _data_len);
	void PrintQueue();
	//CYQueue(uint _total_size, cy_queue *_data)
};
