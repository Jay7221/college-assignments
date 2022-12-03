def register():
    age = int(input('Enter the age of applicant : '))
    if age < 0:
        raise KeyError
    if age > 1000:
        raise ValueError
    if age > 90:
        raise Exception
    if age < 10:
        raise Exception
    print(f'Registraition Done for age : {age}')

try:
    register()
except KeyError as k:
    print('Invalid Input')
except ValueError as v:
    print('Invalid Value')
except:
    print('Some Error Occured')
else:
    print('Registration Succesfull')
