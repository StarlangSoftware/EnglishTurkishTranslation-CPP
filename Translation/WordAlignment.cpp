//
// Created by Olcay Taner YILDIZ on 2019-06-03.
//

#include "WordAlignment.h"

WordAlignment::WordAlignment(Sentence *toSentence, Sentence *fromSentence) {
    this->toSentence = toSentence;
    this->fromSentence = fromSentence;
    for (int i = 0; i < toSentence->wordCount(); i++){
        if (i < fromSentence->wordCount()){
            alignment.push_back(i);
        } else {
            alignment.push_back(fromSentence->wordCount());
        }
    }
}

WordAlignment::WordAlignment(Sentence* toSentence, Sentence* fromSentence, vector<int> alignment) {
    this->toSentence = toSentence;
    this->fromSentence = fromSentence;
    //Clone of the array is required. Do not move.
    this->alignment = alignment;
}

void WordAlignment::set(int pos, int value) {
    if (value >= 0 && value <= fromSentence->wordCount()) {
        alignment[pos] = value;
    }
}

int WordAlignment::get(int pos) {
    return alignment.at(pos);
}

Sentence *WordAlignment::from() {
    return fromSentence;
}

Sentence *WordAlignment::to() {
    return toSentence;
}

WordAlignment WordAlignment::copy() {
    return WordAlignment(toSentence, fromSentence, alignment);
}
