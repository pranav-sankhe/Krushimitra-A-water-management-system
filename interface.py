import serial 
from Tkinter import *


master = Tk()

    



ser = serial.Serial(
    port='/dev/ttyACM0',
    baudrate=9600,
    parity=serial.PARITY_ODD,
    stopbits=serial.STOPBITS_TWO,
    bytesize=serial.SEVENBITS
)
def function():
    val = input()
    ser.isOpen()
    ser.write(val)
    print(val);



b = Button(master, text="OK", command=function)
b.pack()
if(b>0):
    print "button pressed"
mainloop()