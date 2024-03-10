#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main(int argc, char** argv)
{
    if (argc == 3) {
        string line;
        float temp;
        int roundedtemp;

        ifstream inputFile(argv[1]);
        ofstream outputFile(argv[2]);

        if (inputFile && outputFile) {
            while (getline(inputFile, line)) {
                temp = std::stof(line);
                temp = (temp * 1.8) + 32;
                temp = std::roundf(temp);
                roundedtemp = (int)(temp);
                line = std::to_string(roundedtemp);
                outputFile << line << "\n";
            }
        }

        inputFile.close();
        outputFile.close();
        cout << "Conversion complete, output file generated." << std::endl;
        return 0;
    }

    else {
        cout << "Invalid input, please try again." << std::endl;
        return -1;
    }
}