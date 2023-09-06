class AcceptNumbers:
    def __init__(self):
        self.x = 0
        self.y = 0
        self.z = 0

    def getNumbers(self):
        self.x = int(input('Enter first number : '))
        self.y = int(input('Enter second number : '))
        self.z = int(input('Enter third number : '))

    def printNumbers(self):
        arr = [self.x, self.y, self.z]
        arr.sort()
        self.x = arr[2]
        self.y = arr[1]
        self.z = arr[0]
        print(f'Largest Number : {self.x}, Second Largest : {self.y}, Third Largest : {self.z}')

c = AcceptNumbers()
c.getNumbers()
c.printNumbers()
