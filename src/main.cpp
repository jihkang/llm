#include "tokenizer.h"
#include "vocabulary.h"
#include "embedding.h"
#include <iostream>
#include <functional>
std::string runTest(std::function<bool()> func) {
    return func() ? "Success" : "Error";
}

int main() {
    // tokenizer;
    {    
        std::cout << runTest(token::TestTokenizer::run) << std::endl;
    }

    // vocabulary builder;
    {
        std::cout << runTest(vocabulary::TestVocabularyBuilder::run) << std::endl;
        std::cout << runTest(vocabulary::TestVocabularyBuilder::runSkipGram) << std::endl;
    }
    
    // Embedding 
    {
        Embedding emb = Embedding(5, 3);
    }

    return 0;
}