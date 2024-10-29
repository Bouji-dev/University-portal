#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;
vector<pair<string, string>>v;
vector<pair<string, string>>mark;
vector<pair<string, pair<string, string>>>maj;
vector<string>code;

int id = 1000;

struct date {
	int d;
	int m;
	int y;
};
class person {
public:
	string fname;
	string lname;
	string fadname;
	bool sex;
	bool marriage;
	int NID;
	date TT;
	void print() {
		cout << "National ID is : " << NID << endl;
		cout << "Name is : " << fname << endl;
		cout << "Last Name is : " <<  lname << endl;
		cout << "Father Name is : " << fadname << endl;
		if(sex==1)
		cout << "Sex is Female" << endl;
		else
			cout << "Sex is Male" << endl;
		if (marriage == 1)
			cout << "Married" << endl;
		else
			cout << "Single" << endl;
		cout << "Birth date is : " << TT.y <<"/" 
			<< TT.m << "/" << TT.d << endl;

	}
};
class major {
public:
	string name;
	int cap;
	int RID;
	void print() {
		cout << "major ID : " << RID << endl;
		cout << "major name : " << name << endl;
		cout << "major Capacity : " << cap << endl;
	}
	void set() {
		fstream fresh;
		fresh.open("major.txt",ios::app);
		fresh << endl;
		cout << "Enter Major name : " << endl;
		string s,ss;
		cin >> s;
		name = s;
		fresh << s << endl;
		RID = id;
		fresh << id << endl;
		id++;
		cout << "Enter Major capacity : " << endl;
		cin >> ss;
		fresh << ss << endl;
		cap = stoi(ss);
		maj.push_back(make_pair(s, make_pair(to_string(RID), ss)));
		
	}
};
class co {
public:
	string name;
	string majorname;
	int maxcap;
	int cap;
	bool tafkik;
	string h1, m1;
	int vahed;
	string h2, m2;
	string day1;
	string day2;
	string master;
	void print() {
		cout << "Master name is : " << master << endl;
		cout << "Code name : " << name << endl;
		cout << "Major name : " << majorname << endl;
		cout << "Max capacity : " << name << endl;
		cout << "capacity : " << name << endl;
		if (tafkik)cout << "Class will be Gender segregation." << endl;
		else cout << "Class will be NOT Gender segregation. "<< endl;
		if (vahed == 2) {
			cout << "The day of code is : " << day1
				<< "in hour : " << h1 << ":" << m1 << endl;
		}
		else {
			cout << "The day of code is : " << day1
				<< " hour : " << h1 << ":" << m1 << endl;
			cout<< "and "<< day2 << " hour : " << h2 
				<< ":" << m2 << endl;
		}
		



	}
};
void addp(string s) {
	string nid;
	nid = s;
	fstream fper;
	string ss = ".txt";
	s = s + ss;
	fper.open(s, ios::out);
	cout << "Enter your First Name : ";
	cin >> s;
	fper << s << endl;
	cout << "Enter your Last Name : ";
	cin >> s;
	fper << s << endl;
	cout << "Enter your Father Name : ";
	cin >> s;
	fper << s << endl;
	cout << "Enter your Gender : \n";
	cout << " 0 : Male." << endl;
	cout << " 1 : Female . " << endl;
	cin >> s;
	fper << s << endl;
	cout << "Enter your Marriage : \n";
	cout << " 0 : Single." << endl;
	cout << " 1 : Married . " << endl;
	cin >> s;
	fper << s << endl;
	cout << "Enter your Birth-date(day) : ";
	cin >> s;
	fper << s << endl;
	cout << "Enter your Birth-date(month) : ";
	cin >> s;
	fper << s << endl;
	cout << "Enter your Birth-date(year) : ";
	cin >> s;
	fper << s << endl;
	int a;
	cout << "Enter your Position : \n";
	cout << " 1 : Student." << endl;
	cout << " 2 : Master . " << endl;
	while (1) {
		cin >> a;
		if (a == 1) {
			string s = "3";
			nid = s + nid;
			break;

		}
		else if (a == 2) {
			string s = "2";
			nid = s + nid;
			break;
		}
		else {
			cout << " Error , Enter your position again.\n";
			cout << " 1 : Student." << endl;
			cout << " 2 : Master . " << endl;
		}
	}
	fper.close();
	fper.open("pass.txt", ios::app);
	fper << nid << endl;
	string temp;
	int sw = 0;
	for (int i = nid.length() - 1; i > 0; i--) {
		sw++;
		if (sw == 5)break;
		temp += nid[i];
	}
	fper << temp << endl;
	v.push_back(make_pair(nid, temp));
	fper.close();
}
void addc(string s) {
	string coden;
	coden = s;
	fstream fper;
	string ss = ".txt";
	s = s + ss;
	fper.open(s, ios::out);
	fper << 0 << endl;
	cout << "Enter Major Name : ";
	cin >> s;
	fper << s << endl;
	cout << "Enter Max capacity : ";
	cin >> s;
	fper << s << endl;
	cout << "Enter capacity : ";
	cin >> s;
	fper << s << endl;
	cout << "Enter Gender segregation : \n";
	cout << " 0 : Not Gender segregation ." << endl;
	cout << " 1 : Gender segregation" << endl;
	cin >> s;
	fper << s << endl;
	cout << "Enter vahed : \n";
	cin >> s;
	fper << s << endl;
	if (s == "2") {
		cout << "Enter hour : \n";
		cin >> s;
		fper << s << endl;
		cout << "Enter minute : \n";
		cin >> s;
		fper << s << endl;
		fper << 0 << endl;
		fper << 0 << endl;
		cout << "Enter day : \n";
		cin >> s;
		fper << s << endl;
		fper << 0 << endl;
	}
	else {
		cout << "Enter hour 1 : \n";
		cin >> s;
		fper << s << endl;
		cout << "Enter minute 1 : \n";
		cin >> s;
		fper << s << endl;
		cout << "Enter hour 2 : \n";
		cin >> s;
		fper << s << endl;
		cout << "Enter minute 2 : \n";
		cin >> s;
		fper << s << endl;
		cout << "Enter day 1 : \n";
		cin >> s;
		fper << s << endl;
		cout << "Enter day 2 : \n";
		cin >> s;
		fper << s << endl;
	}
	fper.close();
	fper.open("code.txt", ios::app);
	fper << coden << endl;
	fper.close();
	code.push_back(coden);
}

int main() {
	system("Color 0B");
	srand(time(0));
	fstream fpass,fresh,fcode;
	fpass.open("pass.txt", ios::in);
	while (!fpass.eof()) {
		string s, ss;
		fpass >> s;
		fpass >> ss;
		v.push_back(make_pair(s, ss));
	}
	fresh.open("major.txt", ios::in);
	while (!fresh.eof()) {
		string s, ss, sss;
		fresh >> s;
		fresh >> ss;
		fresh >> sss;
		maj.push_back(make_pair(s, make_pair(ss, sss)));
	}
	fcode.open("code.txt", ios::in);
	while (!fcode.eof()) {
		string s;
		fcode >> s;
		code.push_back(s);
	}
	fpass.close();
	fresh.close();
	fcode.close();
	while (1) {
		int check = 0;
		string user, pass;
		cout << "Enter username : " << endl;
		cin >> user;
		cout << "Entet password : " << endl;
		cin >> pass;
		for (int i = 0; i < v.size(); i++) {
			if (user == v[i].first) {
				if (pass == v[i].second) {
					if (v[i].first[0] == '1') check = 1;
					if (v[i].first[0] == '2') check = 2;
					if (v[i].first[0] == '3') check = 3;
				}
			}
		}
		if (check == 1)  {
			while (1) {
				cout << "\n1: Add student/Master \n";
				cout << "2: Edit student/Master \n";
				cout << "3: Delete student/Master \n";
				cout << "4: Add major \n";
				cout << "5: Edit major \n";
				cout << "6: Delete major \n";
				cout << "7: Add code \n";
				cout << "8: Edit code \n";
				cout << "9: Delete code \n";
				cout << "10: Log out \n";
				int a;
				cin >> a;
				if (a == 1) {
					string s;
					cout << "Enter your National ID : ";
					cin >> s;
					addp(s);
				}
				else if (a == 2) {
					string s,nid;
					cout << "Enter your National ID : ";
					cin >> s;
					nid = s;
					for (int i = 0; i < v.size(); i++) {
						if (s == v[i].first) {
							fstream fper;
							string ss = ".txt";
							s = s + ss;
							fper.open(s, ios::in);
							person p;
							p.NID = stoi(s);
							fper >> s;
							p.fname = s;
							fper >> s;
							p.lname = s;
							fper >> s;
							p.fadname = s;
							fper >> s;
							if (s == "0")p.sex = 0;
							else p.sex = 1;
							fper >> s;
							if (s == "0")p.marriage = 0;
							else p.marriage = 1;
							fper >> s;
							p.TT.d = stoi(s);
							fper >> s;
							p.TT.m = stoi(s);
							fper >> s;
							p.TT.y = stoi(s);
							p.print();
							addp(nid);
						}
					}
				}
				else if (a == 3) {
					string s;
					cout << "Enter your National ID : ";
					cin >> s;
					for (int i = 0; i < v.size(); i++) {
						if (s == v[i].first) {
							fstream fpass;
							fpass.open("pass.txt", ios::out);
							for (int j = 0; j < v.size(); j++) {
								if (v[j].first != s) {
									fpass << v[j].first << endl;
									fpass << v[j].second << endl;
								}
							}
							fpass.close();
							cout << "\nUser " <<"(" << s << ")" << " Deleted.\n";
						}
					}
				}
				else if (a == 4) {
					major r;
					r.set();
				}
				else if (a == 5) {
					cout << "Enter major's name :";
					string s;
					cin >> s;
					for (int i = 0; i < maj.size(); i++) {
						if (s == maj[i].first) {
							cout << "\n major ID : " << maj[i].first << endl;
							cout << "\n major name : " << maj[i].second.first << endl;
							cout << "\n major capacity : " << maj[i].second.second << endl;
							fresh.open("major.txt", ios::out);
							for (int j = 0; j < maj.size(); j++) {
								if (s != maj[j].first) {
									fresh << maj[j].first << endl;
									fresh << maj[j].second.first << endl;
									fresh << maj[j].second.second << endl;
								}
							}
							major r;
							r.set();
						}
					}
				}
				else if (a == 6) {
					cout << "Enter major's name :";
					string s;
					cin >> s;
					for (int i = 0; i < maj.size(); i++) {
						if (s == maj[i].first) {
							fresh.open("major.txt", ios::out);
							for (int j = 0; j < maj.size(); j++) {
								if (s != maj[j].first) {
									fresh << maj[j].first << endl;
									fresh << maj[j].second.first << endl;
									fresh << maj[j].second.second << endl;
								}
							}cout << "Major " << s << " deleted.";
						}
					}
				}
				else if (a == 7) {
					string s;
					cout << "Enter code name : ";
					cin >> s;
					addc(s);
				}
				else if (a == 8) {
					string s, coden;
					cout << "Enter code name : ";
					cin >> s;
					coden = s;
					for (int i = 0; i < code.size(); i++) {
						if (s == code[i]) {
							fstream fper;
							string ss = ".txt";
							s = s + ss;
							fper.open(s, ios::in);
							co p;
							fper >> s;
							p.master = s;
							fper >> s;
							p.majorname = s;
							fper >> s;
							p.maxcap = stoi(s);
							fper >> s;
							p.cap = stoi (s);
							fper >> s;
							if (s == "0")p.tafkik = 0;
							else p.tafkik = 1;
							fper >> s;
							p.vahed = stoi (s);
 							fper >> s;
							p.h1 = s;
							fper >> s;
							p.m1 = s;
							fper >> s;
							p.h2 = s;
							fper >> s;
							p.m2 = s;
							fper >> s;
							p.day1 = s;
							fper >> s;
							p.day2 = s;
							p.print();
							addp(coden);
						}
					}
				}
				else if (a == 9) {
					string s;
					cout << " Enter code name : \n";
					cin >> s;
					for (int i = 0; i < code.size(); i++) {
						if (s == code[i]) {
							fstream fpass;
							fpass.open("code.txt", ios::out);
							for (int j = 0; j < code.size(); j++) {
								if (code[j] != s) {
									fpass << code[j] << endl;
								}
							}
							fpass.close();
						}
					}
				}
				else if (a == 10) {
					system("cls");
					break;
				}
				else {
					cout << "Error. \n";
				}
			}
		}
		else if (check == 2) {
			cout << "\n1: show codes \n";
			cout << "2: select code \n";
			cout << "3: mark entry \n";
			cout << "4: Log out \n";
			while (1) {
				int a;
				cout << "choice : " << endl;
				cin >> a;
				if (a == 1) {
					for (int i = 0; i < code.size(); i++) {
						cout << "Code name is : " << code[i] << endl;
					}
				}
				else if (a == 2) {
					for (int i = 0; i < code.size(); i++) {
						string ss = ".txt";
						string s = code[i];
						s = s + ss;
						fstream tem;
						tem.open(s, ios::in);
						tem >> s;
						if (s == "0") {
							cout << i + 1 << ". Code name is : " << code[i] << endl;
						}
					}
					int b;
					cout << "Choice :\n";
					cin >> b;
					string ss = ".txt";
					user = user + ss;
					fstream fuser;
					fuser.open(user, ios::in);
					string s;
					fuser >> s;
					fuser >> s;
					string ost = s;
					string coden;
					s = code[b - 1];
					coden = s;
					for (int i = 0; i < code.size(); i++) {
						if (s == code[i]) {
							fstream fper;
							string ss = ".txt";
							s = s + ss;
							fper.open(s, ios::in);
							co p;
							fper >> s;
							p.master = ost;
							fper >> s;
							p.majorname = s;
							fper >> s;
							p.maxcap = stoi(s);
							fper >> s;
							p.cap = stoi(s);
							fper >> s;
							if (s == "0")p.tafkik = 0;
							else p.tafkik = 1;
							fper >> s;
							p.vahed = stoi(s);
							fper >> s;
							p.h1 = s;
							fper >> s;
							p.m1 = s;
							fper >> s;
							p.h2 = s;
							fper >> s;
							p.m2 = s;
							fper >> s;
							p.day1 = s;
							fper >> s;
							p.day2 = s;
							p.print();
							addp(coden);
						}
					}
				}
				else if (a == 3) {
					for (int i = 0; i < code.size(); i++) {
						fstream te;
						string s = code[i], ss = ".txt";
						s = s + ss;
						te.open(s, ios::in);
						te >> s;
						user = user + ss;
						te.open(user, ios::in);
						string sss;
						te >> sss;
						te >> sss;
						if (s == sss) {
							cout << i + 1 << " code name is : " << code[i] << endl;
						}
						int b;
						cout << " choice : ";
						cin >> b;
						string temp = code[b - 1];
						ss = "s.txt";
						temp = temp + ss;
						te.open(temp, ios::in);
						while (!te.eof()) {
							string s, ss;
							te >> s;
							te >> ss;
							mark.push_back(make_pair(s, ss));
						}
						te.open(temp, ios::out);
						for (int j = 0; j < mark.size(); j++) {
							cout << mark[j].first << " is :";
							string q;
							cin >> q;
							te << mark[j].first << endl;
							te << q << endl;
						}


					}
				}
				else if (a == 4) {
					break;
				}
				else {
					cout << "Error \n";
				}
			}
		}
		else if (check == 3) {
			cout << "1: Selection unit \n";
			cout << "2: Mark preview \n";
			cout << "3: Log out \n";
			while (1) {
				int a;
				cout << "choice : ";
				cin >> a;
				if (a == 1) {
					for (int i = 0; i < code.size(); i++) {
						cout << i + 1 << "Code name is : " << code[i] << endl;
					}
					int b;
					cout << "choice : ";
					cin >> b;
					string s = code[b - 1];
					string ss = "s.txt";
					s = s + ss;
					fstream fc;
					fc.open(s, ios::app);
					fc << user << endl;
					fc << 0 << endl;

				}
				else if (a == 2) {
					for (int i = 0; i < code.size(); i++) {
						string s, ss = "s.txt";
						s = code[i];
						s += ss;
						fstream te;
						te.open(s, ios::in);
						while (!te.eof()) {
							string t, tt;
							fpass >> t;
							fpass >> tt;
							if (user == t) {
								cout << "The mark of " << code[i] << "is : " << tt << endl;
							}
							
						}

					}
				}
				else if (a == 3) {
					system("cls");
					break;
				}
				else {
					cout << "Error \n";
				}
			}
		}
		else {
			system("cls");
			cout << "Username or Password is invalid.\nTry again.\n";

		}
	}
}
