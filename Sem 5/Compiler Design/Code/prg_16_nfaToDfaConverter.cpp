#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

void printNFA(const vector<vector<vector<int>>> &nfa)
{
  cout << "#################### TRANSITION TABLE of NFA ####################\n";
  cout << "    INPUT  |";
  for (char c = 'a'; c < 'a' + nfa[0].size(); ++c)
  {
    cout << " " << c << " |";
  }
  cout << "\nSTATE\n";
  for (int i = 0; i < nfa.size(); ++i)
  {
    cout << " q" << i << "        |";
    for (const auto &transitions : nfa[i])
    {
      if (transitions.empty())
      {
        cout << " ∅ ";
      }
      else
      {
        for (int j = 0; j < transitions.size(); ++j)
        {
          cout << " q" << transitions[j];
          if (j < transitions.size() - 1)
            cout << " ";
        }
      }
      cout << " |";
    }
    cout << "\n";
  }
}

void printDFA(const vector<vector<int>> &dfa, const vector<vector<int>> &states)
{
  cout << "#################### TRANSITION TABLE of DFA ####################\n";
  cout << "    INPUT  |";
  for (char c = 'a'; c < 'a' + dfa[0].size(); ++c)
  {
    cout << " " << c << " |";
  }
  cout << "\nSTATE\n";
  for (int i = 0; i < dfa.size(); ++i)
  {
    cout << " ";
    for (int state : states[i])
    {
      cout << "q" << state << " ";
    }
    cout << "|";
    for (const auto &transitions : dfa[i])
    {
      if (transitions.empty())
      {
        cout << " ∅ ";
      }
      else
      {
        for (int j = 0; j < transitions.size(); ++j)
        {
          cout << " q" << transitions[j];
          if (j < transitions.size() - 1)
            cout << " ";
        }
      }
      cout << " |";
    }
    cout << "\n";
  }
}

vector<int> closure(int state, const vector<vector<vector<int>>> &nfa)
{
  vector<int> result = {state};
  queue<int> q;
  q.push(state);

  while (!q.empty())
  {
    int current = q.front();
    q.pop();

    for (int nextState : nfa[current][nfa[current].size() - 1])
    {
      if (find(result.begin(), result.end(), nextState) == result.end())
      {
        result.push_back(nextState);
        q.push(nextState);
      }
    }
  }
  return result;
}

int main()
{
  int n, alpha;
  cout << "##################### NFA to DFA Conversion ########################\n";
  cout << "Enter total number of states in NFA :: ";
  cin >> n;
  cout << "Enter number of elements in Alphabet (a,b,c,...) :: ";
  cin >> alpha;

  vector<vector<vector<int>>> nfa(n);
  for (int i = 0; i < n; ++i)
  {
    cout << "----------------------- For state :: q" << i << " ----------------------\n";
    for (int j = 0; j < alpha; ++j)
    {
      char inputChar = 'a' + j;
      int outputStates;
      cout << "δ(q" << i << "," << inputChar << ") goes to no. of output states :: ";
      cin >> outputStates;

      cout << "Enter output states :: ";
      for (int k = 0; k < outputStates; ++k)
      {
        int state;
        cin >> state;
        nfa[i][j].push_back(state);
      }
    }

    // Handle ε-transitions
    int epsilonOutputStates;
    cout << "δ(q" << i << ",ε) goes to no. of output states :: ";
    cin >> epsilonOutputStates;

    cout << "Enter output states :: ";
    for (int k = 0; k < epsilonOutputStates; ++k)
    {
      int state;
      cin >> state;
      nfa[i].emplace_back(vector<int>{state});
    }
  }

  printNFA(nfa);

  // Construct the DFA
  vector<vector<int>> dfa;
  vector<vector<int>> states;

  states.push_back(closure(0, nfa));
  dfa.push_back(vector<int>(alpha, -1));

  queue<vector<int>> q;
  q.push(states[0]);

  while (!q.empty())
  {
    vector<int> currentStates = q.front();
    q.pop();

    for (int i = 0; i < alpha; ++i)
    {
      vector<int> nextStates;
      for (int state : currentStates)
      {
        for (int nextState : nfa[state][i])
        {
          for (int closureState : closure(nextState, nfa))
          {
            if (find(nextStates.begin(), nextStates.end(), closureState) == nextStates.end())
            {
              nextStates.push_back(closureState);
            }
          }
        }
      }

      // Check if this combination of states already exists
      auto it = find(states.begin(), states.end(), nextStates);
      if (it != states.end())
      {
        dfa.push_back({it - states.begin()});
      }
      else if (!nextStates.empty())
      {
        states.push_back(nextStates);
        dfa.push_back({});
        q.push(nextStates);
      }
      dfa[states.size() - 1].push_back(nextStates);
    }
  }

  printDFA(dfa, states);
  return 0;
}
