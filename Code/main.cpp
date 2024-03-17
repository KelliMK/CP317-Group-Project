/*
 -------------------------------------
 File:    main.c
 Project: CP317
 -------------------------------------
 Author:  Kelli M Knipe
 Email:   knip7550@mylaurier.ca
 Version  2023-12-02
 -------------------------------------
 */

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <iostream>
# include <fstream>
# include <vector>
# include <filesystem> // C++17 or later required
# include <math.h>
# include "supplier.h"
# include "product.h"
using namespace std;
namespace fs = std::filesystem;

//prototype
void outputter(std::vector<Supplier> supplierVect, std::vector<Product> productVect, string outputFileName);

int main(int argc, char* argv[]) {
    int safetyKey = 0;
    if (argc == 4) {
        fs::path suppFilePath = argv[1];
        fs::path prodFilePath = argv[2];
        fs::path outFilePath = argv[3];
        if (suppFilePath.extension() != ".txt") {
            cout << "Your second argument needs to end in .txt for safe reading.\n";
            safetyKey++;
        }
        if (prodFilePath.extension() != ".txt") {
            cout << "Your third argument needs to end in .txt for safe reading.\n";
            safetyKey++;
        }
        if (outFilePath.extension() != ".txt") {
            cout << "Your fourth argument needs to end in .txt for safe reading.\n";
            safetyKey++;
        }
    } else {
        safetyKey = 1;
    }
    if (safetyKey == 0) {
        std::vector<Supplier> suppInput = suppliers(argv[1]);
        std::vector<Product> prodInput = products(argv[2]);
        outputter(suppInput, prodInput, argv[3]);
        return 0;
    } else {
        cout << "Please include three .txt files after program name, for example:\n\n";
        cout << "    ./InventoryGenerator suppliersFile.txt productsFile.txt outputInventoryFile.txt\n\n";
        return 1;
    }
}

void outputter(std::vector<Supplier> supplierVect, std::vector<Product> productVect, string outputFileName) {
    ofstream outputFile(outputFileName);
    int prodVectLen = size(productVect); // get size of product vector
    int suppVectLen = size(supplierVect); // get size of supplier vector
    string theLine;     // String to print to file
    string com = ",";  // Comma delimiter for output
    string suppName;    // 
    for (int i = 0; i < prodVectLen; i++) {
        theLine = "";
        suppName = "";
        Product currentProd = productVect.at(i);
        int matcher = currentProd.sID;
        for (int j = 0; j < suppVectLen; j++) {
            Supplier suppClone = supplierVect.at(j);
            if (matcher == suppClone.sID) {
                suppName = suppClone.Name;
                j = suppVectLen;
            }
            if (j == (suppVectLen - 1) && suppName == "") {
                suppName = "Not Found in supplier list";
            }
        }

        outputFile << currentProd.pID << com 
        << currentProd.Name << com << " " 
        << currentProd.Quantity << com 
        << currentProd.Price << com 
        << currentProd.Status << com 
        << suppName << endl;
    }
    outputFile.close();
    return;
}