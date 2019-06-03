//
// Created by Olcay Taner YILDIZ on 2019-06-03.
//

#include "SourceWord.h"

SourceWord::SourceWord(string name) : Word(move(name)) {
}

vector<TargetPhrase*> SourceWord::getTranslations() {
    return translations;
}

void SourceWord::addTranslation(TargetPhrase* translation) {
    translations.push_back(translation);
}

int SourceWord::translationCount() {
    return translations.size();
}

TargetPhrase *SourceWord::getTranslation(int index) {
    return translations.at(index);
}
