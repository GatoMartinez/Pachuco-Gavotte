#include "fulljacobi.hpp"
#include "create_tridiag.hpp"

int main(){

	int width= 12;
	int prec= 4;
	std::string filename = "analyticaln100.txt";
	std::ofstream ofile;
  	ofile.open(filename);
	double pi=M_PI;
	double n=100;
	double N=n-1;
	double h= 1.0/double(N+1);
	arma::vec a= arma::vec(N-1).fill(-1.0/pow(h,2));
	arma::vec d= arma::vec(N).fill(2.0/pow(h,2));
	arma::mat A= tridiag(a,d,a); 
	
	double eps = pow(10,-3);
	arma::mat S;
	for (int i=0; i<N; i++){
		int j=i+1;
		
		arma::vec analevec= arma::vec(N);
		for (int k=1; k<=N; k++){
			analevec(k-1)=std::sin(j*k*pi/(N+1));
			}
		
		S.insert_cols(i,analevec);
		
		}
		
	for (int i=0; i<N; i++){
	
		ofile << std::setw(width) << std::setprecision(prec) << std::scientific << S(i,0)
			<< std::setw(width) << std::setprecision(prec) << std::scientific << S(i,1)
			<< std::setw(width) << std::setprecision(prec) << std::scientific << S(i,2)
			<< std::endl;
	}
	ofile.close();
	
	
	return 0;
	}
