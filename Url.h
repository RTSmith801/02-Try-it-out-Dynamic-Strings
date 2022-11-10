#ifndef URL_H
#define URL_H

#include "DynamicString.h"
#include <cstring>

class Url : public DynamicString
{

public:

    //Constructors
    Url() : DynamicString() {}
    Url(const char* str) : DynamicString(str) {


        //check for scheme
        schemeEndPos = find('/');
        //std::cout << "First position of '/' = " <<  schemeEndPos << std::endl;
        schemeEndPos = find('/', schemeEndPos + 1);
        //std::cout << "Second position of '/' = " <<  schemeEndPos << std::endl;
        authorityEndPos = find('/', schemeEndPos + 1);
        //std::cout << "Third position of '/' = " <<  authorityEndPos << std::endl;

        //std::cout << this->myArray << std::endl;
        this->toLower(authorityEndPos); // converts scheme and authority to lowercase as they are case-insensitive
        //std::cout << this->myArray << std::endl;
        if (schemeEndPos < 5){ // scheme will end at shortest valid position per test case at position 5 ie smb://

            std::cout << "No scheme found in " << this->myArray << std::endl;
            throw std::invalid_argument("Constructor requires valid URL");
        }
    }



    //You may want to store the Scheme, Authority and Path as distinct class variables for easier comparisons between strings.
    //Use the  existing DynamicString methods like find, compare and iCompare to parse and compare urls
    int compare(const Url& other);

    //<scheme>://<authority>/<path>
    //When comparing two urls, the scheme and authority are case-insensitive but the path is case-sensitive.

private:


//    DynamicString scheme;
//    DynamicString authority;
//    DynamicString path;

    int schemeEndPos;
    int authorityEndPos;


};

#endif