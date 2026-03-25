#pragma once
#include <numeric>

template<typename I> requires std::integral<I>
class rational
{
    I num_;
    I den_;
public:
    /* Costruttore di default */
    rational()
        : num_(I(0.0)), den_(I(0.0))
    {}

    /* Costruttore user-defined */
    rational(const I& pnum, const I& pden)
        : num_(pnum),den_(pden)
    {}

    /* Restituiscono i valori di num e den*/
    I num() const {return num_;}
    I den() const {return den_;}

    /* Implementazione canonica dell'incremento*/
    rational& operator+=(const rational& other) {
        if (den_== 0 || other.den_== 0){
            if (num_== 0 || other.num_== 0){
                num_=0;
                den_=0;
            }
            else {
                num_=1;
                den_=0;
            }
        }
        else {
            num_ *= other.den_; 
            num_ += den_ * other.num_;
            den_ *= other.den_;
        }
        return *this;
    }

    /* Implementazione canoninca della somma*/
    rational operator+(const rational& other) const{
        rational ret = *this;
        ret += other;
        return ret;
    }

    /* Implementazione canonica di *= */
    rational& operator*=(const rational& other) {
        num_ *= other.num_;
        den_ *= other.den_;
        return *this;    
    }

    /* Implementazione canonica del prodotto*/
    rational operator*(const rational& other) const{
        rational ret = *this;
        ret *= other;
        return ret;
    }

    /* Implementazione canonica del decremento*/
    rational& operator-=(const rational& other) {
        if (den_==0 || other.den_== 0){
            if (num_==0 || other.num_== 0){
                num_=0;
                den_=0;
            }
            else {
                if(den_==0 && other.den_==0 && num_!=0 && other.num_!=0){
                    num_=0;
                    den_=0;
                }
                else{
                    num_=1;
                    den_=0;
                }
            }
        }
        else {
            num_ *= other.den_; 
            num_ -= den_ * other.num_;
            den_ *= other.den_;
        }
        return *this;
    }

    /* Implementazione canonica della differenza*/
    rational operator-(const rational& other) const{
        rational ret = *this;
        ret -= other;
        return ret;
    }

    /* Implementazione canonica di /= */
    rational& operator/=(const rational& other) {
        if (den_==0 || other.den_== 0){
            if (num_==0 || other.num_== 0){
                num_=0;
                den_=0;
            }
            else {
                if (den_==0){
                    num_=1;
                    den_=0;
                }
                else if (other.den_==0){
                    num_=0;
                    den_=1;
                }
                else {
                    num_=0;
                    den_=0;
                }

            }
        }
        else {
            num_ *= other.den_;
            den_ *= other.num_;
        }               
        return *this;
    }

    /* Implementazione canonica della divisione */
    rational operator/(const rational& other) const{
        rational ret = *this;
        ret /= other;
        return ret;
    }
};

template<typename I>
std::ostream&
operator<<(std::ostream& os, const rational<I>& r)
{
    /* Stampa di un oggetto con la semplificazione */
    if (r.den()==0){
        if (r.num()==0){
            os << "NaN";
        }
        else {
            os << "Inf";
        }
    }
    else {
        if(r.num()%r.den()==0){
            I rnum=r.num()/r.den();
            os << rnum;
        }
        else if (r.den()%r.num()==0){
            I rden=r.den()/r.num();
            os << "1/" << rden;
        }
        else {
            I rnum = r.num() / std::gcd(r.num(),r.den());
            I rden = r.den() / std::gcd(r.num(),r.den());
            os << rnum << "/" << rden;
        }
    }
    return os;
}
