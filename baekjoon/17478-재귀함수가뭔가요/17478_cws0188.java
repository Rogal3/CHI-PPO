import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		String str = "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.";
		System.out.println(str);
		recur(0, N);
	}
	
	public static void recur(int i, int N) {
		final String start = "\"재귀함수가 뭔가요?\"";
		final String[] mid = 
			{"\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.",
				"마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.",
				"그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\""};
		final String match = "\"재귀함수는 자기 자신을 호출하는 함수라네\"";
		final String end = "라고 답변하였지.";
		
		printlnWithIndentation(start, i);
		if (i < N) {
			for (String str : mid) {
				printlnWithIndentation(str, i);
			}
			recur(i + 1, N);
		}
		else {
			printlnWithIndentation(match, i);
		}
		printlnWithIndentation(end, i);
	}
	
	public static void printlnWithIndentation(String str, int n) {
		final String ind = "____";
		for (int i = 0; i < n; ++i) {
			System.out.print(ind);
		}
		System.out.println(str);
	}
}
