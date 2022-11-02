#include<iostream>
#include<istream>
#include<fstream>
#include<string.h>

using namespace std;

void menu();
void menu2();
void reg();
void log();
void forgot();

main(void){
  int choice;
  
  menu();
  
  cout<<"Enter choice:"<<endl;
  cin>>choice;  

    switch(choice){
         case 1: 
              reg();
                                break;
         case 2: 
              log(); 
                                break;
         case 3:
              forgot();
                                break;
         case 4: 
         system("cls");
         cout<<"Thanks for using the login page!"<<endl;                
                                break;

         default: 
         system("cls");
         cout<<"Sorry this option do not exist!"<<endl; break;                                                                      
    }

    return 0;
}

void menu(){
    cout<<"***************************************"<<endl;
    cout<<"*                 MENU                *"<<endl;
    cout<<"***************************************"<<endl;
    cout<<"*                                     *"<<endl;
    cout<<"*     1.Register                      *"<<endl;
    cout<<"*     2.Login                         *"<<endl;
    cout<<"*     3.Forgot account                *"<<endl;
    cout<<"*     4.Exit                          *"<<endl;
    cout<<"***************************************"<<endl;
}

void menu2(){
    cout<<"***************************************"<<endl;
    cout<<"*                 MENU                *"<<endl;
    cout<<"***************************************"<<endl;
    cout<<"*                                     *"<<endl;
    cout<<"*     1.Forgot password               *"<<endl;
    cout<<"*     2.Forgot username               *"<<endl;
    cout<<"*     3.Exit                          *"<<endl;
    cout<<"***************************************"<<endl;
}


void reg(){
    string reuser , repass, ru, rp;
    
    system("cls");
    
    cout<<"Enter your UserName: "<<endl;
    cin>>reuser;
    cout<<"Enter your Password: "<<endl;
    cin>>repass;
      
    ifstream searchr("database.txt");
     
    while(searchr>>ru>>rp)
    {
      if(ru == reuser || rp == repass)
      {
        system("cls");
        cout<<"You are already registered or you need to change username or password!"<<endl;
        cout<<endl;
        cout<<"Press eny key to go menu!"<<endl;
        cin.get();
        cin.get();
        system("cls");
        main();
      }
    }
    searchr.close();

       ofstream reg("database.txt", ios::app);
 
       reg<<reuser<<' '<<repass<<endl;
       system("cls");

       cout<<"Registration is successfully!"<<endl;
       cout<<endl;
       cout<<"Press a key to go back menu!"<<endl;
       cin.get();
       cin.get();
       system("cls");
       main();

}

void log(){
    int exist;

    string luser , lpass , lu , lp;

    system("cls");

    cout<<"Enter your UserName: "<<endl;
    cin>>luser;
    cout<<"Enter your Password: "<<endl;
    cin>>lpass;

    ifstream input("database.txt");

    while(input>>lu>>lp)
    {
      if(lu == luser  && lp == lpass)
      {
        exist = 1;
      }
    }  
      input.close();

      if(exist == 1){
        system("cls");
        cout<<"Hello "<<luser<<" !"<<endl;
        cout<<"Your login is successfully!"<<endl;
        cout<<endl;
        
       
            cout<<"Press a key to go menu!"<<endl;
            cin.get();
            cin.get();
            system("cls");
            main();                         

      }else{
        system("cls");
        cout<<"This account is not found!"<<endl;
        cout<<"If you are not registered go back to menu and choice first option!"<<endl;
        cout<<endl;
        cout<<"Press any key to go back menu!"<<endl;
        cin.get();
        cin.get();
        system("cls");
        main();
      }
}

void forgot(){
    int ch;
  
    system("cls");

    menu2();
    cout<<"Enter choice: "<<endl;
    cin>>ch;

    switch(ch){
        case 1:
      {
           
           int ex = 0;
           
           string suser, su, sp;
           
           cout<<"Enter your remembered username: "<<endl;
           cin>>suser;

           ifstream search("database.txt");
           while(search>>su>>sp)
           {
              if(su == suser)
              {
                ex = 1;
                break;
              }
           }
           search.close();
           if(ex == 1)
           {
             system("cls");
             cout<<"Account found!"<<endl;
             cout<<"Your password is: "<<sp;
             cout<<endl;
             cout<<"Press a key to go menu!"<<endl;

             cin.get();
             cin.get();
             system("cls");
             main();
           }else{
             system("cls");
             cout<<"Sorry, your account is not found!"<<endl;
             cout<<endl;
             cout<<"Press a key to go menu!"<<endl;
            
             cin.get();
             cin.get();
             system("cls");
             main();
           }
        }                     break;
        case 2:
        { 
            
            int exi = 0;

            string spass , shu , shp;
            
            cout<<"Enter the remembered password: "<<endl;
            cin>>spass;

            ifstream searchp("database.txt");

            while(searchp>>shu>>shp)
            {
              if(shp == spass)
              {
                exi = 1;
                break;
              }
            }
            searchp.close();
            if(exi == 1)
            {
             system("cls"); 
             cout<<"Account found!"<<endl;
             cout<<"Your username is: "<<shu;
             cout<<endl;
             cout<<"Press a key to go menu!"<<endl;

             cin.get();
             cin.get();
             system("cls");
             main();
            }else{
             system("cls");  
             cout<<"Sorry, your account is not found!"<<endl;
             cout<<endl;
             cout<<"Press a key to go menu!"<<endl;
            
             cin.get();
             cin.get();
             system("cls");
             main();
            }
         }                  break;
        
        case 3:
           system("cls");  
            main();   break;

        default: cout<<"Sorry this option do not exist!"<<endl; break;                                       
    }


}