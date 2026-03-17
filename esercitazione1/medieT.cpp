#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, const char *argv [])
{
    string filename = argv[1];
    ifstream ifs(filename);
    if (ifs.is_open() ) {
        while (!ifs.eof() ){
            string city;
            double temp1;
            double temp2;
            double temp3;
            double temp4;
            ifs >> city >> temp1 >> temp2 >> temp3 >> temp4;
            if (ifs.fail()){
                cerr << "error extracting from file\n";
            }
            double media = (temp1+temp2+temp3+temp4)/4;
            cout << city << "   " << media << "\n";
        }
    }
        else {
        cerr << "unable to open file\n";
    }
    return 0;    
}