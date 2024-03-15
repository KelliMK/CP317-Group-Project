#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include "supplier.h"

using namespace std;

int main() {

    string filename = "testSupply.txt"; //change to commandline args eventually

    std::vector<Supplier> Suppliers; //init Suppliers vector

    ifstream infile(filename); //open pseudo-CSV file

    string line; //string buffer for input

    if (!infile) {
        cerr << "Invalid input file.\n";
        return -1;
    }

    while (getline(infile, line)) { //first loop is reading the lines directly from the file

        std::istringstream stringstr(line);

        string sTemp; //temporary string used as a buffer for each element of a line from the main file
        vector<string> vTemp; //temporary vector used to store elements for easier insertion into the main vector

        while(std::getline(stringstr, sTemp, ',')) {
            vTemp.push_back(sTemp); //pushing elements into temp vector
        }

        Supplier s; //initializing an object for one supplier to hold values obtained by vTemp
        s.ID = std::stoi(vTemp[0]); //converting string ID into an integer
        s.Name = vTemp[1];
        s.Addr = vTemp[2];
        s.Phone = vTemp[3];
        s.Email = vTemp[4];

        Suppliers.push_back(s); //inserting the supplier vector as one element of the larger Suppliers vector

    };

    int size = Suppliers.size(); //making a separate integer for the size of the vector array

    for (int i = 0; i < size; i++) { //basic output loop for testing/debugging
        cout << Suppliers[i].ID
        << Suppliers[i].Name
        << Suppliers[i].Addr
        << Suppliers[i].Phone
        << Suppliers[i].Email << endl;
    };

    infile.close(); //closing file
    return 0;
}
