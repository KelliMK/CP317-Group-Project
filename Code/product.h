#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <vector>

using namespace std;

struct Product
    {
        int pID;
        string Name;
        string Desc;
        string Price; 
        int Quantity;
        string Status; 
        int sID;
    };

std::vector<Product> products(string filename);

#endif