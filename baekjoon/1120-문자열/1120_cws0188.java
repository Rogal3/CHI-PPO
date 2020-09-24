import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String a = scanner.next();
		String b = scanner.next();
		int maxOfMatchings = 0;
		for (int start = 0; start <= b.length() - a.length(); ++start) {
			maxOfMatchings = Math.max(maxOfMatchings, compareString(a, b.substring(start)));
		}
		System.out.println(a.length() - maxOfMatchings);
	}
	
	public static int compareString(String lsh, String rsh) {
		int countOfMatchings = 0;
		for (int i = 0; i < lsh.length(); ++i) {
			if (lsh.charAt(i) == rsh.charAt(i)) {
				++countOfMatchings;
			}
		}
		return countOfMatchings;
	}
}
