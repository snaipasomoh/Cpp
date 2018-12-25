#ifndef CPP_LAB3_EXCEPTIONS
#define CPP_LAB3_EXCEPTIONS
#include <exception>

struct dLListOutOfRangeException : std::exception{
	char const *what () const noexcept{
		return "dLList out of range";
	}
};

struct dLListRemException : std::exception{
	char const *what () const noexcept{
		return "remove from empty dLList";
	}
};

#endif
