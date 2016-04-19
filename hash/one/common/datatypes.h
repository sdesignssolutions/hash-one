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
  * Reference: Own Implementation
  *
  */

#ifndef _hash_one_common_datatypes_h_
#define _hash_one_common_datatypes_h_

#pragma once

#include <iostream.h>
#include <string.h>

typedef std::string String;
typedef int Integer;
typedef bool Boolean;
typedef double Number;
typedef void* OpaqueHandle;

typedef std::vector<String> StringCollection;

#define READONLY /*readonly*/

#define isNull(_prop)      (_prop == NULL)
#define isNotNull(_prop)   !isNull(_prop)
#define setNull(_prop)     (_prop = (void*)NULL)
#define isTrue(_expr)      (_expr == true)

#endif //_hash_one_common_datatypes_h_

