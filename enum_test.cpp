#include <iostream>
using namespace std;
enum months_t { january, february, march, april, may, june, july, august, september,    
  october, november, december} y2k;

 int main ()
  {
    cout << "sizeof months_t is  " << sizeof(months_t) << endl;
    cout << "sizeof y2k is  " << sizeof(y2k) << endl;
    enum months_t1 { january, february, march, april, may, june, july, august,    
       september, october, november, december} y2k1;
    cout << "sizeof months_t1 is  " << sizeof(months_t1) << endl;
    cout << "sizeof y2k1 is  " << sizeof(y2k1) << endl;
 }
