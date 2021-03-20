// https://leetcode.com/contest/biweekly-contest-48/problems/second-largest-digit-in-a-string/

import java.util.*;
import java.util.stream.Collectors;

class Solution {
    public int secondHighest(String s) {
        var set = new TreeSet();
        s.chars().filter(o -> Character.isDigit(o)).map(o -> o - '0').forEach(set::add);
        var list = (List<Integer>) set.stream().collect(Collectors.toList());
        return list.size() > 1 ? list.get(list.size() - 2) : -1;
    }
}
