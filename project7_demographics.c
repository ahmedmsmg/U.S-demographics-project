/*** Name: Ahmed Ghoneim..
 * This program is to sort states depending on the percentage of population for who is 65 years old+
 * ***/


#include<stdio.h>
//maximum num of states
#define max 100
//maximum num of state char
#define max_char 150
#include<string.h>

//structure for states
struct state {
	char name[max_char+1];
	int pop2020;
	int pop2010;
	double pop5;
	double pop18;
	double pop65;
};

void sort_states(struct state list[], int n);
int find_largest(struct state list[], int n);


int main() {

//array of structures
struct state a[max];
char name1[100];

printf("Input file name: ");
scanf("%s", name1);


//reading file from user's input
FILE *fp = fopen(name1, "r");
if(fp == NULL){
	printf("error");
	return 1;
}

int i= 0;
while(!feof(fp) && !ferror(fp)){
	fscanf(fp,"%[^,], %d, %d, %lf, %lf, %lf\n", a[i].name, &a[i].pop2020, &a[i].pop2010, &a[i].pop5, &a[i].pop18, &a[i].pop65 );
i++;
}

//closing file fp
fclose(fp);

//calling function sort_states
sort_states(a, i);


char str1[100];

strcpy(str1, "sorted_");
strcat(str1, name1);

//creatinng new file and writing the output
FILE *fw = fopen(str1, "w");
if(fw == NULL){
        printf("error");
        return 1;
}
int j;

for(j = i-1; j > i-52 ; j--)
{

	fprintf(fw, "%s, %d, %d, %.1lf, %.1lf, %.1lf\n", a[j].name, a[j].pop2020, a[j].pop2010, a[j].pop5, a[j].pop18, a[j].pop65 );

	
}
fclose(fw);

printf("Output file name: %s",str1);


return 0;
}

//sort states function that uses a nested for loop to sort the array of structers
void sort_states(struct state list[], int n)
{
	struct state temp;
	int i = 0;
	int j;
	
	while(i < n)
	{
		j = i;
		while(j < n)
		{
			if(list[j].pop65 < list[i].pop65){
				temp = list[i];
				list[i] = list[j];
				list[j] = temp; 	
			}
	j++;
}
i++;
}
}
