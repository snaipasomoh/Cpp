#ifndef LAB_DOBJ_H
#define LAB_DOBJ_H
#include <iostream>
#include <set>
#include <string>
#include <cstring>

namespace lab{
	class dObj{
		char *Name = nullptr;
		std::set<std::string> Sports;
		int Year = 0;
		size_t Capacity = 0;
		size_t Areas = 0;

	public:
		explicit dObj (){ Name = strcpy(new char [4], "def"); }
		explicit dObj (char const *name, std::set<std::string> const &sports,
					   int year, size_t capacity, size_t areas);
		dObj (dObj const &other);
		dObj &operator= (dObj const &other);
		~dObj ();

		char const *getName () const;
		std::set<std::string> getSports () const;
		int getYear () const;
		size_t getCapacity () const;
		size_t getAreas () const;

		void setName (char const *name);
		void setSports (std::set<std::string> const &sports);
		void setYear (int year);
		void setCapacity (size_t capacity);
		void setAreas (size_t areas);

		std::ostream &write (std::ostream &fout) const;
		std::istream &read (std::istream &fin);

		bool operator< (dObj other) const;
		bool operator> (dObj other) const;
		bool operator== (dObj other) const;
		bool operator!= (dObj other) const;
		bool operator<= (dObj other) const;
		bool operator>= (dObj other) const;
	};

	std::ostream &operator<< (std::ostream &fout, dObj const &obj);
	std::istream &operator>> (std::istream &fin, dObj &obj);
}

#endif
