This is a very simple read-only serial terminal that reads Serial1 and prints the output to the Seedstudio TFT Touch Shield V1.0 mounted on an Arduino MEGA ADK.

http://www.seeedstudio.com/wiki/TFT_Touch_Shield_V1.0

I wrote it so I could see the Mighty Ohm Geiger Counter's serial output in a portable way.

http://mightyohm.com/blog/products/geiger-counter/

It includes the libraries that worked with Arduino 1.0.5-r2

The terminal is currently a hack job that neither constrains the length of serial input safely or the output to the display correctly.