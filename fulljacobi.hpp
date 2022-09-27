#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <armadillo>




std::map<std::string,double> max_offdiag_symmetric(const arma::mat A){

	int n = A.n_cols;
	
	std::map<std::string,double> out;
	std::vector<double> v1(1);
	v1[0]=0;
	std::vector<double> v2(1);
	std::vector<double> v3(1);
	for (int i=0; i<n-1; i++){
		for (int j=i+1; j<n; j++){
			double a= std::abs(A(i,j));
			if (a>v1[v1.size()-1]){
				v1.push_back(a);
				v2.push_back(i);
				v3.push_back(j);
			
			}
			
		}
		
	}
	
        out["maxval"] = v1[v1.size()-1];
        out["row"]=v2[v2.size()-1]; 
        out["col"]=v3[v3.size()-1]; 
           
	return out;


}




double jacobi_rotate(arma::mat& A, arma::mat& R, double& k, double& l){
	
	 int n = A.n_cols;
	 
	 double tau= (A(l,l)-A(k,k))/(2*A(k,l));
         double t;
	 if (tau>=0){
	 	t= -tau+std::sqrt(1+pow(tau,2));
	 }
	 else {
	 	t= -tau-std::sqrt(1+pow(tau,2));
	 }
	 double c= 1/(std::sqrt(1+pow(t,2)));
	 double s= c*t;
	 	
	 double Ak=A(k,k);	
	 A(k,k)= A(k,k)*pow(c,2)-2*A(k,l)*c*s+A(l,l)*pow(s,2);
	 A(l,l)= A(l,l)*pow(c,2)+2*A(k,l)*c*s+Ak*pow(s,2);
	 A(k,l)=0;
	 A(l,k)=0;
	 	
	 for (int i=1; i<n; i++){
	 	if (i!=k and i!=l){
	 		double a;
	 		a=A(i,k)*c-A(i,l)*s;
	 		A(i,l)=A(i,l)*c+A(i,k)*s;
	 		A(l,i)=A(i,l);
	 		A(i,k)=a;
	 		A(k,i)=A(i,k);
	 		}
	 	}
	 	
	 
	 	
	 for (int i=0; i<n; i++){
	 	double Rl1= R(i,l);
	 	R(i,l)=R(i,l)*c+R(i,k)*s;
	 	R(i,k)=R(i,k)*c-Rl1*s;
	 }
	 
	 std::map<std::string, double> v = max_offdiag_symmetric(A);
	 k= v["row"];
	 l= v["col"];
	 double maxval = v["maxval"];
	 
	 return maxval; 
	 }
	 
	 





void jacobi_eigensolver(arma::mat& A, int& iter, double eps, arma::vec& eval, arma::mat& evec){

	int N= A.n_cols;
	
	arma::mat R= arma::mat(N,N).fill(0.);
	
	for(int i=0;i<N;i++){
		R(i,i)=1;
		}
	
	std::map<std::string, double> v = max_offdiag_symmetric(A);
	double k= v["row"];
	double l= v["col"];
	
	iter=0;
	double m= 1.;
	
	while (m > eps){
		m=jacobi_rotate(A,R,k,l);
		iter++;
		}
	
	eval=arma::vec(N).fill(0.);
	evec=R;
	
	for (int i=0; i<N; i++){
		eval(i)= A(i,i);
		}
}



arma::vec eval;
arma::mat evec;
int iter;
double eps=pow(10,-3);







