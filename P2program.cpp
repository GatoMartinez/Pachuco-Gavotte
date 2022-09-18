#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip>

double u(double x); 

double u(double x){
    return 1-(1-exp(-10))*x-exp(-10*x);
}
int main() {
    
	std::string filename = "valores.txt";
	std::ofstream ofile;
  	ofile.open(filename);


	int width= 12;
	int prec= 4;

	for (size_t i = 0; i <= 100; i++){
    
	    double a= i*(1.0/100.0);
	    double c= u(a);
	    ofile << std::setw(width) << std::setprecision(prec) << std::scientific << a
	    	  << std::setw(width) << std::setprecision(prec) << std::scientific << c 
	          << std::endl;
	    
	    
	
	}

	ofile.close();
	return 0;
}
