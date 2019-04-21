#include <iostream>
#include <string.h>

#include "cy_queue.h"

using namespace std;
int main()
{
	char arr[][7] = { { "DATA 1" }, { "DATA 2" } };
	int len = strlen(arr[0]);
	
	CYQueue cyq(3, (void*)arr[0], len);
	printf("INSERT");
	cyq.InsertQueue((void*)arr[1], len);
	
	printf("INSERT");
	cyq.PrintQueue();

	return 1;
}