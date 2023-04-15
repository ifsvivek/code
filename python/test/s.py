import random


def generate_random_string():

    chars = " delHorW!"

    string_length = 12

    random_string = "".join(random.choice(chars) for i in range(string_length))

    return random_string


def check_hello_world(string):
    return string == "Hello World!"


print(
    "This program generates random strings and checks if they say 'Hello World!'"
)
print("It may take a while to find a string that says 'Hello World!'")

while True:
    random_string = generate_random_string()
    print(random_string)
    if check_hello_world(random_string):
        print(random_string)
        break