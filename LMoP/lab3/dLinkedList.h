#ifndef CPP_LAB3_LIST
#define CPP_LAB3_LIST
#include <iostream>
#include "exceptions.h"

namespace Lab1NS{
	template <class T>
	class dLList{
	protected:
		struct dLListNode{
			T data;
			dLListNode *prev = NULL;
			dLListNode *next = NULL;
		};

		dLListNode *_top = nullptr;
		size_t _size = 0;

	public:
		explicit dLList ()
			: _top(), _size(){}

		dLList (dLList const &other){
			dLListNode *currNode = other._top;
			while (currNode && currNode->prev){
				currNode = currNode->prev;
			}
			while (currNode){
				this->insInEnd(currNode->data);
				currNode = currNode->next;
			}
		}

		dLList &operator= (dLList const &other){
			if (this != &other){
				dLList *tempStack = new dLList(other);
				size_t tSize = tempStack->_size;
				dLListNode *tTop = tempStack->_top;
				tempStack->_size = _size;
				tempStack->_top = _top;
				_size = tSize;
				_top = tTop;
			}
			return *this;
		}

		~dLList (){
			while (!this->empty()){
				this->remFromEnd();
			}
		}

		void insInEnd (T const &obj){
			dLListNode *newNode = new dLListNode;
			newNode->data = obj;
			if (!this->_size){
				_top = newNode;
			}
			else{
				_top->next = newNode;
				newNode->prev = _top;
				_top = newNode;
			}
			_size++;
		}

		T remFromEnd (){
			if (_size){
				T temp = _top->data;
				dLListNode *tTop = _top->prev;
				delete _top;
				_top = tTop;
				if (_top){
					_top->next = NULL;
				}
				_size--;
				return temp;
			}
			throw dLListRemException();
		}

		size_t size () const{
			return _size;
		}

		bool empty () const{
			return !_size;
		}

		void insert (size_t i, T &obj){
			if (i >= _size){
				this->insInEnd(obj);
			}
			else {
				dLListNode *newNode = new dLListNode;
				newNode->data = obj;
				dLListNode *currNode = _top;
				for (size_t j = 0; j < _size - i - 1; j++){
					currNode = currNode->prev;
				}
				if (currNode->prev){
					currNode->prev->next = newNode;
					newNode->prev = currNode->prev;
				}
				currNode->prev = newNode;
				newNode->next = currNode;
			}
			_size++;
		}

		void remove (size_t i){
			if (i == _size - 1){
				this->remFromEnd();
			}
			else if (i < _size - 1){
				dLListNode *currNode = _top;
				for (size_t j = 0; j < _size - i - 1; j++){
					currNode = currNode->prev;
				}
				if (currNode->prev){
					currNode->prev->next = currNode->next;
				}
				currNode->next->prev = currNode->prev;
				delete currNode;
				_size--;
			}
		}

		T operator[] (long i) const {
			if (i < 0){
				i += _size;
			}
			if (i < (long)_size && i >= 0){
				dLListNode *currNode = _top;
				for (size_t j = 0; j < _size - i -1; j++){
					currNode = currNode->prev;
				}
				return currNode->data;
			}
			throw dLListOutOfRangeException();
		}

		T &operator[] (long i) {
			if (i < 0){
				i += _size;
			}
			if (i < (long)_size && i >= 0){
				dLListNode *currNode = _top;
				for (size_t j = 0; j < _size - i -1; j++){
					currNode = currNode->prev;
				}
				return currNode->data;
			}
			throw dLListOutOfRangeException();
		}

		void removeSuitable (T const &obj){
			dLListNode *currNode = _top;
			while (currNode && currNode->data == obj){
				this->remFromEnd();
				currNode = _top;
			}
			while (currNode){
				if (currNode->data == obj){
					dLListNode *tempNode = currNode->prev;
					if (currNode->prev){
						currNode->prev->next = currNode->next;
					}
					if (currNode->next){
						currNode->next->prev = currNode->prev;
					}
					delete currNode;
					_size--;
					currNode = tempNode;
				}
				else{
					currNode = currNode->prev;
				}
			}
		}

		template <class Compare>
		void removeSuitable (T const &obj, Compare comp){
			dLListNode *currNode = _top;
			while (currNode && comp(currNode->data, obj)){
				this->remFromEnd();
				currNode = _top;
			}
			while (currNode){
				if (comp(currNode->data, obj)){
					dLListNode *tempNode = currNode->prev;
					if (currNode->prev){
						currNode->prev->next = currNode->next;
					}
					if (currNode->next){
						currNode->next->prev = currNode->prev;
					}
					delete currNode;
					_size--;
					currNode = tempNode;
				}
				else{
					currNode = currNode->prev;
				}
			}
		}

		dLList<T> &find (T const &obj){
			dLList<T> newStack;
			dLListNode *currNode = _top;
			while (currNode && currNode->prev){
				currNode = currNode->prev;
			}
			while (currNode->next){
				if (currNode->data == obj){
					newStack.insInEnd(currNode->data);
				}
				currNode = currNode->next;
			}
			return newStack;
		}

		template <class Compare>
		dLList<T> &find (T const &obj, Compare comp){
			dLList<T> newStack;
			dLListNode *currNode = _top;
			while (currNode && currNode->prev){
				currNode = currNode->prev;
			}
			while (currNode->next){
				if (comp(currNode->data, obj)){
					newStack.insInEnd(currNode->data);
				}
				currNode = currNode->next;
			}
			return newStack;
		}

		template <class L>
		friend std::istream &operator>> (std::istream &fin,
										 Lab1NS::dLList<L> &obj);

		template <class L>
		friend std::ostream &operator<< (std::ostream &fout,
										 Lab1NS::dLList<L> const &obj);
	};

/*

 #######  ##     ## ######## ########  ##        #######     ###    ########  #### ##    ##  ######
##     ## ##     ## ##       ##     ## ##       ##     ##   ## ##   ##     ##  ##  ###   ## ##    ##
##     ## ##     ## ##       ##     ## ##       ##     ##  ##   ##  ##     ##  ##  ####  ## ##
##     ## ##     ## ######   ########  ##       ##     ## ##     ## ##     ##  ##  ## ## ## ##   ####
##     ##  ##   ##  ##       ##   ##   ##       ##     ## ######### ##     ##  ##  ##  #### ##    ##
##     ##   ## ##   ##       ##    ##  ##       ##     ## ##     ## ##     ##  ##  ##   ### ##    ##
 #######     ###    ######## ##     ## ########  #######  ##     ## ########  #### ##    ##  ######

*/

	template <class L>
	std::istream &operator>> (std::istream &fin, dLList<L> &obj){
		while (!obj.empty()){
			obj.remFromEnd();
		}
		L tempL;
		while (fin >> tempL){
			obj.insInEnd(tempL);
		}
		return fin;
	}

	template <class L>
	std::ostream &operator<< (std::ostream &fout, dLList<L> const &obj){
		auto currNode = obj._top;
		if (!currNode){
			return fout;
		}
		while (currNode->prev){
			currNode = currNode->prev;
		}
		while (currNode){
			fout << currNode->data << std::endl;
			currNode = currNode->next;
		}
		return fout;
	}

	template <class T>
	Lab1NS::dLList<T> operator+ (Lab1NS::dLList<T> stack, T const &obj){
		stack.insInEnd(obj);
		return stack;
	}

	template <class T>
	Lab1NS::dLList<T> operator+ (T const &obj, Lab1NS::dLList<T> stack){
		stack.insInEnd(obj);
		return stack;
	}

	template <class T>
	Lab1NS::dLList<T> operator- (Lab1NS::dLList<T> stack, T const &obj){
		stack.removeSuitable(obj);
		return stack;
	}

	template <class T>
	Lab1NS::dLList<T> operator- (T const &obj, Lab1NS::dLList<T> stack){
		stack.removeSuitable(obj);
		return stack;
	}
}
#endif
