#ifndef RAT_H
#define RAT_H

#include <iostream>
#include <string>
#include <sstream>

class RatTester;

class rat
{
    friend class RatTester;

private:
    int num;
	int den;
public:
	rat();
	rat(int n);
	rat(int n, int d);
   
};

#endif