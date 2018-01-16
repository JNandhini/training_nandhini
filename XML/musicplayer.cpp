#pragma once
#include "musicplayer.h"
XercesDOMParser*   parser = NULL;
 ErrorHandler*      errorHandler = NULL;
 
 musicplayer::musicplayer(const char* file) : document(NULL)
 {
	   
XMLPlatformUtils::Initialize();
	 parser = new XercesDOMParser();
    parser->parse(file);
		 document = parser->adoptDocument();
	
		/* XMLCh tempString[100];
		 XMLString::transcode("LS", tempString, 99);
		 DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(tempString);
		 DOMLSParser* parser = ((DOMImplementationLS*)impl)->createLSParser(DOMImplementationLS::MODE_SYNCHRONOUS, 0);
  		 document = parser->parseURI(file);
			*/
		 
	
	 }

 musicplayer::~musicplayer()
	  {
	      if (document) document->release();
	  }
 

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
 

	  int musicplayer::getRootElementCount(const char* rootElementTag)
	  {
	  	DOMNodeList* list = document->getElementsByTagName(XMLString::transcode(rootElementTag));
	  	return (int)list->getLength();
	  }
 

	  int musicplayer::getChildCount(const char* parentTag, int parentIndex, const char* childTag)
	  {
	  	XMLCh* tag = XMLString::transcode(parentTag);
	  	DOMNodeList* list = document->getElementsByTagName(tag);
	  	XMLString::release(&tag);
		DOMElement* parent = dynamic_cast<DOMElement*>(list->item(parentIndex));
	  	DOMNodeList* childList = parent->getElementsByTagName(XMLString::transcode(childTag));
	    return (int)childList->getLength();
	  }
	 
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
		  DOMText* SongText = document->createTextNode(L"song7");
		  SongNameElement->appendChild(SongText);
		  DOMElement* Artist = document->createElement(L"artistid");
		  element->appendChild(Artist);
		  Artist->setAttribute(L"id", L"artist1 artist3");
		  DOMElement* Album = document->createElement(L"albumid");
		  element->appendChild(Album);
		  Album->setAttribute(L"id", L"album1");
		  OutputXML(document, "./musicplayer.xml");
		 
	  }
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
		  DOMText* ArtistText = document->createTextNode(L"artist5");
		  ArtistNameElement->appendChild(ArtistText);
		  DOMElement* Songs = document->createElement(L"songId");
		  newartist->appendChild(Songs);
		  Songs->setAttribute(L"id", L"song7 song3");
		  OutputXML(document, "./musicplayer.xml");

	  }
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
		  DOMText* AlbumText = document->createTextNode(L"album4");
		  AlbumNameElement->appendChild(AlbumText);
		  DOMElement* AlbumSong = document->createElement(L"songid");
		  newalbum->appendChild(AlbumSong);
		  AlbumSong->setAttribute(L"id", L"song3 song2");
		  DOMElement* AlbumYearElement = document->createElement(L"album_year");
		  newalbum->appendChild(AlbumYearElement);
		  DOMNode* AlbumYear = document->createTextNode(L"1992");
		  AlbumYearElement->appendChild(AlbumYear);
		  OutputXML(document, "./musicplayer.xml");
	  }
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
		  OutputXML(document, "./musicplayer.xml");
	  }
	  const int ABSOLUTE_PATH_FILENAME_PREFIX_SIZE = 0;

	  void musicplayer:: OutputXML(xercesc::DOMDocument* Document, std::string filePath)
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
	  void musicplayer::display_songs()
	  {
		  string value;
		  for (int count = 0; count < getChildCount("songs", 0, "song"); count++)
		  {
			  cout << "\nThe songs are";
			  value = get_attribute("songs", 0, "song", count, "id");
			  cout << "\nSong id is " << value.c_str() << endl;
			  value = get_value("song", count, "song_name", 0);
			  cout << "Song name is " << value.c_str() << endl;
			  value = get_attribute("songs", 0, "artistid", count, "id");
			  cout << "Artists name " << value.c_str() << endl;
			  value = get_attribute("songs", 0, "albumid", count, "id");
			  cout << "album name " << value.c_str() << endl;

		  }

		  for (int count = 0; count < getChildCount("songs", 1, "song"); count++)
		  {

			  cout << "\nThe songs are";
			  value = get_attribute("songs", 1, "song", count, "id");
			  cout << "\nSong id is " << value.c_str() << endl;
			  value = get_value("song", count, "song_name", 1);
			  cout << "Song name is " << value.c_str() << endl;
			  value = get_attribute("songs", 1, "artistid", count, "id");
			  cout << "Artists name " << value.c_str() << endl;
			  value = get_attribute("songs", 1, "albumid", count, "id");
			  cout << "album name " << value.c_str() << endl;

　
		  }
	  }
	  void musicplayer::display_artist()
	  {
		  string value;
		  for (int count = 0; count <getChildCount("artists", 0, "artist"); count++)
		  {
			  cout << "\nThe artists are";
			  value = get_attribute("artists", 0, "artist", count, "id");
			  cout << "\nArtist id is " << value.c_str() << endl;
			  value = get_value("artist", count, "artist_name", 0);
			  cout << "Artist name is " << value.c_str() << endl;
			  value = get_attribute("artists", 0, "songID", count, "id");
			  cout << "Songs are " << value.c_str() << endl;

		  }
		  for (int count = 0; count < getChildCount("artists", 1, "artist"); count++)
		  {
			  cout << "\nThe artists are";
			  value = get_attribute("artists", 1, "artist", count, "id");
			  cout << "\nArtist id is " << value.c_str() << endl;
			  value = get_value("artist", count, "artist_name", 1);
			  cout << "Artist name is " << value.c_str() << endl;
			  value = get_attribute("artists", 1, "songID", count, "id");
			  cout << "Songs are " << value.c_str() << endl;
		  }
	  }
	  void musicplayer::display_album()
	  {
		  string value;
		  for (int count = 0; count < getChildCount("albums", 0, "album"); count++)
		  {
			  cout << "\nThe albums are";
			  value = get_attribute("albums", 0, "album", count, "id");
			  cout << "\nAlbum id " << value.c_str() << endl;
			  value =get_value("album", count, "album_name", 0);
			  cout << "Album name is " << value.c_str() << endl;
			  value = get_attribute("albums", 0, "songid", count, "id");
			  cout << "The songs are " << value.c_str() << endl;
			  value = get_value("album", count, "album_year", 0);
			  cout << "Album year " << value.c_str() << endl;
		  }
		  for (int count = 0; count < getChildCount("albums", 1, "album"); count++)
		  {
			  cout << "\nThe albums are";
			  value = get_attribute("albums", 1, "album", count, "id");
			  cout << "\nAlbum id " << value.c_str() << endl;
			  value = get_value("album", count, "album_name", 1);
			  cout << "Album name is " << value.c_str() << endl;

			  value = get_attribute("albums", 1, "songid", count, "id");
			  cout << "The songs are " << value.c_str() << endl;
			  value = get_value("album", count, "album_year", 1);
			  cout << "Album year " << value.c_str() << endl;
		  }

		  for (int count = 0; count < getChildCount("albums1", 0, "compilation_album"); count++)
		  {

			  value = get_attribute("albums", 0, "compilation_album", count, "id");
			  cout << " \ncompilation album id " << value.c_str() << endl;
			  value = get_value("complilation_album", count, "compilation_album_name", 0);
			  cout << "Compilation album name " << value.c_str() << endl;

			  value = get_attribute("albums1", 0, "songId", count, "id");
			  cout << "Songs are\n " << value.c_str() << endl;
		  }

	  }
	  void musicplayer::display_playlist()
	  {
		  string value;
		  for (int count = 0; count < getChildCount("playlists", 0, "playlist"); count++)
		  {
			  cout << "\nThe playlists are";
			  value = get_value("playlist", count, "playlist_name", 0);
			  cout << "\nPlaylist name " << value.c_str() << endl;
			  value = get_attribute("playlists", 0, "song", count, "id");
			  cout << "Songs in the playlist are " << value.c_str() << endl;
		  }
		  for (int count = 0; count < getChildCount("playlists", 1, "playlist"); count++)
		  {
			  cout << "\nThe playlists are";
			  value = get_value("playlist", count, "playlist_name", 1);
			  cout << "\nPlaylist name " << value.c_str() << endl;
			  value = get_attribute("playlists", 1, "song", count, "id");
			  cout << "Songs in the playlist are " << value.c_str() << endl;
		  }
	  }
