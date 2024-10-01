/*
 * ex3.h
 *
 *  Created on: Sep 30, 2024
 *      Author: tranm
 */

#ifndef INC_EX3_H_
#define INC_EX3_H_

extern const int MAX_LED;
extern int led_buffer[4];
extern int index_led;
void update7SEG( int index_led );
void updateClockBuffer(int minute, int hour);
void ex3();
void ex8();

#endif /* INC_EX3_H_ */
