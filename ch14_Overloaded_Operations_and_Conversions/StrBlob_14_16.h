#ifndef CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_STRBLOB_14_16_H_
#define CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_STRBLOB_14_16_H_
#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>
#include <utility>
class StrBlob {
  friend bool operator==(const StrBlob &lhs, const StrBlob &rhs);
  friend bool operator!=(const StrBlob &lhs, const StrBlob &rhs);

 public:
  typedef std::vector<std::string>::size_type size_type;
  StrBlob();
  StrBlob(std::initializer_list<std::string> il);  // NOLINT
  size_type size() const {return data->size();}
  bool empyt() const { return data->empty();}
  void push_back(const std::string &t) {data->push_back(t);}
  void push_back(std::string &&t);
  void pop_back();
  std::string &front();
  std::string &back();
  const std::string &front() const;
  const std::string &back() const;

 private:
  std::shared_ptr<std::vector<std::string>> data;
  void check(size_type i, const std::string &msg) const;
};
bool operator==(const StrBlob &lhs, const StrBlob &rhs);
bool operator!=(const StrBlob &lhs, const StrBlob &rhs);
#endif  // CH14_OVERLOADED_OPERATIONS_AND_CONVERSIONS_STRBLOB_14_16_H_
