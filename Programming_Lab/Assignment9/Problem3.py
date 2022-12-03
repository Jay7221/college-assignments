class Numeral:
    def __init__(self):
        self.x = 0

    def toRoman(self, k):
        self.x = k
        self.ans = []
        mp = {
                'M' : 1000,
                'CM' : 900,
                'D' : 500,
                'CD' : 400,
                'C' : 100,
                'XC' : 90,
                'L' : 50,
                'XL' : 40,
                'X' : 10,
                'IX' : 9,
                'V' : 5,
                'IV' : 4,
                'I' : 1
            }
        while k > 0:
            for st, val in zip(mp.keys(), mp.values()):
                if k >= val:
                    k = k - val
                    self.ans.append(st)
                    break
        self.ans = ''.join(self.ans)
        print(f'The roman numeral of {self.x} is {self.ans}')

c = Numeral()
c.toRoman(43)
