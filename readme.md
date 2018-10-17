# C++ Boilerplate
[![Build Status](https://travis-ci.org/CP-TSAI/ENPM808X-Midterm-Project.svg?branch=master)](https://travis-ci.org/CP-TSAI/ENPM808X-Midterm-Project)
[![Coverage Status](https://coveralls.io/repos/github/CP-TSAI/ENPM808X-Midterm-Project/badge.svg?branch=master)](https://coveralls.io/github/CP-TSAI/ENPM808X-Midterm-Project?branch=master)
---

## Overview

Perception is the key to intelligent behavior in Robotics, and situational awareness is crucial for safe operation in the real and dynamic environments. Our team propose a project to implement the perception module in Acme robotic system. Our design utilizes techniques of Harr cascade, HOG feature and SVM classifier for human detection upon images.

Haar cascade is a method which uses a cascade function to train from positive and negative images, and use the function to detect objects with similar features. Histograms of Oriented Gradients (HOG) is a feature which calculates frequency of gradient orientation in local part of an image. It allows the same object to produce similar feature descriptor whenviewed under different conditions. The Support Vector Machine (SVM) represents inputs as points in a mapped space and calculate largest decision boundary for each category. The SVM model takes features from Harr cascade and HOG feature, and creates a classifier to classify image objects.

After the processing input image with the above HOG detection algorithm, the program displays bounding boxes of detected humans, and prints the position of each bounding box. The printed bounding box positon resembles the coordinates between the humans and the robot. The software is implemented with C++ on Ubuntu 16.04. Libraries such as OpenCV are applied to enhance image processing.

## Statement of Work
- Create detection module and declare classes, class variables and class methods
- Design unit tests for the module and each method
- Implement methods to handle input image dataset and down sample images
- Implement human detection algorithm using OpenCV library
- Implement methods to calculate object location in robot reference and display human position and their sizes
- Verify unit testing
- Create comments using Doxygen style

## Output Result

![OutputImage1](https://raw.githubusercontent.com/CP-TSAI/ENPM808X-Midterm-Project/master/imageDetected/person_062.bmp)


## Licence
- Mit Licence
```
Copyright <2018> <Chin-Po Tsai> <Chien-Te Lee>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the "Software"), to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions
of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
IN THE SOFTWARE.
```


## Dependencies
- Ubuntu 16.04
- OpenCV 3.3
- CMake

## Standard install via command-line
- clone from repository
- create build folder
- build program
```
git clone --recursive https://github.com/CP-TSAT/ENPM808X_Midterm
cd <repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## Run Demo Example
- in <repository>/build directory
```
./app/shell-app
```

## Run Unit Tests
- in <repository>/build directory
```
./test/cpp-test
```


## Pair Programming and SIP Process
The product backlog, iteration backlog, and worklog googlesheet is at: [Product Backlog](https://docs.google.com/spreadsheets/d/1iUGy3wYF-gTKpujZMg4uWaInznVW3jiqRCExSMgYiPU/edit?usp=sharing)







