# Movement :wave:

**Hello everyone! This is my sixth challenge in course from Ucode IT Academy featuring Ajax Systems.**

## The main idea  ✨

**Make our first gestures with robohand :scream:**

## Our equipment

-   **TI LaunchPad CC1352R1 x2**
-   **TI Sensors BoosterPack “BOOSTXL-SENSORS”**
-   **Laptop or PC**
-   **Ajax special edition super robohand**

## What is my project about

**This project was made to gain knowledge about servo-motors, servo-motor driver PCA9685, gyroscope, accelerometer, madgwick filter.**

## How does it works

**First microcontroller gets raw data from gyroscope and accelerometer (“BOOSTXL-SENSORS”), and puts this data into the madgwick filter. After that, writes filtered x coordinate into the serial terminal. Python script reads current x coordinate and writes it into another serial terminal. From another serial terminal, our second launchpad gets coordinate and puts all fingers in the correct position.**

## Example
**Look at the launchpad in my hand and look at robohand. :open_mouth:**
![Alt Text](https://github.com/IlayMarchenko/movement_ucode_ajax_iot/blob/master/materials/ezgif.com-video-to-gif.gif)

## How you could run it

1. **Download my project.**
2. **Using the Code Composer Studio, built a project in folder “i2cbmi160_CC1352R1_LAUNCHXL_tirtos_ccs”.**
3. **Flash binary file into your first microcontroller. It should be connected with Sensors BoosterPack. You could use CCS or UniFlash.**
4. **Using the Code Composer Studio, built a project in folder “servo_pca9685”.**
5. **Flash binary file into your second microcontroller. It should be connected with Sensors BoosterPack. You could use CCS or UniFlash.**
6. **Open Python_script/connection.py and run it.**
7. **Connect your two launchpads with your computer.**
8. **Connect your second launchpad with robohand**

## Author

**Illia Marchenko, 18 y.o, Ukraine, Kiev, junior embedded developer, email:  [ilya.marchenko02@gmail.com](mailto:ilya.marchenko02@gmail.com).**

## [](https://github.com/IlayMarchenko/transfer_iot_ajax_ucode/blob/master/README.md#note)Note

**Do not forget that to work with TI Launchpads and Sensors BoosterPack, you should download SDKs.**
