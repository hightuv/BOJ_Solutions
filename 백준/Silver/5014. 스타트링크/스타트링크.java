import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int F, S, G, U, D;
    static int[] floor;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        F = Integer.parseInt(st.nextToken()); // Total floors
        S = Integer.parseInt(st.nextToken()); // Current floor
        G = Integer.parseInt(st.nextToken()); // Destination
        U = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());

        floor = new int[F + 1];
        visited = new boolean[F + 1];

        if (bfs(S)) {
            System.out.println(floor[G]);
        }
        else {
            System.out.println("use the stairs");
        }
    }

    static boolean bfs(int start) {
        Queue<Integer> q = new LinkedList<>();
        visited[start] = true;
        q.add(start);

        int cur;

        while (!q.isEmpty()) {
            cur = q.peek();
            q.poll();

            if (cur == G) {
                return true;
            }

            int next;
            for (int i = 0; i < 2; i++) {
                if (i == 0) {
                    next = cur + U;
                }
                else {
                    next = cur - D;
                }

                if (next >= 1 && next <= F) {
                    if (!visited[next]) {
                        floor[next] = floor[cur] + 1;
                        visited[next] = true;
                        q.add(next);
                    }
                }
            }
        }

        return false;
    }
}