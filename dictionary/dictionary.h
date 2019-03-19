#include <iostream>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

string delete_spaces (string data);

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

   Dictionary (string data) {
      this->size = 10e5;
      top = -1;
      keys = new string [size];
      values = new T [size];

      string trim_data = delete_spaces (data);
      int n = trim_data.length ();
      char result [n + 1]; 
      bool is_key = true;
      string key, value;
      strcpy (result, trim_data.c_str());

      //string to process
      cout << result << endl;


      // for (int i=0; i<data.length (); i++) {

      //    cout << "key = " << key;
      //    cout << "value = " << value;

      //    while (is_key) {
      //       if (data.at(i) == ":") {
      //          is_key = false;
      //          value.clear ();
      //       }
      //       else {

      //          while (is_key) {
      //             key.append (data[i]);
      //          }

      //          while (!is_key) {
      //             value-append (data[i]);
      //          }
      //       }
      //    }
      // }
   }
   
   //DESTRUCTOR
   ~Dictionary () {
      delete []keys;
      delete []values;
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
            
      cout << "Dictionary: {" << endl;
      for (int i=0; i<=top; i++)
         cout << "  " << "[\"" << keys[i] << "\"] = " << values[i] << endl;
      cout << "}" << endl;   
   }

   T get (string key) {

      int index = search (key);
      return (values [index]);
   }

   bool exists (string key) {

      int index = search (key);
      return (index != -1);
   }

   void push (string key, T value) {

      if (is_full ()) cout << "Dictionary is full" << endl;

      else {
         keys[++top] = key;
         values[top] = value; 
      }  
   }

   void pop () {

      if (is_empty ()) cout << "Dictionary is empty." << endl;
      else top -= 1;
   }

   void remove_item (string key) {

      int index = search (key);

      for (int i=index; i<top; i++) {
         keys [i] = keys [i+1];
         values [i] = values [i+1];
      }
      top--;
   }

   void clear () {
      top = -1;
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

string delete_spaces (string str) {

   string new_data;
   str.erase (remove (str.begin (), str.end (), ' '), str.end ()); 
   return (str.substr (1, str.length () - 2));
}