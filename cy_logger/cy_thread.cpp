#include <iostream>
#include <pthread.h>
#include <cstdlib>
#include <string.h>

#include "cy_thread.h"

//CYThread : 
CYThread::CYThread(uint _size)
{
	thd_ = (pthread_t*)malloc(sizeof(pthread_t)*_size);
	thd_state_ = (int*)malloc(sizeof(int)*_size);
	thd_size_ = _size;
}

CYThread::CYThread(const CYThread& _th)
{
	thd_ = _th.thd_;
	thd_state_ = _th.thd_state_;
	thd_size_ = _th.thd_size_;
}

CYThread& CYThread::operator = (const CYThread &T)
{
	thd_ = T.thd_;
	thd_state_ = T.thd_state_;
	thd_size_ = T.thd_size_;

	return *this;
}

CYThread::~CYThread()
{
	free(thd_);	
}

int CYThread::Create(uint _idx, void *(*_func)(void*), void *_argc, void *_attr)
{
	int ret = pthread_create(&thd_[_idx], (const pthread_attr_t*)_attr, _func, _argc);
	if( 0 != ret )
	{
		std::cout << "[ERR][CYThread::ThreadCreate]: " << ret << std::endl;
		return -1;
	}
	thd_state_[_idx] = 1;
	return ret;
}

int CYThread::Join(uint _idx, char **_ret)
{
	void *retval;
	int ret = pthread_join(thd_[_idx], (void**)_ret);
	if( 0 != ret )
	{
		std::cout << "[ERR][CYThread::ThreadJoin:" << _idx << "]: " << ret << std::endl;
		return -1;
	}

	thd_state_[_idx] = 0;
	std::cout << "[INFO][CYThread::ThreadJoin:" << _idx << "]: " << ret << std::endl;

	return ret;
}

void CYThread::Exit(uint _idx, const void *_ret)
{
	pthread_exit((void*)_ret);
}

bool CYThread::IsAlive(uint _idx)
{
	return thd_state_[_idx] == 1 ;
}
