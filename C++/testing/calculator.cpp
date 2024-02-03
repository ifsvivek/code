#include <iostream>
using namespace std;
int main() {
  int a, b, c;
  cout << "Enter two numbers: ";
  cin >> a >> b;
  cout << "Choose an operator: ";
  char op;
  cin >> op;
  if (op == '+') {
    c = a + b;
    cout << "The sum is: " << c;
  } else if (op == '-') {
    c = a - b;
    cout << "The difference is: " << c;
  } else if (op == '*') {
    c = a * b;
    cout << "The product is: " << c;
  } else if (op == '/') {
    c = a / b;
    cout << "The quotient is: " << c;
  } else {
    cout << "Invalid operator";
  }
}