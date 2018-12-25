#ifndef DESTACK_H
#define DESTACK_H
#include <list>
#include <iostream>
#include <functional>

template<
	class T,
	class Allocator = std::allocator<T>>
class Destack : public std::list<T, Allocator>{
public:
	explicit Destack (Allocator const &alloc = Allocator()) :
		std::list<T, Allocator>(alloc){}

	explicit Destack (size_t count, T const &value = T(),
	 				  Allocator const &alloc = Allocator()) :
		std::list<T, Allocator>(count, value, alloc){}

	explicit Destack(size_t count) :
		std::list<T, Allocator>(count){}

	template <class InputIt>
	Destack (InputIt first, InputIt last,
		 	 Allocator const &alloc = Allocator()) :
		std::list<T, Allocator>(first, last, alloc){}

	Destack (std::list<T, Allocator> const &other,
			 Allocator const &alloc = Allocator()) :
	 	std::list<T, Allocator>(other, alloc){}

	Destack (std::list<T, Allocator> &&other,
			 Allocator const &alloc = Allocator()) :
		std::list<T, Allocator>(other, alloc){}

	Destack (std::initializer_list<T> init,
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
	Destack find_if (Compare cmp) const{
		Destack temp(*this);
		temp.remove_if(std::not1(cmp));
		return temp;
	}
};

template<
    class T,
    class Allocator = std::allocator<T>>
std::ostream &operator<< (std::ostream &fout, Destack<T, Allocator> const &obj){
	for (auto &i : obj){
		fout << i << std::endl;
	}
	return fout;
}

template<
    class T,
    class Allocator = std::allocator<T>>
std::istream &operator>> (std::istream &fin, Destack<T, Allocator> &obj){
	obj.clear();
	T temp;
	while (fin >> temp){
		obj.push_back(temp);
	}
	return fin;
}

#endif
