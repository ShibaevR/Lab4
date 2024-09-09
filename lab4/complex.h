#ifndef LAB4_COMPLEX_H
#define LAB4_COMPLEX_H

#include <cmath>

template <class T>
class Complex{
private:
    double c_real;
    double c_im;

public:
    Complex() : c_real(0), c_im(0){}

    Complex(const double real, const double imag) : c_real(real), c_im(imag){}

    double GetReal() const{
        return c_real;
    }

    double GetImag() const{
        return c_im;
    }

    Complex<T> operator+(const Complex<T>& complex) const{
        Complex<T> result((c_real + complex.GetReal()), (c_im + complex.c_im));

        return result;
    }

    void operator+=(const Complex<T>& complex){
        c_real = c_real + complex.GetReal();
        c_im = c_im + complex.GetImag();
    }

    Complex<T> operator*(const Complex<T>& complex) const{
        Complex<T> result(c_real * complex.GetReal(), c_im * complex.c_im);

        return result;
    }

    Complex<T> operator/(const Complex<T>& complex) const{
        Complex<T> result(c_real / complex.GetReal(), c_im / complex.c_im);

        return result;
    }

    void SquareRoot(){
        c_real = sqrt(c_real);
        c_im = sqrt(c_im);
    }

    Complex<T>& operator=(const Complex<T>& complex){
        c_real = complex.GetReal();
        c_im = complex.GetImag();

        return *this;
    }

    bool operator==(const Complex<T>& complex){
        if(c_real == complex.GetReal() && c_im == complex.GetImag()){
            return true;
        }

        return false;
    }

};


#endif //LAB4_COMPLEX_H
