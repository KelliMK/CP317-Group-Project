#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <string>
#include <vector>

using namespace std;

// And Here We Test Our Powers Of Encapsulation
class Supplier{
        public:
                int sID;
                string Name;
        protected:
                string Addr;
                string Phone;
                string Email;
};

// And Here We Test Our Powers Of Inheritance 
// (doesn't reflect the song title as well)
class PublicSupplier: public Supplier {
        public:
                string getAddr() { return Addr; }
                string getPhone() { return Phone; }
                string getEmail() { return Email; }
                void setAddr(string inputA) { Addr = input; }
                void setPhone(string inputP) { Phone = input; }
                void setEmail(string inputE) { Email = input; }
}

// And Here We Test Our Powers Of Polymorphism
std::vector<PublicSupplier> suppliers(string filename);
std::vector<PublicSupplier> suppliers();

#endif