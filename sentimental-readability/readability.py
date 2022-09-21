# Readability.py
# Defining Main Function
def main():
    # User Input as Text
    text = input("Text: ")
    # Calling count_letters, count_words, count_sentences function
    c_letter = count_letters(text)
    c_word = count_words(text)
    c_sentence = count_sentences(text)
    # Calling the function to calculate the coleman liau index
    index = Coleman_liau_Index(c_letter, c_word, c_sentence)
    # Checking the index and printing
    if index < 1:
        print("Before Grade 1")
    elif index > 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")

# Counting the number of letters


def count_letters(string):
    count_letter = 0
    for i in string:
        if i.isalpha():
            count_letter += 1
    return count_letter

# Counting the number of words


def count_words(string):
    list_word = string.split(' ')
    count_word = len(list_word)
    return count_word

# Counting the number of sentences


def count_sentences(string):
    count_sentence = 0
    for i in string:
        if i in ['.', '!', '?']:
            count_sentence += 1
    return count_sentence

# Counting the Coleman Liau Index


def Coleman_liau_Index(l, w, s):
    L = l * 100 / w
    S = s * 100 / w
    index = round(0.0588 * L - 0.296 * S - 15.8)
    return index


if __name__ == "__main__":
    main()