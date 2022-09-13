#include "P6program.hpp"


double f( double x){

	return 100*exp(-10*x);
}

int main(int argc, char* argv[]){
	
	auto t1 = std::chrono::high_resolution_clock::now();
	
	int n = atoi(argv[1]);                  //The command input line is the number of steps that our solution will have
	
	
	
	double xmin=0.0;
	double xmax=1.0;
	double u0=0.0;
	double u1=0.0;
	double h= (xmax-xmin)/((double) n;

	std::vector<double> a(n-2,-1.0);
	std::vector<double> b(n-1,2.0);      //If the domain is divided into n steps, the number of points in our solution is n+1. However, we are leaving the boundary points out of this.
	std::vector<double> c(n-2, -1.0);
	
	std::vector<double> x(n-1);
	std::vector<double> g(n-1);
	
	
	for (int i=1; i<=n-1; i++){
	
		x[i-1]= xmin+h*i;
	
	}

	g[0]=pow(h,2)*x[0]+u0;
	g[n-2]=pow(h,2)*x[n]+u1;
	
	
	for (int i=1; i<n-2; i++){
	
		g[i]=pow(h,2)*f(x[i]);		
	
	}
	
	l(a,b,c,g,xmin, xmax, n);
	auto t2 = std::chrono::high_resolution_clock::now();
	double duration_seconds = std::chrono::duration<double>(t2 - t1).count();
	std::cout<< duration_seconds <<std::endl;
	return 0;
}
