import java.util.*;
public class Solution {
public static void main(String[] args)
{
    int n = input.nextInt();
	long res = 0;
	for(int i = 100; i < 1000; i++)
		for(int j = 100; j<1000; j++)
			if(go(i*j)) res = Math.max(res, i*j);
	System.out.println(res);
}
static boolean go(int n)
{
	String s = n+"";
	for(int i = 0; i<s.length(); i++) if(s.charAt(i) != s.charAt(s.length()-1-i)) return false;
	return true;
}
}


