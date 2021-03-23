/*
 * servo_pca9685.h
 *
 *  Created on: 23 sep. 2020 y.
 *      Author: Leonov Dima
 */

#include <unistd.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

#ifndef _SERVO_PCA9685_H_
#define _SERVO_PCA9685_H_

#define SERVO_MIN       204 // 1us ; 4096 - 20 us ; 50 Hz
#define SERVO_CENTER    307
#define SERVO_MAX       409 // 2us
#define SERVO_ZONE      SERVO_MAX - SERVO_MIN

#define PCA9685_I2C_ADDRESS 0x40

// register
#define    PCA9685_MODE1            0x00
#define    PCA9685_MODE2            0x01
#define    PCA9685_SUBADR1          0x02
#define    PCA9685_SUBADR2          0x03
#define    PCA9685_SUBADR3          0x04
#define    PCA9685_PRESCALE         0xFE
#define    PCA9685_LED0_ON_L        0x06
#define    PCA9685_LED0_ON_H        0x07
#define    PCA9685_LED0_OFF_L       0x08
#define    PCA9685_LED0_OFF_H       0x09
#define    PCA9685_ALL_LED_ON_L     0xFA
#define    PCA9685_ALL_LED_ON_H     0xFB
#define    PCA9685_ALL_LED_OFF_L    0xFC
#define    PCA9685_ALL_LED_OFF_H    0xFD
#define    PCA9685_I2C_ADR          0x40

// Bits
#define    PCA9685_RESTART     0x80
#define    PCA9685_SLEEP       0x10
#define    PCA9685_ALLCALL     0x01
#define    PCA9685_INVRT       0x10
#define    PCA9685_OUTDRV      0x04

// Import I2C Driver definitions
#include <ti/drivers/I2C.h>
#include "ti_drivers_config.h"

void PCA_ServoInit();
void PCA_ServoWrite(uint8_t srvo_n, uint8_t angle);

#endif /* SERVO_PCA9685_SERVO_PCA9685_H_ */
