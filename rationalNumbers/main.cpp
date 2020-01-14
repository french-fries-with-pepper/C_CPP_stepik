#include <iostream>;
using namespace std;

struct Rational
{
    Rational(int numerator = 0, int denominator = 1);

    void add(Rational rational);
    void sub(Rational rational);
    void mul(Rational rational);
    void div(Rational rational);

    void neg();
    void inv();
    double to_double() const;

    Rational operator-() const { return Rational(numerator_, -denominator_); };
    Rational operator+() const { return Rational(numerator_, denominator_); }
    Rational &operator+=(int n)
    {
        numerator_ += n * denominator_;
        return *this;
    }

    Rational &operator-=(int n)
    {
        numerator_ -= n * denominator_;
        return *this;
    }

    Rational &operator*=(int n)
    {
        numerator_ *= n;
        return *this;
    }

    Rational &operator/=(int n)
    {
        denominator_ *= n;
        return *this;
    }

    Rational &operator+=(Rational const &n)
    {
        this->add(n);
        return *this;
    }
    Rational &operator-=(Rational const &n)
    {
        this->sub(n);
        return *this;
    }
    Rational &operator*=(Rational const &n)
    {
        this->mul(n);
        return *this;
    }
    Rational &operator/=(Rational const &n)
    {
        this->div(n);
        return *this;
    }

    int getNum() const
    {
        return this->numerator_;
    }

    int getDen() const
    {
        return this->denominator_;
    }

    operator double() const
    {
        return this->to_double();
    }

private:
    int numerator_;
    int denominator_;
};

Rational operator+(Rational n1, Rational const &n2)
{
    return n1 += n2;
}
Rational operator-(Rational n1, Rational const &n2)
{
    return n1 -= n2;
}
Rational operator*(Rational n1, Rational const &n2)
{
    return n1 *= n2;
}
Rational operator/(Rational n1, Rational const &n2)
{
    return n1 /= n2;
}

bool operator==(Rational const &left, Rational const &right)
{
    Rational tmp = 1 + left - right;
    return tmp.getDen() == tmp.getNum() ? true : false;
}

bool operator!=(Rational const &left, Rational const &right)
{
    return !(left == right);
}

bool operator>(Rational const &left, Rational const &right)
{
    Rational tmp = (left - right);
    return tmp.getDen() * tmp.getNum() > 0 ? true : false;
}

bool operator<(Rational const &left, Rational const &right)
{
    return right > left;
}

bool operator>=(Rational const &left, Rational const &right)
{
    return !(left < right);
}

bool operator<=(Rational const &left, Rational const &right)
{
    return !(right < left);
}
