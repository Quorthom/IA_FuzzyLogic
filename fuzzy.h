#ifndef FUZZY_H_
#define FUZZY_H_

#include <iostream>

class fuzzy{
public:
  fuzzy();
  //methods for fuzzification
  void fuzzification(double d, double v);
  //  check memberships
  void membership_left(double d);
  void membership_centered(double d);
  void membership_right(double d);
  void membership_going_left(double v);
  void membership_steady(double v);
  void membership_going_right(double v);


private:
  //memberships for position
  double left;
  double centered;
  double right;
  //memberships for position change
  double going_left;
  double steady;
  double going_right;

};


#endif
