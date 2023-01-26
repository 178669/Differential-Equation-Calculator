#include "Lhdeccic.h"
//class definitions
//[1]constructors: Start🔥🔥🔥🔥
	Lhdeccic::Lhdeccic()
		{
			sett0(0);
			setb(1);
			setK0(1);
			setlabel("y");
			//Diffeqsol.set_f(100);
			//Diffeqsol.set_samples(510);
			//Diffeqsol.set_t0(gett0());
		}
	Lhdeccic::Lhdeccic(double a,double b,double c)
		{
			sett0(a);
			setb(b);
			setK0(c);
			setlabel("y");
			//Diffeqsol.set_f(100);
			//Diffeqsol.set_samples(510);
			//Diffeqsol.set_t0(gett0());
		}
//[1]end
//🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑
//[2]mutators and accessors start🔥🔥🔥🔥
	void Lhdeccic::setb(double a)
		{
			b=a;
		}
	void Lhdeccic::sett0(double a)
		{
			t0=a;
		}
	void Lhdeccic::setK0(double a)
		{
			K0=a;
		}
	double Lhdeccic::getb()
		{
			return b;
		}
	double Lhdeccic::gett0()
		{
			return t0;
		}
	double Lhdeccic::getK0()
		{
			return K0;
		}
	void Lhdeccic::setlabel(std::string a)
		{//statement that uses the solution signal to set its label mmember variable to label used for diffeq
			Diffeqsol.set_string(a);//setting the input string to diffeqsol's label
			label=a;
		}	
	const std::string Lhdeccic::getlabel()//modified for step 7
		{
			return label;
		}
//[2]end
//🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑
//[3] textNum from signal class start 🔥🔥🔥🔥🔥
	const std::string Lhdeccic::textNum(double x) const 
			{
				if (x >= 100)
				// large numbers truncated as int -> string 
					return std::to_string(int(x));
				else {
					// small numbers will get 3 digits 
					std::string x_exp = std::to_string(x); // return 4 characters, or 5 if x<0 
					return x_exp.substr(0, 4 + (x<0));
					} 
			}	
//[3] end
//🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑
//[4] Virtual functions start 🔥🔥🔥
	/*const std::string Lhdeccic::textrep()//defining it here bc I cant get it to work in implementation
			{
				std::string textreptext=getlabel()+"'(t) + "+textNum(getb())+getlabel()+"(t) = 0";
				return textreptext;
			}
	const void Lhdeccic::header(std::ofstream &access)//second virtual for printing header
		{//first 3 lines
				access<<"---------------------------------\n"
				<<"First-Order Differential Equation\n"
				<<"---------------------------------\n";
			//fourt line
				access<<textrep()<<std::endl;
			}
	
	const std::string Lhdeccic::ICtextrep()
			{
				std::string a=getlabel()+"("+textNum(gett0())+") = "+textNum(getK0());
				return a;
			}
	*/
	/*const void Lhdeccic::fills()
		{
			Signal* solptr;
			solptr=accDiffeqsol();
			(*solptr).set_samples(501);
			(*solptr).set_f(100);
			(*solptr).set_t0(gett0());
			(*solptr).expfill(1/b,getK0());
		}
	*/
//end
//🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑🛑
//[5] step 7 start🔥🔥🔥
		Signal* Lhdeccic::accDiffeqsol()
			{
				return &Diffeqsol;
			}
		
		const std::string Lhdeccic::DEtextrep()
			{
				return getlabel()+"(t) = "+Diffeqsol.get_math();
			}
	const void Lhdeccic::DPrint(std::ofstream &access)
		{
			access << "Solution\n"
            << "--------\n"
            << DEtextrep()<<std::endl<<std::endl;
            Diffeqsol.writes();
		}
	


