// https://leetcode.com/contest/biweekly-contest-48/problems/design-authentication-manager/

import java.util.HashMap;
import java.util.Map;
import java.util.Optional;

class AuthenticationManager {
    private final int timeTolive;
    Map<String, int[]> tokenById;

    public AuthenticationManager(int timeToLive) {
        this.timeTolive = timeToLive;
        this.tokenById = new HashMap();
    }

    public void generate(String tokenId, int currentTime) {
        tokenById.put(
                tokenId,
                new int[] {currentTime, currentTime + timeTolive}
        );
    }

    public void renew(String tokenId, int currentTime) {
        Optional.ofNullable(tokenById.get(tokenId))
                .ifPresent(o -> o[1] = currentTime < o[1] ? currentTime + timeTolive : o[1]);
    }

    public int countUnexpiredTokens(int currentTime) {
        return (int) tokenById.entrySet().stream()
                .filter(o -> o.getValue()[0] <= currentTime && currentTime < o.getValue()[1])
                .count();
    }
}

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager obj = new AuthenticationManager(timeToLive);
 * obj.generate(tokenId,currentTime);
 * obj.renew(tokenId,currentTime);
 * int param_3 = obj.countUnexpiredTokens(currentTime);
 */
