#include "Folhdeccic.h"
#include <iostream>
int main()

{
	std::ofstream access("ECE 0301 - Differential Equation Reports.txt");
	//after opening an output file define objects corresponding to prolbme
/*step 7
	Folhdeccic one;
	one.header(access);
	one.DPrint(access);
	Folhdeccic two(-2.5,10,1);
	two.setlabel("x");
	two.header(access);
	two.DPrint(access);
	return 0;
 end step 7 */
 
// step 8
	Folhdeccic one(-1.25,2,120);
	one.setlabel("x");
	one.header(access);
	one.DPrint(access);
}

