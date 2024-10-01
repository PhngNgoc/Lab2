/*
 * ex1.c
 *
 *  Created on: Sep 29, 2024
 *      Author: tranm
 */

#include "ex1.h"
#include "timer.h"
#include "main.h"

int led = 0;

void display7SEG(int num){
	switch (num) {
		case 0:
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_SET);
			break;
		case 1:
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_SET);
			break;
		case 2:
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_SET);
			break;
		case 8:
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, GPIO_PIN_RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, RESET);
			HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, RESET);
			HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, RESET);
			HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, RESET);
			HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, SET);
			HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, RESET);
			HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, RESET);
			break;

	}
}


void ex1(){
	if(timer1_flag == 1){
			 	  		setTimer1(50);
			 	  		  //to do
			 	  		display7SEG(led+1);
			 	  		led = 1 - led;
			 	  		if (led == 0 ){
			 	  			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			 	  			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			 	  		}
			 	  		if (led == 1 ){
			 	  			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
			 	  			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			 	  		}

			 	  	  }
}

