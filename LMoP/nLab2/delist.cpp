#include "delist.h"

/*

 ######  ########  ########  ######  ####    ###    ##
##    ## ##     ## ##       ##    ##  ##    ## ##   ##
##       ##     ## ##       ##        ##   ##   ##  ##
 ######  ########  ######   ##        ##  ##     ## ##
      ## ##        ##       ##        ##  ######### ##
##    ## ##        ##       ##    ##  ##  ##     ## ##
 ######  ##        ########  ######  #### ##     ## ########

*/

lab::delist::delist (lab::delist const &other){
	lab::delist::Node *currNode = other.Head;
	for (size_t i = 0; i < other.Size; i++){
		this->add(currNode->Data);
		currNode = currNode->Next;
	}
}

lab::delist &lab::delist::operator= (lab::delist const &other){
	if (this != &other){
		lab::delist::Node *currNode = Head;
		for (size_t i = 0; i < Size; i++){
			lab::delist::Node *nextNode = currNode->Next;
			delete currNode;
			currNode = nextNode;
		}
		lab::delist tempDelist(other);
		Head = tempDelist.Head;
		tempDelist.Head = nullptr;
		Size = tempDelist.Size;
		tempDelist.Size = 0;
	}
	return *this;
}

lab::delist::~delist (){
	lab::delist::Node *currNode = Head;
	for (size_t i = 0; i < Size; i++){
		lab::delist::Node *nextNode = currNode->Next;
		delete currNode;
		currNode = nextNode;
	}
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

void lab::delist::add (lab::dObj const &data){
	lab::delist::Node *newNode = new lab::delist::Node;
	newNode->Data = data;
	newNode->Next = nullptr;													//newNode->Next = Head if circ list
	newNode->Prev = nullptr;
	if (!Size){
		Head = newNode;
		Head->Next = Head;
		Head->Prev = Head;
		Size++;
		return;
	}
	lab::delist::Node *currNode = Head;
	for (size_t i = 0; i < Size - 1; i++){
		currNode = currNode->Next;
	}
	currNode->Next = newNode;
	newNode->Prev = currNode;
	Head->Prev = newNode;
	newNode->Next = Head;
	Size++;
}

lab::dObj lab::delist::rem (size_t index){
	lab::delist::Node *currNode = Head;
	for (size_t i = 0; i < index; i++){
		currNode = currNode->Next;
	}
	dObj res = currNode->Data;
	currNode->Prev->Next = currNode->Next;
	currNode->Next->Prev = currNode->Prev;
	if (currNode == Head){
		Head = Head->Next;
	}
	Size--;
	if (!Size){
		Head = nullptr;
	}
	delete currNode;
	return res;
}

size_t lab::delist::size () const{
	return Size;
}

void lab::delist::insert (lab::dObj const &data, size_t index){
	if (index > Size){
		return;
	}
	if (Size == index){
		this->add(data);
		return;
	}
	lab::delist::Node *currNode = Head;
	for (size_t i = 0; i < index; i++){
		currNode = currNode->Next;
	}
	lab::delist::Node *newNode = new lab::delist::Node;
	newNode->Data = data;
	newNode->Next = currNode;
	newNode->Prev = currNode->Prev;
	currNode->Prev->Next = newNode;
	currNode->Prev = newNode;
	if (currNode == Head){
		Head = newNode;
	}
	Size++;
}

std::ostream &lab::delist::write (std::ostream &fout) const{
	lab::delist::Node *currNode = Head;
	for (size_t i = 0; i < Size; i++){
		currNode->Data.write(fout);
		fout << std::endl;
		currNode = currNode->Next;
	}
	return fout;
}

std::istream &lab::delist::read(std::istream &fin){
	lab::delist::Node *currNode = Head;
	for (size_t i = 0; i < Size; i++){
		lab::delist::Node *nextNode = currNode->Next;
		delete currNode;
		currNode = nextNode;
	}
	Head = nullptr;
	Size = 0;

	dObj temp;
	while (temp.read(fin)){
		this->add(temp);
	}
	return fin;
}

lab::dObj lab::delist::get (size_t index) const{
	lab::delist::Node *currNode = Head;
	for (size_t i = 0; i < index; i++){
		currNode = currNode->Next;
	}
	return currNode->Data;
}

lab::dObj &lab::delist::get (size_t index){
	lab::delist::Node *currNode = Head;
	for (size_t i = 0; i < index; i++){
		currNode = currNode->Next;
	}
	return currNode->Data;
}

template <class T>
lab::delist lab::delist::find (lab::dObj const &exmpl, T cmp) const{
	lab::delist newDelist;
	lab::delist::Node *currNode = Head;
	for (size_t i = 0; i < Size; i++){
		if (cmp(currNode->Data, exmpl)){
			newDelist.add(currNode->Data);
		}
		currNode = currNode->Next;
	}
	return newDelist;
}

lab::delist lab::delist::find (lab::dObj const &exmpl) const{
	return this->find(exmpl, [](dObj const &a, dObj const &b){return true;});
}

template <class T>
lab::delist lab::delist::remLike (lab::dObj const &exmpl, T cmp){
	lab::delist newDelist;
	lab::delist::Node *currNode = Head;
	for (size_t i = 0; i < Size; i++){
		if (cmp(currNode->Data, exmpl)){
			newDelist.add(currNode->Data);
			currNode->Prev->Next = currNode->Next;
			currNode->Next->Prev = currNode->Prev;
			if (currNode == Head){
				Head = Head->Next;
			}
			lab::delist::Node *tempNode = currNode->Next;
			delete currNode;
			currNode = tempNode;
		}
		else{
			currNode = currNode->Next;
		}
	}
	Size -= newDelist.size();
	if (!Size){
		Head = nullptr;
	}
	return newDelist;
}

lab::delist lab::delist::remLike (lab::dObj const &exmpl){
	auto func = [](dObj const &a, dObj const &b){return a == b;};
	return this->remLike(exmpl, func);
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

lab::dObj lab::delist::operator[] (size_t index) const{
	return this->get(index);
}

lab::dObj &lab::delist::operator[] (size_t index){
	return this->get(index);
}

lab::delist lab::operator+ (lab::delist cnt, lab::dObj const &data){
	cnt.add(data);
	return cnt;
}

lab::delist lab::operator+ (lab::dObj const &data, lab::delist cnt){
	cnt.add(data);
	return cnt;
}

lab::delist lab::operator- (lab::delist cnt, lab::dObj const &data){
	cnt.remLike(data);
	return cnt;
}

lab::delist lab::operator- (lab::dObj const &data, lab::delist cnt){
	cnt.remLike(data);
	return cnt;
}

std::ostream &lab::operator<< (std::ostream &fout, lab::delist const &cnt){
	return cnt.write(fout);
}

std::istream &lab::operator>> (std::istream &fin, lab::delist &cnt){
	return cnt.read(fin);
}
