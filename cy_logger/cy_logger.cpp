#include <iostream>
#include <string.h>

#include "cy_logger.h"

void* PushMessage(void *_argc)
{
	cy_log_data *_data = (cy_log_data*)_argc;
	size_t _data_len = strlen(_data->msg);
	_data->cyq->PushQueue((void*)_data->msg, _data_len);
}

void* PopMessage(void *_argc)
{
	cy_log_data *_data = (cy_log_data*)_argc;
	size_t len;
	_data->msg = (char*)_data->cyq->PopQueue(&len);
}

CYLogger::CYLogger(uint _thd_cnt, pthread_mutex_t _mutex, uint _queue_size)
{
	thd_ = CYThreadManager(_thd_cnt, _mutex);
}

void CYLogger::SetPushThd(uint _thd_idx, void *(*_func)(void*), void *_argc, void *_attr)
{
	int ret = thd_.ThreadCreate(_thd_idx, _func, _argc, _attr);
	if( 0 != ret )
		std::cout << "[ERR][CYLogger::SetThd] Fail: " << ret << std::endl;
}

void CYLogger::SetPopThd(uint _thd_idx, void *(*_func)(void*), void *_argc, void *_attr)
{
	int ret = thd_.ThreadCreate(_thd_idx, _func, _argc, _attr);
	if( 0 != ret )
		std::cout << "[ERR][CYLogger::SetThd] Fail: " << ret << std::endl;
}

bool CYLogger::ThdIsAlive(uint _idx)
{
	return thd_.ThreadIsAlive(_idx);
}
