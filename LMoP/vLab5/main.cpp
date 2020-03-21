#include "stack.hpp"
#include "state.hpp"
#include <functional>
#include <fstream>

struct mCmp{
	bool operator() (lab::State const &a, lab::State const &b){
		return b < a;
	}
};

struct good : std::unary_function<lab::State, bool>{

	good (size_t val, char st) : exmpl(val){
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

	bool operator() (lab::State const &a) const{
		if (state == 0){
			return a.getArea() < exmpl;
		}
		if (state == 1){
			return a.getArea() == exmpl;
		}
		return a.getArea() > exmpl;
	}
private:
	size_t exmpl = 0;
	unsigned state = 0;
};

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

	Stack<lab::State> stack;
	stack.push_back(usa);
	stack.push_back(rus);

	rus.setName("Russia2");
	stack.insert(stack.begin(), rus);
	std::cout << stack;

	stack.sort(mCmp());
	std::cout << stack;

	std::ofstream fout ("data.txt");
	fout << stack;
	fout.close();

	std::ifstream fin ("data.txt");

	Stack<lab::State> stack2;
	fin >> stack2;
	fin.close();

	stack2.erase(stack2.begin());
	std::cout << stack2;
	std::cout << std::endl;

	Stack<lab::State> stack3 = stack.find_if(good(16000000, 'm'));
	std::cout << stack3;
	std::cout << std::endl;

}
