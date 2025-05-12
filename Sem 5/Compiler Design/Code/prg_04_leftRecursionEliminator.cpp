#include <iostream>
using namespace std;
void removeLeftRecursion(string nonTerminal, vector<string> productions)
{
  vector<string> alpha, beta;
  string newNonTerminal = nonTerminal + "'";
  for (const auto &production : productions)
  {
    if (production[0] == nonTerminal[0])
    {
      alpha.push_back(production.substr(1));
    }
  }
  for (const auto &prod : beta)
  {
    cout << prod << " ";
  }
  cout << newNonTerminal << " -> ";
  for (const auto &prod : alpha)
  {
    cout << prod << " " << newNonTerminal << " | ";
  }
  cout << "\u03B5" << endl;
}
int main()
{
  vector<string> productionsE = {"E+T", "T"};
  vector<string> productionsT = {"T*F", "F"};
  cout << "Original Grammar:" << endl;
  cout << "E -> E + T | T" << endl;
  cout << "T -> T * F | F" << endl;
  cout << "F -> id" << endl
       << endl;
  cout << "Removing Left Recursion for E:" << endl;
  removeLeftRecursion("E", productionsE);
  cout << endl
       << "Removing Left Recursion for T:" << endl;
  removeLeftRecursion("T", productionsT);
  cout << endl
       << "F -> id" << endl;
  return 0;
}
