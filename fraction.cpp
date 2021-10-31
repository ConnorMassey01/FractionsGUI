#include "fraction.h"

using namespace std;

//---------------implementation of FractionException class methods-----------------
FractionException::FractionException(const string& errorMessage){
    message = errorMessage;
}
string& FractionException::what(){
    return message;
}

//-------------------implementation of Fraction class methods----------------------
Fraction::Fraction(){
    num = 0;
    denom = 1;
}
Fraction::Fraction(int numerator){
    num = numerator;
    denom = 1;
}
Fraction::Fraction(int numerator, int denominator){
    if(denominator == 0){
        throw FractionException("denominator can't be zero");
    }
    else{
        int negativeNumbers = 0;
        int gcd;
        //make the numerator and denominator positive values
        if(numerator < 0){
            negativeNumbers++;
            numerator *= -1;
        }
        if(denominator < 0){
            negativeNumbers++;
            denominator *= -1;
        }
        //find the greatest common denominator
        if(numerator != 0){
            gcd = GCD(numerator, denominator);
        }
        else{
            gcd = 1;
        }
        //assign the numerator with the correct sign
        if(negativeNumbers == 1){
            num = -numerator/gcd;
        }
        else{
            num = numerator/gcd;
        }
        //assign the value of the denominator
        denom = denominator/gcd;
    }
}

Fraction::Fraction(string input){
    //get data from the input string
    int numerator = 0, denominator = 1;
    if(input.find('/') != string::npos){
        string n = input.substr(0, input.find('/'));
        //convert string to int
        numerator = stoi(n);
        string d = input.substr(input.find('/') + 1, input.length());
        //convert string to int
        denominator = stoi(d);
    }
    else{
        numerator = stoi(input);
    }
    //create the fraction
    if(denominator == 0){
        throw FractionException("denominator can't be zero");
    }
    else{
        int negativeNumbers = 0;
        int gcd;
        //make the numerator and denominator positive values
        if(numerator < 0){
            negativeNumbers++;
            numerator *= -1;
        }
        if(denominator < 0){
            negativeNumbers++;
            denominator *= -1;
        }
        //find the greatest common denominator
        if(numerator != 0){
            gcd = GCD(numerator, denominator);
        }
        else{
            gcd = 1;
        }
        //assign the numerator with the correct sign
        if(negativeNumbers == 1){
            num = -numerator/gcd;
        }
        else{
            num = numerator/gcd;
        }
        //assign the value of the denominator
        denom = denominator/gcd;
    }
}

int Fraction::numerator() const{
    return num;
}
int Fraction::denominator() const{
    return denom;
}
int Fraction::GCD(int n, int m){
    if(m <= n && n % m == 0){
        return m;
    }
    else if(n < m){
        return GCD(m, n);
    }
    else{
        return GCD(m, n % m);
    }
}
//-----------------implementation of operators for fractions----------------------
ostream& operator<<(ostream& out, const Fraction& fraction) {
    out << fraction.numerator() << "/" << fraction.denominator();
    return out;
}
istream& operator>>(istream& in, Fraction& fraction){
    int numerator = 0, denominator = 1;
    string line;
    in >> line;
    if(line.find('/') != string::npos){
        string n = line.substr(0, line.find('/'));
        //convert string to int
        numerator = stoi(n);
        string d = line.substr(line.find('/') + 1, line.length());
        //convert string to int
        denominator = stoi(d);
    }
    else{
        numerator = stoi(line);
    }

    Fraction input(numerator, denominator);
    fraction = input;
    return in;
}
Fraction operator+(const Fraction& left, const Fraction& right){
    int top = (left.numerator() * right.denominator()) + (right.numerator() * left.denominator());
    int bottom = left.denominator() * right.denominator();
    Fraction result(top, bottom);
    return result;
}
Fraction operator-(const Fraction& left, const Fraction& right){
    int top = (left.numerator() * right.denominator()) - (right.numerator() * left.denominator());
    int bottom = left.denominator() * right.denominator();
    Fraction result(top, bottom);
    return result;
}
Fraction operator-(const Fraction& right){
    Fraction result(-right.numerator(), right.denominator());
    return result;
}
Fraction operator*(const Fraction& left, const Fraction& right){
    Fraction result(left.numerator() * right.numerator(), left.denominator() * right.denominator());
    return result;
}
Fraction operator/(const Fraction& left, const Fraction& right){
    Fraction result(left.numerator() * right.denominator(), left.denominator() * right.numerator());
    return result;
}
//prefix increment operator
Fraction operator++(Fraction& fraction){
    Fraction result = fraction + 1;
    fraction = fraction + 1;
    return result;
}
//postfix increment operator
Fraction operator++(Fraction& fraction, int){
    Fraction result = fraction;
    fraction = fraction + 1;
    return result;
}
Fraction operator+=(Fraction& left, const Fraction& right){
    left = left + right;
    return left;
}
bool operator==(const Fraction& left, const Fraction& right){
    return (left.numerator() == right.numerator()) && (left.denominator() == right.denominator());
}
bool operator!=(const Fraction& left, const Fraction& right){
    return (left.numerator() != right.numerator() || left.denominator() != right.denominator());
}
bool operator<(const Fraction& left, const Fraction& right){
    float leftValue = (float)left.numerator()/left.denominator();
    float rightValue = (float)right.numerator()/right.denominator();
    return (leftValue < rightValue);
}
bool operator>(const Fraction& left, const Fraction& right){
    float leftValue = (float)left.numerator()/left.denominator();
    float rightValue = (float)right.numerator()/right.denominator();
    return (leftValue > rightValue);
}
bool operator<=(const Fraction& left, const Fraction& right){
    float leftValue = left.numerator()/left.denominator();
    float rightValue = right.numerator()/right.denominator();
    return (leftValue <= rightValue);
}
bool operator>=(const Fraction& left, const Fraction& right){
    float leftValue = left.numerator()/left.denominator();
    float rightValue = right.numerator()/right.denominator();
    return (leftValue >= rightValue);
}
