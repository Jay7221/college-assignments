import math
def analyze(a, b, c, d):
    mean = (a + b + c + d)
    variance = 0
    for x in [a, b, c, d]:
        variance += (x - mean) ** 2
    variance /= 4
    stdDeviation = math.sqrt(variance)
    return [mean, variance, stdDeviation]
a = 10
b = 43
c = 52
d = 352
print(f"The numbers are : a = {a}, b = {b}, c = {c}, d = {d}")
mean, var, stdDev = analyze(a, b, c, d)
print(f"Mean = {mean}, variance = {var}, standard deviation = {stdDev}")

