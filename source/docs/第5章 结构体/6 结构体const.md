# 结构体const

在某些时候我们需要将结构体变量传入到一个函数内，如果使用值传递就会占用大量的内存空间，因为每调用一次函数，计算机就会赋值出一个新的结构体变量，大小和原变量相同，所以应采用地址传递来节省空间，因为指针只占用4个字节。但是使用地址传递会带来一个隐患，即可以在函数体内修改原结构体变量的值，这对数据来说是不安全的，我们需要用const进行修饰，使结构体变量不可更改。

```c
#include<iostream>
using namespace std;

// 定义学生的结构体
struct Student {
	string name;
	int age;
	double score;
};

// 加上const修饰，就可以避免在地址传递时，函数体内修改原变量的属性
void printStu(const Student* p) {

	//p->age = 20;//错误，不能修改
	cout << p->name << "\t" << p->age << "\t" << p->score << endl;

}

int main() {
	//创建结构体变量
	Student s = { "张三",18,90 };
	printStu(&s);
}
```
