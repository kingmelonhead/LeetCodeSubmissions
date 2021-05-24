class FooBar {
private:
    short n;
    char state = 0;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (short i = 0; i < n; i++) {
            while (state != 0)
                std::this_thread::yield();
            
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            this->state++;
        }
    }

    void bar(function<void()> printBar) {
        
        for (short i = 0; i < n; i++) {
            while (state != 1)
                std::this_thread::yield();
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            this->state--;
        }
    }
};
