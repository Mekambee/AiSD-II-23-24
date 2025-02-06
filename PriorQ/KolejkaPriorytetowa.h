#pragma once
#include <array>
#include <vector>

using namespace std;


class KolejkaPriorytetowa
{   
    std::vector<int> vec;

    public:
    void insert(int x);
    int RemoveRootElem();
    void print();   //opcjonalnie dla wy�wietlenia kolejnych element�w macierzy, w kt�rej trzymany jest kopiec.
    int getRootElem();
};