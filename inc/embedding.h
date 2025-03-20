#pragma once
#include <vector>


class Embedding
{
private:
    std::vector<std::vector<double>> matrix;

public:
    Embedding();
    Embedding(int p, int d);
    std::vector<double> getParseVector(size_t idx);
};