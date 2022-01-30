#include <bits/stdc++.h>
#include <conio.h>
#include <cctype>
#include <cstring> 
#include "para.cpp"

using namespace std;


void clearscr(string str) {
	system("cls"); 
	cout << str << endl;
}

void typing(string para) {
	int i = 0, wrong = 0, correct = 0, total = para.size(), NPM = 0; 
	clearscr(para);
	while (i < para.size()) {
		char c = getch();
		if (iscntrl(c)) break;
		if (c == para[i] || c == ' ' && para[i] == '_') {
			para[i] = ' ';
			clearscr(para);
			i++, correct++;
			continue;  
		} 
		wrong++; 
	}
	NPM = ((float)correct / total) * 100; 
	cout << "correct = " << correct << " wrong = " << wrong << " total = " << total << " NPM = " << NPM << '%' << endl;
}


int options() {
	int opt; 
	cout << "Choose from \n1.Easy Text\n2.Meduim Text\n3.Difficult Text\n4.Short Text\n"; 
	cin >> opt; 
	if (opt != 1 && opt != 2 && opt != 3 && opt != 4)  return -1; 
	return opt;
}

int main(int argc, char **argv) {
	string para; 
	int opt = options(); 
	cout << opt << endl;	
	const char *paragraph; 
	srand(time(0)); 
	if (opt == 1) 
		paragraph = e_para[(rand() % 5) + 1]; 
	else if (opt == 2)
		paragraph = m_para[(rand() % 5) + 1]; 
	else if (opt == 3) 
		paragraph = d_para[(rand() % 5) + 1]; 
	else if (opt == 4)	
		paragraph = s_para[(rand() % 5) + 1];

	for (int i = 0; i < strlen(paragraph); i++) {
		if (paragraph[i] == ' ') 
			para.push_back('_');
		else 
			para.push_back(paragraph[i]); 
	}
	typing(para); 
}