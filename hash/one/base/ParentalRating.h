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
  * @file ParentalRating.h
  * @brief About ParentalRating class in OIPF-DAE
  *
  * Reference: OIPF-T1-R2-Specification-Volume-5-Declarative-Application-Environment-v2_3-2014-01-24.pdf
  * Sections: 7.9(Page:157)
  *
  */
#ifndef _hash_one_common_parentalrating_h_
#define _hash_one_common_parentalrating_h_

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

typedef class ParentalRatingClass* ParentalRating;

namespace ParentalRatingConstants {
   ///< \enum of ChannelType enumeration
   typedef enum {
      LABEL_SEXUAL_SUGGESTIVE_DIALOG  = 1,   /// Indicates that a content item features sexual suggestive dialog
      LABEL_STRONG_LANGUAGE           = 2,   /// Indicates that a content item features strong language
      LABEL_SEXUAL_SITUATIONS         = 4, /// Indicates that a content item features sexual situations
      LABEL_VIOLENCE                  = 8, /// Indicates that a content item features violence
      LABEL_FANTASY_VIOLENCE          = 16, /// Indicates that a content item features fantasy violence
      LABEL_DISTURBING_SCENES         = 32, /// Indicates that a content item features disturbing scenes
      LABEL_PORTRAYALS_DISCRIMINATION = 64, /// Indicates that a content item features portrayals of discrimination
      LABEL_ILLEGAL_DRUG_USE_SCENES   = 128, /// Indicates that a content item features scenes of illegal drug use
      LABEL_STROBING                  = 256, /// Indicates that a content item features strobing that could impact viewers suffering from Photosensitive epilepsy
   }ParentalLabelsEnum;
};

/// @class ParentalRatingClass
/// @brief A ParentalRating object describes a parental rating value for a programme or channel. The ParentalRating object 
/// identifies both the rating scheme in use, and the parental rating value within that scheme.  In case of a BCG the values 
/// of the properties in this object will be read from the ParentalGuidance element that is the child of a programme’s BCG description
class ParentalRatingClass {
   private:
      /// a private variable
      /// The string representation of the parental rating value for the respective rating scheme denoted by property scheme.\n
      /// Valid strings include:\n
      /// * if the value of property scheme represents one of the parental rating classification scheme names identified by [MPEG-7]: 
      ///    the string representation of one of the parental rating values as defined by one of the <Name> elements.\n
      /// * if the value of property scheme is ”urn:oipf:GermanyFSKCS” , the string representation of one the values for the 
      /// GermanyFSK rating scheme as defined in [OIPF_META2].\n
      /// * if the value of property scheme is equal to “dvb-si”, this means that the scheme of a minimum recommended age encoded 
      ///    as per ratings 0x01 to 0x0f in the parental rating descriptor from [EN 300 468], which corresponds to rating_type 0 in [IEC62455].
      /// NOTE: If the broadcaster defined range from 0x10 to 0xff is used then that would be a different parental rating scheme and not "dvb-si".
      /// An example of a valid parental rating value is “PG-13”
      READONLY String m_name;

      /// a private variable
      /// Unique name identifying the parental rating guidance scheme to which this parental rating value refers. Valid strings include:\n
      /// * the URI of one of the MPEG-7 classification schemes representing a parental rating scheme as defined by the “uri” 
      ///    attribute of one of the parental rating <ClassificationScheme> elements in [MPEG-7].\n
      /// * the string value “urn:oipf:GermanyFSKCS” to represent the GermanyFSK rating scheme as defined in [OIPF_META2].\n
      /// * the string value “dvb-si”: this means that the scheme of a minimum recommended age encoded as per [EN 300 468], 
      ///    is used to represent the parental rating values.
      READONLY String m_scheme;

      /// a private variable
      /// The parental rating value represented as an index into the set of values defined as part of the ParentalRatingScheme identified 
      /// through property “scheme”.  If an associated ParentalRatingScheme object can be found by calling method getParentalRatingScheme() 
      /// on property parentalRatingSchemes of the application/oipfParentalControlManager object and the value of property scheme is not 
      /// equal to “dvb-si”, then the value property SHALL represent the index of the parental rating value inside the ParentalRatingScheme 
      /// object, or -1 if the value cannot be found. If the value of property scheme is equal to “dvb-si”, then this property SHALL be the 
      /// integer representation of the string value of ParentalRating property name.  If no associated ParentalRatingScheme object can be 
      /// found by calling method getParentalRatingScheme on property parentalRatingSchemes of the application/oipfParentalControlManager 
      /// object, then the value property SHALL have value undefined
      READONLY Integer m_value;

      /// a private variable
      /// The labels property represents a set of parental advisory flags that may provide additional information about the rating.
      /// The value of this field is a 32 bit integer value that represents a binary mask corresponding to the sum of zero or more label 
      /// values defined in ParentalRatingConstants::ParentalLabelsEnum. If no labels have been explicitly set, the value for the “labels” 
      /// property SHALL be 0
      READONLY Integer m_labels;

      /// a private variable
      /// The region to which the parental rating value applies as an alpha-2 region code as defined in ISO 3166-1. Returns undefined 
      /// if no specific region has been defined.
      READONLY String m_region;

   public:
     /// @brief To initialize all the properties of ParentalRatingClass class
     virtual ParentalRatingClass() {};

     /// @brief To deinitialize all the properties of ParentalRatingClass class
     virtual ~ParentalRatingClass() {};
};

}
}

#endif //_hash_one_common_parentalrating_h_

