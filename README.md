# Test-case-generators
This repository contains codes for generating some random test cases which can be used for generating test cases for coding competitions, testing efficiency of your algorithms etc.

All the test case generators are written in C++. The codes are fully commented for easy usage of the codes. Also a readme file describing the code and the tweaking you could do with the code is given algonside.

All the test case generators also have a checker implemented inside them which checks whether all the test case data generated is according to the constraints you set above in the code or not. By default, output file name is set to "inp.txt". To change it you can change the name of file on line having the function "freopen" written on it. 

In case of any wrong generation of data, it simply throws an "SIGABRT" error. If you encounter this, or any type of segmentation fault while using any of these files, do report the error (and preferably screenshot) so that the code can be updated for further use. 

Feel free to contribute to the repository as well.