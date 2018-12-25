#include "dataObj.h"

/*

 ######  ########  ########  ######  ####    ###    ##
##    ## ##     ## ##       ##    ##  ##    ## ##   ##
##       ##     ## ##       ##        ##   ##   ##  ##
 ######  ########  ######   ##        ##  ##     ## ##
      ## ##        ##       ##        ##  ######### ##
##    ## ##        ##       ##    ##  ##  ##     ## ##
 ######  ##        ########  ######  #### ##     ## ########

*/

lab::dObj::dObj (std::string const &name, std::set<std::string> const &sports,
			   		 int year, size_t capacity, size_t areas) :
	Name(name),
	Sports(sports),
	Year(year), Capacity(capacity), Areas(areas){}

lab::dObj::dObj (lab::dObj const &other) :
	Name(other.Name),
	Sports(other.Sports),
	Year(other.Year), Capacity(other.Capacity), Areas(other.Areas){}

lab::dObj &lab::dObj::operator= (lab::dObj const &other){
	if (this != &other){
		Name = other.Name;
		Sports = other.Sports;
		Year = other.Year;
		Capacity = other.Capacity;
		Areas = other.Areas;
	}
	return *this;
}

lab::dObj::~dObj (){}

/*

##     ## ######## ######## ##     ##  #######  ########   ######
###   ### ##          ##    ##     ## ##     ## ##     ## ##    ##
#### #### ##          ##    ##     ## ##     ## ##     ## ##
## ### ## ######      ##    ######### ##     ## ##     ##  ######
##     ## ##          ##    ##     ## ##     ## ##     ##       ##
##     ## ##          ##    ##     ## ##     ## ##     ## ##    ##
##     ## ########    ##    ##     ##  #######  ########   ######

*/

std::string lab::dObj::getName () const{
	return Name;
}

std::set<std::string> lab::dObj::getSports () const{
	return Sports;
}

int lab::dObj::getYear () const{
	return Year;
}

size_t lab::dObj::getCapacity () const{
	return Capacity;
}

size_t lab::dObj::getAreas () const{
	return Areas;
}

void lab::dObj::setName (std::string const &name){
	Name = name;
}

void lab::dObj::setSports (std::set<std::string> const &sports){
	Sports = sports;
}

void lab::dObj::setYear (int year){
	Year = year;
}

void lab::dObj::setCapacity (size_t capacity){
	Capacity = capacity;
}

void lab::dObj::setAreas (size_t areas){
	Areas = areas;
}

std::ostream &lab::dObj::write (std::ostream &fout) const{
	fout << Name << std::endl;
	fout << Sports.size() << std::endl;
	for (auto i : Sports){
		fout << i << std::endl;
	}
	fout << Year << std::endl;
	fout << Capacity << std::endl;
	fout << Areas;
	return fout;
}

std::istream &lab::dObj::read (std::istream &fin){
	fin >> Name;
	if (Name == ""){
		return fin;
	}
	size_t temp;
	fin >> temp;
	Sports.clear();
	for (size_t i = 0; i < temp; i++){
		std::string tstr;
		fin >> tstr;
		Sports.insert(tstr);
	}
	fin >> Year;
	fin >> Capacity;
	fin >> Areas;
	return fin;
}

/*

 #######  ##     ## ######## ########  ##        #######     ###    ########
##     ## ##     ## ##       ##     ## ##       ##     ##   ## ##   ##     ##
##     ## ##     ## ##       ##     ## ##       ##     ##  ##   ##  ##     ##
##     ## ##     ## ######   ########  ##       ##     ## ##     ## ##     ##
##     ##  ##   ##  ##       ##   ##   ##       ##     ## ######### ##     ##
##     ##   ## ##   ##       ##    ##  ##       ##     ## ##     ## ##     ##
 #######     ###    ######## ##     ## ########  #######  ##     ## ########

*/

bool lab::dObj::operator< (lab::dObj other) const{
	return Name < other.Name;
}

bool lab::dObj::operator> (lab::dObj other) const{
	return Name > other.Name;
}

bool lab::dObj::operator== (lab::dObj other) const{
	return Name == other.Name;
}

bool lab::dObj::operator!= (lab::dObj other) const{
	return Name != other.Name;
}

bool lab::dObj::operator<= (lab::dObj other) const{
	return Name <= other.Name;
}

bool lab::dObj::operator>= (lab::dObj other) const{
	return Name >= other.Name;
}

std::ostream &lab::operator<< (std::ostream &fout, lab::dObj const &obj){
	return obj.write(fout);
}

std::istream &lab::operator>> (std::istream &fin, lab::dObj &obj){
	return obj.read(fin);
}
