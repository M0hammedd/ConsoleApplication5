#include <iostream>
using namespace std;


const int max_destination = 5;

class customer {
protected:
    string name;
    string gender;
    int  age;
private:
    int ID;

public:
    customer() {}
    customer(string n, string g, int a, int I) : name(n), gender(g), age(a), ID(I) {}

    virtual ~customer() {} // Virtual destructor for polymorphism

    virtual void print() {
        cout << "customer: " << name << ", gender: " << gender << ", age: $" << age << endl;
    }
};


class booking : public customer {
private:

public:
    string destination_name;
    string location_name;
    double p;
    booking() {};
    booking(string name, string location, double price) : destination_name(name), location_name(location), p(price) {};
    string getlocation() { return location_name; }
   
};









int main() {
    string name;
    string gender;
    int age;
    int id;
    int choice;
    double total_bill = 0.0 ;

    //string destinatio_name;
    //string location_name;
    //double price;
    cout << "\t\t      * EFG Travels *\n" << endl;
    cout << "-------------------------Main Menu--------------------------" << endl;

    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|\tCustomer Management -> 1\t|" << endl;
    cout << "\t|\tBookings Management -> 2\t|" << endl;
    cout << "\t|\tCharges & Bill      -> 3\t|" << endl;
    cout << "\t|\tExit                -> 4\t|" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;

    cout << "\nEnter Choice: ";
    cin >> choice;

    booking* destinations[max_destination];
    destinations[0] = new booking("boursaeed", "egypt", 100);
    destinations[1] = new booking("horgada", "egypt", 200);
    destinations[2] = new booking("dahab", "egypt", 300);
    destinations[3] = new booking("bali", "tiland", 500);
    destinations[4] = new booking("mosscow", "russia", 500);
    if (choice == 1)
    {
        int choice;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Customer ID: ";
        cin >> id;
        cout << "Enter Age: ";
        cin >> age;
        cout << "gender: ";
        cin >> gender;
        customer obj(name, gender, age, id);
    }
    else if (choice == 2)
    {
        for (int i = 0; i < max_destination; i++)
        {
            cout << i + 1 << " : " << "destination is : "  << destinations[i]->destination_name ; // هذا السطر يقوم بعرض اسم الرحله
            cout <<" , location is : "  << destinations[i]->location_name; // هذا السطر يقوم بعرض موقع الرحله
            cout << "  , ticket cost : " <<destinations[i]->p << endl; // هذا السطر يقوم بعرض تكلفة الرحله
        }
        int choice;
        int days;
        cout << " choose the trip :";
        cin >> choice;
        cout << "choose how many days : ";
        cin >> days;
        for(int i = 0 ; i <5 ; i++ )  // تم حذف (اف) ووضع فور لووب في الجزء الخاص بأدخال عدد الايام وحساب الفاتوره 
        {
         total_bill = destinations[i]->p*days; // ضرب عدد الايام في سعر التذكره  // يمكنك الرجوع الي سطر 54 للاطلاع علي المتغير
        }
        //if (choice == 1)
        //{
        //    total_bill = destinations[0]->p*days;
        //}

    }






cout << total_bill;



    for (int i = 0; i < max_destination; i++)
    {
        delete destinations[i];

    }



//name


}
