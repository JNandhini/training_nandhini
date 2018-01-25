#pragma once
#include <iostream>
#include<Windows.h>
#include<string>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>

using namespace std;
class Database
{
public:
#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1000

	SQLHANDLE sqlConnHandle;
	SQLHANDLE sqlStmtHandle;
	//SQLHANDLE sqlStmtHandle1;
	SQLHANDLE sqlEnvHandle;
	//SQLHANDLE DBCHandle;
	SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];
	SQLHSTMT hstmt = SQL_NULL_HSTMT;
	RETCODE retcode;
	SQLCHAR sqlVersion[SQL_RESULT_LEN];
	SQLINTEGER ptrSqlVersion;
	char value[90];
	char compare[90];
	char compare1[90];
	int year=0;
public:
	Database();
	~Database();
	void insert_songs();
	void insert_playlists();
	void display_songs();
	void display_artists();
	void display_albums();
	void display_playlists();
	void search_songs();
	void search_artists();
	void search_albums();
	void search_playlists();
	void update_songs();
	void update_artists();
	void update_albums();
	void update_playlists();
	void delete_data();
	
};
