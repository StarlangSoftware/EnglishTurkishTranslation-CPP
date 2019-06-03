//
// Created by Olcay Taner YILDIZ on 2019-06-03.
//

#include "WordTranslationCandidate.h"
#include <Word.h>

WordTranslationCandidate::WordTranslationCandidate(string translation) : TargetPhrase(move(translation)) {
    count = 1;
}

WordTranslationCandidate::WordTranslationCandidate(string translation, int count) : TargetPhrase(move(translation)){
    this->count = count;
}

int WordTranslationCandidate::getCount() {
    return count;
}

void WordTranslationCandidate::incrementCount() {
    count++;
}

void WordTranslationCandidate::addCount(int addedCount) {
    count += addedCount;
}

string WordTranslationCandidate::to_string() {
    return getTranslation() + " (" + std::to_string(count) + ")";
}

string WordTranslationCandidate::toXml() {
    return "\t\t<translation name=\"" + Word::replaceAll(getTranslation(), "&", "&amp;") + "\" count=\"" + std::to_string(count) + "\"/>\n";
}
