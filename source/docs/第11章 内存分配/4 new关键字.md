# new关键字
1. C++中利用new操作符在堆区开辟数据
2. 堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符`delete`
3. 语法：new数层类型
4. 利用new创建的数据，会返回该数据对应的类型的指针
```c
int* fn() {
	int* p = new int(10);
	return p;
}
int main() {
	int* p = fn();
	cout << *p << endl;
	cout << *p << endl;
	delete p; // 释放
	system("pause");
	return 0;
}
```