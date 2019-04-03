#include "menu_handler.h"
#include <sstream>

int getTensor(string name, vector<Tensor> &tnsrs)
{
  for(int i = 0; i < tnsrs.size(); ++i)
  {
    if(tnsrs[i].getName() == name)
    {
      return i;
    }
  }
  return -1;
}

bool handleCreate(vector<Tensor> &tnsrs)
{
  string name;
  int dim, rank;

  cin >> name >> dim >> rank;
  if(cin.fail())
  {
    cerr << "ERROR: INVALID INPUT\n";
    return false;
  }

  Tensor t(name, dim, rank);
  tnsrs.push_back(t);
}

bool handleCreateInit(vector<Tensor> &tnsrs)
{
  string name;
  int dim, rank;

  cin >> name >> dim >> rank;
  if(cin.fail())
  {
    cerr << "ERROR: INVALID INPUT\n";
    exit(EXIT_FAILURE);
  }

  const int size = pow(dim, rank);
  vector <double> init(size);
  for(size_t i = 0; i < size; ++i)
  {
    cin >> init[i];
    if(cin.fail())
    {
      cerr << "ERROR: INVALID INPUT\n";
      exit(EXIT_FAILURE);
    }
  }

  Tensor t(name, dim, rank, init);
  tnsrs.push_back(t);
}

bool handleList(vector<Tensor> &tnsrs)
{
  for(int i = 0; i < tnsrs.size(); ++i)
  {
    cout << tnsrs[i].getName() << " dim:" << tnsrs[i].getDim() << " rank:" << tnsrs[i].getRank() << endl;
  }
}

bool handleAlg(vector<Tensor> &tnsrs)
{
  string name_res, op_ass, name_t1, op_alg, name_t2;
  cin >> name_res >> op_ass >> name_t1 >> op_alg >> name_t2;

  //Input has to be in a format result = tensor (x, +, *) (constant, tensor)
  if(cin.fail() || op_ass != "=" || ( op_alg != "x" && op_alg != "+" && op_alg != "*"))
  {
    cerr << "ERROR: INCORRECT FORMAT" << endl;
  }

  Tensor t1, t2, res;
  bool t1_found, t2_found, res_found;

  int i_1, i_2, i_res;
  if((i_1 = getTensor(name_t1, tnsrs)) != -1)
  {
    t1 = tnsrs[i_1];
    t1_found = true;
  }
  if((i_2 = getTensor(name_t2, tnsrs)) != -1)
  {
    t2 = tnsrs[i_2];
    t2_found = true;
  }
  if((i_res = getTensor(name_res, tnsrs)) != -1)
  {
    res = tnsrs[i_res];
    res_found = true;
  }

  if(!t1_found)
  {
    cerr << "ERROR: TENSOR DOESN'T EXIST\n";
    exit(EXIT_FAILURE);
  }

  if(op_alg == "x")
  {
      res = t1 * t2;
  }
  else if(op_alg == "*" && !t2_found)
  {
    double k;
    stringstream strtod;
    strtod << name_t2;
    strtod >> k;
    if(strtod.fail())
    {
      cerr << "ERROR: TENSOR DOESN'T EXIST";
      exit(EXIT_FAILURE);
    }
    res = t1 * k;
  }
  else if(op_alg == "*" && t2_found)
  {
    cout << "Please use 'x' instead of '*'" << endl;
    return false;
  }
  else if(op_alg == "+")
  {
    res = t1 + t2;
  }
  if(!res_found)
  {
    res.setName(name_res);
    tnsrs.push_back(res);
  }
  else
  {
    tnsrs[i_res] = res;
  }

}

bool handleGet(vector<Tensor> &tnsrs)
{
  string name;
  int i;
  cin >> name;
  if(cin.fail() || (i = getTensor(name, tnsrs)) == -1)
  {
    cerr << "TENSOR DOESN'T EXIST" << endl;
    return false;
  }

  vector <int> coordinates(tnsrs[i].getRank());

  for(size_t j = 0; j < tnsrs[i].getRank(); ++j)
  {
    cin >> coordinates[j];
    if(cin.fail()) exit(EXIT_FAILURE);
  }

  cout << tnsrs[i].getVal(coordinates) << endl;
}

void handleHelp()
{
  cout << "create <name> <dim> <rank>" << endl;
  cout << "create_init <name> <dim> <rank> <values>" << endl;
  cout << "list" << endl;
  cout << "alg <name of the result> = <name of t1> <+, *, x> <name of t2 or a constant>" << endl;
  cout << "get <name of tensor> <coordinates of the value>" << endl;
}

void handleHello()
{
  cout << "Hello! Have a nice day" << endl;
}
