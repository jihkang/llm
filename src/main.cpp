#include "tokenizer.h"
#include <iostream>

int main()
{
    std::string result = token::TestTokenizer::run() ? "Success" : "Error";
    std::cout << result << std::endl;
    
    return 0;
}