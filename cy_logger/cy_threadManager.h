#ifndef _CY_THREAD_MANAGER_H
#define _CY_THREAD_MANAGER_H
#include <pthread.h>

#include "common.h"
#include "cy_thread.h"

class CYThreadManager{
	private:
		CYThread thread_;
		uint thread_size_;
		pthread_mutex_t mutex_;

	public:
		CYThreadManager();
		CYThreadManager(uint _thread_size, pthread_mutex_t _mutex);
		~CYThreadManager();
		
		int ThreadCreate(uint _idx, void *(*_func)(void*), void *_argc, void *_attr=NULL);
		int ThreadJoin(uint _idx, char **_ret=NULL);
		bool ThreadExit(uint _idx, void *_ret);

		int Lock();
		int TryLock();
		int UnLock();
		//int LockDestroy();
};
#endif
