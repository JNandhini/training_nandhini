#include "Database.h"
#include "Database.h"
#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

　
using namespace std;

Database::Database()
{

	sqlConnHandle = NULL;
	sqlStmtHandle = NULL;
	
	SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle);
	SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);
	SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle);

	cout << "Attempting connection to SQL Server...";
	cout << "\n";

	if (SQLDriverConnect(sqlConnHandle,
		NULL,
		(SQLWCHAR*)L"DRIVER={SQL Server};SERVER=IN11W-TRAINEE-1\\SQLEXPRESS, 49326;DATABASE=Musicplayer;Trusted=true;",
		SQL_NTS,
		retconstring,
		1024,
		NULL,
		SQL_DRIVER_NOPROMPT))
	{
		cout << "connected successfully";
	}

}

Database::~Database()
{
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLDisconnect(sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);
	cout << "\nPress any key to exit...";
	getchar();
}
void Database::display_songs()
{
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);

	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"select * from dbo.Song  inner join  dbo.Artist  on dbo.Song.ArtistId=dbo.Artist.ArtistId inner join dbo.Album on dbo.Song.AlbumId=dbo.Album.AlbumId ", SQL_NTS))
	{
		cout << "Error querying SQL Server";
		cout << "\n";

	}
	else
	{
		SQLCHAR sqlVersion[SQL_RESULT_LEN];
		SQLINTEGER ptrSqlVersion;

		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {

			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
			cout << "SongId=" << sqlVersion << endl;
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
			cout << "SongName=" << sqlVersion << endl;
			SQLGetData(sqlStmtHandle, 6, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		    cout << "Artistiid=" << sqlVersion << endl;
			SQLGetData(sqlStmtHandle, 8, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
			cout << "AlbumId=" << sqlVersion << endl;
		}

	}
	
}
void Database::display_artists()
{
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLCHAR sqlVersion[SQL_RESULT_LEN];
	SQLINTEGER ptrSqlVersion;
	char value[90];
	char compare[90];
	char compare1[90];
	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"select * from dbo.Artist  inner join  dbo.Song  on dbo.Song.ArtistId=dbo.Artist.ArtistId inner join dbo.Artistsong on dbo.Song.Id=dbo.Artistsong.Songid ", SQL_NTS))
	{
		cout << "Error querying SQL Server";
		cout << "\n";

	}
	else
	{
		

		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {

			
			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
			//cout << "artistId=" << sqlVersion << endl;
			strcpy_s(value,(char*)sqlVersion);
			if (strcmp(value ,compare) != 0)
			{
				cout << "artistId=" << sqlVersion << endl;
				strcpy_s(compare, (char*)sqlVersion);
			}
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
			strcpy_s(value, (char*)sqlVersion);
			if (strcmp(compare1, value) != 0)
			{
				cout << "ArtistName=" << sqlVersion << endl;
				strcpy_s(compare1, (char*)sqlVersion);
			}
			SQLGetData(sqlStmtHandle, 4, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
			cout << "Songname=" << sqlVersion << endl;
			
		}

	}

}
void Database::display_albums()
{
	int AlbumYear = 0;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);

	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"select * from dbo.Album  inner join  dbo.Song  on dbo.Song.AlbumId=dbo.Album.AlbumId inner join dbo.Albumsong on dbo.Song.Id=dbo.Albumsong.SongId ", SQL_NTS))
	{
		cout << "Error querying SQL Server";
		cout << "\n";

	}
	else
	{
		SQLCHAR sqlVersion[SQL_RESULT_LEN];
		SQLINTEGER ptrSqlVersion;

		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {

			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
			strcpy_s(value, (char*)sqlVersion);
			if (strcmp(value, compare) != 0)
			{
				cout << "AlbumId=" << sqlVersion << endl;
				strcpy_s(compare, (char*)sqlVersion);
			}
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
			strcpy_s(value, (char*)sqlVersion);
			if (strcmp(compare1, value) != 0)
			{
				cout << "AlbumName=" << sqlVersion << endl;
				strcpy_s(compare1, (char*)sqlVersion);
			}
			
			SQLGetData(sqlStmtHandle, 3, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
			year = (int)sqlVersion;
			if (year != AlbumYear)			{
				cout << "Albumyear=" << sqlVersion << endl;
				AlbumYear = (int)sqlVersion;
			}
			SQLGetData(sqlStmtHandle, 5, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
			cout << "songname=" << sqlVersion << endl;
		}

	}

}
void Database::display_playlists()
{
	char value[90];
	char compare[90];
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);

	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"select *from dbo.Playlist inner join  dbo.Playlistsong on dbo.Playlist.PlaylistId=dbo.Playlistsong.PlaylistId inner join dbo.Song on dbo.Playlistsong.SongId=dbo.Song.Id", SQL_NTS))
	{
		cout << "Error querying SQL Server";
		cout << "\n";

	}
	else
	{
		SQLCHAR sqlVersion[SQL_RESULT_LEN];
		SQLINTEGER ptrSqlVersion;

		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {

			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
			strcpy_s(value, (char*)sqlVersion);
			if (strcmp(value, compare) != 0)
			{
				cout << "PlaylistId=" << sqlVersion << endl;
				strcpy_s(compare, (char*)sqlVersion);
			}
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
			strcpy_s(value, (char*)sqlVersion);
			if (strcmp(compare1, value) != 0)
			{
				cout << "PlaylistName=" << sqlVersion << endl;
				strcpy_s(compare1, (char*)sqlVersion);
			}
			SQLGetData(sqlStmtHandle, 6, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
			cout << "Songname=" << sqlVersion << endl;
			
		}

	}

}
void Database::insert_songs()
{
	
	char Songname[90];
	char SongId[90];
	char ArtistId[90];
	char AlbumId[90];	
	char Id[90];
	char name[90];
	char artist[90];
	char album[90];
	cout << "Enter the Song id";
	cin >> Id;
	cout << "Enter the Song name";
	//cin.ignore();
	cin >> name;
	cout << "Enter the artistid";
	cin >> artist;
	cout << "Enter the albumid";
	cin >> album;
	SQLINTEGER SongItId = SQL_NTS;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);

	SQLPrepare(sqlStmtHandle,L"INSERT INTO Song(Id,Songname,ArtistId,AlbumId) VALUES(?,?,?,?)", SQL_NTS);
	
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &SongId, 0,&SongItId);

    SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &Songname,0,&SongItId);

	SQLBindParameter(sqlStmtHandle, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &ArtistId, 0, &SongItId);

	SQLBindParameter(sqlStmtHandle, 4, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &AlbumId, 0, &SongItId);
	strcpy_s(SongId, Id);
	strcpy_s(Songname, name);
	strcpy_s(ArtistId, artist);
	strcpy_s(AlbumId, album);
	insert_artists();
	SQLExecute(sqlStmtHandle);
	while (SQLExecute(sqlStmtHandle) == SQL_SUCCESS)
	{
		cout << "";
	}/*
	SQLWCHAR *stmt = L"insert into Song(Id,Songname,ArtistId,AlbumId) values('song9','SongName','artist1','album1')";
	

retcode = SQLExecDirect(sqlStmtHandle,stmt , SQL_NTS);
	/*if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) 
	{
		cout<<"Insert data OK!!. SQL was:\n\n\n\n";
	}
	

	
	else if (retcode!=SQL_SUCCESS)
	{
		cout << SQL_ERROR;
	}*/
}
void Database::insert_artists()
{
	char Artistname[90];
	char ArtistId[90];
	char SongId[90];
	char AlbumId[90];
	char Id[90];
	char name[90];
	char song[90];
	SQLHANDLE sqlStmtHandle1;
 sqlStmtHandle1=NULL;
	cout << "Enter the Song id";
	cin >> Id;
	cout << "Enter the Song name";
	//cin.ignore();
	cin >> name;
	cout << "Enter the songid";
	cin >> song;
	
	SQLINTEGER SongItId = SQL_NTS;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);

	SQLPrepare(sqlStmtHandle, L"INSERT INTO Artist(ArtistId,Artistname) VALUES(?,?)", SQL_NTS);
	SQLPrepare(sqlStmtHandle1, L"INSERT INTO Artistsong(ArtistId,SongId) VALUES(?,?)", SQL_NTS);

	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &ArtistId, 0, &SongItId);

	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &Artistname, 0, &SongItId);

	SQLBindParameter(sqlStmtHandle1, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &ArtistId, 0, &SongItId);

	SQLBindParameter(sqlStmtHandle1, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &SongId, 0, &SongItId);
	strcpy_s(ArtistId, Id);
	strcpy_s(Artistname, name);
	strcpy_s(ArtistId, Id);
	strcpy_s(SongId, song);
	SQLExecute(sqlStmtHandle);
	SQLExecute(sqlStmtHandle1);
	while (SQLExecute(sqlStmtHandle) == SQL_SUCCESS)
	{
		cout << "";
	}
}
void Database::insert_playlists()
{
	char PlaylistName[90];
	char PlaylistId[90];
	char SongId[90];
	char Id[90];
	char name[90];
	char song[90];
	char album[90];
	int num;
	cout << "Enter the Song name";
	//cin.ignore();
	cin >> name;
	cout << "Enter the artistid";
	cin >> song;

	SQLINTEGER SongItId = SQL_NTS;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);

	SQLPrepare(sqlStmtHandle, L"INSERT INTO Playlist(PlaylistId,PlaylistName) VALUES(?,?)", SQL_NTS);

	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &PlaylistId, 0, &SongItId);

	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &PlaylistName, 0, &SongItId);

//	SQLBindParameter(sqlStmtHandle, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &SongId, 0, &SongItId);
	strcpy_s(PlaylistId, Id);
	strcpy_s(PlaylistName, name);
//	strcpy_s(SongId, song);
	
	SQLExecute(sqlStmtHandle);
	while (SQLExecute(sqlStmtHandle) == SQL_SUCCESS)
	{
		cout << "";
	}
}
void Database::search_songs()
{
	char Songname[90];
	char name[90];
	cout << "Enter the songname";
	cin >> name;
	SQLINTEGER SongItId = SQL_NTS;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, L"select Song.Id,Song.SongName,Artist.ArtistName,Album.AlbumName from dbo.Song  inner join  dbo.Artist  on dbo.Song.ArtistId=dbo.Artist.ArtistId inner join dbo.Album on dbo.Song.AlbumId=dbo.Album.AlbumId  where Songname='?", SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &Songname, 0, &SongItId);
	strcpy_s(Songname, name);

	SQLExecute(sqlStmtHandle);
	    while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {

		SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		cout << "SongId=" << sqlVersion << endl;
		SQLGetData(sqlStmtHandle, 2, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		cout << "SongName=" << sqlVersion << endl;
		SQLGetData(sqlStmtHandle, 6, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		cout << "Artistname=" << sqlVersion << endl;
		SQLGetData(sqlStmtHandle, 8, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		cout << "Albumname=" << sqlVersion << endl;

　
	}

	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
	{
		cout << "Successfully inserted:\n\n\n\n";
	}
}

void Database::search_artists()
{
	char Artistname[90];
	char name[90];
	cout << "Enter the Artistname";
	cin>>name;
	SQLINTEGER SongItId = SQL_NTS;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, L"select  Artist.ArtistId,Artist.ArtistName,Song.Songname  from dbo.Artist  inner join  dbo.Song  on dbo.Song.ArtistId=dbo.Artist.ArtistId inner join dbo.Artistsong on dbo.Song.Id=dbo.Artistsong.Songid where ArtistName=?", SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &Artistname, 0, &SongItId);
	strcpy_s(Artistname,name);
	
	SQLExecute(sqlStmtHandle);
//	SQLWCHAR *stmt = L"select * from dbo.Artist  inner join  dbo.Song  on dbo.Song.ArtistId=dbo.Artist.ArtistId inner join dbo.Artistsong on dbo.Song.Id=dbo.Artistsong.Songid where ArtistName=?";

　
//	retcode = SQLExecDirect(sqlStmtHandle, stmt, SQL_NTS);
	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {

		SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);

		strcpy_s(value, (char*)sqlVersion);
		if (strcmp(value, compare) != 0)
		{
			cout << "artistId=" << sqlVersion << endl;
			strcpy_s(compare, (char*)sqlVersion);
		}
		SQLGetData(sqlStmtHandle, 2, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		strcpy_s(value, (char*)sqlVersion);
		if (strcmp(compare1, value) != 0)
		{
			cout << "ArtistName=" << sqlVersion << endl;
			strcpy_s(compare1, (char*)sqlVersion);
		}
		SQLGetData(sqlStmtHandle, 3, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		cout << "Songname=" << sqlVersion << endl;

　
	}

	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
	{
		cout << "";
	}
}

void Database::search_albums()
{
	int AlbumYear = 0;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);

	SQLWCHAR *stmt = L"select * from dbo.Album  inner join  dbo.Song  on dbo.Song.AlbumId=dbo.Album.AlbumId inner join dbo.Albumsong on dbo.Song.Id=dbo.Albumsong.SongId where AlbumName='Devotional'";

　
	retcode = SQLExecDirect(sqlStmtHandle, stmt, SQL_NTS);
	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {

		
			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		strcpy_s(value, (char*)sqlVersion);
		if (strcmp(value, compare) != 0)
		{
			cout << "AlbumId=" << sqlVersion << endl;
			strcpy_s(compare, (char*)sqlVersion);
		}
		SQLGetData(sqlStmtHandle, 2, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		strcpy_s(value, (char*)sqlVersion);
		if (strcmp(compare1, value) != 0)
		{
			cout << "AlbumName=" << sqlVersion << endl;
			strcpy_s(compare1, (char*)sqlVersion);
		}

		SQLGetData(sqlStmtHandle, 3, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		year = (int)sqlVersion;
		if (year != AlbumYear)			{
			cout << "Albumyear=" << sqlVersion << endl;
			AlbumYear = (int)sqlVersion;
		}
		SQLGetData(sqlStmtHandle, 5, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		cout << "songname=" << sqlVersion << endl;
		
	}

	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
	{
		cout << "";
	}
}

void Database::search_playlists()
{
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);

	SQLWCHAR *stmt = L"select *from dbo.Playlist inner join  dbo.Playlistsong on dbo.Playlist.PlaylistId=dbo.Playlistsong.PlaylistId inner join dbo.Song on dbo.Playlistsong.SongId=dbo.Song.Id where PlaylistName='playlist'";

　
	retcode = SQLExecDirect(sqlStmtHandle, stmt, SQL_NTS);
	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
		SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		strcpy_s(value, (char*)sqlVersion);
		if (strcmp(value, compare) != 0)
		{
			cout << "PlaylistId=" << sqlVersion << endl;
			strcpy_s(compare, (char*)sqlVersion);
		}
		SQLGetData(sqlStmtHandle, 2, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		strcpy_s(value, (char*)sqlVersion);
		if (strcmp(compare1, value) != 0)
		{
			cout << "PlaylistName=" << sqlVersion << endl;
			strcpy_s(compare1, (char*)sqlVersion);
		}
		SQLGetData(sqlStmtHandle, 6, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		cout << "Songname=" << sqlVersion << endl;
	}

	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
	{
		cout << "";
	}
}

void Database::update_songs()
{ 
	char name[90];
	char id[90];
	char SongId[90];
	char Songname[90];
	cout << "Enter the id";
	cin >> id;
	cout << "Enter the songname";
	cin >> name;
	SQLINTEGER song=SQL_NTS;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, L"UPDATE Song SET Songname=? WHERE Id=?",SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR,50,0,&SongId,0,&song);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR,50,0,&Songname,0,&song);
	strcpy_s(SongId, id);
	strcpy_s(Songname, name);
//	SQLWCHAR *stmt = L"update Song set Songname='Vinayagane' where Id='song1'";
	SQLExecute(sqlStmtHandle);

	//retcode = SQLExecDirect(sqlStmtHandle, stmt, SQL_NTS);
	if (SQLExecute(sqlStmtHandle) == SQL_SUCCESS || SQLExecute(sqlStmtHandle) == SQL_SUCCESS_WITH_INFO)
	{
		cout << "Successfully updates\n";
	}
}
void Database::update_artists()
{
	char name[90];
	char id[90]; 
	char ArtistId[90];
	char Artistname[90];
	cout << "Enter the id";
	cin >> id;
	cout << "Enter the artistname";
	cin >> name;
	SQLINTEGER song = SQL_NTS;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, L"UPDATE Artist SET ArtistName=? WHERE ArtistId=?", SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &ArtistId, 0, &song);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &Artistname, 0, &song);
	strcpy_s(ArtistId, id);
	strcpy_s(Artistname, name);
	SQLExecute(sqlStmtHandle); 
	if (SQLExecute(sqlStmtHandle) == SQL_SUCCESS || SQLExecute(sqlStmtHandle) == SQL_SUCCESS_WITH_INFO)
	{
		cout << "Successfully updated";
	}
}
void Database::update_albums()
{
	char name[90];
	char id[90];
	char AlbumId[90];
	char Albumname[90];
	cout << "Enter the id";
	cin >> id;
	cout << "Enter the albumname";
	cin >> name;
	SQLINTEGER song = SQL_NTS;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, L"UPDATE Album SET AlbumName=? WHERE AlbumId=?", SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &AlbumId, 0, &song);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &Albumname, 0, &song);
	strcpy_s(AlbumId, id);
	strcpy_s(Albumname, name);
	SQLExecute(sqlStmtHandle);
	if (SQLExecute(sqlStmtHandle) == SQL_SUCCESS || SQLExecute(sqlStmtHandle) == SQL_SUCCESS_WITH_INFO)
	{
		cout << "Successfully updated";
	}
	//SQLWCHAR *stmt = L"update Album set Albumname='album' where AlbumId='album1'";

　
	//retcode = SQLExecDirect(sqlStmtHandle, stmt, SQL_NTS);
	//if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
	//{
		//cout << "Successfully upfdated\n";
	//}
}
void Database::update_playlists()
{
	char name[90];
	char id[90];
	char PlaylistId[90];
	char     Playlistname[90];
	cout << "Enter the id";
	cin >> id;
	cout << "Enter the playlistname";
	cin >> name;
	SQLINTEGER song = SQL_NTS;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, L"UPDATE Playlist SET Playlistname=? WHERE PlaylistId=?", SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT_OUTPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &PlaylistId, 0, &song);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT_OUTPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &Playlistname, 0, &song);
	strcpy_s(PlaylistId, id);
	strcpy_s(Playlistname, name);
	SQLExecute(sqlStmtHandle);
	if (SQLExecute(sqlStmtHandle) == SQL_SUCCESS || SQLExecute(sqlStmtHandle) == SQL_SUCCESS_WITH_INFO)
	{
		cout << "Successfully updated";
	}
	
	//SQLWCHAR *stmt = L"update Playlist set Playlistname='playlistname' where PlaylistId='playlist1'";

　
//	retcode = SQLExecDirect(sqlStmtHandle, stmt, SQL_NTS);
	//if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
	//{
		//cout << "Successfully updated\n";
	//}
}
void Database::delete_songs_data()
{

	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	char Songname[90];
	char name[90];
	SQLINTEGER song = SQL_NTS;
	cout << "Enter the Songname";
	cin>> name;
	int flag = 0;
	SQLWCHAR *stmt = L"select Songname from Song";
	

		retcode = SQLExecDirect(sqlStmtHandle, stmt, SQL_NTS);

		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {

			

			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
			cout << sqlVersion;
			strcpy_s(value, (char*)sqlVersion);
			if (strcmp(value, name) == 0)
			{
				SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
				SQLPrepare(sqlStmtHandle, L"delete from Song where Songname=?", SQL_NTS);
				SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT_OUTPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &Songname, 0, &song);
				strcpy_s(Songname, name);
				SQLExecute(sqlStmtHandle);
				flag = 1;
			}
			
			
		}
		if (flag == 0)
		{
			cout << "the data is not in the database";
		}
	
		if (SQLExecute(sqlStmtHandle) == SQL_SUCCESS || SQLExecute(sqlStmtHandle)== SQL_SUCCESS_WITH_INFO)
	{
		cout << "Successfully deleted\n";
	}
}
void Database::delete_artists_data()
{
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	char Artistname[90];
	char name[90];
	SQLINTEGER song = SQL_NTS;
	cout << "Enter the Artistname";
	cin >> name;
	int flag = 0;
	SQLWCHAR *stmt = L"select ArtistName from Artist";

　
	retcode = SQLExecDirect(sqlStmtHandle, stmt, SQL_NTS);

	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {

　
　
		SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		cout << sqlVersion;
		strcpy_s(value, (char*)sqlVersion);
		if (strcmp(value, name) == 0)
		{
			SQLPrepare(sqlStmtHandle, L"delete from Artist where ArtistName=?", SQL_NTS);
			SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT_OUTPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &Artistname, 0, &song);
			strcpy_s(Artistname, name);
			SQLExecute(sqlStmtHandle);
			flag = 1;
		}

　
	}
	if (flag == 0)
	{
		cout << "the data is not in the database";
	}

	if (SQLExecute(sqlStmtHandle) == SQL_SUCCESS || SQLExecute(sqlStmtHandle) == SQL_SUCCESS_WITH_INFO)
	{
		cout << "Successfully deleted\n";
	}
	
}
void Database::delete_albums_data()
{

	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	char Albumname[90];
	char name[90];
	SQLINTEGER song = SQL_NTS;
	cout << "Enter the albumname";
	cin >> name;
	int flag = 0;
	SQLWCHAR *stmt = L"select AlbumName from Album";

　
	retcode = SQLExecDirect(sqlStmtHandle, stmt, SQL_NTS);

	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {

　
　
		SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		cout << sqlVersion;
		strcpy_s(value, (char*)sqlVersion);
		if (strcmp(value, name) == 0)
		{
			SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
			SQLPrepare(sqlStmtHandle, L"delete from Album where AlbumName=?", SQL_NTS);
			SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT_OUTPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &Albumname, 0, &song);
			strcpy_s(Albumname, name);
			SQLExecute(sqlStmtHandle);
			flag = 1;
		}

　
	}
	if (flag == 0)
	{
		cout << "the data is not in the database";
	}

	if (SQLExecute(sqlStmtHandle) == SQL_SUCCESS || SQLExecute(sqlStmtHandle) == SQL_SUCCESS_WITH_INFO)
	{
		cout << "Successfully deleted\n";
	}
	
}

void Database::delete_playlists_data()
{
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	char PlaylistName[90];
	char name[90];
	SQLINTEGER song = SQL_NTS;
	cout << "Enter the Playlistame";
	cin >> name;
	int flag = 0;
	SQLWCHAR *stmt = L"select PlaylistName from Playlist";

　
	retcode = SQLExecDirect(sqlStmtHandle, stmt, SQL_NTS);

	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {

　
　
		SQLGetData(sqlStmtHandle, 2, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		cout << sqlVersion;
		strcpy_s(value, (char*)sqlVersion);
		if (strcmp(value, name) == 0)
		{
			SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
			SQLPrepare(sqlStmtHandle, L"delete from Playlist where PlaylistName=?", SQL_NTS);
			SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT_OUTPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &PlaylistName, 0, &song);
			strcpy_s(PlaylistName, name);
			SQLExecute(sqlStmtHandle);
			flag = 1;
		}

　
	}
	if (flag == 0)
	{
		cout << "the data is not in the database";
	}

	if (SQLExecute(sqlStmtHandle) == SQL_SUCCESS || SQLExecute(sqlStmtHandle) == SQL_SUCCESS_WITH_INFO)
	{
		cout << "Successfully deleted\n";
	}

　
}
