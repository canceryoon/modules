#ifndef _CY_LOGGER_H
#define _CY_LOGGER_H
#include <iostream>
#include <pthread.h>

#include "common.h"
#include "cy_threadManager.h"
#include "cy_queue.h"

class CYLogger{
	private:
		CYQueue queue_;
		CYThreadManager thd_;

	public:
		CYLogger(){};
		CYLogger(uint _thd_cnt, pthread_mutex_t _mutex, uint _queue_size);
		~CYLogger(){};

		void SetPushThd(uint _thd_idx, void *_argc, void *_attr=NULL);
		void SetPopThd(uint _thd_idx, void *_argc, void *_attr=NULL);
		//void* PushMessage(void *_argc);
		//void* PopMessage(void *_argc);
};
#endif
