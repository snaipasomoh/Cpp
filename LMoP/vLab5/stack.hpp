#ifndef H_STACK
#define H_STACK
#include <list>
#include <iostream>
#include <functional>

template<
	class T,
	class Allocator = std::allocator<T>>
class Stack : public std::list<T, Allocator>{
public:
	explicit Stack (Allocator const &alloc = Allocator()) :
		std::list<T, Allocator>(alloc){}

	explicit Stack (size_t count, T const &value = T(),
	                Allocator const &alloc = Allocator()) :
		std::list<T, Allocator>(count, value, alloc){}

	explicit Stack(size_t count) :
		std::list<T, Allocator>(count){}

	template <class InputIt>
	Stack (InputIt first, InputIt last,
	       Allocator const &alloc = Allocator()) :
		std::list<T, Allocator>(first, last, alloc){}

	Stack (std::list<T, Allocator> const &other,
	       Allocator const &alloc = Allocator()) :
		std::list<T, Allocator>(other, alloc){}

	Stack (std::list<T, Allocator> &&other,
	       Allocator const &alloc = Allocator()) :
		std::list<T, Allocator>(other, alloc){}

	Stack (std::initializer_list<T> init,
	       Allocator const &alloc = Allocator()) :
		std::list<T, Allocator>(init, alloc){}

	T operator[] (size_t i) const{
		auto it = this->begin();
		for (size_t j = 0; j < i; j++, it++);
		return *it;
	}

	T &operator[] (size_t i){
		auto it = this->begin();
		for (size_t j = 0; j < i; j++, it++);
		return *it;
	}

	template <class Compare>
	Stack find_if (Compare cmp) const{
		Stack temp(*this);
		temp.remove_if(std::not1(cmp));
		return temp;
	}
};

template<
	class T,
	class Allocator = std::allocator<T>>
std::ostream &operator<< (std::ostream &fout, Stack<T, Allocator> const &obj){
	for (auto &i : obj){
		fout << i << std::endl;
	}
	return fout;
}

template<
	class T,
	class Allocator = std::allocator<T>>
std::istream &operator>> (std::istream &fin, Stack<T, Allocator> &obj){
	obj.clear();
	T temp;
	while (fin >> temp){
		obj.push_back(temp);
	}
	return fin;
}

#endif
