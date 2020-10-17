#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

union Cell{
    signed char c;
};

union Cell *ptr;
union Cell *start;

void process (string);
string getInput (void);

int main (){
    ptr = (union Cell *) calloc (30000, sizeof (union Cell));
    start = ptr;
    string inpMain = getInput ();
    
    while (inpMain != "#"){
        if (inpMain != "!" && inpMain != "")
	        process (inpMain);

        //on to next cycle:
        inpMain = getInput ();
    }

    free (start);
    return 0;
}

string getInput (){
    cout << "\n*** ";
    string str = "";
    char ch;
    long int index = 0l;
    while ((ch = getchar ()) != '\n'){
        if (ch != ' '){
	        if (ch == '.' || ch == ',' || ch == '+' || ch == '-' || ch == '<'|| ch == '>' || ch == '[' || ch == ']'){
	            str += ch;
	        }
	        else if (ch == '#'){
	            str="#";
	            break;
	        }
	        else if(ch == '$'){
	            str="$";
	            break;
	        }
	        else{
	            cout << "Invalid token \"" << ch << "\" at index: " << index;
	            str = "!";
	            getchar(); //swallowing the '\n'
	            break;
	        }
	        index++;
	    }
    }

    return str;
}

void process (string inp){
    for (int i = 0; i < inp.length (); i++){
        switch (inp[i]){
	        case '[':
	            int e, c;
	            e = i + 1;
	            c = 0;
	            while (inp[e] != ']' || c != 0){
	                if (inp[e] == '[')
		                c++;
	                else if (inp[e] == ']')
		                c--;
	                e++;
	            }
	            while (ptr->c != 0){
	                process (inp.substr (i + 1, e - i - 1));
	            }
	            i = e;
	        break;
	        case '+':
	            ptr->c++;
	        break;
	        case '-':
	            ptr->c--;
	        break;
	        case '>':
	            ptr++;
	        break;
	        case '<':
	            ptr--;
	        break;
	        case '.':
	            cout << ptr->c;
	        break;
	        case ',':
	            ptr->c = (signed char) getchar();
	            getchar(); //swallowing the '\n'
	        break;
	        default:
	            free (start);
	            ptr = (union Cell *) calloc (30000, sizeof (union Cell));
	            start = ptr;
	            getchar(); //swallowing the '\n'
        }
    }
}
