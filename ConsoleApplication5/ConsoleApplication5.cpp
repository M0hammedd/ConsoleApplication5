#include <iostream>
using namespace std;

const int max_destination = 5;

class customer {
protected:
    string name;
    string gender;
    int age;
    string destintion;
    string location;
    int days;

private:
    int ID;

public:
    customer() {}
    customer(string n, string g, int a, int I) : name(n), gender(g), age(a), ID(I) {}

    virtual ~customer() {} // Virtual destructor for polymorphism

    virtual void print() {
        cout << "customer: " << name << ", gender: " << gender << ", age: " << age << endl;
    }
    string getname()
    {
        return name;
    }
    string getgender()
    {
        return gender;
    }
    int getage()
    {
        return age;
    }
    int getID()
    {
        return ID;
    }
    void insert()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Customer ID: ";
        cin >> ID;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Gender: ";
        cin >> gender;
    }
    void set_destination(string dest) { destintion = dest; }
    string getdestination() { return destintion; }

    void set_location(string loc) { location = loc; }
    string getlocation() { return location; }

    void set_days(int Days) { days = Days; }
    int get_days() { return days; }


};

class booking {
public:
    string destination_name;
    string location_name;
    double p;

    booking() {}
    booking(string name, string location, double price) : destination_name(name), location_name(location), p(price) {}

    string getlocation() { return location_name; }
};

class special_booking :public booking 
{
public:
    special_booking(){}
 
    special_booking(string name, string location, double price) : booking(name, location, price) {}// special_booking(string name, string location, double price) : destination_name(name), location_name(location), p(price) {}

    string getlocation() { return location_name; }

};

int main() {
    /* string name;
      string gender;
      int age;
      int id;*/
    system("color 54");
    int days;
    int choice;
    double total_bill = 0.0;

    booking* destinations[max_destination];
    destinations[0] = new booking("boursaeed", "egypt", 100);
    destinations[1] = new booking("horgada", "egypt", 200);
    destinations[2] = new booking("dahab", "egypt", 300);
    destinations[3] = new booking("bali", "thailand", 500);
    destinations[4] = new booking("moscow", "russia", 500);

    special_booking* S_destinations[max_destination];
    S_destinations[0] = new special_booking("boursaeed", "egypt", 700);
    S_destinations[1] = new special_booking("horgada", "egypt", 1000);
    S_destinations[2] = new special_booking("dahab", "egypt", 1500);
    S_destinations[3] = new special_booking("bali", "thailand", 1550);
    S_destinations[4] = new special_booking("moscow", "russia", 2000);

    customer obj;
    while (true)
    {
        cout << "                              * EFG Travels *\n" << endl;
        cout << "        -------------------------Main Menu--------------------------" << endl;
        cout << " _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
        cout << "|                                                                          |" << endl;
        cout << "|                     Customer Management         -> 1                     |" << endl;
        cout << "|                     Bookings Management         -> 2                     |" << endl;
        cout << "|                     special Bookings Management -> 3                     |" << endl;
        cout << "|                     Charges & Bill              -> 4                     |" << endl;
        cout << "|                     Exit                        -> 5                     |" << endl;
        cout << "|                                                                          |" << endl;
        cout << "|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |" << endl;

        cout << "\nEnter Choice: ";
        cin >> choice;



        if (choice == 1)  // customer informations 
        {

            obj.insert();
            cout << "Customer added successfully.\n";
        }
        else if (choice == 2) // normal booking 
            {
            for (int i = 0; i < max_destination; i++) {
                cout << i + 1 << " : " << "destination is : " << destinations[i]->destination_name;
                cout << " , location is : " << destinations[i]->location_name;
                cout << "  , ticket cost : " << destinations[i]->p << endl;
            }
            int chosen_trip;
            
            cout << "Choose the trip (1-5): ";
            cin >> chosen_trip;
            cout << "Enter number of days: ";
            cin >> days;
            if (chosen_trip >= 1 && chosen_trip <= max_destination) {
                total_bill = destinations[chosen_trip - 1]->p * days;
                obj.set_destination(destinations[chosen_trip - 1]->destination_name);
                obj.set_location(destinations[chosen_trip - 1]->location_name);

                cout << "Booking successful. Total cost: $" << total_bill << endl;
            }
            else {
                cout << "Invalid choice. Please choose a valid trip number.\n";
            }
        }
        else if (choice == 3) // special booking 
        {
            for (int i = 0; i < max_destination; i++) {
                cout << i + 1 << " : " << "destination is : " << S_destinations[i]->destination_name;
                cout << " , location is : " << S_destinations[i]->location_name;
                cout << "  , ticket cost : " << S_destinations[i]->p << endl;
            }
            int chosen_trip;

            cout << "Choose the trip (1-5): ";
            cin >> chosen_trip;
            cout << "Enter number of days: ";
            cin >> days;
            if (chosen_trip >= 1 && chosen_trip <= max_destination) {
                total_bill = S_destinations[chosen_trip - 1]->p * days;
                obj.set_destination(S_destinations[chosen_trip - 1]->destination_name);
                obj.set_location(S_destinations[chosen_trip - 1]->location_name);

             //   cout << "Booking successful. Total cost: $" << total_bill << endl;
            }
            else {
                cout << "Invalid choice. Please choose a valid trip number.\n";
            }



        }
        else if (choice == 4)  // bill
        {
            cout << "\n-------------------------Bill--------------------------" << endl;
            cout << "Customer Name: " << obj.getname() << endl;
            cout << "Customer age :" << obj.getage() << endl;
            cout << "Destination: " << obj.getdestination() << endl;
            cout << "Location: " << obj.getlocation() << endl;
            cout << "Number of Days: " << days << endl;
            cout << "ID : " << obj.getID() << endl;
            cout << "gender :" << obj.getgender() << endl;
            cout << "Total Bill: $" << total_bill << endl;
            cout << "-------------------------------------------------------------" << endl;
        }
        else if (choice == 5) // exit
        {
            cout << "============================== Good bye! ===============================" << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    for (int i = 0; i < max_destination; i++) {
        delete destinations[i];
        delete S_destinations[i];

    }


    return 0;
}
