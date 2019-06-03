//
// Created by Olcay Taner YILDIZ on 2019-06-03.
//

#include "ScoredSentence.h"

ScoredSentence::ScoredSentence() {
    logProbability = 0;
}

ScoredSentence ScoredSentence::clone() {
    ScoredSentence s;
    for (Word* w:words)
        s.addWord(w);
    return s;
}

ScoredSentence::ScoredSentence(string s) : Sentence(s) {
    logProbability = 0;
    vector<string> tokens = Word::split(s);
    for (const string& token:tokens){
        words.push_back(new Word(token));
    }
}

ScoredSentence ScoredSentence::join(ScoredSentence aSentence) {
    ScoredSentence s = clone();
    s.words.insert(s.words.end(), aSentence.words.begin(), aSentence.words.end());
    s.logProbability = logProbability + aSentence.logProbability;
    return s;
}

void ScoredSentence::addLogProb(double addedLogProb) {
    logProbability += addedLogProb;
}

double ScoredSentence::getProbability() {
    return logProbability;
}
