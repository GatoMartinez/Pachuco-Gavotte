#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <armadillo>

arma::mat cre_trid (arma::vec a, arma::vec b, arma::vec c){
	int m= a.size();
	arma::mat A= arma::mat(m+1,m+1);
	if(b.size()- m !=1 or m !=c.size()){
		std::cout << "The matrix's data haven't been introduced correctly \n" << std::endl;
		arma::mat r= arma::mat(2,2).fill(0.);
		return r;
		}
		
	else {
		for (int i=0; i<m ;i++){
			A(i,i)=b(i);
			A(i+1,i)=a(i);
			A(i,i+1)=c(i);
			}
		A(m,m)=b(m);
		return A;
		}
	
	
}


arma::mat const_diag_matrix(int N){

	double h=1./(N+1);
	double a=-1./pow(h,2);
	double d=2./pow(h,2);
	
	arma::vec subd=arma::vec(N-1).fill(a);
	arma::vec supd=subd;
	arma::vec diag=arma::vec(N).fill(d);
	
	arma::mat A=cre_trid(subd,diag,supd);
	
	return A;
}



