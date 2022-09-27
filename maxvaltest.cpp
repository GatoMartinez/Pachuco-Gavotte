#include "fulljacobi.hpp"

int main(){

	arma::mat A= arma::mat(4,4).fill(0.);
	A(0,0)= 1;
	A(1,1)= 1;
	A(2,2)= 1;
	A(3,3)= 1;
	A(2,1)= -0.7;
	A(1,2)= -0.7;
	A(0,3)= 0.5;
	A(3,0)= 0.5;
	
	std::map<std::string,double> v=max_offdiag_symmetric(A);
	
	double maxval= v["maxval"];
	double k= v["row"];
	double l= v["col"];
	
	std::cout << "The maximum value of any element outside the diagonal is: " << maxval << " , which is located in the row " << k+1 << " and column " << l+1 <<std::endl;
	
	return 0;
}
