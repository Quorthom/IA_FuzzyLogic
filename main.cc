#include "fuzzy.h"
#include "fuzzy.cc"

float const PI = 3.14159;
float const G = 9.81;

int main() {
  fuzzy f;
  double d = 0, v = 0, a = 0; //condiciones iniciales del sistema
  double Theta = 0; //angulo de ajuste del sistema.
  double u = 0, t = 0; //parametros del sitema: factor de rozamiento y tiempo de accion.
  double a0 = 0, d0 = 0, v0 = 0; //variables de movimiento, aceleracion instantanea, distancia anterior (i-1) y velocidad anterior (i-1)
  int it = 0; //iterador

  //TEST WITHOUT INTERFAZ
  d = 5;
  v = 3;
  t = 0.5;
  u = 0.1;

  std::cout<<"STARTING SIMULATION"<<std::endl;
  while( ( d > 0.25 || d < -0.25 ) || ( v > 0.125 || v < -0.125 )  ){
    std::cout<<"Iteration no. "<< it<<std::endl;
    Theta = f.fuzzy_logic(d, v);
    std::cout<<"adjustment: "<< Theta<< " degrees."<<std::endl;
    std::cout<<std::endl;
    if(u*cos(fabs(Theta*(PI/180))) > sin(fabs(Theta*(PI/180)))){
        a = 0;
    }
    else{
        a = G*sin(fabs(Theta*(PI/180))) - u*G*cos(fabs(Theta*(PI/180))) + a0;
    }
    if(Theta > 0) a = a*(-1);
    d0 = d;
    v0 = v;
    a0 = a;
    v = v0 + a*t;
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
  if(it > 100)
  {
    break;
  }
  }
  std::cout<<"SIMULATION FINISHED"<<std::endl;
  std::cout<<"equilibrium for: "<< t*it <<" segundos."<<std::endl;
    return 0;
  }
