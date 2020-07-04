#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "Variables.h"
#include "Config.h"
#include "LecturaIR.h"
#include "LEDs.h"


void main(void){
  EnableInterrupts;
  /* include your code here */

  SYSTEM_CONFIG();
  PORT_CONFIG();
  //PWM_CONFIG();
  //SCI_CONFIG();
  //RTC_CONFIG();
  ADC_CONFIG(); 
  for(;;) {
	  //aux=ADC1R;
	  LecturaIR();
	  //luz();
    //__RESET_WATCHDOG();	/* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}

//	FUNCIONES

void CONVERSOR(short tiempoenc){
velocidad = ((tpmf/tiempoenc)*6.28/300);
velocidad2= ((tpmf/tiempoenc)*6.28/300);
}
//	INTERRUPCIONES

interrupt RTC_INT_VECTOR void RTC_INT(void){
	SRTISC_RTIACK=1;
	CONTADOR++;
	if(CONTADOR < 44){
		ref = ref + 0.25;
		ref2 = ref2 + 0.25;
	}
    if(CONTADOR >= 88){
		ref = ref - 0.25;
		ref2 = ref2 - 0.25;
	}
	if(CONTADOR == 132){
		CONTADOR = 0;
		ref=0;
		ref2=0;
	}
}
interrupt TPM1_CH1_INT_VECTOR void Encoder_2A(void){
	ESTADO = ((PTED & 0b00001000)>>2)+(PTFD);
	if(ESTADO == 3){
			ENC_2A = TPM1C1V;
			GIRO = 0;
			//VEL = (ENC_2A/FREC);
			TPM1CNT = 0;
		}else{
			ENC_2A = TPM1C1V;
		}
	TEMP = TPM1C1SC;
	TPM1C1SC_CH1F = 0;
	
	//CONVERSOR(ENC_2A);
	
}
interrupt TPM1_CH2_INT_VECTOR void Encoder_2B(void){
	ESTADO = ((PTED & 0b00001000)>>2)+(PTFD);
	if(ESTADO == 3){
			ENC_2B = TPM1C2V;
			
			//VEL = (ENC_2B/FREC);
			GIRO = 1;
			TPM1CNT = 0;
		}else{
			ENC_2B = TPM1C2V;
		}
	/*CONTADOR++;
	if(CONTADOR == 0x0FFF){	
		velocidad = velocidad;
		CONTADOR = 0;	
	}*/
	CONVERSOR(ENC_2B);
	TEMP = TPM1C2SC;
	TPM1C2SC_CH2F = 0;
}

