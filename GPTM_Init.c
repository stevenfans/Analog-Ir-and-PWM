// THIS WILL CONTAIN THE MAIN INITIALIZATION FOR THE 
// GENERAL PURPOSE TIMER for TIMER 0 Time B
// INPUT EDGE TIME CAPTURE MODE

#include "GPTM_Init.h"
#include "tm4c123gh6pm.h"

void GPTM_Init(void){
	//1. ensure that the timer enable is disabled
	TIMER0_CTL_R &= ~TIMER_CTL_TAEN; 
	
	//2. Write the GPTM Configuration (GPTMCFG) register with a value of 0x0000.0004
  TIMER0_CFG_R = 0x000000004; 
	//3. In the GPTM Timer Mode (GPTMTnMR) register, write the TnCMR field to 0x1 and 
	//the TnMR field to 0x3 and select a count direction by programming the TnCDIR bit.
	//0000.0000.0000.0111
	TIMER0_TAMR_R |= 0x07;
	
	//4. Configure the type of event that the timer captures by writing the TnEVENT field 
	//of the GPTM Control (GPTMCTL) register.
	// 00-Positive; 01-Negative; 10-Reserved; 11-Both
	TIMER0_CTL_R |= 0xC; 
	
	//5. If a prescaler is to be used, write the prescale value to the GPTM Timer n Prescale Register (GPTMTnPR).
	//TIMER0_TAPR_R = 0xFFFF; 
	//do we need a prescalar for this???
	//6. Load the timer start value into the GPTM Timer n Interval Load (GPTMTnILR) register.
	TIMER0_TAILR_R = 0xFFFF;
	//7. If interrupts are required, set the CnEIM bit in the GPTM Interrupt Mask (GPTMIMR) register.
	//TIMER0_IMR_R = 0x04; 
	// using interrupts??
	//8. Set the TnEN bit in the GPTM Control (GPTMCTL) register to enable the timer and start counting.
	TIMER0_CTL_R |= TIMER_CTL_TAEN; 
	
	//9. Poll the CnERIS bit in the GPTMRIS register or wait for the interrupt to be generated (if enabled).
	//	 In both cases, the status flags are cleared by writing a 1 to the CnECINT bit of the GPTM Interrupt Clear (GPTMICR) register. 
	//   The time at which the event happened can be obtained by reading the GPTM Timer n (GPTMTnR) register.
	
}