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
	cout << cydb.err << endl;

	cydb._execute_db(CREATE_TABLE);
	cout << cydb.err << endl;

	cydb._execute_db(INSERT_TABLE);
	cout << cydb.err << endl;

	cydb._execute_db(SELECT_TABLE);
	cout << cydb.err << endl;

	cydb._close_db();
	cout << cydb.err << endl;

	return 1;
}
