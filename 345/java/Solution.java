import java.util.*;
public class Solution {
	static int n;
	static int[][] data;
public static void main(String[] args)
{
	Scanner input = new Scanner(System.in);
	n = input.nextInt();
	data = new int[n][n];
	for(int i = 0; i<n; i++)
		for(int j = 0; j<n; j++)
			data[i][j] = input.nextInt();
	memo = new int[n][(1<<n)];
	for(int[] A : memo) Arrays.fill(A, -1);
	System.out.println(go(0, 0));
}
static int[][] memo;
static int go(int row, int mask)
{
	if(row == n) return 0;
	if(memo[row][mask] != -1) return memo[row][mask];
	int res = 0;
	for(int j = 0; j<n; j++)
	{
		if((mask & (1<<j)) > 0) continue;
		res = Math.max(res, data[row][j] + go(row+1, mask | (1<<j)));
	}
	return memo[row][mask] = res;
}
}


