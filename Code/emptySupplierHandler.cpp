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

std::vector<PublicSupplier> suppliers() {
	std::vector<PublicSupplier> s;
	PublicSupplier s1, s2, s3;

	s1.sID = 1111;
	s1.Name = "Supplier 1";
	s1.setAddr("Supplier 1 Address");
	s1.setPhone("111-111-1111");
	s1.setEmail("one@supplierOne.com");
	s.push_back(s1);

	s2.sID = 1111;
	s2.Name = "Supplier 2";
	s2.setAddr("Supplier 2 Address");
	s2.setPhone("222-222-2222");
	s2.setEmail("two@supplierTwo.com");
	s.push_back(s2);

	s3.sID = 3333;
	s3.Name = "Supplier 3";
	s3.setAddr("Supplier 3 Address");
	s3.setPhone("333-333-3333");
	s3.setEmail("three@supplierThree.com");
	s.push_back(s3);

	s4.sID = 6789;
	s4.Name = "Hitachi";
	s3.setAddr("123 Hitachi city");
	s3.setPhone("446-234-2314");
	s3.setEmail("support@hitachi.co.jp");
	s.push_back(s4);

	s5.sID = 4567;
	s5.Name = "Fujistsu";
	s5.setAddr("345 Tokyo city");
	s5.setPhone("03-3456-7890");
	s5.setEmail("support@fujistsu.co.jp");
	s.push_back(s5);


	return s;
}