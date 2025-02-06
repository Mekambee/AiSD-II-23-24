#include "KolejkaPriorytetowa.h"
#include <iostream>
#include <vector>

void KolejkaPriorytetowa::insert(int x)
{
    vec.push_back(x);
    for (int i = vec.size() - 1; i > 0 && vec[i] > vec[(i - 1) / 2]; i = (i - 1) / 2)
    {
        std::swap(vec[i], vec[(i - 1) / 2]);
    }
}

int KolejkaPriorytetowa::RemoveRootElem()
{
    if (!vec.empty())
    {
        int root = vec[0];
        vec[0] = vec[vec.size() - 1];
        vec.pop_back();

        int i = 0;
        while (2 * i + 1 < vec.size())
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int max = left;
            if (right < vec.size() && vec[right] > vec[left])
            {
                max = right;
            }
            if (vec[i] < vec[max])
            {
                std::swap(vec[i], vec[max]);
                i = max;
            }
            else
            {
                break;
            }
        }
        return root;
    }
    else
    {
        std::cout << "Kolejka jest pusta!" << std::endl;
        return -1;
    }
}

void KolejkaPriorytetowa::print()
{
    if (!vec.empty())
    {
        for (int i = 0; i < vec.size(); i++)
        {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "kolejka jest pusta" << std::endl;
        return;
    }
}

int KolejkaPriorytetowa::getRootElem()
{
    if (!vec.empty())
    {
        return vec[0];
    }
    else
    {
        std::cout << "Kolejka jest pusta" << std::endl;
        return -1;
    }
}
