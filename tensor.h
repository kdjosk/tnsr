#ifndef TENSOR_H
#define TENSOR_H
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <cstdarg>
#include <vector>
#include <string>

class Tensor
{
  //Store values of the multidimensional tensor, e.g for rank = 2, dim = 3
  //     x 0 1 2
  //   y
  //   0   1 2 3
  //   1   4 5 6
  //   2   7 8 9
  // if you want value at (1, 2) it is stored at 2 * dim + 1
  std::vector<double> values;
  //Store the rank of the tensor
  int rank;
  //store the dimension of the tensor
  int dim;
  //store the name of the tensor
  std::string name;

public:

  //Constructors of the Tensor class
  Tensor(std::string n = "UNNAMED", int d = 3, int r = 1);
  //init stores initial values that are copied to the values of the tensor
  Tensor(std::string n, int d, int r, std::vector<double> init);
  //Empty destructor as no memory needs to be deallocated
  ~Tensor();

  //Add two tensors
  Tensor operator+ (const Tensor& t);
  //multiply tensor by constant k in convention Tensor * k
  Tensor operator* (double k);
  //multiply two tensors
  Tensor operator* (const Tensor& t2);
  //safely assign one tensor to the other
  Tensor operator= (const Tensor& t);

  //return value at x, y, z, ... . Number of parameters has to be equal to the
  //rank of the tensor
  double getVal(...);
  //same as above but parameters are inside a vector
  double getVal(std::vector<int> coordinates);

  //returs rank of the tensor
  int getRank(){ return rank; }

  //return the dimension of the tensor, e.g if the tensor is a cube NxNxN then dim = N;
  int getDim(){ return dim; }

  //return the rank of the tensor
  std::string getName(){ return name; }

  //return number of the elements inside the tensor, should always equal dim^rank
  // or 0 if no values have been assigned yet
  int getSize(){ return values.size(); }

  //Same as getVal but assigns val at given coordinates
  bool setVal(double val, ...);
  bool setVal(double val, std::vector <int> coordinates);

  //set dimension of the tensor
  bool setDim(int d){ dim = d; }

  //set rank of the tensor
  bool setRank(int r){ rank = r; }

  //set name of the tensor
  bool setName(std::string n){ name = n; }
};

#endif
