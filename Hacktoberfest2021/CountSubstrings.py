#1 METHOD!
# Time Complexity : O(1)

def substr_formula(string):

    substring = 0
    # length of the given string
    n = len(string)
    substring = n * (n + 1) // 2

    return substring

  
#2 METHOD!
# Time Complexity : O(n*n)     Consume time for longer strings!

def substr_gen(string):

    substring = 0
    n = len(string)
    # List to store all the calculated substrings
    substr = []

    #loop to append string and get substrings
    for i in range(n):
        for j in range(i, n):
            substr.append(string[i:j])

    substring = len(substr)

    return substring

  
# Main Code(execution starts)
if __name__ == '__main__':
    str = input("enter the string:")

    print('Total number of substring using formula= %d' % substr_formula(str))
    print('Total number of substring using general method= %d' % substr_gen(str))
