#! usr/bin/python

from Tkinter import *
import tkFont
import RPi.GPIO as GPIO
import os

win = Tk()

myFont = tkFont.Font(family = 'Impact', size = 30) 

def VideoON():
	os.system("python /home/pi/bioe421project/SaveVideo.py")

def FilterON():
        os.system("python /home/pi/bioe421project/facialrec.py")

def DrawON():
	os.system("processing-java --sketch=/home/pi/bioe421project/drawpicture --run")

def exitProgram():
	print("Exit Button pressed")
        GPIO.cleanup()
	win.quit()	


win.title("BIOE 421 Final Project by Sonali Mahendran and Alisa Momin")
win.geometry('800x480')
win.configure(bg = 'sky blue')

exitButton  = Button(win, text = "Exit", font = myFont, command = exitProgram, height = 1 , width = 4, background = 'red', foreground = 'white') 
exitButton.pack(side = BOTTOM)

VideoButton = Button(win, text = "Take a video!", font = myFont, command = VideoON, height = 2, width = 14, background = 'deep pink', foreground = 'ivory' )
VideoButton.pack()

DrawButton = Button(win, text = "Draw a filter!", font = myFont, command = DrawON, height = 2, width = 14, background = 'coral', foreground = 'ivory' )
DrawButton.pack()


FilterButton = Button(win, text = "Add your filter!", font = myFont, command = FilterON, height = 2, width = 14 , background = 'teal', foreground = 'ivory' )
FilterButton.pack()

mainloop()

