#ifndef CY_SQLITE_H
#define CY_SQLITE_H

#include <iostream>
#include "sqlite3.h"

using namespace std;

#define CY_DB_INIT_SUCCESS "CY DB INIT SUCCESS"
#define CY_DB_INIT_FAIL "CY DB INIT FAIL"
#define CY_DB_OPEN_SUCCESS "CY DB OPEN SUCCESS"
#define CY_DB_OPEN_FAIL "CY DB OPEN FAIL"
#define CY_DB_CLOSE_SUCCESS "CY DB CLOSE SUCCESS"
#define CY_DB_CLOSE_FAIL "CY DB CLOSE FAIL"
#define CY_DB_QUERY_SUCCESS "CY DB EXECUTE SUCCESS"
#define CY_DB_QUERY_FAIL "CY DB EXECUTE FAIL"


class CY_SQLITE {
private:
	sqlite3 *_cy_sqlite;
	char* err;

public:
	CY_SQLITE() {};
	CY_SQLITE(char* db_name);
	~CY_SQLITE();

	int _open_db(char* db_name);
	int _close_db();
	int _execute_db(char* query);

	const char* _print_status();
};
#endif
