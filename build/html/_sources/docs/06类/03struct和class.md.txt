# struct和class区别

主要区别就在于默认权限，struct默认为公共权限，class为私有权限。
![](https://test-123456-md-images.oss-cn-beijing.aliyuncs.com/img/image-20220329220145754.png#crop=0&crop=0&crop=1&crop=1&id=zLmks&originHeight=886&originWidth=1433&originalType=binary&ratio=1&rotation=0&showTitle=false&status=done&style=none&title=)
**代码**
```c
#include<iostream>
using namespace std;
struct T1 
{
	int a;
};
class T2 
{
	int a;
};
int main() 
{
	T1 t1;
	t1.a = 1;
	T2 t2;
	t2.a = 1;
}
```