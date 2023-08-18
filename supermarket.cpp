#include<iostream>
#include<fstream>
using namespace std;
class shopping
{
    private:
        int pcode;
        float price;
        float dis;
        string pname;
    public:
        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void receipt();
        int count(long);
        
    
};

int shopping::count(long y){
    
    int count=0;
    while(y!=0){
      
         y=y/10;
        count++;
       
    }
 
    return count;
}
void shopping::menu()
{
        m:
        int choice;
        string email;
        string password;

        cout<<"\t\t\t\t_________ \n";
        cout<<"\t\t\t\t                                               \n";
        cout<<"\t\t\t\t      SuperMarket main menu  \n";
        cout<<"\t\t\t\t                                                \n";
        cout<<"\t\t\t\t________ _ \n";
        cout<<"\t\t\t\t                                      |\n";
        cout<<"\t\t\t\t|   1.Administrator         |\n";
        cout<<"\t\t\t\t|                                     |\n";
        cout<<"\t\t\t\t|    2.Buyer                    |\n";
        cout<<"\t\t\t\t|                                     |\n";
        cout<<"\t\t\t\t|    3.Exit                       |\n";
        cout<<"\t\t\t\t|                                    |\n";
        cout<<"\n\t\t\t Please select!";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                    cout<<"\t\t\t Please Login \n";
                    cout<<"\t\t\t Enter email \n";
                    cin>>email;
                    cout<<"\t\t\t Password \n";
                    cin>>password;
                    if(email=="robby@gmail.com" && password=="robby@123")
                    {
                     administrator();
                    }
                    else
                    {
                        cout<<"Invalid email/password";
                    }
                    break;
            }
                case 2:
                {
                    buyer();
                }
                case 3:
                {
                    exit(0);
                }
                default:
                {
                    cout<<"Please select from the given options";
                }
        }
        goto m;
}
void shopping :: administrator()
{       m:
        int choice;
        cout<<"\n\n\n\t\t\t Administrator menu";
        cout<<"\n\t\t\t|__1.Add the product___|";
        cout<<"\n\t\t\t|                                                           |";
        cout<<"\n\t\t\t|__ 2.Modify the product__|";
        cout<<"\n\t\t\t|                                                           |";
        cout<<"\n\t\t\t|__3.Delete the project____|";
        cout<<"\n\t\t\t|                                                             |";
        cout<<"\n\t\t\t|_4.Back to main menu___|";
        cout<<"\n\n\t Please enter your choice";
        cin>>choice;
        switch(choice)
        {
                case 1:
                         add();
                         break;
                case 2:
                          edit();
                            break;

                case 3:
                        rem();
                        break;
                case 4:
                      menu();
                      break;
                default:
                     cout<<"Invalid choice!";
        }
        goto m;
}
void shopping:: buyer()
{       m:
        int choice;
        cout<<"\t\t\t  Buyer                     \n";
        cout<<"\t\t\t______\n";
        cout<<"                                       \n";
        cout<<"\t\t\t 1. Buy product       \n";
        cout<<"\t\t\t                                 \n";
        cout<<"\t\t\t2. Go Back              \n";
        cout<<"\t\t\t  Enter your choice :";
        cin>>choice;
        switch(choice)
        {
            case 1:
                     receipt();
                     break;
            case 2:
                      menu();
                     
            default:
                cout<<"Invalid choice";
        }
        goto m;
}
void shopping::add()
{       m:
        fstream data;
        int c;
        int token=0;
        float p;
        float d;
        string n;
        cout<<"\n\n\t\t\t Add new product";
        cout<<"\n\n\t Product code of the product:";
        cin>>pcode;
        cout<<"\n\n\t Name of the product:";
        cin>>pname;
        cout<<"\n\n\t Price of the product:";
        cin>>price;
        cout<<"\n\n\t Discount of the product:";
        cin>>dis;
        
        data.open("database.txt",ios::in);
        if(!data)
        {
            data.open("database.txt",ios::app|ios::out);
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            data.close();
        }
        else
        {
            data>>c>>n>>p>>d;

            while(!data.eof())
            {
                if(c==pcode)
                {
                    token++;
                }
                data>>c>>n>>p>>d;
            }
            data.close();
        

            if(token==1)
            goto m;

             else
            {
                    data.open("database.txt",ios::app|ios::out);
                    data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
                    data.close();
            }
        
            cout<<"\n\n\t\t Record inserted !";
        }
}
void shopping ::edit()
{
        fstream data,data1;
        int pkey;
        int c;
        int token=0;
        float p;
        float d;
        string n;
        cout<<"\n\n\t\t\t Modify the record";
        cout<<"\n\n\t\t\t Product code";

        cin>>pkey;
        data.open("database.txt",ios::in);
        if(data.fail())
        {
            cout<<"\n\nFile doesn't exist!";
        }
        else
        {
            data1.open("database1.txt",ios::app|ios::out);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
                if(pkey==pcode)
                {
                    cout<<"\n\t\t Product new code :";
                    cin>>c;
                    cout<<"\n\t\t Name of the product :";
                    cin>>n;
                    cout<<"\n\t\t Price :";
                    cin>>p;
                    cout<<"\n\t\t  Discount :";
                    cin>>d;
                    data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                    cout<<"\n\n\t\t Record edited ";
                    token++;
                }
                else
                {
                    data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
                }
                    data>>pcode>>pname>>price>>dis;
            }
            data.close();
            data1.close();
            remove("database.txt");
            rename("database1.txt","database.txt");

            if(token==0)
            {
                cout<<"\n\n Record not found sorry!";
            }
        }
}
  
void shopping::rem()
{
        fstream data,data1;
        int pkey;
        int token=0;
        cout<<"\n\n\t  Delete the product";
        cout<<"\n\n\t   Product code";
        cin>>pkey;
        data.open("database.txt",ios::in);
        if(data.fail())
        {
            cout<<"File doesn't exist";
        }

        else
        {
            data1.open("database1.txt",ios::app|ios::out);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
                if(pkey==pcode)
                {
                    cout<<"\n\n\t Product deleted successfully";
                    token++;
                }
                else
                {       
                    data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
                }
                data>>pcode>>pname>>price>>dis;
            }
                data.close();
                data1.close();
                remove("database.txt");
                rename("database1.txt","database.txt");

                if(token==0)
                {
                    cout<<"\n\n Record not found ";
                }
        }
}

void shopping::list()
{
        fstream data;
        data.open("database.txt",ios::in);
        cout<<"\n\n|____\n";
        cout<<"ProNo\t\tName\t\tPrice\n";
        cout<<"\n\n|____\n";
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            cout<<pcode<<" \t\t"<<pname<<" \t\t"<<price<<"\n";
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
}
void shopping::receipt()
{
        fstream data,data2;
        int arrc[100];
        int arrq[100];
        char choice;
        int c=0;
        float amount=0;
        float dis=0;
        float total=0;

        cout<<"\n\n\t\t\t\t RECEIPT";
        data.open("database.txt",ios::in);
        if(data.fail())
        {
            cout<<"\n\n Empty database";
        }
        else
        {
            
            data.close();
            list();
            cout<<"\n____________\n";
            cout<<"\n                              \n";
            cout<<"\n        Please place order    \n";
            cout<<"\n                              \n";
            cout<<"\n____________\n";
            
            do
            {   
                m:
                try
                {
                     cout<<"\nEnter the product code  :";
                     cin>>arrc[c];
                     cout<<"\nEnter the product quantity   :";
                     cin>>arrq[c];
                 
                    if(arrq[c]>=6)
                    {
                        throw 6;
                    }
                }
                catch(int c)
                {
                    cout<<"Product quantities  are limited only to 5 items";
                    continue;
                }
                for(int i=0;i<c;i++)
                {
                    if(arrc[c]==arrc[i])
                    {
                       cout<<"\n\n Duplicate product code.Please try again!";
                       goto m;
                    }
                }
                c++;
                cout<<"\n\nDo you want to buy another product?if yes then press y else n for no\n";
                cin>>choice;
               
            }while(choice=='y');
                
                
            
           cout<<"\n\n\t RECEIPT__\n";
           cout<<"\nProduct number \t Product name\t Product quantity\t Price\tAmount\t Amount discount\n";
           for(int i=0;i<c;i++)
           {
               data.open("database.txt",ios::in);
               data>>pcode>>pname>>price>>dis;
               while(!data.eof())
               {
                   if(pcode==arrc[i])
                   {
                       amount=price*arrq[i];
                       dis=amount-(amount*dis/100);
                       total=total+dis;
                       cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
                       
                   }
                   data>>pcode>>pname>>price>>dis;
               }data.close();
               
           }
           
        }
        
        cout<<"\n_______________\n";
        cout<<"\n Total amount: "<<total;
         int x;
    long y;
    int g;
    l:
    cout<<"\nDo you want to pay through cash or card?Press 1 for cash and 2 for card\n";
    cin>>x;
    if(x==1)
    {
        cout<<"Thank you!! Visit again\n";
    }
    else
    {
        
        cout<<"Enter the card number\n";
        cin>>y;
        g=count(y);
        if(g==16){
        
            cout<<"Payement done successfully";
            return;
        }
        cout<<"Invalid card  number";
        goto l;
        
       
        
        
    }
        

        
}
int main()
{
        shopping s;
       s.menu();
      
}