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
	 }

 musicplayer::~musicplayer()
	  {
	      if (document) document->release();
	  }
 

	  string musicplayer::getChildValue(const char* parentTag, int parentIndex, const char* childTag, int childIndex)
	  {
	  	XMLCh* temp = XMLString::transcode(parentTag);
	  	DOMNodeList* list = document->getElementsByTagName(temp);
	  	XMLString::release(&temp);
		DOMElement* parent = dynamic_cast<DOMElement*>(list->item(parentIndex));
	  	DOMElement* child = dynamic_cast<DOMElement*>(parent->getElementsByTagName(XMLString::transcode(childTag))->item(childIndex));
	  	string value;
	  	if (child)
		{
		  		char* temp2 = XMLString::transcode(child->getTextContent());
		  		value = temp2;
		        XMLString::release(&temp2);
		 
	 
		}
	  	else 
		{
		  		value = "";
		}
	return value;
	  }
 

　
	  string musicplayer::getChildAttribute(const char* parentTag, int parentIndex, const char* childTag, int childIndex,
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

　
int main()
{

	DOMDocument *document=0;
	string value;
 
   musicplayer * music = new musicplayer("./musicplayer.xml");
 
   DOMNode *node=0;
   if (music) {
	   //	   DOMElement *element = document->getElementById(XMLString::transcode("song1"));
	    
	   for (int count = 0; count < music->getChildCount("songs", 0, "song"); count++)
	   {

　
		   value = music->getChildAttribute("songs", 0, "song", count, "id");
		   cout << "song id is\n" << value.c_str() << endl;
		   value = music->getChildValue("song", count, "song_name", 0);
		   cout << "Song name is\n"<< value.c_str()<<endl;
		   value = music->getChildAttribute("song", 0, "artistt", count, "id");
		   cout << "artists name\n"<< value.c_str()<<endl;
		   value = music->getChildAttribute("song", 0, "album", count, "id");
		   cout << "album name\n"<< value.c_str()<<endl;
	   }
	   for (int count = 0; count < music->getChildCount("artists", 0, "artist"); count++)
	   {
		   value = music->getChildAttribute("artists", 0, "artist", count, "id");
		   cout << "Artist id is\n"<< value.c_str()<<endl;
		   value = music->getChildValue("artist", count, "artist_name", 0);
		   cout << "Artist name is\n"<< value.c_str()<<endl;
		   value = music->getChildAttribute("artist", 0, "songID", count, "id");
		   cout << "Songs are \n"<< value.c_str()<<endl;
	   }
	   for (int count = 0; count < music->getChildCount("albums", 0, "album"); count++)
	   {
		   value = music->getChildAttribute("albums", 0, "album", count, "id");
		   cout << "Album id\n" << value.c_str()<<endl;
		   value = music->getChildValue("album", count, "album_name", 0);
		   cout << "Album name is\n" << value.c_str()<<endl;
		   value = music->getChildAttribute("album", 0, "songid", count, "id");
		   cout << "\nThe songs are\n" << value.c_str()<<endl;
		   value = music->getChildValue("album", count, "album_year", 0);
		   cout << "Album year\n" << value.c_str()<<endl;
	   }
		   for (int count = 0; count < music->getChildCount("albums", 0, "compilation_album"); count++)
		   {
		   value = music->getChildAttribute("albums", 0, "compilation_album", count, "id");
		   cout << " compilation allbum id id\n"<< value.c_str()<<endl;
		   value = music->getChildValue("complilation_album", count, "compilation_album_name", 0);
		   cout << "Compilation album name\n"<< value.c_str()<<endl;

		   value = music->getChildAttribute("compilation_album", 0, "songId", count, "id");
		   cout << "Songs are\n"<< value.c_str()<<endl;
	   }
	   for (int count = 0; count < music->getChildCount("playlists", 0, "playlist"); count++)
	   {	   
		   value = music->getChildValue("playlist", count, "playlist_name", 0);
		   cout << "Playlist name\n"<< value.c_str()<<endl;
		   value = music->getChildAttribute("playlist", 0, "song", count, "id");
		   cout << "Songs in the playlist are\n"<< value.c_str()<<endl;
	   }
   }
   system("pause");
		//   cout << XMLString::transcode(element->getNodeName());
	   
   
}
	
