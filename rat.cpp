#include "rat.h"

// These functions can be useful for calculations with fractions
int gcd(int x, int y)
{
    if (y == 0) 
        return x;
    return gcd(y, x % y);
}

int lcm(int x, int y)
{
    return (x * y) / gcd(x, y);
}

// Put your function implementations here

rat::rat()
	:num(0), den(1)
{ }

rat::rat(int n)
	:num(n), den(1)
{ }

rat::rat(int n, int d)
	:num(n), den(d)
{
	if(den == 0){
		num = 0;
		den = 1;
	}
	rat::reduce();
}

int rat::getNum() const{
	return num;
}

int rat::getDen() const{
	return den;
}

void rat::reduce(){
	int g = gcd(num, den);
	num /= g;
	den /= g;
	if(den < 0){
		num = -num;
		den = -den;
	}
}

rat rat::reciprocal() const{
	return rat(den, num);
}

rat rat::operator+(const rat& right) const{
	int numN = this->num * right.den;
	numN += (this->den * right.num);
	int denN = this->den * right.den;
	return rat(numN, denN);
}

rat rat::operator-(const rat& right) const{
	rat temp = rat(-right.num, right.den);
	return *this + temp;
}

rat rat::operator*(const rat& right) const{
	int numN = this->num * right.num;
	int denN = this->den * right.den;
	return rat(numN, denN);
}

rat rat::operator/(const rat& right) const{
	return *this * right.reciprocal();
}

bool rat::operator==(const rat& right) const{
	if(this->num == right.num){
		if(this->den == right.den){
			return true;
		}
		return false;
	}
	return false;
}

bool rat::operator<(const rat& right) const{
	if(this->num < right.num){
		if(this->den > right.den){
			return true;
		}else if(this->den == right.den){
			return true;
		}
		return false;
	}else if(this->num > right.num){
		if(this->den > right.den){
			return true;
		}
		return false;
	}else{ //num == num
		if(this->den > right.den){
			return true;
		}else if(this->den == right.den){
			return false;
		}
		return false;
	}
	return false;
}

bool rat::operator!=(const rat& right) const{
	return !(*this == right);
}

bool rat::operator>(const rat& right) const{
	if(!(*this == right)){
		return !(*this < right);
	}
	return false;
}

bool rat::operator>=(const rat& right) const{
	if((*this == right) && (*this > right)){
		return true;
	}
	return false;
}

bool rat::operator<=(const rat& right) const{
	if((*this == right) && (*this < right)){
		return true;
	}
	return false;
}

std::string rat::str() const{
	std::stringstream ss;
	ss << this->num << '/' << this->den;
	return ss.str();
}











