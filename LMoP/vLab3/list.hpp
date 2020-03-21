#ifndef H_List
#define H_List
#include "state.hpp"
#include "except.hpp"

namespace lab{
	class List{
	protected:
		struct Node{
			State data;
			Node *next = nullptr;
		};

		Node *head;
		size_t size;

	public:
		explicit List ();
		List (List const &other);
		List &operator= (List const &other);
		~List ();

		void add (State const &data);
		void insert (State const &data, int index);
		void remove (int index);
		State &get (int index);
		State get (int index) const;
		std::ostream &write (std::ostream &fout) const;
		std::istream &read (std::istream &fin);
		size_t getSize () const;
		template <class T>
		List find (State const &exmpl, T cmp) const{
			List ts1;
			for (size_t i = 0; i < size; i++){
				if (cmp(exmpl, get(i))){
					ts1.add(get(i));
				}
			}
			return ts1;
		}
		List find (State const &exmpl) const{
			return find(exmpl, [](State const &a, State const &b)
				{return !strcmp(a.getName(), b.getName());});
		}

		List operator+ (State const &data);
		List operator- (State const &data);

		friend List operator+ (State const &data, List &st);
		friend List operator- (State const &data, List &st);

		State operator[] (int index) const;
		State &operator[] (int index);

	};

	List operator+ (State const &data, List &st);
	List operator- (State const &data, List &st);
	std::ostream &operator<< (std::ostream &fout, List const &cnt);
	std::istream &operator>> (std::istream &fin, List &cnt);
}

#endif
