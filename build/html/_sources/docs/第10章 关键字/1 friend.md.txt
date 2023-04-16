# 10.1 friend
访问一些私有属性，关键字`friend`

## 1、全局函数做友元
类
```c
class Building
{
  // 可以使全局函数访问私有属性
	friend void goodGay(Building* build);
public:
	Building()
	{
		settingRoom = "客厅";
		bedRoom = "卧室";
	}
	string settingRoom;
private:
	string bedRoom;
};
```
测试函数
```c
void test01()
{
	Building b;
	goodGay(&b);
}
```
全局函数
```c
void goodGay(Building *build)
{
	cout << "正在访问b的" << build->settingRoom;
	cout << "正在访问b的" << build->bedRoom;
}
```