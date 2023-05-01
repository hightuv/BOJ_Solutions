import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static int maximum = Integer.MIN_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        List<Integer> list = new ArrayList<>();

        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            list.add(Integer.parseInt(st.nextToken()));
        }

        dfs(list, 0);

        System.out.println(maximum);
    }

    static void dfs(List<Integer> list, int sum) {
        if (list.size() <= 2) {
            if (maximum < sum) {
                maximum = sum;
            }
            return;
        }

        for(int i = 1; i < list.size() - 1; i++) {
            int del = list.get(i);
            int gather = list.get(i - 1) * list.get(i + 1);

            list.remove(i);
            dfs(list, sum + gather);
            list.add(i, del);
        }
    }
}