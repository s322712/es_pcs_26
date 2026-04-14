#include <iostream>
#include <vector>
#include <cstdlib>
#include "sorted.hpp"
#include "insertionsort.hpp"
#include "randfiller.h"

int main(void) {
    randfiller rf;
    for (int i=0; i<100; i++){
        std::vector<int> vi;
        int n = rand() % 100 + 1;
        vi.resize(n);
        rf.fill(vi, -50, 50);
        
        vi = insertionsort(vi);

        if(is_sorted(vi)){
            continue;
        }
        else{
            return EXIT_FAILURE;
        }
    }
    
    std::vector<std::string> vs = {"ciao","bello","Sole","Benedetta","laura","LUNA","buongiorno","PCS","buonanotte","pecore"};
    vs = insertionsort(vs);
    
    if (!is_sorted(vs)){
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}