#ifndef CHHROBOTICS_CPP_BEZIERCURVE_H
#define CHHROBOTICS_CPP_BEZIERCURVE_H

#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include"utils.h"
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

double factorial(int n);

Node bezierCommon(vector<Node>Ps,  double t);
vector<Node> beziertest(vector<Node>Ps);
#endif