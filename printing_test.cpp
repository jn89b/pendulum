#include "Pendulum.h" 
#include "State.h"
#include <iostream>
#include <fstream>
#include <math.h> 
using namespace std;

#define g 9.81      //Gravity (m^2/s)

string file_name = "PID.config";
string control;
double val;
double PID[3];

double dt = 0.01;
float alpha_t;
float omega_t;
float theta_t;

// Functions utilized in main
void printinfo(Pendulum pend, State state, double dt, double kp, double ki, double kd);
double motor_calc(double theta_des, double theta, double er[], double ei[], double ed, double kp, double ki, double kd );

// Deg2rad
double deg2rad( double d )
  {
  return M_PI * d / 180.0;
  }

//Rad2deg function
double rad2deg(double rad){
    return 180.0 * (rad/M_PI);
}

// Main function
int main(){

    // Read Config File 
    ifstream thefile(file_name);
    int i = 0;
    while(thefile >> control >> val ){
        PID[i] = val;
        i++;
    }
    cout << PID[0] << endl;

    // Define Pendululm and state inputs 
    Pendulum Pendulum(1.0,0.8,0.1); // (length, mass, friction)
    double angle = deg2rad(0);
    State State_k(0,angle,0,0);         // (time, theta, omega, alpha)


    // Simulation
    printinfo(Pendulum, State_k, dt, PID[0], PID[1], PID[2]);

    return 0;
}


// Function that takes in states and returns new states
void printinfo(Pendulum pend, State state, double dt, double kp, double ki, double kd){

    //Initialize state
    double theta_des = 0;
    double motor_cmd;
    
    double er[2] = {0,0};
    double ei[2] = {0,0};
    double ed = 0;
    
    // Initialize new state 
    State State_k_1_new = state;

    for(state.time=0; state.time < 2; state.time += dt){


        motor_cmd = motor_calc(theta_des, state.theta, er, ei, ed, kp, ki, kd );

        // double time_new;
        State_k_1_new.alpha = ((g/pend.length)*sin(state.theta)) - ((pend.c_frict/(pend.mass * pow (pend.length, 2))) *(state.omega)) + ((motor_cmd)/(pend.mass * pow(pend.length,2)));
        State_k_1_new.omega = state.omega + (State_k_1_new.alpha*dt);
        State_k_1_new.theta = state.theta + (State_k_1_new.omega*dt) + ((State_k_1_new.alpha * pow(dt,2)) /2);        
        State_k_1_new.time = state.time;
        
        // Printing values for debugging and verifying
        cout << "New Theta of Pendulum is: " <<  rad2deg(State_k_1_new.theta) <<endl;
        cout << "New Angular Velocity is: " << State_k_1_new.omega <<endl;
        cout << "New Angular acceleration is:" << State_k_1_new.alpha <<endl;
        cout << "New Time of Pendulum is: " <<  State_k_1_new.time <<endl;
        cout << "Motor Command is : " <<  motor_cmd <<endl;

        state = State_k_1_new;
        // state = State_k_1_new; 


    }
}

// PID motor calculation 
double motor_calc(double theta_des, double theta, double er[], double ei[], double ed, double kp, double ki, double kd ){

    //Append new values to old values
    er[0] = er[1];
    ei[0] = ei[1];

    // Calculate new errors
    er[1] = theta_des - theta;
    ei[1] = ei[0] + (er[0]/2) * dt; 
    ed = (er[1] - er[0]) * dt;

    cout << "Errors are:" << er[1] << endl;
    double P;
    double I;
    double D;
    double motor_cmd;

    P = kp * er[1];
    I = kd * ei[1];
    D = kd * ed;

    motor_cmd = P + I + D;
    return motor_cmd;
}