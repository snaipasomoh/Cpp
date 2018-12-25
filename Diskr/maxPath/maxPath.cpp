#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <climits>

int findMax (std::vector<int> const &vertMaxPath,
			 std::vector<bool> const &visited){
	int min = -1;
	int i = 0;
	for (size_t j = 0; j < visited.size(); j++){
		if (vertMaxPath[j] > min && !visited[j]){
			min = vertMaxPath[j];
			i = j;
		}
	}
	return i;
}

int maxPath (std::vector<int> const &matrix, int size, int start, int finish){
	std::vector<int> vertMaxPath (size, 0);
	std::vector<bool> visited (size, 0);
	vertMaxPath[start] = INT_MAX;
	visited[start] = 1;
	for (int i = 0; i < size; i++){
		if (!visited[i]){
			vertMaxPath[i] = std::max(vertMaxPath[i],
			std::min(vertMaxPath[start], matrix[start * size + i]));
		}
	}
	while (std::find(visited.begin(), visited.end(), 0) != visited.end()){
		int currVert = findMax(vertMaxPath, visited);
		visited[currVert] = 1;
		for (int i = 0; i < size; i++){
			if (!visited[i]){
				vertMaxPath[i] = std::max(vertMaxPath[i],
				std::min(vertMaxPath[currVert], matrix[currVert * size + i]));
			}
		}
	}
	return vertMaxPath[finish];
}

int main(int argc, char **argv){
	std::vector<int> matrix;
	int size;
	int ans;
	int n;
	std::ifstream fin("test" + (std::string)argv[1] + ".in");
	fin >> size;
	while (fin >> n){
		matrix.push_back(n);
	}
	fin.close();
	fin.open("test" + (std::string)argv[1] + ".out");
	fin >> ans;
	fin.close();
	std::cout << "Correct answer: " << ans << std::endl;
	std::cout << "Calculated answer: " << maxPath(matrix, size,  0, 1)
			  << std::endl;
}