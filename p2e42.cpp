#include "fulljacobi.hpp"
#include "create_tridiag.hpp"

int main(){

	arma::mat A= const_diag_matrix(6)
	
	jacobi_eigensolver(A,iter,eps,eval,evec);
	
	int N=A.n_cols;
	
	for (int i=0;i<N;i++){
		std::cout << eval(i)<<" , " << evec.col(i)  <<std::endl;
		}
	return 0;
}


