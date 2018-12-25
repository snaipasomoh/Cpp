#ifndef CPP_LAB1_BUYER
#define CPP_LAB1_BUYER
#include <cstring>
#include <string>
#include <fstream>
#include <iostream>

namespace Lab1NS{
	class Buyer{
		char *_SecondName;
		char *_Name;
		char *_City;
		char *_Street;
		unsigned _House;
		unsigned _Flat;
		char *_AccountID;
		long _AvgAmount;
	public:
		Buyer ();
		explicit Buyer (char const *SecondName, char const *Name,
						char const *City, char const *Street,
						unsigned House, unsigned Flat,
						char const *AccountID, long AvgAmount);
		Buyer (Buyer const &B);
		Buyer &operator= (Buyer const &B);
		~Buyer ();

		char const *getSecondName () const;
		char const *getName () const;
		char const *getCity () const;
		char const *getStreet () const;
		unsigned getHouse () const;
		unsigned getFlat () const;
		char const *getAccountID () const;
		long getAvgAmount () const;

		void setSecondName (char const *SecondName);
		void setName (char const *Name);
		void setCity (char const *City);
		void setStreet (char const *Street);
		void setHouse (unsigned House);
		void setFlat (unsigned Flat);
		void setAccountID (char const *AccountID);
		void setAvgAmount (long AvgAmount);
	};

	bool operator== (Lab1NS::Buyer const &a, Lab1NS::Buyer const &b);
	bool operator> (Lab1NS::Buyer const &a, Lab1NS::Buyer const &b);
	bool operator< (Lab1NS::Buyer const &a, Lab1NS::Buyer const &b);
	bool operator<= (Lab1NS::Buyer const &a, Lab1NS::Buyer const &b);
	bool operator>= (Lab1NS::Buyer const &a, Lab1NS::Buyer const &b);
	std::istream &operator>> (std::istream &fin, Lab1NS::Buyer &a);
	std::ostream &operator<< (std::ostream &fout, Lab1NS::Buyer const &a);
}

#endif
