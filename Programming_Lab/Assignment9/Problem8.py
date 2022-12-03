import os

fp = open('file.txt', 'x')
fp.write('Hello World')
fp.write('This is a new file named file.txt')
fp.close()


print("Reading File using readline() : ")
with open('file.txt', 'r') as file:
    s = file.readline()
    while len(s) > 0:
        print(s)
        s = file.readline()


print('\n\n')


print('Reading file using read() : ')
with open('file.txt', 'r') as file:
    print(file.read())

print('\n\n')


print('Reading file using for loop : ')
with open('file.txt', 'r') as file:
    for ch in file:
        print(ch, end = '')

print('\n\n')

with open('file.txt', 'w') as file:
    file.write('Hello this file is being overwritten')

with open('file.txt', 'r') as file:
    print(file.read())

print('\n\n')
with open('file.txt', 'a') as file:
    file.write('This text is being appended to the end of the file')

print('\n\n')
file = open('file.txt', 'r')
print(file.read())
file.close()

print('\n\n')
print('The file file.txt is being deleted!!')
if os.path.exists('file.txt'):
    os.remove('file.txt')
