class Temperature:
    def __init__(self):
        self.name = "Temp"

    def ConvertCelsius(self, t):
        cel = (t - 32) * 5 / 9
        return cel

    def ConvertFarenheit(self, t):
        far = (t * 9 / 5) + 32
        return far

Temp = Temperature()
t1 = int(input("Enter temperature in Celsius : "))
print("temp in Farenheit : ", Temp.ConvertFarenheit(t1))
t2 = int(input("Enter temperature in Farenheit : "))
print("temp in Celsius : ", Temp.ConvertCelsius(t2))
