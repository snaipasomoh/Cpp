#include "buyer.h"

/*

 ######  ########  ########  ######  ####    ###    ##
##    ## ##     ## ##       ##    ##  ##    ## ##   ##
##       ##     ## ##       ##        ##   ##   ##  ##
 ######  ########  ######   ##        ##  ##     ## ##
      ## ##        ##       ##        ##  ######### ##
##    ## ##        ##       ##    ##  ##  ##     ## ##
 ######  ##        ########  ######  #### ##     ## ########

*/

Lab1NS::Buyer::Buyer () :
	_SecondName(strcpy(new char [1], "")),
	_Name(strcpy(new char [1], "")),
	_City(strcpy(new char [1], "")),
	_Street(strcpy(new char [1], "")),
	_House(0),
	_Flat(0),
	_AccountID(strcpy(new char [1], "")),
	_AvgAmount(0){}

Lab1NS::Buyer::Buyer (char const *SecondName, char const *Name,
					char const *City, char const *Street,
					unsigned House, unsigned Flat,
					char const *AccountID, long AvgAmount) :
	_SecondName(strcpy(new char [strlen(SecondName) + 1], SecondName)),
	_Name(strcpy(new char [strlen(Name) + 1], Name)),
	_City(strcpy(new char [strlen(City) + 1], City)),
	_Street(strcpy(new char [strlen(Street) + 1], Street)),
	_House(House),
	_Flat(Flat),
	_AccountID(strcpy(new char [strlen(AccountID) + 1], AccountID)),
	_AvgAmount(AvgAmount){}

Lab1NS::Buyer::Buyer (Buyer const &B) :
	_SecondName(strcpy(new char [strlen(B._SecondName) + 1], B._SecondName)),
	_Name(strcpy(new char [strlen(B._Name) + 1], B._Name)),
	_City(strcpy(new char [strlen(B._City) + 1], B._City)),
	_Street(strcpy(new char [strlen(B._Street) + 1], B._Street)),
	_House(B._House),
	_Flat(B._Flat),
	_AccountID(strcpy(new char [strlen(B._AccountID) + 1], B._AccountID)),
	_AvgAmount(B._AvgAmount){}

Lab1NS::Buyer &Lab1NS::Buyer::operator= (Buyer const &B){
	if (this != &B){
		delete [] _SecondName;
		delete [] _Name;
		delete [] _City;
		delete [] _Street;
		delete [] _AccountID;
		_SecondName = strcpy(new char [strlen(B._SecondName) + 1],
							 B._SecondName);
		_Name = strcpy(new char [strlen(B._Name) + 1], B._Name);
		_City = strcpy(new char [strlen(B._City) + 1], B._City);
		_Street = strcpy(new char [strlen(B._Street) + 1], B._Street);
		_House = B._House;
		_Flat = B._Flat;
		_AccountID = strcpy(new char [strlen(B._AccountID) + 1], B._AccountID);
		_AvgAmount = B._AvgAmount;
	}
	return *this;
}

Lab1NS::Buyer::~Buyer (){
	delete [] _SecondName;
	delete [] _Name;
	delete [] _City;
	delete [] _Street;
	delete [] _AccountID;
}

/*

 ######   ######## ########          ######  ######## ########
##    ##  ##          ##            ##    ## ##          ##
##        ##          ##            ##       ##          ##
##   #### ######      ##    #######  ######  ######      ##
##    ##  ##          ##                  ## ##          ##
##    ##  ##          ##            ##    ## ##          ##
 ######   ########    ##             ######  ########    ##

*/

char const *Lab1NS::Buyer::getSecondName () const{
	return _SecondName;
}

char const *Lab1NS::Buyer::getName () const{
	return _Name;
}

char const *Lab1NS::Buyer::getCity () const{
	return _City;
}

char const *Lab1NS::Buyer::getStreet () const{
	return _Street;
}

unsigned Lab1NS::Buyer::getHouse () const{
	return _House;
}

unsigned Lab1NS::Buyer::getFlat () const{
	return _Flat;
}

char const *Lab1NS::Buyer::getAccountID () const{
	return _AccountID;
}

long Lab1NS::Buyer::getAvgAmount () const{
	return _AvgAmount;
}

void Lab1NS::Buyer::setSecondName (char const *SecondName){
	delete [] _SecondName;
	_SecondName = strcpy(new char [strlen(SecondName) + 1], SecondName);
}

void Lab1NS::Buyer::setName (char const *Name){
	delete [] _Name;
	_Name = strcpy(new char [strlen(Name) + 1], Name);
}

void Lab1NS::Buyer::setCity (char const *City){
	delete [] _City;
	_City = strcpy(new char [strlen(City) + 1], City);
}

void Lab1NS::Buyer::setStreet (char const *Street){
	delete [] _Street;
	_Street = strcpy(new char [strlen(Street) + 1], Street);
}

void Lab1NS::Buyer::setHouse (unsigned House){
	_House = House;
}

void Lab1NS::Buyer::setFlat (unsigned Flat){
	_Flat = Flat;
}

void Lab1NS::Buyer::setAccountID (char const *AccountID){
	delete [] _AccountID;
	_AccountID = strcpy(new char [strlen(AccountID) + 1], AccountID);
}

void Lab1NS::Buyer::setAvgAmount (long AvgAmount){
	_AvgAmount = AvgAmount;
}

/*

 #######  ##     ## ######## ########  ##        #######     ###    ########  #### ##    ##  ######
##     ## ##     ## ##       ##     ## ##       ##     ##   ## ##   ##     ##  ##  ###   ## ##    ##
##     ## ##     ## ##       ##     ## ##       ##     ##  ##   ##  ##     ##  ##  ####  ## ##
##     ## ##     ## ######   ########  ##       ##     ## ##     ## ##     ##  ##  ## ## ## ##   ####
##     ##  ##   ##  ##       ##   ##   ##       ##     ## ######### ##     ##  ##  ##  #### ##    ##
##     ##   ## ##   ##       ##    ##  ##       ##     ## ##     ## ##     ##  ##  ##   ### ##    ##
 #######     ###    ######## ##     ## ########  #######  ##     ## ########  #### ##    ##  ######

*/

bool Lab1NS::operator== (Lab1NS::Buyer const &a, Lab1NS::Buyer const &b){
	return a.getAvgAmount() == b.getAvgAmount();
}

bool Lab1NS::operator> (Lab1NS::Buyer const &a, Lab1NS::Buyer const &b){
	return a.getAvgAmount() > b.getAvgAmount();
}

bool Lab1NS::operator< (Lab1NS::Buyer const &a, Lab1NS::Buyer const &b){
	return a.getAvgAmount() < b.getAvgAmount();
}

bool Lab1NS::operator<= (Lab1NS::Buyer const &a, Lab1NS::Buyer const &b){
	return a.getAvgAmount() <= b.getAvgAmount();
}

bool Lab1NS::operator>= (Lab1NS::Buyer const &a, Lab1NS::Buyer const &b){
	return a.getAvgAmount() >= b.getAvgAmount();
}

std::istream &Lab1NS::operator>> (std::istream &fin, Lab1NS::Buyer &a){
	std::string temp;
	long t;
	fin >> temp;
	a.setSecondName(temp.c_str());
	fin >> temp;
	a.setName(temp.c_str());
	fin >> temp;
	a.setCity(temp.c_str());
	fin >> temp;
	a.setStreet(temp.c_str());
	fin >> t;
	a.setHouse(t);
	fin >> t;
	a.setFlat(t);
	fin >> temp;
	a.setAccountID(temp.c_str());
	fin >> t;
	a.setAvgAmount(t);
	return fin;
}

std::ostream &Lab1NS::operator<< (std::ostream &fout, Lab1NS::Buyer const &a){
	fout << a.getSecondName() << std::endl;
	fout << a.getName() << std::endl;
	fout << a.getCity() << std::endl;
	fout << a.getStreet() << std::endl;
	fout << a.getHouse() << std::endl;
	fout << a.getFlat() << std::endl;
	fout << a.getAccountID() << std::endl;
	fout << a.getAvgAmount();
	return fout;
}
