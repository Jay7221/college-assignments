lst = [1.5, "Python", -5, 4, 0, 8, -3.2, 'C++']
print('a)', lst)
lst.append(0.8)
print('b)', lst)
lst.extend([1, 1.5, 6, 0, 8])
print('c)', lst)
lst.insert(2, 500)
print('d)', lst)
lst.remove('C++')
print('e)', lst)
lst.pop(5)
print('f)', lst)
print('g)', 'Index of element -5 is :' ,lst.index(-5))
print('h)', 'Occruence of 4 in lst is : ', lst.count(4))
print('i)', lst[2:6])
lst.reverse()
print('j)', lst)
newLst = lst.copy()
print('k)', newLst)