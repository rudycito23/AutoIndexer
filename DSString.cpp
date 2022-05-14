// Created by mark on 6/2/2021.

#include "DSString.h"

DSString::DSString() {  // constructor when no string is created
    word = nullptr;
    num = 0;
}

DSString::DSString(const char* anotherWord) {  // constructor
    // allocate memory for private data members +1 for null terminator
    word = new char[strlen(anotherWord) + 1];
    // copying data in anotherWord to word
    strcpy(word, anotherWord);
    word[strlen(anotherWord)] = '\0';
}

DSString::DSString(const DSString &anotherDSString) {  // copy constructor
    // allocate memory for private data member (word) +1 for null terminator
    word = new char[strlen(anotherDSString.word) + 1];
    // copying anotherDSString.word to word
    strcpy(word, anotherDSString.word);
    //word[strlen(anotherDSString.word)] = '\0';
}

DSString::~DSString() {  // destructor
    // deallocating memory that was reserved for *word (private data member)
    delete[] word;
}
// overload assignment operator
DSString &DSString::operator=(const char * anotherWord) {
    // allocate memory for private data members +1 for null terminator
    word = new char[strlen(anotherWord) + 1];
    strcpy(word, anotherWord);
    return *this;
}
// overload assignment operator
DSString &DSString::operator=(const DSString &anotherDSString) {
    // allocate memory for private data members +1 for null terminator
    if (anotherDSString.word != nullptr) {
        word = new char[strlen(anotherDSString.word) + 1];
        strcpy(word, anotherDSString.word);
    }
    return *this;
}

DSString DSString::operator+(const DSString &anotherDSString) {
    // created result object because I do not want to change the data in this->word
    DSString result;
    // allocate enough space for both words by adding anotherDSString.word && this->word +1 for null
    result.word = new char[strlen(anotherDSString.word) + 1 + strlen(this->word)];
    // copies word into result.word
    strcpy(result.word, word);
    // append anotherDSString to result.word
    strcat(result.word, anotherDSString.word);
    return result;
}
// overload comparison operator
bool DSString::operator==(const char * rightSide) const {
    // compare the left char* with the right char*, return if equal
    return strcmp(word, rightSide) == 0;
}
// overload comparison operator
bool DSString::operator==(const DSString &rightSide) const {
    // compare the left DSString with right DSString, return if equal
    return strcmp(word, rightSide.word) == 0;
}
// overload the > operator
bool DSString::operator>(const DSString &rightSide) const {
    // create a char* variable for the left and right side
    char* rightSideString = rightSide.word;
    char* leftSideString = word;
    // save the size of the DSString on the left and right side
    int sizeOfRightSide = strlen(rightSideString);
    int sizeOfLeftSide = strlen(leftSideString);
    // if size of left side is bigger than size of right side
    bool leftIsBigger = sizeOfLeftSide > sizeOfRightSide;
    // return true
    return leftIsBigger;
}
// overload the > operator
bool DSString::operator>(const char * rightSide) const {
    return strcmp(word, rightSide) > 0;
}
// overload the [] operator
char &DSString::operator[](const int index) const {
    // condition if the index is valid
    if (index >= strlen(word)) {
        throw std::out_of_range("Vector index is out of bounds");
    }
    else {
        // return what is in the index
        return word[index];
    }
}

int DSString::getLength() {
    return strlen(word);
}

DSString DSString::substring(int start, int numChars) {
    char newWord[numChars + 1];
    for (int i = 0; i < numChars; ++i) {
       newWord[i] = word[start + i];
    }
    newWord[numChars] = '\0';
    return DSString(newWord);
}
char *DSString::c_str() {
    return word;
}
// function will print out what is in DSString, overloading insertion operator
    ostream &operator<<(ostream &output, const DSString &newString) {
        output << newString.word;
        return output;
}

bool DSString::does_contain_keyword(DSString keywords) {
    for (int i = 0; i < this->getLength(); ++i) {
        bool match = true;
        for (int j = 0; j < keywords.getLength(); ++j) {
            if (i + j >= this->getLength() || !((*this)[i + j] == keywords[j])) {
                match = false;
                break;
            }
        }
        if (match) {
            return true;
        }
    }
    return false;
}

bool DSString::operator<(const DSString &rightSide) const {
    // save both sizes of char* on the left and right side
    return strcasecmp(word, rightSide.word) < 0;
}

char DSString::toUpperCase(char letter) {
    return toupper(letter);
}

char DSString::toLowerCase(char letter) {
    return tolower(letter);
}

bool DSString::operator!=(const DSString &rightSide) const {
    return strcmp(word, rightSide.word) != 0;
}