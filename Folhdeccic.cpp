#include "Folhdeccic.h"
//first order class definitions
//constructors
	Folhdeccic::Folhdeccic():Lhdeccic()
		{
			fills();
		}
	Folhdeccic::Folhdeccic(double a,double b,double c):Lhdeccic(a,b,c)
		{
			fills();
		}
	const std::string Folhdeccic::textrep()//defining it here bc I cant get it to work in implementation
		{
			std::string textreptext=getlabel()+"'(t) + "+textNum(getb())+" "+getlabel()+"(t) = 0";
			return textreptext;
		}
	const void Folhdeccic::header(std::ofstream &access)//second virtual for printing header modified for step 6
		{//first 3 lines
			access<<"---------------------------------\n"
			<<"First-Order Differential Equation\n"
			<<"---------------------------------\n";
		//fourt line
			access<<textrep()<<std::endl<<std::endl;
		//initioal cond print implement	
			access<<"Initial Condition\n-----------------\n"
			<<ICtextrep()<<"\n\n";

		}
	const std::string Folhdeccic::ICtextrep()
		{
			std::string a=getlabel()+"("+textNum(gett0())+") = "+textNum(getK0());
			return a;
		}
	const void Folhdeccic::fills()
		{
			Signal* solptr;
			solptr=accDiffeqsol();
			(*solptr).set_samples(501);
			(*solptr).set_f(200);
			(*solptr).set_t0(gett0());
			(*solptr).expfill(1/getb(),getK0());
			(*solptr).rounder();
		}
	void Folhdeccic::setb(double a)
		{
			Lhdeccic::setb(a);
			fills();//step7
		}
	void Folhdeccic::sett0(double a)
		{
			Lhdeccic::sett0(a);
			fills();//step7
		}
	void Folhdeccic::setK0(double a)
		{
			Lhdeccic::setK0(a);
			fills();//step 7
		}
	/*const void Folhdeccic::DPrint(std::ofstream &access)
		{
			access << "Solution\n"
            << "--------\n"
            << DEtextrep()<<std::endl<<std::endl;
            
		}
	*/
