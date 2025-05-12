#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <sstream>

using namespace std;

void findLeading(const string &nonTerminal, const map<string, vector<string>> &productions,
                 set<char> &leading, set<string> &visited)
{
  if (visited.count(nonTerminal))
    return;
  visited.insert(nonTerminal);

  for (const auto &production : productions.at(nonTerminal))
  {
    for (char symbol : production)
    {
      if (isalpha(symbol))
      {
        leading.insert(symbol);
        break; // No need to check further symbols in this production
      }
      else if (isupper(symbol) && productions.count(string(1, symbol)))
      {
        findLeading(string(1, symbol), productions, leading, visited);
        break; // Break after checking the first non-terminal
      }
    }
  }
}

int main()
{
  map<string, vector<string>> productions;
  productions["A"] = {"BC"};
  productions["B"] = {"a"};
  productions["C"] = {"d"};

  map<string, set<char>> leadingMap;

  for (const auto &production : productions)
  {
    const string &nonTerminal = production.first;
    set<char> leading;
    set<string> visited;
    findLeading(nonTerminal, productions, leading, visited);
    leadingMap[nonTerminal] = leading;
  }

  cout << "Leading of non-terminals:\n";
  for (const auto &entry : leadingMap)
  {
    cout << entry.first << " -> { ";
    for (char terminal : entry.second)
    {
      cout << terminal << " ";
    }
    cout << "}\n";
  }

  return 0;
}
