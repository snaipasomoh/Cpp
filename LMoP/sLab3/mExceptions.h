#ifndef LAB_MEXCEPTIONS_H
#define LAB_MEXCEPTIONS_H
#include <exception>

struct delistOORE : std::exception{
	char const *what () const noexcept{
		return "delist out of range";
	}
};

struct delistRFELE : std::exception{
	char const *what () const noexcept{
		return "rem from empty list";
	}
};

#endif
