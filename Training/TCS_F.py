def room_optimization(room_sizes, initial_land, additional_land):
    def max_rooms(area):
        dp = [0]*(area+1)
        for i in range(1, area+1):
            for room in room_sizes:
                if room <= i:
                    dp[i] = max(dp[i], 1 + dp[i-room])
        return dp[-1]

    initial_rooms = max_rooms(initial_land)
    total_rooms = max_rooms(initial_land + additional_land)
    return total_rooms - initial_rooms

# Take the input for room sizes
A, B, C, D = map(int, input().split())
room_sizes = [A, B, C, D]

# Take the input for initial and additional land
X, Y = map(int, input().split())

# Calculate the difference in the number of rooms
difference = room_optimization(room_sizes, X, Y)

# Print the difference
print(difference)
