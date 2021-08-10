#ifndef UNIQUE_PENDULUM_H
#define UNIQUE_PENDULUM_H

// This is a header file with all your classes and function prototypes and variable declarations
// These variables are not defined but declared so keep that in mind
class Pendulum {
    public:
    // Declare variables
        double length;      // Length of pendulum(m)
        double mass;        // Mass of pendulum (kg)
        double c_frict;     // Damping coefficient of friction 

        //
        Pendulum(double len, double mas, double frict); // Declare a constructor
        void setParams(double len, double mas, double frict);

        double getLength(){return length;}
        double getMass(){return mass;}
        double getFriction(){return c_frict;}


};


#endif