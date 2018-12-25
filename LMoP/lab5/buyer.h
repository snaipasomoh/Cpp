#ifndef CPP_LAB1_BUYER
#define CPP_LAB1_BUYER
#include <string>
#include <iostream>

namespace Lab1NS{
	class Buyer{
		std::string _SecondName;
		std::string _Name;
		std::string _City;
		std::string _Street;
		unsigned _House;
		unsigned _Flat;
		std::string _AccountID;
		long _AvgAmount;
	public:
		Buyer ();
		explicit Buyer (std::string const &SecondName, std::string const &Name,
						std::string const &City, std::string const &Street,
						unsigned House, unsigned Flat,
						std::string const &AccountID, long AvgAmount);
		Buyer (Buyer const &B);
		Buyer &operator= (Buyer const &B);
		~Buyer ();

		std::string getSecondName () const;
		std::string getName () const;
		std::string getCity () const;
		std::string getStreet () const;
		unsigned getHouse () const;
		unsigned getFlat () const;
		std::string getAccountID () const;
		long getAvgAmount () const;

		void setSecondName (std::string const &SecondName);
		void setName (std::string const &Name);
		void setCity (std::string const &City);
		void setStreet (std::string const &Street);
		void setHouse (unsigned House);
		void setFlat (unsigned Flat);
		void setAccountID (std::string const &AccountID);
		void setAvgAmount (long AvgAmount);
	};

	bool operator== (Lab1NS::Buyer const &a, Lab1NS::Buyer const &b);
	bool operator!= (Lab1NS::Buyer const &a, Lab1NS::Buyer const &b);
	bool operator> (Lab1NS::Buyer const &a, Lab1NS::Buyer const &b);
	bool operator< (Lab1NS::Buyer const &a, Lab1NS::Buyer const &b);
	bool operator<= (Lab1NS::Buyer const &a, Lab1NS::Buyer const &b);
	bool operator>= (Lab1NS::Buyer const &a, Lab1NS::Buyer const &b);
	std::istream &operator>> (std::istream &fin, Lab1NS::Buyer &a);
	std::ostream &operator<< (std::ostream &fout, Lab1NS::Buyer const &a);
}

#endif
