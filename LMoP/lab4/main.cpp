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

	Lab1NS::dStack<Lab1NS::Buyer, 10> newStack;
	newStack.push(newBuyer);
	newBuyer.setSecondName("Petrov");
	newStack = newStack + newBuyer;
	newBuyer.setSecondName("Sidorov");
	newStack.insert(1, newBuyer);
	newStack[2].setAvgAmount(15000);

	std::cout << "newStack max size: " << newStack.maxSize() << std::endl;
	//Lab1NS::dStack<Lab1NS::Buyer, 5> secStack = newStack;						//unknoun conversion here

	std::cout << newStack << std::endl;
	std::cout << std::endl;

	newStack = newStack - newBuyer;
	std::cout << newStack << std::endl;
}
