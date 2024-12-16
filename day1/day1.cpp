#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int main(){
	ifstream input("input.txt");
	string line;
	vector<int> left;
	vector<int> right;
	while (getline(input, line)){
		left.push_back(stoi(line.substr(0,5)));
		right.push_back(stoi(line.substr(8,5)));
	}
	sort(left.begin(), left.end());
	sort(right.begin(), right.end());
	int sum =0;
	for (int i=0;i<left.size();i++){
		sum +=abs(left[i]-right[i]);
	}
	cout<< sum;
}
