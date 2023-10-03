//
// Created by Olcay Taner YILDIZ on 2019-06-03.
//

#include "SourceWord.h"

/**
 * Constructor for SourceWord. The method gets lemma of the word as input and calls its super. It also
 * initializes the possible translations of the word.
 * @param name Lemma of the word.
 */
SourceWord::SourceWord(string name) : Word(move(name)) {
}

/**
 * Returns all possible translations for the word
 * @return An ArrayList of all possible translations of the word
 */
vector<TargetPhrase*> SourceWord::getTranslations() {
    return translations;
}

/**
 * Adds another possible translation to the all possible translations array
 * @param translation New translation of the current word
 */
void SourceWord::addTranslation(TargetPhrase* translation) {
    translations.push_back(translation);
}

/**
 * Returns number of possible translations.
 * @return Number of translations.
 */
int SourceWord::translationCount() {
    return translations.size();
}

/**
 * Returns the i'th possible translation for the current word.
 * @param index Index of the translation
 * @return i'th possible translation for the current word.
 */
TargetPhrase *SourceWord::getTranslation(int index) {
    return translations.at(index);
}
