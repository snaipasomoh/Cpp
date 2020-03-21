#ifndef H_STACK
#define H_STACK
#include "state.hpp"
#include <exception>

namespace lab{
	template <class T, size_t MaxSize = 16>
	class Stack{
	protected:
		struct Node{
			T data;
			Node *next = nullptr;
		};

		Node *head;
		size_t size;

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

		explicit Stack () :
			head(nullptr), size(0) {}

		Stack (Stack const &other){
			head = nullptr;
			size = 0;
			for (size_t i = 0; i < other.size; i++){
				add(other.get(i));
			}
		}

		Stack &operator= (Stack const &other){
			if (this != &other){
				if (head != nullptr){
					Node *currNode = head;
					Node *nextNode;
					while ((nextNode = currNode->next) != nullptr){
						delete currNode;
						currNode = nextNode;
					}
					delete currNode;
				}

				Stack tempStack(other);
				head = tempStack.head;
				tempStack.head = nullptr;
				size = tempStack.size;
				tempStack.size = 0;
			}
			return *this;
		}

		~Stack (){
			if (!size){
				return;
			}
			Node *currNode = head;
			Node *nextNode;
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

		void add (T const &data){
			insert(data, size);
		}

		void insert (T const &data, int index){
			if (size >= MaxSize){
				return;
			}
			if (index < 0){
				index += size;
			}
			if (index < 0 || (size_t)index > size){
				throw("List out of range exception");
			}
			if ((size_t)index == size){
				Node *newNode = new Node;
				newNode->data = data;
				newNode->next = head;
				head = newNode;
				size++;
				return;
			}
			Node *prevNode = head;
			Node *currNode = prevNode->next;
			for (size_t i = size - 1; i > (size_t)index; i--){
				prevNode = currNode;
				currNode = prevNode->next;
			}
			Node *newNode = new Node;
			newNode->data = data;
			newNode->next = currNode;
			prevNode->next = newNode;
			size++;
		}

		void remove (int index){
			if (size == 0){
				throw("Remove from empty stack exception");
			}
			if (index < 0){
				index += size;
			}
			if (index < 0 || (size_t)index >= size){
				throw("Stack out of range exception");
			}
			Node *currNode = head;
			if ((size_t)index + 1 == size){
				head = head->next;
				delete currNode;
				size--;
				return;
			}
			currNode = head;
			Node *prevNode;
			for (size_t i = size - 1; i > (size_t)index; i--){
				prevNode = currNode;
				currNode = prevNode->next;
			}
			prevNode->next = currNode->next;
			delete currNode;
			size--;
		}

		T &get (int index){
			if (index < 0){
				index += size;
			}
			if (index < 0 || (size_t)index >= size){
				throw("Stack out of range exception");
			}
			if ((size_t)index + 1 == size){
				return head->data;
			}
			Node *currNode = head;
			for (size_t i = size - 1; i > (size_t)index; i--){
				currNode = currNode->next;
			}
			return currNode->data;
		}

		T get (int index) const{
			if (index < 0){
				index += size;
			}
			if (index < 0 || (size_t)index >= size){
				throw("Stack out of range exception");
			}
			if ((size_t)index + 1 == size){
				return head->data;
			}
			Node *currNode = head;
			for (size_t i = size - 1; i > (size_t)index; i--){
				currNode = currNode->next;
			}
			return currNode->data;
		}

		std::ostream &write (std::ostream &fout) const{
			for (size_t i = 0; i < size; i++){
				get(i).write(fout);
			}
			return fout;
		}

		std::istream &read (std::istream &fin){
			Node *currNode = head;
			Node *nextNode;
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

		size_t getSize () const{
			return size;
		}

		template <class L>
		Stack find (T const &exmpl, L cmp) const{
			Stack ts1;
			for (size_t i = 0; i < size; i++){
				if (cmp(exmpl, get(i))){
					ts1.add(get(i));
				}
			}
			return ts1;
		}
		Stack find (T const &exmpl) const{
			return find(exmpl, [](T const &a, T const &b)
				{return !strcmp(a.getName(), b.getName());});
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

		Stack operator+ (T const &data){
			Stack res(*this);
			res.add(data);
			return res;
		}

		Stack operator- (T const &data){
			Stack res;
			for (size_t i = 0; i < getSize(); i++){
				if (get(i) == data){
					continue;
				}
				res.add(get(i));
			}
			return res;
		}

		T operator[] (int index) const{
			return get(index);
		}

		T &operator[] (int index){
			return get(index);
		}


	};

	template<class L, size_t mSize>
	Stack<L, mSize> operator+ (L const &data, Stack<L, mSize> &st){
		return st + data;
	}

	template<class L, size_t mSize>
	Stack<L, mSize> operator- (L const &data, Stack<L, mSize> &st){
		return st - data;
	}

	template<class L, size_t mSize>
	std::ostream &operator<< (std::ostream &fout, Stack<L, mSize> const &cnt){
		return cnt.write(fout);
	}

	template<class L, size_t mSize>
	std::istream &operator>> (std::istream &fin, Stack<L, mSize> &cnt){
		return cnt.read(fin);
	}
}

#endif
