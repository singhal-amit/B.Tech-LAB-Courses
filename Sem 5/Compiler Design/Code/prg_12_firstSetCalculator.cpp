#include <bits/stdc++.h>
using namespace std;

char productionSet[10][10];
int n; // Declare n globally

void FIRST(set<char> &result, char c)
{
  if (!(isupper(c)))
  {
    result.insert(c);
    return;
  }
  for (int i = 0; i < n; i++)
  {
    if (productionSet[i][0] == c)
    {
      FIRST(result, productionSet[i][2]); // Recursively find FIRST of the production
    }
  }
}

int main()
{
  cout << "Enter number of productions: ";
  cin >> n;

  cout << "Enter productions (example: A -> aB): \n";
  for (int i = 0; i < n; i++)
  {
    cin >> productionSet[i];
  }

  set<char> nonTerminals;
  for (int i = 0; i < n; i++)
  {
    nonTerminals.insert(productionSet[i][0]);
  }

  for (auto c : nonTerminals)
  {
    set<char> result;
    FIRST(result, c);
    cout << "First (" << c << ") : { ";
    for (auto x : result)
    {
      cout << x << " ";
    }
    cout << "}\n";
  }

  return 0;
}
