def count_rooms(m, n, lines):
  """
  Counts the number of rooms and rooms with exits in a labyrinth.

  Args:
      m: Length of the rectangular cardboard.
      n: Height of the rectangular cardboard.
      lines: List of tuples representing starting and ending points of cardboard pieces.

  Returns:
      total_rooms: Total number of rooms in the labyrinth.
      exit_rooms: Number of rooms with exits.
  """
  rooms = [[False] * m for _ in range(n)]  # Mark if a cell is part of a room.
  exit_rooms = 0  # Number of rooms with exits.

  # Mark cells occupied by cardboard pieces.
  for (x1, y1, x2, y2) in lines:
    for x in range(x1, x2 + 1):
      for y in range(y1, y2 + 1):
        rooms[y][x] = True

  # Count rooms and rooms with exits.
  for y in range(n):
    for x in range(m):
      if not rooms[y][x]:
        # Found a new room, check its edges for exits.
        total_rooms += 1
        if (y == 0 or not rooms[y-1][x]) or \
          (y == n-1 or not rooms[y+1][x]) or \
          (x == 0 or not rooms[y][x-1]) or \
          (x == m-1 or not rooms[y][x+1]):
          exit_rooms += 1

  return total_rooms, exit_rooms

def main():
  # Read input
  m, n = map(int, input().split())
  t = int(input())
  lines = []
  for _ in range(t):
    lines.append(tuple(map(int, input().split())))

  # Count rooms and rooms with exits.
  total_rooms, exit_rooms = count_rooms(m, n, lines)

  # Calculate and print escape probability.
  escape_probability = (exit_rooms / total_rooms) * 100
  print(round(escape_probability))

if __name__ == "__main__":
  main()
