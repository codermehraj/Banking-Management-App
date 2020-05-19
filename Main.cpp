/* ~CoderMehRaj~ */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
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
void ani2();
void Hit_with_a_nyx_logo_to_flex_up();
void animate_seq_fn(vector < int > &seq);

/// The main Function

int main(){
    initiate_app_environment();
    return 0;
}

void load(){
    clr;
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

void animate_seq_fn(vector < int > &seq){
    string What_To_Print="0 ";
    int indx=0;
    while(seq[indx]>=0) {
        pf(What_To_Print[indx%2],seq[indx]);
        indx++;
    }
}

void ani_2(){
    vector < int > seq;
    rep(3) ENTER
    rep(10){
        /// Print codes for printing "BANKING"
        cout<<"\t";
        if(i==1) seq={9,4,10,3,4,7,3,2,3,4,3,2,3,2,4,7,3,3,10,-1};
        else if(i==2) seq={10,2,12,2,5,6,3,2,3,3,3,3,3,2,5,6,3,2,12,-1};
        else if(i==3) seq={2,6,2,2,3,6,3,2,6,5,3,2,3,2,3,4,3,2,6,5,3,2,3,6,3,-1};
        else if(i==4) seq={2,6,2,2,3,6,3,2,3,1,3,4,3,2,3,1,3,5,3,2,6,5,3,2,3,6,3,-1};
        else if(i==5) seq={9,3,3,6,3,2,3,2,3,3,3,2,6,6,3,2,3,2,3,3,3,2,3,-1};
        else if(i==6) seq={9,3,12,2,3,3,3,2,3,2,6,6,3,2,3,3,3,2,3,2,3,3,5,-1};
        else if(i==7) seq={2,6,2,2,12,2,3,4,3,1,3,2,3,1,3,5,3,2,3,4,3,1,3,2,3,3,2,1,3,-1};
        else if(i==8) seq={2,6,2,2,3,6,3,2,3,5,6,2,3,2,3,4,3,2,3,5,6,2,3,6,3,-1};
        else if(i==9) seq={10,2,3,6,3,2,3,6,5,2,3,3,3,3,3,2,3,6,5,2,12,-1};
        else if(i==10) seq={9,3,3,6,3,2,3,7,4,2,3,4,3,2,3,2,3,7,4,3,10,-1};
        animate_seq_fn(seq);
        seq.clear();
        ENTER
    }
    rep(2) ENTER
    rep(10){
        /// Print codes for printing "APP"
        if(i==1) seq={0,23,10,4,10,4,10,-1};
        else if(i==2) seq={0,22,12,2,12,2,12,7,-1};
        else if(i==3 || i==4) seq={0,22,3,6,3,2,3,6,3,2,3,6,3,3,-1};
        else if(i==5) seq={0,22,3,6,3,2,12,2,12,3,-1};
        else if(i==6) seq={0,22,12,2,11,3,11,4,-1};
        else if(i==7) seq={0,22,12,2,3,11,3,12,-1};
        else if(i==8) seq={0,22,3,6,3,2,3,11,3,12,-1};
        else if(i==9) seq={0,22,3,6,3,2,3,11,3,12,-1};
        else if(i==10) seq={0,22,3,6,3,2,3,11,3,12,-1};
        animate_seq_fn(seq);
        if(i==2)
            { pf("< Made By >",1); }
        else if(i==3||i==10)
            { pf('~',21); }
        else if(i==4)
            { pf("| MehRajul",1); pf(' ',10); pf('|',1); }
        else if(i==5)
            { pf("|    Islam",1); pf(' ',10); pf('|',1); }
        else if(i==6)
            { pf("|       SUST",1); pf(' ',8); pf('|',1); }
        else if(i==7)
            { pf("|     Software",1); pf(' ',6); pf('|',1); }
        else if(i==8)
            { pf("|",1); pf(' ',7); pf("Engineering |",1); }
        else if(i==9)
            { pf("|",1); pf(' ',15); pf("'19.|",1); }

        seq.clear();
        ENTER
    }
    pf("\n",4);
    pf("\t",4);
    pf("Press enter to continue...",1);
    getchar();
}

void Hit_with_a_nyx_logo_to_flex_up(){
    ani();
    load();
    ani_2();
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
    load();
    Hit_with_a_nyx_logo_to_flex_up();
    load();
}
