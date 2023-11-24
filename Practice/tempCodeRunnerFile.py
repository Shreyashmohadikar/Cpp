def raj_cafe(N, priorities, K):
    friend_order = priorities[K-1]
    orders = [(priorities[i], i) for i in range(N)]
    orders.sort(reverse=True)
    time = 0
    while True:
        order = orders.pop(0)
        if order[1] == K-1 and order[0] >= max(orders)[0]:
            return time + 1
        else:
            orders.append((order[0]+1, order[1]))
            time += 1

N = int(input().strip())
priorities = list(map(int, input().strip().split()))
K = int(input().strip())

print(raj_cafe(N, priorities, K))
