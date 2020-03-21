#ifndef H_STATE
#define H_STATE
#include <cstddef>
#include <cstring>
#include <string>
#include <iostream>

namespace lab{
	class State{
		char *name;
		char *capital;
		char *language;
		size_t population;
		size_t area;

	public:
		explicit State ();
		State (State const &other);
		State &operator= (State const &other);
		~State ();

		char *getName () const;
		char *getCapital () const;
		char *getLanguage () const;
		size_t getPopulation () const;
		size_t getArea () const;

		void setName (char const *newName);
		void setCapital (char const *newCapital);
		void setLanguage (char const *newLanguage);
		void setPopulation (size_t newPopulation);
		void setArea (size_t newArea);

		std::ostream &write (std::ostream &fout) const;
		std::istream &read (std::istream &fin);

		bool operator< (State const &other) const;
		bool operator> (State const &other) const;
		bool operator== (State const &other) const;
		bool operator!= (State const &other) const;
		bool operator<= (State const &other) const;
		bool operator>= (State const &other) const;
	};

	class Node{
		Node *next = nullptr;
	public:
		virtual ~Node () = 0;
	};

	class NodeData : State, Node{
	};
}

#endif
