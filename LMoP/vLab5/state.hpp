#ifndef H_STATE
#define H_STATE
#include <cstddef>
#include <cstring>
#include <string>
#include <iostream>

namespace lab{
	class State{
		std::string name;
		std::string capital;
		std::string language;
		size_t population;
		size_t area;

	public:
		explicit State ();
		State (State const &other);
		State &operator= (State const &other);
		~State (){};

		std::string getName () const;
		std::string getCapital () const;
		std::string getLanguage () const;
		size_t getPopulation () const;
		size_t getArea () const;

		void setName (std::string const &newName);
		void setCapital (std::string const &newCapital);
		void setLanguage (std::string const &newLanguage);
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

	std::ostream &operator<< (std::ostream &fout, State const &data);
	std::istream &operator>> (std::istream &fin, State &data);
}

#endif
