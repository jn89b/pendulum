#include "State.h"
#include <iostream>
using namespace std;


//  Define Constructor of State
State::State(float t, float thet, float omeg, float alph){
    
    setStates(t,thet,omeg,alph);

}

//Member function definitions
void State::setStates(float t, float thet, float omeg, float alph){

    time = t;
    theta = thet;
    omega = omeg;
    alpha = alph;

    /*cout << "Time of Pendulum is: " <<  time <<endl;
    cout << "Theta of Pendulum is: " <<  theta <<endl;
    cout << "Angular Velocity is: " << omega <<endl;
    cout << "Angular acceleration is:" << alpha <<endl;*/

}

