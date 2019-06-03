//
// Created by Olcay Taner YILDIZ on 2019-06-03.
//

#include "WordTranslations.h"
#include "WordTranslationCandidate.h"

WordTranslations::WordTranslations(string name) : SourceWord(move(name)) {
}

string WordTranslations::removeParentheses(string word) {
    while (word.find('(') != string::npos && word.find(')') != string::npos){
        unsigned long start = word.find('(');
        unsigned long end = word.find(')');
        word = word.substr(0, start) + word.substr(end + 1);
    }
    return word;
}

WordTranslations::WordTranslations(SourceWord* word) : SourceWord(word->getName()) {
    for (TargetPhrase* targetPhrase : word->getTranslations()){
        if (targetPhrase->getTranslation().find('(') == string::npos && targetPhrase->getTranslation().find(')') == string::npos){
            addTranslation(new Word(Word::trim(targetPhrase->getTranslation())), 1);
        } else {
            addTranslation(new Word(Word::trim(removeParentheses(targetPhrase->getTranslation()))), 1);
        }
    }
}

void WordTranslations::addTranslation(Word *translation, int count) {
    translations.push_back(new WordTranslationCandidate(translation->getName(), count));
    totalCount += count;
}

WordTranslations::WordTranslations(SourceWord *word, string pos) : SourceWord(word->getName()){
    for (TargetPhrase* targetPhrase : word->getTranslations()){
        if (!targetPhrase->getLexicalClass().empty() && targetPhrase->getLexicalClass() == pos){
            if (targetPhrase->getTranslation().find('(') == string::npos && targetPhrase->getTranslation().find(')') == string::npos){
                addTranslation(new Word(Word::trim(targetPhrase->getTranslation())), 1);
            } else {
                addTranslation(new Word(Word::trim(removeParentheses(targetPhrase->getTranslation()))), 1);
            }
        }
    }
}

void WordTranslations::addTranslation(Word *translation) {
    bool found = false;
    for (TargetPhrase* targetPhrase :translations){
        WordTranslationCandidate* wordTranslationCandidate = (WordTranslationCandidate*) targetPhrase;
        if (wordTranslationCandidate->getTranslation() == translation->getName()){
            wordTranslationCandidate->incrementCount();
            totalCount++;
            found = true;
            break;
        }
    }
    if (!found){
        translations.push_back(new WordTranslationCandidate(translation->getName()));
    }
}

double WordTranslations::getProbability(WordTranslationCandidate *translation) {
    return translation->getCount() / (totalCount + 0.0);
}

void WordTranslations::sortTranslations() {
    for (int i = 0; i < translations.size(); i++){
        for (int j = 0; j < translations.size(); j++){
            if (((WordTranslationCandidate*) translations.at(i))->getCount() > ((WordTranslationCandidate*) translations.at(j))->getCount()){
                std::swap(translations[i], translations[j]);
            }
        }
    }
}

void WordTranslations::mergeTranslations(WordTranslations *word) {
    bool found;
    for (TargetPhrase* targetPhrase:word->getTranslations()){
        WordTranslationCandidate* translation = (WordTranslationCandidate*) targetPhrase;
        found = false;
        for (TargetPhrase* currentTargetPhrase:translations){
            WordTranslationCandidate* currentTranslation = (WordTranslationCandidate*) currentTargetPhrase;
            if (currentTranslation->getTranslation() == translation->getTranslation()){
                currentTranslation->addCount(translation->getCount());
                totalCount += translation->getCount();
                found = true;
                break;
            }
        }
        if (!found){
            translations.push_back(translation);
        }
    }
}

string WordTranslations::toXml() {
    sortTranslations();
    string result = "\t<word name=\"" + Word::replaceAll(name, "&", "&amp;") + "\">\n";
    for (TargetPhrase* targetPhrase:translations){
        WordTranslationCandidate* translation = (WordTranslationCandidate*) targetPhrase;
        result = result + translation->toXml();
    }
    result = result + "\t</word>\n";
    return result;
}
