/*
 * LecturaIR.h
 *
 *  Created on: Nov 3, 2018
 *      Author: Miguel Rivera Ser
 */

#ifndef LECTURAIR_H_
#define LECTURAIR_H_

void LecturaIR(){
		i=0;
		MaskSensor=0b00000111;
		Sensor=5;
	for(i;i<6;i++){
		PTAD_PTAD0=0;
		PTAD_PTAD1=0;
		PTAD_PTAD2=0;
		MaskedSens=(MaskSensor&Sensor);
		ADC1SC1=(MaskedSens);
		while(ADC1SC1_COCO==0);
		aux1=ADC1R;
			switch (MaskedSens){
			case 0:
				PTAD_PTAD0=1;	
				PTAD_PTAD1=0;
				PTAD_PTAD2=0;
				break;
			case 1:
				PTAD_PTAD0=1;	
				PTAD_PTAD1=0;
				PTAD_PTAD2=0;
				break;
			case 2:
				PTAD_PTAD0=0;	
				PTAD_PTAD1=0;
				PTAD_PTAD2=1;
				break;
			case 3:
				PTAD_PTAD0=0;	
				PTAD_PTAD1=0;
				PTAD_PTAD2=1;
				break;
			case 4:
				PTAD_PTAD0=0;	
				PTAD_PTAD1=1;
				PTAD_PTAD2=0;
				break;
			case 5:
				PTAD_PTAD0=0;	
				PTAD_PTAD1=1;
				PTAD_PTAD2=0;
				break;
			default:
				PTAD_PTAD0=0;
				PTAD_PTAD1=0;
				PTAD_PTAD2=0;
				break;
			}
		ADC1SC1=(MaskedSens);
		while(ADC1SC1_COCO==0);
		aux2=ADC1R;
		aux3=aux2-aux1;
		luz();
		//while(SCI1S1_TDRE==0);
		//SCI1D=aux3;
		//Sensor++;
	}
}


#endif /* LECTURAIR_H_ */
