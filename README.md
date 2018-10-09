# C-python interface for generating correlated random numbers (normal distribution)
Hybrid C-python project

----
Compile:
g++ -std=c++14 test_Randc.c -I/usr/include/python2.7 -lpython2.7
----
Content:
test_Randc.c : C++ main() function;
get_rand.py  : python function that generate random number with (0,1) distribution and correlation coefficients;

-----
Environment:
Python 2.7; Ubuntu 16.04LTS;
