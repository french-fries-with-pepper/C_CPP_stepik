#include <iostream>
using namespace std;

struct Expression
{
    virtual double evaluate() const = 0;

    virtual ~Expression(){};
};

struct Number : Expression
{
    Number(double value)
        : value(value)
    {
    }

    double evaluate() const
    {
        return value;
    }

private:
    double value;
};

struct BinaryOperation : Expression
{
    /*
      Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операциям,
      которые вам нужно реализовать.
     */
    BinaryOperation(Expression const *left, char op, Expression const *right)
        : left(left), op(op), right(right)
    {
    }

    double evaluate() const
    {

        switch (op)
        {
        case '+':
            return left->evaluate() + right->evaluate();
        case '-':
            return left->evaluate() - right->evaluate();
        case '*':
            return left->evaluate() * right->evaluate();
        case '/':
            return left->evaluate() / right->evaluate();
        }
    }

    ~BinaryOperation()
    {
        delete left;
        delete right;
    }

private:
    Expression const *left;
    Expression const *right;
    char op;
};

bool check_equals(Expression const *left, Expression const *right)
{
    // put your code here
    cout << *((int **)left) << endl;
    cout << *((int **)right) << endl;

    return *((int **)left) == *((int **)right) ? true : false;
}

int main()
{

    Expression *sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Expression *expr = new BinaryOperation(new Number(3), '+', sube);

    Expression *exp1 = new Number(5);
    Expression *exp2 = new Number(7);

    cout << expr->evaluate() << endl;

    check_equals(exp1, expr);

    return 0;
}