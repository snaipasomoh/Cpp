#include <iostream>
#include <functional>
#include "destack.h"
#include "buyer.h"

struct mCmp{
	bool operator() (Lab1NS::Buyer const &a, Lab1NS::Buyer const &b){
		return b < a;
	}
};

struct good : std::unary_function<Lab1NS::Buyer, bool>{

	good (int val, char st) : exmpl(val){
		if (st == 'l'){
			state = 0;
		}
		else if (st == 'e'){
			state = 1;
		}
		else if (st == 'm'){
			state = 2;
		}
	}

	bool operator() (Lab1NS::Buyer const &a) const{
		if (state == 0){
			return a.getAvgAmount() < exmpl;
		}
		if (state == 1){
			return a.getAvgAmount() == exmpl;
		}
		return a.getAvgAmount() > exmpl;
	}
private:
	int exmpl = 0;
	unsigned state = 0;
};

int main (int argc, char **argv){
	Lab1NS::Buyer b0("SecondName0", "Name0", "City0", "Street0", 0, 0, "ID0", 0);
	Lab1NS::Buyer b1("SecondName1", "Name1", "City1", "Street1", 1, 1, "ID1", 1);
	Lab1NS::Buyer b2("SecondName2", "Name2", "City2", "Street2", 2, 2, "ID2", 2);
	Lab1NS::Buyer b3("SecondName3", "Name3", "City3", "Street3", 3, 3, "ID3", 3);
	Destack<Lab1NS::Buyer> foo({b0, b1, b2, b3});
	foo.reverse();
	Destack<Lab1NS::Buyer> bar(foo);
	foo.reverse();
	std::cout << foo << std::endl;
	std::cout << "POINT 1......................................" << std::endl << std::endl;
	std::cout << foo[0] << std::endl << foo[1] << std::endl;
	std::cout << "POINT 2......................................" << std::endl << std::endl;
	bar = foo;
	std::cout << bar << std::endl;
	std::cout << "POINT 3......................................" << std::endl << std::endl;
	bar.sort(mCmp());
	std::cout << bar << std::endl;
	std::cout << "POINT 4......................................" << std::endl << std::endl;
	bar.reverse();
	std::cout << bar.find_if(good(2, 'l')) << std::endl;
	std::cout << "POINT 5......................................" << std::endl << std::endl;
	return 0;
}
