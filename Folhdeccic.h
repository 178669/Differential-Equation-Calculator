#ifndef FOLHDECCIC_H
#define FOLHDECCIC_H
#include "Lhdeccic.h"

class Folhdeccic : public Lhdeccic//first order class
	{			
		public: 
			Folhdeccic();
			Folhdeccic(double,double,double);
			const std::string textrep();//first virtual for text representation
			const void header(std::ofstream &access);//second virtual for printing header
			const std::string ICtextrep();//third virtual function for initial cond
			const void fills();
			//const void DPrint(std::ofstream &access);

			//adding virtual t0,b,k0 from base
			//mutators
			void setb(double);
			void sett0(double);
			void setK0(double);
			//
	};
#endif
