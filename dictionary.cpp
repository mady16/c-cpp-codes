#include <iostream>
using namespace std;

template <class T> class Dictionary {
   
   private:
      int size, top;
      string *keys;
      T *values;

   public: 
      Dictionary (int size) {
         this->size = size;
         top = -1;
         keys = new string [size];
         values = new T [size];
      }
      
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

      bool is_full () {
         return (top == size - 1);
      }

      bool is_empty () {
         return (top == -1);
      }

      void print () {
         
         if (is_empty ()) cout << "Dictionary is empty" << endl;
         for (int i=0; i<top; i++)
            cout << "[\"" << keys[i] << "\"] = " << values[i] << endl;
         cout << endl;   
      }

      T operator [] (string key) {

         for (int i=0; i<size; i++)
            if (keys [i] == key) return (values [i]);

         return (-1);
      }
};

int main () {

   Dictionary <int> dict (3);
   dict.push ("Simon", 25);
   dict.push ("Maria", 19);
   dict.print ();

   return (0);
}