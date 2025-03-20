#pragma once
#include <vector>
class Embedding
{
private:
    std::vector<std::vector<double>> matrix;

public:
    Embedding(int p, int d);
};