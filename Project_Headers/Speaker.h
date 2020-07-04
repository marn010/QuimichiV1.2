/*
 * Speaker.h
 *
 *  Created on: Nov 8, 2018
 *      Author: Vaio
 */

#ifndef SPEAKER_H_
#define SPEAKER_H_
int Freq1=0;
int dur=0;

int DO=654;
int RE=734;
int MI=824;
int FA=873;
int SOL=980;
int LA=1100;
int SI=1234;
void Cancion(){
	TPM1C4SC=0b00101000;
	Nota(DO,1);
	Nota(RE,2);
}

void Nota(int Freq1,int Dur ){
	//Canal 1 - Captura señal encoder - Modo: Input Capture

	//Freq2=Freq1;	// conversion de frecuencia nominal a valor de PWM Value
	TPM1C4V=Freq1;
}
#endif /* SPEAKER_H_ */
