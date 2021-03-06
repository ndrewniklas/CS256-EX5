//Andrew Niklas
//Exercise 5
//Completed 2/5/2016


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
	void reduce();
public:
	rat();
	rat(int n);
	rat(int n, int d);
	int getNum() const;
	int getDen() const;
	rat reciprocal() const;
	
	rat operator+(const rat& right) const;
	rat operator-(const rat& right) const;
	rat operator*(const rat& right) const;
	rat operator/(const rat& right) const;
	
	bool operator==(const rat& right) const;
	bool operator<(const rat& right) const;
	bool operator!=(const rat& right) const;
	bool operator>(const rat& right) const;
	bool operator>=(const rat& right) const;
	bool operator<=(const rat& right) const;
	
	std::string str() const;
   
};

#endif