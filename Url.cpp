/**
 * @file: Url.cpp
 * @assignment_name: 02: Try it out: Dynamic Strings
 * @author: Rick Smith (rickysmith@mail.weber.edu)
 * @start-date: 11/07/2022
 * @finish-date: 11/09/2022
 * @brief: This program will cover Inheritance and Memory Management with dynamic allocated memory.
 *
 */


#include "Url.h"




//<scheme>://<authority>/<path>
//When comparing two urls, the scheme and authority are case-insensitive but the path is case-sensitive.

int Url::compare(const Url& other){
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