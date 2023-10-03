//
// Created by Olcay Taner YILDIZ on 2019-06-03.
//

#include "WordTranslationCandidate.h"
#include <Word.h>

/**
 * Constructor for WordTranslationCandidate. Gets the translation string as input and calls its super class
 * with it. Since this is the first occurrence for this translation, it sets count to 1.
 * @param translation Translation of the word.
 */
WordTranslationCandidate::WordTranslationCandidate(string translation) : TargetPhrase(move(translation)) {
    count = 1;
}

/**
 * Another constructor for WordTranslationCandidate. Gets the translation string and count for that
 * translation as input. Calls its superclass with translation and sets the translation count.
 * @param translation Translation of the word.
 * @param count Number of occurrences of this translation.
 */
WordTranslationCandidate::WordTranslationCandidate(string translation, int count) : TargetPhrase(move(translation)){
    this->count = count;
}

/**
 * Accessor for the count attribute.
 * @return Count attribute.
 */
int WordTranslationCandidate::getCount() {
    return count;
}

/**
 * Increments the count attribute.
 */
void WordTranslationCandidate::incrementCount() {
    count++;
}

/**
 * Increments the count attribute by the amount of input addedCount.
 * @param addedCount Increment value.
 */
void WordTranslationCandidate::addCount(int addedCount) {
    count += addedCount;
}

string WordTranslationCandidate::to_string() {
    return getTranslation() + " (" + std::to_string(count) + ")";
}

/**
 * Converts the translation to Xml format.
 * @return Xml string form of translation.
 */
string WordTranslationCandidate::toXml() {
    return "\t\t<translation name=\"" + Word::replaceAll(getTranslation(), "&", "&amp;") + "\" count=\"" + std::to_string(count) + "\"/>\n";
}
