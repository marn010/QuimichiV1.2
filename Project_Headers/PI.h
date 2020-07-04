/*
 * PI.h
 *
 *  Created on: Nov 4, 2018
 *      Author: Miguel Rivera Ser
 */

#ifndef PI_H_
#define PI_H_

void PI(){
	error=ref-velocidad;
	errorabs=(float)errorabs+(error*0.001);
	control=(float)(kp*error)+(ki*errorabs);
	if(control>=0){
      t_mod=(int)(control*240/100);
        if(t_mod>240){
        	TPM2C1V=240;	
        } else{
        	TPM2C1V=t_mod;
        }
        
	}else{
	  TPM2C1V=0;	
      t_mod=-1*(int)(control*240/100);	     
	}
	// segundo motor
	error2=ref2-velocidad2;
	errorabs2=(float)errorabs2+(error2*0.001);
	control2=(float)(kp2*error)+(ki2*errorabs2);
	if (control2>=0){
		t_mod2=(int)(control2*240/100);
		if (t_mod2>240){
			TPM2C0V=240;
		} else{
			TPM2C0V=t_mod2;
		}
	}else{
		TPM2C0V=0;
		t_mod2=-1*(int) (control2*240/100);
	}
}

#endif /* PI_H_ */
