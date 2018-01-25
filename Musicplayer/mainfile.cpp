#include<iostream>
#include"Database.h"
#include "musicplayer.h"

　
int main()
{
	musicplayer * music = new musicplayer("./musicplayer.xml");
	Database data;
	char choice;

	while (1)
	{

		cout << "\nXML\na.Insert songs\nb.Insert artists\nc.Insert albums\nd.Insert playlist\ne.Display the songs\nf.Display the artist\ng.Display the albums\nh.Display the playlists\ni.Search_songs\nj.Search artists\nDATABASE\nk.Insert songs in database\nl.Insert playlist in database\nm.Display the songs in database\nn.Display the artist in database\no.Display the albums in database\np.Display the playlists in database\nq.Search songs\nr.search artists\ns.search albums\ntsearch playlists\nu.update songsname\nv.update artistname\nw.update albumname\nx.update playlistname\ny.delete the data\nz.Exit";
		cout << "\nEnter the choice";
		cin >> choice;
	
		switch (choice)
		{
			if (choice == 'a' || choice == 'b' || choice == 'c' || choice == 'd' || choice == 'e' || choice == 'f' || choice == 'g' || choice == 'h' || choice == 'i' || choice == 'j' || choice == 'k' || choice == 'l' || choice == 'm' || choice == 'n' || choice == 'o' || choice == 'p' || choice == 'q' || choice == 'r' || choice == 's' || choice == 't' || choice == 'u' || choice == 'v' || choice == 'w' || choice == 'x')
			{
		case'a':
 		music->insert_songs();
		
			break;
		case 'b':
			music->insert_artist();
		
			break;
		case 'c':
			music->insert_album();
		

			break;
		case 'd':
			music->insert_playlist();
			
			break;
		case 'e':
			music->display_songs();
			break;
		case'f':
			music->display_artist();
			break;
		case 'g':
			music->display_album();
			music->display_compilation_album();
			break;
		case 'h':
			music->display_playlist();
			break;
		case 'i':
			music->search_songs();
			break;
		case 'j':
			music->search_artists();
			break;
		case 'k':
			data.insert_songs();
			break;
		case'l':
			data.insert_playlists();
			break;
		case'm':
			data. display_songs();
			break;
		case'n':
			data. display_artists();
			break;
		case'o':
			data.display_albums();
			break;
		case'p':

			data. display_playlists();
			break;
		case'q':
			data.search_songs();
			break;
		case'r':
			data.search_artists();
			break;
		case's':
			data.search_albums();
			break;
		case't':
			data.search_playlists();
			break;
		case'u':
			data.update_songs();
			break;
		case'v':
			data.update_artists();
			break;
		case'w':
			data.update_albums();
			break;
		case'x':
			data.update_playlists();
			break;
		case'y':
			data.delete_data();
			break;
		case 'z':
			exit(0);
			}
			else
			{
				cout << "Invalid choice";
			}
		}
		
	}

}
