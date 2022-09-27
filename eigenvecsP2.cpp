#include "create_tridiag.hpp"


double pi=M_PI;

int main(){


	arma::mat A= const_diag_matrix(6);
	
	
	
	std::cout << A << std::endl;
	
	arma::vec eigval;
	arma::mat eigvec;
	arma::eig_sym(eigval,eigvec,A);
	
	
	int N= eigval.size();
	
	std::string filename = "analeig.txt";
	std::ofstream ofile;
  	ofile.open(filename);
  	
  	int width= 25;
	int prec= 7;
	
	std::string aval= "Analytic eigenvalue";
	std::string avec= "Analytic eigenvector";
	std::string pval= "Program's eigenvalue";
	std::string pvec= "Program's eigenvector";
	
	double h=1./(N+1);
	double a=-1./pow(h,2);
	double d=2./pow(h,2);
	
	for (int i=0; i<N; i++){
		int j=i+1;
		double analeval= d+2*a*std::cos(j*pi/(N+1));
		double eval= eigval(i);
		arma::vec analevec= arma::vec(N);
		for (int k=1; k<=N; k++){
			analevec(k-1)=std::sin(j*k*pi/(N+1));
			}
		arma::vec analevec1= arma::normalise(analevec);
		arma::vec evec= eigvec.col(i);
		arma::mat B= arma::mat(N,0);
		B.insert_cols(0,analevec1);
		B.insert_cols(1,evec);
		
		ofile << std::setw(width) << std::setprecision(prec) << aval << std::setw(width) << std::setprecision(prec) << pval << std::endl;
		ofile << std::setw(width) << std::setprecision(prec) << std::scientific << analeval << std::setw(width) << std::setprecision(prec) << std::scientific << eval << std::endl;
		ofile << std::setw(width) << std::setprecision(prec) << avec <<  std::setw(width) << std::setprecision(prec) << pvec << std::endl;
		
		for (int k=0;k<n;k++){
			ofile << std::setw(width) << std::setprecision(prec) << std::scientific << analevec1[k] << std::setw(width) << std::setprecision(prec) << std::scientific << evec[k] << std::endl;
			}
		
		//std::cout << "analytic eigenvalue= \n" << analeval << "," << "program's eigenvalue= \n" << eval << std::endl;
		//std::cout << "analytic eigenvector // program's eigenvector \n";
		//std::cout << B << std::endl;
		}
	
	return 0;





}
