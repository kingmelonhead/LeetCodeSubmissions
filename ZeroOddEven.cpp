class ZeroEvenOdd {
private:
    int n;
    mutex mZero, mEven, mOdd;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->mEven.lock();
        this->mOdd.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 1; i <= this->n; i++){
            this->mZero.lock();
            printNumber(0);
            if (i % 2 == 0) this->mEven.unlock();
            else this->mOdd.unlock();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= this->n; i+=2){
            this->mEven.lock();
            printNumber(i);
            this->mZero.unlock();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i<= this->n; i+=2){
            this->mOdd.lock();
            printNumber(i);
            this->mZero.unlock();
        }
    }
};
