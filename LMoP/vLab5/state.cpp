#include "state.hpp"

/*

 ######  ########  ########  ######  ####    ###    ##
##    ## ##     ## ##       ##    ##  ##    ## ##   ##
##       ##     ## ##       ##        ##   ##   ##  ##
 ######  ########  ######   ##        ##  ##     ## ##
      ## ##        ##       ##        ##  ######### ##
##    ## ##        ##       ##    ##  ##  ##     ## ##
 ######  ##        ########  ######  #### ##     ## ########

*/

lab::State::State () :
	name(""),
	capital(""),
	language(""),
	population(0), area(0){}

lab::State::State (lab::State const &other) :
	name(other.name),
	capital(other.capital),
	language(other.language),
	population(other.population), area(other.area){}

lab::State &lab::State::operator= (lab::State const &other){
	if (this != &other){
		name = other.name;
		capital = other.capital;
		language = other.language;
		population = other.population;
		area = other.area;
	}
	return *this;
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

std::string lab::State::getName () const{
	return name;
}

std::string lab::State::getCapital () const{
	return capital;
}

std::string lab::State::getLanguage () const{
	return language;
}

size_t lab::State::getPopulation () const{
	return population;
}

size_t lab::State::getArea () const{
	return area;
}

void lab::State::setName (std::string const &newName){
	name = newName;
}

void lab::State::setCapital (std::string const &newCapital){
	capital = newCapital;
}

void lab::State::setLanguage (std::string const &newLanguage){
	language = newLanguage;
}

void lab::State::setPopulation (size_t newPopulation){
	population = newPopulation;
}

void lab::State::setArea (size_t newArea){
	area = newArea;
}

std::ostream &lab::State::write (std::ostream &fout) const{
	fout << name << std::endl;
	fout << capital << std::endl;
	fout << language << std::endl;
	fout << population << std::endl;
	fout << area << std::endl;
	return fout;
}

std::istream &lab::State::read (std::istream &fin){
	std::string Name;
	std::string Capital;
	std::string Language;
	size_t Population;
	size_t Area;
	if (!(fin >> Name >> Capital >> Language >> Population >> Area)){
		return fin;
	}
	name = Name;
	capital = Capital;
	language = Language;
	population = Population;
	area = Area;
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

bool lab::State::operator< (lab::State const &other) const{
	return getArea() < other.getArea();
}

bool lab::State::operator> (lab::State const &other) const{
	return getArea() > other.getArea();
}

bool lab::State::operator== (lab::State const &other) const{
	return getArea() == other.getArea();
}

bool lab::State::operator!= (lab::State const &other) const{
	return getArea() != other.getArea();
}

bool lab::State::operator<= (lab::State const &other) const{
	return getArea() <= other.getArea();
}

bool lab::State::operator>= (lab::State const &other) const{
	return getArea() >= other.getArea();
}

std::ostream &lab::operator<< (std::ostream &fout, lab::State const &data){
	data.write(fout);
	return fout;
}

std::istream &lab::operator>> (std::istream &fin, lab::State &data){
	data.read(fin);
	return fin;
}
