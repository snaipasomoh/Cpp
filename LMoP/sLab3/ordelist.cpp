#include "ordelist.h"

lab::ordelist::ordelist (delist const &other){
	for (size_t i = 0; i < other.size(); i++){
		this->ordadd(other[i]);
	}
}

void lab::ordelist::ordadd (lab::dObj const &data){
	size_t i = 0;
	for (; i < this->size(); i++){
		if (this->get(i) >= data){
			break;
		}
	}
	if (i == this->size()){
		this->add(data);
	}
	else{
		this->insert(data, i);
	}
}
