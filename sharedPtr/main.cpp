

struct Expression;
struct Number;
struct BinaryOperation;

struct SharedPtr
{
        explicit SharedPtr(Expression *ptr = 0)
    : ptr_(ptr)
    {
        if(ptr_){
            c_ = new size_t(1);
        }
    }

    ~SharedPtr(){
        if(--*c_==0){
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