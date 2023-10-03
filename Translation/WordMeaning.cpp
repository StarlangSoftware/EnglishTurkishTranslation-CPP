//
// Created by Olcay Taner YILDIZ on 2019-06-03.
//

#include "WordMeaning.h"

/**
 * Constructor for the WordMeaning class. Gets meaningClass and meaningText as input and sets the
 * corresponding attributes.
 * @param meaningClass Meaning class of the word.
 * @param meaningText Meaning text of the word.
 */
WordMeaning::WordMeaning(string meaningClass, string meaningText) {
    this->meaningClass = move(meaningClass);
    this->meaningText = move(meaningText);
}

/**
 * Another constructor for the WordMeaning class. Gets meaningText as input and sets the corresponding
 * attribute.
 * @param meaningText Meaning text of the word.
 */
WordMeaning::WordMeaning(string meaningText) {
    this->meaningText = move(meaningText);
}

/**
 * Accessor for the meaningClass attribute.
 * @return MeaningClass attribute.
 */
string WordMeaning::getMeaningClass() {
    return meaningClass;
}

/**
 * Accessor for the meaningText attribute.
 * @return MeaningText attribute.
 */
string WordMeaning::getMeaningText() {
    return meaningText;
}

/**
 * Mutator for the meaningText attribute.
 * @param meaningText New meaning text.
 */
void WordMeaning::setMeaningText(string meaningText) {
    this->meaningText = move(meaningText);
}
