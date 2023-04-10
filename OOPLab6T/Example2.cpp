#include "Lab6Example.h"
#include <iostream>
#include <cmath>
using namespace std; //  гоглг
namespace SpaceExample2 {
    // Abstract Class
// Створити абстрактний базовий клас домашня тварина із віртуальною функцією говорить. 
// Створити похідні класи: кішка, собака, корова, качка та курка. 
 
    using namespace std;

    class Data {
    public:
        virtual double norm() = 0;
    };

    class ComplexNumber : public Data {
    private:
        double real, imag;
    public:
        ComplexNumber(double r, double i) : real(r), imag(i) {}
        double norm() {
            return real * real + imag * imag;
        }
    };

    class Vector : public Data {
    private:
        double elements[10];
    public:
        Vector(double e1, double e2, double e3, double e4, double e5, double e6, double e7, double e8, double e9, double e10) {
            elements[0] = e1;
            elements[1] = e2;
            elements[2] = e3;
            elements[3] = e4;
            elements[4] = e5;
            elements[5] = e6;
            elements[6] = e7;
            elements[7] = e8;
            elements[8] = e9;
            elements[9] = e10;
        }
        double norm() {
            double sum_of_squares = 0;
            for (int i = 0; i < 10; i++) {
                sum_of_squares += elements[i] * elements[i];
            }
            return sqrt(sum_of_squares);
        }
    };

    class Matrix : public Data {
    private:
        double a, b, c, d;
    public:
        Matrix(double aa, double bb, double cc, double dd) : a(aa), b(bb), c(cc), d(dd) {}
        double norm() {
            return sqrt(a * a + b * b + c * c + d * d);
        }
    };

    int mainExample2() {
        Data* data[3];
        data[0] = new ComplexNumber(3, 4);
        data[1] = new Vector(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
        data[2] = new Matrix(1, 2, 3, 4);
        for (int i = 0; i < 3; i++) {
            cout << "Norm of data[" << i << "]: " << data[i]->norm() << endl;
        }
        return 0;
    }
}
