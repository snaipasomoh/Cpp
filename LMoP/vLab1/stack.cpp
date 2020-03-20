#include "stack.hpp"

/*

 ######  ########  ########  ######  ####    ###    ##
##    ## ##     ## ##       ##    ##  ##    ## ##   ##
##       ##     ## ##       ##        ##   ##   ##  ##
 ######  ########  ######   ##        ##  ##     ## ##
      ## ##        ##       ##        ##  ######### ##
##    ## ##        ##       ##    ##  ##  ##     ## ##
 ######  ##        ########  ######  #### ##     ## ########

*/

lab::Stack::Stack () :
	head(nullptr), size(0) {}

lab::Stack::Stack (lab::Stack const &other){
	head = nullptr;
	size = 0;
	for (size_t i = 0; i < other.size; i++){
		add(other.get(i));
	}
}

lab::Stack &lab::Stack::operator= (lab::Stack const &other){
	if (this != &other){
		lab::Stack::Node *currNode = head;
		lab::Stack::Node *nextNode;
		while ((nextNode = currNode->next) != nullptr){
			delete currNode;
			currNode = nextNode;
		}
		delete currNode;

		lab::Stack tempStack(other);
		head = tempStack.head;
		tempStack.head = nullptr;
		size = tempStack.size;
		tempStack.size = 0;
	}
	return *this;
}

lab::Stack::~Stack (){
	if (!size){
		return;
	}
	lab::Stack::Node *currNode = head;
	lab::Stack::Node *nextNode;
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

void lab::Stack::add (lab::State const &data){
	insert(data, size);
}

void lab::Stack::insert (lab::State const &data, size_t index){
	if (index > size){
		return;
	}
	if (index == size){
		lab::Stack::Node *newNode = new lab::Stack::Node;
		newNode->data = data;
		newNode->next = head;
		head = newNode;
		size++;
		return;
	}
	lab::Stack::Node *prevNode = head;
	lab::Stack::Node *currNode = prevNode->next;
	for (size_t i = size - 1; i > index; i--){
		prevNode = currNode;
		currNode = prevNode->next;
	}
	lab::Stack::Node *newNode = new lab::Stack::Node;
	newNode->data = data;
	newNode->next = currNode;
	prevNode->next = newNode;
	size++;
}

void lab::Stack::remove (size_t index){
	std::cout << index << " " << size << std::endl;
	if (index >= size){
		return;
	}
	lab::Stack::Node *currNode = head;
	if (index + 1 == size){
		head = head->next;
		delete currNode;
		size--;
		return;
	}
	currNode = head;
	lab::Stack::Node *prevNode;
	for (size_t i = size - 1; i > index; i--){
		prevNode = currNode;
		currNode = prevNode->next;
	}
	prevNode->next = currNode->next;
	delete currNode;
	size--;
}

lab::State &lab::Stack::get (size_t index){
	if (index + 1 == size){
		return head->data;
	}
	lab::Stack::Node *currNode = head;
	for (size_t i = size - 1; i > index; i--){
		currNode = currNode->next;
	}
	return currNode->data;
}

lab::State lab::Stack::get (size_t index) const{
	if (index + 1 == size){
		return head->data;
	}
	lab::Stack::Node *currNode = head;
	for (size_t i = size - 1; i > index; i--){
		currNode = currNode->next;
	}
	return currNode->data;
}

std::ostream &lab::Stack::write (std::ostream &fout) const{
	for (size_t i = 0; i < size; i++){
		get(i).write(fout);
	}
	return fout;
}

std::istream &lab::Stack::read (std::istream &fin){
	lab::Stack::Node *currNode = head;
	lab::Stack::Node *nextNode;
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

size_t lab::Stack::getSize () const{
	return size;
}
