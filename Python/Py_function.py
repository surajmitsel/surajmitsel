def my_function(fname, lname):
  print(fname + " " + lname)
my_function("Emil", "Refsnes") # Emil Refsnes

#--------------------------------------
# Arbitrary Arguments, *args
#--------------------------------------
# If the number of arguments is unknown, add a * before the parameter name:
def my_function(*kids):
  print("The youngest child is " + kids[2])
my_function("Emil", "Tobias", "Linus") # The youngest child is Linus

#--------------------------------------
# Keyword Arguments
#--------------------------------------
def my_function(child3, child2, child1):
  print("The youngest child is " + child3)
my_function(child1 = "Emil", child2 = "Tobias", child3 = "Linus")


#--------------------------------------
# Arbitrary Keyword Arguments, **kwargs
#--------------------------------------
# If you do not know how many keyword arguments that will be passed into your function, add two asterisk: ** before the parameter name in the function definition.
# This way the function will receive a dictionary of arguments, and can access the items accordingly:
def my_function(**kid):
  print("His last name is " + kid["lname"])
my_function(fname = "Tobias", lname = "Refsnes") # His last name is Refsnes

#--------------------------------------
# Default Parameter Value
#--------------------------------------
def my_function(country = "Norway"):
  print("I am from " + country)
my_function("Sweden")
my_function("India")
my_function()
my_function("Brazil")
# I am from Sweden
# I am from India
# I am from Norway
# I am from Brazil

#--------------------------------------
# Passing a List as an Argument
#--------------------------------------
# You can send any data types of argument to a function (string, number, list, dictionary etc.), 
# and it will be treated as the same data type inside the function.
def my_function(food):
  for x in food:
    print(x)
fruits = ["apple", "banana", "cherry"]
my_function(fruits)
# apple
# banana
# cherry

#--------------------------------------
# Return Values
#--------------------------------------
# To let a function return a value, use the return statement:
def my_function(x):
  return 5 * x
print(my_function(3))
print(my_function(5))
print(my_function(9))
# 15
# 25
# 45

#--------------------------------------
# The pass Statement
#--------------------------------------
# function definitions cannot be empty, but if you for some reason have a function definition with 
# no content, put in the pass statement to avoid getting an error.
def myfunction():
  pass
# having an empty function definition like this, would raise an error without the pass statement

#--------------------------------------
# Recursion
#--------------------------------------
# Python also accepts function recursion, which means a defined function can call itself.
def tri_recursion(k):
  if(k > 0):
    result = k + tri_recursion(k - 1)
    print(result)
  else:
    result = 0
  return result

print("\n\nRecursion Example Results")
tri_recursion(6)
# Recursion Example Results
# 1
# 3
# 6
# 10
# 15
# 21

#--------------------------------------
# Python Lambda
#--------------------------------------
# A lambda function is a small anonymous function.
# A lambda function can take any number of arguments, but can only have one expression.

# Syntax
# lambda arguments : expression

# Add 10 to argument a, and return the result:
x = lambda a : a + 10
print(x(5)) # 15

# Multiply argument a with argument b and return the result:
x = lambda a, b : a * b
print(x(5, 6)) # 30

# Summarize argument a, b, and c and return the result:
x = lambda a, b, c : a + b + c
print(x(5, 6, 2)) # 13