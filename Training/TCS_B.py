# def solve(arr, n):
#     arr = [a.lower() for a in arr]

#     while True:
#         s = ''.join([a[0] for a in arr])
#         found = False
#         for i in range(len(s)):
#             for j in range(i+2, len(s)+1):
#                 if s[i:j] == s[i:j][::-1]:
#                     del arr[i]
#                     found = True
#                     break
#             if found:
#                 break
#         if not found:
#             break

#     index = 0
#     while len(arr) > 1:
#         index = (index + n - 1) % len(arr)
#         del arr[index]

#     return arr[0]

# names = input().split()
# N = int(input())

# result = solve(names, N)
# print(result)


def find_winner(names, N):
    # Function to check if a word is a mirror word
    def is_mirror_word(word):
        return word == word[::-1]

    # Remove mirror words
    names = [name for name in names if not is_mirror_word(name)]

    # Eliminate every Nth name until only one name is left
    index = 0
    while len(names) > 1:
        index = (index + N - 1) % len(names)
        del names[index]

    # The last name left is the winner
    return names[0]

# Test the function with the provided examples
print(find_winner(['Janu', 'gita', 'sana', 'gopi', 'jaslin', 'Tony', 'Ritu', 'Naina', 'sonu', 'Neha'], 2))  # Output: Janu
print(find_winner(['Vishal', 'ram', 'Vina', 'veda', 'Lekha', 'Rahul', 'Keerthi'], 1))  # Output: Keerthi


JGSJTRNS



