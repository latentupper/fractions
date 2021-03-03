//
// Created by Никита Тоглохинов on 14.02.2021.
//

#include "Fraction.h"
#include <iostream>
#include <numeric>

Fraction::Fraction(): p(0), q(1) {}

Fraction::Fraction(double a)
{
    bool IsNonNeg = true;
    if(a<0)
    {
        IsNonNeg = false;
    }
    double pp = a;
    if(pp<0)
    {
        pp = -pp;
    }
    int qq = 1;
    for(;;)
    {
        if(pp == (int)pp)
        {
            break;
        }
        pp *=10;
        qq *=10;
    }
    p = (int)pp;
    q = qq;
    MakeProper();
    if(!IsNonNeg)
    {
        p *= (-1);
    }
}

Fraction::Fraction(int pp, int qq)
{
    p = std::abs(pp);
    q = std::abs(qq);
    MakeProper();
    if(qq == 0) {
        std::cout << "Error: division by zero!" << std::endl;
        std::cout << "Fraction is turned to zero" << std::endl;
    }
    if(pp*qq < 0)
    {
        p *= (-1);
    }
}

//"катающий" конструктор
Fraction::Fraction(const Fraction& orig): p(orig.p), q(orig.q) {}

//приведение дроби к правильной
void Fraction::MakeProper() {
    int nod = std::gcd(p, q);
    if(p*q != 0)
    {
        p /= nod;
        q /= nod;
    } else
    {
        p = 0;
        q = 1;
    }
}

[[nodiscard]] int Fraction::getP() const {
    return p;
}

[[nodiscard]] int Fraction::getQ() const {
    return q;
}

void Fraction::ChangeP(int pp) {
    p = pp;
}

void Fraction::ChangeQ(int qq) {
    q = qq;
}

//операции с дробями

Fraction Fraction::operator+(const Fraction& b) const
{
    Fraction s(p*b.q + q*b.p, q*b.q);
    s.MakeProper();
    return s;
}

Fraction Fraction::operator-(const Fraction& b) const
{
    Fraction s(p*b.q - q*b.p, q*b.q);
    s.MakeProper();
    return s;
}

Fraction Fraction::operator*(const Fraction& b) const
{
    Fraction s(p*b.p, q*b.q);
    s.MakeProper();
    return s;
}

Fraction Fraction::operator/(const Fraction& b) const
{
    if(b.p != 0) {
        Fraction s;
        if(p*b.p < 0)
        {
            s.ChangeP(-std::abs(p * b.q));
        } else s.ChangeP(p * b.q);
        s.ChangeQ(std::abs(q*b.p));
        s.MakeProper();
        return s;
    } else {
        std::cout << "Error: division by zero" << std::endl;
        return Fraction();
    }
}

//унарный минус
Fraction Fraction::operator-() const
{
    return Fraction(-p, q);
}

// операторы приравнивания

Fraction& Fraction::operator=(const Fraction& b)
{
    return const_cast<Fraction &>(b);
}

void Fraction::operator+=(const Fraction& b)
{
    int pp = p*b.q + q*b.p;
    int qq = q*b.q;
    p = pp;
    q = qq;
    MakeProper();
}

void Fraction::operator-=(const Fraction& b)
{
    int pp = p*b.q - q*b.p;
    int qq = q*b.q;
    p = pp;
    q = qq;
    MakeProper();
}

void Fraction::operator*=(const Fraction& b)
{
    int pp = p*b.p;
    int qq = q*b.q;
    p = pp;
    q = qq;
    MakeProper();
}

void Fraction::operator/=(const Fraction& b)
{
    if(b.p != 0) {
        int pp = p * b.q;
        int qq = q * b.p;
        p = pp;
        q = qq;
        MakeProper();
    } else {
        std::cout << "Error: division by zero; Fraction is not modified" << std::endl;
    }
}

void Fraction::operator+=(int a)
{
    p += q*a;
    MakeProper();
}

void Fraction::operator-=(int b)
{
    p -= q*b;
    MakeProper();
}

void Fraction::operator*=(int pp)
{
    if(pp!=0)
    {
        p *= pp;
        MakeProper();
    } else{
        p = 0;
        q = 1;
    }
}

void Fraction::operator/=(int qq)
{
    if(qq!=0)
    {
        q *= std::abs(qq);
        MakeProper();
        if(qq<0)
        {
            p *= (-1);
        }
    } else{
        std::cout << "Error: division by zero; Fraction is not modified" << std::endl;
    }
}

//операторы типа ДРОБЬ <оператор> ЧИСЛО

Fraction Fraction::operator+(int a) const
{
    Fraction s(p + q*a, q);
    s.MakeProper();
    return s;
}

Fraction Fraction::operator-(int b) const
{
    Fraction s(p - q*b, q);
    s.MakeProper();
    return s;
}

Fraction Fraction::operator*(int pp) const
{
    Fraction s;
    if(pp != 0)
    {
        s.ChangeP(p*pp);
        s.ChangeQ(q);
        s.MakeProper();
    }
    return s;
}

Fraction Fraction::operator/(int qq) const
{
    Fraction s;
    if(qq!=0)
    {
        s.ChangeQ(q*std::abs(qq));
        if(qq<0)
        {
            s.ChangeP(-p);
        } else
        {
            s.ChangeP(p);
        }
        s.MakeProper();
    } else{
        std::cout << "Error: division by zero" << std::endl;
    }
    return s;
}

//оператор приведения к типу double
Fraction::operator double() const
{
    return (double)p/(double)q;
}

//операторы типа ЧИСЛО <оператор> ДРОБЬ

Fraction operator+(int a, const Fraction& b)
{
    Fraction s(a*b.getQ() + b.getP(), b.getQ());
    s.MakeProper();
    return s;
}

Fraction operator-(int a, const Fraction& b)
{
    Fraction s(a*b.getQ() - b.getP(), b.getQ());
    s.MakeProper();
    return s;
}

Fraction operator*(int a, const Fraction& b)
{
    Fraction s(a*b.getP(), b.getQ());
    s.MakeProper();
    return s;
}

Fraction operator/(int a, const Fraction& b)
{
    Fraction s;
    if(b.getP() != 0)
    {
        if(a*b.getP() <0)
        {
            s.ChangeP(-abs(a*b.getQ()));
        } else
        {
            s.ChangeP(a*b.getQ());
        }
        s.ChangeQ(std::abs(b.getP()));
        s.MakeProper();
    } else{
        std::cout << "Error: division by zero" << std::endl;
    }
    return s;
}

std::istream& operator>>(std::istream& istr, Fraction& s)
{
    int a, b;
    istr >> a >> b;
    s.ChangeP(a);
    s.ChangeQ(b);
    s.MakeProper();
    return istr;
}

std::ostream& operator<<(std::ostream& ostr, const Fraction& s)
{
    ostr << s.getP() << "/" << s.getQ();
    return ostr;
}