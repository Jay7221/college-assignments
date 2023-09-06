def get_notes(n):
    hundred = n / 100
    n = n % 100
    fifty = n / 50
    n = n % 50
    ten = n / 10
    print("Give %d notes of 100, %d notes of 50, %d notes of 10" % (hundred, fifty, ten))
    
n = int(input("Input the amount to be withdrawn : "))
get_notes(n)
