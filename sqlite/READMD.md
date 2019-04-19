SQLite Module Class

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
