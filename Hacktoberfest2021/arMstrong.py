# if sum of cubes of digits of a number is equal to the number
# itself then its an armstrong number
# for example 153 is a armestrong number (1^3 + 5^3 + 3^3 = 153)

# function to check if a number is armstrong or not
def isArmstrong(n):
    sum = 0
    k = n
    while k != 0:
        d = k % 10
        sum += d * d * d
        k = int(k/10)

    return (sum == n)

def main():
    num = int(input('Enter a number to check if its armstrong:\n'))
    armstrong = isArmstrong(num)
    if armstrong:
        print("It's an Armstrong number")
    else:
        print("It's not an Armstrong number")


if __name__ == '__main__':
    main()