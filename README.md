# Energy-Saving-Super-Bright-LED-Light

This project was done as a semester project under *_Electronic Design Realization_* module in Electronic and Telecommunication department. Main objective of this project was manufacture a consumer product for the market.   

## ***Project Description***

The product is Super bright - 18W Ceiling LED light with adjustable brightness and color temperature using an IR remote. The user can easily mount the light on their ceiling and control it using a remote with friendly user interface. In addition to brightness and color adjustability, it has lot of features and functions which makes more convenient for users.

----

## ***Features and Functions***

- Power - 18W
- Color Temperature - 5000K to 10000K
- Remote type - IR Remote , Works within 7 meter range
- Operating Voltage - 230V 50/60 Hz AC

### Functions of the remote

- Continuous Brighness and color temperature adjustability
- Enabling timers to **auto turn off**.
- Direct 25% / %50 brightness enabling option
- Special pre defined color modes - _Warm white, Cool white and Daylight white_

----

## ***Functionality of the Light***

This light consists two main parts. First one is the LED light panel and the second part is the LED driver. LED Driver controls the current to the LED light panel and maintains a constant current.
Led light is powered up from main 230V AC supply.At first, Main voltage is converted into 24V DC voltage using a 24V 1A switching mode power supply (SMPS). Then the current is divided into 4 channels and fed into mosfet based constant current sources. Those 4 current sources keep the current through themselves constant always and provide to LED panel. An IR reciever recieves the signals from IR remote and  **ATTINY 85** microcontroller decodes those signal to provide the control signals for the current sources to activate the required function.   


### _LED Driver_

Consist of 4 mosfet based constant current sources. Current limit of those sources are controlled by control signals from attiny85 microcontroller.


<img src="https://github.com/ShehanHMK/Energy-Saving-Super-Bright-LED-Light/assets/121402775/13024d29-f5ca-4a4e-96aa-332f408ee1dd" width = "500" />
---
<img src="https://github.com/ShehanHMK/Energy-Saving-Super-Bright-LED-Light/assets/121402775/c47795af-b249-4706-a1d4-3a818656511c" width="300" />


-----


### _LED Light Panel_

4 Led channels with 7 series high power 1W led in each string are mounted on a PCB with aluminium as the base material. It provides a good thermal conductivity and acts a heat sink to each of those 1W small led bulbs.

<img src="https://github.com/ShehanHMK/Energy-Saving-Super-Bright-LED-Light/assets/121402775/6e55a20e-0956-4ee6-a854-ab207a088dd6" width = "500" />
---
<img src="https://github.com/ShehanHMK/Energy-Saving-Super-Bright-LED-Light/assets/121402775/8b624231-9019-4f98-b2cc-755ac6e3ed00" width = "300" />


### Schematic designs and PCB layouts were designed using _Altium Designer_ software and printed fron [JLC PCB](https://jlcpcb.com/) .

-----

## ***Enclosure***

An Enclosure to mount the LED panel and another enclosure to place the SMPS and driver circuit were designed using _Solidworks 3D_ software and manufactured using 3D printing.

<img src="https://github.com/ShehanHMK/Energy-Saving-Super-Bright-LED-Light/assets/121402775/4a5e9ec0-d02e-41c5-9335-3394c3c6d7ba" width = "400" />
---
<img src="https://github.com/ShehanHMK/Energy-Saving-Super-Bright-LED-Light/assets/121402775/88b30cfa-effb-4478-9212-23a92762b23c" width = "400" />


-----

## ***Assembled LED Light***

<img src="https://github.com/ShehanHMK/Energy-Saving-Super-Bright-LED-Light/assets/121402775/ac024643-c4e0-4d6a-b652-9c32de854765" width = "600" />












