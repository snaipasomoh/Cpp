#ifndef LAB_DELIST_H
#define LAB_DELIST_H
#include "dataObj.h"
#include <iostream>

namespace lab{
	class delist{
		struct Node{
			dObj Data;
			Node *Next = nullptr;
			Node *Prev = nullptr;
		};

		Node *Head = nullptr;
		size_t Size = 0;
	public:
		explicit delist (){}
		delist (delist const &other);
		delist &operator= (delist const &other);
		~delist ();

		void add (dObj const &data);
		dObj rem (size_t index);
		size_t size () const;

		void insert (dObj const &data, size_t index);
		std::ostream &write (std::ostream &fout) const;
		std::istream &read(std::istream &fin);

		dObj get (size_t index) const;
		dObj &get (size_t index);

		template <class T>
		delist find (dObj const &exmpl, T cmp) const;
		delist find (dObj const &exmpl) const;

		template <class T>
		delist remLike (dObj const &exmpl, T cmp);
		delist remLike (dObj const &exmpl);

		dObj operator[] (size_t index) const;
		dObj &operator[] (size_t index);
	};

	delist operator+ (delist cnt, dObj const &data);
	delist operator+ (dObj const &data, delist cnt);

	delist operator- (delist cnt, dObj const &data);
	delist operator- (dObj const &data, delist cnt);

	std::ostream &operator<< (std::ostream &fout, delist const &cnt);
	std::istream &operator>> (std::istream &fin, delist &cnt);
}

#endif
