/**
 * Fall 2021 PA 02 Template Repo.
 */

#include <iostream>
#include <fstream>
#include "DSString.h"
#include "Keywords.h"

/**
 * catch_setup.h and catch_setup.cpp contain the #define directive for
 * the CATCH2 framework.  You can see in main below how I'm calling the
 * runCatchTests() function which is declared in this header.
 *
 * On average, this should reduce the build time for your project on your local
 * machine.
 */

#include "catch_setup.h"

int main(int argc, char** argv) {
//    if(argc == 1) {
        runCatchTests();
//    }
//    else {
//        std::cout << "Hello, 2341 students!" << std::endl;
//        std::cout << "Attempting to open and write to " << argv[2] << std::endl;
//        std::ofstream o(argv[2]);
//        o << "Writing to output file." << std::endl;
//        o.close();
//  }
//    Keywords object;
//    object.getKeyWordsFromSampleFile("./data/terms.txt");
//    for (int i = 0; i < object.keywords.getVectorSize(); ++i) {
//        cout << object.keywords[i];
//    }

//Keywords readFile;
//readFile.readBookFile("./data/test_book.txt");

    return 0;
}
