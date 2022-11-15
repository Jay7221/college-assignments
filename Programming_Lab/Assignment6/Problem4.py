# a - Number
# b - List
# c - Tuple
# d - Byte
# e - Bytearray
# f - Set
# g - Frozenset
# h - Dictionary
a = 343
b = [3, 3,1, 5, 45, "Hello World", 43.43, [3, 3, 4]]
c = (3, 4, 2, 4)
d = b'4334'
e = bytearray(b'aaccdd34')
f = {3, 4, 2, 3, 3, 4, 5}
g = frozenset([4, 3, 42, 43, 2])
h = {"name":"Jay Shirgupe", "class":"CSE", "College":"Walchand College of Engineering, Sanglie"}
for elem in [a, b, c, d, e, f, g, h]:
    print(type(elem), elem, sep = '\n')
    print()
