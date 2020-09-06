import java.util.Scanner;

public class Main {
	static int N;
	static int M;
	static int K;
	static long[] numbers;
	static long[] tree;
	
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		N = scanner.nextInt();
		M = scanner.nextInt();
		K = scanner.nextInt();
		numbers = new long[N + 1];
		int height =  (int)Math.ceil(Math.log(N) / Math.log(2));
		tree = new long[1 << (height + 1)];
		for (int n = 1; n <= N; ++n) {
			numbers[n] = scanner.nextInt();
		}
		init(1, 1, N);
		for (int q = 0; q < K + M; ++q) {
			// print();
			if (scanner.nextInt() == 1) {
				update(1, 1, N, scanner.nextInt(), scanner.nextInt());
			} else {
				long sum = sum(1, 1, N, scanner.nextInt(), scanner.nextInt());
				System.out.println(sum);
			}
		}
	}
	
	public static long init(int node, int s, int e) {
		if (s == e) {
			return tree[node] = numbers[s];
		} else {
			return tree[node] = init(node * 2, s, (s + e) / 2) + init(node * 2 + 1, (s + e) / 2 + 1, e);
		}
	}
	
	public static long update(int node, int s, int e, int index, int value) {
		if (s == index && e == index) {
			return tree[node] = value;
		}
		if (s <= index && index <= e) {
			return tree[node] = update(node * 2, s, (s + e) / 2, index, value) +
					update(node * 2 + 1, (s + e) / 2 + 1, e, index, value);
		}
		return tree[node];
	}
	
	public static long sum(int node, int s, int e, int l, int r) {
		if (r < s || e < l) {
			return 0;
		}
		if (l <= s && e <= r) {
			return tree[node];
		}
		return sum(node * 2, s, (s + e) / 2, l , r) +
				sum(node * 2 + 1, (s + e) / 2 + 1, e, l, r);
	}
	
	public static void print() {
		for (long l : tree) {
			System.out.print(l + " ");
		}
		System.out.println();
	}
}
