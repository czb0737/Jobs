import java.util.*;

public class WordBreak {
	public boolean wordBreak(String s, Set<String> wordDict) {
		if (s == null) {
			return false;
		}
		int maxLen = 0;
		for (String word : wordDict) {
			maxLen = Math.max(maxLen, word.length());
		}
		boolean[] dp = new boolean[s.length() + 1];
		dp[0] = true;
		for (int len = 1; len <= s.length(); len++) {
			for (int i = len - 1; len - i <= maxLen && i >= 0; i--) {
				if (dp[i] && wordDict.contains(s.substring(i, len))) {
					dp[len] = true;
					break;
				}
			}
		}
		return dp[s.length()];
	}
	public static void main(String[] args) {
		
	}
}