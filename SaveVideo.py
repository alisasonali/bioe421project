#! /usr/bin/python

import picamera
import cv2
import os

os.system("rm find_our_faces.mp4") 

with picamera.PiCamera() as camera:
	camera.resolution = (640, 480)
	camera.start_preview()
	camera.framerate = 24
	camera.start_recording('/home/pi/bioe421project/find_our_faces.h264')
	camera.wait_recording(10)
#	key =  cv2.waitKey(1) & 0xFF  
#	if key == ord('q'):
	camera.stop_recording()
#        ffmpeg -i find_our_faces.h264 -vcodec mjpeg -qscale 1 -an find_our_faces.avi
	os.system("MP4Box -fps 30 -add /home/pi/bioe421project/find_our_faces.h264 /home/pi/bioe421project/find_our_faces.mp4")	
