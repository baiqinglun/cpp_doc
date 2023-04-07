#include <memory>
#include <iostream>

class MyClass {
public:
    MyClass() {
        std::cout << "MyClass constructed." << std::endl;
    }
    ~MyClass() {
        std::cout << "MyClass destructed." << std::endl;
    }
    void doSomething() {
        std::cout << "Doing something." << std::endl;
    }
};

int main() {
    // 创建一个std::shared_ptr来管理MyClass对象
    std::shared_ptr<MyClass> ptr(new MyClass);

    // 使用箭头运算符来访问MyClass对象的成员函数
    ptr->doSomething();

    // 另外一个std::shared_ptr也可以指向同一个MyClass对象
    std::shared_ptr<MyClass> ptr2 = ptr;

    // 此时，MyClass对象的引用计数为2

    return 0;
}
