#include <iostream>
#include <vector>
#include <queue>
#include <fstream>


std::vector<int> findPath (std::vector<int> &matrix, int len,
						   int start, int finish){
	std::vector<int> path;
	std::vector<int> parents (len, -1);
	parents[start] = start;
	std::queue<int> queue;
	queue.push(start);
	bool flag = 0;
	while(queue.size()){
		int currVert = queue.front();
		queue.pop();
		for (int i = 0; i < len; i++){
			if (parents[i] == -1 && matrix[currVert * len + i]){
				parents[i] = currVert;
				queue.push(i);
			}
			if (i == finish && matrix[currVert * len + i]){
				flag = 1;
				break;
			}
		}
		if (flag){
			break;
		}
	}
	if (parents[finish] == -1){
		return path;
	}
	int currVert = finish;
	while (currVert != start){
		path.insert(path.begin(), currVert);
		currVert = parents[currVert];
	}
	path.insert(path.begin(), currVert);
	return path;
}

int updateMatrix (std::vector<int> &matrix, int len, std::vector<int> &path){
	int flow = matrix[path[0] * len + path[1]];
	for (unsigned i = 1; i < path.size() - 1; i++){
		flow = std::min(flow, matrix[path[i] * len + path[i + 1]]);
	}
	for (unsigned i = 0; i < path.size() - 1; i++){
		matrix[path[i] * len + path[i + 1]] -= flow;
		matrix[path[i + 1] * len + path[i]] += flow;
	}
	return flow;
}

int maxFlow (std::vector<int> &matrix,int len, int start, int finish){
	int flow = 0;
	std::vector<int> newPath;
	while ((newPath = findPath(matrix, len, start, finish)).size()){
		flow += updateMatrix(matrix, len, newPath);
	}
	return flow;
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
	std::cout << "Calculated answer: " << maxFlow(matrix, size,  0, 1)
			  << std::endl;
}
