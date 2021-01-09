import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {
	public String[] solution(String[] record) {
		Map<String, String> nicknameMap = new HashMap<>();
		
		record = Arrays.stream(record).filter(r -> {
			String[] tokens = r.split(" ");
			switch (tokens[0]) {
			case "Enter":
				nicknameMap.put(tokens[1], tokens[2]);
			case "Leave":
//			System.out.println(tokens[0] + " " + tokens[1]);
				return true;
			case "Change":
				nicknameMap.put(tokens[1], tokens[2]);
			}
			return false;
		}).toArray(String[]::new);
		
		return Arrays.stream(record).map(r -> {
			String[] tokens = r.split(" ");
//		System.out.println(tokens[1] + " is " + nicknameMap.get(tokens[1]));
			switch (tokens[0]) {
			case "Enter":
				return nicknameMap.get(tokens[1]) + "님이 들어왔습니다.";
			case "Leave":
				return nicknameMap.get(tokens[1]) + "님이 나갔습니다.";
			}
			return "";
		}).toArray(String[]::new);
	}
}
