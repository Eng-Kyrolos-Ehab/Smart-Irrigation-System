# Smart-Irrigation-System
Smart Irrigation System using Stm32f103C6 &amp; Arduino ide


how to use stm32f103c6 with arduino ide?

there are the steps:
-----------------------------------------------------------------------------------
setup stm with utility

1) download & setup : st-link utility & arduino ide
2) open st-link utility 
3) connect st-link wtih pc & stm 

4) in stm32 there are two yallow switches : 
        
               - make it in side u can see and read register names correctly from left side to right side
               - now move the first switch from 0 to 1  "u can search for videos about how to setup stm32"
 
5) press connect then choose add file in utiltiy

6) choose file whose name: generic_boot20_pc13.bin

7) then program & verify

8) back the first switch from 1 to 0 


done.



<< now u can use it with arduino ide ^-^ >>


-----------------------------------------------------------------------------------
setup arduino ide to use stm:

1) Disconnect st-link
2) connect stm32 with pc using micro usb cable to use it in bootloader mode
3) In your Arduino IDE, go to File > Preferences.
              - in white box put this:

                        http://dan.drown.org/stm32duino/package_STM32duino_index.json
 
4) Go to Tools > Board > Boards Manager.

5) Search for STM32,onewire,dallas select latest version and click Install. 
"we will put these libraries with the readme file"

6) From the Tools > Board > STM32 Board, select Generic STM32F1c6/STM32F1c8 fake series.


if u have stm32f103c8:
7) Select Tools > Board Part Number > Blue Pill F103C8


else:

7) tools > upload methods > stm32duino bootloader

8) tools > port > COM5 or 7 

note: if no ports shown try this way:
- go to file > examples > basic > blink

- now change pin to PC13

- press upload 

now back to ports it will be shown to u


done.


now u can be able to start programming using C Programing ^-^
