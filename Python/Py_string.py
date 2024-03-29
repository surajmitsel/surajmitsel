# 'hello' is the same as "hello".

print("Hello")
print('Hello')

# o/p
# Hello
# Hello

#---------------------------------------------------------------------------
# You can use three double quotes:

a = """Lorem ipsum dolor sit amet,
consectetur adipiscing elit,
sed do eiusmod tempor incididunt
ut labore et dolore magna aliqua."""
print(a)

# o/p
# Lorem ipsum dolor sit amet,
# consectetur adipiscing elit,
# sed do eiusmod tempor incididunt
# ut labore et dolore magna aliqua.

#---------------------------------------------------------------------------
# Strings are Arrays
a = "Hello, World!"
print(a[1])

# o/p
# e

#---------------------------------------------------------------------------
# Looping Through a String
for x in "banana":
  print(x)
  
# o/p
# b
# a
# n
# a
# n
# a
#---------------------------------------------------------------------------

a = "Hello, World!"
print(len(a))

# o/p
# 13
#---------------------------------------------------------------------------
# To check if a certain phrase or character is present in a string, 
# we can use the keyword in.
txt = "The best things in life are free!"
print("free" in txt)
print("expensive" not in txt)

if "free" in txt:
  print("Yes, 'free' is present.")
if "expensive" not in txt:
  print("No, 'expensive' is NOT present.")

# o/p
# True
# True
# Yes, 'free' is present.
# No, 'expensive' is NOT present.

#---------------------------------------------------------------------------
# Slicing in middle (excludes last)
b = "Hello, World!"
print(b[2:5])
# o/p
# llo

# Slice From the Start
b = "Hello, World!"
print(b[:5])
# o/p
# Hello

# Slice To the End (include begining)
b = "Hello, World!"
print(b[2:])
# o/p
# llo, World!

# Negative Indexing
#From: "o" in "World!" (position -5)
#To, but not included: "d" in "World!" (position -2):

b = "Hello, World!"
print(b[2:5])   # (begin include, last exclude)
print(b[-5:-2]) # (begin exclude, last include)
# o/p
# llo
# orl

#---------------------------------------------------------------------------
# Upper Case and Lower Case
a = "Hello, World!"
print(a.upper())
# o/p
# HELLO, WORLD!

print(a.lower())
# o/p
# hello, world!

#---------------------------------------------------------------------------
# The strip() method removes any whitespace from the beginning or the end:
a = " Hello, World! "
print(a.strip()) # returns "Hello, World!"

# o/p
# Hello, World!

#---------------------------------------------------------------------------
# The replace() method replaces a string with another string:
a = "Hello, World!"
print(a.replace("o", "J"))
# o/p
# HellJ, WJrld!

#---------------------------------------------------------------------------
# The split() method returns a list where the text between the specified separator
# becomes the list items.

a = "Hello, World!"
print(a.split(",")) # ['Hello', ' World!']
print(a.split("o")) # ['Hell', ', W', 'rld!']
print(a.split("l")) # ['He', '', 'o, Wor', 'd!']

#---------------------------------------------------------------------------
# String Concatenation
a = "Hello"
b = "World"
c = a + b
print(c) # HelloWorld

#---------------------------------------------------------------------------
# String Format

age = 36
# txt = "My name is John, I am " + age 
# above line gies error TypeError: can only concatenate str (not "int") to str
txt = "My name is John, and I am {}"
print(txt.format(age)) # My name is John, and I am 36

quantity = 3
itemno = 567
price = 49.95
myorder = "I want {} pieces of item {} for {} dollars."
print(myorder.format(quantity, itemno, price))
# o/p
# I want 3 pieces of item 567 for 49.95 dollars.


quantity = 3
itemno = 567
price = 49.95
myorder = "I want to pay {2} dollars for {0} pieces of item {1}."
print(myorder.format(quantity, itemno, price))
# o/p
# I want to pay 49.95 dollars for 3 pieces of item 567.

#---------------------------------------------------------------------------
# Escape Character: An escape character is a backslash \ followed by the 
# character you want to insert.
txt = "We are the so-called \"Vikings\" from the north."

#---------------------------------------------------------------------------
# Method	Description

# capitalize()	Converts the first character to upper case
# casefold()	    Converts string into lower case
# center()	    Returns a centered string
# count()	        Returns the number of times a specified value occurs in a string
# encode()	    Returns an encoded version of the string
# endswith()	    Returns true if the string ends with the specified value
# expandtabs()	Sets the tab size of the string
# find()	        Searches the string for a specified value and returns the position of where it was found
# format()	    Formats specified values in a string
# format_map()	Formats specified values in a string
# index()	        Searches the string for a specified value and returns the position of where it was found
# isalnum()	    Returns True if all characters in the string are alphanumeric
# isalpha()	    Returns True if all characters in the string are in the alphabet
# isascii()	    Returns True if all characters in the string are ascii characters
# isdecimal()	    Returns True if all characters in the string are decimals
# isdigit()	    Returns True if all characters in the string are digits
# isidentifier()	Returns True if the string is an identifier
# islower()	    Returns True if all characters in the string are lower case
# isnumeric()	    Returns True if all characters in the string are numeric
# isprintable()	Returns True if all characters in the string are printable
# isspace()       Returns True if all characters in the string are whitespaces
# istitle()	    Returns True if the string follows the rules of a title
# isupper()	    Returns True if all characters in the string are upper case
# join()	        Joins the elements of an iterable to the end of the string
# ljust()	        Returns a left justified version of the string
# lower()	        Converts a string into lower case
# lstrip()	    Returns a left trim version of the string
# maketrans()	    Returns a translation table to be used in translations
# partition()	    Returns a tuple where the string is parted into three parts
# replace()	    Returns a string where a specified value is replaced with a specified value
# rfind()	        Searches the string for a specified value and returns the last position of where it was found
# rindex()	    Searches the string for a specified value and returns the last position of where it was found
# rjust()	        Returns a right justified version of the string
# rpartition()	Returns a tuple where the string is parted into three parts
# rsplit()	    Splits the string at the specified separator, and returns a list
# rstrip()	    Returns a right trim version of the string
# split()	        Splits the string at the specified separator, and returns a list
# splitlines()	Splits the string at line breaks and returns a list
# startswith()	Returns true if the string starts with the specified value
# strip()	        Returns a trimmed version of the string
# swapcase()	    Swaps cases, lower case becomes upper case and vice versa
# title()	        Converts the first character of each word to upper case
# translate()	    Returns a translated string
# upper()	        Converts a string into upper case
# zfill()	        Fills the string with a specified number of 0 values at the beginning
#---------------------------------------------------------------------------

