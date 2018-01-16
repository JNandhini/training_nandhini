#pragma once

#include<iostream>

#include<string>

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

#include <xercesc/dom/DOMAttr.hpp>

#include <xercesc/dom/impl/DOMDocumentFragmentImpl.hpp>

using namespace std;

using namespace xercesc;

class musicplayer

{

	DOMDocument* document;

	DOMImplementation* implement;

public:


	musicplayer(const char *file);

	~musicplayer();

	string get_value(const char* parentTag, int parentIndex, const char* childTag, int childIndex);

    string get_attribute(const char* parentTag, int parentIndex, const char* childTag, int childIndex,const char* attributeTag);

    int getRootElementCount(const char* rootElementTag);

	int getChildCount(const char* parentTag, int parentIndex, const char* childTag);

	void insert_songs();

	void insert_artist();

	void insert_album();

	void insert_playlist();

	void display_songs();

	void display_artist();

	void display_album();

	void display_playlist();

	void OutputXML(xercesc::DOMDocument* Document, std::string filePath);

	

private:

     musicplayer();

     musicplayer(const musicplayer&);

};

