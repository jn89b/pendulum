#include "Pendulum.h"
#include <iostream>
using namespace std;

//This is the source file where you get into the meat and potatoes of your code
//Such as your method function definitions and etc

// Pendulum Constructor :: -> Binary Resolution Complitator 
Pendulum::Pendulum(double len, double mas, double frict)
{
    setParams(len,mas,frict);

}

//Member function definitions 
void Pendulum::setParams(double len, double mas, double frict){

    length = len;
    mass = mas;
    c_frict= frict;

    /*cout << "Length of Pendulum is: " <<  length <<endl;
    cout << "Mass of Pendulum is: " <<  mass <<endl;
    cout << "Damping coefficient of friction is: " << c_frict <<endl;*/

}

