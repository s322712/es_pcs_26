#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "bubblesort.hpp"
#include "insertionsort.hpp"
#include "selectionsort.hpp"
#include "timecounter.h"
#include "randfiller.h"

int main(void){
    randfiller rf;
    for (int i=2; i<=13; i++){
        int k = std::pow(2,i);
        std::vector<int> vi;
        vi.resize(k);
        rf.fill(vi, -50, 50);

        timecounter tc;
        tc.tic();

        std::vector<int> v_bubble = bubblesort(vi);
        double bubble_time = tc.toc();
        
        tc.tic();
        std::vector<int> v_insertion = insertionsort(vi);
        double insertion_time = tc.toc();

        tc.tic();
        std::vector<int> v_selection = selectionsort(vi);
        double selection_time = tc.toc();

        tc.tic();
        std::sort(vi.begin(), vi.end());
        double sort_time = tc.toc();

        std::cout<< "Dimensione: " << k << "\n";
        std::cout<< "Bubblesort: " << bubble_time << "\n";
        std::cout<< "Insertionsort: " << insertion_time << "\n";
        std::cout<< "Selectionsort: " << selection_time << "\n";
        std::cout<< "Sort: " << sort_time << "\n";
        std::cout<< "\n";
    }


}