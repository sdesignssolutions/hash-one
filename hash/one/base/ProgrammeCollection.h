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
  * @file ProgrammeCollection.h
  * @brief About ProgrammeCollection class in OIPF-DAE
  *
  * Reference: OIPF-T1-R2-Specification-Volume-5-Declarative-Application-Environment-v2_3-2014-01-24.pdf
  * Sections: 7.16.3(Page:274)
  *
  */
#ifndef _hash_one_oipfbase_programmecollection_h_
#define _hash_one_oipfbase_programmecollection_h_

#pragma once

// System headers
#include <stdio.h>
#include <iostream.h>
#include <string.h>

// User headers
#include "common/datatypes.h"
#include "base/Channel.h"

namespace HASH {
namespace ONE {

typedef class ProgrammeCollectionClass* ProgrammeCollection;

/// @class ProgrammeCollectionClass
/// @brief The ProgrammeCollection class represents a collection of Programme objects. See Annex K for the definition of the collection template
class ProgrammeCollectionClass {
   public:
     /// @brief To initialize all the properties of ProgrammeCollectionClass class
     virtual ProgrammeCollectionClass() {};

     /// @brief To deinitialize all the properties of ProgrammeCollectionClass class
     virtual ~ProgrammeCollectionClass() {};

     /// @brief To get the number available channels in the list
     /// @return returns the number of channels available in the list
     virtual Integer length() { return 0 };

     /// @brief Return the item at position index in the collection, or null if no item is present at that position
     /// @param channelID - The index of the item that SHALL be returned
     /// @return returns the Programme in the list that matches the given index, otherwise null
     virtual Programme item(Integer index) { return NULL };
};

}
}

#endif //_hash_one_oipfbase_programmecollection_h_

