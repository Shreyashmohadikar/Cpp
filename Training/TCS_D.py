# from collections import defaultdict

# def max_damage(D, S, C, B):
#     category = defaultdict(list)
#     for d, s, c in zip(D, S, C):
#         category[c].append((s, d))
#     for c in category:
#         category[c].sort(reverse=True, key=lambda x: x[1]/x[0])
#     dp = [0]*(B+1)
#     for c in category:
#         for b in range(B, -1, -1):
#             for s, d in category[c]:
#                 if s <= b:
#                     dp[b] = max(dp[b], dp[b-s] + d)
#     return dp[B]

# D = list(map(int, input().split()))
# S = list(map(int, input().split()))
# C = list(map(int, input().split()))
# B = int(input())

# print(max_damage(D, S, C, B))


from collections import defaultdict

def solve(D, S, C, B):
    cat = defaultdict(list)
    for d, s, c in zip(D, S, C):
        cat[c].append((s, d))
    for c in cat:
        cat[c].sort(reverse=True, key=lambda x: x[1]/x[0])
    dp = [0]*(B+1)
    for c in cat:
        for b in range(B, -1, -1):
            for s, d in cat[c]:
                if s <= b:
                    dp[b] = max(dp[b], dp[b-s] + d)
    return dp[B]

D = list(map(int, input().split()))
S = list(map(int, input().split()))
C = list(map(int, input().split()))
B = int(input())

print(solve(D, S, C, B))
