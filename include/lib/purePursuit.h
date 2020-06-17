#include "main.h"
#include "../include/lib/robot.h"
#ifndef PURSUIT_H_
#define PURSUIT_H_
using namespace std; 
#define N 1
#define M 2

class vec{
    public: 
        extern float val[2]; 
        vec(const int _vec[2]);
        float16_t mag();
        float16_t dot(const int a[2], const int b[2]);
};

class purePursuit : public vec { //inherit odo as well 
public: 
    extern vector< vector<int> > path(N, vector<int> (M));
    virtual void generatePath(const int genPath[3][2]);
    void generateTarget(int v[2], int z[2]);
}

#endif