#include<iostream>
#include<string>
#include<vector>

using namespace std;

class employee;
class petManagement;
class pet
{
    string name;
    int petCode;
    int price;
    bool status;
    public:
    pet()
    {
        status=true;
    }
    pet(string n,int c,int p)
    {
        name=n;
        petCode=c;
        price=p;
        status=true;
    }
    void display()
    {
        cout<<"Name:"<<name<<endl;
        cout<<"Code:"<<petCode<<endl;
        cout<<"Price:"<<price<<endl;
        if(status)
            cout<<"Pet status: Available."<<endl;
        else
            cout<<"Pet status: Not available."<<endl;
    }
    int getPrice()
    {
        return price;
    }
    ~pet(){};
    friend int orderPets(petManagement,int);
};

class petManagement
{
    vector<pet> pets;
    int no_of_pets;
    public:
    petManagement()
    {
        no_of_pets=0;
    }
    void addPets(string n,int c,int p)
    {
        pets.push_back(pet(n,c,p));
        no_of_pets++;
    }
    void displayAllPets()
    {
        for(int i=0;i<no_of_pets;i++)
        {
            pets[i].display();
            cout<<endl;
        }
    }
    int getPetPrice(petManagement p,int index)
    {
        return p.pets[index].getPrice();
    }
    void eraseRecord(int i)
    {
        pets.erase(pets.begin()+i);
    }
    friend int orderPets(petManagement,int);
    ~petManagement(){}
};

int orderPets(petManagement p,int c)
{
    int n=1;
    for(int i=0;i<p.no_of_pets;i++)
    {
        if(p.pets[i].petCode==c)
        {
            cout<<"Found pet."<<endl;

            n=0;

            string address;
            string name;
            int phone;

            cout<<"Enter name: ";
            cin.ignore();
            getline(cin,name);
            cout<<"Enter address: ";
            getline(cin,address);
            cout<<"Enter phone: ";
            cin>>phone;
            cout<<endl<<"It will be delievered soon."<<endl;

            cout<<endl<<"******************"<<endl;
            cout<<endl<<"Customer bill: "<<endl;
            cout<<"Pet name: "<<p.pets[i].name<<endl;
            cout<<"Pet price: "<<p.pets[i].price<<endl;
            cout<<"Customer name: "<<name<<endl;
            cout<<"Address: "<<address<<endl;
            cout<<"Phone: "<<phone<<endl;
            cout<<endl<<"The pet has been delievered."<<endl;

            p.pets[i].status=false;
            p.pets[i].~pet();
            return i;
        }
    }

    if(n)
        cout<<"Pet not found."<<endl;
    return 0;
}

class revenue
{
    int rev;
    public:
    revenue()
    {
        rev=0;
    }
    void addProfit(int p)
    {
        rev+=p;
    }
    friend class employee;
};
class employee
{
    int employeeCode;
    public:
    employee()
    {
        employeeCode=0;
    }
    employee(int c)
    {
        employeeCode=c;
    }
    void displayRevenue(employee e,revenue r,int c)
{
    int a=1;
    if(e.employeeCode==c)
    {
        cout<<"Revenue: "<<r.rev<<endl;
        cout<<"Revenue check was successful."<<endl;
        a=0;
    }
    if(a)
        cout<<"Invalid input."<<endl;
}
};


int main()
{
    employee e1(59321);
    revenue r;
    petManagement cats,dogs,rabbits;

    cats.addPets("cat1",11,500);
    cats.addPets("cat2",12,500);
    dogs.addPets("dog1",21,1000);
    dogs.addPets("dog2",22,1000);
    rabbits.addPets("rabbit1",31,1500);
    rabbits.addPets("rabbit1",32,1500);
    cout<<endl;


    cout<<"             ";
    cout<<"*****   Pet Shop   *****"<<endl<<"                     Welcome"<<endl;


    int t1=1;
    while(t1)
    {
        cout<<endl;
        cout<<"Are you an\n1.Employee\nor a\n2.Customer?"<<endl;
        int op;
        cin>>op;

        if(op!=1&&op!=2)
        {
            cout<<"Invalid input."<<endl;
            t1=0;
        }

        else if(op==1)
        {
            cout<<"Enter employee code to check revenue."<<endl;
            int c;
            cin>>c;
            e1.displayRevenue(e1,r,c);

            cout<<"1.Return to main menu\n2.Exit"<<endl;
            int op3;
            cin>>op3;

            if(op3!=1&&op3!=2)
                cout<<"Invalid input."<<endl;

            else if(op3==2)
            {
                t1=0;
                cout<<"Successful exit."<<endl;
            }
        }
        else
        {
            int option;
            cout<<"What do you want to do?"<<endl;
            cout<<"1.Look for pets"<<endl;
            cout<<"2.Order pets"<<endl;
            cin>>option;

            if(option==1)
            {
                cout<<"Select an option:"<<endl;
                cout<<"1.Cats\n2.Dogs\n3.Rabbits"<<endl;
                int op2;
                cin>>op2;

                if(op2!=1&&op2!=2&&op2!=3)
                    cout<<"Invalid input.\n";

                else
                {
                    if(op2==1)
                        cats.displayAllPets();

                    else if(op2==2)
                        dogs.displayAllPets();

                    else
                        rabbits.displayAllPets();
                }
            }

            else if(option==2)
            {
                cout<<"Select an option:"<<endl;
                cout<<"1.Cats\n2.Dogs\n3.Rabbits"<<endl;
                int op2;
                cin>>op2;

                if(op2!=1&&op2!=2&&op2!=3)
                    cout<<"Invalid input.\n";

                else
                {
                    int c;
                    cout<<"Enter pet code:"<<endl;
                    cin>>c;

                    if(op2==1)
                    {
                        int i=orderPets(cats,c);
                        r.addProfit(cats.getPetPrice(cats,i));
                    }

                    else if (op2==2)
                    {
                        int i=orderPets(dogs,c);
                        r.addProfit(dogs.getPetPrice(dogs,i));
                    }

                    else
                    {
                        int i=orderPets(rabbits,c);
                        r.addProfit(rabbits.getPetPrice(rabbits,i));
                    }
                }
            }

            else
                cout<<"Invalid input."<<endl;

            cout<<"1.Return to main menu\n2.Exit"<<endl;
            int op3;
            cin>>op3;

            if(op3!=1&&op3!=2)
                cout<<"Invalid input."<<endl;

            else if(op3==2)
            {
                t1=0;
                cout<<"Visit our store again!!"<<endl;
                cout<<"Successful exit."<<endl;
            }
        }
    }
}
