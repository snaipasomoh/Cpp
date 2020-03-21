#include "list.hpp"

/*

 ######  ########  ########  ######  ####    ###    ##
##    ## ##     ## ##       ##    ##  ##    ## ##   ##
##       ##     ## ##       ##        ##   ##   ##  ##
 ######  ########  ######   ##        ##  ##     ## ##
      ## ##        ##       ##        ##  ######### ##
##    ## ##        ##       ##    ##  ##  ##     ## ##
 ######  ##        ########  ######  #### ##     ## ########

*/

lab::List::List () :
	head(nullptr), size(0) {}

lab::List::List (lab::List const &other){
	head = nullptr;
	size = 0;
	for (size_t i = 0; i < other.size; i++){
		add(other.get(i));
	}
}

lab::List &lab::List::operator= (lab::List const &other){
	if (this != &other){
		if (head != nullptr){
			lab::List::Node *currNode = head;
			lab::List::Node *nextNode;
			while ((nextNode = currNode->next) != nullptr){
				delete currNode;
				currNode = nextNode;
			}
			delete currNode;
		}

		lab::List tempList(other);
		head = tempList.head;
		tempList.head = nullptr;
		size = tempList.size;
		tempList.size = 0;
	}
	return *this;
}

lab::List::~List (){
	if (!size){
		return;
	}
	lab::List::Node *currNode = head;
	lab::List::Node *nextNode;
	while ((nextNode = currNode->next) != nullptr){
		delete currNode;
		currNode = nextNode;
	}
	delete currNode;
}

/*

##     ## ######## ######## ##     ##  #######  ########   ######
###   ### ##          ##    ##     ## ##     ## ##     ## ##    ##
#### #### ##          ##    ##     ## ##     ## ##     ## ##
## ### ## ######      ##    ######### ##     ## ##     ##  ######
##     ## ##          ##    ##     ## ##     ## ##     ##       ##
##     ## ##          ##    ##     ## ##     ## ##     ## ##    ##
##     ## ########    ##    ##     ##  #######  ########   ######

*/

void lab::List::add (lab::State const &data){
	insert(data, size);
}

void lab::List::insert (lab::State const &data, int index){
	if (index < 0){
		index += size;
	}
	if (index < 0 || (size_t)index > size){
		throw(ListOORE());
	}
	if ((size_t)index == size){
		lab::List::Node *newNode = new lab::List::Node;
		newNode->data = data;
		newNode->next = head;
		head = newNode;
		size++;
		return;
	}
	lab::List::Node *prevNode = head;
	lab::List::Node *currNode = prevNode->next;
	for (size_t i = size - 1; i > (size_t)index; i--){
		prevNode = currNode;
		currNode = prevNode->next;
	}
	lab::List::Node *newNode = new lab::List::Node;
	newNode->data = data;
	newNode->next = currNode;
	prevNode->next = newNode;
	size++;
}

void lab::List::remove (int index){
	if (size == 0){
		throw(ListRFELE());
	}
	if (index < 0){
		index += size;
	}
	if (index < 0 || (size_t)index >= size){
		throw(ListOORE());
	}
	lab::List::Node *currNode = head;
	if ((size_t)index + 1 == size){
		head = head->next;
		delete currNode;
		size--;
		return;
	}
	currNode = head;
	lab::List::Node *prevNode;
	for (size_t i = size - 1; i > (size_t)index; i--){
		prevNode = currNode;
		currNode = prevNode->next;
	}
	prevNode->next = currNode->next;
	delete currNode;
	size--;
}

lab::State &lab::List::get (int index){
	if (index < 0){
		index += size;
	}
	if (index < 0 || (size_t)index >= size){
		throw(ListOORE());
	}
	if ((size_t)index + 1 == size){
		return head->data;
	}
	lab::List::Node *currNode = head;
	for (size_t i = size - 1; i > (size_t)index; i--){
		currNode = currNode->next;
	}
	return currNode->data;
}

lab::State lab::List::get (int index) const{
	if (index < 0){
		index += size;
	}
	if (index < 0 || (size_t)index >= size){
		throw(ListOORE());
	}
	if ((size_t)index + 1 == size){
		return head->data;
	}
	lab::List::Node *currNode = head;
	for (size_t i = size - 1; i > (size_t)index; i--){
		currNode = currNode->next;
	}
	return currNode->data;
}

std::ostream &lab::List::write (std::ostream &fout) const{
	for (size_t i = 0; i < size; i++){
		get(i).write(fout);
	}
	return fout;
}

std::istream &lab::List::read (std::istream &fin){
	lab::List::Node *currNode = head;
	lab::List::Node *nextNode;
	if (head != nullptr){
		while ((nextNode = currNode->next) != nullptr){
			delete currNode;
			currNode = nextNode;
		}
		delete currNode;
	}
	head = nullptr;
	size = 0;

	lab::State tempState;
	while(tempState.read(fin)){
		add(tempState);
	}
	return fin;
}

size_t lab::List::getSize () const{
	return size;
}

/*

 #######  ##     ## ######## ########  ##        #######     ###    ########
##     ## ##     ## ##       ##     ## ##       ##     ##   ## ##   ##     ##
##     ## ##     ## ##       ##     ## ##       ##     ##  ##   ##  ##     ##
##     ## ##     ## ######   ########  ##       ##     ## ##     ## ##     ##
##     ##  ##   ##  ##       ##   ##   ##       ##     ## ######### ##     ##
##     ##   ## ##   ##       ##    ##  ##       ##     ## ##     ## ##     ##
 #######     ###    ######## ##     ## ########  #######  ##     ## ########

*/

lab::List lab::List::operator+ (lab::State const &data){
	lab::List res(*this);
	res.add(data);
	return res;
}

lab::List lab::List::operator- (lab::State const &data){
	lab::List res;
	for (size_t i = 0; i < getSize(); i++){
		if (get(i) == data){
			continue;
		}
		res.add(get(i));
	}
	return res;
}

lab::List lab::operator+ (lab::State const &data, lab::List &st){
	return st + data;
}

lab::List lab::operator- (lab::State const &data, lab::List &st){
	return st - data;
}

lab::State lab::List::operator[] (int index) const{
	return get(index);
}

lab::State &lab::List::operator[] (int index){
	return get(index);
}

std::ostream &lab::operator<< (std::ostream &fout, lab::List const &cnt){
	return cnt.write(fout);
}

std::istream &lab::operator>> (std::istream &fin, lab::List &cnt){
	return cnt.read(fin);
}
