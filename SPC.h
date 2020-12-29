/* This is the Header file for the SPC Library
 *  SPC stands for Square, Peaks and Counts. 
 *  This library is signal conditioning, where an Analog input is to be analyzed.
 *  The analog signal is converted into a square wave based on the threshold value given by the user, and positive edges are counted.
 *  Release Date: 29/12/2020
 *  Aaryaa Padhyegurjar
 */
#ifndef SPC_H
#define SPC_H

#include <Arduino.h>
class SPC {
  public:
    //Constructor
    SPC(); 
    //Functions of the Library
    int SPC_getSquare(int THRESHOLD, int CURRENT_SENSOR_STATE);
    int SPC_getCount(int CURRENT_SQUARE_STATE);
    
  private:
    //Private variables accessible only in 
    int LAST_SENSOR_STATE = LOW;   //sensor's previous state
    int SQUARE_STATE = 0; //Converting analog waveform into square waveform w.r.t threshold
    int LAST_SQUARE_STATE = LOW;
    int EDGE_COUNT = 0;
    int POSEDGE_COUNT = 0;
};


#endif
