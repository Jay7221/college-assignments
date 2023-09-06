newDict = {'Jay' : 34, 'Rahul' : 43}
print(newDict.keys())
print(newDict.values())
for name in ['Jay', 'Rahul', 'Chinmay']:
    newDict.setdefault(name, 'NOT AVALIABLE')
    print('Roll No. of ', name, newDict[name])
newDict['newKey'] = 'Value'
print(newDict['newKey'])
del newDict['newKey']
print(newDict)
copyDict = newDict.copy()
print(copyDict)
print(len(newDict))
del newDict
