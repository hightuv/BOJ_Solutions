import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N, M;
    static char[][] board;
    static HashSet<String> visited = new HashSet<>();

    static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, -1, 1};
    static int sr1, sc1, sr2, sc2;
    static Queue<TwoCoins> q = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        board = new char[N][M];

        int coins = 1;

        for (int i = 0; i < N; i++) {
            String s = br.readLine();
            for (int j = 0; j < M; j++) {
                board[i][j] = s.charAt(j);
                if (board[i][j] == 'o') {
                    if (coins == 1) {
                        sr1 = i;
                        sc1 = j;
                        coins += 1;
                    }
                    else if (coins == 2) {
                        sr2 = i;
                        sc2 = j;
                    }
                }
            }
        }

        q.add(new TwoCoins(sr1, sc1, sr2, sc2, 0));

        System.out.println(bfs());
    }

    static int bfs() {
        String start = "";
        start += sr1; start += sc1; start += sr2; start += sc2;
        visited.add(start);

        TwoCoins cur;

        while(!q.isEmpty()) {
            cur = q.poll();

            if (cur.trial > 10) {
                break;
            }

            for (int i = 0; i < 4; i++) {
                int nr1 = cur.r1 + dr[i];
                int nc1 = cur.c1 + dc[i];
                int nr2 = cur.r2 + dr[i];
                int nc2 = cur.c2 + dc[i];

                if ((!isInBoard(nr1, nc1) && isInBoard(nr2, nc2)) || (isInBoard(nr1, nc1) && !isInBoard(nr2, nc2))) {
                    if (cur.trial + 1 > 10) {
                        return -1;
                    }
                    return cur.trial + 1;
                }

                if (!isInBoard(nr1, nc1) && !isInBoard(nr2, nc2)) continue;

                if (board[nr1][nc1] == '#' && board[nr2][nc2] == '#') {
                    continue;
                }

                if (board[nr1][nc1] == '#') {
                    nr1 = cur.r1;
                    nc1 = cur.c1;
                }
                else if (board[nr2][nc2] == '#') {
                    nr2 = cur.r2;
                    nc2 = cur.c2;
                }

                String pos = "";
                pos += nr1; pos += nc1; pos += nr2; pos += nc2;

                if (!visited.contains(pos)) {
                    visited.add(pos);
                    q.add(new TwoCoins(nr1, nc1, nr2, nc2, cur.trial + 1));
                }
            }
        }

        return -1;
    }

    static boolean isInBoard(int r, int c) {
        return (r >= 0 && r < N) && (c >= 0 && c < M);
    }

    static class TwoCoins {
        int r1, c1;
        int r2, c2;
        int trial;

        public TwoCoins(int r1, int c1, int r2, int c2, int trial) {
            this.r1 = r1;
            this.c1 = c1;
            this.r2 = r2;
            this.c2 = c2;
            this.trial = trial;
        }
    }
}