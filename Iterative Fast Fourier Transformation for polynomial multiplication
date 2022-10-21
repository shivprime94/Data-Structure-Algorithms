// CPP program to implement iterative
// fast Fourier transform.
#include <bits/stdc++.h>
using namespace std;

typedef complex<double> cd;
const double PI = 3.1415926536;

// Utility function for reversing the bits
// of given index x
unsigned int bitReverse(unsigned int x, int log2n)
{
	int n = 0;
	for (int i = 0; i < log2n; i++)
	{
		n <<= 1;
		n |= (x & 1);
		x >>= 1;
	}
	return n;
}

// Iterative FFT function to compute the DFT
// of given coefficient vector
void fft(vector<cd>& a, vector<cd>& A, int log2n)
{
	int n = 4;

	// bit reversal of the given array
	for (unsigned int i = 0; i < n; ++i) {
		int rev = bitReverse(i, log2n);
		A[i] = a[rev];
	}

	// j is iota
	const complex<double> J(0, 1);
	for (int s = 1; s <= log2n; ++s) {
		int m = 1 << s; // 2 power s
		int m2 = m >> 1; // m2 = m/2 -1
		cd w(1, 0);

		// principle root of nth complex
		// root of unity.
		cd wm = exp(J * (PI / m2));
		for (int j = 0; j < m2; ++j) {
			for (int k = j; k < n; k += m) {

				// t = twiddle factor
				cd t = w * A[k + m2];
				cd u = A[k];

				// similar calculating y[k]
				A[k] = u + t;

				// similar calculating y[k+n/2]
				A[k + m2] = u - t;
			}
			w *= wm;
		}
	}
}

int main()
{
	vector<cd> a{ 1, 2, 3, 4 };
	vector<cd> A(4);
	fft(a, A, 2);
	for (int i = 0; i < 4; ++i)
		cout << A[i] << "\n";
}
