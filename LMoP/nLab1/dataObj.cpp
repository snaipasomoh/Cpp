#include "dataObj.h"

lab::dObj::dObj (lab::dObj const &other) :
	Func(other.Func), Diff(other.Diff), LLim(other.LLim),
	RLim(other.RLim), Val(other.Val){}

lab::dObj &lab::dObj::operator= (lab::dObj const &other){
	if (this != &other){
		Func = other.Func;
		Diff = other.Diff;
		LLim = other.LLim;
		RLim = other.RLim;
		Val = other.Val;
	}
	return *this;
}

double (*lab::dObj::getFunc () const)(double){
	return Func;
}

double lab::dObj::getDiff () const{
	return Diff;
}

double lab::dObj::getLLim () const{
	return LLim;
}

double lab::dObj::getRLim () const{
	return RLim;
}

double lab::dObj::getVal () const{
	return Val;
}

void lab::dObj::setFunc (double (*func)(double)){
	Func = func;
}

void lab::dObj::setDiff (double diff){
	Diff = diff;
}

void lab::dObj::setLLim (double lLim){
	LLim = lLim;
}

void lab::dObj::setRLim (double rLim){
	RLim = rLim;
}

double lab::dObj::calcVal (){
	double sum = 0;
	for (double i = LLim; i <= RLim; i += Diff){
		sum += (*Func)(i) * Diff;
	}
	Val = sum;
	if (Val < Diff && -Val < Diff){
		Val = 0;
	}
	return Val;
}

std::ostream &lab::dObj::write (std::ostream &fout) const{
	fout << Diff << std::endl;
	fout << LLim << std::endl;
	fout << RLim << std::endl;
	fout << Val << std::endl;
	return fout;
}

std::istream &lab::dObj::read (std::istream &fin){
	fin >> Diff >> LLim >> RLim >> Val;
	return fin;
}
