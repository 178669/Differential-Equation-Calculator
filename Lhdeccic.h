#ifndef LHDECCIC_H
#define LHDECCIC_H
#include <string>
#include <string>
#include <fstream>
#include "Signal.h"
class Lhdeccic
	{
		private: 
			double b;//b in eq 1 and 4
			double t0;//t initial
			double K0;//K_0 in eq 2 and 5
			std::string label;//label
			Signal Diffeqsol;//diffeq solution variable to store solution
		public:
		//default constr.
			Lhdeccic();
			Lhdeccic(double,double,double);
		//mutators
			void virtual setb(double);
			void virtual sett0(double);
			void virtual setK0(double);
			void setlabel(std::string);
		//accessors
			double getb();
			double gett0();
			double getK0();
			const std::string getlabel();//modified for step 7
		//textnum from signal class must be const
			const std::string textNum(double) const;//the function i was instructed to copy paste
		//virtual
			const virtual std::string textrep()=0;//first virtual for text representation
			const virtual void header(std::ofstream &access)=0;//second virtual for printing header
			const virtual std::string ICtextrep()=0;//third for initial cond textrep
			virtual const void fills()=0;
			virtual const void DPrint(std::ofstream &access);

		//step 7
			Signal* accDiffeqsol();
			const std::string DEtextrep(); 

	};
#endif
