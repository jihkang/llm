#pragma once

#include <vector>
#include <string>

namespace token
{ 
    class Tokenizer
    {
        private:
        std::vector<std::string> tokens;
        
        public:
        
        void simpleTokenize(const std::string& str);
        std::vector<std::string> getTokens(void);
    };

    class TestTokenizer
    {
    public:
        static bool run();
    };
}