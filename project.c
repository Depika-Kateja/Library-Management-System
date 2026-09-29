#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void password();
void menu();
void BookManagement();
void MemberManagement();
void Help();
void BookList();
void SearchBook();
void AddBook();
void DeleteBook();
void IssueBook();
void ReturnBook();
void AddMember();
void DeleteMember();
void SearchMember();
void Upgrade();
void ViewMemberList();

int t=1;

struct BookInfo{
	int id;
	char title[50];
	char author[50];
	char category[50];
	char genre[50];
	int quantity;
};

struct BookInfo a;

FILE *file;

int main(){
	printf("\n\n ********************** Library Management System ****************************** \n\n");
	password();
}

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


void menu(){
	int choice;
	printf("\n ******************* Main Menu ************************ ");
	printf("\n 1. Book Management");
	printf("\n 2. Member Management");
	printf("\n 3. Help");
	printf("\n 4. Exit");
	printf("\n ******************************************************** ");
	printf("\n Enter your choice");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			BookManagement();
		break;
		case 2:
			MemberManagement();
		break;
		case 3:
			Help();
		break;
		case 4:
			exit(0);
		break;
		default:
			printf("\n Enter choices from 1 to 4:");	
		break;	
	}	
}

void BookManagement(){
		int BookChoice;
		printf("\n*********************** Book Management ********************************");
		printf("\n 1. View Book List");
		printf("\n 2. Search Book");
		printf("\n 3. Add Book");
		printf("\n 4. Delete Book");
		printf("\n 5. Issue Book");
		printf("\n 6. Return Book");
		printf("\n************************************************************************");
		printf("\n Enter your Choice");
		scanf("%d",&BookChoice);
		switch(BookChoice){
		case 1:
			BookList();
		break;
		case 2:
			SearchBook();
		break;
		case 3:
			AddBook();
		break;
		case 4:
			DeleteBook();
		break;
		case 5:
			IssueBook();
		break;
		case 6:
			ReturnBook();
		break;
		default:
			printf("\n Enter choices from 1 to 6:");	
		break;	
	}
	}
	
	void MemberManagement(){
		int Member;
		printf("\n************************* Member Management ******************************");
		printf("\n 1. Add Member");
		printf("\n 2. Delete Member");
		printf("\n 3. Search Member");
		printf("\n 4. Ugrade a Member to Vip");
		printf("\n 5. View All Members");
		printf("\n *************************************************************************");
		printf("\n Enter your choice");
		scanf("%d",&Member);
		switch(Member){
		case 1:
			AddMember();
		break;
		case 2:
			DeleteMember();
		break;
		case 3:
			SearchMember();
		break;
		case 4:
			Upgrade();
		break;
		case 5:
			ViewMemberList();
		break;
		default:
			printf("\nEnter choices from 1 to 5:");	
		break;	
	}
}
	
	void Help(){
		printf("\n************************* Help ******************************");
	}
	
	void BookList(){

	}
	
	void SearchBook(){
	}
	
	void AddBook(){
		printf("*************** Adding Book *****************\n");

		int d;
		
		file = fopen("books.txt","w");

		printf("Enter Book ID: ");
		scanf("%d",&d);

		fprintf(file, "%d", d);
	}
	
	void DeleteBook(){
	}
	
	void IssueBook(){
	}
	
	void ReturnBook(){
	}
	
	void AddMember(){
	}
	
	void DeleteMember(){
	}
	
	void Upgrade(){
	}
	
	void SearchMember(){
	}
	
	void ViewMemberList(){
	}
