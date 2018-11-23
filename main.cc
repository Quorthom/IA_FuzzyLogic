#include "fuzzy.h"

int main() {
  fuzzy f;
  double d = 0, v = 0; //condiciones iniciales del sistema
  double Theta = 0; //angulo de ajuste del sistema.
  double u = 0, t = 0; //parametros del sitema: factor de rozamiento y tiempo de accion.
  double a = 0, d0 = 0, v0 = 0, fx = 0, fy = 0; //variables de movimiento, aceleracion instantanea, distancia anterior (i-1) y velocidad anterior (i-1)
  float const PI=3.1415926536;
  int it = 0; //iterador

  //TEST WITHOUT INTERFAZ
  d = 2.5;
  v = 0;
  t = 0.125;
  u = 0.15;

  std::cout<<"STARTING SIMULATION"<<std::endl;
  //while( ( d > 0.25 || d < -0.25 ) || ( v > 0.125 || v < -0.125 )  ){
  while( ( d > 0.25 || d < -0.25 ) || ( v > 0.125 || v < -0.125 )  ){
    std::cout<<"iteration no. "<< it<<std::endl;
    Theta = f.fuzzy_logic(d, v);
    std::cout<<"adjustment: "<< Theta<< " degrees."<<std::endl;
    std::cout<<std::endl;
    //a = 9.807*sin(fabs(Theta*(PI/180))) - u*9.807*cos(fabs(Theta*(PI/180)));
    fx = 9.807*sin(fabs(Theta*(PI/180)));
    fy = u*9.807*cos(fabs(Theta*(PI/180)));
    if(fx <= fy) a = 0;
    else a = fx - fy;
    if(Theta > 0) a = a*(-1);
    d0 = d;
    v0 = v;
    v = v0 + a*(t*t);
    d = d0 + v0*t + (0.5)*a*(t*t);
    std::cout<<"aceleration = " << a << std::endl;
    std::cout<<"position after: "<< t << " seconds = " << d << std::endl;
    std::cout<<"position change after: "<< t << " seconds = " << v << std::endl;
    if( (d > 10) || (d < -10) ){
    std::cout<<"OBJECT LOST!"<<std::endl;
    break;
  }
  std::cout<<"**********************************************"<<std::endl;
  it++;
  }
  std::cout<<"SIMULATION FINISHED"<<std::endl;
  std::cout<<"equilibrium for: "<< t*it <<" segundos."<<std::endl;
    return 0;
  }


  /* NUMERIC TEST
  u = 0.15;
  t = 1;
  d = 5;
  v = 3;
  Theta = f.fuzzy_logic(d, v);
  std::cout<<"angle = " << Theta << std::endl;
  std::cout<<"angle = " << fabs(Theta) << std::endl;
  a = 9.807*sin(fabs(Theta*(PI/180))) - u*9.807*cos(fabs(Theta*(PI/180)));
  if(Theta < 0) a = a*(-1);
  std::cout<<"aceleracion = " << a << std::endl;
  d0 = d;
  v0 = v;
  std::cout<<"position0 = " << d0 << std::endl;
  std::cout<<"change position0 = " << v0 << std::endl;
  v = v0 + a*(t*t);
  d = d0 + v0*t + (0.5)*a*(t*t);
  std::cout<<"position = " << d << std::endl;
  std::cout<<"change position = " << v << std::endl;*/
