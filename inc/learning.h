
#pragma once

#include "embedding.h"
#include "vocabulary.h"
#include <vector>

class Learning{
private:
    Embedding embedVector;
    vocabulary::VocabularyBuilder vocabulary;
public:
    Learning(std::string str);
    std::vector<std::vector<double>> forward();
};