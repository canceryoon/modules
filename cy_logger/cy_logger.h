#ifndef _CY_LOGGER_H
#define _CY_LOGGER_H
#include <iostream>
#include <pthread.h>

#include "common.h"
#include "cy_threadManager.h"
#include "cy_queue.h"

typedef struct _cy_log_data{
	CYQueue *cyq;
	char *msg;
}cy_log_data;

class CYLogger{
	private:
		CYThreadManager thd_;

	public:
		CYLogger(){};
		CYLogger(uint _thd_cnt, pthread_mutex_t _mutex, uint _queue_size);
		~CYLogger(){};

		void SetPushThd(uint _thd_idx, void *(*_func)(void*), void *_argc, void *_attr=NULL);
		void SetPopThd(uint _thd_idx, void *(*_func)(void*), void *_argc, void *_attr=NULL);
		bool ThdIsAlive(uint _idx);
};

void* PushMessage(void *_argc);
void* PopMessage(void *_argc);
#endif
