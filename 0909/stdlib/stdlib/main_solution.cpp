//
//  main.cpp
//  read2vector
//
//  Created by will_mccarthy on 9/11/19.
//  Copyright © 2019 will_mccarthy. All rights reserved.
//

#include <iostream>
#include <list>
#include <vector>
using namespace std;

#include <fstream>

struct grocery_item {
  grocery_item()
  : grocery_item("", 0, 0.00) {}
  
  grocery_item(const string& name, size_t code, double price)
  : name_(name), code_(code), price_(price) {}
  
//  bool operator<(const grocery_item& other) const  {   // alphabetical sort
//    return (name_ < other.name_);
//  }
    bool operator<(const grocery_item& other) const  {   // descending price sort
      return (price_ > other.price_);
    }

  friend istream& operator>>(istream& is, grocery_item& gi) {
    return is >> gi.name_ >> gi.code_ >> gi.price_;
  }

  friend ostream& operator<<(ostream& os, const grocery_item& gi) {
    return os << gi.name_ << ", " << gi.code_ << ", " << gi.price_ << "\n";
  }
  
  string name_;
  size_t code_;
  double price_;
};


class grocery_bill {
public:
  // grocery_bill() default constructor auto-generated, will automatically create vector<grocery_item> for us
  
  void add(const grocery_item& gi) { items_.push_back(gi); }
  size_t size() const { return items_.size(); }
  bool empty() const { return size() == 0; }
  
  double total() const {
    double total = 0.0;
    for (const grocery_item& el : items_) {
      total += el.price_;
    }
    return total;
  }
  
  friend ostream& operator<<(ostream& os, grocery_bill& gb) {  // NOT const if you sort the array
    if (gb.empty()) { return os << "grocery bill has no items\n"; }
    
//    std::sort(gb.items_.begin(), gb.items_.end(),
//              [](const grocery_item& lhs, const grocery_item& rhs) -> bool {
//                return lhs.price_ > rhs.price_; });    // gb CANNOT be const if sorting
    std::sort(gb.items_.begin(), gb.items_.end());
    os << "==== Grocery Bill ========\n";
    for (const grocery_item& el : gb.items_) {
      os << el;
    }
    return os << "==========================\nTOTAL: $" << gb.total();
  }
  
private:
  vector<grocery_item> items_;
};


int main(int argc, const char* argv[]) {
  if (argc != 2) {  cerr << "Usage: prog filename\n";  exit(1); }

  ifstream ifs(argv[1]);
  if (!ifs.is_open()) { cerr << "Could not open: " << argv[1] << "\n";  exit(2); }

  grocery_item item;
  grocery_bill bill;
  while (ifs >> item) {
    bill.add(item);
  }
  ifs.close();

  cout << bill << "\n";

  std::cout << "\n\t\t...done.\n";
  return 0;
}
