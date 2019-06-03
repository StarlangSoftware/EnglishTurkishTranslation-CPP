//
// Created by Olcay Taner YILDIZ on 2019-06-03.
//

#ifndef TRANSLATION_TARGETPHRASE_H
#define TRANSLATION_TARGETPHRASE_H

#include <string>
#include "WordMeaning.h"

using namespace std;

class TargetPhrase {
protected:
    string lexicalClass;
    WordMeaning meaning = WordMeaning("");
public:
    TargetPhrase(string lexicalClass, WordMeaning meaning);
    explicit TargetPhrase(WordMeaning meaning);
    explicit TargetPhrase(string meaningText);
    string getTranslation();
    string getLexicalClass();
    string to_string();
};


#endif //TRANSLATION_TARGETPHRASE_H
