#include <iostream>
#include <cmath>

int main()
{
    static const int N = 10;
    double arr[N] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};

    std::cout << "Minimo: " << arr[0] << "\n";
    std::cout << "Massimo: " << arr[9] << "\n";

    double media = (arr[0]+arr[1]+arr[2]+arr[3]+arr[4]+arr[5]+arr[6]+arr[7]+arr[8]+arr[9])/N;
    double varianza = ((arr[0]-media)*(arr[0]-media)+(arr[1]-media)*(arr[1]-media)+(arr[2]-media)*(arr[2]-media)+(arr[3]-media)*(arr[3]-media)+(arr[4]-media)*(arr[4]-media)+(arr[5]-media)*(arr[5]-media)+(arr[6]-media)*(arr[6]-media)+(arr[7]-media)*(arr[7]-media)+(arr[8]-media)*(arr[8]-media)+(arr[9]-media)*(arr[9]-media))/N;
    
    double deviazione_standard = sqrt(varianza);
    std::cout << "Media: " << media << "\n";
    std::cout << "Deviazione standard: " << deviazione_standard << "\n";

    return 0;

}