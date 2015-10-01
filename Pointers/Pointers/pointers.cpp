#include <iostream>
using namespace std;

// Basics of pointers in C++

void ChangeValue(int);
void ChangePointer(int *); 
void ChangeTwoPointers(int *, int *);

int main(int argc, char* argv[]) {
   int x = 5, y = 100; // normal int variables

   // A "pointer" is a special variable that "points" to another variable.
   // Pointers are initialized by assigning the *address* of another variable of
   // the same type.


   int *p;
   // p is a variable of type "pointer to int."
   // The * indicates a pointer variable. Whitespace doesn't matter.
   // int * p, int* p, int *p -- all the same.
   // Like all variables, p has a garbage value until it is assigned something.

   // We assign the addresses of variables to pointers.
   p = &x; // & means "address of"; &x means "address of x". assigning &x to p
           // makes p point to x.
   
   /*
   To change the VALUE of the thing p points to, we use the * operator on p to
   "de-reference" the pointer. This gives us access to the actual memory that
   it points to. We can then read or write to that memory as usual.
   */
   
   cout << *p << endl; // Read the value of the thing that p points to.
   *p = 10; // Assign a value to the thing that p points to. 

   // We can declare and initialize a pointer in one line:
   int *p2 = &x;
   
   // Pointers are type-safe, somewhat: can't assign int* to double*
   // double *cant = &x; // error: cannot convert from 'int *' to 'double *'

   // But you can assign one pointer to another
   int *otherPointer = p;
   // This line DECLARES a pointer and INITIALIZES IT to point to the thing 
   // p points to.
   *otherPointer = 100; // what does this change?

   /* 
   THIS IS IMPORTANT!
   When you copy or assign pointer A to pointer B, you are making B point to the
   same thing that A points to.
`   */

   /* 
   MINI QUIZ:
   Which of these statements will not compile?

   int *a = &x;
   int *b = &a;
   int *c = 10;
   short *d = &x;
   int *e = *a;
   */

   // Pointers can be made to "point" to something else by assigning them a 
   // new address.
   p = &y; // this does not change x's value; it makes p "point to" y
   *p = 40;  // what actual variable changed?

   // What does this output now?
   cout << "*p is: " << *p << " -- y is: " << y << endl;

   /*
   Pointers can be passed to functions. This allows the function to change a 
   parameter so that the caller sees the change.

   Before passing pointers as arguments, review passing "normal" variables.
   */
   ChangeValue(x); // x has value 100 before this call; what about after?
                   // That's because variables are passed to functions...
                   // BY ____________ (fill in the blank).

   /*
   Because the "value" of a pointer is a memory address, when a pointer is
   passed by value, the address of the thing it points to is copied to the
   parameter, creating a pointer that points to the same thing as what the
   argument points to.
   */
   ChangePointer(p); 
   // The address p points to is copied to the function's parameter...
   // then what?
   cout << "After function, *p == " << *p << endl;

   // It is more common to pass &y directly to the function.
   ChangePointer(&y);
   cout << "After function, y and *p == " << *p << " (" << y << ")"
      << endl;

   
   ChangeTwoPointers(&x, &y);
   
   return 0;
}

void ChangeValue(int v) {
   v = 500;
}

void ChangePointer(int *p) {
   *p = 1000;
}

void ChangeTwoPointers(int *p1, int *p2) {
   *p1 = -1;
   *p2 = -2;
}