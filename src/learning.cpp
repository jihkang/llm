#include "vocabulary.h"
#include "learning.h"
#include "embedding.h"
#include "tokenizer.h"
#include <iostream>

Learning::Learning(std::string str) {
    token::Tokenizer tokenizer;
    tokenizer.simpleTokenize(str);
    for (auto token: tokenizer.getTokens()) {
        vocabulary.setVocabulary(token);
    }

    Embedding embed = Embedding(vocabulary.getSize(), 3);
    embedVector = std::move(embed);
}

std::vector<std::vector<double>> Learning::forward() {
    int size = vocabulary.getSize();

    // will be parallel multiple
    std::vector<std::vector<double>> result;
    result.resize(size);
    for (int i = 0; i < size; i++) {
        result[i].resize(size);
        std::vector<double> h = embedVector.getParseVector(i);
        for (int j = 0; j < size; j++) {
            std::vector<double> getMatrixValue = embedVector.getParseVector(j);
            int d = getMatrixValue.size();
            for (int k = 0; k < d; k++) {
                result[i][j] += getMatrixValue[k] * h[k];
            }
        }
    }

    for (int i = 0; i < size; i++) {
        std::cout << vocabulary.getToken(i) << ": ";    
        for (int j = 0; j < size; j++) {
            std::string sep = j == size - 1? "\n" : ", ";
            std::cout << result[i][j] << sep;
        }
    }

    return result;
}