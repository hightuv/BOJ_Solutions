import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N;
    static int[][] board;
    static boolean[][] visited;
    static int count = 0;
    static int maxCount = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        board = new int[N][N];
        visited = new boolean[N][N];

        Set<Integer> height = new HashSet<>();

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
                height.add(board[i][j]);
            }
        }

        for (int h : height) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (board[i][j] >= h && !visited[i][j]) {
                        bfs(i, j, h);
                        count += 1;
                    }
                }
            }

            if (maxCount < count) {
                maxCount = count;
            }

            count = 0;
            initVisited();
        }

        System.out.println(maxCount);
    }

    static void initVisited() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                visited[i][j] = false;
            }
        }
    }

    static void bfs(int sr, int sc, int height) {
        Queue<int[]> q = new LinkedList<>();
        visited[sr][sc] = true;
        q.add(new int[] {sr, sc});

        int r, c, nr, nc;

        int[] dr = {-1, 1, 0, 0};
        int[] dc = {0, 0, -1, 1};

        while (!q.isEmpty()) {
            r = q.peek()[0];
            c = q.peek()[1];
            q.poll();

            for (int i = 0; i < 4; i++) {
                nr = r + dr[i];
                nc = c + dc[i];

                if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
                    if (!visited[nr][nc] && board[nr][nc] >= height) {
                        visited[nr][nc] = true;
                        q.add(new int[] {nr, nc});
                    }
                }
            }
        }
    }
}