#include <cstdlib>                                                      // EXIT_SUCCESS
#include <string>                                                       // std::string
#include <iostream>                                                     // std::cout
#include <vector>                                                       // std::vector
#include <list>                                                         // std::list
#include <random>                                                       // std::random_device, std::default_random_engine, std::uniform_int_distribution

int main() {                                                            // entrypoint of the program

// ====================
// variables
// ====================
// boolean
    bool                boolean1 {true};                                // true or false                                    1 byte
// char
    char                char1 {'a'};                                    // -127         to 127          or 0 to 255      >= 1 byte
    signed char         char2 {'a'};                                    // -127         to 127                              1 byte
    unsigned char       char3 {'a'};                                    // 0            to 255                              1 byte
// short (int)
    short               short1 {1};                                     // -32768       to 32767                         >= 2 byte
    short int           short2 {1};                                     //                              (same as short)     2 byte
    signed short        short3 {1};                                     // -32768       to 32767        (same as short)     2 byte
    unsigned short      short4 {1};                                     // 0            to 65535                            2 byte
// int
    int                 int1 {1};                                       // -2147483648  to 2147483647                    >= 4 bytes
    signed int          int2 {1};                                       //                              (same as int)       4 bytes
    unsigned int        int3 {1};                                       // 0            to 4294967295                       4 bytes
    // int8_t           int4 {1};                                       // 2 byte                       (not supported in all c++ implementations)
    // int16_t          int5 {1};                                       // 4 byte       (same as int)   (not supported in all c++ implementations)
    // int32_t          int6 {1};                                       // 8 byte                       (not supported in all c++ implementations)
    // int64_t          int7 {1};                                       // 16 byte                      (not supported in all c++ implementations)
// long (int)
    long                long1 {1};                                      // -2147483648  to 2147483647                    >= 8 byte
    long int            long2 {1};                                      //                              (same as long)      8 byte
    signed long         long3 {1};                                      //                              (same as long)      8 byte
    unsigned long       long4 {1};                                      // 0            to 4294967295                       8 byte
// float
    float               float1 {1.0};                                   //                                                  4 bytes
// double
    double              double1 {1.0};                                  //                                                  8 bytes
// string
    std::string         string1 = "This is a String";                   //                              (library <string> needed)
    int                 string1_size = string1.size();                  // size of string   -> size()   used most common for bytes
    // int              string1_length = string1.length();              // same as size()   -> length() used most common for letters
    std::string         string2 {"String 2" + string1};                 // link or chain strings
// list
    std::list<int>      list1 {1, 2, 3, 4, 5};                          // list of int elements         (library <list> needed)
                                                                        // try using vectors instead of lists for performance reasons !!!
// vector
    std::vector<int>    vec1 {1, 2, 3, 4, 5};   // -> prefered method   // vector of int elements       (library <vector> needed)
// array
    int array1 [5] {1, 2, 3, 4, 5};                                     // array of int elements
    int array2 [2][5]   {
                            {10, 11, 12, 13, 14},  // 0                 // multidimensional array of int elements
                            {20, 21, 22, 23, 24}   // 1                 // to get the 22  -> array2[1][2]
                        };//  0,  1,  2,  3,  4
    // char array3 [string2.length()];

// ====================
// declaration
// ====================
    int             int8 = 1;                                           // create of an integer in two steps. 1.: zero-initialization; 2.: allocation with 1
    int             int9 {1};    // => overall prefered method!         // create of an integer in one step.  1.: initialization with 1
    int             int10 (1);                                          // create of an integer with constructor initialization
    // int int11, int12, int13;                                         // create multiple integers

    // std::string     string3 {u8"This is a String"};                  // u8 = utf8                    (not supported in all c++ implementations)

// ====================
// terminal output
// ====================

// kill not used warnings
    int int14 = int1 + int2 + int3 + int8 + int9 + int10 + (int)short1 + (int)short2 + (int)short3 + (int)short4;
    int14 += (int)long1 + (int)long2 + (int)long3 + (int)long4 + (int)float1 + (int)double1 + string1_size + array1[1] + array2[1][2];
//

    std::cout << "This is a Terminal output with a variabe: " << std::to_string(int14) << std::endl;
    std::cout << string1 << " " << string2 << " " << char1 << char2 << char3 << '\n';

// ====================
// conditions
// ====================

// if else
    if (boolean1 == false) {
        int1++;                 // do something
    } else if (int1 > 2 ) {
        int1--;                 // do something
    } else {
        int1 = 1;               // do something else
    }

// switch (case)
    switch (int1) {
        case 1 :
            int1++;             // do something
            break;              // break is needed, because otherwise the case 2 block would also be passed
        case 2 :
            int1--;             // do something
            break;              // break is needed, because otherwise the default block would also be passed
        default:
            int1 = 1;           // do something if nothing matches
            break;
    }

// ====================
// loops
// ====================

// for
    for (size_t i = 0; i < int1 ; ++i) {                                // size_t is typically used for arrays or loop counts (= unsigned int)
        std::cout << "Number: " << i << '\n';
    }

    // std::string        string1 = "This is a String";
    std::string::iterator it_string1_begin = string1.begin();           // pointer to the first iterator (position) of string  -> output with *it_string1_begin
    std::string::iterator it_string1_end = string1.end();               // pointer to the last iterator (position) of string   -> output with *it_string1_end
    for (std::string::iterator it = it_string1_begin; it != it_string1_end; it++) {
        std::cout << *it;           // prints the string
    }
    std::cout << std::endl;

    for (int e: array1) {        // -> prefered for vectors and arrays  // go through all elements (e) in vec1
        std::cout << "Vector Element: " << e << '\n';
    }

// while
    // std::vector<int>        vec1 {1, 2, 3, 4, 5};
    std::vector<int>::iterator it_vec1_begin = vec1.begin();            // pointer to the first vector int element  -> output with *it_vec1_begin
    std::vector<int>::iterator it_vec1_end = vec1.end();                // pointer to the last vector int element   -> output = error because it's empty
    while (it_vec1_begin != it_vec1_end) {
        std::cout << *it_vec1_begin;
        it_vec1_begin++;
    }
    std::cout << std::endl;

// do while
    it_vec1_begin = vec1.begin();
    do {                                                                // difference:
        std::cout << *it_vec1_begin;                                    //     while:       loop maybe running 0 times if condition doesn't match
        it_vec1_begin++;                                                //     do while:    loop is running at least once even if the condition doesn't match!
    } while (it_vec1_begin != it_vec1_end);
    std::cout << std::endl;

    return EXIT_SUCCESS;                                                // return 0 (success)           (library <cstdlib> needed)
}

// ====================
// functions
// ====================

// get random number
int get_random(int begin, int end) {                                    // create a random number between begin, end
    std::random_device rd;                                              // Einen "seed" erzeugen        (library <random> needed)
    std::default_random_engine rengine(rd());                           // define default random engine
    std::uniform_int_distribution<int> udist(begin, end);               // define udist
    return udist(rengine);                                              // return number
}
