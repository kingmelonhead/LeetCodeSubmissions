class FizzBuzz {
private:
    int n;
    pthread_barrier_t b;
public:
    FizzBuzz(int n) {
        this->n = n;
        pthread_barrier_init(&b, 0, 4);
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        for (int i = 1; i<= this->n; i++){
            if (i % 3 == 0 && i % 5 != 0) printFizz();
            pthread_barrier_wait(&b);
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        for (int i = 1; i<= this->n; i++){
            if (i % 5 == 0 && i % 3 != 0) printBuzz();
            pthread_barrier_wait(&b);
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        for (int i = 1; i<= this->n; i++){
            if (i % 3 == 0 && i % 5 == 0) printFizzBuzz();
            pthread_barrier_wait(&b);
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        for (int i = 1; i<= this->n; i++){
            if (i % 3 != 0 && i % 5 != 0) printNumber(i);
            pthread_barrier_wait(&b);
        }
    }
};
