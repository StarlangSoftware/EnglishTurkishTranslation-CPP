//
// Created by Olcay Taner YILDIZ on 2019-06-03.
//

#ifndef TRANSLATION_WORDTRANSLATIONCANDIDATE_H
#define TRANSLATION_WORDTRANSLATIONCANDIDATE_H


#include "TargetPhrase.h"

class WordTranslationCandidate : public TargetPhrase{
private:
    int count;
public:
    explicit WordTranslationCandidate(string translation);
    WordTranslationCandidate(string translation, int count);
    int getCount();
    void incrementCount();
    void addCount(int addedCount);
    string to_string();
    string toXml();
};


#endif //TRANSLATION_WORDTRANSLATIONCANDIDATE_H
