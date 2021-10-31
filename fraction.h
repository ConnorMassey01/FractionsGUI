#ifndef FRACTION_H
#define FRACTION_H

#include "Fraction_global.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class FRACTION_EXPORT FractionException {
public:
    //constructor to initialize the string message
    FractionException(const string& errorMessage);
    //function that returns the message to display
    string& what();
private:
    string message;
};

class FRACTION_EXPORT Fraction
{
public:
    //constructor methods
    Fraction();
    Fraction(int numerator);
    Fraction(int numerator, int denominator);
    Fraction(string input);
    //accessor methods
    int numerator() const;
    int denominator() const;
    //returns the greatest common denominator of n and m
    int GCD(int n, int m);
private:
    //variables to hold the numerator and denominator
    int num;
    int denom;
};

ostream& operator<<(ostream& out, const Fraction& fraction);
istream& operator>>(istream& in, Fraction& fraction);
FRACTION_EXPORT Fraction operator+(const Fraction& left, const Fraction& right);
FRACTION_EXPORT Fraction operator-(const Fraction& left, const Fraction& right);
FRACTION_EXPORT Fraction operator-(const Fraction& right);
FRACTION_EXPORT Fraction operator*(const Fraction& left, const Fraction& right);
FRACTION_EXPORT Fraction operator/(const Fraction& left, const Fraction& right);
//prefix increment operator
FRACTION_EXPORT Fraction operator++(Fraction& fraction);
//postfix increment operator
FRACTION_EXPORT Fraction operator++(Fraction& fraction, int);
FRACTION_EXPORT Fraction operator+=(Fraction& left, const Fraction& right);
bool operator==(const Fraction& left, const Fraction& right);
bool operator!=(const Fraction& left, const Fraction& right);
bool operator<(const Fraction& left, const Fraction& right);
bool operator>(const Fraction& left, const Fraction& right);
bool operator<=(const Fraction& left, const Fraction& right);
bool operator>=(const Fraction& left, const Fraction& right);


#endif // FRACTION_H
