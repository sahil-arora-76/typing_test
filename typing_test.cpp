#include <bits/stdc++.h>
#include <conio.h>
#include <cctype>
#include <ctime>
#include "para.cpp"

using namespace std;

#define isctrl(a) (a == 3 ? true : false)

bool train = false; 

typedef struct ttime {
	int minutes; 
	int seconds;
} ttime; 

string format(string str) {
	string para; 
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ') 
			para.push_back('_');
		else 
			para.push_back(str[i]); 
	}
	return para; 
}

void clearscr(string str) {
	system("cls"); 
	cout << str << endl;
}

ttime get_ttime() {
	std::time_t tt = std::time(0); 
	std::tm *now = std::localtime(&tt);
	ttime t; 
	t.seconds = now->tm_sec; 
	t.minutes = now->tm_min;  
	return t; 
}

ttime get_typing_ttime(ttime *st, ttime *et) {
	ttime t; 
	if (st->minutes == et->minutes) {
		t.minutes = 0; 
		t.seconds = et->seconds - st->seconds; 
	} else  {
		t.minutes = 0; 
		int seconds = (et->minutes - st->minutes) * 60;
		seconds -=  st->seconds;
		seconds += et->seconds; 
		t.seconds = seconds; 
	}
	return t; 
}

void typing(string para) {
	int i = 0, wrong = 0, correct = 0, total = para.size(), WPM = 0, seconds = 0, minutes = 0, j = 0;
	ttime st, et, tt;  
	clearscr(para);
	st = get_ttime(); 
	et = get_ttime(); 
	tt = get_typing_ttime(&st, &et); 
	while ((i < para.size() && train) || (tt.seconds < 60 && !train)) {
		if (!train && para.size() - j <= 14) {
			string temp = m_para[(rand() % 5) + 1]; 
			para.append("_");
			para.append(format(temp)); 
			total += temp.size();
			total++;  
		} 
		char c = getch();
		et = get_ttime(); 
		tt = get_typing_ttime(&st, &et); 	
		if (isctrl(c))  break;
		if (c == para[i] || c == ' ' && para[i] == '_') {
			para[i] = ' ';
			clearscr(para);
			i++, correct++, j++;
			continue;  
		} 
		wrong++, j++;
	}
	if (train) {
		cout << "time taken to finish is = " << tt.seconds << "sec" << endl;   
		cout << "correct characters typed = " << correct << " wrong characters typed = " << wrong <<  endl;
	} else {
		WPM = correct / 5; 
		cout << "correct character typed = " << correct << " wrong character typed = " << wrong  << " WPM = " << WPM << '%' <<  endl;
	}
}


void e_key(string para) {
	clearscr(para);
	cout << "\n\n\n\nPress ENTER key to continue\nNOTE -: insert space insert of _" << endl;  
	char c = getche();
	while (c != '\n') { c = getchar(); };  
	clearscr(para);
	typing(para);
}

int options() {
	int opt;
	string str; 
	if (train)  
		str = "Traning mode -: on \nChoose from \n1.Easy Text\n2.Meduim Text\n3.Difficult Text\n"; 
	else
		str = "Choose from \n1.Easy Text\n2.Meduim Text\n3.Difficult Text\n"; 
	clearscr(str);
	cin >> opt; 
	if (opt != 1 && opt != 2 && opt != 3)  return -1; 
	return opt;
}



int main(int argc, char **argv) {
	if (argc >= 2 && strcmp(argv[1],"--train") == 0) {
		train = true; 
	}
	string para; 
	int opt = options(); 
	string paragraph;
	srand(time(0)); 
	if (opt == 1) 
		paragraph = e_para[(rand() % 5) + 1]; 
	else if (opt == 2)
		paragraph = m_para[(rand() % 5) + 1]; 
	else if (opt == 3) 
		paragraph = d_para[(rand() % 5) + 1]; 
	para = format(paragraph); 

	e_key(para);
}	