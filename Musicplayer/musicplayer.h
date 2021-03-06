#pragma once
#include<iostream>
#include<string>
//#undef DOMDocument
 
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/dom/DOM.hpp>
#include<xercesc/dom/DOMNodeList.hpp>
#include <xercesc/sax/HandlerBase.hpp> 
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOMNode.hpp>
#include <xercesc/dom/DOMImplementation.hpp>
#include <xercesc/dom/impl/DOMImplementationImpl.hpp>
#include <xercesc/dom/DOMImplementationLS.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/dom/impl/DOMElementImpl.hpp>
#include <xercesc/dom/DOMNodeList.hpp>
#include <xercesc/framework/StdOutFormatTarget.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>
#include <xercesc/dom/impl/DOMDocumentFragmentImpl.hpp>
using namespace std;
using namespace xercesc;

//class which contains the details of songs 

class musicplayer
{
	xercesc::DOMDocument* document;
	DOMImplementation* implement;
public:
	string name;
	string id;
	string idrefs;
	string idref;
	
public:

	musicplayer(const char *file);
	~musicplayer();
	string get_value(const char* parent, int index, const char* child, int childindex);
    string get_attribute(const char* parent, int index, const char* child, int childindex,const char* attribute);
    int get_root_count(const char* rootelement);
	int get_count(const char* parent, int index, const char* childelement);
	void insert_songs();
	void insert_artist();
	void insert_album();
	void insert_playlist();
	void display_songs();
	void display_artist();
	void display_album();
	void display_compilation_album();
	void display_playlist();
	void search_songs();
	void search_artists();
	void reading_xmlfile(xercesc::DOMDocument* Document, std::string filePath);
	
private:
     musicplayer();
     musicplayer(const musicplayer&);
};
