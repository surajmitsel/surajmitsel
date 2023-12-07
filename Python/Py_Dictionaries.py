# Dictionary
# Dictionaries are used to store data values in key:value pairs.
# As of Python version 3.7, dictionaries are ordered. In Python 3.6 and earlier, dictionaries are unordered.

thisdict = {
  "brand": "Ford",
  "model": "Mustang",
  "year": 1964
}
print(thisdict) # {'brand': 'Ford', 'model': 'Mustang', 'year': 1964}
print(thisdict["brand"]) # Ford

# Changeable: meaning that we can change, add or remove items after the dictionary has been created.
# Duplicates Not Allowed: Dictionaries cannot have two items with the same key:
thisdict = {
  "brand": "Ford",
  "model": "Mustang",
  "year": 1964,
  "year": 2020
}
print(thisdict) # {'brand': 'Ford', 'model': 'Mustang', 'year': 2020}
print(len(thisdict)) # 3

# The values in dictionary items can be of any data type:
# String, int, boolean, and list data types:
thisdict = {
  "brand": "Ford",
  "electric": False,
  "year": 1964,
  "colors": ["red", "white", "blue"]
}
print(thisdict) # {'brand': 'Ford', 'electric': False, 'year': 1964, 'colors': ['red', 'white', 'blue']}
print(type(thisdict)) # <class 'dict'>

# The dict() Constructor
# Using the dict() method to make a dictionary:
thisdict = dict(name = "John", age = 36, country = "Norway")
print(thisdict) # {'name': 'John', 'age': 36, 'country': 'Norway'}

#---------------------------------------------------------------------------
# Access Dictionary Items
#---------------------------------------------------------------------------
thisdict =	{
  "brand": "Ford",
  "model": "Mustang",
  "year": 1964
}
x = thisdict["model"]
print(x) # Mustang


# There is also a method called get() that will give you the same result:
x = thisdict.get("model")
print(x) # Mustang
x = thisdict.keys()
print(x) # dict_keys(['brand', 'model', 'year'])


# Add a new item to the original dictionary, and see that the keys list gets updated as well:
car = {
"brand": "Ford",
"model": "Mustang",
"year": 1964
}
x = car.keys()
print(x) # dict_keys(['brand', 'model', 'year'])
car["color"] = "white"
print(x) # dict_keys(['brand', 'model', 'year', 'color'])


# Get Values: The values() method will return a list of all the values in the dictionary.
thisdict = {
  "brand": "Ford",
  "model": "Mustang",
  "year": 1964
}
x = thisdict.values()
print(x) # dict_values(['Ford', 'Mustang', 1964])


# Make a change in the original dictionary, and see that the values list gets updated as well:
car = {
"brand": "Ford",
"model": "Mustang",
"year": 1964
}
x = car.values()
print(x) # dict_values(['Ford', 'Mustang', 1964])
car["year"] = 2020
print(x) # dict_values(['Ford', 'Mustang', 2020])


# Add a new item to the original dictionary, and see that the values list gets updated as well:
car = {
"brand": "Ford",
"model": "Mustang",
"year": 1964
}
x = car.values()
print(x) # dict_values(['Ford', 'Mustang', 1964])
car["color"] = "red"
print(x) # dict_values(['Ford', 'Mustang', 1964, 'red'])


# Get Items: The items() method will return each item in a dictionary, as tuples in a list.
thisdict = {
  "brand": "Ford",
  "model": "Mustang",
  "year": 1964
}
x = thisdict.items()
print(x) # dict_items([('brand', 'Ford'), ('model', 'Mustang'), ('year', 1964)])


# Make a change in the original dictionary, and see that the items list gets updated as well:
car = {
"brand": "Ford",
"model": "Mustang",
"year": 1964
}
x = car.items()
print(x) # dict_items([('brand', 'Ford'), ('model', 'Mustang'), ('year', 1964)])
car["year"] = 2020
print(x) # dict_items([('brand', 'Ford'), ('model', 'Mustang'), ('year', 2020)])


# Add a new item to the original dictionary, and see that the items list gets updated as well:
car = {
"brand": "Ford",
"model": "Mustang",
"year": 1964
}
x = car.items()
print(x) # dict_items([('brand', 'Ford'), ('model', 'Mustang'), ('year', 1964)])
car["color"] = "red"
print(x) # dict_items([('brand', 'Ford'), ('model', 'Mustang'), ('year', 1964), ('color', 'red')])


# Check if Key Exists
thisdict = {
  "brand": "Ford",
  "model": "Mustang",
  "year": 1964
}
if "model" in thisdict:
  print("Yes, 'model' is one of the keys in the thisdict dictionary")
  
#---------------------------------------------------------------------------
# Change Dictionary Items
#---------------------------------------------------------------------------

# You can change the value of a specific item by referring to its key name:
thisdict = {
  "brand": "Ford",
  "model": "Mustang",
  "year": 1964
}
thisdict["year"] = 2018
print(thisdict) # {'brand': 'Ford', 'model': 'Mustang', 'year': 2018}


# Update Dictionary
# Update the "year" of the car by using the update() method:
thisdict = {
  "brand": "Ford",
  "model": "Mustang",
  "year": 1964
}
thisdict.update({"year": 2020})
print(thisdict) # {'brand': 'Ford', 'model': 'Mustang', 'year': 2020}

#---------------------------------------------------------------------------
# Add Dictionary Items
#---------------------------------------------------------------------------

# Adding an item to the dictionary is done by using a new index key and assigning a value to it:
thisdict = {
  "brand": "Ford",
  "model": "Mustang",
  "year": 1964
}
thisdict["color"] = "red"
print(thisdict) # {'brand': 'Ford', 'model': 'Mustang', 'year': 1964, 'color': 'red'}


# Update Dictionary
# The update() method will update the dictionary with the items from a given argument. 
# If the item does not exist, the item will be added.
thisdict = {
  "brand": "Ford",
  "model": "Mustang",
  "year": 1964
}
thisdict.update({"color": "red"})
print(thisdict) # {'brand': 'Ford', 'model': 'Mustang', 'year': 1964, 'color': 'red'}

#---------------------------------------------------------------------------
# Remove Dictionary Items
#---------------------------------------------------------------------------

# Removing Items: There are several methods to remove items from a dictionary:
# The pop() method removes the item with the specified key name:
thisdict = {
  "brand": "Ford",
  "model": "Mustang",
  "year": 1964
}
thisdict.pop("model")
print(thisdict) # {'brand': 'Ford', 'year': 1964}


# The popitem() method removes the last inserted item (in versions before 3.7, 
# a random item is removed instead):
thisdict =	{
  "brand": "Ford",
  "model": "Mustang",
  "year": 1964
}
thisdict.popitem()
print(thisdict) # {'brand': 'Ford', 'model': 'Mustang'}


# The del keyword removes the item with the specified key name:
thisdict = {
  "brand": "Ford",
  "model": "Mustang",
  "year": 1964
}
del thisdict["model"]
print(thisdict) # {'brand': 'Ford', 'year': 1964}


# The del keyword can also delete the dictionary completely:
thisdict = {
  "brand": "Ford",
  "model": "Mustang",
  "year": 1964
}
del thisdict
# print(thisdict) #this will cause an error because "thisdict" no longer exists.


# The clear() method empties the dictionary:
thisdict = {
  "brand": "Ford",
  "model": "Mustang",
  "year": 1964
}
thisdict.clear()
print(thisdict) # {}

#---------------------------------------------------------------------------
# Loop Dictionaries
#---------------------------------------------------------------------------
# You can loop through a dictionary by using a for loop.
thisdict =	{
  "brand": "Ford",
  "model": "Mustang",
  "year": 1964
}
for x in thisdict:
  print(x)
# brand
# model
# year


# Print all values in the dictionary, one by one:
thisdict =	{
  "brand": "Ford",
  "model": "Mustang",
  "year": 1964
}
for x in thisdict:
  print(thisdict[x])
# Ford
# Mustang
# 1964


# You can also use the values() method to return values of a dictionary:
thisdict =	{
  "brand": "Ford",
  "model": "Mustang",
  "year": 1964
}
for x in thisdict.values():
  print(x)
# Ford
# Mustang
# 1964


# You can use the keys() method to return the keys of a dictionary:
thisdict =	{
  "brand": "Ford",
  "model": "Mustang",
  "year": 1964
}
for x in thisdict.keys():
  print(x)
# brand
# model
# year


# Loop through both keys and values, by using the items() method:
thisdict =	{
  "brand": "Ford",
  "model": "Mustang",
  "year": 1964
}
for x, y in thisdict.items():
  print(x, y)
# brand Ford
# model Mustang
# year 1964

#---------------------------------------------------------------------------
# Nested Dictionaries
#---------------------------------------------------------------------------
# A dictionary can contain dictionaries, this is called nested dictionaries.
# Create a dictionary that contain three dictionaries:
myfamily = {
  "child1" : {
    "name" : "Emil",
    "year" : 2004
  },
  "child2" : {
    "name" : "Tobias",
    "year" : 2007
  },
  "child3" : {
    "name" : "Linus",
    "year" : 2011
  }
}
print(myfamily) # {'child1': {'name': 'Emil', 'year': 2004}, 'child2': {'name': 'Tobias', 'year': 2007}, 'child3': {'name': 'Linus', 'year': 2011}}


# Or, if you want to add three dictionaries into a new dictionary:
child1 = {
  "name" : "Emil",
  "year" : 2004
}
child2 = {
  "name" : "Tobias",
  "year" : 2007
}
child3 = {
  "name" : "Linus",
  "year" : 2011
}

myfamily = {
  "child1" : child1,
  "child2" : child2,
  "child3" : child3
}
print(myfamily) # {'child1': {'name': 'Emil', 'year': 2004}, 'child2': {'name': 'Tobias', 'year': 2007}, 'child3': {'name': 'Linus', 'year': 2011}}


# Access Items in Nested Dictionaries
# Print the name of child 2:
myfamily = {
  "child1" : {
    "name" : "Emil",
    "year" : 2004
  },
  "child2" : {
    "name" : "Tobias",
    "year" : 2007
  },
  "child3" : {
    "name" : "Linus",
    "year" : 2011
  }
}
print(myfamily["child2"]["name"]) # Tobias

#---------------------------------------------------------------------------
# Dictionary Methods
#---------------------------------------------------------------------------
# clear()	    Removes all the elements from the dictionary
# copy()	    Returns a copy of the dictionary
# fromkeys()	Returns a dictionary with the specified keys and value
# get()	        Returns the value of the specified key
# items()	    Returns a list containing a tuple for each key value pair
# keys()	    Returns a list containing the dictionary's keys
# pop()	        Removes the element with the specified key
# popitem()	    Removes the last inserted key-value pair
# setdefault()	Returns the value of the specified key. If the key does not exist: insert the key, with the specified value
# update()	    Updates the dictionary with the specified key-value pairs
# values()	    Returns a list of all the values in the dictionary