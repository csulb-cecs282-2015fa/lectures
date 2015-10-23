#include <iostream>
#include <string>

using namespace std;

void StringByValue(string s);
void StringByPointer(string *p);
void StringByReference(string &r);
void StringByConstReference(const string &c);

int main() {
   string longString = "Suppose I have a long string like this. Every character "
      "needs 1 byte of memory. This string is still small in the grand scheme "
      "of things, so just imagine a very very long string.";

   // What happens in memory when I pass this variable to a function? Remember
   // the rules...

   StringByValue(longString);
   cout << longString << endl;

   // How much memory is used by a pointer?
   StringByPointer(&longString);
   cout << longString << endl;

   StringByReference(longString);
   cout << longString << endl;

   // Before continuing, the "const" keyword can be applied to a declaration
   // to mark a variable as "const" -- that is, its value CANNOT change.
   const string cantChange = "This string cannot change";
   // I can't assign a new value
   // cantChange = "New value";  ERROR: cantChange is const
   // I can't call methods that change the value
   // cantChange.append("Append this!");  ERROR: cannot call a non-const method
   // This is 100% COMPILER ENFORCED


   // What if I want to pass my long string to a method WITHOUT copying it...
   // but I don't want the method to be able to modify the string?
   // 1. Can't use pointer -- WHY?
   // 2. Can't use reference -- WHY?
   // 3. CAN use "const reference"!
   StringByConstReference(longString);
}

void StringByValue(string s) {
   s = "What is this changing?";
}

void StringByPointer(string *p) {
   p->append(" Remember what append does? What variable is changing?");
}

void StringByReference(string &r) {
   r.append(" Don't be confused by the syntax. A & when declaring a variable "
      "declares a reference. A reference is like a pointer, in that any change "
      "to the reference changes the thing it refers to. The difference is the "
      "syntax");

   // A reference does not need a * to dereference; attempting ot use the 
   // reference variable's value will defereference it automatically.

   // Why are there two syntaxes for doing this?
}


void StringByConstReference(const string &c) {
   // Can't modify c *at all*.
   // c is not a duplicate, it is a reference to another string.
   // So we save memory, while promising to not change the value. 
   // Best of both worlds!

   cout << c.size() << endl;
}