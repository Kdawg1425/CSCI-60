#ifndef BIGUINT_H
#define BIGUINT_H

#include <cstdlib>
#include <iostream>
#include <string>

// WANT: integers with CAPACITY digits, only non-negative
//
// support:
//    2 constructors: int, string
//    member functions:  [] returns individual digits given position
//                        +=
//                        -=
//                        compare: return +1, 0, -1, depending on
//                        whether this biguint >, ==, < than given biguint
//                        +, - (binary), - (unary), <, <=, ==, !=, >=, >
//                        <<, >>


class biguint
{
public:
    // CONSTANTS & TYPES

    static const std::size_t CAPACITY = 20;

    // CONSTRUCTORS

    // pre: none
    // post: creates a biguint with value 0
    biguint();

    // pre: s contains only decimal digits
    // post: creates a biguint whose value corresponds to given string of digits
    biguint(const std::string &);

    // CONSTANT MEMBER FUNCTIONS

    // pre: pos < CAPACITY
    // post: returns the digit at position pos
    //          0 is the least significant (units) position

    unsigned short operator [](std::size_t pos) const;

    // pre: none
    // post: returns 1 if this biguint > b
    //               0 if this biguint == b
    //              -1 if this biguint < b
    int compare(const biguint & b) const;

    //Pre: None
    //Post:: Returns a string version of the biguint that is calling this function.
    std::string toString();

    // MODIFICATION MEMBER FUNCTIONS


    // pre: none
    // post: b is added to this biguint; ignore last carry bit if any
    void operator += (const biguint & b);

    //Pre: None
    //Post: The value of the calling biguint will change to the difference of the old value
    //      minus the value of b. If b is bigger than a, the biguint calling the function
    //      will be filled with all zeros
    void operator -= (const biguint & b);



private:

    unsigned short data_[CAPACITY];

    // INVARIANTS:
    //    data_[i] holds the i^th digit of this biguint or 0 if not used
    //    data_[0] holds the least significant (units) digit
};

// nonmember functions

std::ostream& operator << (std::ostream& out, const biguint &b);

//Pre: None
//Post: Returns a new biguint that is the sum of biguint a and b.
biguint operator + (const biguint &, const biguint &);

//Pre: None
//Post: Return a new biguint that is a-b. If b is bigger than a, the biguint that is
//      returned will be all zeros
biguint operator - (const biguint &, const biguint &);

//Pre: None
//Post: Returns a boolean. If a is less than b, returns true. If not, returns false.
bool operator < (const biguint &, const biguint &);

//Pre: None
//Post: Returns a boolean. If a is less than or equal to b, returns true.
//      If not, returns false
bool operator <= (const biguint &, const biguint &);

//Pre: None
//Post: Returns a boolean. If a and b are not equal returns true. If not, returns false.
bool operator != (const biguint &, const biguint &);

//Pre: None
//Post: Returns a boolean. If a and b are equal, returns true. If not, returns false.
bool operator == (const biguint &, const biguint &);

//Pre: None
//Post: Returns a boolean. If a is bigger or equal to b, return true. If not, returns false.
bool operator >= (const biguint &, const biguint &);

//Pre: None
//Post: Returns a boolean. If a is bigger than b, returns true. Vice versa
bool operator > (const biguint &, const biguint &);




#endif // BIGUINT_H
