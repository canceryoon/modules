#include <iostream>
#include <string.h>

#include "cy_queue.h"

using namespace std;
int main()
{
	char arr[] = {"DATA 1"};
	int len = strlen(arr);
  CYQueue cyq(3, (void*)arr, len);
	
	cyq.PrintQueue();
	
	return 1;
}
