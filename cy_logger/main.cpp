#include <iostream>
#include <string.h>

#include "cy_queue.h"

using namespace std;
int main()
{
	char arr[][7] = { { "DATA 1" }, { "DATA 2" }, {"DATA 3"} };
	int len = strlen(arr[0]);
	
	printf("CREATE\n");
	CYQueue cyq(3, (void*)arr[0], len);

	printf("INSERT\n");
	cyq.PushQueue((void*)arr[1], len);
	cyq.PushQueue((void*)arr[2], len);
	
	printf("PRINT\n");
	cyq.PrintQueue();

	printf("POP\n");
	size_t pop_len;
	char *pop_data = static_cast<char*>(cyq.PopQueue(&pop_len));
	printf("pop data: [%d][%s]\n", pop_len, pop_data);

	printf("PRINT\n");
	cyq.PrintQueue();

	return 1;
}
