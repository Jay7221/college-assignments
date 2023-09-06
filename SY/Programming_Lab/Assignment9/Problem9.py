import sys
def divide(a, b):
    return a / b

try:
    a = int(input('Enter first number: '))
    b = int(input('Enter second number: '))
    print(f'a / b = {a / b}')
except ZeroDivisionError:
    print('Value of b cannot be 0')
except ValueError:
    print('Value of a and b must be integer')
except Exception:
    print('Some Error Occured')
