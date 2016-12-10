/*
 * bitManipulation.c
 *
 *  Created on: 10 de dic. de 2016
 *      Author: karl
 */

#include "stdio.h"

#define MOTOR1_A 2
#define MOTOR1_B 3
#define MOTOR2_A 1
#define MOTOR2_B 4
#define MOTOR3_A 5
#define MOTOR3_B 7
#define MOTOR4_A 0
#define MOTOR4_B 6

#define FORWARD 1
#define BACKWARD -1
#define RELEASE 0

int latch_state = 0;

int motorDirection(int motornum, int cmd) {
  int a, b;
  /* Section 1: choose two shift register outputs based on which
   * motor this instance is associated with.   motornum is the
   * motor number that was passed to this instance's constructor.
   */
  switch (motornum) {
	  case 1:
		a = MOTOR1_A; b = MOTOR1_B; break;
	  case 2:
		a = MOTOR2_A; b = MOTOR2_B; break;
	  case 3:
		a = MOTOR3_A; b = MOTOR3_B; break;
	  case 4:
		a = MOTOR4_A; b = MOTOR4_B; break;
	  default:
		return -1;
  }

  /* Section 2: set the selected shift register outputs to high/low,
   * low/high, or low/low depending on the command.  This is done
   * by updating the appropriate bits of latch_state and then
   * calling tx_latch() to send latch_state to the chip.
   */
  switch (cmd) {
  case FORWARD:               // high/low
    latch_state |= (1 << a);
    latch_state &= ~(1 << b);
    break;
  case BACKWARD:              // low/high
    latch_state &= ~ (1 << a);
    latch_state |= (1 << b);
    break;
  case RELEASE:               // low/low
    latch_state &= ~(1 << a);
    latch_state &= ~(1 << b);
    break;
  }
  return latch_state;
}


int main()
{
	printf("%d\n", motorDirection(1, FORWARD));
	printf("%d\n", motorDirection(1, BACKWARD));
	printf("%d\n", motorDirection(1, RELEASE));
	return 0;
}
