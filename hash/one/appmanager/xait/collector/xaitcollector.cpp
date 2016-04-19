/*
Copyright [2016] [sdesignssolutions - ssundaramp@rediffmail.com]

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

/**
  *
#################################################\n
##########~~~####~~~##################~~~########\n
##########~~~####~~~################~~~~~########\n
##########~~~####~~~###############~~~~~~########\n
#####~~~~~~~~~~~~~~~~~~~~~########~~~#~~~########\n
#####~~~~~~~~~~~~~~~~~~~~~#######~~~##~~~########\n
#####~~~~~~~~~~~~~~~~~~~~~############~~~########\n
##########~~~####~~~##################~~~########\n
##########~~~####~~~##################~~~########\n
##########~~~####~~~##################~~~########\n
#####~~~~~~~~~~~~~~~~~~~~~############~~~########\n
#####~~~~~~~~~~~~~~~~~~~~~############~~~########\n
#####~~~~~~~~~~~~~~~~~~~~~############~~~########\n
##########~~~####~~~##################~~~########\n
##########~~~####~~~#############~~~~~~~~~~~~~###\n
##########~~~####~~~#############~~~~~~~~~~~~~###\n
#################################################\n
  *
  * Project: HASH::ONE (HbbTV Application SHrink OIPF Native Extension layer)
  *
  * Author(s): ssundaramp@rediffmail.com
  *
  * @file xaitcollector.cpp
  * @brief Implementation of XAITCollector class
  *
  */

// User headers
#include "xaitcollector.h"

namespace HASH {
namespace ONE {

/// XAITCollector Implementation
XAITCollector* XAITCollector::createInstance(std::string url, bool isRead)
{
   XAITCollector* collector;
   if ((url.find("file://")==0)) {
      collector = new XAITFileCollector(url, isRead);
   } else if ((url.find("http://")==0)) {
      collector = new XAITHttpCollector(url, isRead);
   } else if ((url.find("dvb://")==0)) {
      collector = new XAITDvbCollector(url, isRead);
   } else {
      collector = new XAITFileCollector(url, isRead);
   }
   return collector;
}

void XAITCollector::destoryInstance(XAITCollector* inst)
{
   inst->close();
   delete (inst);
}

/// XAITFileCollector Implementation
bool XAITFileCollector::open()
{
   const char *mode = isReadMode() ? "rb" : "wb";
   const char *fname = getFileUrl().c_str();
   printf("\n*** open(%s,%s) called ***\n",fname,mode);
   FILE *fp = fopen(fname, mode);
   if (isNull(fp)) {
      return false;
   }
   fileHandle(reinterpret_cast<OpaqueHandle>(fp));
   return true;
}

bool XAITFileCollector::read(char* buftoread, int sizetoread, int &readsize)
{
   FILE *fp = reinterpret_cast<FILE*>(fileHandle());
   if (isNull(fp)) {
      return false;
   }
   fread(buftoread, sizetoread, 1, fp);
   readsize = ftell(fp);
   printf("\n*** read() called *** [%d]\n",readsize);
   return true;
}

bool XAITFileCollector::write(char* buftowrite, int sizetowrite, int &writtensize)
{
   FILE *fp = reinterpret_cast<FILE*>(fileHandle());
   if (isNull(fp)) {
      return false;
   }
   writtensize = fwrite(buftowrite, sizetowrite, 1, fp);
   return true;
}

bool XAITFileCollector::close()
{
   FILE *fp = reinterpret_cast<FILE*>(fileHandle());
   if (isNull(fp)) {
      return false;
   }
   fclose(fp);
   fileHandle(NULL);
   return true;
}

/// XAITHttpCollector Implementation
bool XAITHttpCollector::open()
{
   return false;
}

bool XAITHttpCollector::read(char* buftoread, int sizetoread, int &readsize)
{
   return false;
}

bool XAITHttpCollector::write(char* buftowrite, int sizetowrite, int &writtensize)
{
   return false;
}

bool XAITHttpCollector::close()
{
   return false;
}

/// XAITDvbCollector Implementation
bool XAITDvbCollector::open()
{
   return false;
}

bool XAITDvbCollector::read(char* buftoread, int sizetoread, int &readsize)
{
   return false;
}

bool XAITDvbCollector::write(char* buftowrite, int sizetowrite, int &writtensize)
{
   return false;
}

bool XAITDvbCollector::close()
{
   return false;
}

}
}

