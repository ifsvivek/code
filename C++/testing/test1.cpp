// cpp program for calculator using arrays
#include <iostream>
using namespace std;
int main() {
  int a[10], b[10], c[10], i, j, k, n, m, sum = 0;
  cout << "Enter the number of elements in first array: ";
  cin >> n;
  cout << "Enter the elements of first array: ";
  for (i = 0; i < n; i++) cin >> a[i];
  cout << "Enter the number of elements in second array: ";
  cin >> m;
  cout << "Enter the elements of second array: ";
  for (i = 0; i < m; i++) cin >> b[i];
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) c[i + j] = a[i] + b[j];
  cout << "The elements of resultant array are: ";
  for (i = 0; i < n + m; i++) cout << c[i] << " ";
  cout << endl;
  for (i = 0; i < n + m; i++) sum = sum + c[i];
  cout << "The sum of all elements is: " << sum;
  return 0;
}