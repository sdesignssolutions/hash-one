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
  * @file log.h
  * @brief Providing an unique and stylish type of logging
  *
  * Reference: Own Implementation
  *
  */

#ifndef _hash_one_common_log_h_
#define _hash_one_common_log_h_

#pragma once

#include "common/datatypes.h"
#include <stdarg.h>

namespace HASH {
namespace ONE {

extern Trace* kTrace;

namespace TraceConstants {
   ///< \enum of TraceLogLevels enumeration
   typedef enum {
      TRACE_LEVEL_NONE      = 0,
      TRACE_LEVEL_DEBUG     = 0x0001,
      TRACE_LEVEL_ERROR     = 0x0002,
      TRACE_LEVEL_CALLER    = 0x0004,
      TRACE_LEVEL_WARNING   = 0x0008,
      TRACE_LEVEL_CRITICAL  = 0x0010,
      TRACE_LEVEL_ALL       = 0xFFFF,
   }LogLevelsEnum;
}

/// @class Trace
/// @brief A Trace is an interface of logging 
class Trace {
   private:
      TraceConstants::LogLevelsEnum m_logLevel;
   public:
      /// @brief To initialize all the properties of Trace class
      Trace ();
      /// @brief To initialize all the properties of Trace class
      /// @param level - Valid values are declared in TraceConstants::LogLevelsEnum
      Trace (TraceConstants::LogLevelsEnum level);
      /// @brief To deinitialize all the properties of Trace class
      virtual ~Trace ();
      /// @brief To setting up the log level
      /// @param level - Valid values are declared in TraceConstants::LogLevelsEnum
      void setLevel(TraceConstants::LogLevelsEnum level);
      /// @brief Getting the stored log level
      TraceConstants::LogLevelsEnum getLevel() const;
      /// @brief Method to print debug log
      int Debug(const char *fmt, ...);
      /// @brief Method to print error log
      int Error(const char *fmt, ...);
      /// @brief Method to print caller log
      int Caller(const char *fmt, ...);
      /// @brief Method to print warning log
      int Warning(const char *fmt, ...);
      /// @brief Method to print critical log
      int Critical(const char *fmt, ...);
};

}
}

#endif //_hash_one_common_log_h_

