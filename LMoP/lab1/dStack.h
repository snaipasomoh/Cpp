#ifndef CPP_LAB1_STACK
#define CPP_LAB1_STACK
#include <iostream>

namespace Lab1NS{
	template <class T>
	class dStack{
		struct dStackNode{
			T data;
			dStackNode *prev = NULL;
			dStackNode *next = NULL;
		};

		dStackNode *_top = nullptr;
		size_t _size = 0;

	public:
		explicit dStack ()
			: _top(), _size(){}

		dStack (dStack const &other){
			dStackNode *currNode = other._top;
			while (currNode && currNode->prev){
				currNode = currNode->prev;
			}
			while (currNode){
				this->push(currNode->data);
				currNode = currNode->next;
			}
		}

		dStack &operator= (dStack const &other){
			if (this != &other){
				dStack *tempStack = new dStack(other);
				size_t tSize = tempStack->_size;
				dStackNode *tTop = tempStack->_top;
				tempStack->_size = _size;
				tempStack->_top = _top;
				_size = tSize;
				_top = tTop;
			}
			return *this;
		}

		~dStack (){
			while (!this->empty()){
				this->pop();
			}
		}

		void push (T const &obj){
			dStackNode *newNode = new dStackNode;
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

		T pop (){
			if (_size){
				T temp = _top->data;
				dStackNode *tTop = _top->prev;
				delete _top;
				_top = tTop;
				if (_top){
					_top->next = NULL;
				}
				_size--;
				return temp;
			}
			throw "Pop from empty stack\n";
		}

		size_t size () const{
			return _size;
		}

		bool empty () const{
			return !_size;
		}

		void insert (size_t i, T &obj){
			if (i >= _size){
				this->push(obj);
			}
			else {
				dStackNode *newNode = new dStackNode;
				newNode->data = obj;
				dStackNode *currNode = _top;
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
				this->pop();
			}
			else if (i < _size - 1){
				dStackNode *currNode = _top;
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

		T operator[] (size_t i) const {
			if (i < _size){
				dStackNode *currNode = _top;
				for (size_t j = 0; j < _size - i -1; j++){
					currNode = currNode->prev;
				}
				return currNode->data;
			}
			throw std::out_of_range("Out of size\n");
		}

		T &operator[] (size_t i) {
			if (i < _size){
				dStackNode *currNode = _top;
				for (size_t j = 0; j < _size - i -1; j++){
					currNode = currNode->prev;
				}
				return currNode->data;
			}
			throw std::out_of_range("Out of size\n");
		}

		void removeSuitable (T const &obj){
			dStackNode *currNode = _top;
			while (currNode && currNode->data == obj){
				this->pop();
				currNode = _top;
			}
			while (currNode){
				if (currNode->data == obj){
					dStackNode *tempNode = currNode->prev;
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
			dStackNode *currNode = _top;
			while (currNode && comp(currNode->data, obj)){
				this->pop();
				currNode = _top;
			}
			while (currNode){
				if (comp(currNode->data, obj)){
					dStackNode *tempNode = currNode->prev;
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

		dStack<T> &find (T const &obj){
			dStack<T> newStack;
			dStackNode *currNode = _top;
			while (currNode && currNode->prev){
				currNode = currNode->prev;
			}
			while (currNode->next){
				if (currNode->data == obj){
					newStack.push(currNode->data);
				}
				currNode = currNode->next;
			}
			return newStack;
		}

		template <class Compare>
		dStack<T> &find (T const &obj, Compare comp){
			dStack<T> newStack;
			dStackNode *currNode = _top;
			while (currNode && currNode->prev){
				currNode = currNode->prev;
			}
			while (currNode->next){
				if (comp(currNode->data, obj)){
					newStack.push(currNode->data);
				}
				currNode = currNode->next;
			}
			return newStack;
		}

		template <class L>
		friend std::istream &operator>> (std::istream &fin,
										 Lab1NS::dStack<L> &obj);

		template <class L>
		friend std::ostream &operator<< (std::ostream &fout,
										 Lab1NS::dStack<L> const &obj);
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
	std::istream &operator>> (std::istream &fin, dStack<L> &obj){
		while (!obj.empty()){
			obj.pop();
		}
		L tempL;
		while (fin >> tempL){
			obj.push(tempL);
		}
		return fin;
	}

	template <class L>
	std::ostream &operator<< (std::ostream &fout, dStack<L> const &obj){
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
	Lab1NS::dStack<T> operator+ (Lab1NS::dStack<T> stack, T const &obj){
		stack.push(obj);
		return stack;
	}

	template <class T>
	Lab1NS::dStack<T> operator+ (T const &obj, Lab1NS::dStack<T> stack){
		stack.push(obj);
		return stack;
	}

	template <class T>
	Lab1NS::dStack<T> operator- (Lab1NS::dStack<T> stack, T const &obj){
		stack.removeSuitable(obj);
		return stack;
	}

	template <class T>
	Lab1NS::dStack<T> operator- (T const &obj, Lab1NS::dStack<T> stack){
		stack.removeSuitable(obj);
		return stack;
	}
}
#endif
