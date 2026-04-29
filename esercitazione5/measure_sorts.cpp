#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "mergesort.hpp"
#include "quicksort.hpp"
#include "timecounter.h"
#include "randfiller.h"
#include "bubblesort.hpp"
#include "insertionsort.hpp"
#include "selectionsort.hpp"

int main(void){
    randfiller rf;
    timecounter tc;
    
    std::vector<std::vector<int>> vettori(100);

    for (int k=1; k<101; k++){

        for (int i=0; i<100; i++){
            std::vector<int> vi = vettori[i];
            vi.resize(k);
            rf.fill(vi, -50, 50);    
            vettori[i] = vi;    
        }

        tc.tic();
        for (int i=0; i<100; i++){
            std::vector<int> vi = vettori[i];

            std::vector<int> vi_bubble = vi;
            bubblesort(vi_bubble);
            
            std::vector<int> vi_insertion = vi;
            insertionsort(vi_insertion);

            std::vector<int> vi_selection = vi;
            selectionsort(vi_selection);

            std::vector<int> vi_merge = vi;
            mergesort(vi_merge, 0, k-1);

            std::vector<int> vi_quick = vi;
            quicksort(vi_quick, 0, k-1);

            std::vector<int> vi_sort = vi;
            std::sort(vi_sort.begin(), vi_sort.end());
        }
        double tempo = tc.toc();
        double media = tempo/100;
        
        std::cout<< "Dimensione: " << k << "\n";
        std::cout<< "Tempo medio: " << media << "\n";
        std::cout<< "\n";

    }    

}