/*
 * ex3.c
 *
 *  Created on: Sep 30, 2024
 *      Author: tranm
 */

#include "ex3.h"
#include "ex1.h"
#include "timer.h"
#include "main.h"

const int MAX_LED = 4;
int led_buffer[4] = {1 , 2 , 3 , 4};
int index_led = 0;
int hour = 15, minute = 8, second = 50;

void update7SEG( int index_led ) {
	switch ( index_led ) {
		case 0 :
				display7SEG(led_buffer[0]);
	  			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
	  			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	  			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	  			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			break;
		case 1 :
				display7SEG(led_buffer[1]);
	  			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	  			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
	  			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	  			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			break;
		case 2 :
				display7SEG(led_buffer[2]);
	  			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	  			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	  			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
	  			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			break;
		case 3 :
				display7SEG(led_buffer[3]);
	  			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	  			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	  			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	  			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
			break;
		default :
			break;
	}
}

void updateClockBuffer(int minute, int hour){
	if (minute >= 10){
		led_buffer[2] = minute/10;
		led_buffer[3] = minute%10;
	}
	if (minute < 10 ){
		led_buffer[2] = 0;
		led_buffer[3] = minute;
	}
	if (hour >= 10){
		led_buffer[0] = hour/10;
		led_buffer[1] = hour%10;
	}
	if (hour < 10 ){
		led_buffer[0] = 0;
		led_buffer[1] = hour;
	}
}

void ex3(){
	if ( timer1_flag == 1 ){
		  	setTimer1(100);
		  	update7SEG(index_led);
		  	index_led++;
		  	if (index_led >= MAX_LED ) index_led = 0;
	}
  	if ( timer2_flag == 1 ){
  		setTimer2(100);
  		//to do
  		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
  		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
  	}
}

void ex5(){
		if ( timer1_flag == 1 ){
			  	setTimer1(25);

				  updateClockBuffer(minute, hour);
			  	update7SEG(index_led);
			  	index_led++;
			  	if (index_led >= MAX_LED ) index_led = 0;
		}
	  	if ( timer2_flag == 1 ){
	  		setTimer2(100);
			  second++;
			  if ( second >= 60 ) {
				  second = 0;
				  minute++;
			  }
			  if ( minute >= 60 ) {
				  minute = 0;
				  hour++;
			  }
			  if ( hour >= 24 ) {
				  hour = 0;
			  }
	  		//to do
	  		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	  		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
	  	}
}
