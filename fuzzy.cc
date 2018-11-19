#include "fuzzy.h"

fuzzy::fuzzy(){
  //memberships for position
  left = 0;
  centered = 0;
  right = 0;
  //memberships for position change
  going_left = 0;
  steady = 0;
  going_right = 0;
}

void fuzzy::fuzzification(double d, double v){
  membership_left(d);
  membership_centered(d);
  membership_right(d);
  membership_going_left(v);
  membership_steady(v);
  membership_going_right(v);

  /*test for fuzzification
  std::cout<<"left = " << left <<"."<<std::endl;
  std::cout<<"centered = " << centered <<"."<<std::endl;
  std::cout<<"right = " << right <<"."<<std::endl;
  std::cout<<std::endl;
  std::cout<<"going_left = " << going_left <<"."<<std::endl;
  std::cout<<"steady = " << steady <<"."<<std::endl;
  std::cout<<"going_right = " << going_right <<"."<<std::endl;*/
}

void fuzzy::membership_left(double d){
  if( d < -5 ) left = 1;
  else if( d >  0 ) left = 0;
  else left = -(d/5);
}

void fuzzy::membership_centered(double d){
  if( d < -5 || d >  5 ) centered = 0;
  else if( d > -5 && d <  0 ) centered = ((d/5)+1);
  else if( d >  0 && d <  5 ) centered = (-(d/5)+1);
}

void fuzzy::membership_right(double d){
  if( d >  5 ) right = 1;
  else if( d <  0 ) right = 0;
  else right = (d/5);
}

void fuzzy::membership_going_left(double v){
  if( v < -2.5 ) going_left = 1;
  else if( v >   0  ) going_left = 0;
  else going_left = -(v/2.5);
}

void fuzzy::membership_steady(double v){
  if( v < -2.5 || v > 2.5 ) steady = 0;
  else if( v > -2.5 && v <  0  ) steady = ((v/2.5)+1);
  else if( v >   0  && v < 2.5 ) steady = (-(v/2.5)+1);
}

void fuzzy::membership_going_right(double v){
  if( v > 2.5 ) going_right = 1;
  else if( v <  0  ) going_right = 0;
  else going_right = (v/2.5);
}
