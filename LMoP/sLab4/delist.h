#ifndef LAB_DELIST_H
#define LAB_DELIST_H
#include "dataObj.h"
#include <iostream>
#include <stdexcept>

namespace lab{
	template <class T, size_t MaxSize>
	class delist{
		struct Node{
			T Data;
			Node *Next = nullptr;
			Node *Prev = nullptr;
		};

		Node *Head = nullptr;
		size_t Size = 0;

	public:

/*

 ######  ########  ########  ######  ####    ###    ##
##    ## ##     ## ##       ##    ##  ##    ## ##   ##
##       ##     ## ##       ##        ##   ##   ##  ##
 ######  ########  ######   ##        ##  ##     ## ##
      ## ##        ##       ##        ##  ######### ##
##    ## ##        ##       ##    ##  ##  ##     ## ##
 ######  ##        ########  ######  #### ##     ## ########

*/

		explicit delist (){}

		delist (delist const &other){
			Node *currNode = other.Head;
			for (size_t i = 0; i < other.Size; i++){
				this->add(currNode->Data);
				currNode = currNode->Next;
			}
		}

		delist &operator= (delist const &other){
			if (this != &other){
				Node *currNode = Head;
				for (size_t i = 0; i < Size; i++){
					Node *nextNode = currNode->Next;
					delete currNode;
					currNode = nextNode;
				}
				delist tempDelist(other);
				Head = tempDelist.Head;
				tempDelist.Head = nullptr;
				Size = tempDelist.Size;
				tempDelist.Size = 0;
			}
			return *this;
		}

		~delist (){
			Node *currNode = Head;
			for (size_t i = 0; i < Size; i++){
				Node *nextNode = currNode->Next;
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

		void add (T const &data){
			if (Size >= MaxSize){
				return;
			}
			Node *newNode = new Node;
			newNode->Data = data;
			newNode->Next = nullptr;													//newNode->Next = Head if circ list
			newNode->Prev = nullptr;
			if (!Size){
				Head = newNode;
				Size++;
				return;
			}
			Node *currNode = Head;
			for (size_t i = 0; i < Size - 1; i++){
				currNode = currNode->Next;
			}
			currNode->Next = newNode;
			newNode->Prev = currNode;
			Size++;
		}

		void ordadd (T const &data){
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

		T rem (int index){
			if (this->size() == 0){
				throw(std::logic_error("rem from empty delist"));
			}
			if (index < 0){
				index += this->size();
			}
			if (index < 0 || index >= (int)this->size()){
				throw(std::out_of_range("rem out of range"));
			}
			Node *currNode = Head;
			for (int i = 0; i < index; i++){
				currNode = currNode->Next;
			}
			T res = currNode->Data;
			if (currNode->Prev){
				currNode->Prev->Next = currNode->Next;
			}
			else{
				Head = currNode->Next;
			}
			if (currNode->Next){
				currNode->Next->Prev = currNode->Prev;
			}
			Size--;
			delete currNode;
			return res;
		}

		size_t size () const{
			return Size;
		}

		void insert (T const &data, int index){
			if (Size >= MaxSize){
				return;
			}
			if (index < 0){
				index += this->size();
			}
			if (index < 0 || index > (int)this->size()){
				throw(std::out_of_range("insert out of range"));
			}
			if ((int)Size == index){
				this->add(data);
				return;
			}
			Node *currNode = Head;
			for (int i = 0; i < index; i++){
				currNode = currNode->Next;
			}
			Node *newNode = new Node;
			newNode->Data = data;
			newNode->Next = currNode;
			newNode->Prev = currNode->Prev;
			if (currNode->Prev){
				currNode->Prev->Next = newNode;
			}
			else{
				Head = newNode;
			}
			currNode->Prev = newNode;
			Size++;
		}

		std::ostream &write (std::ostream &fout) const{
			Node *currNode = Head;
			for (size_t i = 0; i < Size; i++){
				fout << currNode->Data;
				fout << std::endl;
				currNode = currNode->Next;
			}
			return fout;
		}

		std::istream &read(std::istream &fin){
			Node *currNode = Head;
			for (size_t i = 0; i < Size; i++){
				Node *nextNode = currNode->Next;
				delete currNode;
				currNode = nextNode;
			}
			Head = nullptr;
			Size = 0;

			T temp;
			while (!fin.eof()){
				try{
					fin >> temp;
				}
				catch (std::exception const &e){
					throw(e);
				}
				this->add(temp);
			}
			return fin;
		}

		T get (int index) const{
			if (index < 0){
				index += this->size();
			}
			if (index < 0 || index >= (int)this->size()){
				throw(std::out_of_range("get out of range"));
			}
			Node *currNode = Head;
			for (int i = 0; i < index; i++){
				currNode = currNode->Next;
			}
			return currNode->Data;
		}

		T &get (int index){
			if (index < 0){
				index += this->size();
			}
			if (index < 0 || index >= (int)this->size()){
				throw(std::out_of_range("get out of range"));
			}
			Node *currNode = Head;
			for (int i = 0; i < index; i++){
				currNode = currNode->Next;
			}
			return currNode->Data;
		}

		template <class L>
		delist find (T const &exmpl, L cmp) const{
			delist newDelist;
			Node *currNode = Head;
			for (size_t i = 0; i < Size; i++){
				if (cmp(currNode->Data, exmpl)){
					newDelist.add(currNode->Data);
				}
				currNode = currNode->Next;
			}
			return newDelist;
		}

		delist find (T const &exmpl) const{
			return this->find(exmpl, [](T const &a, T const &b){return true;});
		}

		template <class L>
		delist remLike (T const &exmpl, L cmp){
			delist newDelist;
			Node *currNode = Head;
			for (size_t i = 0; i < Size; i++){
				if (cmp(currNode->Data, exmpl)){
					newDelist.add(currNode->Data);
					if (currNode->Prev){
						currNode->Prev->Next = currNode->Next;
					}
					else{
						Head = currNode->Next;
					}
					if (currNode->Next){
						currNode->Next->Prev = currNode->Prev;
					}
					Node *tempNode = currNode->Next;
					delete currNode;
					currNode = tempNode;
				}
				else{
					currNode = currNode->Next;
				}
			}
			Size -= newDelist.size();
			return newDelist;
		}

		delist remLike (T const &exmpl){
			return this->remLike(exmpl, [](T const &a, T const &b){return true;});
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

		T operator[] (size_t index) const{
			return this->get(index);
		}

		T &operator[] (size_t index){
			return this->get(index);
		}
	};

	template <class T, size_t MaxSize>
	delist<T, MaxSize> operator+ (delist<T, MaxSize> cnt, T const &data){
		cnt.add(data);
		return cnt;
	}

	template <class T, size_t MaxSize>
	delist<T, MaxSize> operator+ (T const &data, delist<T, MaxSize> cnt){
		cnt.add(data);
		return cnt;
	}

	template <class T, size_t MaxSize>
	delist<T, MaxSize> operator- (delist<T, MaxSize> cnt, T const &data){
		cnt.remLike(data);
		return cnt;
	}

	template <class T, size_t MaxSize>
	delist<T, MaxSize> operator- (T const &data, delist<T, MaxSize> cnt){
		cnt.remLike(data);
		return cnt;
	}

	template <class T, size_t MaxSize>
	std::ostream &operator<< (std::ostream &fout, delist<T, MaxSize> const &cnt){
		return cnt.write(fout);
	}

	template <class T, size_t MaxSize>
	std::istream &operator>> (std::istream &fin, delist<T, MaxSize> &cnt){
		return cnt.read(fin);
	}
}

#endif
