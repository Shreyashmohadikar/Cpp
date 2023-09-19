def sumOfDigits(n):
    power = 2**n
    return power % 9

# def sumOfDigits(n):
#     power = pow(2, n)
#     sumDig = 0
#     while power > 0:
#         sumDig += power % 10
#         power = power // 10
#     while power > 9:
#         sumDig = sum([int(digit) for digit in str(sumDig)])
#     return sumDig

t = int(input())
while t > 0:
    n = int(input())
    print(sumOfDigits(n))
    t -= 1


