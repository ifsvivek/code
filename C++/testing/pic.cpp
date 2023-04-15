#include <iostream>
#include <string>
#include <random>

int main()
{
    std::string helloWorld = "hello world";
    std::string randomString = "";

    while (true)
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
    }
    return 0;
}