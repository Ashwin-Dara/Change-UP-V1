#include "main.h" // <include = "main.h"> making this file part of PROS project
#include "../include/lib/robot.h" // <include = "robot.h"> accessing all needed math files via config file
// <header guard>
#ifndef PURSUIT_H_ 
#define PURSUIT_H_
using namespace std; 
#define N 22
#define M 2

/**
 * <class = "vec"> 2 dimensional mathemtical vector class so that 
 * normnalizing the path for the pursuit code later is condensed
 * and easier 
**/

class vec{
    public: 

        /**
        * <var "i, j"> the i and j components of the vector that will be
        * assigned via the constructor and can be modified later
        *
        * <var "projection"> scalar projection vector and its value will be 
        * stored in this array
        **/

        float i, j;  
        extern float projection[2] = {0, 0};

        /**
        * <param = "i, j"> constructor that will initialize the values of the vector
        * summary: initializer
        **/

        vec(float i = 0, float j = 0){ //constructor initing values of components
            this->i = i; 
            this->j = j;
        }
        
        //<return> the magnitude of the vector created
        float mag(){ 
            return sqrt(i*i + j*j);
        }
        void projection(const vec &scalarVec){
            float dotP = (i*scalarVec.i + j*scalarVec.j); //numerator of projection scalar 
            float modP = (pow(scalarVec.i, 2.0) + pow(scalarVec.j, 2.0)); //denom=. of projection scalar
            float frac = dotP/modP; //scalar value
            projection[0] = scalarVec.i * frac; //k*vec{scalarVec}
            projection[1] = scalarVec.j * frac; //update...update
        }
};

float dot(const vec &a, const vec &b){ //returns the dot product (scalar) of 2 vecs
    return (a.i * b.i) + (a.j * b.j);           
}

/** 
 * declare the path to follow (in this instance will be line)
 * find the coordinates of your bot vs the coordinates of the target
 * how to generate the target; calculate projection of start to look ahead and the vector of the path
 * 
 **/

//line path follower (no need for smoothing algorithm this game)
class purePursuit : public vec { //inherit odo as well 
private: 
    string mapK = ""; //key to seek for intuitiveness
public: 
     vector< vector<int> > path(N, vector<int> (M)); // dynamic array for path
    virtual void init(); //init mem for other variables
    virtual void generatePath(const int genPath[2][2]){
        for(i=0; i<2; i++){ //manual declaration of line segment to follow 
            //line segment is the path
            for(j=0; j<2; j++){
                path[i][j] = genPath[i][j];
            }
        }
    }
    void generateTarget(const vec &a1, const vec &a2, const string &input){
        
    }
    void seek(const &string key);
};

#endif