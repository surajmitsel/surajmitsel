# Built-in Data Types
# Text Type:	    str
# Numeric Types:	int, float, complex
# Sequence Types:	list, tuple, range
# Mapping Type:	    dict
# Set Types:	    set, frozenset
# Boolean Type:	    bool
# Binary Types:	    bytes, bytearray, memoryview
# None Type:	    NoneType

#---------------------------------------------------------------------------
# Setting the Data Type
# In Python, the data type is set when you assign a value to a variable:
#---------------------------------------------------------------------------	
x = "Hello World"	                            # str	
x = 20	                                        # int	
x = 20.5	                                    # float	
x = 1j	                                        # complex	
x = ["apple", "banana", "cherry"]	            # list  []
x = ("apple", "banana", "cherry")	            # tuple  ()	 	
x = {"name" : "John", "age" : 36}	            # dict   {key:value}	
x = {"apple", "banana", "cherry"}	            # set	   {}
x = frozenset({"apple", "banana", "cherry"})	# frozenset ({})
x = range(6)	                                # range	
x = True	                                    # bool	
x = b"Hello"	                                # bytes	
x = bytearray(5)	                            # bytearray	
x = memoryview(bytes(5))	                    # memoryview	
x = None	                                    # NoneType

#---------------------------------------------------------------------------
# Setting the Specific Data Type
# If you want to specify the data type, you can use the following constructor functions:	

x = str("Hello World")	                        # str	
x = int(20)	                                    # int	
x = float(20.5)	                                # float	
x = complex(1j)	                                # complex	
x = list(("apple", "banana", "cherry"))	        # list	
x = tuple(("apple", "banana", "cherry"))	    # tuple	
x = range(6)	                                # range	
x = dict(name="John", age=36)	                # dict	
x = set(("apple", "banana", "cherry"))	        # set	
x = frozenset(("apple", "banana", "cherry"))	# frozenset	
x = bool(5)	                                    # bool	
x = bytes(5)	                                # bytes	
x = bytearray(5)	                            # bytearray	
x = memoryview(bytes(5))	                    # memoryview


#display x:
print(x)

#display the data type of x:
print(type(x)) 

# o/p
# <memory at 0x104080e80>
# <class 'memoryview'>

#---------------------------------------------------------------------------
# Convert from one type to another:

x = 1    # int
y = 2.8  # float
z = 1j   # complex

#convert from int to float:
a = float(x)

#convert from float to int:
b = int(y)

#convert from int to complex:
c = complex(x)

print(a)
print(b)
print(c)

print(type(a))
print(type(b))
print(type(c))

# o/p
# 1.0
# 2
# (1+0j)
# <class 'float'>
# <class 'int'>
# <class 'complex'>
#---------------------------------------------------------------------------