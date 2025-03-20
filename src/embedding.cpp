#include "embedding.h"
#include <random>
#include <iostream>
#include <cassert>

Embedding::Embedding() {}

Embedding::Embedding(int p, int d) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dis(0, 1.0 / std::sqrt(d));
    
    // 행렬 초기화 
    matrix.resize(p);
    for (int i = 0; i < p; i++) {
        matrix[i].resize(d);
        for (int j = 0; j < d; j++) {
            matrix[i][j] = dis(gen);
        }
    }

    for (int i = 0; i < p; i++) {
        for (int j = 0; j < d; j++) {
            std::string sep = j == d - 1? "\n" : ", ";
            std::cout << matrix[i][j] << sep;
        }
    }
}

std::vector<double> Embedding::getParseVector(size_t idx) {
    // assert(idx >= matrix.size());
    if (idx >= matrix.size())
    {
        throw new std::runtime_error("matrix size over");
    }

    return matrix[idx];
}