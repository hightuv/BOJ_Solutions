import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

import static java.util.Collections.sort;

public class Main {

    static int M, N, K;
    static int[][] board;
    static boolean[][] visited;

    static int count = 0;

    static List<Integer> areaList = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        board = new int[M][N];
        visited = new boolean[M][N];

        int x1, y1, x2, y2;

        while (K != 0) {
            st = new StringTokenizer(br.readLine());

            x1 = Integer.parseInt(st.nextToken());
            y1 = Integer.parseInt(st.nextToken());
            x2 = Integer.parseInt(st.nextToken());
            y2 = Integer.parseInt(st.nextToken());

            // 0 2 4 4 -> r 1 ~ 2 / c 0 ~ 3
            for (int i =  M - y1 - 1; i >= M - y2; i--) {
                for (int j = x1; j <= x2 - 1; j++) {
                    board[i][j] = 1;
                }
            }

            K -= 1;
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j] && board[i][j] != 1) {
                    bfs(i, j);
                    count += 1;
                }
            }
        }

        System.out.println(count);

        sort(areaList);

        for (Integer a : areaList) {
            System.out.print(a + " ");
        }
        System.out.println();
    }

    static void bfs(int sr, int sc) {
        Queue<int[]> q = new LinkedList<>();
        visited[sr][sc] = true;
        q.add(new int[] {sr, sc});

        int area = 1;

        int[] dr = {-1, 1, 0, 0};
        int[] dc = {0, 0, -1, 1};

        int r, c, nr, nc;

        while (!q.isEmpty()) {
            r = q.peek()[0];
            c = q.peek()[1];
            q.poll();

            for (int i = 0; i < 4; i++) {
                nr = r + dr[i];
                nc = c + dc[i];

                if (nr >= 0 && nr < M && nc >= 0 && nc < N) {
                    if (!visited[nr][nc] && board[nr][nc] == 0) {
                        visited[nr][nc] = true;
                        area += 1;
                        q.add(new int[] {nr, nc});
                    }
                }
            }
        }

        areaList.add(area);
    }
}