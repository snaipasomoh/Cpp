#ifndef H_STACK
#define H_STACK
#include "state.hpp"

namespace lab{
	class Stack{
		struct Node{
			State data;
			Node *next = nullptr;
		};

		Node *head;
		size_t size;

	public:
		explicit Stack ();
		Stack (Stack const &other);
		Stack &operator= (Stack const &other);
		~Stack ();

		void add (State const &data);
		void insert (State const &data, size_t index);
		void remove (size_t index);
		State &get (size_t index);
		State get (size_t index) const;
		std::ostream &write (std::ostream &fout) const;
		std::istream &read (std::istream &fin);
		size_t getSize () const;
		template <class T>
		Stack find (State const &exmpl, T cmp) const{
			Stack ts1;
			for (size_t i = 0; i < size; i++){
				if (cmp(exmpl, get(i))){
					ts1.add(get(i));
				}
			}
			return ts1;
		}
		Stack find (State const &exmpl) const{
			return find(exmpl, [](State const &a, State const &b)
				{return !strcmp(a.getName(), b.getName());});
		}

	};
}

#endif
