//
// Created by rrluc on 2/28/2022.
//

#ifndef INC_21F_PA02_KEYWORDS_H
#define INC_21F_PA02_KEYWORDS_H
#include "DSString.h"
#include "DSVector.h"

class Keywords {
private:
    //DSVector<DSString> keywords;
    map<DSString, DSVector<int>> keywordsAndPageNumbers;

public:
    DSVector<DSString> keywords;
    Keywords();
    void getKeywordsFromSampleFile(char* fileName);
    void readBookFile(char* fileName);



};


#endif //INC_21F_PA02_KEYWORDS_H
