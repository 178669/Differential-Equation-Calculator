#ifndef SIGNAL_H
#define SIGNAL_H
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
class Signal
	{
		private: 
			unsigned int samples;
			double f;
			double t0;
			double tfix;
			std::string label;
			std::string filename;
			std::string math;
			std::vector<double>signal;
			std::vector<double>time;
			
		public:
		//==Constructors	
			Signal();
			Signal(unsigned int,double,double);
		//==Accessors and mutators	
			void set_samples(unsigned int);
			void set_f(double);
			void set_t0(double);
			unsigned int get_samples();
			double get_f();
			double get_t0();
		//==pt 2 mutator and accessors	
			void set_string(std::string);
			std::string get_label();
			std::string get_filename();
		//==pt 3 mutator and accessors
			void set_math(std::string);
			std::string get_math();
		//==pt 4
			void writes();
		//==pt 5 accessors
			void set_signal1();
			std::vector<double> signal1();//signal vector accessor
			double signal1(unsigned int);//signal accessor vector overload
			void set_time1();
			std::vector<double> time1();//time vector accessor
			double time1(unsigned int);//time vector overload accessor
			void filltime();//fills using formula
		//==pt 6 functions	
			void c_signal(double);//creates const signal
			const std::string textNum(double) const;//the function i was instructed to copy paste
		//==pt 7 op over	
			Signal operator = (const Signal &);//operator overload
		//==pt 8
			//void plotter();
		//==pt 10
			void sinusoid(double,double,double);
		//==pt 11 rounder
			void rounder();
		//==pt 12 overload
			Signal operator + (const Signal &);//operator overload
		//==pt 15 *overload
			Signal operator * (const Signal &);
		//ica13 start: new member funct
			void expfill(double, double);//fills with exponential signal
		
	};

#endif
