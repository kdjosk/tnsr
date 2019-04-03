#ifndef MENU_HANDLER
#define MENU_HANDLER
#include "tensor.h"
#include <sstream>
using namespace std;

//Search for a tensor with a given name in a vector of tensors and return its index
//if not found return -1
int getTensor(string name, vector<Tensor> &tnsrs);

//Create empty tensor
bool handleCreate(vector<Tensor> &tnsrs);
//Create tensor and fill it with numbers
bool handleCreateInit(vector<Tensor> &tnsrs);
//List all tensors in the workspace
bool handleList(vector<Tensor> &tnsrs);
//Handle basic algebraic operations on tensors
bool handleAlg(vector<Tensor> &tnsrs);
//Return value of given tensor at given coordinates
bool handleGet(vector<Tensor> &tnsrs);
//Air support
void handleHelp();
//Answers a greeting
void handleHello();

#endif
