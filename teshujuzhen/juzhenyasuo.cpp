#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

bool isPrime(int num){
	if(num<2) return false;
	for(int i=2;i<=num/i;i++){
		if(num%i==0) return false;
	}
	return true;
}

void printPrimesInRange(int a, int b){
	vector<int> res;
	for(int i=a;i<=b;i++){
		if(isPrime(i)) res.push_back(i);
	}
	cout<<left;
	for(int i=0;i<res.size();i++){
		cout<<setw(5)<<res[i];
		if((i+1)%5==0) cout<<endl;
	}
	cout<<right;
}

int main(){
	int a,b; cin>>a>>b;
	printPrimesInRange(a,b);
	return 0;
}

