#ifndef H_EXCEPT
#define H_EXCEPT
#include <exception>

struct ListException : std::exception{};

struct ListOORE : ListException{
	char const *what () const noexcept{
		return "List out of range exception";
	}
};

struct ListRFELE : ListException{
	char const *what () const noexcept{
		return "Remove from empty list exception";
	}
};


#endif
