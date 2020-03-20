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
	name(strcpy(new char[1], "")),
	capital(strcpy(new char[1], "")),
	language(strcpy(new char[1], "")),
	population(0), area(0){}

lab::State::State (lab::State const &other) :
	name(strcpy(new char[strlen(other.name) + 1], other.name)),
	capital(strcpy(new char[strlen(other.capital) + 1], other.capital)),
	language(strcpy(new char[strlen(other.language) + 1], other.language)),
	population(other.population), area(other.area){}

lab::State &lab::State::operator= (lab::State const &other){
	if (this != &other){
		delete[] name;
		delete[] capital;
		delete[] language;
		name = strcpy(new char[strlen(other.name) + 1], other.name);
		capital = strcpy(new char[strlen(other.capital) + 1], other.capital);
		language = strcpy(new char[strlen(other.language) + 1], other.language);
		population = other.population;
		area = other.area;
	}
	return *this;
}

lab::State::~State (){
	delete[] name;
	delete[] capital;
	delete[] language;
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

char *lab::State::getName () const{
	return name;
}

char *lab::State::getCapital () const{
	return capital;
}

char *lab::State::getLanguage () const{
	return language;
}

size_t lab::State::getPopulation () const{
	return population;
}

size_t lab::State::getArea () const{
	return area;
}

void lab::State::setName (char const *newName){
	delete[] name;
	name = strcpy(new char[strlen(newName) + 1], newName);
}

void lab::State::setCapital (char const *newCapital){
	delete[] capital;
	capital = strcpy(new char[strlen(newCapital) + 1], newCapital);
}

void lab::State::setLanguage (char const *newLanguage){
	delete[] language;
	language = strcpy(new char[strlen(newLanguage) + 1], newLanguage);
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
	delete[] name;
	delete[] capital;
	delete[] language;
	name = strcpy(new char[Name.size() + 1], Name.c_str());
	capital = strcpy(new char[Capital.size() + 1], Capital.c_str());
	language = strcpy(new char[Language.size() + 1], Language.c_str());
	population = Population;
	area = Area;
	return fin;
}
