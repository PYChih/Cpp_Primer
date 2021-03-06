// Exercise 14.02
//    Write declarations for the overloaded
//    input,
//    output,
//    addition,
//    and compound-assignment operators for Sales_data.
//    see exercise 7.41
#include "exercise_14_02.h"  // NOLINT
using std::string;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;
Sales_data &Sales_data::combine(const Sales_data &rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}
istream &read(istream &is, Sales_data &item) {  // NOLINT
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}
ostream &print(ostream &os, const Sales_data &item) {
  os << "isbn : " << item.isbn() << " "
     << "unit sold : " << item.units_sold << " "
     << "revenue : " << item.revenue << " "
     << "average price : " << item.avg_price();
  return os;
}
Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;
  sum.combine(rhs);
  return sum;
}
