#include "vocabulary.h"
#include <iostream>
namespace vocabulary
{   
void VocabularyBuilder::setVocabulary(const std::string str) {
    if (vocabulary.find(str) == vocabulary.end()) {
        vocabulary[str] = vocabulary.size();
        tokens.push_back(str);
    }
}

int VocabularyBuilder::getVec(const std::string str) {
    if (vocabulary.find(str) == vocabulary.end())
        return -1;

    return vocabulary[str];
}

int VocabularyBuilder::getSize() {
    return tokens.size();
}

std::string VocabularyBuilder::getToken(int idx) {
    if (idx >= (int)tokens.size())
        throw std::runtime_error("index overflow");

    return tokens[idx];
}

std::vector<std::pair<std::string, std::string>> VocabularyBuilder::skipGram(int windowSize) {
    std::vector<std::pair<std::string, std::string>> pairSequence;

    for (size_t i = 0; i < tokens.size(); i++) {
        size_t start = i - windowSize > 0 ? i - windowSize : 0;
        size_t end = i + windowSize >= tokens.size() ? tokens.size() : i + windowSize;
        for (size_t j = start; j <= end; j++) {
            if (j == i)
                continue ;

            pairSequence.push_back({this->tokens[i], this->tokens[j]});
        }
    }

    return pairSequence;
}

bool TestVocabularyBuilder::run() {
    std::vector<std::string> tokens = {
        "a", "bb", "accc", "bab", "acc", "bcb", "accc", "bb",
    };
    VocabularyBuilder vocabulary;

    std::unordered_map<std::string, int> testVoca = {
        {"a", 0}, {"bb", 1}, {"accc", 2}, {"bab", 3}, {"acc", 4}, {"bcb", 5},
    };

    for (size_t i = 0; i < tokens.size(); i++) {
        vocabulary.setVocabulary(tokens[i]);
        if (vocabulary.getVec(tokens[i]) != testVoca[tokens[i]]) {
            return false;
        }
    }

    return true;
}

bool TestVocabularyBuilder::runSkipGram() {
    std::vector<std::string> tokens = {"a", "bb", "accc", "bab", "acc", "bcb", "accc", "bb"};
    VocabularyBuilder vocabulary;

    auto res = vocabulary.skipGram(2);
    std::vector<std::pair<std::string, std::string>> resTest = {
        {"a", "bb"}, {"a", "accc"},
        {"bb", "a"}, {"bb", "accc"}, {"bb", "bab"},
        {"accc", "a"}, {"accc", "bb"}, {"accc", "bab"}, {"accc", "acc"},
        {"bab", "bb"}, {"bab", "accc"}, {"bab", "acc"}, {"bab", "bcb"},
        {"acc", "accc"}, {"acc", "bab"}, {"acc", "bcb"}, {"acc", "accc"},
        {"bcb", "bab"}, {"bcb", "acc"}, {"bcb", "accc"},
        {"accc", "acc"}, {"accc", "bcb"}
    };

    return std::equal(res.begin(), res.end(), resTest.begin());
}

}