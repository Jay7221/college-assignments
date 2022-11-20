def countSpaces(s):
    ans = 0
    for character in s:
        if character == ' ':
            ans += 1
    return ans

s = input("Enter a string : ")
print("The number of spaces is : %d"%countSpaces(s))
