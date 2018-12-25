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

lab::dObj::dObj (char const *name, std::set<std::string> const &sports,
			   		 int year, size_t capacity, size_t areas) :
	Name(strcpy(new char [strlen(name) + 1], name)),
	Sports(sports),
	Year(year), Capacity(capacity), Areas(areas){}

lab::dObj::dObj (lab::dObj const &other) :
	Name(strcpy(new char [strlen(other.Name) + 1], other.Name)),
	Sports(other.Sports),
	Year(other.Year), Capacity(other.Capacity), Areas(other.Areas){}

lab::dObj &lab::dObj::operator= (lab::dObj const &other){
	if (this != &other){
		delete [] Name;
		Name = strcpy(new char [strlen(other.Name) + 1], other.Name);
		Sports = other.Sports;
		Year = other.Year;
		Capacity = other.Capacity;
		Areas = other.Areas;
	}
	return *this;
}

lab::dObj::~dObj (){
	delete [] Name;
}

/*

##     ## ######## ######## ##     ##  #######  ########   ######
###   ### ##          ##    ##     ## ##     ## ##     ## ##    ##
#### #### ##          ##    ##     ## ##     ## ##     ## ##
## ### ## ######      ##    ######### ##     ## ##     ##  ######
##     ## ##          ##    ##     ## ##     ## ##     ##       ##
##     ## ##          ##    ##     ## ##     ## ##     ## ##    ##
##     ## ########    ##    ##     ##  #######  ########   ######

*/

char const *lab::dObj::getName () const{
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

void lab::dObj::setName (char const *name){
	Name = strcpy(new char [strlen(name) + 1], name);
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
	std::string tName;
	fin >> tName;
	if (tName == ""){
		return fin;
	}
	delete [] Name;
	Name = strcpy(new char [strlen(tName.c_str()) + 1], tName.c_str());
	size_t temp;
	fin >> temp;
	Sports.clear();
	for (size_t i = 0; i < temp; i++){
		fin >> tName;
		Sports.insert(tName);
		std::cerr << tName << std::endl;
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
	return strcmp(Name, other.Name) < 0;
}

bool lab::dObj::operator> (lab::dObj other) const{
	return strcmp(Name, other.Name) > 0;
}

bool lab::dObj::operator== (lab::dObj other) const{
	return strcmp(Name, other.Name) == 0;
}

bool lab::dObj::operator!= (lab::dObj other) const{
	return strcmp(Name, other.Name) != 0;
}

bool lab::dObj::operator<= (lab::dObj other) const{
	return strcmp(Name, other.Name) <= 0;
}

bool lab::dObj::operator>= (lab::dObj other) const{
	return strcmp(Name, other.Name) >= 0;
}

std::ostream &lab::operator<< (std::ostream &fout, lab::dObj const &obj){
	return obj.write(fout);
}

std::istream &lab::operator>> (std::istream &fin, lab::dObj &obj){
	return obj.read(fin);
}
