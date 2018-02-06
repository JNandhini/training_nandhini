#include "Database.h"
#include "Database.h"
#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

　
using namespace std;

// Constructor which allocates handle


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

//Display the details of the songs

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

//Displays the details of the artists

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

//Display the details of the albums

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

//Displays the details of the playlists

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

//Insert the songs

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

	SQLExecute(sqlStmtHandle);
	while (SQLExecute(sqlStmtHandle) == SQL_SUCCESS)
	{
		cout << "Successfully inserted";
	}

}

//Insert the playlist

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

	strcpy_s(PlaylistId, Id);
	strcpy_s(PlaylistName, name);
	
	SQLExecute(sqlStmtHandle);
	while (SQLExecute(sqlStmtHandle) == SQL_SUCCESS)
	{
		cout << "Successfully Inserted";
	}
}

/Searchrs for songs

void Database::search_songs()
{
	char Songname[90];
	char name[90];
	cout << "Enter the songname";
	cin >> name;
	int flag = 0;
	SQLINTEGER SongItId = SQL_NTS;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, L"select *from dbo.Song  inner join  dbo.Artist  on dbo.Song.ArtistId=dbo.Artist.ArtistId inner join dbo.Album on dbo.Song.AlbumId=dbo.Album.AlbumId  where Songname=?", SQL_NTS);
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
		flag = 1;

	}
		if (flag == 0)
		{
			cout << "The searched element is not in database";
		}

	}

//Searches the artists

void Database::search_artists()
{
	char Artistname[90];
	char name[90];
	cout << "Enter the Artistname";
	cin>>name;
	int flag = 1;
	SQLINTEGER SongItId = SQL_NTS;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, L"select  Artist.ArtistId,Artist.ArtistName,Song.Songname  from dbo.Artist  inner join  dbo.Song  on dbo.Song.ArtistId=dbo.Artist.ArtistId inner join dbo.Artistsong on dbo.Song.Id=dbo.Artistsong.Songid where ArtistName=?", SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &Artistname, 0, &SongItId);
	strcpy_s(Artistname,name);
	
	SQLExecute(sqlStmtHandle);
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
		flag = 1;

	}
	if (flag == 0)
	{
		cout << "The searched element is not in database";
	}

	}

//Searches the albums

void Database::search_albums()
{
	int AlbumYear = 0;
	char Albumname[90];
	char name[90];
	int flag = 0;
	cout << "Enter the Albumname";
	cin >> name;
	SQLINTEGER AlbumId = SQL_NTS;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, L"select * from dbo.Album  inner join  dbo.Song  on dbo.Song.AlbumId=dbo.Album.AlbumId inner join dbo.Albumsong on dbo.Song.Id=dbo.Albumsong.SongId where AlbumName=?", SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &Albumname, 0, &AlbumId);
	strcpy_s(Albumname, name);

	SQLExecute(sqlStmtHandle);
	

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
		flag = 1;
		
	}

	if (flag==0)
	{
		cout << "The searched element is not in database";
	}
}

//Searches the playlists

void Database::search_playlists()
{
	int AlbumYear = 0;
	char Playlistname[90];
	char name[90];
	int flag = 0;
	cout << "Enter the playlistname";
	cin >> name;
	SQLINTEGER PlaylistId = SQL_NTS;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, L"select *from dbo.Playlist inner join  dbo.Playlistsong on dbo.Playlist.PlaylistId=dbo.Playlistsong.PlaylistId inner join dbo.Song on dbo.Playlistsong.SongId=dbo.Song.Id where PlaylistName=?", SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &Playlistname, 0, &PlaylistId);
	strcpy_s(Playlistname, name);

	SQLExecute(sqlStmtHandle);

　
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
		flag = 1;
	}

	if (flag == 0)
	{
		cout << "The searched element is not in database";
	}
}

//Updates the aomga

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
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR,50,0,&Songname,0,&song);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR,50,0,&SongId,0,&song);
	strcpy_s(SongId, id);
	strcpy_s(Songname, name);
	SQLExecute(sqlStmtHandle);
	if (SQLExecute(sqlStmtHandle) == SQL_SUCCESS || SQLExecute(sqlStmtHandle) == SQL_SUCCESS_WITH_INFO)
	{
		cout << "Successfully updated\n";
	}
}

//updates the artists

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
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &Artistname, 0, &song);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &ArtistId, 0, &song);
	strcpy_s(ArtistId, id);
	strcpy_s(Artistname, name);
	SQLExecute(sqlStmtHandle); 
	if (SQLExecute(sqlStmtHandle) == SQL_SUCCESS || SQLExecute(sqlStmtHandle) == SQL_SUCCESS_WITH_INFO)
	{
		cout << "Successfully updated";
	}
}

//Updates the albums

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
	SQLPrepare(sqlStmtHandle,L"UPDATE Album SET AlbumName=? WHERE AlbumId=?", SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &Albumname, 0, &song);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &AlbumId, 0, &song);
	strcpy_s(AlbumId, id);
	strcpy_s(Albumname, name);
	SQLExecute(sqlStmtHandle);
	if (SQLExecute(sqlStmtHandle) == SQL_SUCCESS || SQLExecute(sqlStmtHandle) == SQL_SUCCESS_WITH_INFO)
	{
		cout << "Successfully updated";
	}
	}

//Updates the playlists

void Database::update_playlists()
{
	char name[90];
	char name1[90];
	char PlaylistId[90];
	char     Playlistname[90];
	cout << "Enter the playlistname";
	cin >> name;
	cout << "Enter new playlistname";
	cin >> name1;
	SQLINTEGER Playlist = SQL_NTS;
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);

	SQLPrepare(sqlStmtHandle, L"update Playlist set Playlistname=? where Playlistname=?", SQL_NTS);

	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &PlaylistId, 0, &Playlist);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &Playlistname, 0, &Playlist);
	strcpy_s(PlaylistId, name1);
	strcpy_s(Playlistname, name);
	if (SQLExecute(sqlStmtHandle) == SQL_SUCCESS)
	{
		cout << "Successfully updated";
	}
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);

	}
//Deletes the detaila of the songs
	
void Database::delete_data()
{

	char Songname[90];
	char name[90];
	char id[90];
	SQLINTEGER SongId = SQL_NTS;
	cout << "Enter the Songname";
	cin>> name;
	int flag = 0;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);

	SQLWCHAR *stmt = L"select Songname,Id from dbo.Song";
	

		retcode = SQLExecDirect(sqlStmtHandle, stmt, SQL_NTS);

		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {

			
			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);

	
			strcpy_s(value, (char*)sqlVersion);
			if (strcmp(value, name) == 0)
			{
				SQLGetData(sqlStmtHandle, 2, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
				strcpy_s(id, (char*)sqlVersion);

				SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);

				SQLPrepare(sqlStmtHandle, L"DELETE FROM Song WHERE Id=?", SQL_NTS);

				SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &Songname, 0, &SongId);
				strcpy_s(Songname, id);
				if (SQLExecute(sqlStmtHandle)==SQL_SUCCESS)
				{
					cout << "";
				}
				SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);

				SQLPrepare(sqlStmtHandle, L"DELETE FROM Artistsong WHERE Songid=?", SQL_NTS);

				SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &Songname, 0, &SongId);
				strcpy_s(Songname, id);
				if (SQLExecute(sqlStmtHandle))
				{
					cout << "";
				}				
				SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);

				SQLPrepare(sqlStmtHandle, L"DELETE FROM Albumsong WHERE SongId=?", SQL_NTS);

				SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &Songname, 0, &SongId);
				strcpy_s(Songname, id);
				if (SQLExecute(sqlStmtHandle))
				{
					cout << "";
				}	
				SQLPrepare(sqlStmtHandle, L"DELETE FROM Playlistsong WHERE SongId=?", SQL_NTS);

				SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, &Songname, 0, &SongId);
				strcpy_s(Songname, id);
				if (SQLExecute(sqlStmtHandle))
				{
					cout << "";
				}

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
