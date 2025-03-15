#pragma once

namespace vocabulary
{    
    class VocabularyBuilder
    {
    private:
        std::unordered_map<std::string, int> vocabulary;
        // word 2 vec
    
    public:
        void setVocabulary(std::string str);
        int getVec(std::string);


    };
}