//
// Created by Charlton Smith on 5/19/16.
//

#include "fraction.h"

fraction::fraction(int num, int denom) {
    if (denom < 0 && num > 0) {
        num *= -1;
        denom *= -1;
    } else if (denom < 0 && num < 0) {
        num *= -1;
        denom *= -1;
    }
    this->num = num;
    this->denom = denom;

}

fraction::fraction(int num) {
    this->num = num;
    this->denom = 1;
}

int fraction::getNumerator() const {
    return num;
}

int fraction::getDenominator() const {
    return denom;
}

void fraction::reduce() {
    int gcf = getGCD();
    num = num / gcf;
    denom = denom / gcf;
}

bool fraction::canReduce() {
    return getGCD() != 1;
}

double fraction::convert() const {
    return (double) num / double(denom);
}

fraction::fraction() {
    this->num = 0;
    this->denom = 1;
};

fraction fraction::operator*(const int &integer) {
    fraction f(integer);
    int nnum = this->num * f.num;
    int ddenom = this->denom * f.denom;
    fraction t(nnum, ddenom);
    t.reduce();
    return t;
}

fraction fraction::operator*=(const int &integer) {
    fraction f(integer);
    this->num *= f.num;
    this->denom *= f.denom;
    this->reduce();
    return *this;
}

fraction fraction::operator/(const int &integer) {
    fraction f(integer);
    int nnum = this->num * f.denom;
    int ddenom = this->denom * f.num;
    fraction t(nnum, ddenom);
    t.reduce();
    return t;
}

fraction fraction::operator/=(const int &integer) {
    fraction f(integer);
    this->num *= f.denom;
    this->denom *= f.num;
    this->reduce();
    return *this;
}

fraction fraction::operator+(const int &integer) {
    fraction f(integer);
    int nnum = 1, ddenom = 1;
    if (hasSameBase(this->denom, f.denom)) {
        nnum = this->num + f.num;
        ddenom = this->denom;
    } else {
        if (isFactor(this->denom, f.denom)) {
            if (this->denom > f.denom) {
                ddenom = this->denom;
                int small = multiplyBy(this->denom, f.denom);
                int fnum = f.num * small;
                nnum = this->num + fnum;
            } else if (this->denom < f.denom) {
                ddenom = f.denom;
                int small = multiplyBy(this->denom, f.denom);
                int tnum = this->num * small;
                nnum = f.num + tnum;
            }
        } else {
            int tm, fm;
            if (getLCD(this->denom, f.denom, &tm, &fm)) {
                nnum = this->num * tm + f.num * fm;
                ddenom = this->denom * tm;
            }
        }
    }
    fraction t(nnum, ddenom);
    t.reduce();
    return t;
}

fraction fraction::operator-(const int &integer) {
    fraction f(integer);
    int nnum = 1, ddenom = 1;
    if (hasSameBase(this->denom, f.denom)) {
        nnum = this->num - f.num;
        ddenom = this->denom;
    } else {
        if (isFactor(this->denom, f.denom)) {
            if (this->denom > f.denom) {
                ddenom = this->denom;
                int small = multiplyBy(this->denom, f.denom);
                int fnum = f.num * small;
                nnum = this->num - fnum;
            } else if (this->denom < f.denom) {
                ddenom = f.denom;
                int small = multiplyBy(this->denom, f.denom);
                int tnum = this->num * small;
                nnum = tnum - f.num;
            }
        } else {
            int tm, fm;
            if (getLCD(this->denom, f.denom, &tm, &fm)) {
                nnum = this->num * tm - f.num * fm;
                ddenom = this->denom * tm;
            }
        }
    }
    fraction t(nnum, ddenom);
    t.reduce();
    return t;
}

fraction fraction::operator+=(const int &integer) {
    fraction f(integer);
    int nnum = 1, ddenom = 1;
    if (hasSameBase(this->denom, f.denom)) {
        nnum = this->num + f.num;
        ddenom = this->denom;
    } else {
        if (isFactor(this->denom, f.denom)) {
            if (this->denom > f.denom) {
                ddenom = this->denom;
                int small = multiplyBy(this->denom, f.denom);
                int fnum = f.num * small;
                nnum = this->num + fnum;
            } else if (this->denom < f.denom) {
                ddenom = f.denom;
                int small = multiplyBy(this->denom, f.denom);
                int tnum = this->num * small;
                nnum = f.num + tnum;
            }
        } else {
            int tm, fm;
            if (getLCD(this->denom, f.denom, &tm, &fm)) {
                nnum = this->num * tm + f.num * fm;
                ddenom = this->denom * tm;
            }
        }
    }
    this->num = nnum;
    this->denom = ddenom;
    this->reduce();
    return *this;
}

fraction fraction::operator-=(const int &integer) {
    fraction f(integer);

    int nnum = 1, ddenom = 1;
    if (hasSameBase(this->denom, f.denom)) {
        nnum = this->num - f.num;
        ddenom = this->denom;
    } else {
        if (isFactor(this->denom, f.denom)) {
            if (this->denom > f.denom) {
                ddenom = this->denom;
                int small = multiplyBy(this->denom, f.denom);
                int fnum = f.num * small;
                nnum = this->num - fnum;
            } else if (this->denom < f.denom) {
                ddenom = f.denom;
                int small = multiplyBy(this->denom, f.denom);
                int tnum = this->num * small;
                nnum = tnum - f.num;
            }
        } else {
            int tm, fm;
            if (getLCD(this->denom, f.denom, &tm, &fm)) {
                nnum = this->num * tm - f.num * fm;
                ddenom = this->denom * tm;
            }
        }
    }
    this->num = nnum;
    this->denom = ddenom;
    this->reduce();
    return *this;
}


fraction fraction::operator*(const fraction &f) {
    int nnum = this->num * f.num;
    int ddenom = this->denom * f.denom;
    fraction t(nnum, ddenom);
    t.reduce();
    return t;
}

fraction fraction::operator*=(const fraction &f) {
    this->num *= f.num;
    this->denom *= f.denom;
    this->reduce();
    return *this;
}

fraction fraction::operator/(const fraction &f) {
    int nnum = this->num * f.denom;
    int ddenom = this->denom * f.num;
    fraction t(nnum, ddenom);
    t.reduce();
    return t;
}

fraction fraction::operator/=(const fraction &f) {
    this->num *= f.denom;
    this->denom *= f.num;
    this->reduce();
    return *this;
}

fraction fraction::operator+(const fraction &f) {
    int nnum = 1, ddenom = 1;
    if (hasSameBase(this->denom, f.denom)) {
        nnum = this->num + f.num;
        ddenom = this->denom;
    } else {
        if (isFactor(this->denom, f.denom)) {
            if (this->denom > f.denom) {
                ddenom = this->denom;
                int small = multiplyBy(this->denom, f.denom);
                int fnum = f.num * small;
                nnum = this->num + fnum;
            } else if (this->denom < f.denom) {
                ddenom = f.denom;
                int small = multiplyBy(this->denom, f.denom);
                int tnum = this->num * small;
                nnum = f.num + tnum;
            }
        } else {
            int tm, fm;
            if (getLCD(this->denom, f.denom, &tm, &fm)) {
                nnum = this->num * tm + f.num * fm;
                ddenom = this->denom * tm;
            }
        }
    }
    fraction t(nnum, ddenom);
    t.reduce();
    return t;
}

fraction fraction::operator-(const fraction &f) {
    int nnum = 1, ddenom = 1;
    if (hasSameBase(this->denom, f.denom)) {
        nnum = this->num - f.num;
        ddenom = this->denom;
    } else {
        if (isFactor(this->denom, f.denom)) {
            if (this->denom > f.denom) {
                ddenom = this->denom;
                int small = multiplyBy(this->denom, f.denom);
                int fnum = f.num * small;
                nnum = this->num - fnum;
            } else if (this->denom < f.denom) {
                ddenom = f.denom;
                int small = multiplyBy(this->denom, f.denom);
                int tnum = this->num * small;
                nnum = tnum - f.num;
            }
        } else {
            int tm, fm;
            if (getLCD(this->denom, f.denom, &tm, &fm)) {
                nnum = this->num * tm - f.num * fm;
                ddenom = this->denom * tm;
            }
        }
    }
    fraction t(nnum, ddenom);
    t.reduce();
    return t;
}

fraction fraction::operator+=(const fraction &f) {
    int nnum = 1, ddenom = 1;
    if (hasSameBase(this->denom, f.denom)) {
        nnum = this->num + f.num;
        ddenom = this->denom;
    } else {
        if (isFactor(this->denom, f.denom)) {
            if (this->denom > f.denom) {
                ddenom = this->denom;
                int small = multiplyBy(this->denom, f.denom);
                int fnum = f.num * small;
                nnum = this->num + fnum;
            } else if (this->denom < f.denom) {
                ddenom = f.denom;
                int small = multiplyBy(this->denom, f.denom);
                int tnum = this->num * small;
                nnum = f.num + tnum;
            }
        } else {
            int tm, fm;
            if (getLCD(this->denom, f.denom, &tm, &fm)) {
                nnum = this->num * tm + f.num * fm;
                ddenom = this->denom * tm;
            }
        }
    }
    this->num = nnum;
    this->denom = ddenom;
    this->reduce();
    return *this;
}

fraction fraction::operator-=(const fraction &f) {
    int nnum = 1, ddenom = 1;
    if (hasSameBase(this->denom, f.denom)) {
        nnum = this->num - f.num;
        ddenom = this->denom;
    } else {
        if (isFactor(this->denom, f.denom)) {
            if (this->denom > f.denom) {
                ddenom = this->denom;
                int small = multiplyBy(this->denom, f.denom);
                int fnum = f.num * small;
                nnum = this->num - fnum;
            } else if (this->denom < f.denom) {
                ddenom = f.denom;
                int small = multiplyBy(this->denom, f.denom);
                int tnum = this->num * small;
                nnum = tnum - f.num;
            }
        } else {
            int tm, fm;
            if (getLCD(this->denom, f.denom, &tm, &fm)) {
                nnum = this->num * tm - f.num * fm;
                ddenom = this->denom * tm;
            }
        }
    }
    this->num = nnum;
    this->denom = ddenom;
    this->reduce();
    return *this;
}
bool fraction::operator<(const fraction &f) {
    return this->fraction::convert() < f.convert();
}

bool fraction::operator==(const fraction &f) {
    return this->fraction::convert() == f.convert();
}

bool fraction::operator<=(const fraction &f) {
    return this->fraction::convert() <= f.convert();
}

bool fraction::operator>(const fraction &f) {
    return this->fraction::convert() > f.convert();
}

bool fraction::operator>=(const fraction &f) {
    return this->fraction::convert() >= f.convert();
}

bool fraction::operator!=(const fraction &f) {
    return this->fraction::convert() != f.convert();
}


bool fraction::hasSameBase(int denom, int denom2) {
    return denom == denom2;
}

int fraction::getGCD(int num, int denom) {
    if (num < 0) num = num * -1;
    if (denom < 0) denom = denom * -1;
    if (num % denom == 0) return denom;
    else if (denom % num == 0) return num;
    else {
        int big, small;
        if (num > denom) {
            big = num;
            small = denom;
        } else if (denom > num) {
            big = denom;
            small = num;
        } else if (denom == num) {
            return denom;
        }
        for (int i = (big / 2); i > 1; i--) {
            if (small % i == 0 && big % i == 0) {
                return i;
            }
        }
        return 1;
    }
}

int fraction::getGCD() {
    return getGCD(num, denom);
}

bool fraction::isFactor(int n1, int n2) {
    if (n1 < 0) n1 = n1 * -1;
    if (n2 < 0) n2 = n2 * -1;
    if (n1 > n2) return n1 % n2 == 0;
    else if (n1 < n2) return n2 % n1 == 0;
    else return false;
}

bool fraction::getLCD(int denom, int denom2, int *m1, int *m2) {
    if (denom < 0) denom = denom * -1;
    if (denom2 < 0) denom2 = denom2 * -1;
    for (int i = 2; i < denom; i++) {
        for (int j = 2; j < denom2; j++) {
            if (denom * i == denom2 * j) {
                *m1 = i;
                *m2 = j;
                return true;
            }
        }
    }
    return false;
}


int fraction::multiplyBy(int n1, int n2) {
    if (n1 < 0) n1 = n1 * -1;
    if (n2 < 0) n2 = n2 * -1;
    if (n1 > n2) return n1 / n2;
    else if (n1 < n2) return n2 / n1;
    else return 1;
}
