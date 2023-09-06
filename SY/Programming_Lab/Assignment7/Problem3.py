def getGraceMarks(Class, numberFailSubjects):
    if Class == 'First' and numberFailSubjects > 3:
        return 0
    if numberFailSubjects <= 3:
        return (5 * numberFailSubjects)
    if Class == 'Second' and numberFailSubjects > 2:
        return 0
    if numberFailSubjects <= 2:
        return (4 * numberFailSubjects)
    if Class == 'Third' and numberFailSubjects > 1:
        return 0
    if numberFailSubjects == 1:
        return 5

n = int(input("Enter the number of subjects in which the student failed : "))
Class = input("Enter the class obtained by the student : ")
print("The student will get %d grace marks"%(getGraceMarks(Class, n)))
