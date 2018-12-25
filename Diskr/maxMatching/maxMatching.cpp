#include <iostream>
#include <vector>
#include <fstream>

bool findChain (std::vector<int> &matrix, std::vector<int> &parents,
				std::vector<bool> &used, int start, int len){
	if (used[start]){
		return false;
	}
	used[start] = true;
	for (int i = 0; i < len; i++){
		if (matrix[start * len + i] && (parents[i] == -1 ||
		   findChain(matrix, parents, used, parents[i], len))){
			parents[i] = start;
			return true;
		}
	}
	return false;
}

int main (int argc, char **argv){
	int n;
	int m;
	int count = 0;
	std::ifstream fin ("test" + (std::string)argv[1] + ".in");
	fin >> n >> m;
	std::vector<int> matrix (n * m, 0);
	std::vector<int> parents (m, -1);
	std::vector<bool> used;

	for (int i = 0; i < n; i++){
		int j;
		fin >> j;
		for (int k = 0; k < j; k++){
			int p;
			fin >> p;
			matrix[i * m + p] = 1;
		}
	}

	for (int i = 0; i < n; i++){
		used.assign(n, false);
		findChain(matrix, parents, used, i, m);
	}

	for (int i = 0; i < m; i++){
		if (parents[i] != -1){
			count++;
		}
	}
	fin.close();
	fin.open("test" + (std::string)argv[1] + ".out");
	int t;
	fin >> t;
	fin.close();
	std::cout << "Correct answer: " << t << std::endl;
	std::cout << "Calculated answer: " << count << std::endl;
}
