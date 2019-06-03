//
// Created by Olcay Taner YILDIZ on 2019-06-03.
//

#ifndef TRANSLATION_WORDALIGNMENT_H
#define TRANSLATION_WORDALIGNMENT_H


#include <Sentence.h>

class WordAlignment {
private:
    Sentence* fromSentence;
    Sentence* toSentence;
    vector<int> alignment;
public:
    WordAlignment(Sentence* toSentence, Sentence* fromSentence);
    WordAlignment(Sentence* toSentence, Sentence* fromSentence, vector<int> alignment);
    void set(int pos, int value);
    int get(int pos);
    Sentence* from();
    Sentence* to();
    WordAlignment copy();
};


#endif //TRANSLATION_WORDALIGNMENT_H
