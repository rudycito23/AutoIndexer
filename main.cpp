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
    if(argc == 1) {
    runCatchTests();
    }
    else {
        Keywords read;
        read.getKeywordsFromSampleFile(argv[2]);
        read.readBookFile(argv[1]);

        ofstream outputFile;
        outputFile.open(argv[3]);
        if (!outputFile.is_open()) {
            cout << "Could not open file." << endl;
            return 1;
        }
        else {
            read.printOutputFile(outputFile);
        }
    }
    return 0;
}