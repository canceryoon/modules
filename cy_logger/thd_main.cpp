#include <iostream>
#include <stdlib.h>

#include "cy_thread.h"

using namespace std;

CYThread thd = CYThread(2);
const char *msg = {"THD1 END"};

void *_func1(void *_data)
{
	cout << (char*)_data << endl;
	thd.Exit(0, msg);
}

void *_func2(void *_data)
{
	cout << (char*)_data << endl;
}

int main()
{
	char *retval;
	int ret = 0;
	ret = thd.Create(0, _func1, (void*)"THD1" );
	ret = thd.Create(1, _func2, (void*)"THD2" );

	ret = thd.Join(1);
	ret = thd.Join(0, &retval);
	
	std::cout << "THD 1 Join: " << retval << std::endl;
	std::cout << "[END]" << std::endl;
	return 1;
}

