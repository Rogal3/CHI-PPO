/*

6 2000000000
1000000000 1000000000 1000000000 1000000000 1000000000 1000000000


666666666

*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static int N;
	static int M;
	static int[] trees;
	static int[] subs;
	static int height;
	
	public static void main(String[] args) throws IOException{
		readInput();
		Arrays.sort(trees);
		makeSubs();
		findHeight();
		System.out.println(height);
	}
	
	public static void readInput() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		trees = new int[N];
		st = new StringTokenizer(br.readLine());
		for (int n = 0; n < N; ++n) {
			trees[n] = Integer.parseInt(st.nextToken());
		}
	}
	
	public static void makeSubs() {
		subs = new int[N];
		subs[0] = trees[0];
		for (int i = 1; i < N; ++i) {
			subs[i] = trees[i] - trees[i - 1];
		}
	}
	
	public static void findHeight() {
		long sum = 0;
		for (int i = N - 1; 0 <= i; --i) {
			sum += (long)subs[i] * (N - i);
			if (M <= sum) {
				height = (int) ((0 < i ? trees[i - 1] : 0) + (sum - M) / (N - i));
				return;
			}
		}
	}
}
