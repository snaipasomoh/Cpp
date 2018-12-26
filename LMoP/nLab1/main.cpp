#include <iostream>
#include <fstream>
#include <cmath>
#include "delist.h"

double f (double x){
	return sin(x);
}

int main (int argc, char **argv){
	lab::delist newList;
	lab::dObj newObj;
	newObj.setRLim(asin(1));
	newObj.setFunc(&f);
 	newList.add(newObj);
	newObj.setRLim(asin(1) * 2);
	newList.add(newObj);
	newObj.setRLim(asin(1) * 4);
	newList.add(newObj);
	newList.write(std::cout);
	std::cout << std::endl;

	newList.get(0).calcVal();
	newList.get(1).calcVal();
	newList.get(2).calcVal();

	lab::delist secList(newList.find(newObj));
	secList.write(std::cout);
	std::cout << std::endl;

	newObj = secList.get(2);
	std::cout << secList.size() << std::endl;
	secList.write(std::cout);
	std::cout << std::endl;

	std::ofstream fout ("buf.txt");
	secList.insert(newObj, 3);
	secList.write(fout);
	fout << std::endl;
	fout.close();

	std::ifstream fin ("buf.txt");
	newList.read(fin);
	newList.write(std::cout);
	std::cout << std::endl;
	fin.close();
}
