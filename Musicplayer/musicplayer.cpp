#pragma once
#include "musicplayer.h"
XercesDOMParser*   parser = NULL;
 ErrorHandler*      errorHandler = NULL;
 const int ABSOLUTE_PATH_FILENAME_PREFIX_SIZE = 0;

 //constructor which initializes the parser

 musicplayer::musicplayer(const char* file) : document(NULL)
 {
	 if (!parser)
	 {
		 XMLPlatformUtils::Initialize();
		 parser = new XercesDOMParser();
		 parser->parse(file);
		 document = parser->adoptDocument();
	 }
	
	
	 }
 
 //destructor which releases the document 

 musicplayer::~musicplayer()
	  {
	      if (document) document->release();
	  }
 

 //this is used to get the element value

	  string musicplayer::get_value(const char* parentTag, int parentIndex, const char* childTag, int childIndex)
	  {
	  	XMLCh* tag = XMLString::transcode(parentTag);
	  	DOMNodeList* list = document->getElementsByTagName(tag);
	  	XMLString::release(&tag);
		DOMElement* parent = dynamic_cast<DOMElement*>(list->item(parentIndex));
	  	DOMElement* child = dynamic_cast<DOMElement*>(parent->getElementsByTagName(XMLString::transcode(childTag))->item(childIndex));
	  	string value;
	  	if (child)
		{
		  		char* tagname = XMLString::transcode(child->getTextContent());
		  		value = tagname;
		        XMLString::release(&tagname);
		 
	 
		}
	  	else 
		{
		  		value = "";
		}
	return value;
	  }

　
	  //this is used to get the attribute values

	  string musicplayer::get_attribute(const char* parentTag, int parentIndex, const char* childTag, int childIndex,
	                                           const char* attributeTag)
	  {

	  	XMLCh* tag = XMLString::transcode(parentTag);
	  	DOMNodeList* list = document->getElementsByTagName(tag);
	  	XMLString::release(&tag);
		DOMElement* parent = dynamic_cast<DOMElement*>(list->item(parentIndex));
	  	DOMElement* child = dynamic_cast<DOMElement*>(parent->getElementsByTagName(XMLString::transcode(childTag))->item(childIndex));
	  	string value;
	  	if (child)
		{
		        tag= XMLString::transcode(attributeTag);
		  		char* tagname = XMLString::transcode(child->getAttribute(tag));
		 		value = tagname;
		        XMLString::release(&tagname);
		
		}
		else
		{
			value = "";
		}		
	  	return value;
	  }
 
	  //get the root element count

	  int musicplayer::get_root_count(const char* rootElementTag)
	  {
	  	DOMNodeList* list = document->getElementsByTagName(XMLString::transcode(rootElementTag));
	  	return (int)list->getLength();
	  }
 
	  //it counts the nodes

	  int musicplayer::get_count(const char* parentTag, int parentIndex, const char* childTag)
	  {
	  	XMLCh* tag = XMLString::transcode(parentTag);
	  	DOMNodeList* list = document->getElementsByTagName(tag);
	  	XMLString::release(&tag);
		DOMElement* parent = dynamic_cast<DOMElement*>(list->item(parentIndex));
	  	DOMNodeList* childList = parent->getElementsByTagName(XMLString::transcode(childTag));
	    return (int)childList->getLength();
	  }
	 

	  //used to insert the songs in xml file

	  void musicplayer::insert_songs()
	  {
		  DOMImplementation* implement = document->getImplementation();
		  wstring SongName;
		  wstring id;
		  wstring ArtistId;
		  wstring AlbumId;
		  string artistid;
		  int index = 0;
		//  string value;
		  string albumid;
		  const wchar_t* song;
	      const wchar_t* songid;
	//	  const wchar_t* idrefs;
		  
		  if (document->getDocumentElement() == NULL)
		  {
			  document = implement->createDocument(0, L"musicplayer", 0);
			  DOMElement* Root = document->getDocumentElement();
			  DOMElement* NewSongs = document->createElement(L"songs");
			  Root->appendChild(NewSongs);
			  DOMElement* NewArtists = document->createElement(L"artists");
			  Root->appendChild(NewArtists);
			  DOMElement* NewAlbums = document->createElement(L"albums");
			  Root->appendChild(NewAlbums);
			  DOMElement* NewPlaylists = document->createElement(L"playlists");
			  Root->appendChild(NewPlaylists);

		  }
			  XMLCh* tag = XMLString::transcode("songs");
			  DOMNodeList* list = document->getElementsByTagName(tag);
			  XMLString::release(&tag);
			  DOMElement* Root = dynamic_cast<DOMElement*>(list->item(0));
			  DOMElement* element = document->createElement(L"song");
			  Root->appendChild(element);
			  cout << "Enter the song id ";
			  wcin.ignore();
			  getline(wcin, id);
			  songid = id.c_str();
			  element->setAttribute(L"id", songid);
			  DOMElement* SongNameElement = document->createElement(L"song_name");
			  element->appendChild(SongNameElement);
			  cout << "Enter the songname ";
			  getline(wcin, SongName);
			  song = SongName.c_str();
			  DOMText* SongText = document->createTextNode(song);
			  SongNameElement->appendChild(SongText);
			  DOMElement* Artist = document->createElement(L"artistid");
			  element->appendChild(Artist);
			  cout << "Enter the artistid ";
			  getline(wcin, ArtistId);
			  string value(ArtistId.begin(), ArtistId.end());
			  song = ArtistId.c_str();
			  Artist->setAttribute(L"id", song);
			 
				  for (int iterator = 0; iterator < get_count("artists", 0, "artist"); iterator++)
				  {
					  artistid = get_attribute("artists", 0, "artist", iterator, "id");

					  if (artistid == value)
					  {
						  
						  DOMElement* elem = document->getDocumentElement();
						  XMLCh* tag = XMLString::transcode("artists");
						  DOMNodeList* list = document->getElementsByTagName(tag);
						  XMLString::release(&tag);
						  DOMElement* root = dynamic_cast<DOMElement*>(list->item(0));
						  XMLCh* tag1 = XMLString::transcode("artist");
						  DOMNodeList* list1 = document->getElementsByTagName(tag1);
						  XMLString::release(&tag);
						  DOMElement* root1 = dynamic_cast<DOMElement*>(list1->item(iterator));

						  DOMElement* Songs = document->createElement(L"songID");
						  root1->appendChild(Songs);
						  Songs->setAttribute(L"id", songid);

					  }
				  }
			  
			  DOMElement* Album = document->createElement(L"albumid");
			  element->appendChild(Album);
			  cout << "Enter the albumid ";
			  getline(wcin, AlbumId);
			  string album(AlbumId.begin(), AlbumId.end());
			  song = AlbumId.c_str();
			  Album->setAttribute(L"id", song);
			  for (int iterator = 0; iterator < get_count("albums", 0, "album"); iterator++)
			  {
				  albumid = get_attribute("albums", 0, "album", iterator, "id");

				  if (albumid == album)
				  {
					  
					  DOMElement* file = document->getDocumentElement();
					  XMLCh* tag = XMLString::transcode("albums");
					  DOMNodeList* list = document->getElementsByTagName(tag);
					  XMLString::release(&tag);
					  DOMElement* root = dynamic_cast<DOMElement*>(list->item(0));
					  XMLCh* tagname = XMLString::transcode("album");
					  DOMNodeList* listname = document->getElementsByTagName(tagname);
					  XMLString::release(&tagname);
					  DOMElement* RootName = dynamic_cast<DOMElement*>(listname->item(iterator));
					  DOMElement* Songs = document->createElement(L"songid");
					  RootName->appendChild(Songs);
					  Songs->setAttribute(L"id", songid);

				  }
			  }
			  reading_xmlfile(document, "./musicplayer.xml");
		 
	  }

	  //used to insert the artist in xml file

	  void musicplayer:: insert_artist()
	  {
		  DOMImplementation* implement=document->getImplementation();
		  wstring ArtistName;
		  wstring Artistid;
		  wstring SongId;
		  const wchar_t*	artist;
		//  const wchar_t* idrefs;
		  if (document->getDocumentElement() == NULL)
		  {
			  document = implement->createDocument(0, L"musicplayer", 0);
			  DOMElement* Root = document->getDocumentElement();
			  DOMElement* NewSongs = document->createElement(L"songs");
			  Root->appendChild(NewSongs);
			  DOMElement* NewArtists = document->createElement(L"artists");
			  Root->appendChild(NewArtists);
			  DOMElement* NewAlbums = document->createElement(L"albums");
			  Root->appendChild(NewAlbums);
			  DOMElement* NewPlaylists = document->createElement(L"playlists");
			  Root->appendChild(NewPlaylists);
		  }
		 
			  XMLCh* tag = XMLString::transcode("artists");
			  DOMNodeList* list = document->getElementsByTagName(tag);
			  XMLString::release(&tag);
			  DOMElement* root = dynamic_cast<DOMElement*>(list->item(0));
			  DOMElement* newartist = document->createElement(L"artist");
			  root->appendChild(newartist);
			  cout << "Enter the artist id ";
			  wcin.ignore();
			  getline(wcin, Artistid);
			  artist = Artistid.c_str();
			  newartist->setAttribute(L"id", artist);
			  DOMElement* ArtistNameElement = document->createElement(L"artist_name");
			  newartist->appendChild(ArtistNameElement);
			  cout << "Enter the artist name ";
			  getline(wcin, ArtistName);
			  artist = ArtistName.c_str();
			  DOMText* ArtistText = document->createTextNode(artist);
			  ArtistNameElement->appendChild(ArtistText);
			  DOMElement* Songs = document->createElement(L"songID");
			  newartist->appendChild(Songs);
			  cout << "Enter the song id ";
			  getline(wcin, SongId);
			  artist = SongId.c_str();

			//  DOMElement* elem = document->getElementById();
			  //cout << elem;
			  Songs->setAttribute(L"id", artist);
			  reading_xmlfile(document, "./musicplayer.xml");
		  
	 }

	  //used to insert the album in xml file

	  void musicplayer::insert_album()
	  {
		  DOMImplementation* implement = document->getImplementation();
		  wstring AlbumName;
		  wstring Albumid;
		  wstring SongId;
		  wstring year;
		  const wchar_t* album;
		//  const wchar_t* idrefs;
		  if (document->getDocumentElement() == NULL)
		  {
			  document = implement->createDocument(0, L"musicplayer", 0);
			  DOMElement* Root = document->getDocumentElement();
			  DOMElement* NewSongs = document->createElement(L"songs");
			  Root->appendChild(NewSongs);
			  DOMElement* NewArtists = document->createElement(L"artists");
			  Root->appendChild(NewArtists);
			  DOMElement* NewAlbums = document->createElement(L"albums");
			  Root->appendChild(NewAlbums);
			  DOMElement* NewPlaylists = document->createElement(L"playlists");
			  Root->appendChild(NewPlaylists);
		  }
			  XMLCh* tag = XMLString::transcode("albums");
			  DOMNodeList* list = document->getElementsByTagName(tag);
			  XMLString::release(&tag);
			  DOMElement* Root = dynamic_cast<DOMElement*>(list->item(0));
			  DOMElement* newalbum = document->createElement(L"album");
			  Root->appendChild(newalbum);
			  cout << "Enter the album id ";
			  wcin.ignore();
			  getline(wcin, Albumid);
			  album = Albumid.c_str();
			  newalbum->setAttribute(L"id", album);
			  DOMElement* AlbumNameElement = document->createElement(L"album_name");
			  newalbum->appendChild(AlbumNameElement);
			  cout << "Enter the album name ";
			  getline(wcin, AlbumName);
			  album = AlbumName.c_str();
			  DOMText* AlbumText = document->createTextNode(album);
			  AlbumNameElement->appendChild(AlbumText);
			  DOMElement* AlbumSong = document->createElement(L"songid");
			  newalbum->appendChild(AlbumSong);
			  cout << "Enter the song id ";
			  getline(wcin, SongId);
			  album = SongId.c_str();
			  AlbumSong->setAttribute(L"id", album);
			  DOMElement* AlbumYearElement = document->createElement(L"album_year");
			  newalbum->appendChild(AlbumYearElement);
			  cout << "Enter the album year ";
			  wcin >> year;
			  album = year.c_str();
			  DOMNode* AlbumYear = document->createTextNode(album);
			  AlbumYearElement->appendChild(AlbumYear);
			  reading_xmlfile(document, "./musicplayer.xml");
		  
	  }

	  //used to inserts playlist in xml file

	  void musicplayer::insert_playlist()
	  {
		  DOMImplementation* implement = document->getImplementation();
		  wstring name;
		  wstring SongId;
		  const wchar_t* playlist;
//		  const wchar_t* idrefs;
		  if (document->getDocumentElement() == NULL)
		  {
			  document = implement->createDocument(0, L"musicplayer", 0);
			  DOMElement* Root = document->getDocumentElement();
			  DOMElement* NewSongs = document->createElement(L"songs");
			  Root->appendChild(NewSongs);
			  DOMElement* NewArtists = document->createElement(L"artists");
			  Root->appendChild(NewArtists);
			  DOMElement* NewAlbums = document->createElement(L"albums");
			  Root->appendChild(NewSongs);
			  DOMElement* NewPlaylists = document->createElement(L"playlists");
			  Root->appendChild(NewPlaylists);
		  }

			 
			  XMLCh* tag = XMLString::transcode("playlists");
			  DOMNodeList* list = document->getElementsByTagName(tag);
			  XMLString::release(&tag);
			  DOMElement* Root = dynamic_cast<DOMElement*>(list->item(0));
			  DOMElement* PlaylistElement = document->createElement(L"playlist");
			  Root->appendChild(PlaylistElement);
			  cout << "Enter the playlist name ";
			  wcin.ignore();
			  getline(wcin, name);
			  playlist = name.c_str();
			  DOMElement* PlaylistNameElement = document->createElement(L"playlist_name");
			  PlaylistElement->appendChild(PlaylistNameElement);
			  DOMText* PlaylistName = document->createTextNode(playlist);
			  PlaylistNameElement->appendChild(PlaylistName);
			  DOMElement* PlaylistSong = document->createElement(L"song");
			  PlaylistElement->appendChild(PlaylistSong);
			  cout << "Enter the song id ";
			  getline(wcin, SongId);
			  playlist = SongId.c_str();
			  PlaylistSong->setAttribute(L"id", playlist);

			  //calls the reading xml file to modify it by inserting

			  reading_xmlfile(document, "./musicplayer.xml");
		 
	  }
	  
	  //this insert the elements 

	  void musicplayer:: reading_xmlfile(xercesc::DOMDocument* Document, std::string filePath)
	  {
		  
		  DOMImplementation *implementation = DOMImplementationRegistry::getDOMImplementation(L"LS");
		  DOMLSSerializer *serializer = ((DOMImplementationLS*)implementation)->createLSSerializer();
		  if (serializer->getDomConfig()->canSetParameter(XMLUni::fgDOMWRTFormatPrettyPrint, true))
	      serializer->getDomConfig()->setParameter(XMLUni::fgDOMWRTFormatPrettyPrint, true);
		  serializer->setNewLine(XMLString::transcode("\r\n"));
		  XMLCh *tempFilePath = XMLString::transcode(filePath.c_str());
		  const int pathLength = XMLString::stringLen(tempFilePath);
		  XMLCh *targetPath = (XMLCh*)XMLPlatformUtils::fgMemoryManager->allocate((pathLength + ABSOLUTE_PATH_FILENAME_PREFIX_SIZE) * sizeof(XMLCh));
		  XMLString::fixURI(tempFilePath, targetPath);
		  XMLFormatTarget *formatTarget = new LocalFileFormatTarget(targetPath);
		  DOMLSOutput *output = ((DOMImplementationLS*)implementation)->createLSOutput();
		  output->setByteStream(formatTarget);	
		  serializer->write(Document, output);	
		  serializer->release();
		  XMLString::release(&tempFilePath);
		  delete formatTarget;
		  output->release();
	  }
	  void musicplayer::search_songs()
	  {
		  string songs;
		  string value;
		  string artistid;
		  int flag = 0;
		  string Id;
		  string albumid;
		  cout << "\nEnter the song";
		  cin.ignore();
		  getline(cin, songs);
		  for (int count = 0; count < get_count("songs", 0, "song"); count++)
		  {
			//  idrefs = get_attribute("songs", 0, "song", count, "id");
			  idref = get_value("song", count, "song_name", 0);
			  if (songs == idref)
			  {
				
				  cout << "\nSong name " << idref.c_str();
				  value = get_attribute("songs", 0, "artistid", count, "id");
				  for (int iterator = 0; iterator < get_count("artists", 0, "artist"); iterator++)
				  {
					
					  artistid = get_attribute("artists", 0, "artist", iterator, "id");

					  if (value == artistid)
					  {
						  string Id = get_value("artist", iterator, "artist_name", 0);
						  cout << "\nArtists name " << Id.c_str();
						  flag = 1;
					  }

				  }
				  
				  idref = get_attribute("songs", 0, "albumid", count, "id");
				  for (int iterator = 0; iterator < get_count("albums", 0, "album"); iterator++)
				  {

					  albumid = get_attribute("albums", 0, "album", iterator, "id");
					  if (idref == albumid)
					  {
						  string Id = get_value("album", iterator, "album_name", 0);
						  cout << "\nAlbum name " << Id.c_str();
						  flag = 1;
					  }

				  }
				
			  }

		  }
		  if (flag == 0)
		  {
			  cout << "\nThe seached song is not available";
		  }
	  }
	  void musicplayer::search_artists()
	  {
		  string artist;
		  string value;
		  int size = 0;
		  string artistid;
		  int flag = 0;
		  string Id;
		  int increment = 0;
		  cout << "\nEnter the artistname";
		  cin.ignore();
		  getline(cin, artist);
		  for (int count = 0; count < get_count("artists", 0, "artist"); count++)
		  {

			  value = get_value("artist", count, "artist_name", 0);
			
			  if (artist == value)
			  {
				  

				  for (int iterate = 0; iterate < get_count("artist",count,"songID"); iterate++)
				  {
					  artistid = get_attribute("artist", count, "songID", increment, "id");

					  for (int iterator = 0; iterator < get_count("songs", 0, "song"); iterator++)
					  {
						  Id = get_attribute("songs", 0, "song", iterator, "id");
						  if (Id == artistid)
						  {
							  idrefs = get_value("song", iterator, "song_name", 0);
							  cout << "\nSong name " << idrefs.c_str();
							  flag = 1;
						  }

					  }
					  increment++;

				  }
			  }
		  }	  if (flag == 0)
				  {
					  cout << "\nThe seached song is not available";
				  }

			  
		  
	  }

	  //display the songs

	  void musicplayer::display_songs()
	  {
		  string value;
		  string artistid;
	//	  int val2 = 0;
		  string Id;
		  string albumid;
		  int iterator = 0;
		  if (document->getDocumentElement() == NULL)
		  {
			  cout << "Xml file is empty";
		  }
		  else
		  {
			  for (int count = 0; count < get_count("songs", 0, "song"); count++)
			  {
				 // val2 = count;
				  cout << "\nThe songs are";
				  id = get_attribute("songs", 0, "song", count, "id");
				  cout << "\nSong id is " << id.c_str() << endl;
				  name = get_value("song", count, "song_name", 0);
				  cout << "Song name is " << name.c_str() << endl;

				  value = get_attribute("songs", 0, "artistid", count, "id");
				  for (iterator= 0; iterator < get_count("artists", 0, "artist"); iterator++)
				  {
					 
					  artistid = get_attribute("artists", 0, "artist", iterator, "id");
					
					  if (value ==artistid )
					  {
						  string Id = get_value("artist", iterator, "artist_name", 0);
						  cout <<"Artists name "<< Id.c_str();
					  }

				  }
						idref = get_attribute("songs", 0, "albumid", count, "id");
						for (iterator = 0; iterator < get_count("albums", 0, "album"); iterator++)
						{
							

							albumid = get_attribute("albums", 0, "album", iterator, "id");
							if (idref == albumid)
							{
								string Id = get_value("album", iterator, "album_name", 0);
								cout << "\nAlbum name " << Id.c_str();
							}

						}
					    
				  }
			  }
		  }
	  

　
	  //displays the artist

	  void musicplayer::display_artist()
	  {

		  int value = 0;
		  int increment = 0;
		  string songid;
		  string ID;

		  int iterator = 0;
		  int iterate = 0;
		  if (document->getDocumentElement() == NULL)
		  {
			  cout << "Xml file is empty";
		  }
		  else
		  {
			  for (int count = 0; count < get_count("artists", 0, "artist"); count++)
			  {
				  cout << "\nThe artists are";

				  id = get_attribute("artists", 0, "artist", count, "id");
				  cout << "\nArtist id is " << id.c_str() << endl;
				  name = get_value("artist", count, "artist_name", 0);
				  cout << "Artist name is " << name.c_str() << endl;

				  value = get_count("artist", count, "songID");
				 
				  for (int iterate = 0; iterate < value; iterate++)
				  {
					  songid = get_attribute("artists", 0, "songID", increment, "id");
					 
					  for (iterator = 0; iterator < get_count("songs", 0, "song"); iterator++)
					  {
						  ID = get_attribute("songs", 0, "song", iterator, "id");
						  if (ID == songid)
						  {
							  idrefs = get_value("song", iterator, "song_name", 0);
							  cout << "\nSong name " << idrefs.c_str();
						  }

					  }
					  increment++;

				 }
			  }
		  }
	  }

	 
	  //displays the album

	  void musicplayer::display_album()
	  {
		  string year;

		  int value = 0;
		  int increment = 0;
		  string songid;
		  string ID;
		  int iterator = 0;
		  int iterate = 0;
		  if (document->getDocumentElement() == NULL)
		  {
			  cout << "Xml file is empty";
		  }
		  else
		  {
			 
			  for (int count = 0; count < get_count("albums", 0, "album"); count++)
			  {
				  cout << "\nThe albums are";
				  id = get_attribute("albums", 0, "album", count, "id");
				  cout << "\nAlbum id " << id.c_str() << endl;
				  name = get_value("album", count, "album_name", 0);
				  cout << "Album name is " << name.c_str();
				  value = get_count("album", count, "songid");
				  for (int iterate = 0; iterate < value; iterate++)
				  {
					  songid = get_attribute("albums", 0, "songid", increment, "id");
					 
					  for (iterator = 0; iterator < get_count("songs", 0, "song"); iterator++)
					  {

　
　
						  ID = get_attribute("songs", 0, "song", iterator, "id");

　
						  if (ID == songid)
						  {
							  idrefs = get_value("song", iterator, "song_name", 0);
							  cout << "\nSong name " << idrefs.c_str();
						  }

					  }
					  increment++;

				  }
				  year = get_value("album", count, "album_year", 0);
				  cout << "\nAlbum year " << year.c_str() << endl;
			  }
		  }
	  }
		 
	 
	  //display the compilation album

	  void musicplayer::display_compilation_album()
	  {
		  
			  int count = 0;
			  id = get_attribute("albums", 0, "compilation_album", 0, "Id");
			  cout << " \nCompilation album id " << id.c_str() << endl;
			  name = get_value("albums", 0, "compilation_album_name", 0);
			  cout << "Compilation album name is " << name.c_str() << endl;
			  id = get_attribute("albums", 0, "songId", count, "id");
			  cout << "Songs are\n " << id.c_str() << endl;

		  
	  }

　
	  //displays the playlist 

	  void musicplayer::display_playlist()
	  {
		  string name;
		  int id=0;
		  int value = 0;
		  int increment = 0;
		  string songid;
		  string ID;
		  int iterator = 0;
		  int iterate = 0;
		  int count = 0;
		  if (document->getDocumentElement() == NULL)
		  {
			  cout << "Xml file is empty";
		  }
		  else
		  {
			  for (int count = 0; count < get_count("playlists", 0, "playlist"); count++)
			  {
				  cout << "\nThe playlists are";
				  name = get_value("playlist", count, "playlist_name", 0);
				  cout << "\nPlaylist name " << name.c_str();
				  value = get_count("playlist", 0, "song");
				  for (int iterate = 0; iterate < value; iterate++)
				  {
					  songid = get_attribute("playlists", 0, "song", increment, "id");

					  for (iterator = 0; iterator < get_count("songs", 0, "song"); iterator++)
					  {

　
　
						  ID = get_attribute("songs", 0, "song", iterator, "id");

　
						  if (ID == songid)
						  {
							  idrefs = get_value("song", iterator, "song_name", 0);
							  cout << "\nSong name " << idrefs.c_str();
						  }

					  }
					  increment++;

				  }
				 
			  }
		  }
	  }
	 
