# 6.12 对象模型和this指针

## 1、成员变量和成员函数分开存储
1.  类内的成员变量和成员函数分开存储；
2.  只有非静态的成员变量存储在类内；
3.  空对象占用1个字节，来区分不同的对象；`sizeof()`查看大小
4.  一旦空对象里有非静态成员变量，则该对象占用的空间等于非静态成员变量的大小；
![](https://test-123456-md-images.oss-cn-beijing.aliyuncs.com/img/image-20220405131326402.png#crop=0&crop=0&crop=1&crop=1&id=WKJ71&originHeight=218&originWidth=712&originalType=binary&ratio=1&rotation=0&showTitle=false&status=done&style=none&title=)

## 2、this指针
**用途**
1. 当成员变量和形参名相同时，可以通过this来区分；
2. 在类内非静态成员函数中可以返回对象本身，*this；
**区分形参和成员变量**
```c
class Person
{
  Person(int age)
  {
    // 可将传递过来的形参age赋值到成员属性上
    this->age = age;
  }
  int age;
}
```
**返回对象本身**
1. this本身是指针，返回时需要解引用；
2. 且要使用&进行接收；
![](https://test-123456-md-images.oss-cn-beijing.aliyuncs.com/img/image-20220405132600133.png#crop=0&crop=0&crop=1&crop=1&id=rvJfL&originHeight=866&originWidth=1647&originalType=binary&ratio=1&rotation=0&showTitle=false&status=done&style=none&title=)
```
#include<iostream>
using namespace std;
class Person
{
public:
	Person(int age)
	{
		this->age = age;
	}
	Person& add(Person &p)
	{
		this->age += p.age;
		return *this;
	}
	int age;
};
void test01()
{
	Person p1(10);
	Person p2(20);
	p1.add(p2).add(p1); //相当于10+20+(10+20)
	cout << p1.age << endl;
	cout << p2.age << endl;
}
int main()
{
	test01();
}
```
> 这就是一种编程思想：链式法则，我们可以无限制地往下调用；
> 
## 3、空指针访问成员函数

1. 空指针可以访问成员函数，但是成员函数内部不能包含成员变量；
**可以访问**
```c
class Person
{
public:
	void f1()
	{
		cout << "f1()被访问了" << endl;
	}
};
void main()
{
  Person *p = NULL;
	p->f1();
}
```
**不可以访问**
报错
```c
class Person
{
public:
	void f2()
	{
		cout << age << endl;
	}
  int age;
};
void main()
{
  Person *p = NULL;
	p->f2();
}
```
## 4、`const`修饰的成员函数
1. 常函数：
成员函数后加`const`后我们称为这个函数为常函数
常函数内不可以修改成员属性
成员属性声明时加关键字mutable后，在常函数中依然可以修改
2. 常对象：
声明对象前加`const`称该对象为常对象
常对象只能调用常函数
**常函数**
加上mutable可以修改
![](https://test-123456-md-images.oss-cn-beijing.aliyuncs.com/img/image-20220405134400862.png#crop=0&crop=0&crop=1&crop=1&id=WV6x4&originHeight=640&originWidth=1338&originalType=binary&ratio=1&rotation=0&showTitle=false&status=done&style=none&title=)
**常对象**
![](https://test-123456-md-images.oss-cn-beijing.aliyuncs.com/img/image-20220405134639603.png#crop=0&crop=0&crop=1&crop=1&id=rti1C&originHeight=541&originWidth=1169&originalType=binary&ratio=1&rotation=0&showTitle=false&status=done&style=none&title=)