#include <iostream>
#include <stdlib.h>

#include "cy_thread.h"

using namespace std;

CYThread thd = CYThread(2);
const char *msg = {"THD1 END"};

void *_func1(void *_data)
{
	cout << (char*)_data << endl;
	thd.ThreadExit(0, msg);
}

void *_func2(void *_data)
{
	cout << (char*)_data << endl;
}

int main()
{
	char *retval;
	int ret = 0;
	ret = thd.ThreadCreate(0, _func1, (void*)"THD1" );
	ret = thd.ThreadCreate(1, _func2, (void*)"THD2" );

	ret = thd.ThreadJoin(1);
	ret = thd.ThreadJoin(0, &retval);
	
	std::cout << "THD 1 Join: " << retval << std::endl;
	std::cout << "[END]" << std::endl;
	return 1;
}

