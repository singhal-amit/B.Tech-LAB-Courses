#include <iostream>
#include <vector>
#include <string>
using namespace std;

void exitWithError()
{
  cout << "Not operator grammar" << endl;
  exit(0);
}

int main()
{
  int n;
  cout << "Enter the number of productions: ";
  cin >> n;
  vector<string> grammar(n);

  cout << "Enter the productions (e.g., A=B+C):\n";
  for (int i = 0; i < n; i++)
  {
    cin >> grammar[i];
  }

  for (const auto &prod : grammar)
  {
    int j = 2; // Start after the left-hand side (assuming format A=B+C)
    char c;

    while (prod[j] != '\0')
    {
      c = prod[j];
      // Check for operators and ensure they are not at the end of the production
      if (c == '+' || c == '-' || c == '*' || c == '/')
      {
        if (prod[j + 1] == '\0' || prod[j + 1] == '$')
        {
          exitWithError();
        }
      }
      else if (c == '$')
      {
        exitWithError();
      }
      else if (!(isupper(c)) && c != 'A')
      { // Allow only uppercase letters and 'A'
        exitWithError();
      }
      j++;
    }
  }

  cout << "Operator grammar" << endl;
  return 0;
}
