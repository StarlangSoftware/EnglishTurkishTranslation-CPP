//
// Created by Olcay Taner YILDIZ on 2019-06-03.
//

#ifndef TRANSLATION_SCOREDSENTENCE_H
#define TRANSLATION_SCOREDSENTENCE_H


#include <Sentence.h>

class ScoredSentence : public Sentence{
private:
    double logProbability;
public:
    ScoredSentence();
    ScoredSentence clone();
    explicit ScoredSentence(string s);
    ScoredSentence join(ScoredSentence aSentence);
    void addLogProb(double addedLogProb);
    double getProbability();
};


#endif //TRANSLATION_SCOREDSENTENCE_H
