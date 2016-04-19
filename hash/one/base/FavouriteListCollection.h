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
  * @file FavouriteListCollection.h
  * @brief About FavouriteListCollection class in OIPF-DAE
  *
  * Reference: OIPF-T1-R2-Specification-Volume-5-Declarative-Application-Environment-v2_3-2014-01-24.pdf
  * Sections: 7.13.12(Page:231)
  *
  */
#ifndef _hash_one_oipfbase_favouritelistcollection_h_
#define _hash_one_oipfbase_favouritelistcollection_h_

#pragma once

// System headers
#include <stdio.h>
#include <iostream.h>
#include <string.h>

// User headers
#include "common/datatypes.h"

namespace HASH {
namespace ONE {

typedef class FavouriteListCollectionClass* FavouriteListCollection;

/// @class FavouriteListCollectionClass
/// @brief The FavouriteListCollectionClass class represents a list of favourite channels. See Annex K for the definition of the collection template
class FavouriteListCollectionClass {
   public:
     /// @brief To initialize all the properties of FavouriteListCollectionClass class
     virtual FavouriteListCollectionClass() {};

     /// @brief To deinitialize all the properties of FavouriteListCollectionClass class
     virtual ~FavouriteListCollectionClass() {};
};

}
}

#endif //_hash_one_oipfbase_favouritelistcollection_h_

