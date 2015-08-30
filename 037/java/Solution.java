import java.util.*;
public class Solution {
public static void main(String[] args)
{
	sieve = new boolean[10000000];
	Arrays.fill(sieve,  true);
	sieve[1] = false;
	for(int i = 2; i<sieve.length; i++)
	{
		if(sieve[i])
		{
			for(long j = (long)i*i; j < sieve.length; j += i) sieve[(int)j] = false;
		}
	}
	int sum = 0;
	for(int i = 10; i < 1000000; i++) if(isGood(i)) sum += i;
	System.out.println(sum);
}
static boolean[] sieve;
static int[] tenpows = new int[]{1, 10, 100, 1000, 10000, 100000, 1000000};
static boolean isGood(int n)
{
	if(!sieve[n]) return false;
	int len = (n+"").length();
	for(int i = 0; i<len; i++)
	{
		if(!sieve[n/tenpows[i]] || !sieve[n%tenpows[i]]) return false;
	}
	return true;
}
}


