#include <iostream>
#include <string>
using namespace std;

#define SUCCESS 1
#define FAILED 0

int E(), Edash(), T(), Tdash(), F();
const char *cursor;
string input;

int main()
{
  cout << "Enter the string: ";
  cin >> input;           // Read input from the user
  cursor = input.c_str(); // Initialize cursor to point to the input string

  cout << "\nInput\t\t Action\n";
  cout << "--------------------------------\n";
  if (E() && *cursor == '\0')
  {
    cout << "--------------------------------\n";
    cout << "String is successfully parsed\n";
    return 0;
  }
  else
  {
    cout << "--------------------------------\n";
    cout << "Error in parsing String\n";
    return 1;
  }
}

int E()
{
  cout << cursor << "\t\t E -> T E'\n";
  if (T())
  {
    if (Edash())
      return SUCCESS;
    else
      return FAILED;
  }
  else
    return FAILED;
}

int Edash()
{
  if (*cursor == '+')
  {
    cout << cursor << "\t\t E' -> + T E'\n";
    cursor++;
    if (T())
    {
      if (Edash())
        return SUCCESS;
      else
        return FAILED;
    }
    else
      return FAILED;
  }
  else
  {
    cout << cursor << "\t\t E' -> $\n";
    return SUCCESS; // E' -> ε (empty string)
  }
}

int T()
{
  cout << cursor << "\t\t T -> F T'\n";
  if (F())
  {
    if (Tdash())
      return SUCCESS;
    else
      return FAILED;
  }
  else
    return FAILED;
}

int Tdash()
{
  if (*cursor == '*')
  {
    cout << cursor << "\t\t T' -> * F T'\n";
    cursor++;
    if (F())
    {
      if (Tdash())
        return SUCCESS;
      else
        return FAILED;
    }
    else
      return FAILED;
  }
  else
  {
    cout << cursor << "\t\t T' -> $\n";
    return SUCCESS; // T' -> ε (empty string)
  }
}

int F()
{
  if (*cursor == '(')
  {
    cout << cursor << "\t\t F -> ( E )\n";
    cursor++;
    if (E())
    {
      if (*cursor == ')')
      {
        cursor++;
        return SUCCESS;
      }
      else
        return FAILED;
    }
    else
      return FAILED;
  }
  else if (*cursor == 'i')
  {
    cout << cursor << "\t\t F -> i\n";
    cursor++;
    return SUCCESS;
  }
  else
    return FAILED;
}
