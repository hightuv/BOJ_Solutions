import java.util.*;
import java.io.*;

public class Main {

    static final int sr = 0;
    static final int sc = 0;
    static int R, C;
    static char[][] board;
    static boolean[][] visited;
    static List<Character> route = new ArrayList<>();
    static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, -1, 1};
    static int answer = Integer.MIN_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        board = new char[R][C];
        visited = new boolean[R][C];

        String s;
        for (int i = 0; i < R; i++) {
            s = br.readLine();
            for (int j = 0; j < C; j++) {
                board[i][j] = s.charAt(j);
            }
        }



        visited[sr][sc] = true;
        route.add(board[sr][sc]);
        dfs(sr, sc, 0);

        System.out.println(answer + 1);
    }

    static void dfs(int r, int c, int depth) {
        if (answer < depth) {
            answer = depth;
        }

        int nr, nc;

        for (int i = 0; i < 4; i++) {
            nr = r + dr[i];
            nc = c + dc[i];

            if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                if (!visited[nr][nc]) {
                    if (checkDuplicate(board[nr][nc])) {
                        visited[nr][nc] = true;
                        route.add(board[nr][nc]);
                        dfs(nr, nc, depth + 1);
                        route.remove(depth + 1);
                        visited[nr][nc] = false;
                    }

                }
            }
        }
    }

    static boolean checkDuplicate(char x) {
        for (Character c : route) {
            if (c == x) {
                return false;
            }
        }
        return true;
    }
}