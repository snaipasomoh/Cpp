#include "buyer.h"
#include "dStack.h"
#include <iostream>
#include <cstring>

bool mcmp(Lab1NS::Buyer const &a, Lab1NS::Buyer const &b){
	return !strcmp(a.getSecondName(), b.getSecondName());
}

int main (int argc, char **argv){
	Lab1NS::Buyer newBuyer("Ivanov", "Ivan", "Moscow", "Arbat",
						   1, 1, "IIMA11", 10000);

	Lab1NS::dStack<Lab1NS::Buyer> newStack;
	newStack.push(newBuyer);
	newBuyer.setSecondName("Petrov");
	newStack = newStack + newBuyer;
	newBuyer.setSecondName("Sidorov");
	newStack.insert(1, newBuyer);
	newStack[2].setAvgAmount(15000);

	std::cout << newStack << std::endl;
	std::cout << std::endl;

	newStack = newStack - newBuyer;
	std::cout << newStack << std::endl;
	std::cout << "@@@@@@@@@@@@@@@" << std::endl;
	try{
		std::cout << newStack[-2] << std::endl;
	}
	catch(std::exception const &e){
		std::cout << e.what() << std::endl;
	}
}
