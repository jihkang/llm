#include "tokenizer.h"
#include <sstream>
#include <vector>
#include <iostream>

namespace token
{
    void Tokenizer::simpleTokenize(const std::string& str)
    {
        std::istringstream stream(str);
        std::string token;
        
        while (stream >> token)
        {
            if (token.size() == 0)
            {
                continue ;
            }
            
            this->tokens.push_back(token);
        }
    }
    
    std::vector<std::string> Tokenizer::getTokens(void)
    {
        return this->tokens;
    }
    
    
    bool TestTokenizer::run()
    {
        const std::string str = "a  q w ee r q";
        std::string result[] = {"a", "q", "w", "ee", "r", "q"};

        Tokenizer token;
        token.simpleTokenize(str);
        std::vector<std::string> tokens = token.getTokens();
        for (size_t i = 0; i < tokens.size(); i++)
        {
            if (tokens[i].compare(result[i]))
            {
                std::cout << "Error: test failed\n";
                return false;
            }
        }

        return true;
    }
}