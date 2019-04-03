#include "tensor.h"

Tensor::Tensor(std::string n, int d, int r): name(n), rank(r), dim(d), values(std::pow(d,r)) { }
Tensor::Tensor(std::string n, int d, int r, std::vector<double> init)
{
  //set of values has to be complete
  if(std::pow(d, r) != init.size())
  {
    std::cerr << "WARNING: WRONG VECTOR SIZE\n";
    exit(EXIT_FAILURE);
  }
  else
  {
    name = n;
    values = init;
    dim = d;
    rank = r;
  }
}

//Destruktor klasy Tensor
Tensor::~Tensor(){ }

Tensor Tensor::operator+ (const Tensor& t)
{
  //if tensors have the same rank and the same dimension, the result of addition
  //at coordinates x,y,... is equal to the sum of values of both ingredients at
  //those coordinates
  if(this->rank == t.rank && this->dim == t.dim)
  {
    Tensor res("noname", t.dim, t.rank);
    for(size_t i = 0; i < this->values.size(); ++i)
    {
      res.values[i] = this->values[i] + t.values[i];
    }
    return res;
  }
}

Tensor Tensor::operator* (double k)
{
  for(int i = 0; i < values.size(); ++i)
  {
    values[i] *= k;
  }

  return *this;
}

Tensor Tensor::operator* (const Tensor& t2)
{
  Tensor t1 = *this;
  if(t1.rank != t2.rank || t1.dim != t2.dim)
  {
    std::cerr << "ERROR: TENSORS HAVE DIFFERENT RANKS AND/OR DIMENSIONS\n";
    exit(EXIT_FAILURE);
  }

  Tensor res("unnamed", t1.dim, t1.rank);

  //The result of multiplication of two tensors at index x, y, ... is equal to
  //the product of the values at those coordinates in the two factors
  for(int i = 0; i < t1.values.size(); ++i)
  {
    res.values[i] = t1.values[i] * t2.values[i];
  }

  return res;
}

Tensor Tensor::operator= (const Tensor& t)
{
  this->dim = t.dim;
  this->rank = t.rank;

  std::vector<double> temp(t.values.size());
  this->values.swap(temp); //Swap for an empty vector of the same size;
  for(int i = 0; i < t.values.size(); ++i)
  {
    this->values[i] = t.values[i];
  }

  return *this;

}

double Tensor::getVal(...)
{
  va_list coordinates;
  va_start(coordinates, rank);

  int ind = 0;
  for(size_t i = 0; i < rank; ++i)
  {
    int c = va_arg(coordinates, int);
    if(c > dim || c < 0)
    {
      std::cout << "ERROR: Incorrect coordinate number\n";
      exit(EXIT_FAILURE);
    }
    else
    {
      //to access use dimensions bigger than 1 use formula (x, y, z, ...) = x + y * dim + z * dim^2 + ...
      ind += c*std::pow(dim, i);
    }
  }
  va_end(coordinates);
  if(ind < values.size() && ind >= 0) return values[ind];
  else
  {
    std::cerr << "COORDINATES NOT CORRECT" << std::endl;
    exit(EXIT_FAILURE);
  }
}

double Tensor::getVal(std::vector<int> coordinates)
{
  if(coordinates.size() != rank)
  {
    std::cout << "WRONG COORDINATES\n";
    exit(EXIT_FAILURE);
  }

  int ind = 0;
  for(int i = 0; i < coordinates.size(); ++i)
  {
    ind += coordinates[i] * std::pow(dim, i);
  }
  if(ind < values.size() && ind >= 0) return values[ind];
  else
  {
    std::cerr << "COORDINATES NOT CORRECT" << std::endl;
    exit(EXIT_FAILURE);
  }
}

bool Tensor::setVal(double val, ...)
{
  va_list coordinates;
  va_start(coordinates, rank);

  int ind = 0;
  for(size_t i = 0; i < rank; ++i)
  {
    int c = va_arg(coordinates, int);
    if(c > dim || c < 0)
    {
      std::cout << "ERROR: Incorrect coordinate number\n";
      exit(EXIT_FAILURE);
    }
    else
    {
      ind += c*std::pow(dim, i);
    }
  }

  va_end(coordinates);
  if(ind < values.size() && ind >= 0) values[ind] = val;
  else
  {
    std::cerr << "COORDINATES NOT CORRECT" << std::endl;
    return false;
  }
  return true;
}

bool Tensor::setVal(double val, std::vector<int> coordinates)
{
  if(coordinates.size() != rank)
  {
    std::cout << "WRONG COORDINATES\n";
    exit(EXIT_FAILURE);
  }

  int ind = 0;
  for(int i = 0; i < coordinates.size(); ++i)
  {
    ind += coordinates[i] * std::pow(dim, i);
  }
  if(ind < values.size() && ind >= 0) values[ind] = val;
  else
  {
    std::cerr << "COORDINATES NOT CORRECT" << std::endl;
    return false;
  }
  return true;
}
