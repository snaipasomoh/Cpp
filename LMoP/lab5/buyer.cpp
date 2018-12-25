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
	_SecondName(""),
	_Name(""),
	_City(""),
	_Street(""),
	_House(0),
	_Flat(0),
	_AccountID(""),
	_AvgAmount(0){}

Lab1NS::Buyer::Buyer (std::string const &SecondName, std::string const &Name,
					std::string const &City, std::string const &Street,
					unsigned House, unsigned Flat,
					std::string const &AccountID, long AvgAmount) :
	_SecondName(SecondName),
	_Name(Name),
	_City(City),
	_Street(Street),
	_House(House),
	_Flat(Flat),
	_AccountID(AccountID),
	_AvgAmount(AvgAmount){}

Lab1NS::Buyer::Buyer (Buyer const &B) :
	_SecondName(B._SecondName),
	_Name(B._Name),
	_City(B._City),
	_Street(B._Street),
	_House(B._House),
	_Flat(B._Flat),
	_AccountID(B._AccountID),
	_AvgAmount(B._AvgAmount){}

Lab1NS::Buyer &Lab1NS::Buyer::operator= (Buyer const &B){
	if (this != &B){
		_SecondName = B._SecondName;
		_Name = B._Name;
		_City = B._City;
		_Street = B._Street;
		_House = B._House;
		_Flat = B._Flat;
		_AccountID = B._AccountID;
		_AvgAmount = B._AvgAmount;
	}
	return *this;
}

Lab1NS::Buyer::~Buyer (){}

/*

 ######   ######## ########          ######  ######## ########
##    ##  ##          ##            ##    ## ##          ##
##        ##          ##            ##       ##          ##
##   #### ######      ##    #######  ######  ######      ##
##    ##  ##          ##                  ## ##          ##
##    ##  ##          ##            ##    ## ##          ##
 ######   ########    ##             ######  ########    ##

*/

std::string Lab1NS::Buyer::getSecondName () const{
	return _SecondName;
}

std::string Lab1NS::Buyer::getName () const{
	return _Name;
}

std::string Lab1NS::Buyer::getCity () const{
	return _City;
}

std::string Lab1NS::Buyer::getStreet () const{
	return _Street;
}

unsigned Lab1NS::Buyer::getHouse () const{
	return _House;
}

unsigned Lab1NS::Buyer::getFlat () const{
	return _Flat;
}

std::string Lab1NS::Buyer::getAccountID () const{
	return _AccountID;
}

long Lab1NS::Buyer::getAvgAmount () const{
	return _AvgAmount;
}

void Lab1NS::Buyer::setSecondName (std::string const &SecondName){
	_SecondName = SecondName;
}

void Lab1NS::Buyer::setName (std::string const &Name){
	_Name = Name;
}

void Lab1NS::Buyer::setCity (std::string const &City){
	_City = City;
}

void Lab1NS::Buyer::setStreet (std::string const &Street){
	_Street = Street;
}

void Lab1NS::Buyer::setHouse (unsigned House){
	_House = House;
}

void Lab1NS::Buyer::setFlat (unsigned Flat){
	_Flat = Flat;
}

void Lab1NS::Buyer::setAccountID (std::string const &AccountID){
	_AccountID = AccountID;
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
	return a.getSecondName() == b.getSecondName();
}

bool Lab1NS::operator!= (Lab1NS::Buyer const &a, Lab1NS::Buyer const &b){
	return a.getSecondName() != b.getSecondName();
}

bool Lab1NS::operator> (Lab1NS::Buyer const &a, Lab1NS::Buyer const &b){
	return a.getSecondName() > b.getSecondName();
}

bool Lab1NS::operator< (Lab1NS::Buyer const &a, Lab1NS::Buyer const &b){
	return a.getSecondName() < b.getSecondName();
}

bool Lab1NS::operator<= (Lab1NS::Buyer const &a, Lab1NS::Buyer const &b){
	return a.getSecondName() <= b.getSecondName();
}

bool Lab1NS::operator>= (Lab1NS::Buyer const &a, Lab1NS::Buyer const &b){
	return a.getSecondName() >= b.getSecondName();
}

std::istream &Lab1NS::operator>> (std::istream &fin, Lab1NS::Buyer &a){
	std::string temp;
	long t;
	fin >> temp;
	a.setSecondName(temp);
	fin >> temp;
	a.setName(temp);
	fin >> temp;
	a.setCity(temp);
	fin >> temp;
	a.setStreet(temp);
	fin >> t;
	a.setHouse(t);
	fin >> t;
	a.setFlat(t);
	fin >> temp;
	a.setAccountID(temp);
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
