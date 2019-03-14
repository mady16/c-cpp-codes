#include <iostream>
using namespace std;

template <class T> class Dictionary {
   
   private:
   int size, top;
   string *keys;
   T *values;

   public: 
   //CONSTRUCTORS
   Dictionary () {
      this->size = 10e5;
      top = -1;
      keys = new string [size];
      values = new T [size];
   }

   Dictionary (int size) {
      this->size = size;
      top = -1;
      keys = new string [size];
      values = new T [size];
   }
   
   //DESTRUCTOR
   ~Dictionary () {
      delete []keys;
      delete []values;
   }

   void push (string key, T value) {

      if (is_full ()) cout << "Dictionary is full" << endl;

      else {
         keys[++top] = key;
         values[top] = value; 
      }  
   }

   int length () {
      return (top + 1);
   }

   bool is_full () {
      return (top == size - 1);
   }

   bool is_empty () {
      return (top == -1);
   }

   void print () {
      
      if (is_empty ()) cout << "Dictionary is empty" << endl;
      
      cout << "{" << endl;
      for (int i=0; i<=top; i++)
         cout << "  " << "[\"" << keys[i] << "\"] = " << values[i] << endl;
      cout << "}" << endl;   
   }

   T operator [] (string key) {

      int index = search (key);
      return (values [index]);
   }

   //AUXILIARY FUNCTIONS 
   int search (string key) {

      int index;
      bool found = false;

      for (int i=0; i<size; i++) {

         if (keys [i] == key) {
            index = i;
            i = size+1;
            found = true;
         }
      }

      if (found) return (index);
      else return (-1);
   }
};

int main () {

   Dictionary <int> dict (3);
   dict.push ("Simon", 25);
   dict.push ("Maria", 19);
   
   cout << "Size of the dictionary: " << dict.length() << endl;
   cout << "Dictionary: ";
   dict.print ();
   cout << dict ["Simon"];

   return (0);
}