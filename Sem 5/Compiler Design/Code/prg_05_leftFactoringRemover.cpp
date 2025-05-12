#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

void leftFactoring(const string &nonTerminal, const vector<string> &productions)
{
  unordered_map<string, vector<string>> prefixMap;
  for (const auto &production : productions)
  {
    string prefix = production.substr(0, 1);
    prefixMap[prefix].push_back(production.substr(1));
  }
  if (prefixMap.size() > 1)
  {
    cout << nonTerminal << " -> ";
    for (const auto &[prefix, suffixes] : prefixMap)
    {
      if (suffixes.size() > 1)
      {
        cout << prefix << nonTerminal + "' | ";
      }
    }
    Cout << endl;
    cout << nonTerminal + "' -> ";
    for (const auto &[prefix, suffixes] : prefixMap)
    {
      if (suffixes.size() > 1)
      {
        for (const auto &suffix : suffixes)
        {
          cout << suffix << " | ";
        }
      }
      else
      {
        cout << suffixes[0] << " | ";
      }
    }
    cout << "ε" << endl;
  }
  else
  {
    cout << nonTerminal << " -> ";
    for (const auto &production : productions)
    {
      cout << production << " | ";
    }
    cout << endl;
  }
}

int main()
{
  vector<string> productionsA = {"aB", "aC", "bD", "aE"};
  cout << "Original Grammar:" << endl;
  cout << "A -> aB | aC | bD | aE" << endl;
  cout << "After Left Factoring:" << endl;
  leftFactoring("A", productionsA);
  return 0;
}
