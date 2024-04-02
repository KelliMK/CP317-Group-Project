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
void outputter(std::vector<PublicSupplier> supplierVect, std::vector<Product> productVect, string outputFileName);

/* Main function that calls all lower functionality */
int main(int argc, char* argv[]) {
    int safetyKey = 0;
    
    if (argc == 4) {    // Checks for correctly input arguments
        fs::path suppFilePath = argv[1];
        fs::path prodFilePath = argv[2];
        fs::path outFilePath = argv[3];
        if (suppFilePath.extension() != ".txt") {
            cerr << "Your second argument needs to end in .txt for safe reading.\n";
            safetyKey++;
        }
        if (prodFilePath.extension() != ".txt") {
            cerr << "Your third argument needs to end in .txt for safe reading.\n";
            safetyKey++;
        }
        if (outFilePath.extension() != ".txt") {
            cerr << "Your fourth argument needs to end in .txt for safe reading.\n";
            safetyKey++;
        }
    } else {
        safetyKey = 1;
    }


    if (safetyKey == 0) {   // Main Function calls
        std::vector<PublicSupplier> suppInput = suppliers(argv[1]);
        std::vector<Product> prodInput = products(argv[2]);
        outputter(suppInput, prodInput, argv[3]);
        return 0;
    } else {
        cerr << "Please include three .txt files after program name, for example:\n\n";
        cerr << "    ./CinventoryGenerator suppliersFile.txt productsFile.txt outputInventoryFile.txt\n\n";
        exit(EXIT_FAILURE);
    }
}



/* Outputs to file given in argv[3] */
void outputter(std::vector<PublicSupplier> supplierVect, std::vector<Product> productVect, string outputFileName) {
    
    ofstream outputFile(outputFileName);    // ofstream to write to output file
    int prodVectLen = size(productVect);    // get size of product vector
    int suppVectLen = size(supplierVect);   // get size of supplier vector
    string com = ",";  // Comma delimiter for output
    string suppName;    // supplier name


    /*
    for (int i = 0; i < suppVectLen; i++) {     // Duplicate sIDs check
        for (int j = (i + 1); j < suppVectLen; j++) {
            if (supplierVect[i].sID == supplierVect[j].sID) {
                cerr << "Multiple supplier entries with ID " + std::to_string(supplierVect[i].sID) + "\n";
                exit(EXIT_FAILURE);
            }
        }
    }
    */

    /*
    for (int i = 0; i < prodVectLen; i++) {     // Duplicate pIDs check
        for (int j = (i + 1); j < prodVectLen; j++) {
            if (productVect[i].pID == productVect[j].pID) {
                cerr << "Multiple product entries with ID " + std::to_string(productVect[i].pID) + "\n";
                exit(EXIT_FAILURE);
            }
        }
    }
    */

    for (int i = 0; i < (prodVectLen); i++) {   // matches sIDs for inserting supplier names
        suppName = "";
        Product currentProd = productVect.at(i);
        int matcher = currentProd.sID;
        for (int j = 0; j <= suppVectLen; j++) {
            Supplier suppClone = supplierVect.at(j);
            if (matcher == suppClone.sID) {
                suppName = suppClone.Name;
                j = suppVectLen;
            }

            if (j == (suppVectLen - 1) && suppName == "") {     // Unknown Supplier check
                suppName = "Not Found in supplier list";
                cerr << "Unknown supplier for product ID " + std::to_string(currentProd.pID) + "\n";
                exit(EXIT_FAILURE);
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