#include <iostream>
#include <string>
#include <cstdlib>
#include <random>
#include <ctime>

using namespace std;

int main()
{
    string helloWorld = "hello world";
    string randomString = "";

    srand(time(0));
    int i = 0;
    while (randomString != helloWorld)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(97, 122);
        randomString += (char)dis(gen);
        std::cout << randomString << std::endl;
        if (randomString == helloWorld)
        {
            std::cout << "Match found!" << std::endl;
        }
        i++;
    }
    cout << "Number of iterations: " << i << endl;
    cout << "Random String: " << randomString << endl;
    ;
    return 0;
}