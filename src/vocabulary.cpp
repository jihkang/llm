#include "vocabulary.h"

namespace vocabulary
{   
    void VocabularyBuilder::setVocabulary(const std::string str) {
        if (vocabulary.find(str) == vocabulary.end()) {
            vocabulary[str] = vocabulary.size();
        }
    }

    int VocabularyBuilder::getVec(const std::string str) {
        if (vocabulary.find(str) == vocabulary.end())
            return -1;

        return vocabulary[str];
    }

    bool TestVocabularyBuilder::run()
    {
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
}