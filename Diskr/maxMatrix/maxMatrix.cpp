#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <climits>


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

int updateMatrix (std::vector<int> &matrix, std::vector<int> &flowM,
				  int len, std::vector<int> &path){
	int flow = matrix[path[0] * len + path[1]];
	for (unsigned i = 1; i < path.size() - 1; i++){
		flow = std::min(flow, matrix[path[i] * len + path[i + 1]]);
	}
	for (unsigned i = 0; i < path.size() - 1; i++){
		matrix[path[i] * len + path[i + 1]] -= flow;
		matrix[path[i + 1] * len + path[i]] += flow;
		if (i && i < path.size() - 2){
			flowM[path[i] * len + path[i + 1]] += flow;
		}
	}
	return flow;
}

int maxFlow (std::vector<int> &matrix, std::vector<int> &flowM,
			 int len, int start, int finish){
	int flow = 0;
	std::vector<int> newPath;
	while ((newPath = findPath(matrix, len, start, finish)).size()){
		flow += updateMatrix(matrix, flowM, len, newPath);
	}
	return flow;
}

int main(int argc, char **argv){
	std::vector<int> matrix;
	int ans;
	int res = 0;
	int n;
	int m;
	std::ifstream fin("test" + (std::string)argv[1] + ".in");
	fin >> n >> m;
	for (int i = 0; i < (n + m + 2) * (n + m + 2); i++){
		int j = i / (n + m + 2);
		int k = i % (n + m + 2);
		if (j != k && ((j > 1 && j < n + 2 && k >= n + 2) ||
					   (k > 1 && k < n + 2 && j >= n + 2))){
			matrix.push_back(INT_MAX / 2);
		}
		else{
			matrix.push_back(0);
		}
	}
	for (int i = 0; i < n; i++){
		int t;
		fin >> t;
		matrix[i + 2] = t;
	}
	for (int i = 0; i < m; i++){
		int t;
		fin >> t;
		matrix[(n + m + 2) * (i + n + 2) + 1] = t;
	}
	fin.close();
	fin.open("test" + (std::string)argv[1] + ".out");
	fin >> ans;
	fin.close();
	std::vector<int> flow ((m + n + 2) * (m + n + 2), 0);
	std::cout << "Correct answer: " << ans << std::endl;
	maxFlow(matrix, flow, m + n + 2, 0, 1);
	for (auto i : flow){
		res += i;
	}
	std::cout << "Calculated answer: " << res << std::endl;
}
