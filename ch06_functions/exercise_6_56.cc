// Exercise 6.56:
//  練習6.56: 呼叫那個vector中的每個元素，並印出它們的結果
//   Exercise 6.55:
//    寫出四個函式，為兩個int值進行加減乘除。將這些函式的指標儲存到你為前一個練習所寫的vector
//   Exercise 6.54:
//    為一個函式撰寫宣告，它有兩個int參數，並回傳一個int，然後再宣告一個vector，其元素具有這種函式指標型別
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
int f1(int i1, int i2) { return 0; }
int add(int i1, int i2) { return i1 + i2; }
int minus(int i1, int i2) { return i1 - i2; }
int multiple(int i1, int i2) { return i1 * i2; }
int division(int i1, int i2) {return i1 / i2; }
int main() {
  using f1FuncType = decltype(f1);
  vector<f1FuncType*> fvec_decl1;
  typedef int (*funcp) (int, int);  // funcp is a function pointer type
  vector<funcp> fvec_typede1;
  typedef int (func) (int, int);  // func is a function type
  vector<func*> fvec_typede2;
  typedef decltype(f1)* funcp_decl;
  vector<funcp_decl> fvec_decl2;
  fvec_typede1.push_back(&add);
  fvec_typede2.push_back(minus);
  fvec_decl1.push_back(division);
  fvec_decl2.push_back(multiple);
  cout << fvec_typede1[0](1, 1) << endl;
  cout << (*fvec_typede2[0])(1, 1) << endl;
  cout << (*fvec_decl1[0])(1, 1) << endl;
  cout << (fvec_decl2[0])(1, 1) << endl;
}