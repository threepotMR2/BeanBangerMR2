BeanBangerMR2
=============

<img src=https://github.com/threepotMR2/BeanBangerMR2/blob/master/PXL_20260322_195308444.jpg>

<img src=https://github.com/threepotMR2/BeanBangerMR2/blob/master/PXL_20260322_195332580.jpg>

<img src=https://github.com/threepotMR2/BeanBangerMR2/blob/master/Screenshot%20from%202026-03-22%2019-50-18.png>


This is an adaption/fork for the BeanMPX project by fiztech-code - thank you for amazing work, this would not exist without you. I have no idea what I'm doing but have butched the BeanMPX project to make this do what it should. It is probably the worst code man has seen, and I am probably using Github in totally the wrong way. Please forgive my stupidity and ignorance!

All you need is in the BeanBangerMR2 folders, one is the arduino project, the other is the gerber/bom for the PCB.

1) Simply upload the gerber to pcbway or jlcpcb and get some made for peanuts.
2) The list of components you need is printed on the circuit board and its all though hole easy soldering
3) upload the arduino sketch to the arduino nano
4) wire in the wire from the alternator charge sense line, the oil pressure switch, take a spur from the temp sensor, 12v, ground and the bean wires (either way doesn't matter).

Then as soon as you turn on the car, the warning lights will works and the temp gauge works.

Here is some testing video footage and description of usage:-
https://www.youtube.com/watch?v=NijV0-c2hg0

You will see it completed here:-
https://www.youtube.com/shorts/5FSTMIWvpoY

There is a very messy spreadsheet that "helps" to make the formula for to convert the analogue input voltage to the BEAN temp hex value for the arduino sketch so you can calibrate it for different temp sensors and ecu combinations.

Enjoy! 

ThreepotMR2

Components list:-

3 x 10k resistors
5 x 1k resistors
2 x 330 ohm resistors
4 x 2n3904 transistors
2 x PC817 optocouplers
1 x arduino nano
Some 2.54mm pitch PCB Mount Screw Terminal blocks ... or just solder your wires direct to the PCB




How To wire it in
=================

Inside the cluster the MPX1 and MPX2 wires are both joined together, so you can use either or both! The do the same thing.

<img src=https://github.com/threepotMR2/BeanBangerMR2/blob/master/howtowirebeanMPXcluster.png>

This diagram shows you what each wire to use from the MR2 engine ecu connector.

<img src=https://github.com/threepotMR2/BeanBangerMR2/blob/master/ecu%20connector.png>

BUT it you need to wire the temp sensor to your current ECU, which has a pullup resistor in it and thus the beanbanger works if you pull a spur from your temp sensor. e.g. your temp sensor will be feeding both the beanbanger and your engine ecu. The temp gauge calibration supplied in the arduino code is for Ecumaster Emu Black which has a 2.2k pull up resistor.



How To Calibrate te temp gauge algo for different sensor and ecu combinations
=============================================================================


In the "BeanBanger_works.ino" file this is this bit of code on lines 42 to 45

      //Does the temp gauge Algo is 75000/(ADC+300)).... ADC 0-1023 is 0-5v
      //Engine Temp Gauge moves 90-255 but normal range deadzone 165-212
      t = analogRead(A7);  //read temp sensor voltage on analogue pin 2  
      t = 75000/(t+300);

We are reading the analog value from the ADC Value from arduino input pin "A7", then we do a bit of maths on it:-

75000 / ( ADC value + 300) = bean temp value

You can play with this mnaths to create a value which ranges from 90 to 255 which is the gauge needle possition. Its weird though, 90 to 165 is cold to upto the middle of the gauge, then there is a deadzone from 165 to 212 which is normal temperature, then if you go about this the needle shoots up quickly.

So roughly Degrees C x 2 = Bean value ......... e.g. 90c x 2 = 180 = which is in the dead zone being normal.

Thus the deadzone starts at 82.5c and goes upto 106c which is pretty reasonable. Anything above this makes the gauge shoot up, e.g 107c = 214 bean

There is a spreadsheet here called temp gauge algo.ods https://github.com/threepotMR2/BeanBangerMR2/blob/master/temp%20gauge%20algo.ods which is an utter mess but if you play with it you will see it draws you some graphs and will let you experiement with your algo, it is truly an utter mess though.



