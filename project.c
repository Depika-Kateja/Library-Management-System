#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define IN 1
#define OUT 0

int menu();
void password();
void Addbook();
void Searchbook();
void Displaybook();
void Author();
void Titlelist();
void Stock();
void Issue();
void bookret();
void Addmembr();
void Exit();

char info[500];

struct
{
  int bid;
  char bname[25] ;
  char author[25];
  int nooftitles;
  char titles[500];
  int status;
}book;
struct
{
  int mid;
  char mname[25] ;
  char department[25];
  int availibcard;
  int phno;

}membr;

int t;
void password(){
	char pwd1[10] = {"admin"};
	char pwd[10];
	
	printf("\n Enter Password: ");
	scanf("%s",&pwd);

	if(strcmp(pwd1,pwd) == 0){
		printf("\n Access Granted");
		menu();
	} else {
		//t represents no. of tries if it exceeds three tries the program ends
		if(t == 3){
			exit(0);
		}
		t++;
		printf("\n Access Denied");
		printf("\n Try again:");
		password();
	}
}
int main()
{
    int i;

    printf("\n\t\t---Library Management System by Asif Ahmed Neloy---\n");
    password();
    menu();
 return (0);
}
