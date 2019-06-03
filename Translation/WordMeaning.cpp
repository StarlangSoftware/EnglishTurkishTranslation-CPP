//
// Created by Olcay Taner YILDIZ on 2019-06-03.
//

#include "WordMeaning.h"

WordMeaning::WordMeaning(string meaningClass, string meaningText) {
    this->meaningClass = move(meaningClass);
    this->meaningText = move(meaningText);
}

WordMeaning::WordMeaning(string meaningText) {
    this->meaningText = move(meaningText);
}

string WordMeaning::getMeaningClass() {
    return meaningClass;
}

string WordMeaning::getMeaningText() {
    return meaningText;
}

void WordMeaning::setMeaningText(string meaningText) {
    this->meaningText = move(meaningText);
}
