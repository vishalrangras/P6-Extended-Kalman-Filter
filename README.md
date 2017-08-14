### Extended-Kalman-Filter ###

Submitted by - Vishal Rangras

The goals for this project are:

1. Initilizing Variables and Matrices in FusionEKF.cpp.
2. Initilizing the Kalman-Filter in FusionEKF.cpp.
3. Calling Predict and Update step of Kalman-Filter in ProcessMeasurement() of FusionEKF.cpp.
4. Implement Predict function in kalman_filter.cpp.
5. Implement Update function for Lidar Measurement Update and UpdateEKF for Radar Measurement Update in kalman_filter.cpp.
6. Implement CalculateRMSE and CalculateJacobian function in tools.cpp which will be used as helper functions.

** [Rubric](https://review.udacity.com/#!/rubrics/748/view) Points **

### Building the Project and Execution ###

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make` 
   * On windows, you may need to run: `cmake .. -G "Unix Makefiles" && make`
4. Run it: `./ExtendedKF `
5. See the results in Simulator

### Results ###

[image1]: ./img/Dataset-01.png "Dataset-01"
[image2]: ./img/Dataset-02.png "Dataset-02"

![alt text][image1]
![alt text][image2]