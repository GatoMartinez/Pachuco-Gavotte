#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip>


double l( std::vector<double> g, double x_min, double x_max);
double l( std::vector<double> g,double x_min, double x_max){
	int m= g.size()-1;
	
	
	std::string filename = ""; //This is the table where we will store the values of x and v_i
	std::ofstream ofile;
  	ofile.open(filename);
	
	
	std::vector<double> v(m+1);
	std::vector<double> b1(m+1);
	std::vector<double> g1(m+1);
	
	
	if (a.size()!=c.size() or b.size()-a.size()!=1 or b.size()!=g.size()){    //This part of the code is run to make sure that the data have been introduced correcticly
	
		std::cout << "The equality is not possible\n";
		return 0;
	}
	else {	
		b1[0]=2;
		g1[0]=g[0];
		for (int i = 1 ; i <= m ; i++){
		
			b1[i]= 2-(1.0/b1[i-1]);                  //For loop that redefines the values of b and g after performing the Gauss elimination method
			
			g1[i]= g[i]+(1.0/b1[i-1])*g1[i-1];
			
			}
			
		v[m]= g1[m]/b1[m];
		
		for (int i = 1; i <=m; i++){
			
			int j=m-i;                                             //Another for loop that, in this case, computes the values of the different v_i
			v[j]= (g1[j]+v[j+1])/b1[j];
			}
	
		
		int width= 16;
		int prec= 6;
		
		for (int i=1; i<=m+1; i++){
			
			double a= x_min+i*(x_max-x_min)/(m+2);               //All of the indexes in this program are chosen in order to leave the boundary points out of the solution
			double c= v[i-1];
			ofile << std::setw(width) << std::setprecision(prec) << std::scientific << a
	    	  		<< std::setw(width) << std::setprecision(prec) << std::scientific << c 
	          		<< std::endl;
		}
			
		ofile.close();
		return 0;		
	}
}
