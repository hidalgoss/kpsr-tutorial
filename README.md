<p align="right">
  <img width="25%" height="25%"src="../images/klepsydra_logo.jpg">
</p>

# kpsr-tutorial

Public tutorial for using Klepsydra API. See the file
[Tutorial](./Tutorial.md) to see a step by step tutorial on how to
start with a small application and build up to integrate with
middlewares like ROS, ZMQ or DDS.


# Installation Instructions

## System dependencies

* Ubuntu 14.04 or above
* Google Tests (https://github.com/klepsydra-technologies/googletest)
* ROS Indigo or above (optional)
* ZMQ 3 or above (optional)
* DDS (optional)
* Cmake 3.5.1 or above
* gcc for C++11 5.4.0 or above.
* Doxygen (optional)
* Moxygen (https://github.com/sourcey/moxygen) (optional)

Note that Google Tests is pulled in automatically when installing this project and does not need separate installation.

### Dependencies installed by Klepsydra

No separate installation is needed for the following dependencies if the Klepsydra installation was done correctly.

* ConcurrentQueue (https://github.com/klepsydra-technologies/concurrentqueue)
* Cereal (https://github.com/klepsydra-technologies/cereal)
* spdlog (https://github.com/klepsydra-technologies/spdlog)

## Klepsydra dependencies

* kpsr-core (installed with yaml support)
* kpsr-build (https://github.com/klepsydra-technologies/kpsr-build)

kpsr-build will be pulled in automatically by the install process of this project.

### Installation

If you wish to follow the DDS and ROS examples in this
project, then the Klepsydra software must have been installed using the 
`-DKPSR_WITH_DDS=true` and `-DKPSR_WITH_ROS=true` arguments with cmake.

## System installation

	sudo apt install build-essentials
	sudo apt install git
	sudo apt install cmake

## Installation

Given ```$KLEPSYDRA_HOME```, for example ```$HOME/klepsydra```:

```
cd $KLEPSYDRA_HOME
git clone https://github.com/kpsr-devs/kpsr-tutorial.git
cd kpsr-tutorial
git submodule update --init
mkdir build
cd build
cmake ..
make
```

The cmake has the following options:

* -DKPSR_INSTALL_PATH to specify where kpsr-tutorial binaries should be installed (/opt/klepsydra by default)
* -DKPSR_WITH_DDS for building the DDS version of the tutorial.

### Install process for ROS Examples

For compiling ROS examples, we further need to install the kpsr-tutorial module. This can be done by running (after the above build process):
```
make install
```
Next, make a symlink in your ROS catkin workspace to point to  the ROS subfolder of this project.

```
cd $CATKIN_WORKSPACE/src
source install/setup.bash
ln -s $KLEPSYDRA_HOME/kpsr-tutorial/tests/kpsr_ros_tests
catkin_make
```

Run the ROS example as you would run any ros node.

#  License

&copy; Copyright 2019-2020, Klepsydra Technologies, all rights reserved. Licensed under the terms in [LICENSE.md](./LICENSE.md)

This software and documentation are Copyright 2019-2020, Klepsydra Technologies
Limited and its licensees. All rights reserved. See [license file](./LICENSE.md) for full copyright notice and license terms.

#  Contact

https://www.klepsydra.com
support@klepsydra.com
