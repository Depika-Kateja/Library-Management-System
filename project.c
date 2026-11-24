#include <stdio.h> //has library functions like printf,scanf,getchar,fgets
#include <string.h> //has library functions like strcmp,strcspn
#include <stdlib.h>

//constants don't change their values unlike variables. The preprocessor replaces them with their value before compilation.
#define MAX_BOOKS 100
#define MAX_MEMBERS 100
#define MAX_ISSUES 200

// structures
struct Book
{
    int id;
    char title[100];
    char author[100];
    int totalCopies;
    int availableCopies;
};

struct Member
{
    int id;
    char name[100];
};

struct Issue
{
    int bookID;
    int memberID;
    int active;
};

// global arrays
struct Book books[MAX_BOOKS];
struct Member members[MAX_MEMBERS];
struct Issue issues[MAX_ISSUES];

// global counters
int bookCount = 0;
int memberCount = 0;
int issueCount = 0;

/* function declarations */

// do not return value
void password();
void AddBook();
void DeleteBook();
void SearchBook();
void DisplayBook();
void Author();
void TitleList();
void Stock();
void IssueBook();
void ReturnBook();
void AddMember();
void ExitProgram();

// returns integer
int FindBook(int id);
int FindMember(int id);

// do not reurn value
void ClearInput();
void ReadString(char str[], int size);

// function definitions


/* clears extra input from keyboard that might be left after scanf function*/

void ClearInput()
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF);
}


/* reads a string including its spaces */

void ReadString(char str[], int size)
{
    fgets(str, size, stdin);

    str[strcspn(str, "\n")] = '\0';
}


/* password*/
void password(){
	char pwd1[10] = {"admin"};
	char pwd[10];
	
	printf("\n Enter Password: ");
	scanf("%s",pwd);

	if(strcmp(pwd1,pwd) == 0){
		printf("\n Access Granted");
	}
	else{
		printf("\n Wrong Password. Try again.");
		password();
	}
}
/* finds a book using its ID */

int FindBook(int id)
{
    int i;

    for (i = 0; i < bookCount; i++)
    {
        if (books[i].id == id)
        {
            return i;
        }
    }

    return -1;
}


/* finds a member using their ID */

int FindMember(int id)
{
    int i;

    for (i = 0; i < memberCount; i++)
    {
        if (members[i].id == id)
        {
            return i;
        }
    }

    return -1;
}


/* 1. add book */

void AddBook()
{
    int id;

    if (bookCount >= MAX_BOOKS)
    {
        printf("\nLibrary book storage is full!\n");
        return;
    }

    printf("\nEnter Book ID: ");
    scanf("%d", &id);
    ClearInput();

    if (FindBook(id) != -1)
    {
        printf("Book ID already exists!\n");
        return;
    }

    books[bookCount].id = id;

    printf("Enter Book Title: ");
    ReadString(books[bookCount].title, 100);

    printf("Enter Author Name: ");
    ReadString(books[bookCount].author, 100);

    printf("Enter Number of Copies: ");
    scanf("%d", &books[bookCount].totalCopies);
    ClearInput();

    if (books[bookCount].totalCopies <= 0)
    {
        printf("Copies must be greater than zero!\n");
        return;
    }

    books[bookCount].availableCopies =
        books[bookCount].totalCopies;

    bookCount++;

    printf("\nBook added successfully!\n");
}

/* 2. delete book */

void DeleteBook()
{
    int id, index, i;

    printf("\nEnter Book ID to delete: ");
    scanf("%d", &id);
    ClearInput();

    index = FindBook(id);

    if (index == -1)
    {
        printf("Book not found!\n");
        return;
    }

    if (books[index].availableCopies !=
        books[index].totalCopies)
    {
        printf("Book cannot be deleted because copies are issued.\n");
        return;
    }

    for (i = index; i < bookCount - 1; i++)
    {
        books[i] = books[i + 1];
    }

    bookCount--;

    printf("Book deleted successfully!\n");
}

/* 3. Search books */
void SearchBook()
{
    int id, index;

    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);
    ClearInput();

    index = FindBook(id);

    if (index == -1)
    {
        printf("Book not found!\n");
    }
    else
    {
        printf("\nBook Found!\n");

        printf("Book ID: %d\n", books[index].id);
        printf("Title: %s\n", books[index].title);
        printf("Author: %s\n", books[index].author);
        printf("Total Copies: %d\n",
               books[index].totalCopies);
        printf("Available Copies: %d\n",
               books[index].availableCopies);
    }
}


/* 4. display all books */

void DisplayBook()
{
    int i;

    if (bookCount == 0)
    {
        printf("\nNo books available in the library.\n");
        return;
    }

    printf("\n========== ALL BOOKS ==========\n");

    for (i = 0; i < bookCount; i++)
    {
        printf("\nBook ID: %d\n", books[i].id);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Total Copies: %d\n",
               books[i].totalCopies);
        printf("Available Copies: %d\n",
               books[i].availableCopies);
    }
}

/* 5. author search */

void Author()
{
    char authorName[100];
    int i, found = 0;

    printf("\nEnter Author Name: ");
    ReadString(authorName, 100);

    printf("\nBooks written by %s:\n", authorName);

    for (i = 0; i < bookCount; i++)
    {
        if (strcmp(books[i].author, authorName) == 0)
        {
            printf("\nBook ID: %d\n", books[i].id);
            printf("Title: %s\n", books[i].title);
            printf("Available Copies: %d\n",
                   books[i].availableCopies);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("No books found for this author.\n");
    }
}


/* 6. title list in alphabetical order using bubble sorting */

void TitleList()
{
    int i, j;
    int temp;
    int order[MAX_BOOKS];

    if (bookCount == 0)
    {
        printf("\nNo books available.\n");
        return;
    }

    /* store book indexes */

    for (i = 0; i < bookCount; i++)
    {
        order[i] = i;
    }

    /* sort indexes according to title */

    for (i = 0; i < bookCount - 1; i++)
    {
        for (j = 0; j < bookCount - i - 1; j++)
        {
            if (strcmp(books[order[j]].title,books[order[j + 1]].title) > 0)
            {
                temp = order[j];

                order[j] = order[j + 1];

                order[j + 1] = temp;
            }
        }
    }

    printf("\n========== TITLE LIST ==========\n");

    for (i = 0; i < bookCount; i++)
    {
        printf("%d. %s\n",i + 1,books[order[i]].title);
    }
}

/* 7. stock information */

void Stock()
{
    int i;
    int total = 0;
    int available = 0;
    int issued = 0;

    printf("\n========== STOCK INFORMATION ==========\n");

    for (i = 0; i < bookCount; i++)
    {
        total += books[i].totalCopies;

        available += books[i].availableCopies;

        issued += books[i].totalCopies -
                  books[i].availableCopies;
    }

    printf("Total Different Books: %d\n", bookCount);
    printf("Total Book Copies: %d\n", total);
    printf("Available Copies: %d\n", available);
    printf("Issued Copies: %d\n", issued);

    printf("\nIndividual Stock:\n");

    for (i = 0; i < bookCount; i++)
    {
        printf("%s --> %d available out of %d\n",
               books[i].title,
               books[i].availableCopies,
               books[i].totalCopies);
    }
}





/* 8. issue a book */

void IssueBook()
{
    int bookID, memberID;
    int bookIndex, memberIndex;
    int i;

    if (issueCount >= MAX_ISSUES)
    {
        printf("Issue record storage is full!\n");
        return;
    }

    printf("\nEnter Book ID: ");
    scanf("%d", &bookID);

    printf("Enter Member ID: ");
    scanf("%d", &memberID);

    ClearInput();

    bookIndex = FindBook(bookID);
    memberIndex = FindMember(memberID);

    if (bookIndex == -1)
    {
        printf("Book does not exist!\n");
        return;
    }

    if (memberIndex == -1)
    {
        printf("Member does not exist!\n");
        return;
    }

    if (books[bookIndex].availableCopies <= 0)
    {
        printf("This book is currently unavailable!\n");
        return;
    }

    /* checks if this member already has this book */

    for (i = 0; i < issueCount; i++)
    {
        if (issues[i].bookID == bookID &&
            issues[i].memberID == memberID &&
            issues[i].active == 1)
        {
            printf("This member already has this book issued!\n");
            return;
        }
    }

    issues[issueCount].bookID = bookID;
    issues[issueCount].memberID = memberID;
    issues[issueCount].active = 1;

    issueCount++;

    books[bookIndex].availableCopies--;

    printf("\nBook issued successfully!\n");
    printf("Book: %s\n", books[bookIndex].title);
    printf("Member: %s\n", members[memberIndex].name);
}


/* 9. returning a book */

void ReturnBook()
{
    int bookID, memberID;
    int bookIndex, memberIndex;
    int i, found = 0;

    printf("\nEnter Book ID: ");
    scanf("%d", &bookID);

    printf("Enter Member ID: ");
    scanf("%d", &memberID);

    ClearInput();

    bookIndex = FindBook(bookID);
    memberIndex = FindMember(memberID);

    if (bookIndex == -1 || memberIndex == -1)
    {
        printf("Invalid Book ID or Member ID!\n");
        return;
    }

    for (i = 0; i < issueCount; i++)
    {
        if (issues[i].bookID == bookID &&
            issues[i].memberID == memberID &&
            issues[i].active == 1)
        {
            issues[i].active = 0;

            books[bookIndex].availableCopies++;

            printf("\nBook returned successfully!\n");
            printf("Book: %s\n", books[bookIndex].title);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("This book was not issued to this member.\n");
    }
}


/* 10. add a member */

void AddMember()
{
    int id;

    if (memberCount >= MAX_MEMBERS)
    {
        printf("Member storage is full!\n");
        return;
    }

    printf("\nEnter Member ID: ");
    scanf("%d", &id);
    ClearInput();

    if (FindMember(id) != -1)
    {
        printf("Member ID already exists!\n");
        return;
    }

    members[memberCount].id = id;

    printf("Enter Member Name: ");
    ReadString(members[memberCount].name, 100);

    memberCount++;

    printf("\nMember added successfully!\n");
}


/* 11. exit function */

void ExitProgram()
{
    printf("\nThank you for using the Library Management System!\n");
    exit(0);
    /* stdlib provides exit as a built in function used to exit the program */
}


/* main function */

int main()
{
	password();
    int choice;
	/* use do while loop for menu as it needs to be executed atleast once */
    do
    {
        printf("\n");
        printf("====================================\n");
        printf("      LIBRARY MANAGEMENT SYSTEM\n");
        printf("====================================\n");

        printf("1. Add Book\n");
        printf("2. Delete Book\n");
        printf("3. Search Book\n");
        printf("4. Display All Books\n");
        printf("5. Author\n");
        printf("6. Title List\n");
        printf("7. Stock\n");
        printf("8. Issue Book\n");
        printf("9. Return Book\n");
        printf("10. Add Member\n");
        printf("11. Exit\n");

        printf("------------------------------------\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        ClearInput();

        switch (choice)
        {
            case 1:
                AddBook();
                break;

            case 2:
                DeleteBook();
                break;

            case 3:
                SearchBook();
                break;

            case 4:
                DisplayBook();
                break;

            case 5:
                Author();
                break;

            case 6:
                TitleList();
                break;

            case 7:
                Stock();
                break;

            case 8:
                IssueBook();
                break;

            case 9:
                ReturnBook();
                break;

            case 10:
                AddMember();
                break;

            case 11:
                ExitProgram();
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
		

    } while (choice != 11);

    return 0;
}
