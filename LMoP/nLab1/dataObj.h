#ifndef LAB_DOBJ_H
#define LAB_DOBJ_H
#include <iostream>

namespace lab{
	class dObj{
		double (*Func)(double) = nullptr;
		double Diff = 0.001;
		double LLim = 0;
		double RLim = 0;
		double Val = 0;

	public:
		explicit dObj (){}
		dObj (dObj const &other);
		dObj &operator= (dObj const &other);
		~dObj (){};

		double (*getFunc () const)(double);
		double getDiff () const;
		double getLLim () const;
		double getRLim () const;
		double getVal () const;

		void setFunc (double (*func)(double));
		void setDiff (double diff);
		void setLLim (double lLim);
		void setRLim (double rLim);

		double calcVal ();

		std::ostream &write (std::ostream &fout) const;
		std::istream &read (std::istream &fin);
	};
}

#endif
