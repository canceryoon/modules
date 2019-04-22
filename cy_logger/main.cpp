#include <iostream>
#include <string.h>

#include "cy_queue.h"

using namespace std;
int main()
{
	char arr[][7] = { { "DATA 1" }, { "DATA 2" } };
	int len = strlen(arr[0]);
	
	printf("CREATE\n");
	CYQueue cyq(3, (void*)arr[0], len);
//	printf("INSERT\n");
//	cyq.InsertQueue((void*)arr[1], len);
	
	printf("PRINT\n");
	cyq.PrintQueue();

	return 1;
}
