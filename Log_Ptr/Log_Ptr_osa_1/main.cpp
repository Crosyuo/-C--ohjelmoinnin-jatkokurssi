#include <iostream>
#include <memory>

template<typename T>
class Log_Ptr {
private:
    T* ptr;

public:
    explicit Log_Ptr(T* p) : ptr(p) {
        std::cout << "Log_Ptr: omistajuus siirretty" << std::endl;
    }

    ~Log_Ptr() {
        delete ptr;
        std::cout << "Log_Ptr: olio tuhottu" << std::endl;
    }

    Log_Ptr(const Log_Ptr&) = delete;
    Log_Ptr& operator=(const Log_Ptr&) = delete;

    T* get() const { return ptr; }
    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }
};

class TestClass {
public:
    TestClass() { std::cout << "TestClass: luotu" << std::endl; }
    ~TestClass() { std::cout << "TestClass: tuhottu" << std::endl; }
    void doSomething() { std::cout << "TestClass: tein jotain" << std::endl; }
};

int main() {
    Log_Ptr<TestClass> logPtr(new TestClass());
    logPtr->doSomething();
    return 0;
}