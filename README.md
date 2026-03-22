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
