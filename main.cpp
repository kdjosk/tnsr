#include "tensor.h"
#include "menu_handler.h"
#include <sstream>
#include <cstdio>
using namespace std;

int main()
{
  string input;
  vector<Tensor> tnsrs;
  cout << "Welcome to tnsr, type help for help\n";

  while(input != "exit")
  {
    cin >> input;
    if(cin.fail()) exit(EXIT_FAILURE);

    if(input == "create")
    {
      handleCreate(tnsrs);
    }
    else if(input == "create_init")
    {
      handleCreateInit(tnsrs);
    }
    else if(input == "list")
    {
      handleList(tnsrs);
    }
    else if(input == "alg")
    {
      handleAlg(tnsrs);
    }
    else if(input == "get")
    {
      handleGet(tnsrs);
    }
    else if(input == "help")
    {
      handleHelp();
    }
    else if(input == "hello")
    {
      handleHello();
    }
    else
    {
      cout << "Try again" << endl;
    }
  }
}
