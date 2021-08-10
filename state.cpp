#include "state.h"
#include <iostream>
using namespace std;


class State {
    public:
        float time;      // Time (s)
        float theta;     // theta of pendulum (deg)
        float omega;     // anglar velocity (deg/s)
        float alpha;     // angular acceleration (deg^2/s)

        //Member functions declaration
        void setTime( float t );
        void setTheta( float  thet );
        void setOmega( float omeg );
        void setAlpha( float alph);
};


//Member function definitions 
void State::setTime(float t){
    time = t;
}

void State::setTheta(float thet){
    theta = thet;
}

void State::setOmega(float omeg){
    omega = omeg;
}

void State::setAlpha(float alph){
    alpha = alph;
}


void printinfo(float time, float theta, float omega){

    cout << "Time of Pendulum is: " <<  time <<endl;
    cout << "Theta of Pendulum is: " <<  theta <<endl;
    cout << "Angular Velocity is: " << omega <<endl;
}

int main(){
    State State_Input;    // Declare pendulum1 as type pendulum

    // State_Input specifications
    State_Input.setTime(0.0);
    State_Input.setTheta(0);
    State_Input.setOmega(0.0);
    State_Input.setAlpha(0.0);

    // Printinfo function
    printinfo(State_Input.time , State_Input.theta, State_Input.omega);
}

