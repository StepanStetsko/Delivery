#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Order
{
    string m_nameOrder;
    vector<string> m_orderComponents;
    double m_orderCost;
    int m_discount;

    void printComponents()
    {
        for (auto obj : m_orderComponents)
        {
            cout << obj << " " << endl;
        }
    }
};

class OrderBasket
{
private:
    string m_restaurantName;
    string m_restaurantAddress;
    string m_workTime;
    int m_deliveryTime;
    double m_finalCost;
    double m_rating;
    vector<Order> m_menu;
public:
    OrderBasket(string name, string address, string time, int deliveryTime, double rating, vector<Order>* order) :
        m_restaurantName{ name }, m_restaurantAddress{ address }, m_workTime{ time }, m_deliveryTime{ deliveryTime }, m_rating{ rating }, m_menu {*order}{}
    void printRestaurantInfo()
    {
        cout << "Name: " << m_restaurantName << "\t" << "Rating: " << m_rating << endl <<
            "Address: " << m_restaurantAddress << endl <<
            "Work time: " << m_workTime << endl <<
            "Delivery time: " << m_deliveryTime << " min" << endl << endl;

        for (auto obj : m_menu)
        {
            cout << "Name: " <<obj.m_nameOrder << endl << 
                "Cost: " << obj.m_orderCost << "\tDiscount: " << obj.m_discount << endl << endl;
            m_finalCost += obj.m_orderCost;
        }
        cout << "Total: " << m_finalCost << endl;
    }

    void addMenu(Order newPosition)
    {
        if (m_menu.empty())
            m_menu.resize(5);
    }
};

int main()
{
    vector<string> s{ "Pomidirky", "Kapusta", "Harosh" };
    vector<string> d{ "Pomidirky - 2", "Kapusta - 2", "Harosh - 2" };
    Order a{ "Salat", s, 23.45, 0 };
    Order b{ "Salat - 2", d, 76.32, 0 };
    vector<Order>g{a,b};
    OrderBasket rest1("Rest1", "Address1", "18:00", 34, 4.6, &g);

    rest1.printRestaurantInfo();
}

