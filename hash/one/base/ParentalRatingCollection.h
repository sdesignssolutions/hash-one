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
  * @file ParentalRatingCollection.h
  * @brief About ParentalRatingCollection class in OIPF-DAE
  *
  * Reference: OIPF-T1-R2-Specification-Volume-5-Declarative-Application-Environment-v2_3-2014-01-24.pdf
  * Sections: 7.9.5(Page:160)
  *
  */
#ifndef _hash_one_oipfbase_parentalratingcollection_h_
#define _hash_one_oipfbase_parentalratingcollection_h_

#pragma once

// System headers
#include <stdio.h>
#include <iostream.h>
#include <string.h>

// User headers
#include "common/datatypes.h"
#include "base/ParentalRating.h"

namespace HASH {
namespace ONE {

typedef class ParentalRatingCollectionClass* ParentalRatingCollection;

/// @class ParentalRatingCollectionClass
/// @brief A ParentalRatingCollection represents a collection of parental rating values. See Annex K for the definition of the collection template.
/// In addition to the methods and properties defined for generic collections, the ParentalRatingCollection class supports the additional properties and methods defined below
class ParentalRatingCollectionClass {
   public:
     /// @brief To initialize all the properties of ParentalRatingCollectionClass class
     virtual ParentalRatingCollectionClass() {};

     /// @brief To deinitialize all the properties of ParentalRatingCollectionClass class
     virtual ~ParentalRatingCollectionClass() {};

     /// @brief To get the number available parentalrating in the list
     /// @return returns the number of parentalrating available in the list
     virtual Integer length() { return 0; };

     /// @brief Return the item at position index in the collection, or null if no item is present at that position
     /// @param channelID - The index of the item that SHALL be returned
     /// @return returns the ParentalRating in the list that matches the given index, otherwise null
     virtual ParentalRating item(Integer index) { return NULL; };

     /// @brief Creates a ParentalRating object instance for a given parental rating scheme and parental rating value, and adds it to the 
     /// ParentalRatingCollection for a programme or channel
     /// @param scheme - A unique string identifying the parental rating scheme to which this value refers. See property scheme in section 7.9.4.1 for more information about possible values
     /// @param name - A string representation of the parental rating value. See property name in section 7.9.4.1 for more information about possible values. Values are not case sensitive
     /// @param value - The parental rating value represented as an Integer. See property value in section 7.9.4.1 for more information about possible values
     /// @param labels - A set of content rating labels that may provide additional information about the rating. See property labels in section 7.9.4.1 for more information about possible values
     /// @param region - The region to which the parental rating value applies as an alpha-2 region code as defined in ISO 3166-1. The value of this argument must be null or undefined if no specific region has been identified. Values are not case sensitive
     /// @return void
     virtual void addParentalRating( String scheme, String name, Integer value, Integer labels, String region ) { return; };
};

}
}

#endif //_hash_one_oipfbase_parentalratingcollection_h_

