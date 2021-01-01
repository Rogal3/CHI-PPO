import java.util.Arrays;
import java.util.Comparator;

class Solution {
	class Comp implements Comparator<String> {
		@Override
		public int compare(String arg0, String arg1) {
			int[] numberRangeOfArg0 = findRangeOfNumber(arg0);
			arg0 = arg0.substring(0, numberRangeOfArg0[0]);
			int[] numberRangeOfArg1 = findRangeOfNumber(arg1);
			arg1 = arg1.substring(0, numberRangeOfArg1[0]);
			arg0 = arg0.toLowerCase();
			arg1 = arg1.toLowerCase();
			int ret = arg0.compareTo(arg1);
			if (ret != 0) {
				return ret;
			}
			return Integer.compare(numberRangeOfArg0[2], numberRangeOfArg1[2]);
		}
	}
	
    public String[] solution(String[] files) {
        sort(files);
        return files;
    }
    
    // @RETURN array of integer as { begin, end, valueOfNumber }
    public int[] findRangeOfNumber(String str) {
    	int[] ret = new int[3];
    	int i = 0;
    	int sum = 0;
    	for (; i < str.length(); ++i) {
    		char c = str.charAt(i);
    		if (Character.isDigit(c)) {
    			ret[0] = i;
    			break;
    		}
    	}
    	for (; i < str.length(); ++i) {
    		char c = str.charAt(i);
    		if (Character.isDigit(c)) {
    			int digit = Character.getNumericValue(c);
    			sum = sum * 10 + digit;
    		} else {
    			break;
    		}
    	}
		ret[1] = i;
		ret[2] = sum;
    	return ret;
    }
    
    public String[] sort(String[] array) {
    	Comp comp = new Comp();
    	Arrays.sort(array, comp);
    	return array;
    }
}
