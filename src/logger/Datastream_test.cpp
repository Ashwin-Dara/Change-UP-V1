
#include <iostream>
#include <fstream>
#include <string>
#include <cstdarg>
using namespace std;
std::ofstream dataStreamWriter;
//display target, current sensor, error, power
//ball detected, line_sensor value, 
std::ofstream chassisStream[4]; 
std::ofstream intakeStream[4];


class Logger{
  private: 
    //creating a map
  
    extern string fileNames[4];
  
  public: 
    //enter in the subsystem
    Logger(const std::string &subsystem){
      
    }
  
    void setFileName(const string &fileName, int i){
      fileNames[i] = fileName;
    }
    
  void beginWriting(const std::string &data, const std::string &fileName){
      
    }
    
  
}

//ISSUE NEED MULTIPLE INSTANCES OF STD::OFSTEAM ONE FOR EACH SUBSYSTEM?

class Logger{
  private: 
    //string fileName; 

  public: 
    
    string fileName; 
    
    Logger(const std::string &file_name){
        fileName = file_name; 
    }
    
    //will need to be threaded
    void beginWriting(const std::string &dataToDisplay){
        dataStreamWriter.open(fileName);
        for(int i = 0 ; i < 20 ; i ++){
            dataStreamWriter << dataToDisplay << "\n";
        }
    }
    
};

class Chassis : public Logger {
    public: 
        Chassis(const std::string &fileName) : Logger{fileName}{};
};

class Intake : public Logger { 
    public: 
        Intake(const std::string &fileName) : Logger{fileName}{};

};

int main()
{
    cout<<"Hello World";
    Chassis chassisNew("ChassisDataStream");
    Intake intakeNew("IntakeStream");
 //   Logger chassisLogger("ChassisDataStream");
 //   Logger intakeLogger("IntakeDataStream");
    std::string chassisValues = to_string(100);
    chassisNew.beginWriting("position is 90");
    intakeNew.beginWriting("ball count: 1");

    return 0;
}
