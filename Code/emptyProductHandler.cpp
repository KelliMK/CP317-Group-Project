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

std::vector<Product> products() {
	std::vector<Product> testProds;
	Product p1, p2, p3;
	
	p1.pID = "1000";
	p1.Name = "Product 1";
	p1.Desc = "First Testing Product";
	p1.Price = "$100.00";
	p1.Quantity = 10;
	p1.Status = "A";
	p1.sID = 1111;
	testProds.push_back(p1);

	p2.pID = "2000";
	p2.Name = "Product 2";
	p2.Desc = "Second Testing Product";
	p2.Price = "$200.00";
	p2.Quantity = 20;
	p2.Status = "B";
	p2.sID = 2222;
	testProds.push_back(p2);

	p3.pID = "3000";
	p3.Name = "Product 3";
	p3.Desc = "Third Testing Product";
	p3.Price = "$300.00";
	p3.Quantity = 30;
	p3.Status = "C";
	p3.sID = 3333;
	testProds.push_back(p3);

	return testProds;
}