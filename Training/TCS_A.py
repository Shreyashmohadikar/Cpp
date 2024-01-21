def solve(S1, S2):
    n = len(S1)
    S2 = S2 + S2[::-1]
    i = 0
    ans = []
    while i < n:
        j = i
        while j < n and S1[i:j+1] in S2:
            j += 1
        if j == i:
            return "Impossible"
        ans.append(S1[i:j])
        i = j
    return '|'.join(ans)

# Take input
S1 = input()
S2 = input()

# Test the function
result = solve(S1, S2)
print(result)
