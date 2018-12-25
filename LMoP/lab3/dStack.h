#ifndef CPP_LAB3_STACK
#define CPP_LAB3_STACK
#include "dLinkedList.h"

namespace Lab1NS{
	template<class T>
	class dStack : public Lab1NS::dLList<T>{
	public:
		explicit dStack () :
			Lab1NS::dLList<T>(){}

		dStack (dLList<T> const &other) :
			Lab1NS::dLList<T>(other){}

		dStack &operator= (dLList<T> const &other){
			if (this != &other){
				dStack *tempStack = new dStack(other);
				size_t tSize = tempStack->_size;
				typename Lab1NS::dLList<T>::dLListNode *tTop = tempStack->_top;
				// auto tTop = tempStack->_top;
				tempStack->_size = this->_size;
				tempStack->_top = this->_top;
				this->_size = tSize;
				this->_top = tTop;
			}
			return *this;
		}

		void push (T const &obj){
			this->insInEnd(obj);
		}

		T pop (){
			return this->remFromEnd();
		}
	};
}

#endif
