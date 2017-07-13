#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
class vahed;
class stack {
   public:
      int empty(stack* s );
      void pop(stack *, int * ,int * underflow);
      void push(stack *,int * ,int * overflow);
      int menu();
      int myTop;
      int data[300];
};
class darse{
public:
	string name;
	int code;
	int roze;
	int hour;
	double nomre;
	darse *link;
	darse *link1[20];
	darse *parent;
};
class vahed{
	darse dars[200];
	int pas[200];
	int num;
	int term_g[200];
};
class student {
public:
	double average;
	string name;
	string family;
	string reshe;
	int sale_vorodi;
	int sh_daneshjoi;
	int bedehi;
	vahed va1;
	student *link;
};

void switchesalon( void);
void get_student(student*);
void read_student(student*);
void getda(darse*);
void get_darse(darse*);
void read_darse(darse *);
void entekhab(student*);
void vahedd(darse *corse, student *stu);
int main(){
	cout<<"                          well come"<<endl;
	cout<<"enter password";
	int num,k,ca,pass;
	cin>>pass;
    //	int j, b[7][7],fasele[7][7] , sum[7] ;
    //switchesalon( );
    // matrix_klabgah(b[7][7],fasele[7][7] , sum[7] );
    if(pass==123){
	   student *person;
       person = new student;
	   darse *less;
	   less = new darse;
	   cout<<"how many work do you want";
	   cin>>num;
	   for(k=0;k<num;k++){
	       cout<<"enter1 for add student 2for add lesson 3 for pish niaz 4 choose dormitory 5 for vahed va nomarat va show";
	       cin>>ca;
	       switch(ca){
		      case(1):
	            get_student(person);
	            break;
	          case(2):  
	            getda(less);
	            break;
	          case(3):
	            get_darse(less);
	            getda(less);   
	            break;
	          case(4):
	            get_student(person);
	            entekhab(person);
	            break;
	          case(5):
	            get_student(person);
	            getda(less);
	            get_darse(less);
	            vahedd(less, person);
	            break;
		   }
      }
   }
   else{
	   cout<<"pass wrong";
   }
   return 0;
}
void get_darse(darse *les){
	int  num2, flag, i,k, code1,code2;
	darse  *temp, *corse;
	temp = les;
	corse = les;
	for (i = 0; corse != 0; i++){
		cout << "enter " << i << "pishniaz code";
		cin >> code1;
		if (code1 == 0){
			corse->parent = 0;
		}
		else{
			flag = 0;
			for (; temp != 0;){
				if (code1 == temp->code){
					flag = 1;
					corse->parent = temp;
				}
				temp = temp->link;
			}
			if (flag == 0){
				cout << "eror";
			}
		}
		cout << corse->name;
	    cout << "enter num "<<corse->name<<" child 1ta5";
		cin >> num2;
		temp=les;
		for (k = 0; k<num2; k++){
		   temp = les;
		   cout << "enter code"<<corse->name<<" child";
		   cin >> code2;
		   for (; temp != 0;){
		     if (code2 == temp->code){
		        corse->link1[k] = temp;
		     }
		     temp=temp->link;
		   }
		}
		corse = corse->link;
	}
}
void get_student(student *person){
	student *temp1, *temp2;
	fstream output("test.txt", ios::out);
	if (!output)
	{
		cout << "File can not open." << endl;
		exit(1);
	}
	temp2 = new student;
	int n;
	cout << "enter number student";
	cin >> n;
	output << n << endl;
	cout << "enter name student";
	cin >> person->name;
	output << person->name << endl;
	cout << "enter family student";
	cin >> person->family;
	output << person->family << endl;
	cout << "enter average";
	cin >> person->average;
	output << person->average << endl;
	cout << "enter sh danshjoi";
	cin >> person->sh_daneshjoi;
	output << person->sh_daneshjoi << endl;
	cout << "enter sale vorodi";
	cin >> person->sale_vorodi;
	output << person->sale_vorodi;
	cout << "enter bedehi";
	cin >> person->bedehi;
	output << person->bedehi;
	person->link = 0;
	temp2 = person;
	for (int i = 1; i<n; i++){
		temp1 = new student;
		cout << "enter name";
		cin >> temp1->name;
		output << temp1->name << endl;
		cout << "enter family";
		cin >> temp1->family;
		output << temp1->family << endl;
		cout << "enter average";
		cin >> temp1->average;
		output << temp1->average << endl;
		cout << "enter sh danshjoi";
		cin >> temp1->sh_daneshjoi;
		output << temp1->sh_daneshjoi << endl;
		cout << "enter sale vorodi";
		cin >> temp1->sale_vorodi;
		output << temp1->sale_vorodi;
		cout << "enter bedehi";
		cin >> temp1->bedehi;
		output << temp1->bedehi;
		temp1->link = 0;
		temp2->link = temp1;
		temp2 = temp1;
	}
}
void read_student(student *person){
	fstream input("test.txt", ios::in);
	if (!input)
	{
		cout << "File can not open." << endl;
		exit(1);
	}
	int n, i;
	input >> n;
	for (i = 0; i<n; i++){
		input >> person->name;
		input >> person->family;
		input >> person->average;
		input >> person->sh_daneshjoi;
		input >> person->sale_vorodi;
		input >> person->bedehi;
		person = person->link;
	}
}
void read_darse(darse *les){
	fstream input3("test3.txt", ios::in);
	if (!input3)
	{
		cout << "File can not open." << endl;
		exit(1);
	}
	int n, i;
	input3 >> n;
	for (i = 0; i<n; i++){
		input3 >> les->name;
		cout << les->name;
		input3 >> les->code;
		input3 >> les->roze;
		input3 >> les->hour;
		cout << les->hour;
		les = les->link;
	}
}
void getda(darse *les){
	darse *temp1, *temp2;
	fstream output3("test3.txt", ios::out);
	if (!output3)
	{
		cout << "File can not open." << endl;
		exit(1);
	}
	temp2 = new darse;
	int n;
	cout << "enter number dars";
	cin >> n;
	output3 << n << endl;
	cout << "enter name darse";
	cin >> les->name;
	output3 << les->name << endl;
	cout << "enter code darse";
	cin >> les->code;
	output3 << les->code << endl;
	cout << "roze tashkil clas";
	cout << "1for shanbe 2 for sun day...7for fridy";
	cin >> les->roze;
	output3 << les->roze << endl;
	cout << "sate clas";
	cin >> les->hour;
	output3 << les->hour << endl;
	les->link = 0;
	temp2 = les;
	for (int i = 1; i<n; i++){
		temp1 = new darse;
		cout << "enter name";
		cin >> temp1->name;
		output3 << temp1->name << endl;
		cout << "enter code";
		cin >> temp1->code;
		output3 << temp1->code << endl;
		cout << "roze tashkil clas";
		cout << "1for shanbe 2 for sun day...7for fridy";
		cin >> temp1->roze;
		output3 << temp1->roze << endl;
		cout << "sate clas";
		cin >> temp1->hour;
		output3 << temp1->hour << endl;
		temp1->link = 0;
		temp2->link = temp1;
		temp2 = temp1;
	}
}
void vahedd(darse *corse, student *stu){
	darse *temp, *first;
	student *temp2;
	temp2 = new student;
	temp2 = stu;
	first = corse;
	temp = first;
	int num1,num, ca,j,trm, code1, flag1, stud, flag2, i, code3[200], code4[i], code2[200];
	cout << "enter shomare stu";
	cin >> stud;
	for (; temp2 != 0;){
		if (temp2->sh_daneshjoi == stud){
			break;
		}
		temp2 = temp2->link;
	}
	cout << "enter num vahedhai dashte";
	cin >> num1;
	for (i = 0; i<num1; i++){
			cout << "enter code vahed dashte";
			cin >> code2[i];
			cout << "term chand";
			cin >> code3[i];
			cout << "nomre";
			cin >> code4[i];
	}
	cout<<"enter 1for entekhab vahed 2for nomere3 for show";
	cin>>ca;
	switch(ca){
		case(1):
	       cout << "enter num vahed you want add";
	       cin >> num;
	       for (i = 0; i<num; i++){
	        	flag1 = 0;
		        cout << "enter code ";
		        cin >> code1;
		        for (; temp != 0;){
			        if (temp->code == code1){
				        flag1 = 1;
				        flag2 = 0;
				        for (j = 0; j<num1; j++){
					        if (temp->parent->code == code2[j]){
						      flag2 = 1;
					        }
					        if (temp->parent == 0){
						        flag2 = 1;
					        }
				        }
				        if (flag2 == 0){
					       cout << "eror pishniaz";
				        }
				        else{
					        cout << "you can";
				        }
			        }
			        temp = temp->link;
		        }
		        if (flag1 == 0){
			    cout << "not find";
		}
	   }
	   break;
	   case(2):
	     cout<<"which term";
	     cin>>trm;
	     for(i=0;i<num1;i++){
		    if(trm==code3[i]){
			   cout<<code4[i]<<endl;
		    }
	     }
	     break;
	   case(3): 
	     cout<<"which term";
	     cin>>trm;
	     for(i=0;i<num1;i++){
			 temp=corse;
			 if(trm==code3[i]){
				 for(;temp!=0;){
					 if(temp->code==code2[i]){
						 cout<<temp->roze<<"roze"<<endl;
						 cout<<temp->hour<<"hour"<<endl;
					 }
					 temp=temp->link;
				 }
			 }
		 }
		 break;
  }
}
void entekhab(student* person){
   student *groh[200],*temp1,*temp2,*temp3[200];
   temp1=person;
   temp2=person;
   int k,sum[200],j,gr1,gr2,num,code,flag,tedad[200],mand[200];
   temp1=new student;
   temp2=new student;
   //groh=new student;
   temp3[0]=groh[0];
   k=0;
   sum[k]=0;
   flag=0;
   cout<<"enter tedad groh";
   cin>>num;
   for(k=0;k<num;k++){
      cout<<"enter /num groh 1ta5";
      cin>>tedad[k];
      for(j=0;j<tedad[k];j++){
          temp3[k]=groh[k];
          cout<<"enter sh danshjo";
          cin>>code;
          temp1=person;
          flag=0;
          for(;temp1!=0;){
              temp2=person;
              for(;temp2!=0;){
                  if(temp2->sh_daneshjoi==code){
                     groh[k]=temp2;
                     sum[k]=sum[k]+temp2->sale_vorodi;
                     mand[k]=mand[k]+temp2->bedehi;
                     groh[k]=groh[k]->link;
                     groh[k]=0;
                     flag=1;
                  }
                  temp2=temp2->link;
              }
              temp1=temp1->link;
          }
          if(flag==0){
              cout<<"eror"<<endl;
          }
     }
     groh[k]=temp3[k];
     }
     cout<<"shomare groh1";
	 cin>>gr1;
	 cout<<"shomare groh2";
	 cin>>gr2;
		 if(tedad[gr1]==tedad[gr2]){
			 if(mand[gr1]==mand[gr2]){
                if(sum[gr1]<sum[gr2]){
					cout<<gr1<<"first";
				}
				else{
					cout<<gr2<<"first";
				}
			}
			else{
				if(mand[gr1]>mand[gr2]){
					cout<<gr2<<"first";
				}
				else{
					cout<<gr1<<"first";
			    }
		    }
		}
		else{
			if(tedad[gr1]>tedad[gr2]){
				cout<<gr1<<"first";
			}
			else{
					cout<<gr2<<"first";
				}
  }
}
