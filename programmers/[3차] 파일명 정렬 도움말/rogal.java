import java.util.Arrays;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Solution {
    public String[] solution(String[] files) {
        return Arrays.stream(files)
        		.sorted((arg0, arg1) -> {
        			Pattern pattern = Pattern.compile("\\d+");
        			Matcher matcher0 = pattern.matcher(arg0);
        			Matcher matcher1 = pattern.matcher(arg1);
        			matcher0.find();
        			matcher1.find();
        			int ret = arg0.substring(0, matcher0.start()).toLowerCase()
        					.compareTo(arg1.substring(0, matcher1.start()).toLowerCase());
        			if (ret != 0) {
        				return ret;
        			}
        			return Integer.compare(Integer.parseInt(matcher0.group()), Integer.parseInt(matcher1.group()));
        		})
        		.toArray(String[]::new);
    }
}
