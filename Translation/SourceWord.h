//
// Created by Olcay Taner YILDIZ on 2019-06-03.
//

#ifndef TRANSLATION_SOURCEWORD_H
#define TRANSLATION_SOURCEWORD_H


#include <Word.h>
#include <vector>
#include "TargetPhrase.h"

class SourceWord : public Word{
protected:
    vector<TargetPhrase*> translations;
public:
    explicit SourceWord(string name);
    vector<TargetPhrase*> getTranslations();
    void addTranslation(TargetPhrase* translation);
    int translationCount();
    TargetPhrase* getTranslation(int index);
};


#endif //TRANSLATION_SOURCEWORD_H
