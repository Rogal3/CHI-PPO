import java.util.*;
import java.util.stream.Stream;

class Solution {
	public String[] solution(String[] record) {
		HashMap<String, String> nicknameMap = new HashMap<>();
		Stream.of(record)
			.filter(r -> r.startsWith("Enter") || r.startsWith("Change"))
			.forEach(r -> nicknameMap.put(r.split(" ")[1], r.split(" ")[2]));
		return Stream.of(record)
			.filter(r -> r.startsWith("Enter") || r.startsWith("Leave"))
			.map(r -> nicknameMap.get(r.split(" ")[1]) + (r.split(" ")[0].equals("Enter") ? "님이 들어왔습니다." : "님이 나갔습니다."))
			.toArray(String[]::new);
	}
}
