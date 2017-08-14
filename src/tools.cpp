#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
  
  // Creating an rmse vector with length of 4 and initializing values to 0
  VectorXd rmse(4);
  rmse << 0, 0, 0, 0;
  
  // Checking if Esitmation Vector length is not equal to ground truth vector length
  // or if Estimation Vector length is equal to 0
  if (estimations.size() != ground_truth.size() || estimations.size() == 0){
    cout << "Invalid estimation or ground_truth data" << endl;
	return rmse;
  }
  
  // Calculating difference squared of each value
  for (unsigned int i=0; i < estimations.size(); ++i){
    
	VectorXd difference = estimations[i] - ground_truth[i];
	
	// Element-wise multiplication to obtain squares of each data pointer
	difference = difference.array() * difference.array();
	rmse += difference;
	
  }
  
  // Calculating reduced mean of the same
  rmse = rmse/estimations.size();
  
  // Calculating the squared root
  rmse = rmse.array().sqrt();
  
  // Returning the result
  return rmse;
  
}

MatrixXd Tools::CalculateJacobian(const VectorXd& x_state) {
  /**
  TODO:
    * Calculate a Jacobian here.
  */
  
  MatrixXd Hj(3,4);
  
  //Get state parameters
  float px = x_state(0);
  float py = x_state(1);
  float vx = x_state(2);
  float vy = x_state(3);
  
  // Intermediate Calculations
  float c1 = px*px + py*py;
  float c2 = sqrt (c1);
  float c3 = (c1 * c2);
  
  // Prevent division by zero
  if(fabs(c1) < 0.0001){
    cout << "Error - tools.cpp - CalculateJacobian() -  Division by Zero" << endl;
	return Hj;
  }
  
  // Computing Jacobian Matrix
  Hj << (px/c2), (py/c2), 0, 0,
        -(py/c1), (px/c1), 0, 0,
		py*(vx*py - vy*px)/c3, px*(px*vy - py*vx)/c3, px/c2, py/c2;
  return Hj;
}
