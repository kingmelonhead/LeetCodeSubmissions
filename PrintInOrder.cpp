class Foo {
public:
    
    int flag = 0;
  
    Foo() {
    }

    void first(function<void()> printFirst) {
        printFirst();
        flag = 1;
    }

    void second(function<void()> printSecond) {
        while (flag != 1) std::this_thread::sleep_for(1ns);
        printSecond();
        flag = 2;
    }

    void third(function<void()> printThird) {
        while (flag != 2) std::this_thread::sleep_for(1ns);
        printThird();
    }
};
