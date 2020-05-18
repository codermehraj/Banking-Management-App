/* ~CoderMehRaj~ */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>

using namespace std;

/// Preprocessor declarations ~ Macros

#define show(x) cout << #x << " = " << x << '\n';
#define loop(x,i,j) for(int x = i ; x <= (j) ; x++ )
#define rep(n) for(int i=1;i<=n;i++)
#define clr system("cls");
#define w8 Sleep(200)
#define pf(ch,kkk) loop(kk,1,kkk) cout<<ch;
#define ENTER cout<<'\n';

/// Function Prototypes

void initiate_app_environment();
void load();
void ani();
void Hit_with_a_nyx_logo_to_flex_up();

/// The main Function

int main(){
    initiate_app_environment();
    return 0;
}

void ani(){
    char p=(char)177;
    rep(3)  cout<<"\n";
    rep(20){
        if(i==1){ pf(' ',11); pf(p,6); }
		else if( i == 9 ) { pf(' ',9); pf(p,31); }
		else{
            pf(' ',15); pf(p,2);
            if(i==12) { pf(' ',13); pf(p,7); }
            else if(i==13) { pf(' ',13); pf(p,2); pf(' ',3); pf(p,2); }
            else if(i==14) {
                pf(' ',4); pf("THE",1); pf(' ',6); pf(p,3); pf(' ',2); pf(p,2);
            }
            else if(i==15) {
                pf(' ',4); pf("BANKING",1); pf(' ',7); pf(p,2);
            }
            else if(i==16) {
                pf(' ',8); pf("APP",1); pf(' ',7); pf(p,2);
            }
            else if(i==17 || i==19) { pf(' ',18); pf(p,2); }
            else if(i==18) {
                pf(' ',3); pf("By ~ MehRaj",1); pf(' ',4); pf(p,2);
            }
            else if(i==20) pf(p,20);
		}
        if(i%2) Sleep(80);
        ENTER
    }
    rep(3) ENTER
    pf("\t\tPress Enter to continue...",1);
    getchar();
}

void load(){
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t  LOADING...\n\t\t   ");
    for(int r=1;r<=40;r++){
    for(int q=0;q<=20000000;q++);//to display the character slowly
        printf("%c",177);
    }
    clr;
    printf("\n\n\n\n\n\n\n\n\n\n\t\t\t  ~~~ DONE LOADING ~~~\n\n\t\t   ");

    cout<<"\n\n\n\t\t\tpress enter to continue...";
    getchar();
    clr;
}

void Hit_with_a_nyx_logo_to_flex_up(){
    ani();
}

void initiate_app_environment(){
    rep(4) cout<<"\n";
    cout<<"\t"<<"Welcome to The Banking Management App\n";
    Sleep(400);
    cout<<"\t   "<<"Please Maximize Your Screen :P\n\n";
    cout<<"\t    "<<"You may try < ALT + ENTER >\n\n";
    Sleep(300);
    cout<<"\t   "<<"Press enter to continue...";
    getchar();
    clr;
    load();
    clr;
    Hit_with_a_nyx_logo_to_flex_up();
}
