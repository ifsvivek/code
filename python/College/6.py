#Develop a program to sort the contents of a text file and write the sorted contents into a separate text file.
def sort(input, output):
    with open(input, 'r') as input:
        words = input.read().split()
    words.sort()
    with open(output, 'w') as output:
        output.write('\n'.join(words))

sort('txt\\input.txt', 'txt\\output.txt')