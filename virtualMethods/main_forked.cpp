#include <iostream>
using namespace std;

struct Number;
struct BinaryOperation;

struct Visitor {
    virtual void visitNumber(Number const * number) = 0;
    virtual void visitBinaryOperation(BinaryOperation const * binary) = 0;
    virtual ~Visitor() { }
};

struct Expression
{
    virtual double evaluate() const = 0;
    virtual void visit(Visitor * visitor) const  = 0;
    virtual ~Expression(){};
};

struct Number : Expression
{
    Number(double value)
        : value(value)
    {
    }

    void visit(Visitor * visitor) const { visitor->visitNumber(this); }

    double get_value() const { return value; }
    double evaluate() const
    {
        return value;
    }

private:
    double value;
};

struct BinaryOperation : Expression
{
    
    BinaryOperation(Expression const *left, char op, Expression const *right)
        : left(left), op(op), right(right)
    {
    }

    void visit(Visitor * visitor) const { visitor->visitBinaryOperation(this); }


    Expression const * get_left()  const { return left; }
    Expression const * get_right() const { return right; }
    char get_op() const { return op; }

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
        default :
            return 0;
        }
    };

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

struct ScopedPtr
{
    // реализуйте следующие методы:
    //
    // explicit ScopedPtr(Expression *ptr = 0)
    // ~ScopedPtr()
    // Expression* get() const
    // Expression* release()
    // void reset(Expression *ptr = 0)
    // Expression& operator*() const
    // Expression* operator->() const

    //constructor
    explicit ScopedPtr(Expression *ptr = 0)
     : ptr_(ptr)
    { }
    //destructor
    ~ScopedPtr(){
        delete ptr_;
    }
    //get
    Expression* get() const{
        return ptr_;
    }
    //release
    Expression* release(){
        Expression * tmp = ptr_;
        ptr_=0;
        return tmp;
    }
    //reset
    void reset(Expression *ptr = 0){
        delete ptr_;
        ptr_ = ptr;
        return;
    }
    // *
    Expression& operator*() const{
        return *ptr_;
    }
    // ->
    Expression* operator->() const{
        return ptr_;
    }

private:
    // запрещаем копирование ScopedPtr
    ScopedPtr(const ScopedPtr&);
    ScopedPtr& operator=(const ScopedPtr&);

    Expression *ptr_;
};

struct PrintBinaryOperationsVisitor : Visitor {
    void visitNumber(Number const * number)
    { std::cout << '(' << number->evaluate() << ')'; }

    void visitBinaryOperation(BinaryOperation const * bop)
    {   
        std::cout << '(';
        bop->get_left()->visit(this);
        std::cout << bop->get_op() << " ";
        bop->get_right()->visit(this);
        std::cout << ')';

    }
};

bool check_equals(Expression const *left, Expression const *right)
{
    // put your code here
   // cout << *((int **)left) << endl;
   // cout << *((int **)right) << endl;

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

    PrintBinaryOperationsVisitor visitor;
    expr->visit(&visitor);

    return 0;
}