/*
 * servo_pca9685.c
 *
 *  Created on: 23 sep. 2020 y.
 *      Author: Leonov Dima
 */
#define SENSORS 0

#include "servo_pca9685.h"

static void PCA_RegWrite(uint8_t reg, uint8_t data);

/**
  **************************************************************************************************
  * @brief      PCA_ServoInit
  * @details    Init PCA9685 module
  * @return     ( void )
  **************************************************************************************************
**/
void PCA_ServoInit()
{
    // One-time init of I2C driver
    I2C_init();

    uint8_t i;
    uint8_t prescale = (25000000/4096/49.5);

    PCA_RegWrite(PCA9685_MODE2, PCA9685_OUTDRV);
    PCA_RegWrite(PCA9685_MODE1, PCA9685_SLEEP);

    PCA_RegWrite(PCA9685_PRESCALE, prescale);
    PCA_RegWrite(PCA9685_MODE1, PCA9685_ALLCALL | PCA9685_RESTART);

    for(i = 0; i < 16; i++)
    {
        PCA_ServoWrite(i, 0);
    }
}
/**
  **************************************************************************************************
  * @brief      PCA_ServoWrite
  * @details    Set servo angle
  * @param      servo_n - number of servo (chanel)
  * @param      angle   - angle to set
  * @return     ( void )
  **************************************************************************************************
**/
// void PCA_ServoWrite(uint8_t servo_n, uint8_t angle)
// {
//     if(angle > 180)
//     {
//         angle = 180;
//     }

//     uint16_t servo_data = 204 + angle * 1.2;

//     PCA_RegWrite(PCA9685_LED0_ON_L + 4 * servo_n, 0x01);
//     PCA_RegWrite(PCA9685_LED0_ON_H + 4 * servo_n, 0x01);
//     PCA_RegWrite(PCA9685_LED0_OFF_L + 4 * servo_n, servo_data);
//     PCA_RegWrite(PCA9685_LED0_OFF_H + 4 * servo_n, servo_data>>8);
// }

void PCA_ServoWrite(uint8_t servo_n, uint8_t angle)
{
    if(angle > 180)
    {
        angle = 180;
    }

    uint16_t servo_data = 100 + angle * 2;

    PCA_RegWrite(PCA9685_LED0_ON_L + 4 * servo_n, 0x00);
    PCA_RegWrite(PCA9685_LED0_ON_H + 4 * servo_n, 0x00);
    PCA_RegWrite(PCA9685_LED0_OFF_L + 4 * servo_n, servo_data);
    PCA_RegWrite(PCA9685_LED0_OFF_H + 4 * servo_n, servo_data>>8);
}

/**
  **************************************************************************************************
  * @brief      PCA_RegWrite
  * @details    Write register to PCA9685 memmory
  * @param      reg  - register address
  * @param      data - data to write
  * @return     ( void )
  **************************************************************************************************
**/
static void PCA_RegWrite(uint8_t reg, uint8_t data)
{
    uint8_t reg_data[2] = {reg, data};

    // initialize optional I2C bus parameters
    I2C_Params params;
    I2C_Params_init(&params);
    params.bitRate = I2C_400kHz;

    // Open I2C bus for usage
    I2C_Handle i2cHandle = I2C_open(CONFIG_I2C_0, &params);

    // Initialize slave address of transaction
    I2C_Transaction transaction = {0};
    transaction.slaveAddress = PCA9685_I2C_ADDRESS;

    // Write to I2C slave device
    transaction.writeBuf = reg_data;
    transaction.writeCount = sizeof(reg_data);
    transaction.readCount = 0;
    I2C_transferTimeout(i2cHandle, &transaction, 5000);

    // Close I2C
    I2C_close(i2cHandle);
}


