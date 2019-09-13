//
// Created by Olcay Taner YILDIZ on 2019-06-03.
//

#include "WordTranslations.h"
#include "WordTranslationCandidate.h"

/**
 * Constructor for {@link WordTranslations} class. Gets the translation string as input and calls its super class.
 * @param name Translation string.
 */
WordTranslations::WordTranslations(string name) : SourceWord(move(name)) {
}

/**
 * Removes all matching parantheses from the given input word.
 * @param word Input text.
 * @return The word with all matching paramtheses removed.
 */
string WordTranslations::removeParentheses(string word) {
    while (word.find('(') != string::npos && word.find(')') != string::npos){
        unsigned long start = word.find('(');
        unsigned long end = word.find(')');
        word = word.substr(0, start) + word.substr(end + 1);
    }
    return word;
}

/**
 * Another constructor for {@link WordTranslations} class. Gets the sourceWord as input, calls its superclass with
 * it. Afterwards, for each translation in that word, it adds that translation to the current words translations
 * list.
 * @param word Copied source word.
 */
WordTranslations::WordTranslations(SourceWord* word) : SourceWord(word->getName()) {
    for (TargetPhrase* targetPhrase : word->getTranslations()){
        if (targetPhrase->getTranslation().find('(') == string::npos && targetPhrase->getTranslation().find(')') == string::npos){
            addTranslation(new Word(Word::trim(targetPhrase->getTranslation())), 1);
        } else {
            addTranslation(new Word(Word::trim(removeParentheses(targetPhrase->getTranslation()))), 1);
        }
    }
}

/**
 * Adds a totally new translation to the translation list with the given amount.
 * @param translation Translation string.
 * @param count Number of occurrences of that translation.
 */
void WordTranslations::addTranslation(Word *translation, int count) {
    translations.push_back(new WordTranslationCandidate(translation->getName(), count));
    totalCount += count;
}

/**
 * Another construfor {@link WordTranslations} class. Gets the sourceWord as input, calls its superclass with
 * it. Afterwards, for each translation in that word, it adds that translation to the current words translations
 * list, if it has the same pos with the input.
 * @param word Copied source word.
 * @param pos Part of speech tag input.
 */
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

/**
 * Adds a new translation to the translation list. If that translation already occurs in the translation list, it
 * only increments the count. Otherwise, it adds as a new translation with count 1.
 * @param translation Translation string.
 */
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

/**
 * Returns the probability of a given translation.
 * @param translation Translation.
 * @return The probability of the given translation.
 */
double WordTranslations::getProbability(WordTranslationCandidate *translation) {
    return translation->getCount() / (totalCount + 0.0);
}

/**
 * Sorts all translations of the current word in the increasing order of number of occurrences of the translations.
 */
void WordTranslations::sortTranslations() {
    for (int i = 0; i < translations.size(); i++){
        for (int j = 0; j < translations.size(); j++){
            if (((WordTranslationCandidate*) translations.at(i))->getCount() > ((WordTranslationCandidate*) translations.at(j))->getCount()){
                std::swap(translations[i], translations[j]);
            }
        }
    }
}

/**
 * Merges the translation list of a given word with the current word's translation list.
 * The translations are checked; if the translations are same; the counts are added, otherwise the counts and
 * translation are directly merged.
 * @param word Word to be merged.
 */
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

/**
 * Converts the current object to Xml form.
 * @return Xml form of the current object.
 */
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
