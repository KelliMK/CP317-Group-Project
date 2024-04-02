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

// And Here We Test Our Powers Of Inheritance S
class PublicSupplier: public Supplier {
        public:
                string getAddr() { return Addr; }
                string getPhone() { return Phone; }
                string getEmail() { return Email; }
                void setAddr(string inputA) { Addr = inputA; }
                void setPhone(string inputP) { Phone = inputP; }
                void setEmail(string inputE) { Email = inputE; }
};

// And Here We Test Our Powers Of Polymorphism
std::vector<PublicSupplier> suppliers();
std::vector<PublicSupplier> suppliers(string filename);

#endif