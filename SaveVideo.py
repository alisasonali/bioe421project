# Sonali Mahendran and Alisa Momin, Team 6
# BIOE 421: Microcontroller Applications
# Final Project: SnapPainter
# Description: Allows the user to take their own video to 
# add a filter to. Saves the video as a MP4 using conversion tool.

#! /usr/bin/python

import picamera
import cv2
import os

# removes video already present if this code was run previously
os.system("rm find_our_faces.mp4") 

with picamera.PiCamera() as camera:
	camera.resolution = (640, 480) #camera resolution set
	camera.start_preview()
	camera.framerate = 24
	camera.start_recording('/home/pi/bioe421project/find_our_faces.h264') #starts h264 recording
	camera.wait_recording(10) # captures for 10 seconds
	camera.stop_recording()
	os.system("MP4Box -fps 30 -add /home/pi/bioe421project/find_our_faces.h264 /home/pi/bioe421project/find_our_faces.mp4")	
