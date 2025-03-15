#include "vocabulary.h"

namespace vocabulary
{   
    void VocabularyBuilder::setVocabulary(const std::string str) {
        if (vocabulary.find(str) == vocabulary.end()) {
            vocabulary[str] = vocabulary.size() + 1;
        }
    }

    int VocabularyBuilder::getVec(const std::string str) {
        if (vocabulary.find(str) == vocabulary.end())
            return -1;

        return vocabulary[str];
    }
}