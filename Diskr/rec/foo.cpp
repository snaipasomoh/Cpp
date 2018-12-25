#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

std::vector<long long> mMultiply (std::vector<long long> const &a, long a_r,
								  std::vector<long long> const &b, long b_r,
								  long long p = LONG_LONG_MAX){
	long a_c = a.size() / a_r;
	long b_c = b.size() / b_r;
	std::vector<long long> newMatrix(a_r * b_c, 0);
	for (long i = 0; i < a_r; i++){
		for (long j = 0; j < b_c; j++){
			for (long k = 0; k < a_c; k++){
				newMatrix[i * b_c + j] = (newMatrix[i * b_c + j] +
									((a[i * a_c + k] % p) *
									(b[k * b_c + j]) % p) % p) % p;
			}
		}
	}
	return newMatrix;
}

std::vector<long long> mFastPow (std::vector<long long> &matrix,
								 long long n, long long p){
	std::vector<long long> res(matrix.size(), 0);
	long m = sqrt(matrix.size());
	for (long i = 0; i < m; i++){
		res[i * m + i] = 1;
	}

	while (n){
		if (n & 1){
			res = mMultiply(res, m, matrix, m, p);
		}
		matrix = mMultiply(matrix, m, matrix, m, p);
		n >>= 1;
	}

	return res;
}

int main (int argc, char **argv){
	std::vector<long long> start = {0, 1};
	long long k, p;
	long a, b;
	std::cin >> a >> b >> k >> p;
	std::vector<long long> matrix = {0, a, 1, b}; //0, a, 1, b
	std::cout << mMultiply(start, 1, mFastPow(matrix, k, p), 2)[0] << std::endl;
	// std::cout << sizeof(long long) << std::endl;
}
//a        b        k                p             res
//2        3        787              3571          2988
//17       11       32776            1073676287    261002334
//23       31       7687688          274876858367
//2        2        47286            4398042316799
//17357643 18368713 540543250032147 29384578903
