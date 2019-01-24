#include <iostream>
using namespace std;

namespace space1 {

  void print () {
    cout << "I'm in the first space" << endl;
  }
}

namespace space2 {

  void print () {
    cout << "I'm in the second space" << endl;
  }
}

using namespace space1;
int main () {

  print ();
  space2::print ();
  return (0);
}
