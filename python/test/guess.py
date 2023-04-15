import random

secret = random.randint(1, 20)
guess = None
tries = 0

while guess != secret and tries < 6:
    guess = int(input("Guess a number between 1 and 20: "))
    tries += 1
    if guess < secret:
        print("Too low, try again.")
    elif guess > secret:
        print("Too high, try again.")
    elif guess == secret:
        print("Congratulations, you guessed the number!")
if guess != secret:
    print("Sorry, you have reached your maximum number of tries.")
    print("The number was", secret)