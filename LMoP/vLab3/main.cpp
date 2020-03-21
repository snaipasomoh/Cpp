#include "stack.hpp"
#include <fstream>

bool finder (lab::State const &a, lab::State const &b){
	return b.getArea() < a.getArea();
}

int main (int argc, char **argv){
	lab::State rus;
	rus.setName("Russia");
	rus.setCapital("Moscow");
	rus.setLanguage("Russian");
	rus.setPopulation(144000000);
	rus.setArea(17100000);
	lab::State usa;
	usa.setName("USA");
	usa.setCapital("Washington");
	usa.setLanguage("English");
	usa.setPopulation(327000000);
	usa.setArea(9834000);

	lab::Stack stack;
	stack.push(rus);
	stack.push(usa);


	std::ofstream fout ("data.txt");
	fout << stack;
	fout.close();

	std::ifstream fin ("data.txt");

	lab::Stack stack2;
	fin >> stack2;
	fin.close();

	stack2.pop();
	stack2.write(std::cout);
	std::cout << std::endl;

	lab::Stack stack3 = stack.find(rus, finder);
	stack3.write(std::cout);
	std::cout << std::endl;

	stack.find(usa).write(std::cout);
}
