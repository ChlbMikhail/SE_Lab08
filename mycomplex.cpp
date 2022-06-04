/*!
    @file
    @brief файл с описанием методов класса Complex
*/
#include <iostream>
#include <cmath>
#include "mycomplex.h"
using namespace std;
/*!
    @brief конструктор класса.
    @param aRe действительная составляющая
    @param aIm мнимая составляющая
*/
Complex::Complex(double aRe, double aIm)
{
    Re = aRe;
    Im = aIm;
}
/*!
    @brief конструктор класса.
    @param aRval - комплексное число
*/
Complex::Complex(const Complex & aRval)
{
    Re = aRval.Re;
    Im = aRval.Im;
}
/*!
    @brief деструктор класса
*/
Complex::~Complex()
{
    Re = 0.0;
    Im = 0.0;
}
/*!
    @brief установление мнимой и действительной составляющей
*/
void Complex::Set(double aRe, double aIm)
{
    Re = aRe;
    Im = aIm;
}
/*!
    @brief возвращает модуль комплексного числа
    @return модуль комплексного числа
*/
Complex::operator double()
{
    return abs();
}
/*!
    @brief возвращает модуль выражения комплексного числа
    @return модуль выражения комплексного числа
*/
double Complex::abs()
{
    return sqrt(Re * Re + Im * Im);
}
/*!
    @brief возвращает результат сложения комплексного числа
    @return результат сложения комплексного числа
*/
Complex Complex::operator + (const Complex & aRval)
{
    Complex Result;
    Result.Re = Re + aRval. Re;
    Result.Im = Im + aRval.Im;
    return Result;
}
/*!
    @brief возвращает результат вычитания комплексного числа
    @return результат вычитания комплексного числа
*/
Complex Complex::operator - (const Complex & aRval)
{
    Complex Result;
    Result.Re = Re - aRval.Re;
    Result.Im = Im - aRval.Im;
    return Result;
}
/*!
    @brief возвращает результат сложения действительного числа
    @return результат сложения действительного числа
*/
Complex Complex::operator + (const double & aRval)
{
    Complex Result;
    Result.Re = Re + aRval;
    Result.Im = Im;
    return Result;
}
/*!
    @brief возвращает результат вычитания действительного числа
    @return результат вычитания действительного числа
*/
Complex Complex::operator - (const  double & aRval)
{
    Complex Result(*this);
    Result.Re = Re - aRval;
    return Result;
}
/*!
    @brief возвращает результат умножения комплексного числа
    @return результат умножения комплексного числа
*/
Complex Complex::operator * (const Complex  & aRval)
{
    Complex Result;
    Result.Re = Re * aRval.Re - Im * aRval.Im;
    Result.Im = Re * aRval.Im + Im * aRval.Re;
    return Result;
}
/*!
    @brief возвращает результат умножения действительного числа
    @return результат умножения действительного числа
*/
Complex Complex::operator * (const double & aRval)
{
    Complex Result;
    Result.Re = Re * aRval;
    Result.Im = Im * aRval;
    return Result;
}
/*!
    @brief возвращает результат деления действительного числа
    @return результат деления действительного числа
*/
Complex Complex::operator /(const double & aRval)
{
    Complex Result;
    Result.Re = Re / aRval;
    Result.Im = Im / aRval;
    return Result;
}
/*!
    @brief ссылаемся на результат сложения комплексного числа
    @return возврат по значению сложения
*/
Complex & Complex::operator += (const   Complex &  aRval)
{
    Re += aRval.Re;
    Im += aRval.Im;
    return *this;
}
/*!
    @brief ссылаемся на результат вычитания комплексного числа
    @return возврат по значению вычитания
*/
Complex & Complex::operator -= (const Complex & aRval)
{
    Re -= aRval.Re;
    Im -= aRval.Im;
    return * this;
}
/*!
    @brief ссылаемся на результат умножения комплексного числа
    @return возврат по значению умножения
*/
Complex & Complex::operator *= (const Complex & aRval)
{
    double tmpRe = Re;
    Re = Re * aRval.Re - Im * aRval.Im;
    Im = Im * aRval.Re + tmpRe * aRval.Im;
    return *this;
}
/*!
    @brief ссылаемся на результат сложения действительного числа
    @return возврат по значению сложения
*/
Complex& Complex::operator += (const double& aRval)
{
    Re += aRval;
    return *this;
    }
/*!
    @brief ссылаемся на результат вычитания действительного числа
    @return возврат по значению вычитания
*/
Complex & Complex::operator -= (const double & aRval)
{
    Re -= aRval;
    return *this;
}
/*!
    @brief ссылаемся на результат умножения действительного числа
    @return возврат по значению умножения
*/
Complex & Complex::operator *= (const double & aRval)
{
    Re *= aRval;
    Im *= aRval;
    return *this;
}
/*!
    @brief ссылаемся на результат деления действительного числа
    @return возврат по значению деления
*/
Complex & Complex::operator /= (const double & aRval)
{
    Re /= aRval;
    Im /= aRval;
    return *this;
}
/*!
    @brief ссылаемся на результат равенства комплексного числа
    @return возврат по значению равенства
*/
Complex & Complex::operator = (const Complex & aRval)
{
    Re = aRval.Re;
    Im = aRval.Im;
    return *this;
}
/*!
    @brief ссылаемся на результат равенства действительного числа
    @return возврат по значению равенства
*/
Complex & Complex::operator = (const double & aRval)
{
    Re = aRval;
    Im = 0.0;
    return *this;
}
/*!
    @brief извлекаем действительную и мнимую составляющую
    @return извлечение
*/
istream & operator >> (istream & stream, Complex & aRval)
{
    char tmp[256];
    stream >> aRval.Re >> aRval.Im >> tmp;
    return stream;
}
/*!
    @brief вставляем действительную и мнимую составляющую
    @return вставление
*/
ostream & operator << (ostream & stream, Complex & aRval)
{
    stream << aRval.Re;
    if(!(aRval.Im < 0))
        stream << '+';
    stream << aRval.Im << 'i';
    return stream;
}
/*!
    @brief возвращает результат сложения действительного и комплексного чисел
    @param aLval действительное число
    @return результат сложения
*/
Complex operator + (const double & aLval, const Complex & aRval)
{
    Complex Result;
    Result.Re = aLval + aRval.Re;
    Result.Im =  aRval.Im;
    return Result;
}
/*!
    @brief возвращает результат вычитания действительного и комплексного чисел
    @return результат вычитания
*/
Complex operator - (const double & aLval, const Complex & aRval)
{
    Complex Result;
    Result.Re = aLval - aRval.Re;
    Result.Im =- aRval.Im;
    return Result;
}
/*!
    @brief возвращает результат умножения действительного и комплексного чисел
    @return результат умножения
*/
Complex operator * (const double & aLval, const Complex & aRval)
{
    Complex Result;
    Result.Re = aLval * aRval.Re;
    Result.Im = aLval * aRval.Im;
    return Result;
}