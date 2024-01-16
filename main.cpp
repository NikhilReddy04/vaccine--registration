#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct mynode {
	char name[20];
	char gen[6];
	char idtype[40];
	char id[20];
	char mob[20];
	char comor[3];
	struct mynode* link;
} Node;
Node* start = NULL;
int n;
char state[20], dis[20], hos[40], date[12], hour[6];
void heading();
void details();
void venue();
void receipt();
void main()
{
	details();
	venue();
	receipt();
}
void details()
{
	int i;
	char a[20], b[6], c[40], d[20], e[20], f[3];
	heading();
	printf(
		"\t\t\t\tEnter Candidate Number (Max 4 People): ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		system("clear");
		heading();
		printf("\t\t\t\tEnter The %dth Candidate Name: ",
			i);
		fflush(stdin);
		gets(a);
		printf("\t\t\t\tEnter The %dth Candidate Gender: ",
			i);
		fflush(stdin);
		gets(b);
		printf("\t\t\t\tEnter The %dth Candidate Id-Type: ",
			i);
		fflush(stdin);
		gets(c);
		printf(
			"\t\t\t\tEnter The %dth Candidate Id-Number: ",
			i);
		fflush(stdin);
		gets(d);
		printf("\t\t\t\tEnter The %dth Candidate Mobile "
			"Number: ",
			i);
		fflush(stdin);
		gets(e);
		printf("\t\t\t\tEnter The %dth Candidate "
			"Co-Morbidity Status (Yes or No): ",
			i);
		fflush(stdin);
		gets(f);
		addnode(a, b, c, d, e, f);
	}
}
void addnode(char a[20], char b[6], char c[40], char d[20],
			char e[20], char f[3])
{
	Node *newptr = NULL, *ptr;
	newptr = (Node*)malloc(sizeof(Node));
	strcpy(newptr->name, a);
	strcpy(newptr->gen, b);
	strcpy(newptr->idtype, c);
	strcpy(newptr->id, d);
	strcpy(newptr->mob, e);
	strcpy(newptr->comor, f);
	newptr->link = NULL;
	if (start == NULL)
		start = newptr;
	else {
		ptr = start;
		while (ptr->link != NULL)
			ptr = ptr->link;
		ptr->link = newptr;
	}
}
void venue()
{
	int i, x = 0;
	system("clear");
	heading();
	printf("\t\t\t\tEnter State: ");
	gets(state);
	printf("\t\t\t\tEnter District: ");
	gets(dis);
	printf("\t\t\t\tEnter Date (DD-MM-YY): ");
	gets(date);
	printf("\t\t\t\tEnter Time (24 Hours): ");
	gets(hour);
	system("clear");
	heading();
	printf("\t\t\t\t1. GFG Hospital\n");
	printf("\t\t\t\t2. Zilla Hospital\n");
	printf("\t\t\t\t3. DS Hospital\n");
	do {
		printf("\t\t\t\tEnter Choice: ");
		scanf("%d", &i);
		if (i == 1)
			strcpy(hos, "GFG Hospital");
		else if (i == 2)
			strcpy(hos, "Zilla Hospital");
		else if (i == 3)
			strcpy(hos, "DS Hospital");
		else {
			printf("Enter Correct Choice...");
			x = 0;
		}
	} while (x);
}
void receipt()
{
	int i;
	Node* ptr = start;
	system("cls");
	heading();
	printf(
		"\n\t\t\t\t**Take Screenshot For Further Use**\n");
	for (i = 1; i <= n; i++) {
		printf("\t\t\t\t%dst Candidate Name: ", i);
		puts(ptr->name);
		printf("\t\t\t\t%dst Candidate Gender: ", i);
		puts(ptr->gen);
		printf("\t\t\t\t%dst Candidate Id-type: ", i);
		puts(ptr->idtype);
		printf("\t\t\t\t%dst Candidate Id Number: ", i);
		puts(ptr->id);
		printf("\t\t\t\t%dst Candidate Mobile Number: ", i);
		puts(ptr->mob);
		printf(
			"\t\t\t\t%dst Candidate Co-Morbidity Status: ",
			i);
		puts(ptr->comor);
		printf("\n");
		ptr = ptr->link;
	}
	printf("\t\t\t\tState: ");
	puts(state);
	printf("\t\t\t\tDistrict: ");
	puts(dis);
	printf("\t\t\t\tDate: ");
	puts(date);
	printf("\t\t\t\tTime: ");
	puts(hour);
	printf("\t\t\t\tChosen Hospital: ");
	puts(hos);
	printf("\n\t\t\t\t**Thank You For registration**");
}
void heading()
{
	printf(
		"\t\t\t\t***Covid Vaccination Registration***\n");
	printf("\t\t\t***Take Vaccine At Your Time & Fight "
		"Against Corona***\n\n");
}
