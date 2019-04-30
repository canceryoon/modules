#include <pthread.h>

#include "common.h"

class CYThread{
	private:
		pthread_t *thd_;
		int *thd_state_;
		uint thd_size_;
	
	public:
		CYThread(uint _size);
		~CYThread();

		int ThreadCreate(uint _idx, void *(*_func)(void*), void *_argc, void *_attr=NULL); 
		int ThreadJoin(uint _idx, char **_ret=NULL);
		void ThreadExit(uint _idx, const void *_ret);
		bool IsThreadAlive(uint _idx);
};

/*
class CYThreadManager{
	private:
		CYThread thread_;
		uint thread_size_;
		pthread_mutex_t mutex_;

	public:
		CYThreadManager(uint _thread_size, pthread_mutex_t _mutex);
		~CYThreadManager();
		
		int ThreadCreate(uint _idx, void *_func, void *_argc, void *_attr=NULL);
		int ThreadJoin(uint _idx, void *_ret=NULL);
		void ThreadExit(uint _idx, void *_ret);

		int Lock();
		int TryLock();
		int Unlock();
		//int LockDestroy();
};
*/
