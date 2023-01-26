//#include <mgl2/mgl.h>
#include "Signal.h"

//class function definitions
	Signal::Signal()
		{
			samples=101;
			f=100;
			t0=0;
			set_string("x");//mutator set filename
			
			set_math("0");//mutator set mathequation
			set_signal1();//setup vectors
			set_time1();//setup vectors
			
			filltime();//fill w time valyes
		}

	Signal::Signal(unsigned int a, double rate, double time)
		{
			samples=a;
			f=rate;
			t0=time;
			set_string("x");//mutator set filename
			set_math("0");//mutator set mathequation
			set_signal1();//set signal vector and fill
			set_time1();//set time vector and fill 0
			filltime();//fill w time values
		}
		
	void Signal::set_samples(unsigned int a)
		{
			samples=a;
			time.resize(samples);
			signal.resize(samples);
			filltime();
		}

	void Signal::set_f(double a)
		{
			f=a;
			filltime();

		}

	void Signal::set_t0(double a)
		{
			t0=a;
			std::string dog;
			//std::string temp=std::to_string(a);
			//for (int i=1;i<temp.size();i++)
				//{
				//	dog[i-1]=temp[i];
				//}
			//std::cout<<temp;
			//tfix=stod(dog); 
			tfix=a;
			filltime();
		}

	unsigned int Signal::get_samples()//get num samples
		{
			return samples;
		}

	double Signal::get_f()//get sampling frqeuency
		{
			return f;
		}

	double Signal::get_t0()//get t initial
		{
			return t0;
		}
		
	void Signal::set_string(std::string a) //mutator to set label and filename
		{
			label=a;
			filename="diff_eqn_soln_"+a;
		}
		
	std::string Signal::get_label()//accessor for label
		{
			return label;
		}
		
	std::string Signal::get_filename()//accessor for filename
		{
			return filename;
		}
		
	void Signal::set_math(std::string a)//sets math eq
		{
			math=a;
		}
		
	std::string Signal::get_math()//gets math eq
		{
			return math;
		}
		
	void Signal::writes()//writes to file
		{
			std::ofstream access;
			access.open(filename+".txt");
			access<<"Time-Domain Signal Samples\n"
				<<"N = "<<samples<<std::endl
				<<"fs = "<<f<<std::endl
				<<"t0 = "<<t0<<std::endl
				<<"Signal label: "<<label<<std::endl
				<<"Mathematical expression"<<std::endl
				<<label<<"(t) = "<<math<<std::endl
				<<"Time and signal samples in .csv format"<<std::endl
				<<"t, x(t)"<<std::endl
				<<"-------"<<std::endl;
				for(int i=0;i<samples;i++)
					{
						access<<time.at(i)<<", "<<signal.at(i)<<std::endl;
					}
		}
//==Part 5==
	
	void Signal::set_signal1()//creates vector of #samples size and fills w 0's
		{
			signal.resize(samples,0);
		}
	std::vector<double> Signal::signal1()//signal vector accessor
		{
			return signal;
		}
	double Signal::signal1(unsigned int a)//signal vector overload
		{
			return signal[a];
		}
	//--
	void Signal::set_time1()//creates vector of #samples size and fills w 0's
		{
			time.resize(samples,0);
		}
	std::vector<double> Signal::time1()//time vector accessor
		{
			return time;
		}
	double Signal::time1(unsigned int a)//time vector accessor overload
		{
			return time[a];
		}
	//--	
	void Signal::filltime()//fill time member functoon
		{
			for (int i=0;i<samples;i++)
				{
					time[i]=t0+(((double) i)/f);
				}
		}
//xxxxxxxxxxxx

//==Part 6==
	void Signal::c_signal(double a)
		{
			fill(signal.begin(),signal.end(),a);
			set_math(textNum(double(a)));
		}
	const std::string Signal::textNum(double x) const 
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
//xxxxxxxxxxxx	

//==Part 7==
Signal Signal::operator=(const Signal &right)
		{
			if (this!=&right)
				{					
					samples=right.samples;
					signal=right.signal;
					time=right.time;
					f=right.f;
					t0=right.t0;
					math=right.math;
				}
			return *this;
		}
//xxxxxxxxxxxx

//==Part 8==
/*	void Signal::plotter()//plotting
		{
			mglData t_mgl(samples),s_mgl(samples);
			for (int i=0;i<samples;i++)//copying time and signal arrays, but member function "Set()" is not used as an example in the ex program??
			{//I used this method of copying for the last assignment too, so I'll use it again intead of "f.a[k]=val", though I do understand it for exam purposes.
				t_mgl.a[i]=time[i];
				s_mgl.a[i]=signal[i];
			}
			mglGraph gr;
			string temp=label+"(t) = "+math;
			//====converting string to char[]
			int n=temp.length();
			char char_array[n+1];
			strcpy(char_array,temp.c_str());
			gr.Title(char_array);
			//xxxx
			double tmin=t_mgl[0];
			double tmax=t_mgl[samples-1];
	
			//finding max ============
			double peaks=abs(s_mgl[0]);
				for(int i=0;i<samples;i++)
					{
						if (abs(s_mgl[i+1])>peaks)
							{
								peaks=abs(s_mgl[i+1]);
							}
					
					}
			//=========================
		
			gr.SetRanges(tmin,tmax,-peaks,peaks);
			gr.SetOrigin(0, 0);
			gr.Axis();
			gr.Puts(mglPoint(-(tmax/5), (-peaks/4)), mglPoint(-(tmax/5), (peaks/4)), "Signal S(t)");
			gr.Puts(mglPoint( (tmax)/2, -0.5), "t");
			gr.Plot(t_mgl, s_mgl);
			
			//trying to make adaptive filenames
			string temp1="signal_"+label+"_step15.eps";
			int m=temp1.length();
			char char_array1[m+1];
			strcpy(char_array1,temp1.c_str());
			//adaptive filename 2
			string temp2="signal_"+label+"_step15.png";
			int g=temp2.length();
			char char_array2[g+1];
			strcpy(char_array2,temp2.c_str());
			
			gr.WriteEPS(char_array1);
			gr.WritePNG(char_array2);
		}
		*/
//xxxxxxxxx 

//part 10
	void Signal::sinusoid(double Amp, double f1,double phi)
		{
			
			for (int i=0;i<samples;i++)
				{
					signal[i]=Amp*cos(2*M_PI*f1*time[i]+phi);
				}
			set_math(textNum(Amp)+"cos("+textNum(f1)+"t"+"+"+textNum(phi)+")");
			
		}
//xxxxxxxx

//part 11
	void Signal::rounder()
		{
			for(int i=0;i<samples;i++)
			{
				signal[i]=round(signal[i]);
			}
		}
//xxxxxxx

//part 12
	Signal Signal::operator + (const Signal &right)//operator overload
		{
			if (this!=&right)//adding
				{					
					if(samples==right.samples&&f==right.f&&t0==right.t0)
						{
							for(int i=0;i<samples;i++)
								{
									signal[i]=signal[i]+right.signal[i];
								}
							time=right.time;
						}
				}
			else//exit code
				{
					std::cout<<"ERROR! Attempt to add incompatible signals.";
					exit(1);
				}
			std::string l=math;
			std::string r=right.math;
			std::string fin=l+" + "+r;
			math=fin;
			return *this;
		}	
//xxxxxxxxx

//step 15
		Signal Signal::operator * (const Signal &right)
			{
			if (this!=&right)//adding
				{					
					if(samples==right.samples&&f==right.f&&t0==right.t0)
						{
							for(int i=0;i<samples;i++)
								{
									signal[i]=signal[i]*right.signal[i];
								}
							time=right.time;
						}
				}
			else//exit code
				{
					std::cout<<"ERROR! Attempt to multiply incompatible signals.";
					exit(1);
				}
			std::string l=math;
			std::string r=right.math;
			std::string fin="("+l+")"+"("+r+")";
			math=fin;
			return *this;
			}	
//ica 13 start::
		void Signal::expfill(double tau, double A)//fills with exponential signal
			{
				double t, power;
				std::string comp;
				for (int i=0;i<samples;i++)
				{
					t=time[i];
					power=-(t-t0)/tau;
					signal[i]=A*exp(power);
				}
				
			if (tfix>0)
				{
				set_math(textNum(A) + " exp( -(t + " + textNum(tfix) + ") / "+textNum(tau)+" )");
				}
			if (tfix<0)
				{
				set_math(textNum(A) + " exp( -(t + " + textNum(-1*tfix) + ") / "+textNum(tau)+" )");
				}
			if (tfix==0)
				{
				set_math(textNum(A) + " exp( -t )");
				}
			

			}
	
				
