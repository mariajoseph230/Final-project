#include <iostream>
#include <fstream>
using namespace std;
typedef struct student{
char name[20];
int rollno;
string clss;
struct subject{
    int subcode;
    char subname[20];
    int mark;
}sub[5];
int total;
float per;
}student;
void create(){
        student *s;
        FILE *fp;
        int n,i,j;

        cout<<"Enter number of students : ";
        cin>>n;
        s = (student*)calloc(n,sizeof(student));
        fp = fopen("mystudents1.txt","w+");

        for(i=0;i<n;i++){
            s[i].total=0;
            s[i].per=0;
            cout<<"Enter RollNo : "<<endl;
            cin>>s[i].rollno;
            fflush(stdin);
            cout<<"Enter Name : ";
            cin>>s[i].name;
            for(j=0;j<5;j++){
                cout<<"Enter Marks of Sub :\n "<<j+1;
                cin>>s[i].sub[j].mark;
                s[i].total += s[i].sub[j].mark;
            }
            s[i].per = s[i].total / 5.0;

            fwrite(s+i,sizeof(student),1,fp);
        }
        fclose(fp);
}


void append(){
        student *s, s1;
        FILE *fp;
        int n,i,j;

       cout<<"Enter number of students : ";
        cin>>n;
        s = (student*)calloc(n,sizeof(student));
        fp = fopen("mystudents1.txt","a");

        for(i=0;i<n;i++){
            s[i].total=0;
            s[i].per=0;
            cout<<"Enter RollNo : "<<endl;
            cin>>s[i].rollno;
            fflush(stdin);
            cout<<"Enter Name : ";
            cin>>s[i].name;
            for(j=0;j<5;j++){
                cout<<"Enter Marks of Sub : "<<j+1;
                cin>>s[i].sub[j].mark;
                s[i].total += s[i].sub[j].mark;
            }
            s[i].per = s[i].total / 5.0;
            fwrite(s+i,sizeof(student),1,fp);
        }
        fclose(fp);
}


void update(){
    int i, j, found=0;
    student s1;
    FILE *fp, *fp1;
    int rollno;
    cout<<"Enter RollNo to Update : ";
    cin>>rollno;

    fp = fopen("mystudents1.txt","r");
    fp1 = fopen("temp.txt","w");
    while(fread(&s1,sizeof(student),1,fp)){
        if(s1.rollno == rollno){
            found = 1;
            s1.total=0;
            s1.per=0;
            fflush(stdin);
            cout<<"Enter New Name : ";
            cin>>s1.name;
            for(j=0;j<5;j++){
                cout<<"Enter New Marks of Sub : "<<j+1;
                cin>>s1.sub[j].mark;
                s1.total += s1.sub[j].mark;
            }
            s1.per = s1.total / 5.0;
        }
        fwrite(&s1,sizeof(student),1,fp1);
    }
    fclose(fp);
    fclose(fp1);


    if(found){
            fp = fopen("mystudents1.txt","w");
            fp1 = fopen("temp.txt","r");

            while(fread(&s1,sizeof(student),1,fp1)){
                fwrite(&s1,sizeof(student),1,fp);
            }
            fclose(fp);
            fclose(fp1);
    }
    else
        cout<<"\nNot Found.....\n"<<endl;
}


void delete_rec(){
    int i, j, found=0;
    student s1;
    FILE *fp, *fp1;
    int rollno;
    cout<<"Enter RollNo to Delete : ";
    cin>>rollno;

    fp = fopen("mystudents1.txt","r");
    fp1 = fopen("temp.txt","w");
    while(fread(&s1,sizeof(student),1,fp)){
        if(s1.rollno == rollno){
            found = 1;
        }
        else
            fwrite(&s1,sizeof(student),1,fp1);
    }
    fclose(fp);
    fclose(fp1);


    if(found){
            fp = fopen("mystudents1.txt","w");
            fp1 = fopen("temp.txt","r");

            while(fread(&s1,sizeof(student),1,fp1)){
                fwrite(&s1,sizeof(student),1,fp);
            }
            fclose(fp);
            fclose(fp1);
    }
    else
        cout<<"\nNot Found.....\n";
}
void display(){
        student s1;
        FILE *fp;
        int j;
        fp = fopen("mystudents1.txt","r");
        while(fread(&s1,sizeof(student),1,fp))
        {
            cout<<"Rollnumber of student: "<<s1.rollno<<endl;
            cout<<"name of student: "<<s1.name<<endl;
            for(j=0;j<=5;j++){
                cout<<"mark for subject: "<<s1.sub[j].mark<<"\n\n"<<endl;
            }
            cout<<"total"<<s1.total,s1.per;
        }
        fclose(fp);
}

int main(){
    int ch;
    do{
        printf("\n1.CREATE");
        printf("\n2.APPEND");
        printf("\n3.DISPLAY");
        printf("\n4.UPDATE");
        printf("\n5.DELETE");
        printf("\n0.EXIT");
        printf("\nEnter Your Choice : ");
        scanf("%d",&ch);
        switch(ch){
        case 1:
                create();
            break;
        case 2:
                append();
            break;
        case 3:
                display();
            break;

        case 4:
                update();
            break;
            case 5:
                delete_rec();
            break;
        case 0:
                printf("\n\nThanks.....\n\n");
        }
        }while(ch!=0);

    return 0;
}
