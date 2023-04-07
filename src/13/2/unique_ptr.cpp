#include <iostream>
#include <memory>
using namespace std;

int main()
{
  // unique_ptr使用
  // unique_ptr<int> p(new int(5));
  // cout << *p << endl;
  // unique_ptr<int> p1 = make_unique<int>(3);
  // cout << *p1 <<endl;

  // unique_ptr<int> uptr = make_unique<int>(10);
  // // unique_ptr<int> uptr1 = uptr;
  // unique_ptr<int> uptr1 = move(uptr);
  // cout << (uptr == uptr1) <<endl;

  std::unique_ptr<int[]> uptr = std::make_unique<int[]>(10);
  for (int i = 0; i < 10; i++) {
      uptr[i] = i * i;
  }   
  for (int i = 0; i < 10; i++) {
      std::cout << uptr[i] << std::endl;
  }   

  system("pause");
  return 0;
}