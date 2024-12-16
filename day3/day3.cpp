#include <iostream>
#include <sstream>
#include <fstream>
#include <regex>
using namespace std;
int main(){
	ifstream input("input.txt");
	stringstream buffer;
	buffer<<input.rdbuf();
	string inp=buffer.str();
	regex pattern("mul\\((\\d{1,3}),(\\d{1,3})\\)");
	smatch mathes;
	int sum=0;
	string::const_iterator searchStart( inp.cbegin() );	
	while(regex_search(searchStart,inp.cend(),mathes,pattern)){
		sum+= stoi(mathes[1])*stoi(mathes[2]);
		searchStart = mathes.suffix().first;
}
cout<<sum;
}
