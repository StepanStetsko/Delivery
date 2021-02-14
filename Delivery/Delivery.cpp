#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Order
{
    string m_nameOrder;
    vector<string> m_orderComponents;
    int m_finalCost;
    int m_discount;
};

class Restaurant
{
private:
    string m_restaurantName;
    string m_restaurantAddress;
    string m_workTime;
    int m_deliveryTime;
    double m_rating;
    vector<Order> m_menu;
public:
    Restaurant(string name, string address, string time, int deliveryTime, double rating) :
        m_restaurantName{ name }, m_restaurantAddress{ address }, m_workTime{ time }, m_deliveryTime{ deliveryTime }, m_rating{ rating } {}
    void printRestaurantInfo()
    {
        cout << "Name: " << m_restaurantName << "\t" << "Rating: " << m_rating << endl <<
            "Address: " << m_restaurantAddress << endl <<
            "Work time: " << m_workTime << endl <<
            "Delivery time: " << m_deliveryTime << " min" << endl;
    }
};

int main()
{
    Restaurant rest1("Rest1", "Address1", "18:00", 34, 4.6);
    rest1.printRestaurantInfo();
}

