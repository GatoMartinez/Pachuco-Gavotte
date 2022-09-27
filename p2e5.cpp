#include "fulljacobi.hpp"
#include "create_tridiag.hpp"



int main(){

	std::string filename = "n_iter.txt";
	std::ofstream ofile;
  	ofile.open(filename);
	
	int width= 16;
	int prec= 6;
	
	for(int i=1;i<=12;i++){
		int N1=2*i*10;
		arma::mat A=const_diag_matrix(N1);
		jacobi_eigensolver(A,iter,eps,eval,evec);
		std::cout<<iter<<std::endl;
		ofile << std::setw(width) << std::setprecision(prec) << std::scientific << N1
	    	  		<< std::setw(width) << std::setprecision(prec) << std::scientific << iter
	          		<< std::endl;
		}
		
	ofile.close();
	
	return 0;
}
		
	

