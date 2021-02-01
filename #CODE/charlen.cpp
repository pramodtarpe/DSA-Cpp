#include<iostream>
using namespace std;

int length(char c[]){
	if(c[0] == '\0') return 0;
	else return length(c+1) + 1;
}

int main(){
	char c[100];
	cin>>c;
	cout<<length(c)<<endl;
}
