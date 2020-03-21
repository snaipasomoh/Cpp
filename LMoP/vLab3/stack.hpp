#ifndef H_STACK
#define H_STACK
#include "state.hpp"
#include "list.hpp"

namespace lab{
	class Stack : public List{
	public:
		Stack (){};
		Stack (List const &other);
		void push (State const &data);
		State pop ();

	protected:
		using List::add;
		using List::insert;
		using List::remove;
	};
}

#endif
