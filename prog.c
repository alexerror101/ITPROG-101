#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee{                //This declares a struct type containing all information of a employee globally            

    int id;
    char name[55];              
    char designation[30];
    char department[30];
    char doj[10];
    int salary;
    int increment;
    int decrement;
};

void enteremployee(){

    struct Employee *e;
    int i = 0, i1;
    char choice = 'y';
    int count=0;
    printf("Enter how many employee records you want to enter:");
    scanf("%d" , &i1);

    e = (struct Employee *)malloc(i1 * sizeof(struct Employee));

    FILE *fp = fopen("employee_details.txt","a");

    while((choice == 'Y' || choice == 'y') && (i < i1) ){

        printf("Enter the Employee ID:\n");
        scanf("%d",&((e + i))->id);

        printf("Enter the Employee name:\n");
        scanf(" %[^\n]",(e + i)->name);

        printf("Enter the designation:\n");
        scanf(" %[^\n]",(e + i)->designation);

        printf("Enter Employee's department:\n");
        scanf(" %[^\n]",(e + i)->department);

        printf("Enter date of joining of the Employee(DD/MM/YYYY):\n");
        scanf(" %[^\n]",(e + i)->doj);

        printf("Enter the Employee's monthly salary(in rupees):\n");
        scanf("%d",&((e + i))->salary);

        printf("Enter the increment precentage(per annum):\n");
        scanf("%d",&((e + i))->increment);

        printf("Enter the decrement percentage(per annum):\n");
        scanf("%d",&((e + i))->decrement);
        
        fprintf(fp,"Employee ID: %d \nEmployee's Name: %s \nDesignation: %s \nDepartment: %s \nDate of joining: %s \nMonthly salary: %d \nIncrement: %d \nDecrement: %d \n\n",
                        (e + i)->id,(e + i)->name,(e+i)->designation,(e+i)->department,(e+i)->doj,
                        (e+i)->salary,(e+i)->increment,(e+i)->decrement);
        
        i++;
        
         if (i < i1) {
            printf("\nDo you wish to continue (Y/N)? ");
            scanf(" %c", &choice);
            }

    }
	
    fclose(fp);
   
   printf("Employee Record Stored Successfully!!");

}

void displayinfo(){

    FILE *fp = fopen("employee_details.txt","r");
    char ch;


    while((ch = fgetc(fp))!= EOF){
        printf("%c",ch);
    }

    fclose(fp);

}

void deleterecords(int deleteid) {
    FILE *fp = fopen("employee_details.txt", "r+");
    FILE *temp= fopen("temp_employee_details.txt", "w+");

    struct Employee emp;
   
    while (fscanf(fp, "Employee ID: %d \nEmployee's Name: %s \nDesignation: %s \nDepartment: %s \nDate of joining: %s \nMonthly salary: %d \nIncrement: %d \nDecrement: %d \n\n",
                  &emp.id, emp.name, emp.designation, emp.department,
                  emp.doj, &emp.salary, &emp.increment, &emp.decrement) == 8){
        if (emp.id != deleteid) {
            fprintf(temp, "Employee ID: %d \nEmployee's Name: %s \nDesignation: %s \nDepartment: %s \nDate of joining: %s \nMonthly salary: %d \nIncrement: %d \nDecrement: %d \n\n",
                    emp.id, emp.name, emp.designation, emp.department,
                    emp.doj, emp.salary, emp.increment, emp.decrement);

                  }
    }
    fclose(temp);
    fclose(fp);

    remove("employee_details.txt");
    rename("temp_employee_details.txt", "employee_details.txt");
    
    printf("Employee with ID %d deleted successfully.\n", deleteid);
}


void updaterecord(int updateid){

    FILE *fp = fopen("employee_details.txt","r+");
    FILE *tempfile = fopen("temp_employee_details2.txt","a+") ;

    struct Employee emp;

    while (fscanf(fp, "Employee ID: %d \nEmployee's Name: %s \nDesignation: %s \nDepartment: %s \nDate of joining: %s \nMonthly salary: %d \nIncrement: %d \nDecrement: %d \n\n",
                  &emp.id, emp.name, emp.designation, emp.department,
                  emp.doj, &emp.salary, &emp.increment, &emp.decrement) == 8){
        if (emp.id != updateid) {
            fprintf(tempfile, "Employee ID: %d \nEmployee's Name: %s \nDesignation: %s \nDepartment: %s \nDate of joining: %s \nMonthly salary: %d \nIncrement: %d \nDecrement: %d \n\n",
                    emp.id, emp.name, emp.designation, emp.department,
                    emp.doj, emp.salary, emp.increment, emp.decrement);

                  }
    }

    int flag = 0;
    struct Employee *emp1 = (struct Employee *)malloc(sizeof(struct Employee));


        printf("Enter the Employee ID:\n");
        scanf("%d",&(emp1)->id);

        printf("Enter the Employee name:\n");
        scanf(" %[^\n]",(emp1)->name);

        printf("Enter the designation:\n");
        scanf(" %[^\n]",(emp1)->designation);

        printf("Enter Employee's department:\n");
        scanf(" %[^\n]",(emp1)->department);

        printf("Enter date of joining of the Employee(DD/MM/YYYY):\n");
        scanf(" %[^\n]",(emp1)->doj);

        printf("Enter the Employee's monthly salary(in rupees):\n");
        scanf("%d",&(emp1)->salary);

        printf("Enter the increment precentage(per annum):\n");
        scanf("%d",&(emp1)->increment);

        printf("Enter the decrement percentage(per annum):\n");
        scanf("%d",&(emp1)->decrement);
        
        fprintf(tempfile,"Employee ID: %d \nEmployee's Name: %s \nDesignation: %s \nDepartment: %s \nDate of joining: %s \nMonthly salary: %d \nIncrement: %d \nDecrement: %d \n\n",
                        (emp1)->id,(emp1)->name,(emp1)->designation,(emp1)->department,(emp1)->doj,
                        (emp1)->salary,(emp1)->increment,(emp1)->decrement);
        
        flag++; 

    

    fclose(fp);
    fclose(tempfile);

    remove("employee_details.txt");
    rename("temp_employee_details2.txt","employee_details.txt");


}


void searchrecord(){

    int searchid;
    char designation1[30];
    char department1[30];
    char doj1[10];

    printf("\nPlease enter the ID of the Employee of be reached:");
    scanf("%d",&searchid);

    printf("\nPlease enter the designation of the Employee:");
    scanf(" %[^\n]s",designation1);

    printf("\nPlease enter the department of the Employee:");
    scanf(" %[^\n]s",department1);

    printf("\nPlease enter the date of joining of the Employee:");
    scanf(" %[^\n]s",doj1);

    FILE *fp = fopen("employee_details.txt","r");
    
    struct Employee emp;

    while (fscanf(fp, "Employee ID: %d \nEmployee's Name: %s \nDesignation: %s \nDepartment: %s \nDate of joining: %s \nMonthly salary: %d \nIncrement: %d \nDecrement: %d \n\n",
                  &emp.id, emp.name, emp.designation, emp.department,
                  emp.doj, &emp.salary, &emp.increment, &emp.decrement) == 8)
    {
        

        if (emp.id == searchid || strcmp(emp.designation, designation1) == 0 ||
            strcmp(emp.department, department1) == 0 ||
            strcmp(emp.doj, doj1) == 0 ){

        printf("\n\nThe employee's details are displayed below:\n\n");
        printf("Employee ID: %d\nEmployee's Name: %s\nDesignation: %s\nDepartment: %s\nDate of joining: %s\nMonthly salary: %d\nIncrement: %d\nDecrement: %d\n\n",
                   emp.id, emp.name, emp.designation, emp.department,
                   emp.doj, emp.salary, emp.increment, emp.decrement);

                break;
            }
            
        
        }

        fclose(fp);
    }

   









int main(){

    int choice;
    
    printf("\t\t\tWelcome to our program.");

    while(1){
    printf("\n\n\nWhat do you wish to do? \n\n1.Enter Employee Records.\t\t2.Display all the Employee records.\n3.Delete an Employee Record.\t\t4.Update Employee Records.\n5.Search an Employee Record\t\t6.Exit\n\n");

    printf("Select your choice: ");
    scanf("%d",&choice);

    switch(choice){

        case 1: enteremployee();
                break;

        case 2: displayinfo();
                break;  

        case 3: 
                int deleteid;
                printf("\nPlease enter the Employee ID to be deleted:");
                scanf("%d",&deleteid);

                deleterecords(deleteid);
                break;

        case 4: int updateid;
                printf("\nTo edit records, please input the employee's ID:");
                scanf("%d", &updateid);
                
                updaterecord(updateid);
                break;

        case 5: searchrecord();
                break;
        
        case 6: return 0;       
    }    

    }
   
}
