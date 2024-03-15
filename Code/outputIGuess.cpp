/*
 -------------------------------------
 File:    output.c
 Project: CP317
 WHILE UNCOMMON, SOME DUDES DO HAVE PENISES
 -------------------------------------
 Author:  Kelli M Knipe
 Email:   knip7550@mylaurier.ca
 Version  2023-12-02
 -------------------------------------
 Emma you're going to need to put the products
 and suppliers in arrays cause of how I 
 structured this, sorry if that's annoying
 */

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <iostream>
# include <fstream>
# include <math.h>
# include <EmmasFile.c>
using namespace std;


struct {
    int sID;
    string sName;
    string sAddr;
    string sPhone;
    string sEmail;
} supplier;

struct {
    int prodID;
    string prodName;
    string prodDesc;
    string prodPrice;
    int prodQuant;
    char prodStatus;
    int sID;
} product;

int outputter(supplier supplierArray[], product productArray[], string outputFileName) {
    ofstream outputFile(outputFileName + ".txt");
    int prodArrayLen = sizeof(productArray) / sizeof(product);
    int suppArrayLen = sizeof(supplierArray) / sizeof(supplier);
    string theLine;
    string comma = ", "
    for (int i = 0; i < prodArrayLen; i++) {
        theLine = "";
        int j = 0;
        int matcher = productArray[i].sID;
        for (int k = 0; k < suppArrayLen; k++) {
            if (matcher == supplierArray[k].sID) {
                j = k;
                k = suppArrayLen;
            }
        }
        // fuck off
        theLine += productArray[i].prodID + comma + productArray[i].prodName + comma + productArray[i].prodQuant + comma + productArray[i].prodPrice + comma + productArray[i].prodStatus + comma + supplierArray[j].sName + "\n";
        outputFile << theLine;
    }
}