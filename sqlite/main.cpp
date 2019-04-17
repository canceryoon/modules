#include <iostream>
#include "cy_sqlite.h"

using namespace std;

int main()
{
  CY_SQLITE cydb;

	char* _name = (char*)"cy_test.db";
	cydb._open_db(_name);
	cout << cydb.err << endl;

	cydb._close_db();
	cout << cydb.err << endl;

	return 1;
}
