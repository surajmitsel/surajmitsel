# A set is a collection which is unordered, unchangeable*, and unindexed.
# Set items are unchangeable, but you can remove items and add new items.
# Sets are used to store multiple items in a single variable.

# Unordered: Unordered means that the items in a set do not have a defined order.
# Unordered: Set items can appear in a different order every time you use them, and cannot be referred to by index or key.
# Unchangeable: Once a set is created, you cannot change its items, but you can remove items and add new items.

# Create a Set:
thisset = {"apple", "banana", "cherry"}
print(thisset)

# Duplicates Not Allowed: Sets cannot have two items with the same value.
thisset = {"apple", "banana", "cherry", "apple"}
print(thisset) # {'banana', 'cherry', 'apple'}

# True and 1 is considered the same value:
thisset = {"apple", "banana", "cherry", True, 1, 2}
print(thisset) # {True, 2, 'banana', 'cherry', 'apple'}

# False and 0 is considered the same value:
thisset = {"apple", "banana", "cherry", False, True, 0}
print(thisset) # {False, True, 'cherry', 'apple', 'banana'}

# Get the number of items in a set:
thisset = {"apple", "banana", "cherry"}
print(len(thisset)) # 3

# Set items can be of any data type:
set1 = {"apple", "banana", "cherry"}
set2 = {1, 5, 7, 9, 3}
set3 = {True, False, False}
print(set1)
print(set2)
print(set3)
# {'cherry', 'apple', 'banana'}
# {1, 3, 5, 7, 9}
# {False, True}

# A set with strings, integers and boolean values:
set1 = {"abc", 34, True, 40, "male"}
print(set1) # {True, 34, 40, 'male', 'abc'}

# The set() Constructor
# It is also possible to use the set() constructor to make a set.
# Using the set() constructor to make a set:
# note the double round-brackets
thisset = set(("apple", "banana", "cherry")) 
print(thisset) # {'cherry', 'apple', 'banana'} the oder can be anything in each executions

#---------------------------------------------------------------------------
# Access Set Items
#---------------------------------------------------------------------------
# 1. You cannot access items in a set by referring to an index or a key.
# 2. But you can loop through the set items using a for loop, or ask 
# if a specified value is present in a set, by using the in keyword.

thisset = {"apple", "banana", "cherry"}
for x in thisset:
  print(x)
# cherry
# banana
# apple

# Check if "banana" is present in the set:
thisset = {"apple", "banana", "cherry"}
print("banana" in thisset) # True

#---------------------------------------------------------------------------
# Add Set Items
#---------------------------------------------------------------------------
# Once a set is created, you cannot change its items, but you can add new items.
# To add one item to a set use the add() method.
thisset = {"apple", "banana", "cherry"}
thisset.add("orange")
print(thisset) # {'banana', 'cherry', 'orange', 'apple'}

# Add Sets
# To add items from another set into the current set, use the update() method.
thisset = {"apple", "banana", "cherry"}
tropical = {"pineapple", "mango", "papaya"}
thisset.update(tropical)
print(thisset) # {'apple', 'mango', 'cherry', 'pineapple', 'banana', 'papaya'}

# Add Any Iterable
# The object in the update() method does not have to be a set, it can be any iterable object (tuples, lists, dictionaries etc.).
thisset = {"apple", "banana", "cherry"}
mylist = ["kiwi", "orange"]
thisset.update(mylist)
print(thisset) # {'banana', 'cherry', 'apple', 'orange', 'kiwi'}

#---------------------------------------------------------------------------
# Remove Set Items
#---------------------------------------------------------------------------

# To remove an item in a set, use the remove(), or the discard() method.
thisset = {"apple", "banana", "cherry"}
thisset.remove("banana")
print(thisset) # {'apple', 'cherry'}

# Remove "banana" by using the discard() method:
# If the item to remove does not exist, discard() will NOT raise an error.
thisset = {"apple", "banana", "cherry"}
thisset.discard("banana")
print(thisset) # {'cherry', 'apple'}

# You can also use the pop() method to remove an item, but this method 
# will remove a random item, so you cannot be sure what item that gets removed.
# Note: Sets are unordered, so when using the pop() method, you do not know which item that gets removed.

thisset = {"apple", "banana", "cherry"}
x = thisset.pop()
print(x)
print(thisset)

# The clear() method empties the set:
thisset = {"apple", "banana", "cherry"}
thisset.clear()
print(thisset) # set()

# The del keyword will delete the set completely:
thisset = {"apple", "banana", "cherry"}
del thisset
# print(thisset) #this will raise an error because the set no longer exists

#---------------------------------------------------------------------------
# Loop Set Items
#---------------------------------------------------------------------------
# You can loop through the set items by using a for loop:

thisset = {"apple", "banana", "cherry"}
for x in thisset:
  print(x)

# banana
# cherry
# apple
#---------------------------------------------------------------------------
# Join Sets
#---------------------------------------------------------------------------
# There are several ways to join two or more sets in Python.
# You can use the union() method that returns a new set containing all items from both sets, 
# or the update() method that inserts all the items from one set into another:

# Note: Both union() and update() will exclude any duplicate items.

# The union() method returns a new set with all items from both sets:
set1 = {"a", "b" , "c"}
set2 = {1, 2, 3}
set3 = set1.union(set2)
print(set3) # {'c', 2, 'b', 'a', 1, 3}

# The update() method inserts the items in set2 into set1:
set1 = {"a", "b" , "c"}
set2 = {1, 2, 3}
set1.update(set2)
print(set1) # {2, 'b', 'c', 1, 3, 'a'}

# Keep ONLY the Duplicates
# The intersection_update() method will keep only the items that are present in both sets.
# Keep the items that exist in both set x, and set y:
x = {"apple", "banana", "cherry"}
y = {"google", "microsoft", "apple"}
x.intersection_update(y)
print(x) # {'apple'}

# The intersection() method will return a new set, that only contains the items that are present in both sets.
x = {"apple", "banana", "cherry"}
y = {"google", "microsoft", "apple"}
z = x.intersection(y)
print(z) # {'apple'}

# Keep All, But NOT the Duplicates
# The symmetric_difference_update() method will keep only the elements that are NOT present in both sets.
x = {"apple", "banana", "cherry"}
y = {"google", "microsoft", "apple"}
x.symmetric_difference_update(y)
print(x) # {'google', 'banana', 'microsoft', 'cherry'}

# The symmetric_difference() method will return a new set, that contains only the elements 
# that are NOT present in both sets.
x = {"apple", "banana", "cherry"}
y = {"google", "microsoft", "apple"}
z = x.symmetric_difference(y)
print(z) # {'google', 'banana', 'microsoft', 'cherry'}

# Note: The values True and 1 are considered the same value in sets, and are treated as duplicates:
x = {"apple", "banana", "cherry", True}
y = {"google", 1, "apple", 2}
z = x.symmetric_difference(y)
print(z) # {2, 'google', 'cherry', 'banana'}

#---------------------------------------------------------------------------
# Set Methods
#---------------------------------------------------------------------------
# Method	            Description
# add()	                Adds an element to the set
# clear()	            Removes all the elements from the set
# copy()	            Returns a copy of the set
# difference()	        Returns a set containing the difference between two or more sets
# difference_update()	Removes the items in this set that are also included in another, specified set
# discard()	            Remove the specified item
# intersection()	    Returns a set, that is the intersection of two other sets
# intersection_update()	Removes the items in this set that are not present in other, specified set(s)
# isdisjoint()	        Returns whether two sets have a intersection or not
# issubset()	        Returns whether another set contains this set or not
# issuperset()	        Returns whether this set contains another set or not
# pop()	                Removes an element from the set
# remove()	            Removes the specified element
# symmetric_difference()	        Returns a set with the symmetric differences of two sets
# symmetric_difference_update()	    inserts the symmetric differences from this set and another
# union()	            Return a set containing the union of sets
# update()	            Update the set with the union of this set and others
