import java.util.*;
public class Solution {

public static void main(String[] args)
{
	Scanner input = new Scanner(System.in);
	int colors = input.nextInt(), each = input.nextInt(), days = input.nextInt();
	double[][] prob = new double[days+1][colors+1];
	prob[0][0] = 1;
	for(int day = 0; day < days; day++)
		for(int countColor = 0; countColor <= colors; countColor++)
		{
			int waysNew = each * (colors - countColor);
			int waysOld = colors * each - waysNew - day;
			if(waysOld > 0)
				prob[day+1][countColor] += prob[day][countColor] * waysOld / (waysOld + waysNew);
			if(waysNew > 0)
				prob[day+1][countColor+1] += prob[day][countColor] * waysNew / (waysOld + waysNew);
		}
	double expected = 0;
	for(int i = 0; i <= colors; i++)
		expected += prob[days][i] * i;
	System.out.printf("%.9f\n", expected);
}
}


