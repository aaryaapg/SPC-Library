/* This is the Source file for the SPC Library
 *  SPC stands for Square, Peaks and Counts. 
 *  This library is used for signal conditioning, where an Analog input is to be analyzed.
 *  The analog signal is converted into a square wave based on the threshold value given by the user, and positive edges are counted.
 *  Release Date: 29/12/2020
 *  Aaryaa Padhyegurjar
 */
#include <Arduino.h>
#include "SPC.h"

SPC::SPC(){
  
}

/*This function returns a boolean value, ie, a square wave based on the threshold given by the user*/
int SPC::SPC_getSquare(int THRESHOLD, int CURRENT_SENSOR_STATE){
  if (CURRENT_SENSOR_STATE >= THRESHOLD) { //if it's above the threshold
     if (LAST_SENSOR_STATE < THRESHOLD) { // check that the previous value was below the threshold
        //Serial.println("The sensor value just went above the threshold"); 
        SQUARE_STATE = 1;
     }
  }
  else { //if it's below the threshold
    if (LAST_SENSOR_STATE > THRESHOLD) { // check that the previous value was above the threshold
      //Serial.println("The sensor value just went below the threshold"); 
      SQUARE_STATE = 0;
    }
  }
  LAST_SENSOR_STATE = CURRENT_SENSOR_STATE; // save the sensor state for next comparison
  return SQUARE_STATE;
}

/*This function calculates the number of positive edges of any square wave*/
int SPC::SPC_getCount(int CURRENT_SQUARE_STATE){
  if(CURRENT_SQUARE_STATE != LAST_SQUARE_STATE){
    EDGE_COUNT++;
  }
  else {
    EDGE_COUNT = EDGE_COUNT;
  }
  LAST_SQUARE_STATE = CURRENT_SQUARE_STATE;
  POSEDGE_COUNT = EDGE_COUNT/2;
  return POSEDGE_COUNT;
}

/*
# Can be used for any analog sensor
1. http://www.sensingthecity.com/force-sensor-peak-detection/
2. https://itp.nyu.edu/physcomp/labs/labs-arduino-digital-and-analog/lab-sensor-change-detection/
*/
