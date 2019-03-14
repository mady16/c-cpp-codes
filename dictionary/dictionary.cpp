#include <iostream>
#include "dictionary.h"
using namespace std;

int main () {

   Dictionary <int> dict (3);
   dict.push ("Simon", 25);
   dict.push ("Maria", 19);
   dict.push ("Dilian", 54);
   
   cout << "Size of the dictionary: " << dict.length() << endl;
   dict.print ();
   cout << "dict [\"Simon\"] = " << dict ["Simon"] << endl;
   cout << "dict.get (\"Maria\") = " << dict.get ("Maria") << endl;
   cout << dict.exists ("Dilian") << endl;
   dict.remove ("Simon");
   dict.print ();
   dict.pop ();
   dict.print ();

   return (0);
}