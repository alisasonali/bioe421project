#! /usr/bin/python

import picamera
import cv2

camera = picamera.PiCamera()
camera.resolution = (640, 480)
camera.start_preview()
camera.start_recording('my_video.h264')
camera.wait_recording(10)
#key = cv2.waitKey(1) & 0xFF

#if key == ord('q'):
camera.stop_recording()
