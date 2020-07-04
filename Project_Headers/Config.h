/*
 * Config.h
 *
 *  Created on: Nov 3, 2018
 *      Author: Miguel Rivera Ser
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#define KBI_INT_VECTOR 22 
#define RTC_INT_VECTOR 25 
#define TPM1_CH1_INT_VECTOR 6 
#define TPM1_CH2_INT_VECTOR 7 

#define BIT(pos) (1<<(pos))
#define tpmf 84375

void luz(void);

void SYSTEM_CONFIG(){
	SOPT = 0b01000000;	
	//VELOCIDAD DE BUS 10.8MHz
	ICGC1=0b00101000;
	ICGC2=0b00110000;

}
void PORT_CONFIG(){
	PTAD = 0x00;    //Salidas a 0V
	PTBD = 0x00;    //Salidas a 0V
	PTCD = 0x00;    //Salidas a 0V
	PTDD = 0x00;    //Salidas a 0V
	PTED = 0x00;    //Salidas a 0V
	PTFD = 0x00;    //Salidas a 0V
		
	PTBDD = 0b11000000;	//Se habilitan todos los pines como salidas (VALOR HEX)
	PTADD = 0b00000011;//xFF;   //Se habilitan todos los pines como salidas (ANODOS)
	PTCDD = 0b01111100;
	//PTCD=0x1F;
	//PTDDD = 0b11111101; // se usara el puerto ptd1 como ADC_ADIP9
	//PTEDD = 0b00001100; // se usara el puerto PTE2 como activador de leds emisores
	//PTFDD = 0b00110001;//xFF;
	//PTED  = 0b00000100;
	
	
}
void PWM_CONFIG(){
	//Canal 2 - PWM Motores - Modo: Centered PWM
	TPM2SC=0b00101000;
	TPM2MOD=242;
	TPM2C1SC=0b00001000;
	TPM2C1V=121;
	
	TPM2C0SC=0b00001000;
	TPM2C0V=85;
	
	//Canal 1 - Captura señal encoder - Modo: Input Capture
	TPM1SC=0b00001111;
	TPM1MOD=0; //Conteo continuo
	TPM1C1SC=0b01000100;  //Canal 1 - Encoder 2A
	TPM1C2SC=0b01000100;  //Canal 2 - Encoder 2B
}
void SCI_CONFIG(){
	SCI1C1 = 0;
	SCI1C2 = 0x0c;
	SCI1C3 = 0;
	SCI1BD = 72;
}
void ADC_CONFIG(){	
	ADC1CFG=0b11111000;
	ADC1SC2=0b00000000;
	APCTL1=	0b00011111;
	APCTL2=	0b00000000;
	//APCTL3=0b00000000;
	
}
void RTC_CONFIG(){
	SRTISC = 0b00010101;
}

#endif /* CONFIG_H_ */
