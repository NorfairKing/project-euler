import java.util.*;
public class Solution {
public static void main(String[] args)
{
	Scanner input = new Scanner(System.in);
	int n = input.nextInt();
	boolean[] sieve = new boolean[n+1];
	Arrays.fill(sieve,  true);
	sieve[0] = sieve[1] = false;
	long res = 0;
	for(int i = 2; i<=n; i++)
	{
		if(sieve[i])
		{
			res += i;
			for(long j = (long)i*i; j <= n; j += i) sieve[(int)j] = false;
		}
	}
	System.out.println(res);
}
}


