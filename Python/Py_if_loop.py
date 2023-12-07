# Python supports the usual logical conditions from mathematics:
# Equals:       a == b
# Not Equals:   a != b
# Less than:    a < b
# Less than or equal to:    a <= b
# Greater than:             a > b
# Greater than or equal to: a >= b

a = 200
b = 33
if b > a:
  print("b is greater than a")
elif a == b:
  print("a and b are equal")
else:
  print("a is greater than b")
  
  
# One line if statement:
if a > b: print("a is greater than b")

# One line if-else statement:
a = 2
b = 330
print("A") if a > b else print("B")

# This technique is known as Ternary Operators, or Conditional Expressions.
# One line if else statement, with 3 conditions:
a = 330
b = 330
print("A") if a > b else print("=") if a == b else print("B") # =


a = 200
b = 33
c = 500
if a > b and c > a:
  print("Both conditions are True")
if a > b or a > c:
  print("At least one of the conditions is True")

a = 33
b = 200
if not a > b:
  print("a is NOT greater than b")
  
# Nested If
# You can have if statements inside if statements, this is called nested if statements.
x = 41
if x > 10:
  print("Above ten,")
  if x > 20:
    print("and also above 20!")
  else:
    print("but not above 20.")
# Above ten,
# and also above 20!


# The pass Statement
# if statements cannot be empty, but if you for some reason have an 
# if statement with no content, put in the pass statement to avoid getting an error.
a = 33
b = 200
if b > a:
  pass
# having an empty if statement like this, would raise an error without the pass statement

#---------------------------------------------------------------------------
# While loop
#---------------------------------------------------------------------------
# Print i as long as i is less than 6:
i = 1
while i < 6:
  print(i)
  i += 1
# 1
# 2
# 3
# 4
# 5


# Exit the loop when i is 3:
i = 1
while i < 6:
  print(i)
  if i == 3:
    break
  i += 1
# 1
# 2
# 3


# Continue to the next iteration if i is 3:
i = 0
while i < 6:
  i += 1
  if i == 3:
    continue
  print(i)
# 1
# 2
# 4
# 5
# 6


# With the else statement we can run a block of code once when the condition no longer is true:
i = 1
while i < 6:
  print(i)
  i += 1
else:
  print("i is no longer less than 6")
# 1
# 2
# 3
# 4
# 5
# i is no longer less than 6

#---------------------------------------------------------------------------
# While loop
#---------------------------------------------------------------------------
# A for loop is used for iterating over a sequence (that is either 
# a list, a tuple, a dictionary, a set, or a string).

fruits = ["apple", "banana", "cherry"]
for x in fruits:
  print(x)
# apple
# banana
# cherry


for x in "banana":
  print(x)
# b
# a
# n
# a
# n
# a


fruits = ["apple", "banana", "cherry"]
for x in fruits:
  if x == "banana":
    break
  print(x) 
# apple


fruits = ["apple", "banana", "cherry"]
for x in fruits:
  if x == "banana":
    continue
  print(x) 
# apple
# cherry


# Using the range() function:
for x in range(6):
  print(x) 
# 0
# 1
# 2
# 3
# 4
# 5


for x in range(2, 6):
  print(x) 
# 2
# 3
# 4
# 5


# Increment the sequence with 3 (default is 1):
for x in range(2, 30, 3):
  print(x) 
# 2
# 5
# 8
# 11
# 14
# 17
# 20
# 23
# 26
# 29


for x in range(6):
  print(x)
else:
  print("Finally finished!")
# 0
# 1
# 2
# 3
# 4
# 5
# Finally finished!


#If the loop breaks, the else block is not executed.
for x in range(6):
  if x == 3: break
  print(x)
else:
  print("Finally finished!")
# 0
# 1
# 2


# Nested Loops
adj = ["red", "big", "tasty"]
fruits = ["apple", "banana", "cherry"]
for x in adj:
  for y in fruits:
    print(x, y)
# red apple
# red banana
# red cherry
# big apple
# big banana
# big cherry
# tasty apple
# tasty banana
# tasty cherry


# The pass Statement
for x in [0, 1, 2]:
  pass
# having an empty for loop like this, would raise an error without the pass statement