//
// Created by Charlton on 5/19/16.
//

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class fraction {
    int denom;
    int num;
public:

    fraction(int num, int denom);
    fraction(int num);
    fraction();

    int getNumerator() const;
    int getDenominator() const;
    double convert() const;
    bool canReduce();
    void reduce();


    friend std::ostream &operator<<(std::ostream &os, const fraction &f) {
        if (f.getDenominator() == 0) return os << "undefined";
        else if (f.getDenominator() == 1) return os << f.getNumerator();
        else return os << f.getNumerator() << '/' << f.getDenominator();
    }

    friend std::istream &operator>>(std::istream &in, fraction &f) {
        std::string s;
        in >> s;
        unsigned long index = s.find('/', 0);
        if (index != -1) {
            f.num = stoi(s.substr(0, index));
            f.denom = stoi(s.substr(index + 1, s.length()));
        } else {
            f.num = stoi(s);
        }
        return in;
    }

    fraction operator*(const int &integer);
    fraction operator*=(const int &integer);
    fraction operator/(const int &integer);
    fraction operator/=(const int &integer);
    fraction operator+(const int &integer);
    fraction operator-(const int &integer);
    fraction operator+=(const int &integer);
    fraction operator-=(const int &integer);
    fraction operator*(const fraction &f);
    fraction operator*=(const fraction &f);
    fraction operator/(const fraction &f);
    fraction operator/=(const fraction &f);
    fraction operator+(const fraction &f);
    fraction operator-(const fraction &f);
    fraction operator+=(const fraction &f);
    fraction operator-=(const fraction &f);

    bool operator<(const fraction &f);
    bool operator==(const fraction &f);
    bool operator<=(const fraction &f);
    bool operator>(const fraction &f);
    bool operator>=(const fraction &f);
    bool operator!=(const fraction &f);

private:
    bool hasSameBase(int denom, int denom2);
    bool isFactor(int n1, int n2);
    bool getLCD(int denom, int denom2, int *m1, int *m2);
    int multiplyBy(int n1, int n2);
    int getGCD(int num, int denom);
    int getGCD();
};


#endif //FRACTION_H
