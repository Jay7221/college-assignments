def getPopulation(initialPopulation, rateOfGrowth, growthPeriod, numberDoublings):
    ans = initialPopulation
    for i in range(numberDoublings):
        ans = ans * (1 + rateOfGrowth / 100)
    return ans

initialPopulation = int(input("Enter the initial population : "))
rateOfGrowth = int(input("Enter the rate of growth : "))
growthPeriod = int(input("Enter the amount of required to achieve this growth : "))

MAX = 10
for i in range(MAX):
    print("Population at time %d : %f" % (i * growthPeriod, 
getPopulation(initialPopulation, rateOfGrowth, growthPeriod, i)))

    
