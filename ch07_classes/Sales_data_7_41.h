#ifndef CH07_CLASSES_SALES_DATA_7_41_H_
#define CH07_CLASSES_SALES_DATA_7_41_H_
#include <iostream>
#include <string>
class Sales_data {
  friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
  friend std::ostream &print(std::ostream &os, const Sales_data &item);
  friend std::istream &read(std::istream &is, Sales_data &item);  // NOLINT

 public:
  Sales_data(const std::string &s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(p * n) {
        std::cout << "three params constructor" << std::endl;
      }
  Sales_data() : Sales_data("", 0, 0) {
    std::cout << "default constructor" << std::endl;
  }
  Sales_data(const std::string &s) : Sales_data(s, 0, 0) {  // NOLINT
    std::cout << "single string constructor" << std::endl;
  }
  Sales_data(std::istream &is) : Sales_data() {  // NOLINT
    read(is, *this);
    std::cout << "istream constructor" << std::endl;
  }
  std::string isbn() const {return bookNo;}
  Sales_data &combine(const Sales_data &rhs);
  inline double avg_price() const {
    if (units_sold) {
      return revenue / units_sold;
    } else {
      return 0;
    }
  }

 private:
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};
#endif  // CH07_CLASSES_SALES_DATA_7_41_H_
