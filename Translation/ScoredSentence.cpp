//
// Created by Olcay Taner YILDIZ on 2019-06-03.
//

#include "ScoredSentence.h"

/**
 * Constructor for the {@link ScoredSentence} class. Sets the probability for that sentence to 1.
 */
ScoredSentence::ScoredSentence() {
    logProbability = 0;
}

/**
 * Creates a copy of the sentence.
 * @return Copy of the sentence.
 */
ScoredSentence ScoredSentence::clone() {
    ScoredSentence s;
    for (Word* w:words)
        s.addWord(w);
    return s;
}

/**
 * Another constructor for the {@link ScoredSentence} class. Gets the words of the sentence as space delimited
 * tokens in a string, splits the string, and constructs the sentence.
 * @param s String containing the words of the sentence.
 */
ScoredSentence::ScoredSentence(string s) : Sentence(s) {
    logProbability = 0;
    vector<string> tokens = Word::split(s);
    for (const string& token:tokens){
        words.push_back(new Word(token));
    }
}

/**
 * Adds all words of the second sentence to the current sentence. The method also sums the log probabilities.
 * @param aSentence The second sentence to be merged.
 * @return New sentence formed by joining the current sentence with the input sentence.
 */
ScoredSentence ScoredSentence::join(ScoredSentence aSentence) {
    ScoredSentence s = clone();
    s.words.insert(s.words.end(), aSentence.words.begin(), aSentence.words.end());
    s.logProbability = logProbability + aSentence.logProbability;
    return s;
}

/**
 * Increments the log probability by the given amount.
 * @param addedLogProb The amount to be added.
 */
void ScoredSentence::addLogProb(double addedLogProb) {
    logProbability += addedLogProb;
}

/**
 * Accessor for the logProbability attribute.
 * @return logProbability attribute.
 */
double ScoredSentence::getProbability() {
    return logProbability;
}
