#pragma once
#include <optional>
#include <algorithm>

template<typename T>
int partizione(std::vector<T>&vec, int sinistra, int destra)
{
    T x = vec[destra];
    int i = sinistra - 1;
    for (int j = sinistra; j<destra; j++){
        if (vec[j]<=x){
            i = i + 1;
            std::swap(vec[i], vec[j]);
        }
    }
    std::swap(vec[i+1], vec[destra]);

    return i+1;
}