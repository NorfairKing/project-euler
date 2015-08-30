import java.util.*;
public class Solution {
public static void main(String[] args)
{
	Scanner input = new Scanner(System.in);
	int x = input.nextInt();
	for(int i = 1; i<100000; i++)
	{
		long cur = i*(i+1)/2;
		int count = 0;
		for(int j = 1; j*j<=cur; j++)
		{
			if(cur%j == 0) count+= (j*j == cur ? 1 : 2);
		}
		if(count > x)
		{
			System.out.println(cur);
			return;
		}
	}
}
}


