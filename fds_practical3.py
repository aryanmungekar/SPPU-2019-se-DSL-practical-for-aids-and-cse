#Write a Python program to compute following operations on String:
#a) To display word with the longest length
#b) To determines the frequency of occurrence of particular character in the string
#c) To check whether given string is palindrome or not
#d) To display index of first appearance of the substring
#e) To count the occurrences of each word in a given string


def longest_word(text):
    words = text.split()
    longest_word = max(words, key=len)
    return longest_word

def character_frequency(text, character):
    frequency = text.count(character)
    return frequency

def is_palindrome(text):
    text = text.replace(' ', '')
    return text == text[::-1]

def first_substring_index(text, substring):
    index = text.find(substring)
    return index

def word_count(text):
    words = text.split()
    word_counts = {}
    for word in words:
        word_counts[word] = word_counts.get(word, 0) + 1
    return word_counts

text = "HELLO WORLD"
substring = "HELLO"
character = 'L'

print("Longest word:", longest_word(text))
print("Frequency of '{}': {}".format(character, character_frequency(text, character)))
print("Is palindrome:", is_palindrome(text))
print("First substring index:", first_substring_index(text, substring))
print("Word count:", word_count(text))
