#Develop a program to print 10 most frequently appearing words in a text file.
def freq(filename):
    with open(filename) as f:
        words = f.read().lower().split()
    freq = {}
    for word in words:
        freq[word] = freq.get(word, 0) + 1
    top10 = sorted(freq.items(), key=lambda x: x[1], reverse=True)[:10]
    for i, (word, count) in enumerate(top10):
        print(f"{i+1}. {word}: {count}")

freq('txt\\input.txt')