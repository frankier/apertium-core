#ifndef _XMLREADER_
#define _XMLREADER_

#include <apertium/constant_manager.h>
#include <apertium/string_utils.h>
#include <apertium/tagger_data.h>
#include <apertium/ttag.h>
#include <apertium/utf_converter.h>
#include <lttoolbox/pattern_list.h>
#include <lttoolbox/ltstr.h>
#include <lttoolbox/xml_parse_util.h>

#include <libxml/xmlreader.h>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class XMLReader
{
private:
  class XmlTextReaderResource {
    friend class XMLReader;
    XmlTextReaderResource(string const &filename);
    ~XmlTextReaderResource();
    xmlTextReaderPtr reader;
  };

protected:
  XMLReader();
  xmlTextReaderPtr reader;
  int type;
  wstring name;
  wstring attrib(wstring const &name);
  string attrib(string const &name);
  void parseError(wstring const &message);
  void unexpectedTag();
  void stepToTag();
  void step();
  virtual void parse() = 0;

public:
  void read(const string &filename);
};

#endif
