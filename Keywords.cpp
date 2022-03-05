//
// Created by rrluc on 2/28/2022.
//

#include "Keywords.h"

Keywords::Keywords() {

}
void Keywords::getKeywordsFromSampleFile(char *fileName) {
    ifstream keywordFile(fileName);     // read the file
    char oneLineOfData[80];     // one line of data with up to 80 characters
    while (keywordFile.getline(oneLineOfData, 80, '\n')) {  //
        for (int i = 0; i < strlen(oneLineOfData); ++i) {
            oneLineOfData[i] = tolower(oneLineOfData[i]);
        }
        keywords.pushBack(DSString(oneLineOfData));
    }
}

void Keywords::readBookFile(char *fileName) {
    char oneLineOfData[150];               // one line to be 150 characters
    ifstream bookFile(fileName);        // read the book file
    int pageNumber{0};                    // page numbers
    while (bookFile.getline(oneLineOfData, 150, '\n')) {    // while the line contains less than 150 chars
        if (oneLineOfData[0] == '<') {
            pageNumber = int(oneLineOfData[1]);
        }
        else {
            for (int i = 0; i < strlen(oneLineOfData); ++i) {
                oneLineOfData[i] = tolower(oneLineOfData[i]);
            }
            DSString lineOfWords = DSString(oneLineOfData);
            for (int i = 0; i < keywords.getVectorSize(); ++i) {           // iterate through each keyword
                if (lineOfWords.does_contain_keyword(keywords[i])) {    // check if the keyword is within the oneLineOfDate

                }
        }
    }
}
