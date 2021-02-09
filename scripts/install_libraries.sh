#!/bin/bash

# this script has two use cases
# 1 - CI testing and local development of TankControllerLib only (SHALLOW)
# 2 - Development of TankControllerLib and the supporting libraries
# comment this out if you want full depth for the supporting libraries (case 2)
export SHALLOW_MAIN='--depth 1 --branch main --single-branch '
export SHALLOW_MASTER='--depth 1 --branch master --single-branch '
# use this if you started with SHALLOW and now want the full repository with history
# git fetch --unshallow

# ensure we have `arduino_ci`
bundle config --local path vendor/bundle
bundle install

# set up directories
bundle exec ensure_arduino_installation.rb
cd $(bundle exec arduino_library_location.rb)

# add missing libraries
export GITHUB="https://github.com/Arduino-CI"
if [ ! -d "./Adafruit_BusIO" ] ; then
  git clone $SHALLOW_MASTER $GITHUB/Adafruit_BusIO.git
fi

if [ ! -d "./Adafruit_MAX31865" ] ; then
  git clone $SHALLOW_MAIN $GITHUB/Adafruit_MAX31865.git 
fi

if [ ! -d "./Ethernet" ] ; then
  git clone $SHALLOW_MASTER $GITHUB/Ethernet.git 
fi

if [ ! -d "./LiquidCrystal" ] ; then
  git clone $SHALLOW_MASTER $GITHUB/LiquidCrystal.git 
fi

if [ ! -d "./RTClib" ] ; then
  git clone $SHALLOW_MASTER $GITHUB/RTClib.git 
fi
