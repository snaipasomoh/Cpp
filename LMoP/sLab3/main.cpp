#include <iostream>
#include <fstream>
#include "ordelist.h"

int main (int argc, char **argv){
	lab::delist newList;
	lab::dObj newObj;
	newList.add(newObj);
	newObj = lab::dObj("Foo", std::set<std::string>({"sFoo", "sBar", "sBaz"}), 1950, 10000, 2);
	newList.add(newObj);
	newObj = lab::dObj("Bar", std::set<std::string>({"sFoo", "sBar", "sBaz"}), 1950, 10000, 2);
	newList.add(newObj);
	newObj = lab::dObj("Baz", std::set<std::string>({"sFoo", "sBar", "sBaz"}), 1950, 10000, 2);
	newList.add(newObj);
	newList.write(std::cout);
	std::cout << std::endl;
	std::cerr << "point 1" << std::endl;

	lab::delist secList(newList.find(newObj));
	secList.write(std::cout);
	std::cout << std::endl;
	std::cerr << "point 2" << std::endl;

	newObj = secList.get(2);
	std::cout << secList.size() << std::endl;
	secList.write(std::cout);
	std::cout << std::endl;
	std::cerr << "point 3" << std::endl;

	std::ofstream fout ("buf.txt");
	secList.insert(newObj, 3);
	secList.write(fout);
	fout << std::endl;
	fout.close();
	std::cerr << "point 4" << std::endl;

	std::ifstream fin ("buf.txt");
	newList.read(fin);
	newList.write(std::cout);
	std::cout << std::endl;
	fin.close();
	std::cerr << "point 5" << std::endl;

	lab::ordelist newOrdelist;
	lab::dObj orObj;
	orObj = lab::dObj("Baz", std::set<std::string>({"sFoo", "sBar", "sBaz"}), 1950, 10000, 2);
	newOrdelist.ordadd(orObj);
	orObj = lab::dObj("Foo", std::set<std::string>({"sFoo", "sBar", "sBaz"}), 1950, 10000, 2);
	newOrdelist.ordadd(orObj);
	orObj = lab::dObj("Bar", std::set<std::string>({"sFoo", "sBar", "sBaz"}), 1950, 10000, 2);
	newOrdelist.ordadd(orObj);
	std::cout << newOrdelist << std::endl;
	std::cerr << "point 6" << std::endl;

	lab::ordelist omOrdelist;
	try{
		omOrdelist.rem(-1);
	}
	catch (std::exception const &e){
		std::cerr << e.what() << std::endl;
	}
	std::cerr << "point 7" << std::endl;
}
