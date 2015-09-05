package projecteuler;

public class Palindrome {
  public static boolean isPalindrome(int n) {
    String s = Integer.toString(n);
    for(int i = 0; i < s.length(); i++) {
      if(s.charAt(i) != s.charAt(s.length() - 1 - i)) {
        return false;
      }
    }
    return true;
  }
}
