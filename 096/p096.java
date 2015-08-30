import java.util.*;
public class p096 {
	static int n; // Length of a side
	static int nn; // Length of a side of small square
	static int[][] grid;
	static int[] rows, cols, squares; // Bitmasks of numbers free in those places
public static void main(String[] args)
{
	Scanner input = new Scanner(System.in);
	int T = 50;
	int res = 0;
	for(int t = 0; t<T; t++)
	{
		String name = input.next() + " " + input.next();
		n = 9;
		nn = (int)(Math.sqrt(n) + .5);
		grid = new int[n][n];
		rows = new int[n];
		cols = new int[n];
		squares = new int[n];
		int allBits = (1<<n) - 1;
		Arrays.fill(rows, allBits);
		Arrays.fill(cols,  allBits);
		Arrays.fill(squares,  allBits);
		for(int i = 0; i<n; i++)
		{
			String s = input.next();
			for(int j = 0; j<n; j++)
			{
				grid[i][j] = s.charAt(j) - '0';
				if(grid[i][j] != 0)
				{
					int bit = grid[i][j] - 1;
					rows[i] -= (1<<bit);
					cols[j] -= (1<<bit);
					squares[getSquare(i, j)] -= (1<<bit);
				}
			}
		}
		good(0);
//		for(int i = 0; i<n; i++)
//		{
//			for(int j = 0; j<n; j++)
//				System.out.print(grid[i][j]);
//			System.out.println();
//		}
		res += 100 * grid[0][0] + 10 * grid[0][1] + grid[0][2];
	}
	System.out.println(res);
}
static int getRow(int at)
{
	return at / n;
}
static int getCol(int at)
{
	return at%n;
}
static int getSquare(int row, int col)
{
	return (row / nn) * nn + (col / nn);
}
static boolean good(int at)
{
	if(at == n*n) return true;
	int row = at/n, col = at%n;
	if(grid[row][col] != 0) return good(at+1);
	int square = getSquare(row, col);
	int mask = rows[row] & cols[col] & squares[square];
	for(int i = 0; i<n; i++)
	{
		int shift = (1<<i);
		if((mask & shift) == 0) continue;
		rows[row] ^= shift;
		cols[col] ^= shift;
		squares[square] ^= shift;
		grid[row][col] = i+1;
		if(good(at+1)) return true;
		rows[row] ^= shift;
		cols[col] ^= shift;
		squares[square] ^= shift;
		grid[row][col] = 0;
	}
	return false;
}
}

