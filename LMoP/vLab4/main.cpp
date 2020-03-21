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

	lab::Stack<lab::State> stack;
	stack.add(rus);
	stack.add(usa);

	rus.setName("Russia2");
	stack.insert(rus, 1);

	std::ofstream fout ("data.txt");
	stack.write(fout);
	fout.close();

	std::ifstream fin ("data.txt");

	lab::Stack<lab::State> stack2;
	stack2.read(fin);
	fin.close();

	stack2.remove(0);
	stack2.write(std::cout);
	std::cout << std::endl;

	lab::Stack<lab::State> stack3 = stack.find(rus, finder);
	stack3.write(std::cout);
	std::cout << std::endl;

	stack.find(usa).write(std::cout);
}
