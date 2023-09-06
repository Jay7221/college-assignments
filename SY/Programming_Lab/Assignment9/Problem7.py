class Calculator:
    def __init__(self):
        self.x = 0
        self.y = 0
        self.z = 0

    def getNumbers(self):
        self.a = int(input('Enter number a : '))
        self.b = int(input('Enter number b : '))
        self.c = int(input('Enter number c : '))
        self.x = self.a / self.b - self.c

    def calcX(self):
        print(f'Value of X is : {self.x}')



c = Calculator()
c.getNumbers()
c.calcX()
