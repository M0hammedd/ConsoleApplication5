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
    double total_bill = 0.0;

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
            cout << i + 1 << " : " << "destination is : " << destinations[i]->destination_name;
            cout << " , location is : " << destinations[i]->location_name;
            cout << "  , ticket cost : " << destinations[i]->p << endl;
        }
        int chosen_trip;
        int days;
        cout << "Choose the trip (1-5): ";
        cin >> chosen_trip;
        cout << "Enter number of days: ";
        cin >> days;
        if (chosen_trip >= 1) 
        {
            total_bill = destinations[chosen_trip - 1]->p * days;
        }
    }
    else if (choice == 3)
    {
        
            cout << "\n-------------------------Bill--------------------------" << endl;
            cout << "Customer Name: "  << endl;
            cout << "Destination: "  << endl;
            cout << "Location: "<< endl;
            cout << "Number of Days: " << endl;
            cout << "Total Bill: $" << total_bill << endl;
            cout << "-------------------------------------------------------------" << endl;
        
    }
    else if (choice == 4)
    {
        cout << "============================== good bye ! ===============================";
    }
    



for (int i = 0; i < max_destination; i++)
{
    delete destinations[i];
}





}
