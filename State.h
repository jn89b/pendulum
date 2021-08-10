#ifndef UNIQUE_STATE_H
#define UNIQUE_STATE_H

class State {
    public:
        // Declare Constructor
        State();
        float time;      // Time (s)
        float theta;     // theta of pendulum (deg)
        float omega;     // anglar velocity (deg/s)
        float alpha;     // angular acceleration (deg^2/s)
    public:
        //Member functions declaration
        State(float t, float thet, float omeg, float alph);
        void setStates(float t,float thet,float omeg,float alph);

        // Return attributes of State 
        float getTime(){return time;}
        float getOmega(){return omega;}
        float getTheta(){return theta;}
        float getAlpha(){return alpha;}
};


#endif //STATE_H