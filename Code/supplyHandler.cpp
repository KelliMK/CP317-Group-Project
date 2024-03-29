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

std::vector<PublicSupplier> suppliers(string filename) {

    /*
    deprecated
    string filename = "testSupply.txt"; //change to commandline args eventually
    */

    std::vector<PublicSupplier> Suppliers; //init Suppliers vector

    ifstream infile(filename); //open pseudo-CSV file

    string line; //string buffer for input

    if (!infile) {
        cerr << "Invalid input file.\n";
        exit(1);;
    }

    while (getline(infile, line)) { //first loop is reading the lines directly from the file

        std::istringstream stringstr(line);

        string sTemp; //temporary string used as a buffer for each element of a line from the main file
        vector<string> vTemp; //temporary vector used to store elements for easier insertion into the main vector

        while(std::getline(stringstr, sTemp, ',')) {
            vTemp.push_back(sTemp); //pushing elements into temp vector
        }

        PublicSupplier s; //initializing an object for one supplier to hold values obtained by vTemp
        s.sID = std::stoi(vTemp[0]); //converting string ID into an integer
        s.Name = vTemp[1];
        s.setAddr(vTemp[2]);
        s.setPhone(vTemp[3]);
        s.setEmail(vTemp[4]);

        Suppliers.push_back(s); //inserting the supplier vector as one element of the larger Suppliers vector

    };

    int size = Suppliers.size(); //making a separate integer for the size of the vector array

    // basic output loop for testing/debugging
    /*
    for (int i = 0; i < size; i++) { 
        cout << Suppliers[i].sID
        << Suppliers[i].Name
        << Suppliers[i].getAddr()
        << Suppliers[i].getPhone()
        << Suppliers[i].getEmail() << endl;
    };
    */

    infile.close(); //closing file
    return Suppliers;
}
