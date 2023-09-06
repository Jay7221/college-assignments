def swapTemp(a, b):
    tmp = a
    a = b
    b = tmp
    return [a, b]
def swapWithoutTemp(a, b):
    a = a ^ b
    b = a ^ b
    a = a ^ b
    return [a, b]
    
a = 10
b = 43
print(f"Initially : a = {a}, b = {b}")
a, b = swapTemp(a, b)
print(f"After swapping with temporary variable : a = {a}, b = {b}")
a, b = swapWithoutTemp(a, b)
print(f"After swapping without temporary variable : a = {a}, b = {b}")
