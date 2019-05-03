#include <iostream>
#include <pthread.h>

#include <unistd.h>

#include "cy_logger.h"
#include "cy_threadManager.h"

using namespace std;
int main()
{
	unsigned int thd_size = 2;
	unsigned int queue_size = 10;
	pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

	string msg1 = "TEST THD 1";
	string msg2 = "TEST THD 2";

	CYLogger logger(thd_size, mutex, queue_size);
	cout << "Set Push" << endl;
	logger.SetPushThd(0, (void*)msg1.c_str());
	cout << "Set Pop" << endl;
	logger.SetPopThd(1, (void*)msg2.c_str());

	sleep(3);

	cout << "[END PROGRAM]" << endl;
	return 1;
}
