def fibonacci(num):
    a = 0
    b = 1
    c = 0

    while(c <= num):
        c = a+b
        a = b
        b = c
        print(c)


fibonacci(10)
