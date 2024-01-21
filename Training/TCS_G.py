import math

def dream11_team(N, prices, values, budget):
    WicketKeeperCount = math.ceil(N * 0.2)
    BatsmenCount = (N - WicketKeeperCount) // 2
    BowlersCount = N - WicketKeeperCount - BatsmenCount
    AllRoundersCount = N - WicketKeeperCount - BatsmenCount - BowlersCount

    # Sort the players based on values
    players = sorted(range(N), key=lambda x: values[x], reverse=True)

    # Initialize counts for each player type
    wicket_keeper = 0
    batsmen = 0
    bowlers = 0
    all_rounders = 0

    total_value = 0
    total_price = 0

    for i in players:
        if wicket_keeper < WicketKeeperCount and i < N * 0.2:
            total_value += values[i]
            total_price += prices[i]
            wicket_keeper += 1
        elif batsmen < BatsmenCount and i % 2 != 0 and i >= N * 0.2:
            total_value += values[i]
            total_price += prices[i]
            batsmen += 1
        elif bowlers < BowlersCount and i % 2 == 0 and i % 4 != 0 and i >= N * 0.2:
            total_value += values[i]
            total_price += prices[i]
            bowlers += 1
        elif all_rounders < AllRoundersCount and i % 4 == 0 and i >= N * 0.2:
            total_value += values[i]
            total_price += prices[i]
            all_rounders += 1

    if total_price > budget:
        return "Insufficient Budget"
    return total_value

# Input
N = int(input())
prices = list(map(int, input().split()))
values = list(map(int, input().split()))
budget = int(input())

# Output
result = dream11_team(N, prices, values, budget)
print(result)
