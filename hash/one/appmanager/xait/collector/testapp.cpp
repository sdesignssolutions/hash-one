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

// User headers
#include "xaitcollector.h"

using namespace HASH;
using namespace ONE;
using namespace std;

int main()
{
   char src[2048];
   //char *buf = &src;
   int readen, written;
   XAITCollector *reader = XAITCollector::createInstance("/proc/meminfo",true);
   bool stat = reader->open();
   cout << "Open() Return Status: "<<stat<<endl;
   stat = reader->read(src, 2048, readen);
   src[readen] = '\0';
   cout << "read() Return Status: "<<stat<<endl;
   cout << "Read size: "<<readen<<endl;
   cout << "Buffer: "<<src<<endl;
   reader->close();

   XAITCollector *writer = XAITCollector::createInstance("meminfo.txt",false);
   stat = writer->open();
   cout << "Open() Return Status: "<<stat<<endl;
   stat = writer->write(src, readen, written);
   cout << "write() Return Status: "<<stat<<endl;
   cout << "write size: "<<written<<endl;
   writer->close();

   XAITCollector::destoryInstance(reader);
   XAITCollector::destoryInstance(writer);

   return 0;
}

