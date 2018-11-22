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
  //memberships for angle change
  negative_large = 0;
  negative_short = 0;
  zero = 0;
  positive_short = 0;
  positive_large = 0;
  //Areas
  negative_large_Area = 0;
  negative_short_Area = 0;
  zero_Area = 0;
  positive_short_Area = 0;
  positive_large_Area = 0;
}

void fuzzy::fuzzification(double d, double v){
  membership_left(d);
  membership_centered(d);
  membership_right(d);
  membership_going_left(v);
  membership_steady(v);
  membership_going_right(v);

  /*//test for fuzzification
  std::cout<<"left = " << left <<"."<<std::endl;
  std::cout<<"centered = " << centered <<"."<<std::endl;
  std::cout<<"right = " << right <<"."<<std::endl;
  std::cout<<std::endl;
  std::cout<<"going_left = " << going_left <<"."<<std::endl;
  std::cout<<"steady = " << steady <<"."<<std::endl;
  std::cout<<"going_right = " << going_right <<"."<<std::endl;
  std::cout<<std::endl;*/
}

void fuzzy::membership_left(double d){
  if( d <= -5 ) left = 1;
  else if( d >=  0 ) left = 0;
  else left = -(d/5);
}

void fuzzy::membership_centered(double d){
  if( d <= -5 || d >=  5 ) centered = 0;
  else if( d > -5 && d <  0 ) centered = ((d/5)+1);
  else if( d >  0 && d <  5 ) centered = (-(d/5)+1);
  else if( d == 0) centered = 1;
}

void fuzzy::membership_right(double d){
  if( d >=  5 ) right = 1;
  else if( d <=  0 ) right = 0;
  else right = (d/5);
}

void fuzzy::membership_going_left(double v){
  if( v <= -2.5 ) going_left = 1;
  else if( v >= 0 ) going_left = 0;
  else going_left = -(v/2.5);
}

void fuzzy::membership_steady(double v){
  if( v <= -2.5 || v >= 2.5 ) steady = 0;
  else if( v > -2.5 && v <  0  ) steady = ((v/2.5)+1);
  else if( v >   0  && v < 2.5 ) steady = (-(v/2.5)+1);
  else if( v == 0 ) steady = 1;
}

void fuzzy::membership_going_right(double v){
  if( v >= 2.5 ) going_right = 1;
  else if( v <= 0 ) going_right = 0;
  else going_right = (v/2.5);
}


void fuzzy::inference(){
  //RULE 1
  if( left && going_left ) positive_large = Max( Min(left, going_left), positive_large );

  //RULE 2
  if( left && steady ) positive_short = Max( Min(left, steady), positive_short );

  //RULE 3
  if( left && going_right ) zero = Max( Min(left, going_right), zero );

  //RULE 4
  if( centered && going_left ) positive_short = Max( Min(centered, going_left), positive_short );

  //RULE 5
  if( centered && steady ) zero = Max( Min(centered, steady), zero );

  //RULE 6
  if( centered && going_right ) negative_short = Max( Min(centered, going_right), negative_short );

  //RULE 7
  if( right && going_left ) zero = Max( Min(right, going_left), zero );

  //RULE 8
  if( right && steady ) negative_short = Max( Min(right, steady), negative_short );

  //RULE 9
  if( right && going_right ) negative_large = Max( Min(right, going_right), negative_large );

  //test for inference
  std::cout<<"negative_large = " << negative_large <<"."<<std::endl;
  std::cout<<"negative_short = " << negative_short <<"."<<std::endl;
  std::cout<<"zero = " << zero <<"."<<std::endl;
  std::cout<<"positive_short = " << positive_short <<"."<<std::endl;
  std::cout<<"positive_large = " << positive_large <<"."<<std::endl;
  std::cout<<std::endl;

}

double fuzzy::Min(double r, double c){
  if(r < c ) return r;
  else return c;
}

double fuzzy::Max(double min, double membership){
  if(!membership) return min;
  if(membership > min) return membership;
  else return min;
}
double fuzzy::triangle_Area(double h){
  double x = 0;
  x = 30*h;
  return  (60+(60-(2*x)))*h/2;
}

double fuzzy::trapeze_Area(double h){
  double x = 0;
  x = 30*h;
  return (x*h)/2 + (60-x)*h;
}

double fuzzy::center_of_the_sums(){
  negative_large_Area = trapeze_Area(negative_large);
  negative_short_Area = triangle_Area(negative_short);
  zero_Area = triangle_Area(zero);
  positive_short_Area = triangle_Area(positive_short);
  positive_large_Area = trapeze_Area(positive_large);

  /*//test for Areas
  std::cout<<"Area of negative_large = " << negative_large_Area <<"."<<std::endl;
  std::cout<<"Area of negative_short = " << negative_short_Area <<"."<<std::endl;
  std::cout<<"Area of zero = " << zero_Area <<"."<<std::endl;
  std::cout<<"Area of positive_short_short = " << positive_short_Area <<"."<<std::endl;
  std::cout<<"Area of positive_large_short = " << positive_large_Area <<"."<<std::endl;
  std::cout<<std::endl;*/

  double total_area = negative_large_Area + negative_short_Area + zero_Area + positive_short_Area + positive_large_Area;
  //std::cout<<"total_area = " << total_area <<"."<<std::endl;
  //std::cout<<std::endl;
  return ((negative_large_Area*(-60)) + (negative_short_Area*(-30)) + (zero_Area*(0)) + (positive_short_Area*(30)) + (positive_large_Area*(60)) )/total_area;
}

double fuzzy::fuzzy_logic(double d, double v){
  fuzzification(d ,v);
  inference();
  return center_of_the_sums();
}