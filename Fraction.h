//
// Created by Никита Тоглохинов on 14.02.2021.
// Created by Никита Тоглохинов on 14.02.2021.
//
#include <iostream>
#ifndef WEEK2_FRACTION_H
#define WEEK2_FRACTION_H


class Fraction {
public:
    explicit Fraction();
    explicit Fraction(double a);
    explicit Fraction(int pp, int qq);
    Fraction(const Fraction& orig); //"катающий" конструктор
    void MakeProper(); //приведение дроби к правильной
    [[nodiscard]] int getP() const;
    [[nodiscard]] int getQ() const;

    //операции с дробями
    Fraction operator+(const Fraction& b) const;
    Fraction operator-(const Fraction& b) const;
    Fraction operator*(const Fraction& b) const;
    Fraction operator/(const Fraction& b) const;

    Fraction operator-() const; //унарный минус

    //операторы приравнивания
    void operator=(const Fraction& b);
    void operator+=(const Fraction& b);
    void operator-=(const Fraction& b);
    void operator*=(const Fraction& b);
    void operator/=(const Fraction& b);

    void operator+=(int a);
    void operator-=(int b);
    void operator*=(int pp);
    void operator/=(int qq);

    //операторы типа ДРОБЬ <оператор> ЧИСЛО
    Fraction operator+(int a) const;
    Fraction operator-(int b) const;
    Fraction operator*(int pp) const;
    Fraction operator/(int qq) const;

    explicit operator double() const; //оператор приведения к типу double

    //операторы типа ЧИСЛО <оператор> ДРОБЬ
    friend Fraction operator+(int a, const Fraction& b);
    friend Fraction operator-(int a, const Fraction& b);
    friend Fraction operator*(int a, const Fraction& b);
    friend Fraction operator/(int a, const Fraction& b);
    friend std::istream& operator>>(std::istream& istr, Fraction& s);
    friend std::ostream& operator<<(std::ostream& ostr, const Fraction& s);

private:
    int p; //числитель, несет в себе знак
    int q; //знаменатель, только положителен
    void ChangeP(int pp);
    void ChangeQ(int qq);
};
#endif //WEEK2_FRACTION_H
