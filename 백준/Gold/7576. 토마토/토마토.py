from collections import deque

m, n = map(int, input().split())
graph = []
for _ in range(n):
    graph.append(list(map(int, input().split())))

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def bfs():
    q = deque()
    for i in range(n):
        for j in range(m):
            if graph[i][j] == 1:
                q.append((i, j))
    while q:
        y, x = q.popleft()

        for i in range(4):
            nx = x + dx[i];
            ny = y + dy[i];

            if nx < 0 or nx >= m or ny < 0 or ny >= n:
                continue

            if graph[ny][nx] == -1:
                continue

            if graph[ny][nx] == 0:
                graph[ny][nx] = graph[y][x] + 1
                q.append((ny, nx))


def check_before_bfs():
    count = 0
    for i in range(n):
        for j in range(m):
            if graph[i][j] == 0:
                count += 1
    # 익을 토마토가 존재하지 않음
    if count == 0:
        return False
    else:
        return True


def check_after_bfs():
    count = 0
    for i in range(n):
        for j in range(m):
            if graph[i][j] == 0:
                count += 1
    # 익지 않은 토마토가 존재
    if count > 0:
        return False
    else:
        return True


result = check_before_bfs()
if not result:
    print(0)
else:
    bfs()
    result = check_after_bfs()
    if not result:
        print(-1)
    else:
        max_day = 1
        for i in range(n):
            for j in range(m):
                max_day = max_day if max_day > graph[i][j] else graph[i][j]
        print(max_day - 1)
