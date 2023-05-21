
#include <iostream>
#include <string>
#include <random>
#include <thread>

using namespace std;

int main() {
  // Create a random number generator.
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  // Create a string to store the random strings.
  string str;

  // Create a counter to keep track of the number of iterations.
  int iterations = 0;

  // Create a vector of threads.
  vector<thread> threads;

  // Create 12 threads.
  for (int i = 0; i < 12; i++) {
    threads.emplace_back([&]() {
      while (str != "hello world") {
        // Generate a random string of length 10.
        str = string(10, ' ');

        // Fill the string with random characters.
        for (int j = 0; j < str.length(); j++) {
          str[j] = 'a' + rng() % 26;
        }

        // Increment the counter.
        iterations++;
      }
    });
  }

  // Join all of the threads.
  for (auto &t : threads) {
    t.join();
  }

  // Print the number of iterations it took to find "hello world".
  cout << "It took " << iterations << " iterations to find 'hello world'." << endl;

  return 0;
}
