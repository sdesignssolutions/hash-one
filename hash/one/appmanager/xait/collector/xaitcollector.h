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
  * @file xaitcollector.h
  * @brief Platform Implementation of XAIT Collector
  *
  */
#ifndef _hash_one_pclinux_platform_xaitcollector_h_
#define _hash_one_pclinux_platform_xaitcollector_h_

#pragma once

// System headers
#include <stdio.h>
#include <iostream>
#include <string.h>

// User headers
//#include "common/datatypes.h"

namespace HASH {
namespace ONE {

typedef void* OpaqueHandle;
#define isNull(_prop)      (_prop == NULL)

/// @class XAITCollector
/// @brief The XAITCollector class is used to collect the resource from various medium
class XAITCollector {
   protected:
     /// @brief To initialize all the properties of XAITCollector class
     XAITCollector(std::string url, bool isRead)
        : m_url(url)
        , m_readMode(isRead)
        , m_fileHandle(NULL) {
     }

     /// @brief To deinitialize all the properties of XAITCollector class
     ~XAITCollector() {};

   protected:
     std::string getFileUrl() const { return m_url;}
     OpaqueHandle fileHandle() { return m_fileHandle; }
     void fileHandle(OpaqueHandle handle) { m_fileHandle = handle; }
     bool isReadMode() const { return m_readMode; }

   public:
     /// @brief Open the platform file handle for the given physical file
     /// @return returns true if the call success, otherwise false
     virtual bool open() = 0;

     /// @brief Read the file from platform
     /// @param buftoread - User has to give the preallocated buffer to read the content
     /// @param sizetoread - User has to give the size how much data has to read from the file system
     /// @param readsize - Output param to mentioned about how much data getting read from the file system
     /// @return returns true if the call success, otherwise false
     virtual bool read(char* buftoread, int sizetoread, int &readsize) = 0;

     /// @brief Write into the platform
     /// @param buftowrite - User has to give the actual buffer to write into the file
     /// @param sizetowrite - User has to give the size how much date has to write into the file system
     /// @param writtensize - Output param to mentioned about how much data getting written from the buftowrite param
     /// @return returns true if the call success, otherwise false
     virtual bool write(char* buftowrite, int sizetowrite, int &writtensize) = 0;

     /// @brief Close the platform file handle for the given physical file
     /// @return returns true if the call success, otherwise false
     virtual bool close() = 0;

   public:
     static XAITCollector* createInstance(std::string url, bool isRead);
     static void destoryInstance(XAITCollector* inst);

   private:
      std::string         m_url;
      bool        m_readMode;
      OpaqueHandle   m_fileHandle;
};

/// @class XAITFileCollector
/// @brief The XAITFileCollector class is used to collect the resource from file medium
class XAITFileCollector : public XAITCollector {
   public:
     /// @brief To initialize all the properties of XAITFileCollector class
     XAITFileCollector(std::string url, bool isRead)
        : XAITCollector(url, isRead) {
     }

     /// @brief To deinitialize all the properties of XAITFileCollector class
     ~XAITFileCollector(){};

     /// @brief Open the platform file handle for the given physical file
     /// @return returns true if the call success, otherwise false
     bool open();

     /// @brief Read the file from platform
     /// @param buftoread - User has to give the preallocated buffer to read the content
     /// @param sizetoread - User has to give the size how much data has to read from the file system
     /// @param readsize - Output param to mentioned about how much data getting read from the file system
     /// @return returns true if the call success, otherwise false
     bool read(char* buftoread, int sizetoread, int &readsize);

     /// @brief Write into the platform
     /// @param buftowrite - User has to give the actual buffer to write into the file
     /// @param sizetowrite - User has to give the size how much date has to write into the file system
     /// @param writtensize - Output param to mentioned about how much data getting written from the buftowrite param
     /// @return returns true if the call success, otherwise false
     bool write(char* buftowrite, int sizetowrite, int &writtensize);

     /// @brief Close the platform file handle for the given physical file
     /// @return returns true if the call success, otherwise false
     bool close();
};

/// @class XAITHttpCollector
/// @brief The XAITHttpCollector class is used to collect the resource from http medium
class XAITHttpCollector : public XAITCollector {
   public:
     /// @brief To initialize all the properties of XAITHttpCollector class
     XAITHttpCollector(std::string url, bool isRead)
        : XAITCollector(url, isRead) {
     }

     /// @brief To deinitialize all the properties of XAITHttpCollector class
     ~XAITHttpCollector(){};

     /// @brief Open the platform file handle for the given http file
     /// @return returns true if the call success, otherwise false
     bool open();

     /// @brief Read the file from http
     /// @param buftoread - User has to give the preallocated buffer to read the content
     /// @param sizetoread - User has to give the size how much data has to read from the file system
     /// @param readsize - Output param to mentioned about how much data getting read from the file system
     /// @return returns true if the call success, otherwise false
     bool read(char* buftoread, int sizetoread, int &readsize);

     /// @brief Write into the http
     /// @param buftowrite - User has to give the actual buffer to write into the file
     /// @param sizetowrite - User has to give the size how much date has to write into the file system
     /// @param writtensize - Output param to mentioned about how much data getting written from the buftowrite param
     /// @return returns true if the call success, otherwise false
     bool write(char* buftowrite, int sizetowrite, int &writtensize);

     /// @brief Close the platform file handle for the given http file
     /// @return returns true if the call success, otherwise false
     bool close();
};

/// @class XAITDvbCollector
/// @brief The XAITDvbCollector class is used to collect the resource from dvb medium
class XAITDvbCollector : public XAITCollector {
   public:
     /// @brief To initialize all the properties of XAITDvbCollector class
     XAITDvbCollector(std::string url, bool isRead)
        : XAITCollector(url, isRead) {
     }

     /// @brief To deinitialize all the properties of XAITDvbCollector class
     ~XAITDvbCollector(){};

     /// @brief Open the platform file handle for the given physical file
     /// @return returns true if the call success, otherwise false
     bool open();

     /// @brief Read the file from dvb
     /// @param buftoread - User has to give the preallocated buffer to read the content
     /// @param sizetoread - User has to give the size how much data has to read from the file system
     /// @param readsize - Output param to mentioned about how much data getting read from the file system
     /// @return returns true if the call success, otherwise false
     bool read(char* buftoread, int sizetoread, int &readsize);

     /// @brief Write into the dvb
     /// @param buftowrite - User has to give the actual buffer to write into the dvb
     /// @param sizetowrite - User has to give the size how much date has to write into the file system
     /// @param writtensize - Output param to mentioned about how much data getting written from the buftowrite param
     /// @return returns true if the call success, otherwise false
     bool write(char* buftowrite, int sizetowrite, int &writtensize);

     /// @brief Close the platform file handle for the given dvb file
     /// @return returns true if the call success, otherwise false
     bool close();
};

}
}

#endif //_hash_one_pclinux_platform_xaitcollector_h_

