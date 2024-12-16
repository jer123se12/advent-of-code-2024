#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int main(){
	ifstream input("input.txt");
	int safe=0;
	string line;
	while (getline(input,line)){
		vector<int> num;
		string number;
		for (int i=0;i<line.length();i++){
			if (line[i]!=' '){
				number+=line[i];
			}else{
				num.push_back(stoi(number));	
				number="";
			}
		}
		num.push_back(stoi(number));	
		number="";
		bool pass=true;
		bool remove=false;
		int prev=num[0];
		int rmloc;
		int asc=0, dsc=0;
		bool isAcending = num[0]<num[1];
		for (int i=1;i<num.size();i++){
			asc+=num[i-1]<num[i];
			dsc+=num[i-1]>num[i];
		}
		if (asc>2||dsc>2){cout<<asc<<' '<<dsc<<endl;}
		isAcending=asc>=dsc;
		for (int i=1;i<num.size();i++){
			if (remove){
				if (i-1==rmloc){prev=num[i-2];}else{prev=num[i-1];}
			}
			int diff=abs(num[i-1]-num[i]);
			if (num[i-1]==num[i] || (num[i-1]<num[i])!=isAcending){
				if (!remove){remove=true; rmloc=i; continue;}else{
				pass=false;
				break;}
			}
			else if (diff<1 || diff >3){
				if (!remove){remove=true; rmloc=i; continue;}else{
				pass=false;
				break;}
			}
		}
		if (pass){safe++;};
	}
	cout<<safe;	

}
