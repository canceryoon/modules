#include "cy_sqlite.h"

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	int i;
	for (i = 0; i < argc; i++)
	{
		cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << "\n";
	}
	cout << "\n";
	return 0;
}

CY_SQLITE::CY_SQLITE(char* db_name)
{
	if (_open_db(db_name))
	{
		
	}
}

CY_SQLITE::~CY_SQLITE()
{
	sqlite3_close(_cy_sqlite);
}

int CY_SQLITE::_open_db(char* db_name)
{
	int ret = sqlite3_open(db_name, &_cy_sqlite);
	if (ret)
	{
		err = (char*)sqlite3_errmsg(_cy_sqlite);
		return 0;
	}
	err = (char*)CY_DB_OPEN_SUCCESS;
	return 1;
}

int CY_SQLITE::_close_db()
{
	int ret = sqlite3_close(_cy_sqlite);
	if (ret)
	{
		err = (char*)sqlite3_errmsg(_cy_sqlite);
		return 0;
	}
	err = (char*)CY_DB_CLOSE_SUCCESS;
	return 1;
}

int CY_SQLITE::_execute_db(char* query)
{
	char *sqlErr;
	int ret = sqlite3_exec(_cy_sqlite, query, callback, 0, &sqlErr);
	if (ret)
	{
		err = (char*)sqlite3_errmsg(_cy_sqlite);
		sqlite3_free(sqlErr);
		return 0;
	}
	err = (char*)CY_DB_QUERY_SUCCESS;
	return 1;
}

const char* CY_SQLITE::_print_status()
{
	const char* rErr = err;
	err = (char*)"None";
	return rErr; 
}
