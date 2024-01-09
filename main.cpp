#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#define DIM 3
#define T 9
using namespace std;

//prototipi

void carica(char mat[][DIM], bool stato[][DIM]) ;

void visua(char mat[][DIM]) ;

bool win(char mat[][DIM], bool stato[][DIM]) ;

void game(char mat[][DIM], bool stato[][DIM]) ;

//dichiarazione globale

char mat[DIM][DIM];
bool stato[DIM][DIM];


int main() {
    srand(time(NULL));
    setlocale(LC_ALL,"italian");
    char risp;
    do{
        carica(mat,stato);
        game(mat,stato);
        cout<<"Vuoi continuare?(S per sì, N per no)"<<endl;
        cin>>risp;
        risp=toupper(risp);
    } while(risp=='S');
}

void start(string & t1, string & t2) {
    string g1, g2;
    int sce, x;
    cout<<"___________________"<<endl;
    cout<<"|Benvenuto in tris!|"<<endl;
    cout<<"___________________"<<endl;
    cout<<"Digita il nome del primo giocatore(giocherà con la X)"<<endl;
    getline(cin,g1);
    cout<<"Digita il nome del secondo giocatore(giocherà con la O)"<<endl;
    getline(cin,g2);
    cout<<"Chi vuole iniziare?"<<endl<<"Digita: "<<endl<<"1. per far iniziare "<<g1<<endl<<"2. per far iniziare "<<g2<<endl<<"3. per generarlo casualmente"<<endl<<"Cosa scegli?"<<endl;
    cin>>sce;
    while(sce<1 || sce>4) {
        cout<<"Errore, inserire un numero corretto."<<endl;
        cin>>sce;
    }
    switch(sce) {
    case 1:
        t1=g1;
        t2=g2;
    break;

    case 2:
        t1=g2;
        t2=g1;
    break;

    case 3:
        x=1+rand()%2;
        if(x==1) {
            cout<<"Il generatore casuale ha scelto "<<g1<<endl;
            t1=g1;
            t2=g2;
        }
        else {
            cout<<"Il generatore casuale ha scelto "<<g2<<endl;
            t1=g2;
            t2=g1;
        }
        break;

    }
    cout<<"Perfetto adesso possiamo iniziare"<<endl;
    system("pause");
    system("CLS");
}

void carica(char mat[][DIM], bool stato[][DIM]) {
    for(int i=0;i<DIM;i++) {
        for(int j=0;j<DIM;j++){
            mat[i][j]=' ';
            stato[i][j]=false;
        }
    }
}

void visua(char mat[][DIM]) {
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(j!=2) cout<<setw(4)<<mat[i][j]<<'|';
            else cout<<setw(4)<<mat[i][j];
        }
        cout<<endl;
        if(i!=2)
            cout<<"--------------"<<endl;
    }
}

bool win(char mat[][DIM], bool stato[][DIM]) {
    bool didhewon=false;

    //diagonale principale
    if(stato[0][0]==true && stato[1][1]==true && stato[2][2]==true && mat[0][0]==mat[1][1] && mat[0][0]==mat[2][2]) {
        cout<<"bravo"<<endl;
        return didhewon=true;
    }

    //diagonale secondaria
    if(stato[0][2]==true && stato[1][1]==true && stato[2][0]==true && mat[0][2]==mat[1][1] && mat[0][2]==mat[2][0]) {
        return didhewon=true;
    }

    //top orizontal line
    if(stato[0][0]==true && stato[0][1]==true && stato[0][2]==true && mat[0][0]==mat[0][1] && mat[0][0]==mat[0][2]) {
        return didhewon=true;
    }

    //mid orizontal line
    if(stato[1][0]==true && stato[1][1]==true && stato[1][2]==true && mat[1][0]==mat[1][1] && mat[1][0]==mat[1][2]) {
        return didhewon=true;
    }

    //bottom orizontal line
    if(stato[2][0]==true && stato[2][1]==true && stato[2][2]==true && mat[2][0]==mat[2][1] && mat[2][0]==mat[2][2]) {
        return didhewon=true;
    }

    //left vertical line
    if(stato[0][0]==true && stato[1][0]==true && stato[2][0]==true && mat[0][0]==mat[1][0] && mat[0][0]==mat[2][0]) {
        return didhewon=true;
    }

    //central vertical line
    if(stato[0][1]==true && stato[1][1]==true && stato[2][1]==true && mat[0][1]==mat[1][1] && mat[0][1]==mat[2][1]) {
        return didhewon=true;
    }

    //right vertical line
    if(stato[0][2]==true && stato[1][2]==true && stato[2][2]==true && mat[0][2]==mat[1][2] && mat[0][2]==mat[2][2]) {
        return didhewon=true;
    }

    return didhewon;
}

void game(char mat[][DIM], bool stato[][DIM]) {
    string t1,t2;
    char x1, x2;
    start(t1,t2);
    for(int i=0;i<T && win(mat,stato)==false;i++) {
        if(i%2==0) {
            cout<<"Tocca a "<<t1<<endl;
            x1=getch();
            while(x1<'1' || x1>'9') {
                cout<<"Errore." <<t1<<" inserisci un tasto valido"<<endl;
                x1=getch();
            }
            switch(x1){

                case '7': {
                    while(stato[0][0]==true) {
                        cout<<"Errore , hai già inserito in questa casella, reinscerisci."<<endl;
                        x1=getch();
                    }
                    mat[0][0]='X';
                    stato[0][0]=true;
                    break;
                }

                case '8': {
                    while(stato[0][1]==true) {
                        cout<<"Errore , hai già inserito in questa casella, reinscerisci."<<endl;
                        x1=getch();
                    }
                    mat[0][1]='X';
                    stato[0][1]=true;
                    break;
                }

                case '9': {
                    while(stato[0][2]==true) {
                        cout<<"Errore , hai già inserito in questa casella, reinscerisci."<<endl;
                        x1=getch();
                    }
                    mat[0][2]='X';
                    stato[0][2]=true;
                    break;
                }

                case '4': {
                    while(stato[1][0]==true) {
                        cout<<"Errore , hai già inserito in questa casella, reinscerisci."<<endl;
                        x1=getch();
                    }
                    mat[1][0]='X';
                    stato[1][0]=true;
                    break;
                }

                case '5': {
                    while(stato[1][1]==true) {
                        cout<<"Errore , hai già inserito in questa casella, reinscerisci."<<endl;
                        x1=getch();
                    }
                    mat[1][1]='X';
                    stato[1][1]=true;
                    break;
                }

                case '6':{
                    while(stato[1][2]==true) {
                        cout<<"Errore , hai già inserito in questa casella, reinscerisci."<<endl;
                        x1=getch();
                    }
                    mat[1][2]='X';
                    stato[1][2]=true;
                    break;
                }

                case '1': {
                    while(stato[2][0]==true) {
                        cout<<"Errore , hai già inserito in questa casella, reinscerisci."<<endl;
                        x1=getch();
                    }
                    mat[2][0]='X';
                    stato[2][0]=true;
                    break;
                }

                case '2': {
                    while(stato[2][1]==true) {
                        cout<<"Errore , hai già inserito in questa casella, reinscerisci."<<endl;
                        x1=getch();
                    }
                    mat[2][1]='X';
                    stato[2][1]=true;
                    break;
                }

                case '3': {
                    while(stato[2][2]==true) {
                        cout<<"Errore , hai già inserito in questa casella, reinscerisci."<<endl;
                        x1=getch();
                    }
                    mat[2][2]='X';
                    stato[2][2]=true;
                    break;
                }

            }

            system("pause");
            system("CLS");

            visua(mat);

        }
        else {
            cout<<"Tocca a "<<t2<<endl;
            x2=getch();
            while(x2<'1' || x2>'9') {
                cout<<"Errore." <<t2<<" inserisci un tasto valido"<<endl;
                x2=getch();
            }
            switch(x2){

                case '7': {
                    while(stato[0][0]==true) {
                        cout<<"Errore , hai già inserito in questa casella, reinscerisci."<<endl;
                        x2=getch();
                    }
                    mat[0][0]='O';
                    stato[0][0]=true;
                    break;
                }

                case '8': {
                    while(stato[0][1]==true) {
                        cout<<"Errore , hai già inserito in questa casella, reinscerisci."<<endl;
                        x2=getch();
                    }
                    mat[0][1]='O';
                    stato[0][1]=true;
                    break;
                }

                case '9': {
                    while(stato[0][2]==true) {
                        cout<<"Errore , hai già inserito in questa casella, reinscerisci."<<endl;
                        x2=getch();
                    }
                    mat[0][2]='O';
                    stato[0][2]=true;
                    break;
                }

                case '4': {
                    while(stato[1][0]==true) {
                        cout<<"Errore , hai già inserito in questa casella, reinscerisci."<<endl;
                        x2=getch();
                    }
                    mat[1][0]='O';
                    stato[1][0]=true;
                    break;
                }

                case '5': {
                    while(stato[1][1]==true) {
                        cout<<"Errore , hai già inserito in questa casella, reinscerisci."<<endl;
                        x2=getch();
                    }
                    mat[1][1]='O';
                    stato[1][1]=true;
                    break;
                }

                case '6':{
                    while(stato[1][2]==true) {
                        cout<<"Errore , hai già inserito in questa casella, reinscerisci."<<endl;
                        x2=getch();
                    }
                    mat[1][2]='O';
                    stato[1][2]=true;
                    break;
                }

                case '1': {
                    while(stato[2][0]==true) {
                        cout<<"Errore , hai già inserito in questa casella, reinscerisci."<<endl;
                        x2=getch();
                    }
                    mat[2][0]='O';
                    stato[2][0]=true;
                    break;
                }

                case '2': {
                    while(stato[2][1]==true) {
                        cout<<"Errore , hai già inserito in questa casella, reinscerisci."<<endl;
                        x2=getch();
                    }
                    mat[2][1]='O';
                    stato[2][1]=true;
                    break;
                }

                case '3': {
                    while(stato[2][2]==true) {
                        cout<<"Errore , hai già inserito in questa casella, reinscerisci."<<endl;
                        x2=getch();
                    }
                    mat[2][2]='O';
                    stato[2][2]=true;
                    break;
                }

            }

            system("pause");
            system("CLS");

            visua(mat);

        }
    }
    if(win(mat,stato)==false) {
        cout<<"Nessuno ha vinto."<<endl;
    }
    else {
        cout<<"Hai vinto!"<<endl;
    }
}
