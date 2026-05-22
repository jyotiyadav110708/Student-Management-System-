#include<iostream>
#include<fstream>
using namespace std;
class Student{
	public:
	string name;
	int rollnum;
	int marks;
	
	void setdata(){
		cout<<"Enter name of student "<<endl;
		cin.ignore();
		getline(cin, name);
		cout<<"Enter Roll number of Student "<<endl;
		cin>>rollnum;
		cout<<"Enter Marks of Student "<<endl;
		cin>>marks;
	}
	void display(){
		cout<<" \nName: "<<name<<"\nRoll Number: "<<rollnum<<"\nMarks: "<<marks<<endl;
		}
	};	
		void savetofile(Student s){
			ofstream file("student.txt", ios::app);
			file<< s.name<<endl;
			file<< s.rollnum<<endl;
			file<< s.marks<<endl;
			file.close();
		}
		
		void loadfromfile(Student s[], int &total){
			ifstream file("student.txt");
			while(getline(file, s[total].name)){
				file>>s[total].rollnum;
				file>>s[total].marks;
				file.ignore();
				total++;
			}
			file.close();
		}
		
		void rewritefile(Student s[], int total){
			ofstream file("student.txt");
			for(int i=0; i< total; i++){
				file<<s[i].name<<endl;
				file<<s[i].rollnum<<endl;
				file<<s[i].marks<<endl;
			}
			file.close();
		}
	//Add karne ke liye
	
	void add(Student s[], int &total){
		
		cout<<"\n***Student number: "<<total+1<<"***"<<endl;
		s[total].setdata();
		savetofile(s[total]);
		total++;
		
	}
	// Display karne ke liye
	
	void show(Student s[], int total){
	cout<<"\n------Displaying Data of Total Students-------\n";
	for(int i=0; i<total; i++){
		cout<<"\nData of Student "<<i+1<<endl;
		s[i].display();
			}
		}
		//Delete karne ke liye
		
	void Delete(Student s[], int &total){
		int id ,found=0;
		cout<<"Enter roll number to delete ";
		cin>>id;
		for(int i=0;i<total;i++){
			if(s[i].rollnum==id){
				found=1;
				for(int j=i;j<total-1;j++){
					s[j]=s[j+1];
				}
				total--;
				rewritefile(s, total);
				cout<<"Student delete successfully \n";
				break;
			}
		}
		if(!found){
			cout<<"Student not found";
		}
	}
	//topper find karne ke liye
	
	void topper(Student s[], int total){
		if(total==0){
        cout<<"No students available\n";
        return;
    }
		int max=s[0].marks;
		string top=s[0].name;
		for(int i=0; i<total; i++){
			if (s[i].marks>max){
				max=s[i].marks;
				top=s[i].name;
			}
		}
		cout<<"Topper of the Class is: "<<top<<" with "<<max<<" marks"<<endl;
	}
	void update(Student s[], int total){
    int id, found = 0;

    cout<<"Enter roll number to update: ";
    cin>>id;

    for(int i=0;i<total;i++){
        if(s[i].rollnum == id){
            cout<<"Enter new details:\n";
            s[i].setdata();

            rewritefile(s,total);

            found = 1;
            cout<<"Updated successfully\n";
            break;
        }
    }

    if(!found)
        cout<<"Student not found\n";
}

int main(){
Student s[100];
	int total=0;
	loadfromfile(s,total);
	int choice;
	
	do{
		cout<<"\n\t\n 1. Add student";
		cout<<"\n 2. Show student details";
		cout<<"\n 3. Delete student";
		cout<<"\n 4. Topper student";
		cout<<"\n 5. Update student";
		cout<<"\n 6. Exit";
		cout<<"\n Enter choice";
	 	cin>>choice;
	 	
	 	switch(choice){
	 		case 1: add( s, total);
	 		break;
	 		case 2: show( s, total);
	 		break;
	 		case 3: Delete(s,total);
	 		break;
	 		case 4: topper( s, total);
	 		break;
	 		case 5: update( s, total);
	 		break;
	 		case 6: cout<<"\n  Exiting...\n";
	 		break;
	 		default: cout<<"\nInvalid choice\n";
	 	}
	}
	while(choice !=6);
	return 0;
}