import java.io.*;
import java.util.*;
public class Main {
    static int[][] board;
    static List<Pair> empty = new ArrayList<>();
    static boolean solved = false;


    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        board = new int[9][9];

        StringTokenizer st;

        for (int i = 0; i < 9; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 9; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
                if (board[i][j] == 0) {
                    empty.add(new Pair(i, j));
                }
            }
        }

        sudoku(0);
        printAnswer();
    }

    static void sudoku(int n) {
        if (n == empty.size()) {
            solved = true;
            return;
        }

        for (int i = 1; i <= 9; i++) {
            if (check(empty.get(n).r, empty.get(n).c, i)) {
                board[empty.get(n).r][empty.get(n).c] = i;

                sudoku(n + 1);

                if (solved) {
                    return;
                }

                board[empty.get(n).r][empty.get(n).c] = 0;
            }
        }
    }

    static void printAnswer() {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }

    static boolean check(int row, int column, int value) {

        for (int i = 0; i < 9; i++) {
            // check if the value already exists in the same row
            if (board[row][i] == value) {
                return false;
            }
            // check if the value already exists in the same column
            if (board[i][column] == value) {
                return false;
            }
        }

        int areaRow = row / 3;
        int areaColumn = column / 3;

        for (int i = areaRow * 3; i < areaRow * 3 + 3; i++) {
            for (int j = areaColumn * 3; j < areaColumn * 3 + 3; j++) {
                if (board[i][j] == value) {
                    return false;
                }
            }
        }

        return true;
    }

    static class Pair {
        int r;
        int c;

        Pair(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }
}