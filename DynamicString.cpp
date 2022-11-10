/**
 * @file: DynamicString.cpp
 * @assignment_name:  01 Challenge Activity: Dynamic String
 * @author: Rick Smith (rickysmith@mail.weber.edu)
 * @date: 10/20/2022 - started : 10/26/2022 - last update
 * @brief: program to demonstrate mastery of c++ classes and arrays
 *
 */

#include "DynamicString.h"
#include <cctype>
#include <stdexcept>
#include <ostream>
#include <list>

using namespace std;

using std::out_of_range;
using std::tolower;
using std::toupper;
using std::ostream;
using namespace std;
#include <cstring>

/** Default Constructor
 * Creates an empty DynamicString object
 * Initializes the cstr array to be an array of size 1
 * containing the null character
 */
DynamicString::DynamicString(){
    myArray = new char[1];
    myArray[0] = '\0';
    setLen(0); // setLen in DynamicString.h
    //std::cout << "TESTING: Default constructor called" << std::endl;
}

/**
* c-string constructor. Creates a copy of
* the provided c-string, allocating the
* required amount of memory.
* @param str the c-string to store.
*/
DynamicString::DynamicString(const char* str) {
    int len = strlen(str);
    setLen(len); // setLen in DynamicString.h
    //std::cout << "TESTING: Constructor called with length of " << len << std::endl;
    myArray = new char[len + 1];
    for (int i = 0; i <= len; i++) {
        if (i == len) {
            myArray[i] = '\0';
        }
        else{
            myArray[i] = str[i];
        }
    }
}

/**
 * c-string constructor. Creates a copy of
 * the provided c-string, allocating the
 * required amount of memory.
 * @param str the c-string to store.
 */
const char* DynamicString::c_str() const{
    return myArray;
}

/** Get a copy of the character at the specified position.
 * @param position the 0-based index to retreive.
 * @return the character at the specified position.
 */
char DynamicString::char_at(int position) const{
    //std::cout << "TESTING: char at " << position << " = " << myArray[position] << std::endl;

    if (position < 0) {
        throw out_of_range("Out of array bounds");
    }

    if (position < len()) {
        return myArray[position];
    }
    else {
        throw out_of_range("Out of array bounds");
    }
}

/** Get a reference to the character at the specified position.
 * @param position the 0-based index to retreive.
 * @return the character at the specified position.
 */
char& DynamicString::operator[](int position){

    if (position < 0) {
        throw out_of_range("Out of array bounds");
    }
    if (position < len()) {
        return myArray[position];
    }
    else {
        throw out_of_range("Out of array bounds");
    }
}

/** Returns true if other is a prefix of this string.
 * @param other the string to check as a prefix.
 * @return bool true if other is a prefix.
 */
bool DynamicString::startsWith(const DynamicString& other) const{
    int x = other.len();
    for (int i = 0; i < x; i++)
    {
        if (this->myArray[i] != other.myArray[i]) {

            return false;
        }
    }
    return true;
}

/** Returns true if other is a suffix of this string.
 * @param other the string to check as a suffix.
 * @return bool true if other is a suffix.
 */

bool DynamicString::endsWith(const DynamicString& other) const{
    int x = other.len();
    int y = this->len();
    for (int i = x - 1, e = y - 1; i >= 0; i--, e --)
    {
        if (this->myArray[e] != other.myArray[i]) {
            return false;
        }
    }
    return true;
}

/** Compares this string to other using dictionary ordering with the ascii values.
 * @param other the string to compare.
 * @return -1 if this string is smaller (comes earlier in the dictionary),
 * 0 if they are the same, and 1 if this string is larger (comes later in the
 * dictionary).
 */
int DynamicString::compare(const DynamicString& other) const{
    int x, y;
    int a = this->len();
    int b = other.len();
    int i = 0;
    do{
        x = other.myArray[i];
        y = this->myArray[i];

        //cout << "Other Array = " << x << " This Array = " << y << endl;
        if (x > y) {
            return -1;
        }
        if (x < y) {
            return 1;
        }
        if (i == b - 1) {
            if (a > b) {
                //cout << "Array len a = " << a << " Array len b = " << b << endl;
                //cout << "Array A is larger" << endl;
                return 1;
            }
            if (a < b) {
                //cout << "Array len a = " << a << " Array len b = " << b << endl;
                //cout << "Array B is larger" << endl;
                return -1;
            }
        }
        i++;
    } while (i < b);
    return 0;
}

/** Compares this string to other, ignoring case, using dictionary ordering with the ascii values.
 * @param other the string to compare.
 * @return -1 if this string is smaller (comes earlier in the dictionary), 0 if they are the same, and 1 if this string is larger (comes later in the dictionary.
 */
int DynamicString::iCompare(const DynamicString& other) const{
    char x, y;
    int a = this->len();
    int b = other.len();
    int i = 0;
    do {
        x = tolower(other.myArray[i]);
        y = tolower(this->myArray[i]);

        //cout << "Other Array = " << x << " This Array = " << y << endl;
        if (x > y) {
            return -1;
        }
        if (x < y) {
            return 1;
        }
        if (i == b - 1) {
            if (a > b) {
                //cout << "Array A is larger" << endl;
                //cout << "Array len a = " << a << " Array len b = " << b << endl;
                return 1;
            }
            if (a < b) {
                //cout << "Array len a = " << a << " Array len b = " << b << endl;
                //cout << "Array B is larger" << endl;
                return -1;
            }
            //cout << "Array len a = " << a << " Array len b = " << b << endl;
        }
        i++;
    } while (i < b);
    return 0;
}

/** Converts all characters to lowercase.
 * Contents are modified "in-place"
 * @return self (the lowercased string)
 */
DynamicString& DynamicString::toLower(){

    char ch;
    for (int i = 0; i < len(); i++) {
        ch = tolower(myArray[i]);
        myArray[i] = ch;
    }
    return *this;
}

/** Overloading toLower to only adjust characters in array up to position "endPos"
  * @return self (with lowercased string up to endPos)
  */
DynamicString& DynamicString::toLower(int endPos){

   // cout << "endPos = " << endPos << endl;
    //cout << "len() = " << len() << endl;
    if(endPos <= this->len()){
        char ch;
        for (int i = 0; i < endPos; i++) {
            ch = tolower(myArray[i]);
            myArray[i] = ch;
        }
        return *this;
    }
    else{
        throw out_of_range("Out of array bounds *DynamicString.cpp line 244");
    }
}

/** Converts all characters to uppercase.
 * Contents are modified "in-place"
 * @return self (the uppercased string)
 */
DynamicString& DynamicString::toUpper(){

    char ch;
    for (int i = 0; i < len(); i++) {
        ch = toupper(myArray[i]);
        myArray[i] = ch;
    }
    return *this;
}

/** Replaces all instances of char old with char newCh.
 * Contents are modified "in-place"
 * @return self (the string with the replaced characters)
 */
DynamicString& DynamicString::replace(char old, char newCh){
    for (int i = 0; i <= len(); i++) {
        if (myArray[i] == old) {
            myArray[i] = newCh;
        }
    }
    return *this;
}

/** Finds the first index of the character in the string
 * @param start the position of the string to start at
 * @param c the char to look for
 * @return the index of the character or -1 if the character is not found.
 */
int DynamicString::find(char c, int start) const{
    for (int i = start; i < len(); i++) {
        if (myArray[i] == c) {
            return i;
        }
    }
    return -1;
}

/** Finds the last index of the character in the string
 * @param c the char to look for
 * @param start the position of the string to start at (in reverse)
 * @return the index of the character or -1 if the character is not found.
 */
int DynamicString::reverseFind(char c, int start) const{
    for (int i = start; i >= 0; i--) {
        if (myArray[i] == c) {
            return i;
        }
    }
    return -1;
}

/** Finds the last index of the character in the string
 * @param c the char to look for
 * @return the index of the character or -1 if the character is not found.
 */
int DynamicString::reverseFind(char c) const{
    for (int i = len(); i >= 0; i--) {
        if (myArray[i] == c) {
            return i;
        }
    }
    return -1;
}

ostream& operator<<(ostream& out, const DynamicString& str) {
    out << str.myArray; // Thanks Kim!!
    return out;
}


// User defined method to test printing full array.
void DynamicString::printArray() {
    string toPrint = "";
    for (int i = 0; i < len(); i++) {
        toPrint += myArray[i];
    }

    cout << toPrint << endl;
}

/***********************************************************/
/****************02: Try it out: Dynamic Strings************/
/***********************************************************/

//Copy constructor for the DynamicString.  This creates a deep copy of the char array
//by allocating a new array and copy each character over.
DynamicString::DynamicString(const DynamicString & other){
    setLen(other.len());
    myArray = new char[len()+1];
    for(int i = 0; i <= len(); i++){ // < vs <= ?
        myArray[i] = other.myArray[i];
    }
}

//Assignment operator.  Like the copy - constructor,
//this method creates a deep copy of the char array.
//However, it also needs to clean up previous memory allocations as well as check for self - assignment.
DynamicString& DynamicString::operator=(const DynamicString & other){
    return *this;
}