#include <iostream>
#include <pthread.h>

#include "cy_threadManager.h"
#include "cy_thread.h"

CYThreadManager::CYThreadManager(uint _thread_size, pthread_mutex_t _mutex)
{
	thread_ = CYThread(_thread_size);
	thread_size_ = _thread_size;

	mutex_ = _mutex;
//	pthread_mutex_init(&mutex_, NULL);
}

CYThreadManager::~CYThreadManager()
{
	thread_.~CYThread();
	pthread_mutex_destroy(&mutex_);
}

int CYThreadManager::ThreadCreate(uint _idx, void *(*_func)(void*), void *_argc, void *_attr)
{
	if( thread_size_ < _idx )
	{
		std::cout << "[ERR][CYThreadManager::ThreadCreate] _idx is bigger than thread_size_." << std::endl;
		return -2;
	}

	int ret = thread_.Create(_idx, _func, _argc, _attr);
	if( 0 != ret )
		return -1;

	return ret;
}

int CYThreadManager::ThreadJoin(uint _idx, char **_ret)
{
	if( thread_size_ < _idx )
	{
		std::cout << "[ERR][CYThreadManager::ThreadJoin] _idx is bigger than thread_size_." << std::endl;
		return -2;
	}

	int ret = thread_.Join(_idx, _ret);
	if( 0 != ret )
		return -1;

	return ret;
}

bool CYThreadManager::ThreadExit(uint _idx, void *_ret)
{
	if( thread_size_ < _idx )
	{
		std::cout << "[ERR][CYThreadManager::ThreadExit] _idx is bigger than thread_size_." << std::endl;
		return false;
	}

	thread_.Exit(_idx, _ret);

	return true;
}

int CYThreadManager::Lock()
{
	int ret = pthread_mutex_lock(&mutex_);
	if( 0 != ret )
		return ret;

	return 0;
}

int CYThreadManager::UnLock()
{
	int ret = pthread_mutex_unlock(&mutex_);
	if( 0 != ret )
		return ret;

	return 0;
}

int CYThreadManager::TryLock()
{
	int ret = pthread_mutex_trylock(&mutex_);
	if( 0 != ret )
		return ret;

	return 0;
}
