/*
 Student Management System 
 
 Features:
 1. Add Student
 2. Display Students
 3. Search by Roll No
 4. Update Student
 5. Delete Student
 6. Exit
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student{
    char name[50];
    int rollno;
    int age;
    char gender;
    int semester;
    char section;
    char mobileno[15];
    char email[100];
    char address[100];
    int totalclasses;
    int classattended;
    float attendance;
    char feesstatus[20];
    char department[50];
}S;

void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

int main(){
    int ch;
    do{
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1.Add Student\n2.Display Students\n3.Search Student\n4.Update Student\n5.Delete Student\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:addStudent();break;
            case 2:displayStudents();break;
            case 3:searchStudent();break;
            case 4:updateStudent();break;
            case 5:deleteStudent();break;
            case 6:printf("Thank You!\n");break;
            default:printf("Invalid Choice\n");
        }
    }while(ch!=6);
    return 0;
}

void addStudent(){
    FILE *fp=fopen("students.dat","ab");
    S s;
    printf("Name: ");
     scanf("%49s",s.name);
    printf("Roll No: ");
     scanf("%d",&s.rollno);
    printf("Age: ");
     scanf("%d",&s.age);
    printf("Gender(M/F): ");
     scanf(" %c",&s.gender);
    printf("Semester: "); 
    scanf("%d",&s.semester);
    printf("Section: ");
     scanf(" %c",&s.section);
    printf("Mobile: "); 
    scanf("%14s",s.mobileno);
    printf("Email: ");
     scanf("%99s",s.email);
    printf("Address: "); 
    scanf("%99s",s.address);
    printf("Total Classes: "); 
    scanf("%d",&s.totalclasses);
    printf("Classes Attended: ");
     scanf("%d",&s.classattended);
    s.attendance=((float)s.classattended/s.totalclasses)*100;
    printf("Fee Status: ");
     scanf("%19s",s.feesstatus);
    printf("Department: "); 
    scanf("%49s",s.department);
    fwrite(&s,sizeof(S),1,fp);
    fclose(fp);
    printf("Student Added Successfully.\n");
}

void displayStudents(){
    FILE *fp=fopen("students.dat","rb");
    S s;
    if(!fp){printf("No records.\n");return;}
    while(fread(&s,sizeof(S),1,fp)){
        printf("\n------------------------\n");
        printf("Name: %s\nRoll: %d\nAge: %d\nGender: %c\nSemester: %d\nSection: %c\n",s.name,s.rollno,s.age,s.gender,s.semester,s.section);
        printf("Mobile: %s\nEmail: %s\nAddress: %s\n",s.mobileno,s.email,s.address);
        printf("Attendance: %.2f%%\nFee: %s\nDepartment: %s\n",s.attendance,s.feesstatus,s.department);
    }
    fclose(fp);
}

void searchStudent(){
    FILE *fp=fopen("students.dat","rb");
    S s; int roll,found=0;
    if(!fp){printf("No records.\n");return;}
    printf("Enter Roll No: ");
    scanf("%d",&roll);
    while(fread(&s,sizeof(S),1,fp)){
        if(s.rollno==roll){
            found=1;
            printf("Name:%s\nDepartment:%s\nAttendance:%.2f%%\n",s.name,s.department,s.attendance);
            break;
        }
    }
    if(!found) printf("Student Not Found.\n");
    fclose(fp);
}

void updateStudent(){
    FILE *fp=fopen("students.dat","rb+");
    S s; int roll,found=0;
    if(!fp){printf("No records.\n");return;}
    printf("Enter Roll No: ");
    scanf("%d",&roll);
    while(fread(&s,sizeof(S),1,fp)){
        if(s.rollno==roll){
            found=1;
            printf("New Mobile: "); scanf("%14s",s.mobileno);
            printf("New Email: "); scanf("%99s",s.email);
            printf("New Fee Status: "); scanf("%19s",s.feesstatus);
            fseek(fp,-(long)sizeof(S),SEEK_CUR);
            fwrite(&s,sizeof(S),1,fp);
            printf("Updated Successfully.\n");
            break;
        }
    }
    if(!found) printf("Student Not Found.\n");
    fclose(fp);
}

void deleteStudent(){
    FILE *fp=fopen("students.dat","rb");
    FILE *temp=fopen("temp.dat","wb");
    S s; int roll,found=0;
    if(!fp){printf("No records.\n");return;}
    printf("Enter Roll No: ");
    scanf("%d",&roll);
    while(fread(&s,sizeof(S),1,fp)){
        if(s.rollno==roll){found=1;continue;}
        fwrite(&s,sizeof(S),1,temp);
    }
    fclose(fp); fclose(temp);
    remove("students.dat");
    rename("temp.dat","students.dat");
    if(found) printf("Deleted Successfully.\n");
    else printf("Student Not Found.\n");
}
