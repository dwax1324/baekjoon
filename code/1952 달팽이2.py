import sys

# 구현
# 달팽이
sys.setrecursionlimit(10**8)
a, b = map(int, input().split())


ff = [[0, 1], [1, 0], [0, -1], [-1, 0]]
arr = [[0 for i in range(120)] for i in range(120)]
direct = 0


def turn():
    global direct
    direct += 1
    direct %= 4
    return direct


def dfs(y, x):
    global direct
    global cnt
    arr[y][x] = 1
    ny = y + ff[direct][0]
    nx = x + ff[direct][1]
    if(arr[y+1][x] == 1 and arr[y][x+1] == 1 and arr[y-1][x] == 1 and arr[y][x-1] == 1):
        return
    if ny < 1 or nx < 1 or ny >= a+1 or nx >= b+1:
        turn()
        cnt += 1
    elif arr[ny][nx] == 1:
        turn()
        cnt += 1
    ny = y + ff[direct][0]
    nx = x + ff[direct][1]
    dfs(ny, nx)


y = 1
x = 1
cnt = 0
if a == 2 or b == 2:
    print(2)
else:
    dfs(y, x)
    print(cnt)
