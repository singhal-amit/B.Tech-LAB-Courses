#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
using namespace std;

void generateIntermediateCode(const string &expression)
{
  stringstream ss(expression);
  string token;
  vector<string> tokens;

  // Tokenize the input expression
  while (ss >> token)
  {
    tokens.push_back(token);
  }

  int tempCount = 1;
  vector<string> intermediateCode;
  vector<string> operands;
  vector<string> operators;

  // Generate intermediate code
  for (const auto &t : tokens)
  {
    if (t == "=")
    {
      continue; // Skip the assignment operator
    }
    else if (t == "+" || t == "-" || t == "*" || t == "/")
    {
      operators.push_back(t);
    }
    else
    {
      operands.push_back(t);
      if (!operators.empty())
      {
        string op = operators.back();
        operators.pop_back();
        string rhs2 = operands.back();
        operands.pop_back();
        string rhs1 = operands.back();
        operands.pop_back();
        string tempVar = "t" + to_string(tempCount++);
        intermediateCode.push_back(tempVar + " = " + rhs1 + " " + op + " " + rhs2);
        operands.push_back(tempVar); // Push the temporary variable back to operands
      }
    }
  }

  // Final assignment
  if (!operands.empty())
  {
    string lhs = tokens[0];               // Left-hand side variable
    string finalResult = operands.back(); // The result of the last operation
    intermediateCode.push_back(lhs + " = " + finalResult);
  }

  // Output the intermediate code
  cout << "Intermediate Code:\n";
  for (const auto &code : intermediateCode)
  {
    cout << code << endl;
  }
}

int main()
{
  string expression;
  cout << "Enter an expression (e.g., a = b + c * d): ";
  getline(cin, expression);
  generateIntermediateCode(expression);
  return 0;
}
