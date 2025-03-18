#pragma once

#include <vector>
#include <unordered_map>
#include <utility>

namespace vocabulary
{    
    class VocabularyBuilder
    {
    private:
        std::unordered_map<std::string, int> vocabulary;
        std::vector<std::string> tokens;
        // word 2 vec
    
    public:
        void setVocabulary(std::string str);
        int getVec(std::string);
        std::vector<std::pair<std::string, std::string>> skipGram(int windowSize);
    };

    class TestVocabularyBuilder
    {
    public:
    static bool run();
    static bool runSkipGram();
    };
}