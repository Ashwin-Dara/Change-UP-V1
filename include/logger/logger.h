#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include "main.h"
#ifndef LOGGER_H_
#define LOGGER_H_
#define X_POSITION 0 
#define Y_POSITION 1
#define THETA_POSITION 2 

extern  std::ofstream  dataLog;
extern  std::ofstream  odomLog;   
extern  std::string    filePath;
extern  std::string    odomFilePath; 

class Logger{
    bool usingStream; 
    int data; 
    virtual void LoggerInit(const std::string &fileInput);
    void beginWriteStream();
};

namespace odomLogger{
    extern bool odometryDataUpdate; 
    extern std::string filePath; 
    extern int odomPosition[3];
    void odomLoggerInit(const std::string &fileInput, bool odoDataUpdate = false);
    void odomBeginWriteStream();
}


#endif