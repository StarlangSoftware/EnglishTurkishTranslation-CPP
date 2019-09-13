//
// Created by Olcay Taner YILDIZ on 2019-06-03.
//

#include "WordAlignment.h"

/**
 * Constructor for {@link WordAlignment} class. Gets input the target sentence and the source sentence and sets
 * the corresponding attributes. The method also initializes the alignment to the unary alignment.
 * @param targetSentence Target sentence
 * @param sourceSentence Source sentence
 */
WordAlignment::WordAlignment(Sentence *toSentence, Sentence *fromSentence) {
    this->toSentence = toSentence;
    this->fromSentence = fromSentence;
    for (int i = 0; i < toSentence->wordCount(); i++){
        if (i < fromSentence->wordCount()){
            alignment.push_back(i);
        } else {
            alignment.push_back(fromSentence->wordCount());
        }
    }
}

/**
 * Another constructor for {@link WordAlignment} class. Gets input the target sentence, the source sentence and
 * the alignment sets the corresponding attributes.
 * @param targetSentence Target sentence
 * @param sourceSentence Source sentence
 * @param alignment Current alignment
 */
WordAlignment::WordAlignment(Sentence* toSentence, Sentence* fromSentence, vector<int> alignment) {
    this->toSentence = toSentence;
    this->fromSentence = fromSentence;
    //Clone of the array is required. Do not move.
    this->alignment = alignment;
}

/**
 * Mutator for the alignment. Sets the given alignment to the given value.
 * @param pos Index in the alignment array
 * @param value New value for that indexed alignment
 */
void WordAlignment::set(int pos, int value) {
    if (value >= 0 && value <= fromSentence->wordCount()) {
        alignment[pos] = value;
    }
}

/**
 * Accessor for the alignment element
 * @param pos Index of the alignment element
 * @return Alignment element at index pos
 */
int WordAlignment::get(int pos) {
    return alignment.at(pos);
}

/**
 * Accessor for the source sentence.
 * @return Source sentence
 */
Sentence *WordAlignment::from() {
    return fromSentence;
}

/**
 * Accessor for the target sentence.
 * @return Target sentence.
 */
Sentence *WordAlignment::to() {
    return toSentence;
}

/**
 * Creates a copy of the current word alignment.
 * @return A new copy of this current alignment object.
 */
WordAlignment WordAlignment::copy() {
    return WordAlignment(toSentence, fromSentence, alignment);
}
