import java.io.*;
import java.util.*;

public class Main {

    static int N;

    static int[] operands;

    static int[] operators;

    static int maximum = Integer.MIN_VALUE;
    static int minimum = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        operands = new int[N];
        operators = new int[4];

        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            operands[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < 4; i++) {
            operators[i] = Integer.parseInt(st.nextToken());
        }

        dfs(1, operands[0]);

        System.out.println(maximum);
        System.out.println(minimum);
    }

    static void dfs(int depth, int result) {
        if (depth == N) {
            if (maximum < result) {
                maximum = result;
            }
            if (minimum > result) {
                minimum = result;
            }
            return;
        }

        for (int i = 0; i < 4; i++) {
            if (operators[i] > 0) {
                operators[i] -= 1;

                if (i == 0) {
                    dfs(depth + 1, result + operands[depth]);
                }
                else if (i == 1) {
                    dfs(depth + 1, result - operands[depth]);
                }
                else if (i == 2) {
                    dfs(depth + 1, result * operands[depth]);
                }
                else if (i == 3) {
                    dfs(depth + 1, result / operands[depth]);
                }

                operators[i] += 1;
            }
        }
    }
}

