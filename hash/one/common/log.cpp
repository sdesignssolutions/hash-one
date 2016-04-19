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
  * @file datatypes.h
  * @brief Providing an unique and stylish type of primitive datatypes
  *
  *
  * Reference: Own Implementation
  *
  */

#include "common/log.h"

namespace HASH {
namespace ONE {

Trace::Trace()
{
   this->m_logLevel = TraceConstants::TRACE_LEVEL_NONE;
}

Trace::Trace(TraceConstants::LogLevelsEnum level)
{
   this->m_logLevel = level;
}

void Trace::setLevel(TraceConstants::LogLevelsEnum level)
{
   this->m_logLevel = level;
}

TraceConstants::LogLevelsEnum Trace::getLevel()
{
   return this->m_logLevel;
}

int Trace::Debug(const char *fmt, ...) {
   if (this->m_logLevel&TraceConstants::TRACE_LEVEL_DEBUG == 0) {
      return -1;
   }
   va_list arg;
   va_start(arg, fmt);
   vfprintf(stdout, fmt, arg);
   va_end(arg);
   return 0;
}

int Trace::Error(const char *fmt, ...) {
   if (this->m_logLevel&TraceConstants::TRACE_LEVEL_ERROR == 0) {
      return -1;
   }
   va_list arg;
   va_start(arg, fmt);
   vfprintf(stdout, fmt, arg);
   va_end(arg);
   return 0;
}

int Trace::Caller(const char *fmt, ...) {
   if (this->m_logLevel&TraceConstants::TRACE_LEVEL_CALLER == 0) {
      return -1;
   }
   va_list arg;
   va_start(arg, fmt);
   vfprintf(stdout, fmt, arg);
   va_end(arg);
   return 0;
}

int Trace::Warning(const char *fmt, ...) {
   if (this->m_logLevel&TraceConstants::TRACE_LEVEL_WARNING == 0) {
      return -1;
   }
   va_list arg;
   va_start(arg, fmt);
   vfprintf(stdout, fmt, arg);
   va_end(arg);
   return 0;
}

int Trace::Critical(const char *fmt, ...) {
   if (this->m_logLevel&TraceConstants::TRACE_LEVEL_CRITICAL == 0) {
      return -1;
   }
   va_list arg;
   va_start(arg, fmt);
   vfprintf(stdout, fmt, arg);
   va_end(arg);
   return 0;
}

}
}

