# Tuple: Tuples are used to store multiple items in a single variable.
# 1. A tuple is a collection which is ordered and unchangeable.
# 2. Tuples are written with round brackets.
# 3. Tuple items are ordered, unchangeable, and allow duplicate values.

# Ordered
# When we say that tuples are ordered, it means that the items have a defined order, 
# and that order will not change.

# Unchangeable
# Tuples are unchangeable, meaning that we cannot change, add or remove items after the tuple has been created.

# Create a Tuple:
thistuple = ("apple", "banana", "cherry")
print(thistuple) # ('apple', 'banana', 'cherry')

# Tuples allow duplicate values:
thistuple = ("apple", "banana", "cherry", "apple", "cherry")
print(thistuple) # ('apple', 'banana', 'cherry', 'apple', 'cherry')
print(len(thistuple)) # 5

# Create Tuple With One Item
# To create a tuple with only one item, you have to add a comma after the item, 
# otherwise Python will not recognize it as a tuple.
# One item tuple, remember the comma:

thistuple = ("apple",)
print(type(thistuple)) # <class 'tuple'>

#NOT a tuple
thistuple = ("apple")
print(type(thistuple)) # <class 'str'>


# Tuple items can be of any data type:
tuple1 = ("apple", "banana", "cherry")
tuple2 = (1, 5, 7, 9, 3)
tuple3 = (True, False, False)
print(tuple1) # ('apple', 'banana', 'cherry')
print(tuple2) # (1, 5, 7, 9, 3)
print(tuple3) # (True, False, False)

# A tuple can contain different data types:
tuple1 = ("abc", 34, True, 40, "male")
print(tuple1) # ('abc', 34, True, 40, 'male')

# The tuple() Constructor
# It is also possible to use the tuple() constructor to make a tuple.
# Using the tuple() method to make a tuple:
# note the double round-brackets
thistuple = tuple(("apple", "banana", "cherry")) 
print(thistuple)  # ('apple', 'banana', 'cherry')

#---------------------------------------------------------------------------
# Access Tuple Items
#---------------------------------------------------------------------------

# You can access tuple items by referring to the index number, inside square brackets:
thistuple = ("apple", "banana", "cherry")
print(thistuple[1]) # banana

# Negative Indexing
# -1 refers to the last item, -2 refers to the second last item etc.
thistuple = ("apple", "banana", "cherry")
print(thistuple[-1]) # cherry

# Range of Indexes
thistuple = ("apple", "banana", "cherry", "orange", "kiwi", "melon", "mango")
print(thistuple[2:5]) # ('cherry', 'orange', 'kiwi')

# This example returns the items from the beginning to, but NOT included, "kiwi":
thistuple = ("apple", "banana", "cherry", "orange", "kiwi", "melon", "mango")
print(thistuple[:4]) # ('apple', 'banana', 'cherry', 'orange')

# By leaving out the end value, the range will go on to the end of the tuple:
thistuple = ("apple", "banana", "cherry", "orange", "kiwi", "melon", "mango")
print(thistuple[2:]) # ('cherry', 'orange', 'kiwi', 'melon', 'mango')

# Range of Negative Indexes
# This example returns the items from index -4 (included) to index -1 (excluded)
thistuple = ("apple", "banana", "cherry", "orange", "kiwi", "melon", "mango")
print(thistuple[-4:-1]) # ('orange', 'kiwi', 'melon')

# Check if Item Exists
# To determine if a specified item is present in a tuple use the in keyword:
# Check if "apple" is present in the tuple:
thistuple = ("apple", "banana", "cherry")
if "apple" in thistuple:
  print("Yes, 'apple' is in the fruits tuple")
# Yes, 'apple' is in the fruits tuple

#---------------------------------------------------------------------------
# Update Tuples
#---------------------------------------------------------------------------
# Tuples are unchangeable, meaning that you cannot change, add, or remove items once the tuple is created.

# Change Tuple Values
# Once a tuple is created, you cannot change its values. Tuples are unchangeable, 
# or immutable as it also is called.

# Convert the tuple into a list to be able to change it:
x = ("apple", "banana", "cherry")
y = list(x)
y[1] = "kiwi"
x = tuple(y)
print(x) # ("apple", "kiwi", "cherry")

# Add Items into tuple
thistuple = ("apple", "banana", "cherry")
y = list(thistuple)
y.append("orange")
thistuple = tuple(y)

# Add tuple into a tuple
# You are allowed to add tuples to tuples, so if you want to add one item, 
# (or many), create a new tuple with the item(s), and add it to the existing tuple:
thistuple = ("apple", "banana", "cherry")
y = ("orange",)
thistuple += y
print(thistuple) # ('apple', 'banana', 'cherry', 'orange')

# Remove Items
# Tuples are unchangeable, so you cannot remove items from it, 
# but you can use the same workaround as we used for changing and adding tuple items:
thistuple = ("apple", "banana", "cherry")
y = list(thistuple)
y.remove("apple")
thistuple = tuple(y)
print(thistuple) # ('banana', 'cherry')

#  you can delete the tuple completely:
thistuple = ("apple", "banana", "cherry")
del thistuple

#---------------------------------------------------------------------------
# Unpack Tuples
#---------------------------------------------------------------------------

# When we create a tuple, we normally assign values to it. This is called "packing" a tuple:
fruits = ("apple", "banana", "cherry")

# Unpacking a tuple:
fruits = ("apple", "banana", "cherry")
(green, yellow, red) = fruits
print(green)  # apple
print(yellow) # banana
print(red)    # cherry

# Using Asterisk*
# If the number of variables is less than the number of values, 
# you can add an * to the variable name and the values will be assigned to the variable as a list:
# Assign the rest of the values as a list called "red":
fruits = ("apple", "banana", "cherry", "strawberry", "raspberry")
(green, yellow, *red) = fruits
print(green)  # apple
print(yellow) # banana
print(red)    # ['cherry', 'strawberry', 'raspberry']


# Add a list of values the "tropic" variable:
fruits = ("apple", "mango", "papaya", "pineapple", "cherry")
(green, *tropic, red) = fruits
print(green)
print(tropic)
print(red)
# apple
# ['mango', 'papaya', 'pineapple']
# cherry

#---------------------------------------------------------------------------
# Loop Tuples
#---------------------------------------------------------------------------

# Loop Through a Tuple
# You can loop through the tuple items by using a for loop.
thistuple = ("apple", "banana", "cherry")
for x in thistuple:
  print(x)
# o/p
# apple
# banana
# cherry

# Loop Through the Index Numbers
thistuple = ("apple", "banana", "cherry")
for i in range(len(thistuple)):
  print(thistuple[i])
# o/p
# apple
# banana
# cherry

# Using a While Loop
thistuple = ("apple", "banana", "cherry")
i = 0
while i < len(thistuple):
  print(thistuple[i])
  i = i + 1
# o/p
# apple
# banana
# cherry

#---------------------------------------------------------------------------
# Join Tuples
#---------------------------------------------------------------------------
# Join Two Tuples: To join two or more tuples you can use the + operator:
tuple1 = ("a", "b" , "c")
tuple2 = (1, 2, 3)
tuple3 = tuple1 + tuple2
print(tuple3) # ('a', 'b', 'c', 1, 2, 3)

# Multiply Tuples
fruits = ("apple", "banana", "cherry")
mytuple = fruits * 2
print(mytuple) # ('apple', 'banana', 'cherry', 'apple', 'banana', 'cherry')

#---------------------------------------------------------------------------
# Tuple Methods
#---------------------------------------------------------------------------
# count()	Returns the number of times a specified value occurs in a tuple
thistuple = (1, 3, 7, 8, 7, 5, 4, 6, 8, 5)
x = thistuple.count(5)
print(x) # 2

# index()	Searches the tuple for a specified value and returns the position of where it was found
thistuple = (1, 3, 7, 8, 7, 5, 4, 6, 8, 5)
x = thistuple.index(8)
print(x) # 3