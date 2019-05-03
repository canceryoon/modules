#include <iostream>

#include "cy_logger.h"

static void* PushMessage(void *_argc)
{
	std::cout << "Push Message Function : " << (char*)_argc << std::endl;
}

static void* PopMessage(void *_argc)
{
	std::cout << "Pop Message Function : "  << (char*)_argc << std::endl;
}

CYLogger::CYLogger(uint _thd_cnt, pthread_mutex_t _mutex, uint _queue_size)
{
	CYQueue qu = CYQueue(_queue_size);
	queue_ = qu;

	CYThreadManager tm = CYThreadManager(_thd_cnt, _mutex);
	thd_ = tm;
}

void CYLogger::SetPushThd(uint _thd_idx, void *_argc, void *_attr)
{
	int ret = thd_.ThreadCreate(_thd_idx, PushMessage, _argc, _attr);
	if( 0 != ret )
		std::cout << "[ERR][CYLogger::SetThd] Fail: " << ret << std::endl;
	
}

void CYLogger::SetPopThd(uint _thd_idx, void *_argc, void *_attr)
{
	int ret = thd_.ThreadCreate(_thd_idx, PopMessage, _argc, _attr);
	if( 0 != ret )
		std::cout << "[ERR][CYLogger::SetThd] Fail: " << ret << std::endl;
	
}
