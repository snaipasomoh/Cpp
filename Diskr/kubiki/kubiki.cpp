#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

bool findChain (std::vector<int> const &matrix, std::vector<int> &parents,
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
	std::string target;
	std::string ans;
	int count = 0;
	std::ifstream fin ("test" + (std::string)argv[1] + ".in");
	fin >> n >> target;
	m = target.size();
	std::vector<int> matrix (n * m, 0);
	std::vector<int> parents (n, -1);
	std::vector<bool> used;

	for (int i = 0; i < n; i++){
		std::string temp;
		fin >> temp;
		for (int j = 0; j < m; j++){
			if (std::find(temp.begin(), temp.end(), target[j]) != temp.end()){
				matrix[j * n + i] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++){
		used.assign(m, false);
		findChain(matrix, parents, used, i, n);
	}

	for (int i = 0; i < n; i++){
		if (parents[i] != -1){
			count++;
		}
	}
	fin.close();
	fin.open("test" + (std::string)argv[1] + ".out");
	fin >> ans;
	fin.close();
	std::cout << "Correct answer: " << ans << std::endl;
	std::cout << "Calculated answer: "
			  << (count == (int)target.size() ? "YES" : "NO") << std::endl;

}