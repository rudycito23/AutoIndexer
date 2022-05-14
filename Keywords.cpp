//
// Created by rrluc on 2/28/2022.
//

#include "Keywords.h"

Keywords::Keywords() {

}
void Keywords::getKeywordsFromSampleFile(char *fileName) {
    ifstream keywordFile(fileName);     // read the file
    if (!keywordFile.is_open()) {
        cout << "Could not open file.";
    }
    char oneLineOfData[1000];     // one line of data with up to 80 characters
    while (keywordFile.getline(oneLineOfData, 1000, '\n')) {  // while the condition is satisfied
        keywords.pushBack(DSString(oneLineOfData));     // add data in oneLineOfData to my vector of DSString
    }
}

void Keywords::readBookFile(char *fileName) {
    char oneLineOfData[1000];               // one line = 150 characters
    ifstream bookFile(fileName);        // read the book file
    DSString pageNumber;                  // page numbers
    while (bookFile.getline(oneLineOfData, 1000, '\n')) {    // while my condition is satisfied
        for (int i = 0; i < strlen(oneLineOfData); ++i) {       // iterate through oneLineOfData
            oneLineOfData[i] = DSString::toLowerCase(oneLineOfData[i]);     // change all letters to lowercase
        }
        DSString lineOfWords = DSString(oneLineOfData);     // convert oneLineOfData(char) into a DSString lineOfWords
        if (lineOfWords.getLength() == 0) {     // do nothing
        }
        else if (lineOfWords[0] == '<') {       // if the line begins with the '<' symbol
            for (int i = 0; i < lineOfWords.getLength(); ++i) {     // iterate through the line
                if (lineOfWords[i] == '>') {       // if the line reaches the '>' symbol
                    pageNumber = lineOfWords.substring(1, i - 1);   // record what is in between the <>
                }
            }
        }
        else {
            for (int i = 0; i < keywords.getVectorSize(); ++i) {          // iterate through each keyword
                DSString currentKeywords = keywords[i];     // keywords[i] is stored in currentKeywords
                for (int j = 0; j < currentKeywords.getLength(); ++j) {     // iterate through currentKeywords
                currentKeywords[j] = DSString::toLowerCase(currentKeywords[j]);     // change keywords to lower case
                }
                if (lineOfWords.does_contain_keyword(currentKeywords)) {    // if the keyword is within oneLineOfDate
                    map<DSString, DSVector<DSString>>::iterator it;    // store the keyword and the page number
                    it = keywordsAndPageNumbers.find(keywords[i]);     // find the keywords
                    if (it == keywordsAndPageNumbers.end()) {    // if it reaches the end
                        DSVector<DSString> pageNumbers;     // create a pageNumbers vector
                        pageNumbers.pushBack(pageNumber);       // store the pageNumbers into the vector
                        // pair the keyword with its pageNumber
                        keywordsAndPageNumbers.insert(pair<DSString, DSVector<DSString>>(keywords[i], pageNumbers));
                    }
                    else {
                        it->second.pushBack(pageNumber);    // store the pageNumber in the second slot
                    }
                }
            }
        }
    }
}

void Keywords::printOutputFile(ofstream &outputFile) {
    map<DSString, DSVector<DSString>>::iterator it;    // create a map for the keyword and its pageNumbers
    char currentHeader = ' ';       // current header is nothing
    // iterate through the map
    for (it = keywordsAndPageNumbers.begin(); it != keywordsAndPageNumbers.end(); it++) {
        DSString lastPageNumberRecorded = "-1";     // temporary variable
        char firstLetterOfKeyword = DSString::toUpperCase(it->first[0]);    // capitalize the first letter of keyword
        if (currentHeader != firstLetterOfKeyword) {    // if currentHeader does not equal the firstLetterOfKeyword
            outputFile << "[" << firstLetterOfKeyword << "]" << endl;   // print the capitalized firstLetterofKeyword
            currentHeader = firstLetterOfKeyword;       // currentHeader is now the firstLetterOfKeyword
        }
        outputFile << it->first << ": ";
        for (int i = 0; i < it->second.getVectorSize() - 1; ++i) {      // iterate through the vector of pageNumbers
            if (lastPageNumberRecorded != it->second[i]) {         // if the last page number != page number
                outputFile << it->second[i] << ", ";        // print the pageNumbers followed by a comma
                lastPageNumberRecorded = it->second[i];     // update the last page number variable
            }
        }
        if (lastPageNumberRecorded != it->second[it->second.getVectorSize() - 1]) {
            outputFile << it->second[it->second.getVectorSize() - 1];
        }
        outputFile << endl;
    }
}
// create a currentLetter variable that holds the contents within the bracket of the header
// if the first letter of the current keyword is the same as the currentLetterHead,
// you add it to currentLetterHead
// else, you add the keyword to a new header