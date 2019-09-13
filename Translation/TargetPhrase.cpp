//
// Created by Olcay Taner YILDIZ on 2019-06-03.
//

#include "TargetPhrase.h"

/**
 * Constructor for the {@link TargetPhrase} class. Gets the attributes lexicalClass and meaning as input and sets
 * the corresponding attributes.
 * @param lexicalClass Lexical class of the word.
 * @param meaning Meaning text of the word in {@link WordMeaning} form.
 */
TargetPhrase::TargetPhrase(string lexicalClass, WordMeaning meaning) {
    this->lexicalClass = move(lexicalClass);
    this->meaning = move(meaning);
}

/**
 * Another constructor for the {@link TargetPhrase} class. Gets the attribute meaning as input and sets the
 * corresponding attribute.
 * @param meaning Meaning text of the word in {@link WordMeaning} form.
 */
TargetPhrase::TargetPhrase(WordMeaning meaning) {
    this->meaning = move(meaning);
}

/**
 * Another constructor for the {@link TargetPhrase} class. Gets the attribute meaning as input and sets the
 * corresponding attribute.
 * @param meaningText Meaning text of the word in string form.
 */
TargetPhrase::TargetPhrase(string meaningText) {
    this->meaning = WordMeaning(move(meaningText));
}

/**
 * Accessor for the meaning attribute.
 * @return The meaning attribute
 */
string TargetPhrase::getTranslation() {
    return meaning.getMeaningText();
}

/**
 * Accessor for the lexicalClass attribute.
 * @return The lexicalClass attribute.
 */
string TargetPhrase::getLexicalClass() {
    return lexicalClass;
}

string TargetPhrase::to_string() {
    return getTranslation();
}
