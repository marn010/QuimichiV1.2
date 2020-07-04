/*
 * Variables.h
 *
 *  Created on: Nov 3, 2018
 *      Author: Miguel Rivera Ser
 */

#ifndef VARIABLES_H_
#define VARIABLES_H_

short entero = 0; 
char decimal = 0;
int aux=0;
int aux1=0;
int aux2=0;
int aux3=0;
int i=0,Sensor;
char MaskSensor,MaskedSens;
char ESTADO = 0;
//short VEL = 0;
char GIRO = 0;
short ENC_2A = 0;
short ENC_2B = 0;
int TEMP = 0;
int CONTADOR = 0;
long rpm=0;
float velocidad=0;
float a=1.2;
float errorabs=0;
float error=0;
float ref=9;
float kp=9;    //8
float ki=160;   //48
float control=0;
int t_mod=0;
char contled=0;

float velocidad2=0;
float a2=1.2;
float errorabs2=0;
float error2=0;
float ref2=9;
float kp2=9;    //8
float ki2=160;   //48
float control2=0;
int t_mod2=0;



#endif /* VARIABLES_H_ */
