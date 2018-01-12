#pragma once
#include<iostream>
#include<string>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/dom/DOM.hpp>
#include<xercesc/dom/DOMNodeList.hpp>
#include <xercesc/sax/HandlerBase.hpp> 
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOMNode.hpp>
#include <xercesc/dom/impl/DOMImplementationImpl.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/dom/impl/DOMElementImpl.hpp>
#include <xercesc/dom/impl/DOMDocumentFragmentImpl.hpp>
using namespace std;
using namespace xercesc;
class musicplayer
{
	DOMDocument* document;
public:
	musicplayer(const char *file);
	~musicplayer();
	string getChildValue(const char* parentTag, int parentIndex, const char* childTag, int childIndex);
    string getChildAttribute(const char* parentTag, int parentIndex, const char* childTag, int childIndex,const char* attributeTag);
    int getRootElementCount(const char* rootElementTag);
	int getChildCount(const char* parentTag, int parentIndex, const char* childTag);

private:
     musicplayer();
     musicplayer(const musicplayer&);
};
