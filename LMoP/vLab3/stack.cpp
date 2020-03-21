#include "stack.hpp"

lab::Stack::Stack (lab::List const &other){
	head = nullptr;
	size = 0;
	for (size_t i = 0; i < other.getSize(); i++){
		add(other.get(i));
	}
}

void lab::Stack::push (lab::State const &data){
	add(data);
}

lab::State lab::Stack::pop (){
	lab::State data = get(-1);
	remove(-1);
	return data;
}
