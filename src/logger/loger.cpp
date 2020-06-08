#include "main.h"
#include "../include/logger/logger.h"
#define HERTZ 100 
std::string    filePath; 
std::ofstream  dataLog;
std::ofstream  odomLog;   

void Logger::LoggerInit(const std::string &fileInput){
    filePath = fileInput;
    data = usingStream = 0; 
}

void Logger::beginWriteStream() {
    dataLog.open(filePath);
        while(1) {
            dataLog << "data \n";
            pros::delay(HERTZ);
        }
    if(!usingStream)
        dataLog.close();
}

namespace odomLogger{
    int odomPosition[3] = {X_POSITION, Y_POSITION, THETA_POSITION};

    void odomLoggerInit(const std::string &fileInput, bool odoDataUpdate) {
        filePath = fileInput;
        odometryDataUpdate = odometryDataUpdate;
    }

    void odomBeginWriteStream() {
        odomLog.open(filePath);
        while(1) {
            odomLog << "Position-X " + std::to_string(odomPosition[0]) +
                        "Position-Y " + std::to_string(odomPosition[Y_POSITION]) +
                        "Theta " + std::to_string(odomPosition[THETA_POSITION]);
        }
        if(!odometryDataUpdate) {
            odomLog.close();
        }
    }
}