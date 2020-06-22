#include "main.h"
#include "../include/lib/robot.h"
#ifndef PURSUIT_H_
#define PURSUIT_H_
using namespace std; 
#define N 22
#define M 2
int a; 

//vec a(3, 2);
//a.i; //3 
class vec{
    public: 
        float i, j;  
        extern float projection[2] = {0, 0};
        vec(float i = 0, float j = 0){ //constructor initing values of components
            this->i = i; 
            this->j = j;
        }
        float mag(){ //returns the magnitude of the vec
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