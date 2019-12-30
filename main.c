#include <stdio.h>
#include <stdlib.h>

struct BasicInfo{
    char name[20];
    char email[30];
    long long int mob;
    char city[20];
    char state[20];
};

struct University{
    char name[50];
    char degree[30];
    int passout1;
    float cgpa;
};

struct School{
    char name[30];
    int passout2;
    float cgpa;
};

int main()
{
    FILE *fp;
    char loc[] = {"D:\\Resume.txt"};
    fp=fopen(loc,"w+");
    if(fp==NULL){
        printf("File cannot be opened!");
        return 1;
    }

    struct BasicInfo B;
    struct University U;
    struct School S;
    char pass[]={"Passout Year: "};
    char cgpa[]={"CGPA: "};
    int i;

    //Basic Info
    printf("\t\tENTER YOUR BASIC INFO \n");
    printf("Enter your name:");
    gets(B.name);
    printf("Enter your email:");
    scanf("%s",B.email);
    printf("Enter your Mobile No:");
    scanf("%lld",&B.mob);
    printf("Enter City:");
    scanf("%s",B.city);
    fflush(stdin);
    printf("Enter State:");
    gets(B.state);
    fprintf(fp,"\n\n%s \n%s \n%lld \n%s \n%s",B.name,B.email,B.mob,B.city,B.state);
    fprintf(fp,"\n\n---------------------------------------------------------------------\n");
    fflush(stdin);

    //Career objective
    printf("\n\t\tCareer Objective(within 50 words)- \n");
    char objective[300];
    gets(objective);
    fprintf(fp,"\nCAREER OBJECTIVE- \n\n");
    fprintf(fp,"\t%s \n", objective);
    fprintf(fp,"\n---------------------------------------------------------------------\n");

    //Education
    printf("\n\t\tENTER YOUR EDUCATION QUALIFICATION\nUNIVERSITY\n");
    fprintf(fp,"\nEDUCATION");
    printf("College name:");
    gets(U.name);
    printf("Degree:");
    gets(U.degree);
    printf("Passout Year:");
    scanf("%d",&U.passout1);
    printf("Enter CGPA:");
    scanf("%f",&U.cgpa);
    fprintf(fp,"\n\n\tUNIVERSITY- \n");

    fprintf(fp,"\n\t\t%s \n\t\t%s \n\t\t%s%d \n\t\t%s%.2f",U.name, U.degree, pass ,U.passout1, cgpa, U.cgpa);

    fflush(stdin);

    //School
    printf("\nSCHOOL\nEnter School name:");
    gets(S.name);
    printf("Enter passout year:");
    scanf("%d",&S.passout2);
    printf("Enter CGPA:");
    scanf("%f",&S.cgpa);
    fprintf(fp,"\n\n\tSCHOOL- \n");
    fprintf(fp,"\n\t\t%s \n\t\t%s%d \n\t\t%s%.2f",S.name, pass, S.passout2, cgpa, S.cgpa);
    fprintf(fp,"\n\n---------------------------------------------------------------------\n");
    fflush(stdin);

    //Skills

    char skill[5][10];
    fprintf(fp,"\nSKILLS-\n");
    printf("\n\t\tSkills\nEnter your top five(5) skills-\n");
    for(i=0; i<5; i++){
        gets(skill[i]);
        fprintf(fp,"\n\t%s",skill[i]);
        fflush(stdin);
    }
    fprintf(fp,"\n\n---------------------------------------------------------------------\n");

    //Other Profiles
    char profile[3][30];
    char id[3][15]={"LinkedIn: ","Github: ","HackerRank: "};
    fprintf(fp,"\nOTHER PROFILES-\n");
    printf("\n\t\tOther Profiles:\n");
    for(i=0; i<3; i++){
            printf("%s ",id[i]);
            gets(profile[i]);
            fprintf(fp,"\n\t%s%s",id[i],profile[i]);
    }
    fprintf(fp,"\n\n---------------------------------------------------------------------\n");


    printf("Resume created successfully at D:\\Resume.txt!!\n");
    fclose(fp);
    system("pause");
    return 0;
}
