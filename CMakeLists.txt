cmake_minimum_required(VERSION 3.13)
project(Translation)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
link_directories(library)

add_library(Translation SentenceAlignment/SentenceAlignmentType.h Translation/TranslationType.h Translation/WordMeaning.cpp Translation/WordMeaning.h Translation/TargetPhrase.cpp Translation/TargetPhrase.h Translation/WordTranslationCandidate.cpp Translation/WordTranslationCandidate.h Translation/SourceWord.cpp Translation/SourceWord.h Translation/ScoredSentence.cpp Translation/ScoredSentence.h Translation/WordAlignment.cpp Translation/WordAlignment.h Translation/WordTranslations.cpp Translation/WordTranslations.h)

target_link_libraries(Translation Dictionary Corpus)
