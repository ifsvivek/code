def reverse_string_with_punctuation(string):
    # Separate the string into words and punctuation marks
    words = string.split()
    punctuation = [word.strip() for word in string.split() if not word.isalnum()]

    # Reverse the words
    reversed_words = ' '.join(words[::-1])

    # Insert the punctuation marks back into the reversed string
    reversed_string = ''
    for word in reversed_words.split():
        if word in punctuation:
            reversed_string += word + ' '
        else:
            reversed_string += word[::-1] + ' '

    return reversed_string.strip()

# Example usage
input_string = "Hello, world! How are you?"
reversed_string = reverse_string_with_punctuation(input_string)
print(reversed_string)