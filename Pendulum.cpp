#include <iostream>

using namespace std;


class Pendulum {
    public:
    // Defining variables 
        double length;      // Length of pendulum(m)
        double mass;        // Mass of pendulum (kg)
        double c_frict;     // Damping coefficient of friction 

        //Member functions declaration
        void setLength( double len );
        void setMass( double  mas );
        void setFriction( double frict );
};


//Member function definitions -> Using scope resolution operator SRO
// SRO used to access global variable when you have a local variable with same name,
// Define a function outside of a class
void Pendulum::setLength(double len){
    length = len;
}

void Pendulum::setMass(double mas){
    mass = mas;
}

void Pendulum::setFriction(double frict){
    c_frict = frict;
}


void printinfo(double length, double mass, double c_frict){

    cout << "Length of Pendulum is: " <<  length <<endl;
    cout << "Mass of Pendulum is: " <<  mass <<endl;
    cout << "Damping coefficient of friction is: " << c_frict <<endl;
}

int main(){
    Pendulum Pendulum_1;    // Declare pendulum1 as type pendulum

    // Pendulum_1 specifications
    Pendulum_1.setLength(0.3);
    Pendulum_1.setMass(0.2);
    Pendulum_1.setFriction(0.1);

    // Printinfo function
    printinfo(Pendulum_1.length, Pendulum_1.mass, Pendulum_1.c_frict);
    
}


