# list

list封装了链表，非顺序存储，存储下一个元素的指针

![image-20221025102614807](http://test-123456-md-images.oss-cn-beijing.aliyuncs.com/img/image-20221025102614807.png)

<strong style="color:#00b050;">链表和数组的区别：</strong>

1. 数组静态分配内存，链表动态分配内存。
2. 数组在内存中是连续的，链表是不连续的。
3. 数组利用下标定位，查找的时间复杂度是O(1)，链表通过遍历定位元素，查找的时间复杂度是O(N)。
4. 数组插入和删除需要移动其他元素，时间复杂度是O(N)，链表的插入或删除不需要移动其他元素，时间复杂度是O(1)。

<strong style="color:#00b050;">数组的优点</strong>

1. 随机访问性比较强，可以通过下标进行快速定位。
2. 查找速度快
3. 数组的缺点
4. 插入和删除的效率低，需要移动其他元素。
5. 会造成内存的浪费，因为内存是连续的，所以在申请数组的时候就必须规定七内存的大小，如果不合适，就会造成内存的浪费。
6. 内存空间要求高，创建一个数组，必须要有足够的连续内存空间。
7. 数组的大小是固定的，在创建数组的时候就已经规定好，不能动态拓展。

<strong style="color:#00b050;">链表的优点</strong>

1. 插入和删除的效率高，只需要改变指针的指向就可以进行插入和删除。
2. 内存利用率高，不会浪费内存，可以使用内存中细小的不连续的空间，只有在需要的时候才去创建空间。大小不固定，拓展很灵活。

<strong style="color:#00b050;">链表的缺点</strong>

1. 查找的效率低，因为链表是从第一个节点向后遍历查找。
   

## 1、构造方法

1. list容器的迭代器不支持-和+运算符，不能随意访问；
2. 但使用迭代器构造时，可以使用vector的迭代器；或者使用数组的指针作为迭代器；

<strong style="color:#00b050;">构造函数原型</strong>

```c++
1. list(); 创建一个空list
2. list(initialzer_list<T> il); 使用同一初始化列表
3. list(const list<T>& l); 拷贝构造函数
4. list(iterator first,iterator last); 用迭代器创建list
5. list(list<T> &&v); 移动构造函数
```

```c++
// 1. 创建一个空list容器
list <int> l1;
cout << "l.size()=" << l1.size() << endl; // 0

// 2. 使用统一初始化列表创建list容器
//list <int> l2({ 1,2,3,4,5,6,7,8,9,10 });
//list<int> l2 = { 1,2,3,4,5,6,7,8,9,10 };
list<int> l2{ 1,2,3,4,5,6,7,8,9,10 };
for (int value : l2) cout << value << "\t";
cout << endl;

// 3. list(const list<T> &v) 拷贝构造函数
list<int> l3(l2);
for (int value : l3) cout << value << "\t";
cout << endl;

// 4. list(iterator first,iteratoe last) 使用迭代器创建list容器
list<int> l4(l3.begin(), l3.end()); // 不支持随便访问，比如list<int> l4(l3.begin()+2, l3.end()-3);不支持-和+运算符
for (int value : l4) cout << value << "\t";
cout << endl;

// 5. 如果使用vecotr的迭代器创建是可以的
vector <int> v1 = { 1,2,3,4,5,6,7,8,9,10 };
list <int>l5(v1.begin() + 2, v1.end() - 3);
for (int value : l5) cout << value << "\t";
cout << endl;

// 6. 使用数组的指针作为迭代器
int a1[] = { 1,2,3,4,5,6,7,8,9,10 };
list <int>l6(a1 + 2, a1 + 10 - 3);
for (int value : l6) cout << value << "\t";
cout << endl;
```

## 2、特性操作

```c++
1. size_t capacity() const; // 返回容器的容量
2. size_t size() const; // 返回容器的实际大小（已使用的空间）
3. bool empty() const; // 判断容器是否为空
4. void clear(); // 清空容器
5. void reserve(size_t size); // 将容器容量设置为至少size
6. void shrink_to_fit(); // 将容器的容量降到实际大小（需要分配的内存）
7. void resize(size_t size); // 把容器的实际大小设置为size
```

## 3、元素操作

```c++
1. T &front(); // 第一个元素
2. const T &front(); // 第一个元素，只读
3. const T&back(); // 最后一个元素，只读
4. T &back(); // 最后一个元素
```


## 4、赋值操作

```c++
1. list &operator = (const list &l); // 把容器l赋值给当前容器
2. list &operator = (initialzer_list<T> li); // 使用初始列表赋值
3. list assign(initial_list<T> il); // 使用统一初始化列表赋值
4. list assign(Iterator first,Iterator last); // 使用迭代器赋值
```

## 5、交换操作

```c++
1. void swap(list<T> &l); // 把当前容器与l交换，交换的时结点的地址
2. void reverse(); // 反转链表
3. void sort(); // 链表升序
4. void sort(_Pr2 _Pred); // 元素排序，排序方法由_Pred决定（二元函数）
5. void merge(list<T> &l); // 采用归并法合并两个已排序的list容器，合并后仍然是有序的
```

## 6、比较操作

```c++
bool operator == (const list <T> &l) const;
bool operator != (const list <T> &l) const;
```

## 7、插入和删除

```c++
1. void push_back(const T& value); // 在链表的尾部追加一个元素
2. void emplace_back(...); // 在链表的尾部追加一个元素，用于构造元素。C++11
3. iterator insert(iterator pos,const T& value); // 在指定位置插入一个元素，返回指向插入元素的迭代器
4. iterator emplace(iterator iterator pos,...); // 在指定位置插入一个元素，用于构造元素，返回指向插入元素的迭代器.C++11
5. iterator insert(iterator pos,iterator first,iterator last); // 在指定位置插入一个区间的元素
6. void pop_back(); // 从链表尾部删除一个元素
7. iterator erase(iterator pos); //删除指定位置的元素，返回下一个有效的迭代器
8. iterator erase(iterator first, iterator last); // 删除指定区间的元素，返回下一个有效的迭代器
9. push_front(front T& value); // 在链表的头部插入一个元素
10. emplace_front(...); // 在链表的头部插入一个元素，...用构造元素。C++11
11. splice(iterator pos,const list<T> &l); // 把另一个链表连接到当前列表
12. splice(iterator pos,const list<T> &l,iterator first,iterator last); // 把另一个链表指定的区间连接到当前链表
13. splice(iterator pos,const list<T> &l,iterator first); // 把另一个链表从开始到结尾连接到当前链表
14. void remove(value); // 删除链表中等于value的所有元素
15. void remove_if(_Pr1 _Pred); // 删除链表中满足条件的元素，参数_Pred是医院函数
16. void unique(); // 删除重复的元素，只保留一个
```