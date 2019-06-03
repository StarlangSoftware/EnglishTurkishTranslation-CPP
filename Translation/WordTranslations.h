//
// Created by Olcay Taner YILDIZ on 2019-06-03.
//

#ifndef TRANSLATION_WORDTRANSLATIONS_H
#define TRANSLATION_WORDTRANSLATIONS_H


#include "SourceWord.h"
#include "WordTranslationCandidate.h"

class WordTranslations : public SourceWord{
private:
    int totalCount = 0;
    string removeParentheses(string word);
public:
    explicit WordTranslations(string name);
    explicit WordTranslations(SourceWord* word);
    WordTranslations(SourceWord* word, string pos);
    void addTranslation(Word* translation, int count);
    void addTranslation(Word* translation);
    double getProbability(WordTranslationCandidate* translation);
    void sortTranslations();
    void mergeTranslations(WordTranslations* word);
    string toXml();
};


#endif //TRANSLATION_WORDTRANSLATIONS_H
