#pragma once
#include "musicplayer.h"
XercesDOMParser*   parser = NULL;
 ErrorHandler*      errorHandler = NULL;
 const int ABSOLUTE_PATH_FILENAME_PREFIX_SIZE = 0;

 //constructor which initializes the parser

 musicplayer::musicplayer(const char* file) : document(NULL)
 {
	   
XMLPlatformUtils::Initialize();
	 parser = new XercesDOMParser();
    parser->parse(file);
		 document = parser->adoptDocument();
	
	
	
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
		 
		  DOMElement* Root = document->getDocumentElement();
		  DOMElement* Element = document->createElement(L"songs");
		  Root->appendChild(Element);
		  DOMElement* element = document->createElement(L"song");
		  Element->appendChild(element);
		  element->setAttribute(L"id", L"song7");
		  DOMElement* SongNameElement = document->createElement(L"song_name");
		  element->appendChild(SongNameElement);
		  DOMText* SongText = document->createTextNode(L"Konjam un");
		  SongNameElement->appendChild(SongText);
		  DOMElement* Artist = document->createElement(L"artistid");
		  element->appendChild(Artist);
		  Artist->setAttribute(L"id", L"artist1 artist3");
		  DOMElement* Album = document->createElement(L"albumid");
		  element->appendChild(Album);
		  Album->setAttribute(L"id", L"album1");
		  reading_xmlfile(document, "./musicplayer.xml");
		 
	  }

	  //used to insert the artist in xml file

	  void musicplayer:: insert_artist()
	  {
		  DOMElement* Root = document->getDocumentElement();
		  DOMElement* ArtistElement = document->createElement(L"artists");
		  Root->appendChild(ArtistElement);
		  DOMElement* newartist = document->createElement(L"artist");
		  ArtistElement->appendChild(newartist);
		  newartist->setAttribute(L"id", L"artist5");
		  DOMElement* ArtistNameElement = document->createElement(L"artist_name");
		  newartist->appendChild(ArtistNameElement);
		  DOMText* ArtistText = document->createTextNode(L"Aslam");
		  ArtistNameElement->appendChild(ArtistText);
		  DOMElement* Songs = document->createElement(L"songID");
		  newartist->appendChild(Songs);
		  Songs->setAttribute(L"id", L"song7 song3");
		  reading_xmlfile(document, "./musicplayer.xml");

	  }

	  //used to insert the album in xml file

	  void musicplayer::insert_album()
	  {  
		  DOMElement* Root = document->getDocumentElement();
		  DOMElement* AlbumElement = document->createElement(L"albums");
		  Root->appendChild(AlbumElement);
		  DOMElement* newalbum = document->createElement(L"album");
		  AlbumElement->appendChild(newalbum);
		  newalbum->setAttribute(L"id", L"album4");
		  DOMElement* AlbumNameElement = document->createElement(L"album_name");
		  newalbum->appendChild(AlbumNameElement);
		  DOMText* AlbumText = document->createTextNode(L"M.S.Dhoni");
		  AlbumNameElement->appendChild(AlbumText);
		  DOMElement* AlbumSong = document->createElement(L"songid");
		  newalbum->appendChild(AlbumSong);
		  AlbumSong->setAttribute(L"id", L"song3 song2");
		  DOMElement* AlbumYearElement = document->createElement(L"album_year");
		  newalbum->appendChild(AlbumYearElement);
		  DOMNode* AlbumYear = document->createTextNode(L"1992");
		  AlbumYearElement->appendChild(AlbumYear);
		  reading_xmlfile(document, "./musicplayer.xml");
	  }

	  //used to inserts playlist in xml file

	  void musicplayer::insert_playlist()
	  {
		  DOMElement* Root = document->getDocumentElement();
		  DOMElement* Playlist = document->createElement(L"playlists");
		  Root->appendChild(Playlist);
		  DOMElement* PlaylistElement = document->createElement(L"playlist");
		  Playlist->appendChild(PlaylistElement);
		  DOMElement* PlaylistNameElement = document->createElement(L"playlist_name");
		  PlaylistElement->appendChild(PlaylistNameElement);
		  DOMText* PlaylistName = document->createTextNode(L"playlist3");
		  PlaylistNameElement->appendChild(PlaylistName);
		  DOMElement* PlaylistSong = document->createElement(L"song");
		  PlaylistElement->appendChild(PlaylistSong);
		  PlaylistSong->setAttribute(L"id", L"song1 song3 song7");

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

　
	  //display the songs

	  void musicplayer::display_songs()
	  {
		  string name;
		  string id;
		  string idrefs;
		  string idref;
		  for (int count = 0; count < get_count("songs", 0, "song"); count++)
		  {
			  cout << "\nThe songs are";
			  id = get_attribute("songs", 0, "song", count, "id");
			  cout << "\nSong id is " << id.c_str() << endl;
			  name = get_value("song", count, "song_name", 0);
			  cout << "Song name is " << name.c_str() << endl;
			  idrefs = get_attribute("songs", 0, "artistid", count, "id");
			  cout << "Artists name " << idrefs.c_str() << endl;
			  idref = get_attribute("songs", 0, "albumid", count, "id");
			  cout << "album name " << idref.c_str() << endl;

		  }

　
		  for (int count = 0; count < get_count("songs", 1, "song"); count++)
		  {

			  cout << "\nThe songs are";
			  id = get_attribute("songs", 1, "song", count, "id");
			  cout << "\nSong id is " << id.c_str() << endl;
			  name = get_value("songs", 1, "song_name", 0);
			  cout << "Song name is " << name.c_str() << endl;
			  idrefs = get_attribute("songs", 1, "artistid", count, "id");
			  cout << "Artists name " << idrefs.c_str() << endl;
			  idref = get_attribute("songs", 1, "albumid", count, "id");
			  cout << "album name " << idref.c_str() << endl;

　
		  }
		 
	  }

	  //displays the artist

	  void musicplayer::display_artist()
	  {
		  string name;
		  string id;
		  for (int count = 0; count <get_count("artists", 0, "artist"); count++)
		  {
			  cout << "\nThe artists are";
			  id= get_attribute("artists", 0, "artist", count, "id");
			  cout << "\nArtist id is " << id.c_str() << endl;
			  name = get_value("artist", count, "artist_name", 0);
			  cout << "Artist name is " << name.c_str() << endl;
			  id = get_attribute("artists", 0, "songID", count, "id");
			  cout << "Songs are " << id.c_str() << endl;

		  }
		  for (int count = 0; count < get_count("artists", 1, "artist"); count++)
		  {
			  cout << "\nThe artists are";
			  id = get_attribute("artists", 1, "artist", count, "id");
			  cout << "\nArtist id is " << id.c_str() << endl;
			  name = get_value("artists", 1, "artist_name", 0);
			  cout << "Artist name is " << name.c_str() << endl;
			  id = get_attribute("artists", 1, "songID", count, "id");
			  cout << "Songs are " << id.c_str() << endl;
		  }
	  }

　
	  //displays the album

	  void musicplayer::display_album()
	  {
		  string name;
		  string id;
		  string year;
		  for (int count = 0; count < get_count("albums", 0, "album"); count++)
		  {
			  cout << "\nThe albums are";
			  id = get_attribute("albums", 0, "album", count, "id");
			  cout << "\nAlbum id " << id.c_str() << endl;
			  name = get_value("album", count, "album_name", 0);
			  cout << "Album name is " << name.c_str() << endl;
			  id = get_attribute("albums", 0, "songid", count, "id");
			  cout << "The songs are " << id.c_str() << endl;
			  year = get_value("album", count, "album_year", 0);
			  cout << "Album year " << year.c_str() << endl;
		  }
		  for (int count = 0; count < get_count("albums", 1, "album"); count++)
		  {
			  cout << "\nThe albums are";
			  id = get_attribute("albums", 1, "album", count, "id");
			  cout << "\nAlbum id " << id.c_str() << endl;
			  name = get_value("albums", 1, "album_name", 0);
			  cout << "Album name is " << name.c_str() << endl;
			  id = get_attribute("albums", 1, "songid", count, "id");
			  cout << "The songs are " << id.c_str() << endl;
			  year = get_value("albums", 1, "album_year", 0);
			  cout << "Album year " << year.c_str() << endl;
		  }

	  }

	  //display the compilation album

	  void musicplayer::display_compilation_album()
	  {
		  string name;
		  string id;
		  int count = 0;
		  id = get_attribute("albums", 1, "compilation_album", 1, "Id");
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
		  string id;
		  int count = 0;
		  for (int count = 0; count < get_count("playlists", 0, "playlist"); count++)
		  {
			  cout << "\nThe playlists are";
			  name= get_value("playlist", count, "playlist_name", 0);
			  cout << "\nPlaylist name " << name.c_str() << endl;
			  id = get_attribute("playlists", 0, "song", count, "id");
			  cout << "Songs in the playlist are " << id.c_str() << endl;
		  }
		  for (int count = 0; count < get_count("playlists", 1, "playlist"); count++)
		  {
			  cout << "\nThe playlists are";
			  name = get_value("playlists", 1, "playlist_name", 0);
			  cout << "\nPlaylist name " << name.c_str() << endl;
			  id = get_attribute("playlists", 1, "song", count, "id");
			  cout << "Songs in the playlist are " << id.c_str() << endl;
		  }
	  }
