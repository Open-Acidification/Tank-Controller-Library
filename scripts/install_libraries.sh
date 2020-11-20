#!/bin/bash

# this script has two use cases
# 1 - CI testing and local development of TankControllerLib only (SHALLOW)
# 2 - Development of TankControllerLib and the supporting libraries
# comment this out if you want full depth for the supporting libraries (case 2)
export SHALLOW='--depth 1 --branch "master" --single-branch '
# use this if you started with SHALLOW and now want the full repository with history
# git fetch --unshallow

# set up directories
bundle exec ensure_arduino_installation.rb
cd $(bundle exec arduino_library_location.rb)

# add missing libraries
if [ ! -d "./Adafruit BusIO" ] ; then
  git clone $SHALLOW https://github.com/Arduino-CI/Adafruit_BusIO.git  "./Adafruit BusIO"
fi

if [ ! -d "./Adafruit_MAX31865" ] ; then
  git clone $SHALLOW https://github.com/Arduino-CI/Adafruit_MAX31865.git 
fi

if [ ! -d "./Ethernet" ] ; then
  git clone $SHALLOW https://github.com/Arduino-CI/Ethernet.git 
fi

if [ ! -d "./LiquidCrystal" ] ; then
  git clone $SHALLOW https://github.com/Arduino-CI/LiquidCrystal.git 
fi

if [ ! -d "./RTClib" ] ; then
  git clone $SHALLOW https://github.com/Arduino-CI/RTClib.git 
fi
