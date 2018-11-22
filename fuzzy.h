#ifndef FUZZY_H_
#define FUZZY_H_

#include <iostream>
#include <cmath>

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
  //Methods for area calculation
  double triangle_Area(double h);
  double trapeze_Area(double h);
  double center_of_the_sums();
  //control
  double fuzzy_logic(double d, double v);
  //proccess
  void inference();
  double Min(double r, double c);
  double Max(double min, double membership);



private:
  //memberships for position
  double left;
  double centered;
  double right;
  //memberships for position change
  double going_left;
  double steady;
  double going_right;
  //memberships for angle
  double negative_large;
  double negative_short;
  double zero;
  double positive_short;
  double positive_large;
  //Areas
  double negative_large_Area;
  double negative_short_Area;
  double zero_Area;
  double positive_short_Area;
  double positive_large_Area;

};


#endif
