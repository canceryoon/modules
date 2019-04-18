#include <iostream>
#include "cy_sqlite.h"

using namespace std;

#define CREATE_TABLE "create table t1(c2 text, c3 integer)"
#define INSERT_TABLE "insert into t1 values('asdfasdf', 1)"
#define SELECT_TABLE "select * from t1"

int main()
{
  CY_SQLITE cydb;

	char* _name = (char*)"cy_test.db";
	cydb._open_db(_name);
	cout << cydb._print_status() << endl;

	cydb._execute_db((char*)CREATE_TABLE);
	cout << cydb._print_status() << endl;

	cydb._execute_db((char*)INSERT_TABLE);
	cout << cydb._print_status() << endl;

	cydb._execute_db((char*)SELECT_TABLE);
	cout << cydb._print_status() << endl;

	cydb._close_db();
	cout << cydb._print_status() << endl;
	cout << cydb._print_status() << endl;

	return 1;
}
