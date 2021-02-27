#include <iostream>
#include "Fraction.h"

int main() {
    std::cout << "test: constructors" << std::endl;
    Fraction n;
    std::cout << n << std::endl; //output 0/1
    Fraction a(1.125);
    std::cout << a << std::endl; //output 9/8
    Fraction b(2, 3);
    std::cout << b << std::endl; //output 2/3
    std::cout << "test: copy-constructor" << std::endl;
    Fraction c(b);
    std::cout << c << std::endl; //output 2/3
    std::cout << "test: operators frac frac" << std::endl;
    std::cout << a+b << std::endl; //output 43/24
    std::cout << a-b << std::endl; //output 11/24
    std::cout << a*b << std::endl; //output 3/4
    std::cout << a/b << std::endl; //output 27/16
    std::cout << a*n << std::endl; //output 0/1
    std::cout << n/a << std::endl; //output 0/1
    std::cout << "test: = and frac--frac" << std::endl;
    n = c;
    std::cout << n << std::endl; //output 2/3
    a += b;
    std::cout << a << std::endl; //output 43/24
    a -= b;
    std::cout << a << std::endl; //output 9/8
    a *= b;
    std::cout << a << std::endl; //output 3/4
    a /= b;
    std::cout << a << std::endl; //output 9/8
    std::cout << "test: = and frac--int" << std::endl;
    a += 2;
    std::cout << a << std::endl; //output 25/8
    a -= 2;
    std::cout << a << std::endl; //output 9/8
    a *= 4;
    std::cout << a << std::endl; //output 9/2
    a /= 4;
    std::cout << a << std::endl; //output 9/8
    std::cout << "test: operators frac--int" << std::endl;
    std::cout << a+11 << std:: endl; //output 97/8
    std::cout << a-1 << std:: endl; //output 1/8
    std::cout << b*3 << std:: endl; //output 2/1
    std::cout << b/2 << std:: endl; //output 1/3
    std::cout << "test: operators int--frac" << std::endl;
    std::cout << 10+b << std:: endl; //output 32/3
    std::cout << 1-a << std:: endl; //output -1/8
    std::cout << 3*b << std:: endl; //output 2/1
    std::cout << 2/b << std:: endl; //output 3/1
    std::cout << "test: making to double" << std::endl;
    std::cout << double(a) << std:: endl; //output 1.125
    std::cout << double(b) << std:: endl; //output 0.6666...
    std::cout << "test: input and unary minus" << std::endl;
    std::cout << "Vvedite chislitel' i znamenatel' cherez probel" << std::endl;
    std::cin >> n;
    std::cout << -n << std::endl;
    return 0;
}
