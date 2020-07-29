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


struct SharedPtr
{
    // реализуйте следующие методы
    //
    // explicit SharedPtr(Expression *ptr = 0)
    // ~SharedPtr()
    // SharedPtr(const SharedPtr &)
    // SharedPtr& operator=(const SharedPtr &)
    // Expression* get() const
    // void reset(Expression *ptr = 0)
    // Expression& operator*() const
    // Expression* operator->() const

    explicit SharedPtr(Expression *ptr = 0)
    : ptr_(ptr) ,c_(0)
    {
        if(ptr_){
            c_ = new size_t(1);
        }
    }

    ~SharedPtr(){
        if(--*c_== 0){
            delete ptr_;
            delete c_;
        }
    }

    SharedPtr(const SharedPtr & ptr)
    : ptr_(ptr.ptr_), c_(ptr.c_) {
        if(c_){
            ++*c_;
        }
    }

    SharedPtr &operator=(const SharedPtr &ptr){
        if(this!=&ptr){
            if(--*c_==0){
                delete ptr_;
                delete c_;
            }
            ptr_=ptr.ptr_;
            c_=ptr.c_;
            ++*c_;
        }
        return *this;
    }

    Expression* get() const{
        return ptr_;
    }

    void reset(Expression *ptr = 0){
        if(--*c_==0){
                delete ptr_;
                delete c_;
        }
        ptr_ = ptr;
        c_ = new size_t(1);

    }

    Expression& operator*() const{
        return *ptr_;
    }

    Expression* operator->() const{
        return ptr_;
    }

    private:
    Expression *ptr_;
    size_t *c_;
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

    SharedPtr p2(exp1);
    SharedPtr p3(expr);
    
    SharedPtr p4(p2);

    return 0;
}