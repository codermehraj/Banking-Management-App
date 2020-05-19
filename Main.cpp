/* ~CoderMehRaj~ */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <windows.h>

using namespace std;

/// Preprocessor declarations ~ Macros

#define show(x) cout << #x << " = " << x << '\n';
#define loop(x, i, j) for (int x = i; x <= (j); x++)
#define rep(n) for (int i = 1; i <= n; i++)
#define clr system("cls");
#define w8 Sleep(200)
#define pf(ch, kkk) loop(kk, 1, kkk) cout << ch;
#define ENTER cout << '\n';

/// Function Prototypes

void initiate_app_environment();
void load();
void ani();
void ani2();
void Hit_with_a_nyx_logo_to_flex_up();
void animate_seq_fn(vector<int> &seq);
int Get_Menu_Choice_Num();

/// The main Function

int main()
{
	initiate_app_environment();
	int menu_choice_num;
	while (1)
	{
		menu_choice_num = Get_Menu_Choice_Num();
		if (menu_choice_num == 9)
			break;
	}
	return 0;
}
/// LOADING FUNCTION
void load()
{
	clr;
	pf("\n", 11);
	pf("\t", 4);
	pf("  LOADING...", 1);
	pf("\n\t\t   ", 1);
	for (int r = 1; r <= 40; r++)
	{
		for (int q = 0; q <= 9000000; q++)
			; //to display the character slowly
		printf("%c", 177);
	}
	clr;
	pf("\n", 10);
	pf("\t", 3);
	printf("  ~~~ DONE LOADING ~~~\n\n\t\t   ");
	pf("\n", 3);
	pf("\t", 3);
	cout << "press enter to continue...";
	getchar();
	clr;
}

/// FUNCTION TO GET MENU CHOICE

int Get_Menu_Choice_Num()
{
	string choice;
	bool err = 0;
again:
	clr;
	pf('_', 76);
	ENTER;
	rep(18)
	{
		cout << '|';
		if (i == 1)
		{
			pf('>', 24);
			pf("| Banking Management App |", 1);
			pf('<', 24);
		}
		else if (i == 2)
		{
			pf('~', 74)
		}
		else if (i == 3)
		{
			pf('=', 30);
			pf("| MAIN MENU |", 1);
			pf('=', 31);
		}
		else if (i == 4)
		{
			pf('_', 74)
		}
		else if (i == 5)
		{
			pf(' ', 74)
		}
		else if (i == 15)
		{
			pf(' ', 37);
			pf('_', 32);
			pf(' ', 5);
		}
		else if (i == 16)
		{
			pf(' ', 37);
			pf("| ENTER YOUR CHOICE...  <1-9>  |", 1);
			pf(' ', 5);
		}
		else if (i == 17)
		{
			pf(' ', 37);
			pf('|', 1);
			pf(' ', 30);
			pf('|', 1);
			pf(' ', 5);
		}
		else if (i == 18)
		{
			pf('_', 37);
			pf('|', 1);
			pf(' ', 30);
			pf('|', 1);
			pf('_', 5);
		}
		else if (i == 6)
		{
			pf(' ', 4);
			cout << "1 >>>  Open New Account";
			pf(' ', 47);
		}
		else if (i == 7)
		{
			pf(' ', 4);
			cout << "2 >>>  Statement Of Existing Account";
			pf(' ', 34);
		}
		else if (i == 8)
		{
			pf(' ', 4);
			cout << "3 >>>  Transection";
			pf(' ', 52);
		}
		else if (i == 9)
		{
			pf(' ', 4);
			cout << "4 >>>  Take loan";
			pf(' ', 54);
		}
		else if (i == 10)
		{
			pf(' ', 4);
			cout << "5 >>>  Bank Status";
			pf(' ', 52);
		}
		else if (i == 11)
		{
			pf(' ', 4);
			cout << "6 >>>  Update Your Account Information";
			pf(' ', 32);
		}
		else if (i == 12)
		{
			pf(' ', 4);
			cout << "7 >>>  Pay Bill";
			pf(' ', 55);
		}
		else if (i == 13)
		{
			pf(' ', 4);
			cout << "8 >>>  About this app";
			pf(' ', 49);
		}
		else if (i == 14)
		{
			pf(' ', 4);
			cout << "9 >>>  EXIT";
			pf(' ', 59);
		}
		cout << '|';
		ENTER
	}
	if (err)
	{
		pf('.', 8);
		pf("Invalid Input Must enter (1-9) >>> ", 1);
	}
	else
	{
		pf('.', 38);
		pf(" >>> ", 1);
	}
	cin >> choice;
	if (choice[0] < '1' || choice[0] > '9' || choice.size() > 1)
	{
		err = 1;
		goto again;
	}
	return (int)(choice[0] - '0');
}

/// FUNCTION TO SHOW ANIMATION 1

void ani()
{
	char p = (char)177;
	rep(3) cout << "\n";
	rep(20)
	{
		if (i == 1)
		{
			pf(' ', 11);
			pf(p, 6);
		}
		else if (i == 9)
		{
			pf(' ', 9);
			pf(p, 31);
		}
		else
		{
			pf(' ', 15);
			pf(p, 2);
			if (i == 12)
			{
				pf(' ', 13);
				pf(p, 7);
			}
			else if (i == 13)
			{
				pf(' ', 13);
				pf(p, 2);
				pf(' ', 3);
				pf(p, 2);
			}
			else if (i == 14)
			{
				pf(' ', 4);
				pf("THE", 1);
				pf(' ', 6);
				pf(p, 3);
				pf(' ', 2);
				pf(p, 2);
			}
			else if (i == 15)
			{
				pf(' ', 4);
				pf("BANKING", 1);
				pf(' ', 7);
				pf(p, 2);
			}
			else if (i == 16)
			{
				pf(' ', 8);
				pf("APP", 1);
				pf(' ', 7);
				pf(p, 2);
			}
			else if (i == 17 || i == 19)
			{
				pf(' ', 18);
				pf(p, 2);
			}
			else if (i == 18)
			{
				pf(' ', 3);
				pf("By ~ MehRaj", 1);
				pf(' ', 4);
				pf(p, 2);
			}
			else if (i == 20)
				pf(p, 20);
		}
		if (i % 2)
			Sleep(80);
		ENTER
	}
	rep(3) ENTER
		pf("\t\tPress Enter to continue...", 1);
	getchar();
}

/// FUNCTION RELETED TO ANIMATE
void animate_seq_fn(vector<int> &seq)
{
	string What_To_Print = "0 ";
	int indx = 0;
	while (seq[indx] >= 0)
	{
		pf(What_To_Print[indx % 2], seq[indx]);
		indx++;
	}
}

/// 2ND ANIMATION ~ LOGO
void ani_2()
{
	vector<int> seq;
	rep(3) ENTER
		rep(10)
	{
		/// Print codes for printing "BANKING"
		cout << "\t";
		if (i == 1)
			seq = {9, 4, 10, 3, 4, 7, 3, 2, 3, 4, 3, 2, 3, 2, 4, 7, 3, 3, 10, -1};
		else if (i == 2)
			seq = {10, 2, 12, 2, 5, 6, 3, 2, 3, 3, 3, 3, 3, 2, 5, 6, 3, 2, 12, -1};
		else if (i == 3)
			seq = {2, 6, 2, 2, 3, 6, 3, 2, 6, 5, 3, 2, 3, 2, 3, 4, 3, 2, 6, 5, 3, 2, 3, 6, 3, -1};
		else if (i == 4)
			seq = {2, 6, 2, 2, 3, 6, 3, 2, 3, 1, 3, 4, 3, 2, 3, 1, 3, 5, 3, 2, 6, 5, 3, 2, 3, 6, 3, -1};
		else if (i == 5)
			seq = {9, 3, 3, 6, 3, 2, 3, 2, 3, 3, 3, 2, 6, 6, 3, 2, 3, 2, 3, 3, 3, 2, 3, -1};
		else if (i == 6)
			seq = {9, 3, 12, 2, 3, 3, 3, 2, 3, 2, 6, 6, 3, 2, 3, 3, 3, 2, 3, 2, 3, 3, 5, -1};
		else if (i == 7)
			seq = {2, 6, 2, 2, 12, 2, 3, 4, 3, 1, 3, 2, 3, 1, 3, 5, 3, 2, 3, 4, 3, 1, 3, 2, 3, 3, 2, 1, 3, -1};
		else if (i == 8)
			seq = {2, 6, 2, 2, 3, 6, 3, 2, 3, 5, 6, 2, 3, 2, 3, 4, 3, 2, 3, 5, 6, 2, 3, 6, 3, -1};
		else if (i == 9)
			seq = {10, 2, 3, 6, 3, 2, 3, 6, 5, 2, 3, 3, 3, 3, 3, 2, 3, 6, 5, 2, 12, -1};
		else if (i == 10)
			seq = {9, 3, 3, 6, 3, 2, 3, 7, 4, 2, 3, 4, 3, 2, 3, 2, 3, 7, 4, 3, 10, -1};
		animate_seq_fn(seq);
		seq.clear();
		ENTER
	}
	rep(2) ENTER
		rep(10)
	{
		/// Print codes for printing "APP"
		if (i == 1)
			seq = {0, 23, 10, 4, 10, 4, 10, -1};
		else if (i == 2)
			seq = {0, 22, 12, 2, 12, 2, 12, 7, -1};
		else if (i == 3 || i == 4)
			seq = {0, 22, 3, 6, 3, 2, 3, 6, 3, 2, 3, 6, 3, 3, -1};
		else if (i == 5)
			seq = {0, 22, 3, 6, 3, 2, 12, 2, 12, 3, -1};
		else if (i == 6)
			seq = {0, 22, 12, 2, 11, 3, 11, 4, -1};
		else if (i == 7)
			seq = {0, 22, 12, 2, 3, 11, 3, 12, -1};
		else if (i == 8)
			seq = {0, 22, 3, 6, 3, 2, 3, 11, 3, 12, -1};
		else if (i == 9)
			seq = {0, 22, 3, 6, 3, 2, 3, 11, 3, 12, -1};
		else if (i == 10)
			seq = {0, 22, 3, 6, 3, 2, 3, 11, 3, 12, -1};
		animate_seq_fn(seq);
		if (i == 2)
		{
			pf("< Made By >", 1);
		}
		else if (i == 3 || i == 10)
		{
			pf('~', 21);
		}
		else if (i == 4)
		{
			pf("| MehRajul", 1);
			pf(' ', 10);
			pf('|', 1);
		}
		else if (i == 5)
		{
			pf("|    Islam", 1);
			pf(' ', 10);
			pf('|', 1);
		}
		else if (i == 6)
		{
			pf("|       SUST", 1);
			pf(' ', 8);
			pf('|', 1);
		}
		else if (i == 7)
		{
			pf("|     Software", 1);
			pf(' ', 6);
			pf('|', 1);
		}
		else if (i == 8)
		{
			pf("|", 1);
			pf(' ', 7);
			pf("Engineering |", 1);
		}
		else if (i == 9)
		{
			pf("|", 1);
			pf(' ', 15);
			pf("'19.|", 1);
		}
		Sleep(50);
		seq.clear();
		ENTER
	}
	pf("\n", 4);
	pf("\t", 4);
	pf("Press enter to continue...", 1);
	getchar();
}

/// INITIATEING LOGO ~ ANIMATION
void Hit_with_a_nyx_logo_to_flex_up()
{
	ani();
	load();
	ani_2();
}

/// FUNCTION TO INITIATE
void initiate_app_environment()
{
	rep(4) cout << "\n";
	cout << "\t"
		 << "Welcome to The Banking Management App\n";
	Sleep(400);
	cout << "\t   "
		 << "Please Maximize Your Screen :P\n\n";
	cout << "\t    "
		 << "You may try < ALT + ENTER >\n\n";
	Sleep(300);
	cout << "\t   "
		 << "Press enter to continue...";
	getchar();
	load();
	Hit_with_a_nyx_logo_to_flex_up();
	load();
}
