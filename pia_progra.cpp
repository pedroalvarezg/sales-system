#include<iostream>
#include<stdio.h>
#include<math.h>
#include<fstream>

using namespace std;

//marca, modelo, año
class item{
    int itemno,stock,year;
    char iname[50];
    
    char brand[50];
    float price,qnt,tax,dis;

public:
    void getdata(){
        system("cls");
        cout << "\n Please enter the No. of the item: \t";
        cin>> itemno;
        cout << "\n Please enter the Model of the car: \t";
        cin>> iname;
        cout << "\n Please enter the Year of the car: \t";
        cin>> year;
        cout << "\n Please enter the Brand of the car: \t";
        cin>> brand;
        cout << "\n Please enter the price of the item: \t";
        cin>> price;
        cout << "\n Please enter the discount(%) \t";
        cin>> dis;
        cout << "\n Please enter the cars in stock: \t";
        cin>> stock;

    }
    void showdata(){
        system("cls");
        cout<< "\nThe item No. of the item: "<< itemno;
        cout<< "\nThe Model of the car: "<< iname;
        cout<< "\nThe Year of the car: "<< year;
        cout<< "\nThe Brand of the car: "<< brand;
        cout<< "\nThe price of the item: "<< price;
        cout<< "\nDiscount: "<< dis<<"%";
        cout<< "\nStock: "<< stock;
    }
    //functions to return the private data
    int retitemno(){
        return itemno;
    }

    float retprice(){
        return price;
    }

    char* retiname(){
        return iname;
    }
    int retiyear(){
        return year;
    }
    char* retibrand(){
        return brand;
    }

    int retdis(){
        return dis;
    }

    int retstock(){
        return stock;
    }
   
};


class costumer_name{
    
    char cname[999],capellido[999];
    char answer;
    int age,id,id_pago;
    float pago;
    

public:
    void getname(){
        
        system("cls");
        cout << "\n Please enter your id: \t";
        cin>> id;
        cout << "\n Please enter your name: \t";
        cin>> cname;
        cout << "\n Please enter your lastname: \t";
        cin>> capellido;
        cout << "\n Please enter your age: \t";
        cin>> age;
        

    }
    void getPayment(){

        cout << "\n Please enter the ID of your payment(same ID as your costumer ID): \t";
        cin>> id_pago;
        cout << "\n Please enter your payment: \t";
        cin>> pago;
        cout<<"\nChoose how you want to make your payment ?:";
        cout<<"\n\t1.Now";
        cout<<"\n\t2.Credit 1 year";
        cout<<"\n\t3.Credit 3 years";
        cout<<"\n\t4.Credit 5 years";
        cout<<"\n\tChoose your option: ";      
        cin>>answer;
        if(answer=='1'){
            pago= pago;
        }else if(answer=='2'){
            pago= pago* pow((1+0.05),1);
        }else if(answer=='3'){
            pago= pago* pow((1+0.05),3);
            //((1+0.05)**3);
        }else if(answer=='4'){
            pago= pago*pow((1+0.05),5);
            //((1+0.05)**5);
        }else{
            pago= 0;
            cout<<"\nSorry...We dont have that service :( \n";
            cout<<"program is closing...\n";
            exit(0);
        }
        
        
       


        
    }
    void showname(){
        //system("cls");
        cout<< "\nID: "<<id;
        cout<< "\nName: "<< cname<<" "<<capellido<<endl;
        cout<<"\nAge: "<<age;
        
        
    }

    

    void showPayment(){
        //system("cls");
        
        cout<< "\nID: "<<id_pago;
        cout << "\n Payment: "<<pago;

    }
   

    char* retcname(){
        return cname;
    }

    char* retcapellido(){
        return capellido;
    }

    int retcage(){
        return age;
    }
    int retcid(){
        return id;
    }

   
    

    
   
};




fstream f; // class objects
item i;
costumer_name costumer;



void write_to_file(){  
    f.open("store.txt",ios::out|ios::app);
    i.getdata();
    f.write((char*)&i,sizeof(i));
    f.close();
    cout<< "\n\n The item has been created ";
}

void write_costumer_to_file(){
    f.open("costumer.txt",ios::out|ios::app);
    costumer.getname();
    //costumer.getPayment();
    f.write((char*)&costumer,sizeof(costumer));
    f.close();
    cout<< "\n\n The costumer has been created ";
}

void write_payment_to_file(){
    f.open("payment.txt",ios::out|ios::app);
    //costumer.getname();
    costumer.getPayment();
    f.write((char*)&costumer,sizeof(costumer));
    f.close();
    cout<< "\n\n The payment has been created ";
}





void disp_all(){ //func to read all the records from file
    //system("cls");
    cout<<endl<<endl<<endl<< "\n\n\n\t\t DISPLAY ALL RECORDS !!! \n\n"<<endl<<endl;
    f.open("store.txt",ios::in);
    while(f.read((char*)&i,sizeof(i))){
        i.showdata();
        cout<<endl<<endl<<"\n\n ===============================\n\n"<<endl<<endl;

    }
    f.close();

}

void disp_all_costumers(){ //func to read all the costumers records from file
    //system("cls");
    cout<<endl<<endl<<endl<< "\n\n\n\t\t DISPLAY ALL COSTUMERS RECORDS !!! \n\n"<<endl<<endl;
    f.open("costumer.txt",ios::in);
    while(f.read((char*)&costumer,sizeof(costumer))){
        costumer.showname();
        cout<<endl<<endl<<"\n\n ===============================\n\n"<<endl<<endl;

    }
    f.close();

}

void disp_all_payments(){ //func to read all the costumers records from file
    system("cls");
    cout<<endl<<endl<<endl<< "\n\n\n\t\t DISPLAY ALL PAYMENTS RECORDS !!! \n\n"<<endl<<endl;
    f.open("payment.txt",ios::in);
    
    while(f.read((char*)&costumer,sizeof(costumer))){
        costumer.showPayment();
        cout<<endl<<endl<<"\n\n ===============================\n\n"<<endl<<endl;

    }
    f.close();

}



void display_sp(int n){ // func to read an specific record from file
    int flag=0;
    f.open("store.txt",ios::in);
    while(f.read((char*)&i,sizeof(i))){
        if(i.retitemno()==n){
            system("cls");
            i.showdata();
            flag=1;
        }
    }
    f.close();
    if(flag==0)
    cout<<endl<<endl<<"Record doesnt exist";
}


void display_sp_costumer(int a){ // func to read an specific costumer from file
    int bandera=0;
    f.open("costumer.txt",ios::in);
    while(f.read((char*)&costumer,sizeof(costumer))){
        if(costumer.retcid()==a){
            //system("cls");
            costumer.showname();
            bandera=1;
        }
    }
    f.close();
    if(bandera==0)
    cout<<endl<<endl<<"This costumer doesnt exist";
}


void modify(){ //func to modify record to file
    int no, found=0;
    system("cls");
    cout<<endl<<"To modify";
    cout<<endl<<endl<< "\n\n\t Please enter the Item No. of the item: ";
    cin>> no;
    f.open("store.txt",ios::in|ios::out);
    while(f.read((char*)&i,sizeof(i)) && found==0){
        if(i.retitemno()==no){
            i.showdata();
            system("cls");

            cout<<endl<<"\n Pls enter the new details of the item"<< endl;
            i.getdata();
            int pos=-1*((int)sizeof(i));
            f.seekp(pos,ios::cur);
            f.write((char*)&i,sizeof(i));
            cout<<endl<<endl<<"\n\n\t Record updated";
            found=1;
        }
    }
    f.close();
    if(found==0)
        cout<<"\n\n Record not found!";
}


void modify_costumer(){ //func to modify a costumer data record to file
    int ident, encontrar=0;
    system("cls");
    cout<<endl<<"To modify";
    cout<<endl<<endl<< "\n\n\t Please enter the ID of the costumer: ";
    cin>> ident;
    f.open("costumer.txt",ios::in|ios::out);
    while(f.read((char*)&costumer,sizeof(costumer)) && encontrar==0){
        if(costumer.retcid()==ident){
            costumer.showname();
            //system("cls");

            cout<<endl<<"\n Pls enter the new details of the costumer"<< endl;
            costumer.getname();
            int pos=-1*((int)sizeof(costumer));
            f.seekp(pos,ios::cur);
            f.write((char*)&costumer,sizeof(costumer));
            cout<<endl<<endl<<"\n\n\t Record updated";
            encontrar=1;
        }
    }
    f.close();
    if(encontrar==0)
        cout<<"\n\n Record not found!";
}

void deleterec(){ //func to delete record of file
    int no;
    system("cls");
    cout<<endl<<endl<<"\n\n\n\t Delete record";
    cout<<endl<<endl<< "\n\n\t Please enter the Item No. of the item you want to delete: ";
    cin>> no;
    f.open("store.txt",ios::in|ios::out);
    fstream f2;
    f2.open("store.txt",ios::in|ios::out);
    f.seekg(0,ios::beg);
    while(f.read((char*)&i,sizeof(i))){
        if(i.retitemno()!=no){
            f2.write((char*)&i,sizeof(i));
        }
    }
    f2.close();
    f.close();
    remove("store.txt");
    rename("temp.txt", "store.txt");
    cout<<"\n Record deleted...";

}


void menu(){ //func to display all products price list 
    system("cls");
    f.open("store.txt",ios::in);
    if(!f){
        cout<< "ERROR!! FILE COULD NOT BE OPEN\n\n\n GO TO ADMIN TO CREATE A FILE";
        cout<<"program is closing...";
        exit(0);

    }
    cout<<"\n\n\t\t ITEM MENU \n\n";
    cout<<"=========================================================================================\n";
    cout<<"ITEM.NO.\tNAME\t\tYEAR\t\tBRAND\t\tPRICE\t\tIN STOCK\n";
    cout<<"=========================================================================================\n";
    while(f.read((char*)&i,sizeof(i))){
        cout<<i.retitemno()<<"\t\t"<<i.retiname()<<"\t\t"<<i.retiyear()<<"\t\t"<<i.retibrand()<<"\t\t"<<i.retprice()<<"\t\t"<<i.retstock()<<endl;
    }
    f.close();
}




void place_order(){ //func to place order and generate bill
    system("cls");
    int order_arr[50], quan[50], c=0,j,g=0;
    float amt,damt,total=0, adeudo=0;
    char ch='Y';
   
    menu();
    cout<<"\n==============================";
    cout<<"\n       PLACE YOUR ORDER        ";
    cout<<"\n==============================";
    do{
        
        //system("cls");
        
        cout<<endl<<endl<< "\n\n\t Please enter your ID: ";
        cin>> j;
        f.open("costumer.txt",ios::in|ios::out);
        while(f.read((char*)&costumer,sizeof(costumer)) && g==0){
            if(costumer.retcid()==j){
                
                //system("cls");

                
                int pos=-1*((int)sizeof(costumer));
                f.seekp(pos,ios::cur);
                //f.write((char*)&costumer,sizeof(costumer));
                //cout<<endl<<endl<<"\n\n\t Record updated";
                g=1;
            }
        }
        f.close();
        if(g==0){

            cout<< "ERROR!! FILE COULD NOT BE OPEN\n\n\n GO TO ADMIN TO CREATE AN ID :)";
            cout<<"\n\nprogram is closing...\n\n";
            exit(0);
        }
        
        cout<<"\n\nEnter the item No. of the item: \n";
        cin>>order_arr[c];
        cout<<"\n\n Quantity in number: \n";
        cin>>quan[c];
        c++;
        cout<<"\n Do you want another item? (y/n)\t";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    cout<<"\n\n thank you for placing the order";
    system("cls");
    cout<<"\n\n *****************INVOICE*************\n\n\n";
    cout<<"Costumer's ID: "<< costumer.retcid()<<"\n";
    cout<<costumer.retcname()<<" "<<costumer.retcapellido() <<"'s invoice:\n";
    cout<<"\nItem No.\tName\tQuantity\tPrice\tAmount\tAmount after discount\n";
    for(int x=0;x<=c;x++){
        f.open("store.txt", ios::in);
        f.read((char*)&i,sizeof(i));
        while(!f.eof()){
            if(i.retitemno()==order_arr[x]){
                amt= i.retprice()*quan[x];
                damt= amt-(amt*i.retdis()/100);
                cout<<"\n"<<order_arr[x]<<"\t\t"<<i.retiname()<<"\t"<<quan[x]<<"\t\t"<<i.retprice()<<"\t"<<amt<<"\t\t"<<damt;
                total+=damt;
                
                
                
            }
            f.read((char*)&i,sizeof(i));
        }
        f.close();

    }
    
    cout<<"\n\n\t\t\t\t\tTOTAL= "<<total;
    
}






void admin_menu(){
    system("cls");
    char ch2;
    cout<<"\n\n\t ADMIN MENU";
    cout<<"\n\t1.CREATE ITEM";
    cout<<"\n\t2.DISPLAY ALL ITEMS";
    cout<<"\n\t3.QUERY";
    cout<<"\n\t4.MODIFY ITEM";
    cout<<"\n\t5.DELETE ITEM";
    
    cout<<"\n\t6.BACK TO MAIN MENU";
    cout<<"\n\n\t Pls enter your choice(1-6): ";
    cin>>ch2;
    switch(ch2){
        case '1': system("cls");
            write_to_file();
            break;
        case '2': disp_all(); break;
        case '3':
            int num;
            system("cls");
            cout<<"\n\n\tPlease enter the item No.";
            cin>>num;
            display_sp(num);
            break;
        case '4': modify();break;
        case '5': deleterec(); break;
        
        
        case '6': menu();
            break;

        default: cout<<"\a";admin_menu();

            
    }
}

void costumer_menu(){
    char ch3;
    cout<<"\n\n\t COSTUMERS MENU";
    cout<<"\n\t1.CREATE NEW COSTUMER";
    cout<<"\n\t2.DISPLAY ALL COSTUMERS";
    cout<<"\n\t3.MODIFY COSTUMER";
    cout<<"\n\t4.QUERY COSTUMER";
    cout<<"\n\t5.BACK TO ADMIN MENU";
    cout<<"\n\n\t Pls enter your choice(1-5): ";

    cin>>ch3;
    switch(ch3){
        case '1': system("cls");
            write_costumer_to_file();
            break;
        case '2': disp_all_costumers(); break;
        case '3': modify_costumer(); break;
        case '4': int aux;
            system("cls");
            cout<<"\n\n\tPlease enter the ID of the costumer: ";
            cin>>aux;
            display_sp_costumer(aux);
        case '5': admin_menu();
            break;
        default: cout<<"\a";costumer_menu();

    }
}


void pagos_menu(){
    system("cls");
    char ch4;
    cout<<"\n\n\t PAYMENTS MENU";
    cout<<"\n\t1.CREATE NEW PAYMENT";
    cout<<"\n\t2.DISPLAY ALL PAYMENTS";
    cout<<"\n\t3.BACK TO  MENU";
    cout<<"\n\n\t Pls enter your choice(1-3): ";

    cin>>ch4;
    switch(ch4){
        case '1': system("cls");
            write_payment_to_file();
            break;
        case '2': disp_all_payments(); break;
        
        
        case '3': menu();
            break;
        default: cout<<"\a";costumer_menu();
    }
}

int main(){
    char ch;
    do{
        system("cls");
        cout<<"\n\n\n\tMAIN MENU";
        cout<<"\n\n\t1. COSTUMER bills";
        cout<<"\n\n\t2. ADMIN";
        cout<<"\n\n\t3. COSTUMERS INFO";
        cout<<"\n\n\t4. PAYMENTS";
        cout<<"\n\n\t5. EXIT";
        cout<<"\n\n\tPlease selection your option(1-5):";
        cin>>ch;
        switch(ch){
            case '1': system("cls");
                place_order();
                break;
            case '2': admin_menu();
                break;
            case '3': costumer_menu();
                break;
            case '4': pagos_menu();
                break;
            case '5': exit(0);
                break;
            default :cout<<"\a";
        }
    }while(ch!='5');
    return 0;
}

