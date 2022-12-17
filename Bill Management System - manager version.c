#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<dos.h>
#include<windows.h>

struct stock{
	int itemcode;
	char name[100];
	int quantity;
	float price;
	char Remarks;
};
struct billstock{
	int billcode;
	char billname[100];
	int billquantity;
	float billprice;
    float totalprice;
};

struct stock items;
FILE *fptr,*fptrtemp,*fptrsales;
char remarks;
char goback;
char editname[100];
int data=0;
int record=0;
char repeat = 'Y';
char filename[20]="Stocks.txt";
int choice;
char employer[50] = "Bishal Sapkota";
int numberread;
char removename[100];
int billlist;
float totalamount;
float discount;
int logincheck = 0;


void add();
void search();
void edit();
void list();
void remove();
void bill();
void star();
void line();
void index();
void login();
void salesdata();

void top(){
system("cls");	
star();
printf("\t\t\t\t\t    INDRA ELECTRONICS DEPARTMENTAL STORE    \t\t\t\t\t\n");
Sleep(1500);
line();
time_t tm;
time(&tm);

printf("\t\t\t\t\t Date: %s", ctime(&tm));
printf("\t\t\t\t\t Manager: %s \n", employer);
star();
Sleep(1500);
}


int main(){
	login();
	choice=0;
	top();
printf("\t\t\t\t\t\t\t MAIN MENU:\n");
line();
printf("\t\t\t\t\t 1) CREATE NEW ITEM \n\n");
Sleep(700);
printf("\t\t\t\t\t 2) EDIT EXISTING ITEM \n\n");
Sleep(700);
printf("\t\t\t\t\t 3) DELETE AN ITEM \n\n");
Sleep(700);
printf("\t\t\t\t\t 4) SEARCH FOR AN ITEM \n\n");
Sleep(700);
printf("\t\t\t\t\t 5) LIST ALL ITEMS \n\n");
Sleep(700);
printf("\t\t\t\t\t 6) CREATE BILL FOR CUSTOMERS \n\n");
Sleep(700);
printf("\t\t\t\t\t 7) DISPLAY SALES DATA \n\n");
Sleep(700);
printf("\t\t\t\t\t 8) EXIT FROM THE PROGRAM\n\n");
Sleep(700);
numberread = 0;
do{
	printf("\t\t\t\t\t ENTER YOUR CHOICE NUMBER:\t");
	numberread = scanf(" %d",&choice);
    while(numberread != 1){
    	printf("\n\t\t\t\t\t INVALID CHOICE \n");
    	scanf(" %*[^\n]");
    	printf("\t\t\t\t\t ENTER YOUR CHOICE NUMBER:\t");
    	numberread = scanf(" %d",&choice);
	}
if(choice ==1 ){add();}
else if (choice ==2){edit();}
else if (choice ==3){remove();}
else if (choice ==4){search();}
else if(choice ==5){list();}
else if(choice ==6){bill();}
else if(choice ==7){salesdata();}
else if(choice == 8){

printf("\n\t\t\t\t\t Exiting...\t");
Sleep(1500);
exit(0);
}
else{printf("\n\t\t\t\t\t INVALID CHOICE \n");}
}while(choice <1 || choice >8); 

return 0;	
}

void add(){
	repeat = 'Y';
	fptr = fopen(filename,"ab");
	fseek(fptr,0,SEEK_END);
	top();
	while (repeat == 'Y'){
	printf("\t\t\t\t\t CREATE NEW ITEM STOCK \t\t\t\t\t\n");
	Sleep(700);
	printf("\n\t\t\t\t\t Enter item code \t");
	fflush(stdin);
	numberread = 0;
	numberread = scanf(" %d",&items.itemcode);
    while(numberread != 1){
    	printf("\n\t\t\t\t\t INVALID CODE \n");
    	scanf(" %*[^\n]");
    	printf("\t\t\t\t\t Enter item code:\t");
    	numberread = scanf(" %d",&items.itemcode);
	}
	while(items.itemcode<=0){
		printf("\n\t\t\t\t\t INVALID CODE \n");
		printf("\n\t\t\t\t\t Enter item code \t");
	fflush(stdin);
	numberread = 0;
	numberread = scanf(" %d",&items.itemcode);
    while(numberread != 1){
    	printf("\n\t\t\t\t\t INVALID CODE \n");
    	scanf(" %*[^\n]");
    	printf("\t\t\t\t\t Enter item code:\t");
    	numberread = scanf(" %d",&items.itemcode);
	}
	}
	
	
	
	Sleep(700);
	printf("\n\t\t\t\t\t Enter item name \t");
	fflush(stdin);
    scanf(" %s",&items.name);
    Sleep(700);
	printf("\n\t\t\t\t\t Enter item Price \t");
	fflush(stdin);
	numberread = 0;
	numberread = scanf(" %f",&items.price);
    while(numberread != 1){
    	printf("\n\t\t\t\t\t INVALID PRICE \n");
    	scanf(" %*[^\n]");
    	printf("\t\t\t\t\t Enter item price:\t");
    	numberread = scanf(" %f",&items.price);
	}
	while(items.price<=0){
			printf("\n\t\t\t\t\t INVALID PRICE \n");
		printf("\n\t\t\t\t\t Enter item Price \t");
	fflush(stdin);
	numberread = 0;
	numberread = scanf(" %f",&items.price);
    while(numberread != 1){
    	printf("\n\t\t\t\t\t INVALID PRICE \n");
    	scanf(" %*[^\n]");
    	printf("\t\t\t\t\t Enter item price:\t");
    	numberread = scanf(" %f",&items.price);
	}
	}
	
	Sleep(700);
	printf("\n\t\t\t\t\t Enter item quantity \t");
	fflush(stdin);
	numberread = 0;
	numberread = scanf(" %d",&items.quantity);
    while(numberread != 1){
    	printf("\n\t\t\t\t\t INVALID QUANTITY \n");
    	scanf(" %*[^\n]");
    	printf("\t\t\t\t\t Enter item quantity:\t");
    	numberread = scanf(" %d",&items.quantity);
	}
	while(items.quantity<=0){
		printf("\n\t\t\t\t\t INVALID QUANTITY \n");
		printf("\n\t\t\t\t\t Enter item quantity \t");
	fflush(stdin);
	numberread = 0;
	numberread = scanf(" %d",&items.quantity);
    while(numberread != 1){
    	printf("\n\t\t\t\t\t INVALID QUANTITY \n");
    	scanf(" %*[^\n]");
    	printf("\t\t\t\t\t Enter item quantity:\t");
    	numberread = scanf(" %d",&items.quantity);
	}
	}
	
	Sleep(700);
	
	fwrite(&items,sizeof(items),1,fptr);

	printf("\n\t\t\t\t\tAdding...\t\t\t\t\t\n");
	Sleep(700);
	printf("\n\t\t\t\t\t Item Added! \t\t\t\t\t\n");
	Sleep(1500);
	printf("\n\t\t\t\t\t DO YOU WANT TO CONTINUE (Y/N)? \t");
	scanf(" %c",&repeat);
}
	fclose(fptr);
	main();
}

void list(){
	
	fptr = fopen(filename,"rb");
	top();
	printf("\t\t\t\t\t\t\t ITEMS LIST:\n");
	line();
	Sleep(700);
	printf("\n\t\t\t\t\tCode  Name  \tPrice    Quantity  Remarks\n");
	while(fread(&items,sizeof(items),1,fptr)==1){
		star();
		if(items.quantity<20){
			remarks = 'U';
		}else if(items.quantity>=20 && items.quantity<=100){
			remarks = 'F';
		}else{
			remarks = 'O';
		}
		printf("\t\t\t\t\t%d     %s\t%.2f   %d        %c\n",items.itemcode,items.name,items.price,items.quantity,remarks);
		Sleep(1000);
	}
	index();
	fclose(fptr);
Sleep(500);
printf("\t\t\t\t\tEnter any character to go back\t");
fflush(stdin);
scanf(" %c",&goback);
if (goback == 'B') {
  main();
  }	else{
  	main();
  }
}

void edit(){
	data =0;
	record = 0;
	fptr = fopen(filename,"r+b");
	top();
	printf("\t\t\t\t\t\t\t EDIT MENU:\n");
	line();
	Sleep(700);
	fflush(stdin);
    printf("\n\t\t\t\t\t Enter item name to be modified \t");
    scanf(" %s",&editname);
    while(fread(&items,sizeof(items),1,fptr)==1){
    if(strcmp(items.name,editname) == 0){
		data = 1;
	star();
	printf("\t\t\t\t\t\t\t OLD RECORD:\n");
	line();
	Sleep(700);
	printf("\n\t\t\t\t\tCode  Name  \tPrice    Quantity  Remarks\n");
	star();
		if(items.quantity<20){
			remarks = 'U';
		}else if(items.quantity>=20 && items.quantity<=100){
			remarks = 'F';
		}else{
			remarks = 'O';
		}
		printf("\t\t\t\t\t%d     %s\t%.2f   %d        %c\n",items.itemcode,items.name,items.price,items.quantity,remarks);
	index();
	Sleep(1000);
		printf("\n\t\t\t\t\t Enter new item code \t");
	fflush(stdin);
	numberread = 0;
	numberread = scanf(" %d",&items.itemcode);
    while(numberread != 1){
    	printf("\n\t\t\t\t\t INVALID CODE \n");
    	scanf(" %*[^\n]");
    	printf("\t\t\t\t\t Enter new item code:\t");
    	numberread = scanf(" %d",&items.itemcode);
	}
	
		while(items.itemcode<=0){
		printf("\n\t\t\t\t\t INVALID CODE \n");
		printf("\n\t\t\t\t\t Enter new item code \t");
	fflush(stdin);
	numberread = 0;
	numberread = scanf(" %d",&items.itemcode);
    while(numberread != 1){
    	printf("\n\t\t\t\t\t INVALID CODE \n");
    	scanf(" %*[^\n]");
    	printf("\t\t\t\t\t Enter new item code:\t");
    	numberread = scanf(" %d",&items.itemcode);
	}
	}
	Sleep(700);
	printf("\n\t\t\t\t\t Enter new item name \t");
	fflush(stdin);
    scanf(" %s",&items.name);
    Sleep(700);
    printf("\n\t\t\t\t\t Enter new item Price \t");
	fflush(stdin);
	numberread = 0;
	numberread = scanf(" %f",&items.price);
    while(numberread != 1){
    	printf("\n\t\t\t\t\t INVALID PRICE \n");
    	scanf(" %*[^\n]");
    	printf("\t\t\t\t\t Enter new item price:\t");
    	numberread = scanf(" %f",&items.price);
	}
		while(items.price<=0){
			printf("\n\t\t\t\t\t INVALID PRICE \n");
		printf("\n\t\t\t\t\t Enter new item Price \t");
	fflush(stdin);
	numberread = 0;
	numberread = scanf(" %f",&items.price);
    while(numberread != 1){
    	printf("\n\t\t\t\t\t INVALID PRICE \n");
    	scanf(" %*[^\n]");
    	printf("\t\t\t\t\t Enter new item price:\t");
    	numberread = scanf(" %f",&items.price);
	}
	}
	
	Sleep(700);
		printf("\n\t\t\t\t\t Enter new item quantity \t");
	fflush(stdin);
	numberread = 0;
	numberread = scanf(" %d",&items.quantity);
    while(numberread != 1){
    	printf("\n\t\t\t\t\t INVALID QUANTITY \n");
    	scanf(" %*[^\n]");
    	printf("\t\t\t\t\t Enter new item quantity:\t");
    	numberread = scanf(" %d",&items.quantity);
	}
	while(items.quantity<=0){
		printf("\n\t\t\t\t\t INVALID QUANTITY \n");
		printf("\n\t\t\t\t\t Enter new item quantity \t");
	fflush(stdin);
	numberread = 0;
	numberread = scanf(" %d",&items.quantity);
    while(numberread != 1){
    	printf("\n\t\t\t\t\t INVALID QUANTITY \n");
    	scanf(" %*[^\n]");
    	printf("\t\t\t\t\t Enter new item quantity:\t");
    	numberread = scanf(" %d",&items.quantity);
	}
	}
	Sleep(700);
	fseek(fptr,sizeof(items)*record,SEEK_SET);
	if(fwrite(&items,sizeof(items),1,fptr) == 1){
	printf("\n\t\t\t\t\tEditing...\t\t\t\t\t\n");
	Sleep(700);
	printf("\n\t\t\t\t\t Item Editied! \t\t\t\t\t\n");
	Sleep(1500);
	break;
}
   }
record++;

}
if(data ==0){
	star();
	printf("\t\t\t\t\t\t\t MATCH NOT FOUND:\n");
	line();
	Sleep(700);
}
	
fclose(fptr);
printf("\n\t\t\t\t\t DO YOU WANT TO CONTINUE (Y/N)? \t");
fflush(stdin);
scanf(" %c",&repeat);
if(repeat == 'Y'){
	edit();
}else{
	main();
}	
}

void search(){
	fptr = fopen(filename,"rb");
	top();
	data = 0;
	printf("\t\t\t\t\t\t\t SEARCH MENU:\n");
	line();
	Sleep(700);
    printf("\n\t\t\t\t\t Enter item name to be searched \t");
    fflush(stdin);
    scanf(" %s",editname);
    while(fread(&items,sizeof(items),1,fptr)==1){
    if(strcmp(items.name,editname) == 0){
	data = 1;
	star();
	printf("\t\t\t\t\t\t\t SEARCHED ITEM:\n");
	line();
	Sleep(700);
	printf("\n\t\t\t\t\tCode  Name  \tPrice    Quantity  Remarks\n");
	star();
		if(items.quantity<20){
			remarks = 'U';
		}else if(items.quantity>=20 && items.quantity<=100){
			remarks = 'F';
		}else{
			remarks = 'O';
		}
		printf("\t\t\t\t\t%d     %s\t%.2f   %d        %c\n",items.itemcode,items.name,items.price,items.quantity,remarks);
		Sleep(1000);
     index();
}
   }


if(data == 0){
	star();
	printf("\t\t\t\t\t\t  MATCH NOT FOUND:\n");
	
	Sleep(700);
}
fclose(fptr);
printf("\n\t\t\t\t\t DO YOU WANT TO SEARCH AGAIN (Y/N)? \t");
fflush(stdin);
scanf(" %c",&repeat);
if(repeat == 'Y'){
	search();
}else{
	main();
}	

}
 void remove(){
 	top();
 	fptr= fopen(filename,"r+b");
 	fptrtemp = fopen("temp.txt","wb");
 	printf("\t\t\t\t\t\t\t DELETE ITEMS:\n");
	star();
	Sleep(700);
 	printf("\n\t\t\t\t\t Enter item name to be deleted \t");
 	fflush(stdin);
    scanf(" %s",removename);
    while(fread(&items,sizeof(items),1,fptr) == 1){
    	if(strcmp(items.name, removename) != 0){
    		fwrite(&items,sizeof(items),1,fptrtemp);
    		
		}
	}
	fclose(fptr);
	fclose(fptrtemp);
	printf("\n\t\t\t\t\t Deleting...\t");
	Sleep(750);
	remove(filename);
	rename("temp.txt",filename);
 	printf("\n\t\t\t\t\t Successfully deleted\n");
 	star();
 	printf("\n\t\t\t\t\t DO YOU WANT TO CONTINUE (Y/N)? \t");
 scanf(" %c",&repeat);
if(repeat == 'Y'){
	remove();
}else{
	main();
}
 }




void star(){
	printf("\t\t\t\t\t*******************************************\t\t\t\t\t\n");
}
void line(){
	printf("\t\t\t\t\t--------------------------------------------\t\t\t\t\t\n");
}
void index(){
	star();
	printf("\t\t\t\t\t\t\tINDEX:\n");
	line();
	Sleep(200);
	printf("\t\t\t\t\tU:Under stock\tF:Full stock\tO:Over stock\n");
	star();
}

void bill(){
	char customername[50];
	fptr = fopen(filename,"r+b");
	top();
	printf("\t\t\t\t\t\t\t CUSTOMER BILL:\n");
	line();
	Sleep(700);
	fflush(stdin);
	printf("\t\t\t\t\t Enter the customer's name\t");
	scanf(" %s",&customername);
	star();
	
	printf("\t\t\t\t\t Enter the no. of total items\t");
	fflush(stdin);
	numberread = 0;
	numberread = scanf(" %d",&billlist);
    while(numberread != 1){
    	printf("\n\t\t\t\t\t INVALID NUMBER \n");
    	scanf(" %*[^\n]");
    	printf("\t\t\t\t\t Enter the no.of total items\t");
    	numberread = scanf(" %d",&billlist);
	}
	while(billlist <= 0){
		printf("\n\t\t\t\t\t INVALID NUMBER \n");
		printf("\t\t\t\t\t Enter the no. of total items\t");
	fflush(stdin);
	numberread = 0;
	numberread = scanf(" %d",&billlist);
    while(numberread != 1){
    	printf("\n\t\t\t\t\t INVALID NUMBER \n");
    	scanf(" %*[^\n]");
    	printf("\t\t\t\t\t Enter the no.of total items\t");
    	numberread = scanf(" %d",&billlist);
	}
	}
	Sleep(700);
	line();
	printf("\t\t\t\t\t Enter the discount percent\t");
	
	fflush(stdin);
	numberread = 0;
	numberread = scanf(" %f",&discount);
    while(numberread != 1){
    	printf("\n\t\t\t\t\t INVALID NUMBER \n");
    	scanf(" %*[^\n]");
    	printf("\t\t\t\t\t Enter the discount percent\t");
    	numberread = scanf(" %f",&discount);
	}
	while(discount<=0){
		printf("\n\t\t\t\t\t INVALID NUMBER \n");
		printf("\t\t\t\t\t Enter the discount percent\t");
	
	fflush(stdin);
	numberread = 0;
	numberread = scanf(" %f",&discount);
    while(numberread != 1){
    	printf("\n\t\t\t\t\t INVALID NUMBER \n");
    	scanf(" %*[^\n]");
    	printf("\t\t\t\t\t Enter the discount percent\t");
    	numberread = scanf(" %f",&discount);
	}
	}
	
	Sleep(700);
	line();
	struct billstock currentbill[billlist];
	int currentquantity;
	int i;
	
	for(i=0;i<billlist;i++){
	data =0;
	record=0;
	rewind(fptr);
	
	fflush(stdin);
    printf("\n\t\t\t\t\t Enter the item name\t");
    scanf(" %s",editname);
    
    
    while(fread(&items,sizeof(items),1,fptr)== 1){
    if(strcmp(items.name,editname) == 0){
		data = 1;
	strcpy(currentbill[i].billname,items.name);
	currentbill[i].billcode = items.itemcode;
	currentbill[i].billprice = items.price;
		
		
   printf("\n\t\t\t\t\t Enter item quantity \t");
	fflush(stdin);
	numberread = 0;
	numberread = scanf(" %d",&currentquantity);
    while(numberread != 1){
    	printf("\n\t\t\t\t\t INVALID QUANTITY \n");
    	scanf(" %*[^\n]");
    	printf("\t\t\t\t\t Enter item quantity:\t");
    	numberread = scanf(" %d",&currentquantity);
    }
     while(currentquantity<=0){
    	printf("\n\t\t\t\t\t INVALID QUANTITY \n");
    	printf("\n\t\t\t\t\t Enter item quantity \t");
	fflush(stdin);
	numberread = 0;
	numberread = scanf(" %d",&currentquantity);
    while(numberread != 1){
    	printf("\n\t\t\t\t\t INVALID QUANTITY \n");
    	scanf(" %*[^\n]");
    	printf("\t\t\t\t\t Enter item quantity:\t");
    	numberread = scanf(" %d",&currentquantity);
    }
	}
    while(currentquantity > items.quantity){
    	printf("\n\t\t\t\t\t OUT OF STOCK QUANTITY \n");
    	printf("\n\t\t\t\t\t Enter item quantity \t");
	fflush(stdin);
	numberread = 0;
	numberread = scanf(" %d",&currentquantity);
    while(numberread != 1){
    	printf("\n\t\t\t\t\t INVALID QUANTITY \n");
    	scanf(" %*[^\n]");
    	printf("\t\t\t\t\t Enter item quantity:\t");
    	numberread = scanf(" %d",&currentquantity);
	      }
     }
    currentbill[i].billquantity = currentquantity;
    currentbill[i].totalprice = (currentbill[i].billquantity) * (currentbill[i].billprice);
    strcpy(items.name,items.name);
    items.price = items.price;
    items.itemcode = items.itemcode;
    items.quantity = (items.quantity) - (currentquantity);
    line();
    Sleep(700);
	fseek(fptr,sizeof(items)*record,SEEK_SET);
	if(fwrite(&items,sizeof(items),1,fptr) == 1){
	printf("\n\t\t\t\t\tEditing...\t\t\t\t\t\n");
	Sleep(700);
	printf("\n\t\t\t\t\t Item Editied! \t\t\t\t\t\n");
	Sleep(1500);
	break;
       }
    }
    record++;  
}
line();
if(data == 0){
	star();
	printf("\t\t\t\t\t\t\t ITEM NOT FOUND:\n");
	line();
	Sleep(700);
	i = i-1;
}
}
printf("\t\t\t\t\t GENERATING BILL...\n");
Sleep(1500);
totalamount =0;
fptrsales = fopen("Sales.txt","r+b");
	line();
	top();
	printf("\n\t\t\t\t\t\t\tRECEIPT:\n");
	line();
	printf("\t\t\t\t\t Customer's Name: %s \n", customername);
    star();
    Sleep(700);
	printf("\n\t\t\t\t\tCode  Name  \tPrice    Quantity  Total\n");
	line();
	for(i=0;i<billlist;i++){
	printf("\t\t\t\t\t%d     %s\t%.2f   %d        %.2f\n",currentbill[i].billcode,
	currentbill[i].billname,currentbill[i].billprice,currentbill[i].billquantity,currentbill[i].totalprice);
	line();
	totalamount = totalamount +currentbill[i].totalprice;
	fwrite(&currentbill[i],sizeof(currentbill[i]),1,fptrsales);
}
fclose(fptrsales);
discount = discount/100;
printf("\t\t\t\t\t\t\t Sub-Total amount: %.2f\n",totalamount);
printf("\t\t\t\t\t\t\t\t Discount: -%.2f\n", discount*totalamount);
printf("\t\t\t\t\t\t\t\t      VAT: %.2f\n",0.13*(totalamount*(1-discount)));
printf("\t\t\t\t\t\t\t     Total amount: %.2f\n",1.13*(totalamount*(1-discount)));
star();

fclose(fptr);
printf("\n\t\t\t\t\t DO YOU WANT TO CREATE BILL AGAIN (Y/N)? \t");
fflush(stdin);
scanf(" %c",&repeat);
if(repeat == 'Y'){
	bill();
}else{
	main();
}	
}

void login(){
	if(logincheck !=1 ){
	char id[20];
	char password[50];
	char ch;

	   system("cls");
	   star();
       printf("\t\t\t\t\t    INDRA ELECTRONICS DEPARTMENTAL STORE    \t\t\t\t\t\n");
       Sleep(500);
       line();	
		printf("\t\t\t\t\t\t\t LOGIN MENU:\n");
	line();
	printf("\t\t\t\t\t Enter manager id:\t");
	fflush(stdin);
	scanf(" %s", id);
	while (strcmp(id,"manager") !=0){
	printf("\t\t\t\t\tIncorrect id!!!\n");	
	printf("\t\t\t\t\t Enter manager id:\t");
	fflush(stdin);
	scanf(" %s", id);
	}
	
	line();
	int i=0;
	printf("\t\t\t\t\t Enter password:\t");
	while((ch=_getch())!=13){
		password[i] = ch;
		i++;
		printf("*");
	}
	password[i]='\0';
	while(strcmp(password,"manager123")!=0){
	int i=0;
	password[0]='\0';	
	printf("\n\t\t\t\t\t Incorrect password!!!\n");
	printf("\t\t\t\t\t Enter password:\t");
	while((ch=_getch())!=13){
		password[i] = ch;
		i++;
		printf("*");
	}
	password[i] = '\0';
	}
		logincheck = 1;
	printf("\n");	
	star();
	printf("\n\t\t\t\t\t\t Login Successful... ");
	Sleep(1000);	
	}
}

void salesdata(){
	fptrsales = fopen("Sales.txt","rb");
	top();
	printf("\t\t\t\t\t\t\t SOLD ITEMS LIST:\n");
	line();
	struct billstock salesdata;
	Sleep(700);
	printf("\n\t\t\t\t\tCode  Name  \tPrice    Quantity  Total\n");
	while(fread(&salesdata,sizeof(salesdata),1,fptrsales)==1){
		star();
		printf("\t\t\t\t\t%d     %s\t%.2f   %d        %.2f\n",salesdata.billcode,
	salesdata.billname,salesdata.billprice,salesdata.billquantity,salesdata.totalprice);
		Sleep(1000);
	}
	line();
	fclose(fptrsales);
Sleep(500);
printf("\t\t\t\t\tEnter any character to go back\t");
fflush(stdin);
scanf(" %c",&goback);
if (goback == 'B') {
  main();
  }	else{
  	main();
  }
}

