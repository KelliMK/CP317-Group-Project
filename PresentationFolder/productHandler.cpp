#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include "product.h"

using namespace std;

/* Main product handler, for outputting a vector of product objects */
std::vector<Product> products(string filename) {

    /*
    deprecated
    string filename = "testProduct.txt"; 
    */

    std::vector<Product> Products; 

    ifstream infile(filename); 

    string line; 

    if (!infile) {
        cerr << "Invalid input file.\n";
        exit(1);
    }

    while (getline(infile, line)) { 

        std::istringstream stringstr(line);

        string sTemp;
        vector<string> vTemp; 

        while(std::getline(stringstr, sTemp, ',')) {
            vTemp.push_back(sTemp); 
        }

        Product p; 
        p.pID = std::stoi(vTemp[0]); 
        p.Name = vTemp[1];
        p.Desc = vTemp[2];
        p.Price = vTemp[3];
        p.Quantity = std::stoi(vTemp[4]);
        p.Status = vTemp[5];
        p.sID = std::stoi(vTemp[6]);

        Products.push_back(p); 

    };

    int size = Products.size(); 

    /*
    deprecated test
    for (int i = 0; i < size; i++) { 
        cout << Products[i].pID
        << Products[i].Name
        << Products[i].Desc
        << Products[i].Price << " " // this was needed to properly space the outputted elements
        << Products[i].Quantity
        << Products[i].Status  << " " // as was this
        << Products[i].sID << endl;
    };
    */

    infile.close(); 
    return Products;
}
