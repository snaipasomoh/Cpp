#include <iostream>
#include <functional>
#include <string>
#include "destack.h"
#include "dataObj.h"

struct mCmp{
	bool operator() (lab::dObj const &a, lab::dObj const &b){
		return b < a;
	}
};

struct good : std::unary_function<lab::dObj, bool>{

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

	bool operator() (lab::dObj const &a) const{
		if (state == 0){
			return a.getYear() < exmpl;
		}
		if (state == 1){
			return a.getYear() == exmpl;
		}
		return a.getYear() > exmpl;
	}
private:
	int exmpl = 0;
	unsigned state = 0;
};

int main (int argc, char **argv){
	lab::dObj b0("Name0", std::set<std::string>({"Sport00", "Sport10"}), 0, 0, 0);
	lab::dObj b1("Name1", std::set<std::string>({"Sport01", "Sport11"}), 1, 1, 1);
	lab::dObj b2("Name2", std::set<std::string>({"Sport02", "Sport12"}), 2, 2, 2);
	lab::dObj b3("Name3", std::set<std::string>({"Sport03", "Sport13"}), 3, 3, 3);
	Destack<lab::dObj> foo({b0, b1, b2, b3});
	foo.reverse();
	Destack<lab::dObj> bar(foo);
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
