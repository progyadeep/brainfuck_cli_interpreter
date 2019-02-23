#include <iostream>
using namespace std;

#include "preprocess.h"

signed char arr[30000];
int ptr;

void process(string);

int main(){
	string inpMain = "";
	ptr = 0;
	cout << "*** ";
	cin >> inpMain;
	while(inpMain[0] != '#'){
		inpMain = preprocess(inpMain);
		//checking for fucked up input:
		if(inpMain != "IT")
			process(inpMain);

		//on to next cycle:	
		cout << "\n*** ";
		cin >> inpMain;
	}
}

void process(string inp){
	for(int i=0; i<inp.length(); i++){
		switch(inp[i]){
			case '[':
				int e,c;
				e = i+1; c=0;
				while(inp[e] != ']' || c!=0){
					if(inp[e] == '[')
						c++;
					else if(inp[e] == ']')
						c--;
					e++;
				}
				while(arr[ptr] != 0){
					process(inp.substr(i+1, e-i-1));
				}
				i=e;
			break;
			case '+':
				arr[ptr]++;
			break;
			case '-':
				arr[ptr]--;
			break;
			case '>':
				ptr++;
			break;
			case '<':
				ptr--;
			break;
			case '.':
				cout << arr[ptr];
			break;
			case ',':
        		signed char tmp;
         		cin >> tmp;
				arr[ptr] = (signed char)tmp;
			break;
			case '$':
				ptr=0;
				for(int a=0; a<30000; a++)
					arr[a] = (signed char)0;
			break;
			default:
				cout << "IDK What to do now\n";
				//exit(0);
		}
	}
}
