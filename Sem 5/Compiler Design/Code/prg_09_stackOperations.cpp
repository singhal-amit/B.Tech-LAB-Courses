#include <iostream>
#define MAX 5

using namespace std;

class Stack
{
private:
  int stack[MAX];
  int top;

public:
  Stack() : top(-1) {}

  void push(int val)
  {
    if (top == MAX - 1)
    {
      cout << "Stack Overflow\n";
      return;
    }
    stack[++top] = val;
    cout << "Pushed " << val << " onto the stack" << endl;
  }

  int pop()
  {
    if (top == -1)
    {
      cout << "Stack Underflow\n";
      return -1;
    }
    cout << "Popped " << stack[top] << " from the stack" << endl;
    return stack[top--];
  }

  void display()
  {
    if (top == -1)
    {
      cout << "Stack is empty\n";
      return;
    }
    cout << "Stack elements: ";
    for (int i = 0; i <= top; i++)
    {
      cout << stack[i] << " ";
    }
    cout << endl; // Added newline for better formatting
  }
};

int main()
{
  Stack s;
  s.push(10);
  s.push(20);
  s.display();
  s.pop();
  s.display();
  return 0;
}
