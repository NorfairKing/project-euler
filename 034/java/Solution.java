import java.util.*;
public class Solution {
public static void main(String[] args)
{
	long res = 0;
	for(int i = 10; i<10000000; i++) if(i == go(i)) res += i;
	System.out.println(res);
}
static boolean[] sieve;
static int[] facts = new int[]{1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
static int go(int n)
{
	int res = 0;
	while(n > 0)
	{
		res += facts[n%10];
		n /= 10;
	}
	return res;
}
}


