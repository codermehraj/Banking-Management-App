/* ~CoderMehRaj~ */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>
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

/// Custom Data Types

typedef struct date
{
	int day, month, year;
	// In the file it will be stored as day/month/year
	// eg: 01/01/2001
	bool valid_date()
	{
		if (day < 1 || day > 31)
			return 0;
		if (year < 1900 || year > 2100)
			return 0;
		if (month > 12 || month < 1)
			return 0;
		if (day < 28)
			return 1;
		if (month == 2)
		{
			if (day != 29 && day != 28)
				return 0;
			if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
			{
				if (day == 29)
					return 1;
				else
					return 0;
			}
			else if (day == 28)
				return 1;
			else
				return 0;
		}
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day <= 30)
				return 1;
			else
				return 0;
		}
		if (day <= 31)
			return 1;
		return 0;
	}
};

typedef struct BankAccount
{
	string AccountNumber, FirstName, LastName, PhoneNumber, Password, NID, email;
	long long LastTransection = 0;
	long double Balance, Rate;
	int Type;
	// Rate will be initially zero
	// If you want to add a VIP customer then you can choose a special rate for him/her
	date InitialDate, MemorableDate, DateOfBirth, LastTransectionDate;
};

/// Function Prototypes

void initiate_app_environment();
void load();
void ani();
void ani2();
void Hit_with_a_nyx_logo_to_flex_up();
void animate_seq_fn(vector<int> &seq);
int Get_Menu_Choice_Num();
void new_account_message();
void AddThemAllToTheFile(BankAccount temp);
bool valid_account_number(string ac_num, int *error_msg);
bool correct_NID_number(string NID);
bool correct_email_address(string email);
bool correct_phone_number(string phone);
bool nice_date(string a_date, date *x);
bool chk_pass_ok_or_not(string passA, string passB, int *error_msg);
bool initial_balance_fine(string amount_string, long double *amount);
bool VIP_ok_rate(string rate_s, long double *rate);
bool valid_acc_type(string s, int *ans);
bool date_diff(date a, date b);
bool Show_all_info_and_all_ok(BankAccount temp);
void create_new_account();
void Show_Statement();
bool not_found(string s);
void Show_dashboard(BankAccount temp);
void transection();
void trans_initiate_message();
void transection_from_this_account(BankAccount temp);
void send_money_to_extarnal_account(date x, BankAccount temp);
bool valid_send_money(string amount_string, long double *amount, long double Balance);
int get_number_of_days(date dt1, date dt2);
int countLeapYears(date d);
long double get_new_balance(long double cur_balance, int acc_type, int vip_rate, int days_spent);
bool update_bank_acc_info(BankAccount updated_acc);
void recieve_money_from_extarnal_account(date x, BankAccount temp);
void send_money_to_internal_account(date x, BankAccount temp);
bool update_bank_acc_info_of_internal_reciever(string ac_num, date x, long double amount);
void edit_user_info();
bool valid_choice_cng(string s);
void edit_info_message();
void forget_password();
void pay_bill();
void pay_bill_from_this_account(BankAccount temp);
void pay_bill_at_this_date(date x, BankAccount temp);
void pay_bill_initiate_message();
void show_bank_status();
void get_num_of_acc(int *savings_acc, int *fdr_acc, int *buss_acc, int *vip_acc, long double *tot);
void delete_account();
bool delete_this_acc(BankAccount updated_acc);
void about();

/// The main Function

int main()
{
	initiate_app_environment();
	int menu_choice_num;
	while (1)
	{
		menu_choice_num = Get_Menu_Choice_Num();
		if (menu_choice_num == 1)
			create_new_account();
		else if (menu_choice_num == 2)
			Show_Statement();
		else if (menu_choice_num == 3)
			transection();
		else if (menu_choice_num == 4)
			delete_account();
		else if (menu_choice_num == 5)
			show_bank_status();
		else if (menu_choice_num == 6)
			edit_user_info();
		else if (menu_choice_num == 7)
			pay_bill();
		else if (menu_choice_num == 8)
			about();
		else if (menu_choice_num == 9)
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
	return;
	pf("\n", 10);
	pf("\t", 3);
	printf("  ~~~ DONE LOADING ~~~\n\n\t\t   ");
	pf("\n", 3);
	pf("\t", 3);
	cout << "press enter to continue...";
	string s;
	getline(cin, s);
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
			cout << "4 >>>  Delete Your Account";
			pf(' ', 44);
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
	//getchar();
	cin.ignore(1000, '\n');
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
	//getchar();
	cin.ignore(1000, '\n');
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
	//getchar();
	cin.ignore(1000, '\n');
	load();
	Hit_with_a_nyx_logo_to_flex_up();
	load();
}

// Function to show up the initial message of account creation

void new_account_message()
{
	clr;
	rep(3) cout << '\n';
	cout << "\t_________________| Welcome to the automated account creation mode |________________\n\t|";
	pf(' ', 81);
	cout << "|\n\t|                   This will take several minutes to complete";
	pf(' ', 20);
	cout << "|\n\t|";
	pf(' ', 81);
	cout << "|\n\t| Please give authentic information otherwise"
		 << " your account may face permanent BAN |\n\t|";
	pf(' ', 81);
	cout << "|\n\t";
	pf('~', 83);
	cout << "\n";
}

// Function to add all the infromation of a bank account to the end of the file

void AddThemAllToTheFile(BankAccount temp)
{
	ofstream add_new_acc_num("index.txt", ios::app);
	add_new_acc_num << temp.AccountNumber << '\n';
	add_new_acc_num.close();
	add_new_acc_num.open("root.txt", ios::app);
	add_new_acc_num << '\n'
					<< temp.AccountNumber << " " << temp.Password << " " << temp.FirstName
					<< " " << temp.LastName << " " << temp.NID << " " << temp.PhoneNumber;
	add_new_acc_num << " " << temp.email << " " << fixed << setprecision(2) << temp.Balance << " " << temp.LastTransection
					<< " " << temp.Rate << " " << temp.Type << " " << temp.InitialDate.day << " ";
	add_new_acc_num << temp.InitialDate.month << " " << temp.InitialDate.year << " ";
	add_new_acc_num << temp.MemorableDate.day << " " << temp.MemorableDate.month << " "
					<< temp.MemorableDate.year << " " << temp.DateOfBirth.day << " " << temp.DateOfBirth.month
					<< " " << temp.DateOfBirth.year << " " << temp.InitialDate.day << " ";
	add_new_acc_num << temp.InitialDate.month << " " << temp.InitialDate.year;
	add_new_acc_num.close();
}

// Function to check if a new account number is valid or not

bool valid_account_number(string ac_num, int *error_msg)
{
	int n = ac_num.size();
	for (int i = 0; i < n; i++)
		if (ac_num[i] < '0' || ac_num[i] > '9')
		{
			*error_msg = 2; // Account number got invalid digits ~ error code 2
			return 0;
		}
	if (n == 9)
	{
		ofstream indx_file_make("index.txt", ios::app);
		indx_file_make.close();
		// Used ofstream to make index.txt if not existed
		ifstream indxFile;
		string prev_account_num;
		indxFile.open("index.txt");
		while (!indxFile.eof())
		{
			indxFile >> prev_account_num;
			if (prev_account_num == ac_num)
			{
				indxFile.close();
				*error_msg = 3; // Account number exists ~ error code 3
				return 0;
			}
		}
		indxFile.close();
		cout << "\n\tCongratulation!\n\t" << ac_num << " is available...\n";
		cout << "\tAre you sure to consider '" << ac_num << "' as your Account number\n";
		cout << "\tPress 'Y' to say YES and press 'N' to say NO\n";
		cout << "\tEnter your choice (Y/N) >>> ";
		string choice;
		bool first = 1;
		do
		{
			if (!first)
			{
				cout << "\n\tINVALID CHOICE\n\tPress 'Y' to say YES and press 'N' to say NO\n";
				cout << "\tEnter your choice (Y/N) >>> ";
			}
			cin >> choice;
			if (choice == "1")
			{
				*error_msg = 5;
				// return to main menu
				return 0;
			}
			cin.ignore(1000, '\n');
			if (choice == "y" || choice == "Y" || choice == "YES" || choice == "yes" || choice == "Yes")
			{
				// Will be added later on
				// to save all info altogether
				// Other wise half info will be added
				// which may cause error later on the process
				return 1;
			}
			else if (choice == "n" || choice == "N" || choice == "NO" || choice == "no" || choice == "No")
			{
				*error_msg = 4;
				// User choosed so...
				return 0;
			}
			first = 0;
		} while (1);
	}
	else
	{
		*error_msg = 1; // Account number size mismatch ~ error code = 1
		return 0;
	}
}

// Function to check if NID number is correct format or not

bool correct_NID_number(string NID)
{
	int n = NID.size();
	for (int i = 0; i < n; i++)
		if (NID[i] > '9' || NID[i] < '0')
			return 0;
	return 1;
}

// Function to check if email address is correct format or not

bool correct_email_address(string email)
{
	/*
		CONDITIONS :
        First character must be letter
        must contain only 1 @
        must have at least 1 dot after @
        must have at least two letters after last dot
    */
	int n = email.size();
	bool dot = 0;
	int at_the_rate = 0;
	if (n < 5)
		return 0;
	if (email[0] >= 'a' && email[0] <= 'z')
		;
	else if (email[0] >= 'A' && email[0] <= 'Z')
		;
	else
		return 0;
	for (int i = 1; i < n - 2; i++)
	{
		if (email[i] == '@')
			at_the_rate++;
		else if (at_the_rate == 1 && email[i] == '.' && email[i - 1] != '@')
			dot = 1;
		if (at_the_rate > 1)
			return 0;
		if (dot && at_the_rate == 1)
			return 1;
	}
	return 0;
}

// Function to check if phone number is correct format or not

bool correct_phone_number(string phone)
{
	int n = phone.size();
	for (int i = 0; i < n; i++)
		if (phone[i] > '9' || phone[i] < '0')
			return 0;
	return 1;
}

// Function to check if given date is correct format or not

bool nice_date(string a_date, date *x)
{
	// **/**/**** ~ size=10
	// 0123456789 ~ indexes
	if (a_date.size() != 10)
		return 0;
	for (int i = 0; i < 10; i++)
	{
		if (i == 2 || i == 5)
		{
			if (a_date[i] >= '0' && a_date[i] <= '9')
				return 0;
		}
		else if (a_date[i] < '0' || a_date[i] > '9')
			return 0;
	}
	(*x).day = 10 * (int)(a_date[0] - '0') + (int)(a_date[1] - '0');
	(*x).month = 10 * (int)(a_date[3] - '0') + (int)(a_date[4] - '0');
	(*x).year = 1000 * (int)(a_date[6] - '0') + 100 * (int)(a_date[7] - '0');
	(*x).year += 10 * (int)(a_date[8] - '0') + (int)(a_date[9] - '0');
	if ((*x).valid_date())
		return 1;
	else
		return 0;
}

// Function to check if password is correct format or not

bool chk_pass_ok_or_not(string passA, string passB, int *error_msg)
{
	/*
		CONDITIONS :
		- Length must be at least 6
		- Must contain a number
		- Must contain an uppercase letter
		- Must contain a lowercase letter
	*/
	if (passA != passB)
	{
		*error_msg = 1;
		// mismatch code = 1
		return 0;
	}
	int n = passA.size();
	bool num = 0, lower = 0, upper = 0;
	if (n < 6)
	{
		*error_msg = 2;
		// size less than 6
		// error code = 2
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (!num && passA[i] >= '0' && passA[i] <= '9')
			num = 1;
		if (!lower && passA[i] >= 'a' && passA[i] <= 'z')
			lower = 1;
		if (!upper && passA[i] >= 'A' && passA[i] <= 'Z')
			upper = 1;
		if (num && lower && upper)
			return 1;
	}
	if (!num)
	{
		*error_msg = 3;
		// no number
		return 0;
	}
	if (!lower)
	{
		*error_msg = 4;
		// no lower case
		return 0;
	}
	if (!upper)
	{
		*error_msg = 5;
		// no Upper case
		return 0;
	}
	return 1;
}

// Function to check if initial balance is valid or not

bool initial_balance_fine(string amount_string, long double *amount)
{
	int n = amount_string.size(), i = 0, value = 1;
	*amount = 0.00;
	if (amount_string[0] == '-')
		return 0;
	if (n > 11 || n < 3)
		return 0;
	while (amount_string[i] == '0')
		i++;
	for (int j = n - 1; j >= i; j--)
	{
		if (amount_string[j] < '0' || amount_string[j] > '9')
			return 0;
		*amount += 1.0 * (value * (int)(amount_string[j] - '0'));
		value *= 10;
	}
	if (*amount > 999999999.00 || *amount < 500.00)
		return 0;
	return 1;
}

// Function to check if VIP rate is valid or not

bool VIP_ok_rate(string rate_s, long double *rate)
{
	if (rate_s.size() > 2)
		return 0;
	else if (rate_s.size() == 1)
	{
		if (rate_s[0] < '0' || rate_s[0] > '9')
			return 0;
		*rate = 1.0 * (int)(rate_s[0] - '0');
		return 1;
	}
	else if (rate_s.size() == 2)
	{
		if (rate_s[1] < '0' || rate_s[1] > '9')
			return 0;
		if (rate_s[0] < '0' || rate_s[0] > '9')
			return 0;
		*rate = 10.0 * (int)(rate_s[0] - '0') + 1.0 * (int)(rate_s[1] - '0');
		if (*rate > 20.00)
			return 0;
		return 1;
	}
	return 0;
}

// Function to check if account type is valid or not

bool valid_acc_type(string s, int *ans)
{
	if (s.size() > 1)
		return 0;
	if (s[0] == '1')
	{
		*ans = 1;
		return 1;
	}
	else if (s[0] == '2')
	{
		*ans = 2;
		return 1;
	}
	else if (s[0] == '3')
	{
		*ans = 3;
		return 1;
	}
	return 0;
}

// Function to check if date difference is valid or not

bool date_diff(date a, date b)
{
	// returns true if a>=b
	if (a.year < b.year)
		return 0;
	else if (a.year > b.year)
		return 1;
	else
	{
		if (a.month > b.month)
			return 1;
		else if (a.month < b.month)
			return 0;
		else
			return a.day >= b.day;
	}
}

// Function to show all info to the user and get confirmation

bool Show_all_info_and_all_ok(BankAccount temp)
{
	clr;
	cout << "\n\n\t|";
	pf('_', 84);
	cout << "|\n\t|";
	pf('.', 35);
	cout << "| DASHBOARD |";
	pf('.', 36);
	cout << "|\n\t|";
	pf('_', 84);
	cout << "|\n\n";
	cout << "\t     1. Account Number   : " << temp.AccountNumber << endl;
	cout << "\t     2. Full Name        : " << temp.FirstName << " " << temp.LastName << endl;
	cout << "\t     3. National ID      : " << temp.NID << endl;
	cout << "\t     4. Contact Number   : " << temp.PhoneNumber << endl;
	cout << "\t     5. Email Address    : " << temp.email << endl;
	cout << "\t     6. Date of Birth    : " << temp.DateOfBirth.day << "/"
		 << temp.DateOfBirth.month << "/" << temp.DateOfBirth.year << endl;
	cout << "\t     7. Password         : " << temp.Password << endl;
	cout << "\t     8. Balance          : " << fixed << setprecision(2) << temp.Balance << "$\n";
	cout << "\t     9. Last Transection : Credited " << temp.LastTransection << "$ (";
	cout << temp.LastTransectionDate.day << "/" << temp.LastTransectionDate.month << "/" << temp.LastTransectionDate.year << ")\n";
	cout << "\t    10. VIP Status       : ";
	if (temp.Rate >= 0.00)
		cout << "YES ( VIP custom rate = " << temp.Rate << "% )\n";
	else
		cout << "NO\n";
	cout << "\t    11. Account Type     : ";
	if (temp.Type == 1)
		cout << "Savings Account\n";
	else if (temp.Type == 2)
		cout << "Fixed Deposit Account\n";
	else if (temp.Type == 3)
		cout << "Business Account\n";
	cout << "\t    12. A/c Origin Date  : " << temp.InitialDate.day << "/"
		 << temp.InitialDate.month << "/" << temp.InitialDate.year << endl;
	cout << "\t    13. Memorable Date   : " << temp.MemorableDate.day << "/"
		 << temp.MemorableDate.month << "/" << temp.MemorableDate.year << endl;
	cout << "\n\tPlease Check the above information.\n\tIf These are correct Press 'Y' to say YES";
	cout << "\n\tOtherwise Press 'N' to say NO and return to main menu\n\n\t";
	cout << "Enter your choice :: ";
	string choice;
	bool first = 1;
	do
	{
		if (!first)
		{
			cout << "\n\tINVALID CHOICE\n\tPress 'Y' to say YES and press 'N' to say NO\n";
			cout << "\tEnter your choice (Y/N) >>> ";
		}
		cin >> choice;
		cin.ignore(1000, '\n');
		if (choice == "y" || choice == "Y" || choice == "YES" || choice == "yes" || choice == "Yes")
		{
			return 1;
			break;
		}
		else if (choice == "n" || choice == "N" || choice == "NO" || choice == "no" || choice == "No")
		{
			return 0;
			break;
		}
		first = 0;
	} while (1);
}

// Function to create a new bank account

void create_new_account()
{
	load();
	BankAccount save_new_account;
	string ac_num;
	int error_msg = 0;
	do
	{
		new_account_message();
		cout << "\n\tChoose an account number for Your New bank Account...\n";
		cout << "\n\tThe number should be :\n";
		cout << "\t>>> Consist of Nine digits.\n";
		cout << "\t>>> Can have any digit from ( 0-9 ).\n";
		cout << "\t>>> Can contain any number of leading zeros.\n";
		cout << "\t>>> It have to be UNIQUE ( Which is pretty obvious )\n";
		cout << "\tPress '1' to return to main menu...\n\n";
		if (error_msg != 0)
		{
			cout << "\t" << ac_num << " is invalid\n\t";
			if (error_msg == 1)
				cout << "You should give 9 digits not " << ac_num.size();
			else if (error_msg == 2)
				cout << "You cannot give anything except (0 to 9)";
			else if (error_msg == 3)
				cout << "SORRY! " << ac_num << " is already taken by someone else";
			else if (error_msg == 4)
			{
				cout << "Alas! You choose not use '" << ac_num << "' as your account number";
				cout << "\n\tIt was available for use though...\n";
			}
			else if (error_msg == 5)
				return;
			cout << "\n\tPlease again enter an account number for your account ::\n\t>>> ";
		}
		else
			cout << "\tEnter an account number for your account ::\n\t>>> ";
		cin >> ac_num;
		if (ac_num == "1")
			return;
	} while (!valid_account_number(ac_num, &error_msg));
	new_account_message();
	save_new_account.AccountNumber = ac_num;
	cout << "\n\n\tCongratulation!\n\tYou are assigned to a new account number :: '" << ac_num;
	cout << "'\n\tPress Enter to continue... ";
	getchar();
	load();
	if (1)
	{
		/// The block to get some basic Information
		string name;
		new_account_message();
		cout << "\n\n\tAccount number | " << save_new_account.AccountNumber << " |\n";
		cout << "\tNow Please give the following Basic Information :\n\n";
		cout << "\t### | NOTE THAT TEXT SHOULD NOT CONTAIN ANY SPACES | ###\n\n\t";
		cout << "Still if found any text after space that will be ignored\n";
		cout << "\tPress '1' to return to main menu...\n\t";
		cout << "Your first name :: ";
		cin >> name;
		if (name == "1")
			return;
		save_new_account.FirstName = name;
		cin.ignore(1000, '\n');
		cout << "\tYour last name :: ";
		cin >> name;
		if (name == "1")
			return;
		save_new_account.LastName = name;
		cin.ignore(1000, '\n');
		bool starter = 1;
		do
		{
			if (!starter)
				cout << "\n\tINVALID NID Number( Should have only digits 0-9 )";
			cout << "\n\tYour National ID number :: ";
			cin >> name;
			if (name == "1")
				return;
			cin.ignore(1000, '\n');
			starter = 0;
		} while (!correct_NID_number(name));
		save_new_account.NID = name;
		starter = 1;
		do
		{
			if (!starter)
				cout << "\n\tINVALID email address\n\tTRY AGAIN";
			cout << "\n\tYour email address :: ";
			cin >> name;
			if (name == "1")
				return;
			cin.ignore(1000, '\n');
			starter = 0;
		} while (!correct_email_address(name));
		save_new_account.email = name;
		starter = 1;
		date x;
		do
		{
			if (!starter)
			{
				cout << "\n\tINVALID DATE( date format : **/**/**** )";
				cout << "\n\t The date should be a valid day between 1900-2100\n";
			}
			cout << "\n\tEnter Your Date of Birth ( example : 01/05/1995 )\n\t>>> ";
			cin >> name;
			if (name == "1")
				return;
			cin.ignore(1000, '\n');
			starter = 0;
		} while (!nice_date(name, &x));
		save_new_account.DateOfBirth = x;
		starter = 1;
		do
		{
			if (!starter)
				cout << "\n\tINVALID Phone Number( Should have only digits 0-9 )";
			cout << "\n\tYour Phone number :: +";
			cin >> name;
			if (name == "1")
				return;
			cin.ignore(1000, '\n');
			starter = 0;
		} while (!correct_phone_number(name));
		save_new_account.PhoneNumber = "+";
		save_new_account.PhoneNumber += name;
	}
	cout << "\n\tGreat!\n\tYour Basic Information is taken successfully :D ";
	cout << "\n\tPress Enter to continue... ";
	getchar();
	load();
	if (1)
	{
		/// This is another block
		string passA, passB;
		new_account_message();
		cout << "\n\n\tAccount number | " << save_new_account.AccountNumber << " |\n";
		cout << "\tNow Please give the following Intermediate Information :\n\n";
		cout << "\t### | NOTE THAT TEXT SHOULD NOT CONTAIN ANY SPACES | ###\n\n\t";
		cout << "Still if found any text after space that will be ignored\n\n\t";
		error_msg = 0;
		cout << "Try to choose a strong password for your account."
			 << "\n\tMinimum criteria given below :\n";
		cout << "\t- Password must contain at least 6 charecters\n";
		cout << "\t- Password must contain at least 1 number 0-9\n";
		cout << "\t- Password must contain at least 1 Uppercase Letter (A-Z)\n";
		cout << "\t- Password must contain at least 1 Lowercase Letter (a-z)\n";
		cout << "\n\tPress '1' to return to the main menun\n\n";
		do
		{
			if (error_msg == 1)
				cout << "\n\tPASSWORD DIDN'T MATCHED\n\tTRY AGAIN\n";
			else if (error_msg == 2)
			{
				cout << "\n\tPASSWORD's LENGTH MUST BE AT LEAST 6\n\t";
				cout << "Your given password's length was " << passA.size();
				cout << "( less than 6 )\n\tTRY AGAIN\n";
			}
			else if (error_msg == 3)
			{
				cout << "\n\tPASSWORD MUST HAVE AT LEAST A NUMBER (0-9)\n\t";
				cout << "Your given password " << passA << " don't have a ";
				cout << "number\n\tTRY AGAIN\n";
			}
			else if (error_msg == 4)
			{
				cout << "\n\tPASSWORD MUST HAVE AT LEAST A LOWER CASE LETTER (a-z)\n\t";
				cout << "Your given password " << passA << " don't have a ";
				cout << "lowercase letter\n\tTRY AGAIN\n";
			}
			else if (error_msg == 5)
			{
				cout << "\n\tPASSWORD MUST HAVE AT LEAST AN UPPER CASE LETTER (A-Z)\n\t";
				cout << "Your given password " << passA << " don't have an ";
				cout << "uppercase letter\n\tTRY AGAIN\n";
			}
			cout << "\tEnter Your password :: ";
			cin >> passA;
			if (passA == "1")
				return;
			cin.ignore(1000, '\n');
			cout << "\tConfirm Your password :: ";
			cin >> passB;
			if (passB == "1")
				return;
			cin.ignore(1000, '\n');
		} while (!chk_pass_ok_or_not(passA, passB, &error_msg));
		save_new_account.Password = passA;
		cout << "\n\tCongratulation !!!";
		cout << "\n\tPassword is set successfully\n";
		cout << "\tPlease remember '" << save_new_account.Password << "' as your";
		cout << " password for future use.\n\n\tPress Enter to continue... ";
		getchar();
	}

	if (1)
	{
		new_account_message();
		cout << "\n\n\tAccount number | " << save_new_account.AccountNumber << " |\n";
		cout << "\tNow Please give the following Intermediate Information :\n\n";
		cout << "\t### | NOTE THAT TEXT SHOULD NOT CONTAIN ANY SPACES | ###\n\n\t";
		cout << "Still if found any text after space that will be ignored\n\n\t";
		cout << "Press '1' to return to the main menu\n\n\t";
		string name;
		long double amount;
		bool starter = 1;
		do
		{
			if (!starter)
			{
				cout << "\n\tInvalid amount\n\tMust enter integer between ";
				cout << "500 to 999999999\n";
			}
			cout << "\tEnter your Initial Deposit amount :: (It must be at least 500)\n";
			cout << "\t>>> ";
			cin >> name;
			if (name == "1")
				return;
			cin.ignore(1000, '\n');
			starter = 0;
		} while (!initial_balance_fine(name, &amount));
		save_new_account.Balance = amount;
		save_new_account.LastTransection = amount;
		cout << "\t" << save_new_account.LastTransection << "$ Successfully deposited to your account\n";
		cout << "\n\tDo you want premium VIP account??\n";
		cout << "\tPress 'Y' to say YES and press 'N' to say NO\n";
		cout << "\tEnter your choice (Y/N) >>> ";
		string choice;
		bool first = 1;
		do
		{
			if (!first)
			{
				cout << "\n\tINVALID CHOICE\n\tPress 'Y' to say YES and press 'N' to say NO\n";
				cout << "\tEnter your choice (Y/N) >>> ";
			}
			cin >> choice;
			if (choice == "1")
				return;
			cin.ignore(1000, '\n');
			if (choice == "y" || choice == "Y" || choice == "YES" || choice == "yes" || choice == "Yes")
			{
				cout << "\n\tWelcome to your VIP account\n\t";
				cout << "Each VIP account can have custom rates...\n\t";
				cout << "Your custom rate can be between 0% to 20%\n\n\t";
				starter = 1;
				do
				{
					if (!starter)
						cout << "\tINVALID RATE\n\t";
					cout << "Enter your custom rate :: ";
					cin >> name;
					cin.ignore(1000, '\n');
					starter = 0;
				} while (!VIP_ok_rate(name, &amount));
				save_new_account.Rate = amount;
				cout << "\n\tYou VIP account rate is set to " << save_new_account.Rate << "%\n";
				cout << "\tThanks for using VIP account\n";
				break;
			}
			else if (choice == "n" || choice == "N" || choice == "NO" || choice == "no" || choice == "No")
			{
				save_new_account.Rate = -1.0;
				break;
			}
			first = 0;
		} while (1);
		cout << "\n\tSelect Your Account Type :: \n";
		cout << "\t1 >>> Savings Account\n";
		cout << "\t2 >>> Fixed Deposit Account ~ FDR\n";
		cout << "\t3 >>> Current Account ~ Business\n";
		first = 1;
		int inpt;
		do
		{
			if (!first)
				cout << "\tINVALID CHOICE\n";
			cout << "\n\tChoose one from above. Press ( 1 / 2 / 3 )\n\t>>> ";
			cin >> name;
			cin.ignore(1000, '\n');
			first = 0;
		} while (!valid_acc_type(name, &inpt));
		save_new_account.Type = inpt;
		if (save_new_account.Type == 1)
			cout << "\n\tYour Account set to :: Savings Account\n";
		else if (save_new_account.Type == 2)
			cout << "\n\tYour Account set to :: Fixed Deposit Account\n";
		else if (save_new_account.Type == 3)
			cout << "\n\tYour Account set to :: Business Account\n";
		cout << "\n\tPress Enter to continue... ";
		getchar();
	}
	if (1)
	{
		new_account_message();
		cout << "\n\n\tAccount number | " << save_new_account.AccountNumber << " |\n";
		cout << "\tNow Please give the following Intermediate Information :\n\n";
		cout << "\t### | NOTE THAT TEXT SHOULD NOT CONTAIN ANY SPACES | ###\n\n\t";
		cout << "Still if found any text after space that will be ignored\n\n\t";
		cout << "Press '1' to return to main menu\n\n\t";
		bool starter = 1;
		string name;
		date x;
		do
		{
			if (!starter)
			{
				cout << "\n\tINVALID DATE( date format : **/**/**** )";
				cout << "\n\t The date should be a valid day between 1900-2100\n";
			}
			cout << "\n\tEnter Today's Date ( example : 01/05/1995 )\n\t>>> ";
			cin >> name;
			if (name == "1")
				return;
			cin.ignore(1000, '\n');
			starter = 0;
			if (nice_date(name, &x))
			{
				if (date_diff(x, save_new_account.DateOfBirth))
					break;
				else
					cout << "\tYou cannot have your account before your birth :/\n";
			}
		} while (1);
		save_new_account.InitialDate = x;
		save_new_account.LastTransectionDate = x;
		starter = 1;
		cout << "\n\tWe need to know your most memorable date for security purpose\n";
		cout << "\tIt will be used to recover your password in case you need\n";
		do
		{
			if (!starter)
			{
				cout << "\n\tINVALID DATE( date format : **/**/**** )";
				cout << "\n\t The date should be a valid day between 1900-2100\n";
			}
			cout << "\n\tEnter Your Most memorable date ( example : 01/05/1995 )\n\t>>> ";
			cin >> name;
			if (name == "1")
				return;
			cin.ignore(1000, '\n');
			starter = 0;
		} while (!nice_date(name, &x));
		save_new_account.MemorableDate = x;
		if (!Show_all_info_and_all_ok(save_new_account))
			return;
	}
	AddThemAllToTheFile(save_new_account);
	cout << "\n\tCongratulation!";
	cout << "\n\tYour Account has been saved successfully\n\n\t";
	cout << "Press enter to continue... ";
	getchar();
}

// Function to find existing account from the file

bool not_found(string s)
{
	// return 1 if not found
	// return 0 if found
	string acc;
	if (s.size() != 9)
		return 1;
	ifstream index_file("index.txt");
	while (!index_file.eof())
	{
		index_file >> acc;
		if (acc == s)
		{
			index_file.close();
			return 0;
		}
	}
	return 1;
}

// Function to reset ueser password

void forget_password()
{
	load();
	cout << "\n\n\tWelcome to the password recovery mode\n\n\t";
	cout << "Please enter your Account Number to continue...\n\n\t";
	string ac_num, name;
	bool starting = 1;
	do
	{
		if (!starting)
			cout << "\n\tInvalid Account Number\n\t";
		cout << "Press '1' to return to main menu\n";
		cout << "\tEnter your Account number ::  ";
		cin >> ac_num;
		cin.ignore(1000, '\n');
		if (ac_num == "1")
			return;
		starting = 0;
	} while (not_found(ac_num));
	ifstream get_acc("root.txt");
	BankAccount temp;
	while (!get_acc.eof())
	{
		get_acc >> temp.AccountNumber >> temp.Password >> temp.FirstName >> temp.LastName >> temp.NID >> temp.PhoneNumber;
		get_acc >> temp.email >> temp.Balance >> temp.LastTransection >> temp.Rate >> temp.Type >> temp.InitialDate.day;
		get_acc >> temp.InitialDate.month >> temp.InitialDate.year;
		get_acc >> temp.MemorableDate.day >> temp.MemorableDate.month >> temp.MemorableDate.year >> temp.DateOfBirth.day >> temp.DateOfBirth.month >> temp.DateOfBirth.year;
		get_acc >> temp.LastTransectionDate.day >> temp.LastTransectionDate.month >> temp.LastTransectionDate.year;
		if (temp.AccountNumber == ac_num)
		{
			get_acc.close();
			cout << "\n\n\tCongratulation!\n\tAccount Number :: | " << ac_num << " | is Found\n\t";
			cout << "Welcome, " << temp.FirstName << " " << temp.LastName << "\n";
			cout << "\n\tEnter Your most memorable date\n";
			date x;
			bool starter = 1;
			do
			{
				if (!starter)
				{
					cout << "\n\tINVALID DATE( date format : **/**/**** )";
					cout << "\n\t The date should be a valid day between 1900-2100\n";
				}
				cout << "\n\tEnter Your Most memorable date ( example : 01/05/1995 )\n\t>>> ";
				cin >> name;
				if (name == "1")
					return;
				cin.ignore(1000, '\n');
				starter = 0;
			} while (!nice_date(name, &x));
			if (x.day == temp.MemorableDate.day && x.month == temp.MemorableDate.month && x.year == temp.MemorableDate.year)
			{
				cout << "\n\tEnter the amount of your last transection in this account\n\n";
				string amount_string;
				long double amount;
				long long max_amount = 999999999;
				starter = 1;
				do
				{
					if (!starter)
					{
						cout << "\n\tInvalid amount\n\tMust enter integer between ";
						cout << "1 to " << max_amount << "\n";
					}
					cout << "\tEnter the Last Transection amount :: ";
					cin >> amount_string;
					cin.ignore(1000, '\n');
					starter = 0;
				} while (!valid_send_money(amount_string, &amount, max_amount));
				long long x = temp.LastTransection;
				if (x < 0)
					x *= (-1);
				if ((long long)amount == x)
				{
					cout << "\n\n\tCONGRATULATION! Your authentication is completed\n\n\t";
					cout << "Now you can change your password\n\n\t";
					int error_msg = 0;
					string passA, passB;
					cout << "Try to choose a strong password for your account."
						 << "\n\tMinimum criteria given below :\n";
					cout << "\t- Password must contain at least 6 charecters\n";
					cout << "\t- Password must contain at least 1 number 0-9\n";
					cout << "\t- Password must contain at least 1 Uppercase Letter (A-Z)\n";
					cout << "\t- Password must contain at least 1 Lowercase Letter (a-z)\n";
					cout << "\n\tPress '1' to return to the main menun\n\n";
					do
					{
						if (error_msg == 1)
							cout << "\n\tPASSWORD DIDN'T MATCHED\n\tTRY AGAIN\n";
						else if (error_msg == 2)
						{
							cout << "\n\tPASSWORD's LENGTH MUST BE AT LEAST 6\n\t";
							cout << "Your given password's length was " << passA.size();
							cout << "( less than 6 )\n\tTRY AGAIN\n";
						}
						else if (error_msg == 3)
						{
							cout << "\n\tPASSWORD MUST HAVE AT LEAST A NUMBER (0-9)\n\t";
							cout << "Your given password " << passA << " don't have a ";
							cout << "number\n\tTRY AGAIN\n";
						}
						else if (error_msg == 4)
						{
							cout << "\n\tPASSWORD MUST HAVE AT LEAST A LOWER CASE LETTER (a-z)\n\t";
							cout << "Your given password " << passA << " don't have a ";
							cout << "lowercase letter\n\tTRY AGAIN\n";
						}
						else if (error_msg == 5)
						{
							cout << "\n\tPASSWORD MUST HAVE AT LEAST AN UPPER CASE LETTER (A-Z)\n\t";
							cout << "Your given password " << passA << " don't have an ";
							cout << "uppercase letter\n\tTRY AGAIN\n";
						}
						cout << "\tEnter Your password :: ";
						cin >> passA;
						if (passA == "1")
							return;
						cin.ignore(1000, '\n');
						cout << "\tConfirm Your password :: ";
						cin >> passB;
						if (passB == "1")
							return;
						cin.ignore(1000, '\n');
					} while (!chk_pass_ok_or_not(passA, passB, &error_msg));
					temp.Password = passA;
					update_bank_acc_info(temp);
					cout << "\n\tCongratulation !!!";
					cout << "\n\tPassword is changed successfully\n";
					cout << "\tPlease remember '" << temp.Password << "' as your";
					cout << " password for future use.\n\n\tPress Enter to continue... ";
					getchar();
				}
				else
				{
					cout << "\tSORRY! Password recovery Failed\n\t";
					cout << "Press enter to continue... ";
					getchar();
				}
				return;
			}
			else
			{
				cout << "\tSORRY! Password recovery Failed\n\t";
				cout << "Press enter to continue... ";
				getchar();
				return;
			}
		}
	}
}

// Function to show the statement AKA Dashbord

void Show_dashboard(BankAccount temp)
{
	load();
	cout << "\n\n\t|";
	pf('_', 84);
	cout << "|\n\t|";
	pf('.', 35);
	cout << "| DASHBOARD |";
	pf('.', 36);
	cout << "|\n\t|";
	pf('_', 84);
	cout << "|\n\n";
	cout << "\t     1. Account Number   : " << temp.AccountNumber << endl;
	cout << "\t     2. Full Name        : " << temp.FirstName << " " << temp.LastName << endl;
	cout << "\t     3. National ID      : " << temp.NID << endl;
	cout << "\t     4. Contact Number   : " << temp.PhoneNumber << endl;
	cout << "\t     5. Email Address    : " << temp.email << endl;
	cout << "\t     6. Date of Birth    : " << temp.DateOfBirth.day << "/"
		 << temp.DateOfBirth.month << "/" << temp.DateOfBirth.year << endl;
	cout << "\t     7. Password         : " << temp.Password << endl;
	cout << "\t     8. Balance          : " << fixed << setprecision(2) << temp.Balance << "$\n";

	if (temp.LastTransection >= 0.00)
		cout << "\t     9. Last Transection : Credited " << temp.LastTransection << "$ (";
	else
		cout << "\t     9. Last Transection : Debited " << -1.0 * temp.LastTransection << "$ (";
	cout << temp.LastTransectionDate.day << "/" << temp.LastTransectionDate.month << "/"
		 << temp.LastTransectionDate.year << ")\n";

	cout << "\t    10. VIP Status       : ";
	if (temp.Rate >= 0.00)
		cout << "YES ( VIP custom rate = " << temp.Rate << "% )\n";
	else
		cout << "NO\n";
	cout << "\t    11. Account Type     : ";
	if (temp.Type == 1)
		cout << "Savings Account\n";
	else if (temp.Type == 2)
		cout << "Fixed Deposit Account\n";
	else if (temp.Type == 3)
		cout << "Business Account\n";
	cout << "\t    12. A/c Origin Date  : " << temp.InitialDate.day << "/"
		 << temp.InitialDate.month << "/" << temp.InitialDate.year << endl;
	cout << "\t    13. Memorable Date   : " << temp.MemorableDate.day << "/"
		 << temp.MemorableDate.month << "/" << temp.MemorableDate.year << endl;
	cout << "\n\tHere is your statement.\n\t";
	cout << "Press '1' to return to the main menu\n\n\t";
	cout << "Enter your choice :: ";
	string choice;
	bool first = 1;
	do
	{
		if (!first)
		{
			cout << "\n\tINVALID CHOICE\n\tPress '1' to return to main menu\n";
			cout << "\tEnter your choice ('1') >>> ";
		}
		cin >> choice;
		cin.ignore(1000, '\n');
		first = 0;
	} while (choice != "1");
}

// Function to initiate show statement command in menu

void Show_Statement()
{
	load();
	pf('\n', 3);
	cout << "To see your account statement give us the following information\n\n\t";
	string ac_num;
	bool starting = 1;
	do
	{
		if (!starting)
			cout << "\n\tInvalid Account Number\n\t";
		cout << "Press '1' to return to main menu\n";
		cout << "\tEnter your Account number ::  ";
		cin >> ac_num;
		cin.ignore(1000, '\n');
		if (ac_num == "1")
			return;
		starting = 0;
	} while (not_found(ac_num));
	ifstream get_acc("root.txt");
	BankAccount temp;
	while (!get_acc.eof())
	{
		get_acc >> temp.AccountNumber >> temp.Password >> temp.FirstName >> temp.LastName >> temp.NID >> temp.PhoneNumber;
		get_acc >> temp.email >> temp.Balance >> temp.LastTransection >> temp.Rate >> temp.Type >> temp.InitialDate.day;
		get_acc >> temp.InitialDate.month >> temp.InitialDate.year;
		get_acc >> temp.MemorableDate.day >> temp.MemorableDate.month >> temp.MemorableDate.year;
		get_acc >> temp.DateOfBirth.day >> temp.DateOfBirth.month >> temp.DateOfBirth.year;
		get_acc >> temp.LastTransectionDate.day >> temp.LastTransectionDate.month >> temp.LastTransectionDate.year;
		if (temp.AccountNumber == ac_num)
		{
			string passwrd;
			get_acc.close();
			cout << "\n\n\tCongratulation!\n\tAccount Number :: | " << ac_num << " | is Found\n\t";
			cout << "Welcome, " << temp.FirstName << " " << temp.LastName << "\n";
			cout << "\n\tEnter You Password to get logged in to your account\n";
			starting = 1;
			int try_left = 5;
			do
			{
				if (try_left == 0)
				{
					cout << "\n\tSORRY! All your tries are gone\n\n\t";
					cout << "Press Enter to continue...";
					getchar();
					return;
				}
				if (!starting)
					cout << "\tSORRY! Password Didn't Matched\n\tTry Again\n";
				cout << "\n\tPress '1' to return to the main menu\n\t";
				cout << "Press '2' to recover your password\n\t";
				cout << try_left-- << " tries left :)\n";
				cout << "\n\tEnter your password :: ";
				cin >> passwrd;
				cin.ignore(1000, '\n');
				if (passwrd == "1")
					return;
				if (passwrd == "2")
				{
					forget_password();
					return;
				}
				starting = 0;
			} while (passwrd != temp.Password);
			cout << "\n\tCongratulation! Password is matched\n\n\t";
			cout << "Press enter to continue... ";
			cin.ignore(1000, '\n');
			Show_dashboard(temp);
			return;
		}
	}
}

// Function to initiate transection message

void trans_initiate_message()
{
	clr;
	pf('\n', 2);
	cout << " |";
	pf('_', 30);
	cout << "| TRANSECTION MODE |";
	pf('_', 30);
	cout << "|\n\n";
}

// to check if send money is possible or not

bool valid_send_money(string amount_string, long double *amount, long double Balance)
{
	int n = amount_string.size(), i = 0, value = 1;
	*amount = 0.00;

	if (amount_string[0] == '-')
		return 0;

	if (n > 11)
		return 0;

	while (i < n && amount_string[i] == '0')
		i++;

	if (i == n)
	{
		*amount = 0;
		return 0;
	}
	for (int j = n - 1; j >= i; j--)
	{
		if (amount_string[j] < '0' || amount_string[j] > '9')
			return 0;
		*amount += 1.0 * (value * (int)(amount_string[j] - '0'));
		value *= 10;
	}
	if (*amount > Balance)
		return 0;

	if (*amount < 1.0)
		return 0;
	return 1;
}

// Function to count leap year from 0 to d

int countLeapYears(date d)
{
	int years = d.year;

	if (d.month <= 2)
		years--;

	return years / 4 - years / 100 + years / 400;
}

// function to get diffrence between two days

int get_number_of_days(date dt1, date dt2)
{
	int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	long int n1 = dt1.year * 365 + dt1.day;

	for (int i = 0; i < dt1.month - 1; i++)
		n1 += monthDays[i];

	n1 += countLeapYears(dt1);

	long int n2 = dt2.year * 365 + dt2.day;
	for (int i = 0; i < dt2.month - 1; i++)
		n2 += monthDays[i];
	n2 += countLeapYears(dt2);

	return (n2 - n1);
}

// Function to get new Balance of the current account

long double get_new_balance(long double cur_balance, int acc_type, long double vip_rate, int days_spent)
{
	cout << fixed << setprecision(10);
	//show(days_spent);
	long double year_spent = (1.00 * days_spent) / 365.00;
	//show(year_spent);
	if (vip_rate >= 0.00)
	{
		// compound interest of vip_rate% per year
		long double compound_factor = (1.00 + (vip_rate / 100.00));
		return cur_balance * (long double)pow((double)compound_factor, (double)year_spent);
	}
	else if (acc_type == 1)
	{
		// simple interest of 6% per year
		return cur_balance * (1.00 + 0.06 * year_spent);
	}
	else if (acc_type == 2)
	{
		// compound interest of 10% per year
		long double compound_factor = 1.1;
		year_spent = year_spent / 2.0;
		return cur_balance * pow(compound_factor, (long double)(2.0 * (int)year_spent));
	}
	else if (acc_type == 3)
	{
		return cur_balance;
	}
}

// Function to update a bank account information

bool update_bank_acc_info(BankAccount updated_acc)
{
	ifstream get_acc("root.txt");
	ofstream make_acc("temp.txt");
	BankAccount temp;
	while (!get_acc.eof())
	{
		get_acc >> temp.AccountNumber >> temp.Password >> temp.FirstName >> temp.LastName >> temp.NID >> temp.PhoneNumber;
		get_acc >> temp.email >> temp.Balance >> temp.LastTransection >> temp.Rate >> temp.Type >> temp.InitialDate.day;
		get_acc >> temp.InitialDate.month >> temp.InitialDate.year;
		get_acc >> temp.MemorableDate.day >> temp.MemorableDate.month >> temp.MemorableDate.year;
		get_acc >> temp.DateOfBirth.day >> temp.DateOfBirth.month >> temp.DateOfBirth.year;
		get_acc >> temp.LastTransectionDate.day >> temp.LastTransectionDate.month >> temp.LastTransectionDate.year;
		if (temp.AccountNumber == updated_acc.AccountNumber)
		{
			temp.AccountNumber = updated_acc.AccountNumber;
			temp.Password = updated_acc.Password;
			temp.FirstName = updated_acc.FirstName;
			temp.LastName = updated_acc.LastName;
			temp.NID = updated_acc.NID;
			temp.PhoneNumber = updated_acc.PhoneNumber;
			temp.email = updated_acc.email;
			temp.Balance = updated_acc.Balance;
			temp.LastTransection = updated_acc.LastTransection;
			temp.Rate = updated_acc.Rate;
			temp.Type = updated_acc.Type;
			temp.InitialDate.day = updated_acc.InitialDate.day;
			temp.InitialDate.month = updated_acc.InitialDate.month;
			temp.InitialDate.year = updated_acc.InitialDate.year;
			temp.MemorableDate.day = updated_acc.MemorableDate.day;
			temp.MemorableDate.month = updated_acc.MemorableDate.month;
			temp.MemorableDate.year = updated_acc.MemorableDate.year;
			temp.DateOfBirth.day = updated_acc.DateOfBirth.day;
			temp.DateOfBirth.month = updated_acc.DateOfBirth.month;
			temp.DateOfBirth.year = updated_acc.DateOfBirth.year;
			temp.LastTransectionDate.day = updated_acc.LastTransectionDate.day;
			temp.LastTransectionDate.month = updated_acc.LastTransectionDate.month;
			temp.LastTransectionDate.year = updated_acc.LastTransectionDate.year;
		}
		make_acc << '\n'
				 << temp.AccountNumber << " " << temp.Password << " " << temp.FirstName
				 << " " << temp.LastName << " " << temp.NID << " " << temp.PhoneNumber;
		make_acc << " " << temp.email << " " << fixed << setprecision(2) << temp.Balance << " " << temp.LastTransection
				 << " " << temp.Rate << " " << temp.Type << " " << temp.InitialDate.day << " ";
		make_acc << temp.InitialDate.month << " " << temp.InitialDate.year << " ";
		make_acc << temp.MemorableDate.day << " " << temp.MemorableDate.month << " "
				 << temp.MemorableDate.year << " " << temp.DateOfBirth.day << " " << temp.DateOfBirth.month
				 << " " << temp.DateOfBirth.year << " " << temp.LastTransectionDate.day << " ";
		make_acc << temp.LastTransectionDate.month << " " << temp.LastTransectionDate.year;
	}
	get_acc.close();
	make_acc.close();
	if (remove("root.txt") != 0)
		return 0;
	if (rename("temp.txt", "root.txt") != 0)
		return 0;
	return 1;
}

// Function to update internal reciever's account
bool update_bank_acc_info_of_internal_reciever(string ac_num, date x, long double amount)
{
	ifstream get_acc("root.txt");
	ofstream make_acc("temp.txt");
	BankAccount temp;
	while (!get_acc.eof())
	{
		get_acc >> temp.AccountNumber >> temp.Password >> temp.FirstName >> temp.LastName >> temp.NID >> temp.PhoneNumber;
		get_acc >> temp.email >> temp.Balance >> temp.LastTransection >> temp.Rate >> temp.Type >> temp.InitialDate.day;
		get_acc >> temp.InitialDate.month >> temp.InitialDate.year;
		get_acc >> temp.MemorableDate.day >> temp.MemorableDate.month >> temp.MemorableDate.year;
		get_acc >> temp.DateOfBirth.day >> temp.DateOfBirth.month >> temp.DateOfBirth.year;
		get_acc >> temp.LastTransectionDate.day >> temp.LastTransectionDate.month >> temp.LastTransectionDate.year;
		if (temp.AccountNumber == ac_num)
		{
			if (!date_diff(x, temp.LastTransectionDate))
			{
				cout << "Can not do this transection before " << temp.LastTransectionDate.day << "/";
				cout << temp.LastTransectionDate.month << "/" << temp.LastTransectionDate.year << endl;
				get_acc.close();
				make_acc.close();
				remove("temp.txt");
				return 0;
			}
			temp.Balance = get_new_balance(temp.Balance, temp.Type, temp.Rate, get_number_of_days(temp.LastTransectionDate, x));
			temp.Balance = temp.Balance + amount;
			temp.LastTransection = amount;
			temp.LastTransectionDate.day = x.day;
			temp.LastTransectionDate.month = x.month;
			temp.LastTransectionDate.year = x.year;
		}
		make_acc << '\n'
				 << temp.AccountNumber << " " << temp.Password << " " << temp.FirstName
				 << " " << temp.LastName << " " << temp.NID << " " << temp.PhoneNumber;
		make_acc << " " << temp.email << " " << fixed << setprecision(2) << temp.Balance << " " << temp.LastTransection
				 << " " << temp.Rate << " " << temp.Type << " " << temp.InitialDate.day << " ";
		make_acc << temp.InitialDate.month << " " << temp.InitialDate.year << " ";
		make_acc << temp.MemorableDate.day << " " << temp.MemorableDate.month << " "
				 << temp.MemorableDate.year << " " << temp.DateOfBirth.day << " " << temp.DateOfBirth.month
				 << " " << temp.DateOfBirth.year << " " << temp.LastTransectionDate.day << " ";
		make_acc << temp.LastTransectionDate.month << " " << temp.LastTransectionDate.year;
	}
	get_acc.close();
	make_acc.close();
	if (remove("root.txt") != 0)
		return 0;
	if (rename("temp.txt", "root.txt") != 0)
		return 0;
	return 1;
}

// function to send money to an account of this bank

void send_money_to_internal_account(date x, BankAccount temp)
{
	clr;
	trans_initiate_message();
	string sender, reciever, choice;
	temp.Balance = get_new_balance(temp.Balance, temp.Type, temp.Rate, get_number_of_days(temp.LastTransectionDate, x));
	sender = temp.AccountNumber;
	while (1)
	{
		bool starting = 1;
		do
		{
			if (!starting)
				cout << "\n\tInvalid Account Number\n";
			cout << "\tPlease give the account number that you want to sent the money to\n\t";
			cout << "Press '1' to return to main menu\n";
			cout << "\n\tEnter the reciever's account number :: ";
			cin >> reciever;
			cin.ignore(1000, '\n');
			if (reciever == "1")
				return;
			starting = 0;
		} while (not_found(reciever) || reciever == sender);

	again:
		cout << "\tAre you sure to send money to | " << reciever << " | Account";
		cout << "\n\tpress 'Y' to confirm and press 'N' to again enter reciever account number\n";
		cout << "\tEnter your choice :: ";
		cin >> choice;
		cin.ignore(1000, '\n');
		if (choice == "YES" || choice == "Y" || choice == "yes" || choice == "Yes" || choice == "y")
		{
			break;
		}
		else if (choice == "NO" || choice == "N" || choice == "no" || choice == "No" || choice == "n")
		{
			continue;
		}
		else
		{
			cout << "\tInvalid choice\n";
			goto again;
		}
	}
	cout << "\n\tEnter how much money you want to send | ";
	cout << "Balance = " << fixed << setprecision(2) << temp.Balance << " |\n";
	string amount_string;
	long double amount;
	bool starter = 1;
	do
	{
		if (!starter)
		{
			cout << "\n\tInvalid amount\n\tMust enter integer between ";
			cout << "1 to " << (long long)floor(temp.Balance) << "\n";
		}
		cout << "\tEnter the amount you want to send :: ";
		cin >> amount_string;
		cin.ignore(1000, '\n');
		starter = 0;
	} while (!valid_send_money(amount_string, &amount, temp.Balance));
	//cout << "\t Balance before transection = " << fixed << setprecision(2) << temp.Balance << endl;
	temp.Balance = temp.Balance - amount;
	temp.LastTransection = -1.00 * amount;
	temp.LastTransectionDate.day = x.day;
	temp.LastTransectionDate.month = x.month;
	temp.LastTransectionDate.year = x.year;
	if (!update_bank_acc_info_of_internal_reciever(reciever, x, amount))
	{
		cout << "\n\tSomething went wrong...\n\tTRANSECTION FAILED\n";
		return;
	}
	if (!update_bank_acc_info(temp))
		cout << "\n\tSomething went wrong...\n";
}

// Function to send money to an external bank accont

void send_money_to_extarnal_account(date x, BankAccount temp)
{
	clr;
	trans_initiate_message();
	string reciever, choice;
	temp.Balance = get_new_balance(temp.Balance, temp.Type, temp.Rate, get_number_of_days(temp.LastTransectionDate, x));
	while (1)
	{
		cout << "\tPlease give the account number that you want to sent the money to\n";
		cout << "\n\tEnter the reciever's account number :: ";
		cin >> reciever;
		cin.ignore(1000, '\n');
	again:
		cout << "\tAre you sure to send money to | " << reciever << " | Account";
		cout << "\n\tpress 'Y' to confirm and press 'N' to again enter reciever account number\n";
		cout << "\tEnter your choice :: ";
		cin >> choice;
		cin.ignore(1000, '\n');
		if (choice == "YES" || choice == "Y" || choice == "yes" || choice == "Yes" || choice == "y")
		{
			break;
		}
		else if (choice == "NO" || choice == "N" || choice == "no" || choice == "No" || choice == "n")
		{
			continue;
		}
		else
		{
			cout << "\tInvalid choice\n";
			goto again;
		}
	}
	cout << "\n\tEnter how much money you want to send | ";
	cout << "Balance = " << fixed << setprecision(2) << temp.Balance << " |\n";
	string amount_string;
	long double amount;
	bool starter = 1;
	do
	{
		if (!starter)
		{
			cout << "\n\tInvalid amount\n\tMust enter integer between ";
			cout << "1 to " << (long long)floor(temp.Balance) << "\n";
		}
		cout << "\tEnter the amount you want to send :: ";
		cin >> amount_string;
		cin.ignore(1000, '\n');
		starter = 0;
	} while (!valid_send_money(amount_string, &amount, temp.Balance));
	//cout << "\t Balance before transection = " << fixed << setprecision(2) << temp.Balance << endl;
	temp.Balance = temp.Balance - amount;
	temp.LastTransection = -1.00 * amount;
	temp.LastTransectionDate.day = x.day;
	temp.LastTransectionDate.month = x.month;
	temp.LastTransectionDate.year = x.year;
	if (!update_bank_acc_info(temp))
		cout << "\n\tSomething went wrong...\n";
}

// Function to recieve money from other bank to this account

void recieve_money_from_extarnal_account(date x, BankAccount temp)
{
	clr;
	trans_initiate_message();
	string sender, choice;
	while (1)
	{
		cout << "\tPlease give the account number from which you will recieve the money\n";
		cout << "\n\tEnter the sender's account number :: ";
		cin >> sender;
		cin.ignore(1000, '\n');
	again:
		cout << "\tAre you sure to recieve money from | " << sender << " | Account";
		cout << "\n\tpress 'Y' to confirm and press 'N' to again enter sender account number\n";
		cout << "\tEnter your choice :: ";
		cin >> choice;
		cin.ignore(1000, '\n');
		if (choice == "YES" || choice == "Y" || choice == "yes" || choice == "Yes" || choice == "y")
		{
			break;
		}
		else if (choice == "NO" || choice == "N" || choice == "no" || choice == "No" || choice == "n")
		{
			continue;
		}
		else
		{
			cout << "\tInvalid choice\n";
			goto again;
		}
	}
	cout << "\n\tEnter how much money you will recieve\n";
	string amount_string;
	long double amount;
	long long max_amount = 999999999;
	bool starter = 1;
	do
	{
		if (!starter)
		{
			cout << "\n\tInvalid amount\n\tMust enter integer between ";
			cout << "1 to " << max_amount << "\n";
		}
		cout << "\tEnter the amount you will to recieve :: ";
		cin >> amount_string;
		cin.ignore(1000, '\n');
		starter = 0;
	} while (!valid_send_money(amount_string, &amount, max_amount));
	temp.Balance = get_new_balance(temp.Balance, temp.Type, temp.Rate, get_number_of_days(temp.LastTransectionDate, x));
	//cout << "\t Balance before transection = " << fixed << setprecision(2) << temp.Balance << endl;
	temp.Balance = temp.Balance + amount;
	temp.LastTransection = amount;
	temp.LastTransectionDate.day = x.day;
	temp.LastTransectionDate.month = x.month;
	temp.LastTransectionDate.year = x.year;
	if (!update_bank_acc_info(temp))
		cout << "\n\tSomething went wrong...\n";
}

// Function to transfer money from one account given to another unknown

void transection_from_this_account(BankAccount temp)
{
	load();
	trans_initiate_message();
	cout << "\tDear " << temp.FirstName << " " << temp.LastName << ",\n\t";
	cout << "We need to know the date of transection.\n\t";
	cout << "Press '1' to return to main menu\n\n\t";
	bool starter = 1;
	string date_input_string;
	date x;
	do
	{
		if (!starter)
		{
			cout << "\n\tINVALID DATE( date format : **/**/**** )";
			cout << "\n\t The date should be a valid day between 1900-2100\n";
		}
		cout << "\n\tEnter the Date of transection ( example : 01/05/1995 )\n\t>>> ";
		cin >> date_input_string;
		if (date_input_string == "1")
			return;
		cin.ignore(1000, '\n');
		starter = 0;
		if (nice_date(date_input_string, &x))
		{
			if (date_diff(x, temp.LastTransectionDate))
				break;
			else
			{
				cout << "\tYou cannot do this transection transection before | " << temp.LastTransectionDate.day;
				cout << "/" << temp.LastTransectionDate.month << "/" << temp.LastTransectionDate.year << " |\n";
			}
		}
	} while (1);
	cout << "\n\tYou can do any of the following transections : \n\n";
	cout << "\t1 >>> Send money to another account of this bank\n";
	cout << "\t2 >>> Recieve money from an account outside of this bank\n";
	cout << "\t3 >>> Send money to an account outside of this bank\n";
	bool first = 1;
	int inpt;
	string choice;
	do
	{
		if (!first)
			cout << "\tINVALID CHOICE\n";
		cout << "\n\tChoose one from above. Press ( 1 / 2 / 3 )\n\t>>> ";
		cin >> choice;
		cin.ignore(1000, '\n');
		first = 0;
	} while (!valid_acc_type(choice, &inpt));
	if (inpt == 1)
		send_money_to_internal_account(x, temp);
	else if (inpt == 2)
		recieve_money_from_extarnal_account(x, temp);
	else if (inpt == 3)
		send_money_to_extarnal_account(x, temp);
	cout << "\n\tPress Enter to continue... ";
	getchar();
}

// Function to complete transection between two distinct account

void transection()
{
	load();
	trans_initiate_message();
	cout << "\tWelcome to the transection mode.\n\n\t";
	cout << "Please Enter Your Account number to continue...\n\n\t";
	string ac_num;
	bool starting = 1;
	do
	{
		if (!starting)
			cout << "\n\tInvalid Account Number\n\t";
		cout << "Press '1' to return to main menu\n";
		cout << "\tEnter your Account number ::  ";
		cin >> ac_num;
		cin.ignore(1000, '\n');
		if (ac_num == "1")
			return;
		starting = 0;
	} while (not_found(ac_num));
	ifstream get_acc("root.txt");
	BankAccount temp;
	while (!get_acc.eof())
	{
		get_acc >> temp.AccountNumber >> temp.Password >> temp.FirstName >> temp.LastName >> temp.NID >> temp.PhoneNumber;
		get_acc >> temp.email >> temp.Balance >> temp.LastTransection >> temp.Rate >> temp.Type >> temp.InitialDate.day;
		get_acc >> temp.InitialDate.month >> temp.InitialDate.year;
		get_acc >> temp.MemorableDate.day >> temp.MemorableDate.month >> temp.MemorableDate.year >> temp.DateOfBirth.day >> temp.DateOfBirth.month >> temp.DateOfBirth.year;
		get_acc >> temp.LastTransectionDate.day >> temp.LastTransectionDate.month >> temp.LastTransectionDate.year;
		if (temp.AccountNumber == ac_num)
		{
			string passwrd;
			get_acc.close();
			cout << "\n\n\tCongratulation!\n\tAccount Number :: | " << ac_num << " | is Found\n\t";
			cout << "Welcome, " << temp.FirstName << " " << temp.LastName << "\n";
			cout << "\n\tEnter You Password to get logged in to your account\n";
			starting = 1;
			int try_left = 5;
			do
			{
				if (try_left == 0)
				{
					cout << "\n\tSORRY! All your tries are gone\n\n\t";
					cout << "Press Enter to continue...";
					getchar();
					return;
				}
				if (!starting)
					cout << "\tSORRY! Password Didn't Matched\n\tTry Again\n";
				cout << "\n\tPress '1' to return to the main menu\n\t";
				cout << "Press '2' to recover your password\n\t";
				cout << try_left-- << " tries left :)\n";
				cout << "\n\tEnter your password :: ";
				cin >> passwrd;
				cin.ignore(1000, '\n');
				if (passwrd == "1")
					return;
				if (passwrd == "2")
				{
					forget_password();
					return;
				}
				starting = 0;
			} while (passwrd != temp.Password);
			cout << "\n\tCongratulation! Password is matched\n\n\t";
			cout << "Press enter to continue... ";
			getchar();
			transection_from_this_account(temp);
			return;
		}
	}
}

// function to check for valid choice in the update user info mode

bool valid_choice_cng(string s)
{
	if (s == "1")
		return 1;
	if (s == "2")
		return 1;
	if (s == "3")
		return 1;
	if (s == "4")
		return 1;
	if (s == "5")
		return 1;
	if (s == "6")
		return 1;
	return 0;
}

// function to show initiate message for update user info mode

void edit_info_message()
{
	clr;
	pf('\n', 2);
	cout << " |";
	pf('_', 30);
	cout << "| EDIT INFO MODE |";
	pf('_', 30);
	cout << "|\n\n";
}

// function to edit user information

void edit_user_info()
{
	load();
	edit_info_message();
	cout << "\tWelcome to the information editing mode.\n\n\t";
	cout << "Please Enter Your Account number to continue...\n\n\t";
	string ac_num;
	bool starting = 1;
	do
	{
		if (!starting)
			cout << "\n\tInvalid Account Number\n\t";
		cout << "Press '1' to return to main menu\n";
		cout << "\tEnter your Account number ::  ";
		cin >> ac_num;
		cin.ignore(1000, '\n');
		if (ac_num == "1")
			return;
		starting = 0;
	} while (not_found(ac_num));
	ifstream get_acc("root.txt");
	BankAccount temp;
	while (!get_acc.eof())
	{
		get_acc >> temp.AccountNumber >> temp.Password >> temp.FirstName >> temp.LastName >> temp.NID >> temp.PhoneNumber;
		get_acc >> temp.email >> temp.Balance >> temp.LastTransection >> temp.Rate >> temp.Type >> temp.InitialDate.day;
		get_acc >> temp.InitialDate.month >> temp.InitialDate.year;
		get_acc >> temp.MemorableDate.day >> temp.MemorableDate.month >> temp.MemorableDate.year >> temp.DateOfBirth.day >> temp.DateOfBirth.month >> temp.DateOfBirth.year;
		get_acc >> temp.LastTransectionDate.day >> temp.LastTransectionDate.month >> temp.LastTransectionDate.year;
		if (temp.AccountNumber == ac_num)
		{
			string passwrd;
			get_acc.close();
			cout << "\n\n\tCongratulation!\n\tAccount Number :: | " << ac_num << " | is Found\n\t";
			cout << "Welcome, " << temp.FirstName << " " << temp.LastName << "\n";
			cout << "\n\tEnter You Password to get logged in to your account\n";
			starting = 1;
			int try_left = 5;
			do
			{
				if (try_left == 0)
				{
					cout << "\n\tSORRY! All your tries are gone\n\n\t";
					cout << "Press Enter to continue...";
					getchar();
					return;
				}
				if (!starting)
					cout << "\tSORRY! Password Didn't Matched\n\tTry Again\n";
				cout << "\n \tPress '1' to return to the main menu\n\t";
				cout << "press '2' to reset the password\n\t";
				cout << try_left-- << " tries left :)\n";
				cout << "\n\tEnter your password :: ";
				cin >> passwrd;
				cin.ignore(1000, '\n');
				if (passwrd == "1")
					return;
				if (passwrd == "2")
				{
					forget_password();
					return;
				}
				starting = 0;
			} while (passwrd != temp.Password);
			cout << "\n\tCongratulation! Password is matched\n\n\t";
			cout << "Press enter to continue... ";
			getchar();
			string choice;
			bool starter;
			while (1)
			{
				edit_info_message();
				cout << "\t1. First Name      : " << temp.FirstName << endl;
				cout << "\t2. Last Name       : " << temp.LastName << endl;
				cout << "\t3. Contact Number  : " << temp.PhoneNumber << endl;
				cout << "\t4. Email Address   : " << temp.email << endl;
				cout << "\t5. Memorable Date  : " << temp.MemorableDate.day << "/" << temp.MemorableDate.month << "/" << temp.MemorableDate.year << endl;
				cout << "\t6. Save and EXIT to the main menu\n";

				cout << "\n\n\tChoose which one of the above info you want to change...\n\t";
				cout << "AND PRESS 6 to save the cnages and return to the main menu\n\n\t";
				starter = 1;
				do
				{
					if (!starter)
					{
						cout << "\n\tINVAILD CHOICE\n\t";
						cout << "You must enter an integer between (1-6)\n\n\t";
					}
					cout << "Enter your choice : ";
					cin >> choice;
					cin.ignore(1000, '\n');
					starter = 0;
				} while (!valid_choice_cng(choice));
				if (choice == "1")
				{
					cout << "\n\tEnter New First Name : ";
					cin >> temp.FirstName;
					cin.ignore(1000, '\n');
					cout << "\n\n\tYour First name successfully changed to " << temp.FirstName;
					cout << "\n\n\tPress ENTER to contine... ";
					getchar();
				}
				else if (choice == "2")
				{
					cout << "\n\tEnter New Last Name : ";
					cin >> temp.LastName;
					cin.ignore(1000, '\n');
					cout << "\n\n\tYour Last name successfully changed to " << temp.LastName;
					cout << "\n\n\tPress ENTER to contine... ";
					getchar();
				}
				else if (choice == "3")
				{
					string name;
					starter = 1;
					do
					{
						if (!starter)
							cout << "\n\tINVALID Phone Number( Should have only digits 0-9 )";
						cout << "\n\tEnter your new Phone number :: +";
						cin >> name;
						cin.ignore(1000, '\n');
						starter = 0;
					} while (!correct_phone_number(name));
					temp.PhoneNumber = "+";
					temp.PhoneNumber += name;
				}
				else if (choice == "4")
				{
					string name;
					starter = 1;
					do
					{
						if (!starter)
							cout << "\n\tINVALID email address\n\tTRY AGAIN";
						cout << "\n\tYour email address :: ";
						cin >> name;
						cin.ignore(1000, '\n');
						starter = 0;
					} while (!correct_email_address(name));
					temp.email = name;
				}
				else if (choice == "5")
				{
					date x;
					string name;
					starter = 1;
					do
					{
						if (!starter)
						{
							cout << "\n\tINVALID DATE( date format : **/**/**** )";
							cout << "\n\t The date should be a valid day between 1900-2100\n";
						}
						cout << "\n\tEnter Your New Most memorable date ( example : 01/05/1995 )\n\t>>> ";
						cin >> name;
						cin.ignore(1000, '\n');
						starter = 0;
					} while (!nice_date(name, &x));
					temp.MemorableDate = x;
				}
				else if (choice == "6")
				{
					update_bank_acc_info(temp);
					return;
				}
			}
			return;
		}
	}
}

// function to show initiate bill message

void pay_bill_initiate_message()
{
	clr;
	pf('\n', 2);
	cout << " |";
	pf('_', 30);
	cout << "| PAY BILL MODE |";
	pf('_', 30);
	cout << "|\n\n";
}

// function to pay bill from a user at a x date

void pay_bill_at_this_date(date x, BankAccount temp)
{
	clr;
	pay_bill_initiate_message();
	string reciever, choice;
	temp.Balance = get_new_balance(temp.Balance, temp.Type, temp.Rate, get_number_of_days(temp.LastTransectionDate, x));
	while (1)
	{
		cout << "\tPlease give the merchant account number that you want to sent the money to\n";
		cout << "\n\tEnter the merchant's account number :: ";
		cin >> reciever;
		cin.ignore(1000, '\n');
	again:
		cout << "\tAre you sure to send money to | " << reciever << " | Account";
		cout << "\n\tpress 'Y' to confirm and press 'N' to again enter reciever account number\n";
		cout << "\tEnter your choice :: ";
		cin >> choice;
		cin.ignore(1000, '\n');
		if (choice == "YES" || choice == "Y" || choice == "yes" || choice == "Yes" || choice == "y")
		{
			break;
		}
		else if (choice == "NO" || choice == "N" || choice == "no" || choice == "No" || choice == "n")
		{
			continue;
		}
		else
		{
			cout << "\tInvalid choice\n";
			goto again;
		}
	}
	cout << "\n\tEnter how much money you want to send | ";
	cout << "Balance = " << fixed << setprecision(2) << temp.Balance << " |\n";
	string amount_string;
	long double amount;
	bool starter = 1;
	do
	{
		if (!starter)
		{
			cout << "\n\tInvalid amount\n\tMust enter integer between ";
			cout << "1 to " << (long long)floor(temp.Balance) << "\n";
		}
		cout << "\tEnter the amount you want to send :: ";
		cin >> amount_string;
		cin.ignore(1000, '\n');
		starter = 0;
	} while (!valid_send_money(amount_string, &amount, temp.Balance));
	//cout << "\t Balance before transection = " << fixed << setprecision(2) << temp.Balance << endl;
	temp.Balance = temp.Balance - amount;
	temp.LastTransection = -1.00 * amount;
	temp.LastTransectionDate.day = x.day;
	temp.LastTransectionDate.month = x.month;
	temp.LastTransectionDate.year = x.year;
	if (!update_bank_acc_info(temp))
		cout << "\n\tSomething went wrong...\n";
}

// Function to pay bill from this account

void pay_bill_from_this_account(BankAccount temp)
{
	load();
	pay_bill_initiate_message();
	cout << "\tDear " << temp.FirstName << " " << temp.LastName << ",\n\t";
	cout << "We need to know the date of bill payment.\n\t";
	cout << "Press '1' to return to main menu\n\n\t";
	bool starter = 1;
	string date_input_string;
	date x;
	do
	{
		if (!starter)
		{
			cout << "\n\tINVALID DATE( date format : **/**/**** )";
			cout << "\n\t The date should be a valid day between 1900-2100\n";
		}
		cout << "\n\tEnter the Date of bill payment ( example : 01/05/1995 )\n\t>>> ";
		cin >> date_input_string;
		if (date_input_string == "1")
			return;
		cin.ignore(1000, '\n');
		starter = 0;
		if (nice_date(date_input_string, &x))
		{
			if (date_diff(x, temp.LastTransectionDate))
				break;
			else
			{
				cout << "\tYou cannot do this transection transection before | " << temp.LastTransectionDate.day;
				cout << "/" << temp.LastTransectionDate.month << "/" << temp.LastTransectionDate.year << " |\n";
			}
		}
	} while (1);
	pay_bill_at_this_date(x, temp);
	cout << "\n\tPress Enter to continue... ";
	getchar();
}

// Function to initiate pay bill

void pay_bill()
{
	load();
	pay_bill_initiate_message();
	cout << "\tWelcome to the pay bill mode.\n\n\t";
	cout << "Please Enter Your Account number to continue...\n\n\t";
	string ac_num;
	bool starting = 1;
	do
	{
		if (!starting)
			cout << "\n\tInvalid Account Number\n\t";
		cout << "Press '1' to return to main menu\n";
		cout << "\tEnter your Account number ::  ";
		cin >> ac_num;
		cin.ignore(1000, '\n');
		if (ac_num == "1")
			return;
		starting = 0;
	} while (not_found(ac_num));
	ifstream get_acc("root.txt");
	BankAccount temp;
	while (!get_acc.eof())
	{
		get_acc >> temp.AccountNumber >> temp.Password >> temp.FirstName >> temp.LastName >> temp.NID >> temp.PhoneNumber;
		get_acc >> temp.email >> temp.Balance >> temp.LastTransection >> temp.Rate >> temp.Type >> temp.InitialDate.day;
		get_acc >> temp.InitialDate.month >> temp.InitialDate.year;
		get_acc >> temp.MemorableDate.day >> temp.MemorableDate.month >> temp.MemorableDate.year >> temp.DateOfBirth.day >> temp.DateOfBirth.month >> temp.DateOfBirth.year;
		get_acc >> temp.LastTransectionDate.day >> temp.LastTransectionDate.month >> temp.LastTransectionDate.year;
		if (temp.AccountNumber == ac_num)
		{
			string passwrd;
			get_acc.close();
			cout << "\n\n\tCongratulation!\n\tAccount Number :: | " << ac_num << " | is Found\n\t";
			cout << "Welcome, " << temp.FirstName << " " << temp.LastName << "\n";
			cout << "\n\tEnter You Password to get logged in to your account\n";
			starting = 1;
			int try_left = 5;
			do
			{
				if (try_left == 0)
				{
					cout << "\n\tSORRY! All your tries are gone\n\n\t";
					cout << "Press Enter to continue...";
					getchar();
					return;
				}
				if (!starting)
					cout << "\tSORRY! Password Didn't Matched\n\tTry Again\n";
				cout << "\n\tPress '1' to return to the main menu\n\t";
				cout << "Press '2' to recover your password\n\t";
				cout << try_left-- << " tries left :)\n";
				cout << "\n\tEnter your password :: ";
				cin >> passwrd;
				cin.ignore(1000, '\n');
				if (passwrd == "1")
					return;
				if (passwrd == "2")
				{
					forget_password();
					return;
				}
				starting = 0;
			} while (passwrd != temp.Password);
			cout << "\n\tCongratulation! Password is matched\n\n\t";
			cout << "Press enter to continue... ";
			getchar();
			pay_bill_from_this_account(temp);
			return;
		}
	}
}

// Function to get all the bank info

void get_num_of_acc(int *savings_acc, int *fdr_acc, int *buss_acc, int *vip_acc, long double *tot)
{
	(*savings_acc) = (*fdr_acc) = (*buss_acc) = (*vip_acc) = 0;
	(*tot) = 0.0;
	ifstream get_acc("root.txt");
	BankAccount temp;
	while (!get_acc.eof())
	{
		get_acc >> temp.AccountNumber >> temp.Password >> temp.FirstName >> temp.LastName >> temp.NID >> temp.PhoneNumber;
		get_acc >> temp.email >> temp.Balance >> temp.LastTransection >> temp.Rate >> temp.Type >> temp.InitialDate.day;
		get_acc >> temp.InitialDate.month >> temp.InitialDate.year;
		get_acc >> temp.MemorableDate.day >> temp.MemorableDate.month >> temp.MemorableDate.year;
		get_acc >> temp.DateOfBirth.day >> temp.DateOfBirth.month >> temp.DateOfBirth.year;
		get_acc >> temp.LastTransectionDate.day >> temp.LastTransectionDate.month >> temp.LastTransectionDate.year;
		if (temp.Rate >= 0.0)
		{
			(*vip_acc)++;
		}
		else
		{
			if (temp.Type == 1)
				(*savings_acc)++;
			else if (temp.Type == 2)
				(*fdr_acc)++;
			else if (temp.Type == 3)
				(*buss_acc)++;
		}
		(*tot) += temp.Balance;
	}
	get_acc.close();
}

// function to show bank status

void show_bank_status()
{
	load();
	cout << "\n\n";
	pf('>', 40);
	cout << "| BANK STATUS |";
	pf('<', 41);
	cout << "\n";
	pf('_', 96);
	cout << "\n|";
	pf('_', 36);
	cout << "| Bank Interest Rate |";
	pf('_', 36);
	cout << "|\n";
	pf('~', 96);
	cout << "\n\n";
	cout << "  1) Savings Account       : 6% Simple rate        ~ (No Mature date)\n";
	cout << "  2) Fixed Deposit Account : 10% Compound rate     ~ (Mature after each 2 years)\n";
	cout << "  3) Business Account      : No Interest           ~ (Used for business transections)\n";
	cout << "  4) VIP account           : (0-20)% Compound rate ~ (No Mature date)\n\n";
	pf('_', 96);
	cout << "\n|";
	pf('_', 36);
	cout << "| Total Amount Stat |";
	pf('_', 37);
	cout << "|\n";
	pf('~', 96);
	cout << "\n\n";
	int savings_acc = 0, fdr_acc = 0, buss_acc = 0, vip_acc = 0;
	long double tot = 0;
	get_num_of_acc(&savings_acc, &fdr_acc, &buss_acc, &vip_acc, &tot);
	cout << "  1) Number of Savings Acount        : " << savings_acc << endl;
	cout << "  2) Number of Fixed Deposit Account : " << fdr_acc << endl;
	cout << "  3) Number of Business Account      : " << buss_acc << endl;
	cout << "  4) Number of VIP Account           : " << vip_acc << endl;
	cout << "     So, In total = " << savings_acc + fdr_acc + buss_acc + vip_acc << " Accounts\n\n";
	pf('~', 96);
	ENTER;
	pf(' ', 49);
	cout << "Total Reserve Of the Bank : " << fixed << setprecision(2) << tot << "$\n\n\t";
	cout << "Press '1' to return to the main menu\n\n\t";
	cout << "Enter your choice :: ";
	string choice;
	bool first = 1;
	do
	{
		if (!first)
		{
			cout << "\n\tINVALID CHOICE\n\tPress '1' to return to main menu\n";
			cout << "\tEnter your choice ('1') >>> ";
		}
		cin >> choice;
		cin.ignore(1000, '\n');
		first = 0;
	} while (choice != "1");
}

// Function to delete a perticuler bank account

bool delete_this_acc(BankAccount updated_acc)
{
	ifstream get_acc("root.txt");
	ofstream make_acc("temp.txt");
	BankAccount temp;
	while (!get_acc.eof())
	{
		get_acc >> temp.AccountNumber >> temp.Password >> temp.FirstName >> temp.LastName >> temp.NID >> temp.PhoneNumber;
		get_acc >> temp.email >> temp.Balance >> temp.LastTransection >> temp.Rate >> temp.Type >> temp.InitialDate.day;
		get_acc >> temp.InitialDate.month >> temp.InitialDate.year;
		get_acc >> temp.MemorableDate.day >> temp.MemorableDate.month >> temp.MemorableDate.year;
		get_acc >> temp.DateOfBirth.day >> temp.DateOfBirth.month >> temp.DateOfBirth.year;
		get_acc >> temp.LastTransectionDate.day >> temp.LastTransectionDate.month >> temp.LastTransectionDate.year;
		if (temp.AccountNumber == updated_acc.AccountNumber)
		{
			continue;
		}
		make_acc << '\n'
				 << temp.AccountNumber << " " << temp.Password << " " << temp.FirstName
				 << " " << temp.LastName << " " << temp.NID << " " << temp.PhoneNumber;
		make_acc << " " << temp.email << " " << fixed << setprecision(2) << temp.Balance << " " << temp.LastTransection
				 << " " << temp.Rate << " " << temp.Type << " " << temp.InitialDate.day << " ";
		make_acc << temp.InitialDate.month << " " << temp.InitialDate.year << " ";
		make_acc << temp.MemorableDate.day << " " << temp.MemorableDate.month << " "
				 << temp.MemorableDate.year << " " << temp.DateOfBirth.day << " " << temp.DateOfBirth.month
				 << " " << temp.DateOfBirth.year << " " << temp.LastTransectionDate.day << " ";
		make_acc << temp.LastTransectionDate.month << " " << temp.LastTransectionDate.year;
	}
	get_acc.close();
	make_acc.close();
	if (remove("root.txt") != 0)
		return 0;
	if (rename("temp.txt", "root.txt") != 0)
		return 0;
	get_acc.open("index.txt");
	make_acc.open("temp.txt");
	string ac_num;
	while (!get_acc.eof())
	{
		get_acc >> ac_num;
		if (ac_num == updated_acc.AccountNumber)
		{
			continue;
		}
		make_acc << ac_num << '\n';
	}
	get_acc.close();
	make_acc.close();
	if (remove("index.txt") != 0)
		return 0;
	if (rename("temp.txt", "index.txt") != 0)
		return 0;
	return 1;
}

// Function to delete an account

void delete_account()
{
	load();
	pf('\n', 3);
	cout << "To delete your account give us the following information\n\n\t";
	string ac_num;
	bool starting = 1;
	do
	{
		if (!starting)
			cout << "\n\tInvalid Account Number\n\t";
		cout << "Press '1' to return to main menu\n";
		cout << "\tEnter your Account number ::  ";
		cin >> ac_num;
		cin.ignore(1000, '\n');
		if (ac_num == "1")
			return;
		starting = 0;
	} while (not_found(ac_num));
	ifstream get_acc("root.txt");
	BankAccount temp;
	while (!get_acc.eof())
	{
		get_acc >> temp.AccountNumber >> temp.Password >> temp.FirstName >> temp.LastName >> temp.NID >> temp.PhoneNumber;
		get_acc >> temp.email >> temp.Balance >> temp.LastTransection >> temp.Rate >> temp.Type >> temp.InitialDate.day;
		get_acc >> temp.InitialDate.month >> temp.InitialDate.year;
		get_acc >> temp.MemorableDate.day >> temp.MemorableDate.month >> temp.MemorableDate.year;
		get_acc >> temp.DateOfBirth.day >> temp.DateOfBirth.month >> temp.DateOfBirth.year;
		get_acc >> temp.LastTransectionDate.day >> temp.LastTransectionDate.month >> temp.LastTransectionDate.year;
		if (temp.AccountNumber == ac_num)
		{
			string passwrd;
			get_acc.close();
			cout << "\n\n\tCongratulation!\n\tAccount Number :: | " << ac_num << " | is Found\n\t";
			cout << "Welcome, " << temp.FirstName << " " << temp.LastName << "\n";
			cout << "\n\tEnter You Password to get logged in to your account\n";
			starting = 1;
			int try_left = 5;
			do
			{
				if (try_left == 0)
				{
					cout << "\n\tSORRY! All your tries are gone\n\n\t";
					cout << "Press Enter to continue...";
					cin.ignore(1000, '\n');
					return;
				}
				if (!starting)
					cout << "\tSORRY! Password Didn't Matched\n\tTry Again\n";
				cout << "\n\tPress '1' to return to the main menu\n\t";
				cout << "Press '2' to recover your password\n\t";
				cout << try_left-- << " tries left :)\n";
				cout << "\n\tEnter your password :: ";
				cin >> passwrd;
				cin.ignore(1000, '\n');
				if (passwrd == "1")
					return;
				if (passwrd == "2")
				{
					forget_password();
					return;
				}
				starting = 0;
			} while (passwrd != temp.Password);
			cout << "\n\tCongratulation! Password is matched\n\n\t";
			cout << "Press enter to continue... ";
			cin.ignore(1000, '\n');
			clr;
			cout << "\n\n\tARE YOU SURE TO DELETE YOUR ACCOUNT!\n\n\t";
			cout << "You will get " << temp.Balance << "$ after the deletation\n\n";
			cout << "\tPress 'Y' to say YES and press 'N' to say NO\n";
			cout << "\tEnter your choice (Y/N) >>> ";
			string choice;
			bool first = 1;
			do
			{
				if (!first)
				{
					cout << "\n\tINVALID CHOICE\n\tPress 'Y' to say YES and press 'N' to say NO\n";
					cout << "\tEnter your choice (Y/N) >>> ";
				}
				cin >> choice;
				if (choice == "1")
					return;
				cin.ignore(1000, '\n');
				if (choice == "y" || choice == "Y" || choice == "YES" || choice == "yes" || choice == "Yes")
				{
					if (delete_this_acc(temp))
					{
						cout << "\n\tAccount Number - '" << temp.AccountNumber << "' has been deleted successfully\n";
						cout << "\n\tPress enter to continue... ";
						cin.ignore(1000, '\n');
					}
					else
					{
						cout << "\n\tSomething went wrong\n";
						cout << "\n\tPress enter to continue... ";
						cin.ignore(1000, '\n');
					}
					return;
				}
				else if (choice == "n" || choice == "N" || choice == "NO" || choice == "no" || choice == "No")
				{
					return;
				}
				first = 0;
			} while (1);
		}
	}
}

// Function to show about the app

void about()
{
	load();
	cout << "\n\n________________________________________| ABOUT THIS APP |_________________________________________";
	cout << "\n\n\n\tFirst of all, This is a console-based app which I developed using C++ 11.\n";
	cout << "\tIn This App, one can have the basic functionality of a bank.";
	cout << "\n\tThis app can create a new bank account by taking the necessary information from the user.";
	cout << "\n\tThe speciality of this app is that it can handle the exception very well.";
	cout << "\n\tI tried to make it as interactive and stable as possible.";
	cout << "\n\tThis app also ensures the security of the users.";
	cout << "\n\tOne can customize their information at any time using their password.";
	cout << "\n\tAnd also one can delete their account anytime.\n";
	cout << "\n\tThis app is also capable of doing transections of several types.";
	cout << "\n\tIt also has several types of accounts. Those accounts have their unique features.";
	cout << "\n\tIt also can calculate all the interest and financial calculations needed.";
	cout << "\n\tIt can show the overall banking information too.";
	cout << "\n\tOne can also see their statement anytime as they wish.\n";
	cout << "\n\tHopefully, You will definitely like my app.";
	cout << "\n\tPlease let me know if you got any bugs or any suggestion to improve the app.";
	cout << "\n\tI also added all the other information as text files in the GitHub.\n";
	cout << "\tYou can check those to get detail information.\n";
	cout << "\n\tThe skills I gained after making this app:\n";
	cout << "\t- Maintaining Huge codes";
	cout << "\n\t- File Handling";
	cout << "\n\t- Exception Handling";
	cout << "\n\t- Interface Planning";
	cout << "\n\n\tPress '1' to return to the main menu\n\n\t";
	cout << "Enter your choice :: ";
	string choice;
	bool first = 1;
	do
	{
		if (!first)
		{
			cout << "\n\tINVALID CHOICE\n\tPress '1' to return to main menu\n";
			cout << "\tEnter your choice ('1') >>> ";
		}
		cin >> choice;
		cin.ignore(1000, '\n');
		first = 0;
	} while (choice != "1");
}