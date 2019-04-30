#ifndef _CY_THREAD_H
#define _CY_THREAD_H
#include <pthread.h>

#include "common.h"

class CYThread{
	private:
		pthread_t *thd_;
		int *thd_state_;
		uint thd_size_;
	
	public:
		CYThread(){};
		CYThread(uint _size);
		CYThread(const CYThread& _th);
		~CYThread();

		int Create(uint _idx, void *(*_func)(void*), void *_argc, void *_attr=NULL); 
		int Join(uint _idx, char **_ret=NULL);
		void Exit(uint _idx, const void *_ret);
		bool IsAlive(uint _idx);

		CYThread& operator=(const CYThread &T);
};
#endif
