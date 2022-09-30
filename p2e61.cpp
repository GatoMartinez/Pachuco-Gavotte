#include "fulljacobi.hpp"
#include "create_tridiag.hpp"
using namespace arma;
int main(){

	std::string filename = "p26_n100.txt";
	std::ofstream ofile;
  	ofile.open(filename);

	double n=100;
	double N=n-1;
	double h= 1.0/double(N+1);
	vec a= vec(N-1).fill(-1.0/pow(h,2));
	vec d= vec(N).fill(2.0/pow(h,2));
	mat A= tridiag(a,d,a); 
	
	double eps = pow(10,-3);
	jacobi_eigensolver(A,iter,eps,eval,evec);
	
	uvec evalordered;
	evalordered= sort_index(eval, "ascend");
	
		
		
	int width= 12;
	int prec= 4;
		
	for (int i=0; i<N; i++){
		
		
		ofile << std::setw(width) << std::setprecision(prec) << std::scientific << eval(evalordered(i))
	    	  	<< std::setw(width) << std::setprecision(prec) << std::scientific << evec(i,evalordered(0))
	    	  	<< std::setw(width) << std::setprecision(prec) << std::scientific << evec(i,evalordered(1))
	    	  	<< std::setw(width) << std::setprecision(prec) << std::scientific << evec(i,evalordered(2))
	        	<< std::endl;
		
		}	
	ofile.close();
		
		
		
	return 0;
}
