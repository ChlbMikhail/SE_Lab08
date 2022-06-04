/*!
    @file
    @brief заголовочный файл класса Complex.
*/
#ifndef _MY_COMPLEX_H_
#define _MY_COMPLEX_H_
#include <iostream>
using namespace std;

/*!
    @brief класс комплексного числа
*/
class Complex
{
	class Complex
    double Im;

    /*!
        @brief список членов класса
    */
    public:
        Complex(double aRe = 0, double aIm = 0);
        Complex(const Complex &);
        ~ Complex();

        /*!
            @brief установление мнимой и действительной составляющих
        */
        void Set(double aRe, double aIm = 0);
        operator double();

        /*!
            @brief модуль комплексного числа
        */
        double abs();

        /*!
            @brief дружественный класс операции перегрузки ввода >>
        */
        friend istream & operator >> (istream &, Complex &);


        /*!
            @brief дружественный класс операции перегрузки вывода <<
        */
        friend ostream & operator << (ostream &, Complex &);
        Complex operator + (const Complex &);
        Complex operator - (const Complex &);
        Complex operator + (const double &);

        /*!
            @brief  дружественный класс операции сложения
        */
        friend Complex operator + (const double &, const Complex &);
        Complex operator - (const double &);

        /*!
            @brief  дружественный класс операции вычитания
        */
        friend Complex operator - (const double &, const Complex &);
        Complex operator * (const Complex &);
        Complex operator * (const double&);

        /*!
            @brief  дружественный класс операции умножения
        */
        friend Complex operator * (const double &, const Complex &);
        Complex operator / (const double &);
        Complex & operator += (const Complex &);
        Complex & operator -= (const Complex &);
        Complex & operator *= (const Complex &);
        Complex & operator += (const double &);
        Complex & operator -= (const double &);
        Complex & operator *= (const double &);
        Complex & operator /= (const double &);
        Complex & operator = (const Complex &);
        Complex & operator = (const double &);
};
#endif