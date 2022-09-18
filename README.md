# Pachuco-Gavotte
This GitHub repo has been created in order to give a solution to the problems given in Project 1 of the course FYS3150: Computational Physics. \\

The repo contains 5 main files:

-"project1.pdf", which is a LaTeX document that contains all of the solutions and figures concerning Project 1.

-"P2program.cpp". This is a.cpp file with the program that writes a certain amount of values of x and the value of the solution u(x) at such points into a .txt file which can be used in python to plot the function.

-"P6program.hpp". This is a header file that contains the code for the General Algorithm that appears in Problem 6.

-"P7program.cpp". This one is a .cpp file which applies the General Algorithm to the specific problem set in Problem 4 and stores the values of x_i and v_i in a .txt file which can then be imported to python in order to produce the plots that are displayed in problems 7 and 8. For this last one, as the values of the exact analytic function in the points x_i are needed, you must define such function in python and then evaluate it at the x_i points that are already stored in the .txt file. The number of steps in our discretization must be introduced as a command-line input when executing the program in the terminal, and the name of the output file must be changed inside the "P6program.hpp" file (line 14) before doing so for every number of steps that we want to use.

-"P9program.hpp". This is another header file which, in this case, contains the Special ALgorithm from Problem 9.
