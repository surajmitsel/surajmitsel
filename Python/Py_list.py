mylist = ["apple", "banana", "cherry"]
print(mylist)    # ['apple', 'banana', 'cherry']
print(mylist[0]) # apple

# Negative Indexing : Negative indexing means start from the end
thislist = ["me", "you", "them"]
print(thislist[-1])  #them
print(thislist[-2])  #you

# Lists allow duplicate values:
thislist = ["apple", "banana", "cherry", "apple", "cherry"]
print(thislist)  # ['apple', 'banana', 'cherry', 'apple', 'cherry']

# List Length
thislist = ["apple", "banana", "cherry"]
print(len(thislist)) # 3

# Data type: A list can contain same or different data types:
list1 = ["abc", 34, True, 40, "male"]

# type()
mylist = ["apple", "banana", "cherry"]
print(type(mylist)) # <class 'list'>

# The list() Constructor
thislist = list(("apple", "banana", "cherry")) # note the double round-brackets
print(thislist) # ['apple', 'banana', 'cherry']

# Return the third, fourth, and fifth item:
thislist = ["apple", "banana", "cherry", "orange", "kiwi", "melon", "mango"]
print(thislist[2:5]) # ['cherry', 'orange', 'kiwi']

# This example returns the items from the beginning to, but NOT including, "kiwi":
thislist = ["apple", "banana", "cherry", "orange", "kiwi", "melon", "mango"]
print(thislist[:4]) # ['apple', 'banana', 'cherry', 'orange']

# This example returns the items from "cherry" to the end:
thislist = ["apple", "banana", "cherry", "orange", "kiwi", "melon", "mango"]
print(thislist[2:]) # ['cherry', 'orange', 'kiwi', 'melon', 'mango']

# This example returns the items from "orange" (-4) to, but NOT including "mango" (-1):
thislist = ["apple", "banana", "cherry", "orange", "kiwi", "melon", "mango"]
print(thislist[-4:-1]) # ['orange', 'kiwi', 'melon']

# Check if Item Exists
thislist = ["apple", "banana", "cherry"]
if "apple" in thislist:
  print("Yes, 'apple' is in the fruits list") #Yes, 'apple' is in the fruits list

#---------------------------------------------------------------------------
# Change List Items
#---------------------------------------------------------------------------
# Change Item Value
thislist = ["apple", "banana", "cherry"]
thislist[1] = "blackcurrant"
print(thislist) # ['apple', 'blackcurrant', 'cherry']

# Change a Range of Item Values
thislist = ["apple", "banana", "cherry", "orange", "kiwi", "mango"]
thislist[1:3] = ["blackcurrant", "watermelon"]
print(thislist) # ['apple', 'blackcurrant', 'watermelon', 'orange', 'kiwi', 'mango']

# If you insert more items than you replace, the new items will be inserted 
# where you specified, and the remaining items will move accordingly:
thislist = ["apple", "banana", "cherry"]
thislist[1:2] = ["blackcurrant", "watermelon"]
print(thislist) # ['apple', 'blackcurrant', 'watermelon', 'cherry']

# If you insert less items than you replace, the new items will be inserted 
# where you specified, and the remaining items will move accordingly:
thislist = ["apple", "banana", "cherry"]
thislist[1:3] = ["watermelon"]
print(thislist) # ['apple', 'watermelon']

# insert() method. To insert a new list item, without replacing any of the existing values
thislist = ["apple", "banana", "cherry"]
thislist.insert(2, "watermelon")
print(thislist) # ['apple', 'banana', 'watermelon', 'cherry']

#---------------------------------------------------------------------------
# Add List Items
#---------------------------------------------------------------------------
# Using the append() method to append an item:
thislist = ["apple", "banana", "cherry"]
thislist.append("orange")
print(thislist) # ['apple', 'banana', 'cherry', 'orange']

# To insert a list item at a specified index, use the insert() method.
thislist = ["apple", "banana", "cherry"]
thislist.insert(1, "orange")
print(thislist) # ['apple', 'orange', 'banana', 'cherry']

# Extend List: To append elements from another list to the current list, use the extend() method.
thislist = ["apple", "banana", "cherry"]
tropical = ["mango", "pineapple", "papaya"]
thislist.extend(tropical)
print(thislist) #['apple', 'banana', 'cherry', 'mango', 'pineapple', 'papaya']

# Add Any Iterable: The extend() method does not have to append lists, 
# you can add any iterable object (tuples, sets, dictionaries etc.).
thislist = ["apple", "banana", "cherry"]
thistuple = ("kiwi", "orange")
thislist.extend(thistuple)
print(thislist) # ['apple', 'banana', 'cherry', 'kiwi', 'orange']

#---------------------------------------------------------------------------
# Remove List Items
#---------------------------------------------------------------------------

# Remove Specified Item: The remove() method removes the specified item.
thislist = ["apple", "banana", "cherry"]
thislist.remove("banana")
print(thislist) # ['apple', 'cherry']

# Remove the first occurance of "banana":
thislist = ["apple", "banana", "cherry", "banana", "kiwi"]
thislist.remove("banana")
print(thislist) # ['apple', 'cherry', 'banana', 'kiwi']

# Remove Specified Index: The pop() method removes the specified index.
thislist = ["apple", "banana", "cherry"]
thislist.pop(1)
print(thislist) # ['apple', 'cherry']

# If you do not specify the index, the pop() method removes the last item.
thislist = ["apple", "banana", "cherry"]
thislist.pop()
print(thislist) # ['apple', 'banana']

# The del keyword also removes the specified index:
thislist = ["apple", "banana", "cherry"]
del thislist[0]
print(thislist) # ['banana', 'cherry']

# The del keyword can also delete the list completely.
thislist = ["apple", "banana", "cherry"]
del thislist

# Clear the List: The clear() method empties the list.
# The list still remains, but it has no content.
thislist = ["apple", "banana", "cherry"]
thislist.clear()
print(thislist) # []

#---------------------------------------------------------------------------
# Loop List Items
#---------------------------------------------------------------------------

# Loop Through a List
thislist = ["apple", "banana", "cherry"]
for x in thislist:
  print(x) 
# o/p
# apple
# banana
# cherry

# Loop Through the Index Numbers
# Use the range() and len() functions to create a suitable iterable.
thislist = ["apple", "banana", "cherry"]
for i in range(len(thislist)):
  print(thislist[i])
# o/p
# apple
# banana
# cherry

# Using a While Loop
# Use the len() function to determine the length of the list, 
# then start at 0 and loop your way through the list items by referring to their indexes.
thislist = ["apple", "banana", "cherry"]
i = 0
while i < len(thislist):
  print(thislist[i])
  i = i + 1
# o/p
# apple
# banana
# cherry

# Looping Using List Comprehension
# List Comprehension offers the shortest syntax for looping through lists:
thislist = ["apple", "banana", "cherry"]
[print(x) for x in thislist]
# o/p
# apple
# banana
# cherry

#---------------------------------------------------------------------------
# List Comprehension
#---------------------------------------------------------------------------
# List comprehension offers a shorter syntax 
# when you want to create a new list based on the values of an existing list.

# The Syntax=> newlist = [expression for item in iterable if condition == True]
# The return value is a new list, leaving the old list unchanged.

# Method1: Based on a list of fruits, you want a new list, containing only the fruits 
# with the letter "a" in the name.
fruits = ["apple", "banana", "cherry", "kiwi", "mango"]
newlist = []
for x in fruits:
  if "a" in x:
    newlist.append(x)
print(newlist) # ['apple', 'banana', 'mango']

# Method2: With list comprehension you can do all that with only one line of code:
fruits = ["apple", "banana", "cherry", "kiwi", "mango"]
newlist = [x for x in fruits if "a" in x]
print(newlist) # ['apple', 'banana', 'mango']

# Condition: 
# The condition is like a filter that only accepts the items that valuate to True.
# The condition is optional and can be omitted:
# without condition in Comprehension
fruits = ["apple", "banana", "cherry", "kiwi", "mango"]
newlist = [x for x in fruits]
print(newlist) #  ['apple', 'banana', 'cherry', 'kiwi', 'mango']

# Iterable
# The iterable can be any iterable object, like a list, tuple, set etc.
# You can use the range() function to create an iterable:
newlist = [x for x in range(10)]
print(newlist) # [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

# Accept only numbers lower than 5:
newlist = [x for x in range(10) if x < 5] # [0, 1, 2, 3, 4]

# Expression
# The expression is the current item in the iteration, but it is also the outcome, 
# which you can manipulate before it ends up like a list item in the new list:
# Set the values in the new list to upper case:
fruits = ["apple", "banana", "cherry", "kiwi", "mango"]
newlist = [x.upper() for x in fruits]
print(newlist) # ['APPLE', 'BANANA', 'CHERRY', 'KIWI', 'MANGO']

# Set all values in the new list to 'hello':
newlist = ['hello' for x in fruits] 
print (newlist) # ['hello', 'hello', 'hello', 'hello', 'hello']

# The expression can also contain conditions, 
# not like a filter, but as a way to manipulate the outcome:
fruits = ["apple", "banana", "cherry", "kiwi", "mango"]
newlist = [x if x != "banana" else "orange" for x in fruits]
print(newlist) # ['apple', 'orange', 'cherry', 'kiwi', 'mango']

#---------------------------------------------------------------------------
# Sort Lists
#---------------------------------------------------------------------------
# Sort the list alphabetically:
thislist = ["orange", "mango", "kiwi", "pineapple", "banana"]
thislist.sort()
print(thislist) # ['banana', 'kiwi', 'mango', 'orange', 'pineapple']

thislist = [100, 50, 65, 82, 23]
thislist.sort()
print(thislist) # [23, 50, 65, 82, 100]

# Sort the list descending: reverse = True
thislist = ["orange", "mango", "kiwi", "pineapple", "banana"]
thislist.sort(reverse = True)
print(thislist) # ['pineapple', 'orange', 'mango', 'kiwi', 'banana']

# Customize Sort Function
# You can also customize your own function by using the keyword argument key = function
# Sort the list based on how close the number is to 50:
def myfunc(n):
  return abs(n - 50)

thislist = [100, 50, 65, 82, 23]
thislist.sort(key = myfunc)
print(thislist) # [50, 65, 23, 82, 100]

# Case Insensitive Sort
# By default the sort() method is case sensitive, 
# resulting in all capital letters being sorted before lower case letters:
# Case sensitive sorting can give an unexpected result:
thislist = ["banana", "Orange", "Kiwi", "cherry"]
thislist.sort()
print(thislist) # ['Kiwi', 'Orange', 'banana', 'cherry']

# So if you want a case-insensitive sort function, use str.lower as a key function:
# Perform a case-insensitive sort of the list:
thislist = ["banana", "Orange", "Kiwi", "cherry"]
thislist.sort(key = str.lower)
print(thislist) # ['banana', 'cherry', 'Kiwi', 'Orange']

# Reverse Order
# Reverse the order of the list items:
thislist = ["banana", "Orange", "Kiwi", "cherry"]
thislist.reverse()
print(thislist) # ['cherry', 'Kiwi', 'Orange', 'banana']

#---------------------------------------------------------------------------
# Copy Lists
#---------------------------------------------------------------------------
# You cannot copy a list simply by typing list2 = list1, 
# because: list2 will only be a reference to list1, 
# and changes made in list1 will automatically also be made in list2.

# There are ways to make a copy, one way is to use the built-in List method copy().
# Make a copy of a list with the copy() method:
thislist = ["apple", "banana", "cherry"]
mylist = thislist.copy()
print(mylist) # ['apple', 'banana', 'cherry']

# Another way to make a copy is to use the built-in method list().
thislist = ["apple", "banana", "cherry"]
mylist = list(thislist)
print(mylist) # ['apple', 'banana', 'cherry']

#---------------------------------------------------------------------------
# Join Lists
#---------------------------------------------------------------------------
# Join Two Lists
# There are several ways to join, or concatenate, two or more lists in Python.
# One of the easiest ways are by using the + operator.
list1 = ["a", "b", "c"]
list2 = [1, 2, 3]
list3 = list1 + list2
print(list3) # ['a', 'b', 'c', 1, 2, 3]

# Append list2 into list1:
list1 = ["a", "b" , "c"]
list2 = [1, 2, 3]
for x in list2:
  list1.append(x)
print(list1)   # ['a', 'b', 'c', 1, 2, 3]

# Use the extend() method to add list2 at the end of list1:
list1 = ["a", "b" , "c"]
list2 = [1, 2, 3]
list1.extend(list2)
print(list1) # ['a', 'b', 'c', 1, 2, 3]

#---------------------------------------------------------------------------
# Join Methods
#---------------------------------------------------------------------------

# Method	Description
# append()	Adds an element at the end of the list
# clear()	Removes all the elements from the list
# copy()	Returns a copy of the list
# count()	Returns the number of elements with the specified value
# extend()	Add the elements of a list (or any iterable), to the end of the current list
# index()	Returns the index of the first element with the specified value
# insert()	Adds an element at the specified position
# pop()	    Removes the element at the specified position
# remove()	Removes the item with the specified value
# reverse()	Reverses the order of the list
# sort()	Sorts the list