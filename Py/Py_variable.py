#---------------------------------------------------------------------------
print("welcome Python : this is print statement")
#---------------------------------------------------------------------------
# If you want to specify the data type of a variable,
# this can be done with casting.

x = str(3)    # x will be '3'
y = int(3)    # y will be 3
z = float(3)  # z will be 3.0
#---------------------------------------------------------------------------
# Get the Type
# You can get the data type of a variable with the type() function.

x = 5
y = "John"
print(type(x)) # o/p: <class 'int'>
print(type(y)) # o/p: <class 'str'>
#---------------------------------------------------------------------------
# String variables can be declared either by using single or double quotes:

x = "John"
# is the same as
x = 'John'
#---------------------------------------------------------------------------
#A will not overwrite a. these 2 are seperate variables
a = 4
A = "Sally"

#---------------------------------------------------------------------------
# Legal variable names:
myvar = "John"
my_var = "John"
_my_var = "John"
myVar = "John"
MYVAR = "John"
myvar2 = "John"

# Illegal variable names:
# 2myvar = "John"
# my-var = "John"
# my var = "John"

#---------------------------------------------------------------------------
# "Many Values to Multiple Variables"

x, y, z = "Orange", "Banana", "Cherry"
print("x:" + x)
print("y:" +y)
print("z:" + z)

#o/p
# x:Orange
# y:Banana
# z:Cherry

#---------------------------------------------------------------------------
# One Value to Multiple Variables

x = y = z = "Orange"
print("x:",x)
print("y:", y)
print("z:",z)

#o/p
# x: Orange
# y: Orange
# z: Orange

#---------------------------------------------------------------------------
# Unpack a Collection
# If you have a collection of values in a list, tuple etc. 
# Python allows you to extract the values into variables. This is called unpacking.

fruits = ["apple", "banana", "cherry"]
x, y, z = fruits
print(x)
print(y)
print(z)

#o/p
# apple
# banana
# cherry

#---------------------------------------------------------------------------
# Python - Output Variables
# The Python print() function is often used to output variables.

x = "Python is awesome"
print(x)

# o/p
# Python is awesome

#---------------------------------------------------------------------------
# In the print() function, you output multiple variables, separated by a comma:

x = "Python"
y = "is"
z = "awesome"
print(x, y, z)

# o/p
# Python is awesome

# You can also use the + operator to output multiple variables:
x = "Python "
y = "is "
z = "awesome"
print(x + y + z)

# o/p
# Python is awesome

x = 5
y = 10
print(x + y)
# o/p
# 15

#---------------------------------------------------------------------------
# In the print() function, when you try to combine a string and a number 
# with the + operator, Python will give you an error:
x = 5
y = "John"
# print(x + y)

# o/p
# error: TypeError: unsupported operand type(s) for +: 'int' and 'str'

x = 5
y = "John"
print(x, y)

# o/p
# 5 John

#---------------------------------------------------------------------------
# Create a variable inside a function, with the same name as the global variable
x = "awesome"

def myfunc():
  x = "fantastic"
  print("Python is " + x)

myfunc()

print("Python is " + x)

# o/p
# Python is fantastic
# Python is awesome

#---------------------------------------------------------------------------
# Also, use the global keyword if you want to change a global variable 
# inside a function.
# To change the value of a global variable inside a function, 
# refer to the variable by using the global keyword:
x = "awesome"

def myfunc():
  global x
  x = "fantastic"

myfunc()

print("Python is " + x)

# o/p
# Python is fantastic
