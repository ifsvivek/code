#include <iostream>
#include <random>
#include <string>
#include <thread>

using namespace std;

int main() {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  string str;
  int iterations = 0;

  vector<thread> threads;

  for (int i = 0; i < 12; i++) {
    threads.emplace_back([&]() {
      while (str != "hello world") {
        str = string(10, ' ');

        for (int j = 0; j < str.length(); j++) {
          str[j] = 'a' + rng() % 26;
        }

        iterations++;
        cout << str << endl;  // Display each generated output
      }
    });
  }

  for (auto &t : threads) {
    t.join();
  }

  cout << "It took " << iterations << " iterations to find 'hello world'."
       << endl;

  return 0;
}
