/*
 * ex2.c
 *
 *  Created on: Sep 29, 2024
 *      Author: tranm
 */

#include "ex2.h"
#include "ex1.h"
#include "timer.h"
#include "main.h"
int status = 1;

void ex2(){
	  if (timer1_flag == 1){
	  		setTimer1(50);
	  		  //to do
	  		switch (status){
	  			case 1 :
	  				display7SEG(1);
	 	  			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
	 	  			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	 	  			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	 	  			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
	  				break;
	  			case 2 :
	  				display7SEG(2);
	 	  			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
	 	  			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	  				break;
	  			case 3 :
	  				display7SEG(3);
	 	  			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
	 	  			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	  				break;
	  			case 4 :
	  				display7SEG(0);
	 	  			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
	 	  			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	  				break;
	  			default :
	  				break;
	  		}
	  		if ( status == 4 ) status = 0;
	  		status++;
	  }
	  	if ( timer2_flag == 1 ){
	  		setTimer2(100);
	  		//to do
	  		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	  		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
	  	}
}
