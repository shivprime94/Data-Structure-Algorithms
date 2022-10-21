// C++ program to find count of endless points
#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;

// Returns count of endless points
int countEndless(bool input[][MAX], int n)
{
	bool row[n][n], col[n][n];

	// Fills column matrix. For every column, start
	// from every last row and fill every entry as
	// blockage after a 0 is found.
	for (int j=0; j<n; j++)
	{
		// flag which will be zero once we get a '0'
		// and it will be 1 otherwise
		bool isEndless = 1;
		for (int i=n-1; i>=0; i--)
		{
			// encountered a '0', set the isEndless
			// variable to false
			if (input[i][j] == 0)
				isEndless = 0;
			col[i][j] = isEndless;
		}
	}

	// Similarly, fill row matrix
	for (int i=0; i<n; i++)
	{
		bool isEndless = 1;
		for (int j= n-1; j>=0; j--)
		{
			if (input[i][j] == 0)
				isEndless = 0;
			row[i][j] = isEndless;
		}
	}

	// Calculate total count of endless points
	int ans = 0;
	for (int i=0; i<n; i++)
		for (int j=1; j<n; j++)

			// If there is NO blockage in row
			// or column after this point,
			// increment result.
			if (row[i][j] && col[i][j])
				ans++;

	return ans;
}

// Driver code
int main()
{
	bool input[][MAX] = { {1, 0, 1, 1},
						{0, 1, 1, 1},
						{1, 1, 1, 1},
						{0, 1, 1, 0}};
	int n = 4;

	cout << countEndless(input, n);
	return 0;
}
