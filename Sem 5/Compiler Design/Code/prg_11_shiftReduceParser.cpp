#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<char> st, a;

void StackAndInput()
{
  for (auto x : st)
  {
    cout << x << "\t";
  }
  for (auto x : a)
  {
    cout << x;
  }
}

void check()
{
  for (int i = 0; i < st.size(); i++)
  {
    if (st[i] == 'a')
    {
      st[i] = 'E';
      StackAndInput();
      cout << "$\t" << "REDUCE E->a" << endl;
      check();
    }
    if (i + 2 < st.size() && st[i] == 'E' && (st[i + 1] == '+' || st[i + 1] == '*') && st[i + 2] == 'E')
    {
      st.pop_back(); // pop the last 'E'
      st.pop_back(); // pop the operator ('+' or '*')
      st.pop_back(); // pop the first 'E'
      StackAndInput();
      if (st.empty() || st.back() != 'E')
      {
        st.push_back('E'); // push back 'E' after reduction
      }
      cout << "$\t" << "REDUCE E->E+E or E->E*E" << endl;
    }
  }
}

int main()
{
  cout << "GRAMMAR is: \nE -> E + E \nE -> E * E \nE -> a\n";
  string input;
  cout << "Enter input string (consisting of 'a', '+', '*'): ";
  cin >> input;

  for (char ch : input)
  {
    a.push_back(ch);
  }

  cout << "\nStack\tInput\tAction\n";
  for (int i = 0; i < a.size(); i++)
  {
    st.push_back(a[i]);
    a[i] = ' ';
    StackAndInput();
    cout << "$\tSHIFT -> " << st.back() << endl;
    check();
  }

  if (st.size() == 1 && st[0] == 'E')
  {
    cout << "\n\nString accepted\n";
  }
  else
  {
    cout << "\n\nString rejected\n";
  }
  return 0;
}
