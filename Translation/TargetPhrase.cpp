//
// Created by Olcay Taner YILDIZ on 2019-06-03.
//

#include "TargetPhrase.h"

TargetPhrase::TargetPhrase(string lexicalClass, WordMeaning meaning) {
    this->lexicalClass = move(lexicalClass);
    this->meaning = move(meaning);
}

TargetPhrase::TargetPhrase(WordMeaning meaning) {
    this->meaning = move(meaning);
}

TargetPhrase::TargetPhrase(string meaningText) {
    this->meaning = WordMeaning(move(meaningText));
}

string TargetPhrase::getTranslation() {
    return meaning.getMeaningText();
}

string TargetPhrase::getLexicalClass() {
    return lexicalClass;
}

string TargetPhrase::to_string() {
    return getTranslation();
}
