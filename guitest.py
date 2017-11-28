# Sonali Mahendran and Alisa Momin, Team 6
# BIOE 421: Microcontroller Applications
# Final Project: SnapPainter
# Description: This code creates the user interface for our final project
# such that the user can press buttons to take a picture, draw a filter, and
# apply the filter to a specific facial feature.

#! usr/bin/python

from Tkinter import *
import tkFont
import RPi.GPIO as GPIO
import os

win = Tk()
# set font type and size
myFont = tkFont.Font(family = 'Impact', size = 30) 

# define what script to run for each button
def VideoON():
	os.system("python /home/pi/bioe421project/SaveVideo.py")

def FilterMustacheON():
        os.system("python /home/pi/bioe421project/facialrec.py")

def FilterEyesON():
        os.system("python /home/pi/bioe421project/facialreceyes.py")

def FilterLipsON():
        os.system("python /home/pi/bioe421project/facialreclips.py")

def DrawON():
	os.system("processing-java --sketch=/home/pi/bioe421project/drawpicture --run")
# allows user to exit the program when finished
def exitProgram():
	print("Exit Button pressed")
        GPIO.cleanup()
	win.quit()	


win.title("SnapPainter by Sonali Mahendran and Alisa Momin")
win.geometry('800x480') # set screen size
win.configure(bg = 'sky blue') # set background color

# create actual buttons for each functionality
exitButton  = Button(win, text = "Exit", font = myFont, command = exitProgram, height = 1 , width = 4, background = 'red', foreground = 'white') 
exitButton.pack(side = BOTTOM)

VideoButton = Button(win, text = "Take a video!", font = myFont, command = VideoON, height = 1, width = 14, background = 'deep pink', foreground = 'ivory' )
VideoButton.pack()

DrawButton = Button(win, text = "Draw a filter!", font = myFont, command = DrawON, height = 1, width = 14, background = 'coral', foreground = 'ivory' )
DrawButton.pack()

FilterMustacheButton = Button(win, text = "Add your filter below the nose!", font = myFont, command = FilterMustacheON, height = 1, width = 24 , background = 'teal', foreground = 'ivory' )
FilterMustacheButton.pack()

FilterEyesButton = Button(win, text = "Add your filter on the eyes!", font = myFont, command = FilterEyesON, height = 1, width = 24 , background = 'teal', foreground = 'ivory' )
FilterEyesButton.pack()

FilterLipsButton = Button(win, text = "Add your filter on the lips!", font = myFont, command = FilterLipsON, height = 1, width = 24 , background = 'teal', foreground = 'ivory' )
FilterLipsButton.pack()

mainloop()

