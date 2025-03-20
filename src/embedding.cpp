#include "embedding.h"
#include <random>
#include <iostream>

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


    for (int i = 0; i < p; i ++){
        for (int j = 0; j < d; j++) {
            std::string strSeq = j != d - 1 ?  ", " : "\n";
            std::cout << matrix[i][j] << strSeq;
        }
    }
}

