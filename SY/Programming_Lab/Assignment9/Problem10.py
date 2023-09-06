def get():
    a = int(input('Enter a number of : '))
    b = int(input('Enter second number :'))
    print('a + b = {a + b}, a - b = {a - b}, a * b = {a * b}')

try:
    get()
except ValueError:
    print('Please Enter integer values')
else:
    print('No Error Occured')
finally:
    print('Program Execution Complete')
