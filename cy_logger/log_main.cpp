#include <iostream>
#include <pthread.h>

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "cy_logger.h"
#include "cy_threadManager.h"

using namespace std;

static CYLogger logger;
static cy_log_data _data;

void pushMsg(char *_msg)
{
	_data.msg = _msg;
	cout << "Set Push" << endl;
	logger.SetPushThd(0, PushMessage, (void*)&_data);
}

void popMsg()
{
	cout << "Set Pop" << endl;
	logger.SetPopThd(1, PopMessage, (void*)&_data);
}

int main()
{
	unsigned int thd_size = 2;
	unsigned int queue_size = 10;
	pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

	const char *msg = "TEST MESSAGE";

  logger = CYLogger(thd_size, mutex, queue_size);
	_data.cyq = new CYQueue(5);

	pushMsg((char*)msg);	
	sleep(1);
	_data.cyq->PrintQueue();
	
	char *out;
	popMsg();
	sleep(1);

	cout << "Pop Queue DATA: [" << _data.msg << "]" << endl;
	_data.cyq->PrintQueue();

	free(_data.cyq);
	cout << "[END PROGRAM]" << endl;
	return 1;
}
