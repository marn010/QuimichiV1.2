/*
 * LEDs.h
 *
 *  Created on: Nov 5, 2018
 *      Author: Miguel Rivera Ser
 */

#ifndef LEDS_H_
#define LEDS_H_

void luz(){
	switch (MaskedSens){
			case 0:
				if(aux3>=45){
					PTCD_PTCD2=1;
				}else{
					PTCD_PTCD2=0;
				}
				break;
			case 1:
				if(aux3>=10){
					PTCD_PTCD3=1;
				}else{
					PTCD_PTCD3=0;
				}
				break;
			case 2:
				if(aux3>=10){
					PTCD_PTCD4=1;
				}else{
					PTCD_PTCD4=0;
				}
				break;
			case 3:
				if(aux3>=10){
					PTCD_PTCD6=1;
				}else{
					PTCD_PTCD6=0;
				}
				break;
			case 4:
				/*if(aux3>=10){
					PTCD_PTCD5=1;
				}else{
					PTCD_PTCD5=0;
				}*/
				break;
			case 5:
				if(aux3>=10){
					PTCD_PTCD5=1;
				}else{
					PTCD_PTCD5=0;
				}
				break;
			default:
				PTCD=0;
				break;
	}
}


#endif /* LEDS_H_ */
