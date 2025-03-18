#include "vocabulary.h"

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
    std::vector<std::string> tokens;
    VocabularyBuilder vocabulary;

    tokens.push_back("a");
    tokens.push_back("bb");
    tokens.push_back("accc");
    tokens.push_back("bab");
    tokens.push_back("acc");
    tokens.push_back("bcb");
    tokens.push_back("accc");
    tokens.push_back("bb");
    std::unordered_map<std::string, int> testVoca;
    testVoca["a"] = 0;
    testVoca["bb"] = 1;
    testVoca["accc"] = 2;
    testVoca["bab"] = 3;
    testVoca["acc"] = 4;
    testVoca["bcb"] = 5;

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