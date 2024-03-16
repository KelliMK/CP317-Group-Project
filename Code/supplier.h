#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <string>
#include <vector>

using namespace std;

struct Supplier {
        int sID;
        string Name;
        string Addr;
        string Phone;
        string Email;
    };

std::vector<Supplier> suppliers(string filename);

#endif