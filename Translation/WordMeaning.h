//
// Created by Olcay Taner YILDIZ on 2019-06-03.
//

#ifndef TRANSLATION_WORDMEANING_H
#define TRANSLATION_WORDMEANING_H

#include <string>
using namespace std;

class WordMeaning {
private:
    string meaningClass = "";
    string meaningText = "";
public:
    WordMeaning(string meaningClass, string meaningText);
    explicit WordMeaning(string meaningText);
    string getMeaningClass();
    string getMeaningText();
    void setMeaningText(string meaningText);
};


#endif //TRANSLATION_WORDMEANING_H
