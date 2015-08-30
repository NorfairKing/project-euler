import java.util.*;
public class Solution {
public static void main(String[] args)
{
	for(int i = 1; i<1000; i++)
		for(int j = 1; j<1000; j++)
		{
			int sq = i*i + j*j;
			int c = (int)(.5 + Math.sqrt(sq));
			if(Math.abs(c - Math.sqrt(sq)) < 1e-9 && i + j + c == 1000)
			{
				System.out.println(i*j*c);
				return;
			}
		}
}
}


