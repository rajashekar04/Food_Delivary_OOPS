#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "hijack.h"
//  1. persom working
Person::Person(string nme, string phno)
{
  name = nme;
  phonenumber = phno;
}
string Person::get_name()
{
  return name;
}
string Person::get_number()
{
  return phonenumber;
}
// 2.  User Working
string User::get_pw()
{
  return pw;
}
User::User(bool ispre, string nme, string phno, string addr, string passw) : Person(nme, phno), premium(ispre), Address(addr), pw(passw)
{
}
string User::get_address()
{
  return Address;
}
bool User::is_Perimum()
{
  return premium;
}
//  3. Dish WORKING
Dish ::Dish(bool isVeg, string Dish_name, string Section, string description, int price)
{
  this->isVeg = isVeg;
  this->Dish_name = Dish_name;
  this->Section = Section;
  this->description = description;
  this->price = price;
}
int Dish ::get_price()
{
  return price;
}
void Dish ::get_Details()
{
  cout << "The name of the Dish is : " << Dish_name << endl;
  cout << "Section of the Dish is : " << Section << endl;
  if (isVeg)
  {
    cout << "The Status of the dish is Vegtarian " << endl;
  }
  else
  {
    cout << "The Status of the dish is Non-Vegtarian " << endl;
  }
  cout << "The Price of the dish is : " << price << endl;
  cout << description << endl;
}
string Dish ::dish_Name()
{
  return Dish_name;
}

// 4. Restaurant Working

void Restaurant ::display_Details()
{
  cout << "The name of the Restaurant is : " << Restaurant_name << endl;
  cout << "The ID of the Restaurant is : " << Restaurant_id << endl;
  cout << "The Address of the Restaurant is : " << Address << endl;
  cout << "The Dishes available in the Restaurant" << endl
       << endl;
  cout << endl;
  for (int i = 0; i < Array__of_Dishes.size(); i++)
  {
    Array__of_Dishes[i].get_Details();
    cout << endl;
    cout << "Enter " << i << " in the cart if you want to add the Dish to the cart" << endl;
    cout << endl;
    cout << endl;
  }
}
string Restaurant ::get_name()
{
  return Restaurant_name;
}
void Restaurant ::add_Dish(Dish d)
{
  Array__of_Dishes.push_back(d);
}
string Restaurant ::get_Address()
{
  return Address;
}
Restaurant ::Restaurant(string R_nam, int R_i, string Addres) : Restaurant_id(R_i), Restaurant_name(R_nam), Address(Addres)
{
}
//

// public:
//   Restaurant(string, int, string, vector<Dish>);
//   void display_Details();
//   void add_Dish(Dish);
//   string get_Address();
//   vector<Dish> Array__of_Dishes;
//   // friend void Cart ::add_dish(int, Restaurant &);

// private:
//   string Restaurant_name;
//   int Restaurant_id;
//   string Address;
//  5. Cart  working

void Cart ::add_dish(int n, Restaurant &r)
{
  dishes.push_back(n);
  for (int i = 0; i < r.Array__of_Dishes.size(); i++)
  {
    if (n == i)
    {
      cout << "You have Picked " << r.Array__of_Dishes[i].dish_Name() << "in the cart : $" << r.Array__of_Dishes[i].get_price() << endl;
      Price += r.Array__of_Dishes[i].get_price();
    }
  }
  GST = add_tax();
  bill = Price + GST;
}
int Cart ::add_tax()
{
  return (18 * Price) / 100;
}
void Cart ::dispaly_BILL()
{
  cout << "The Price of the Dishes Ordered is : $" << Price << endl;
  cout << "The Governament Tax : $" << GST << endl;
  cout << "The Total Amount to be Paid is : $" << bill << endl;
}

int Cart ::Payment()
{
  return bill;
}
Cart::Cart()
{
  Price = 0;
  GST = 0;
  bill = 0;
}

//  6. delivary working

Delivary::Delivary(string User_address, string Restaurant_address, string User_phone_number, int Total_Amount, Delivary_Labour &p)
{
  this->User_address = User_address;
  this->Restaurant_address = Restaurant_address;
  this->User_phone_number = User_phone_number;
  this->Total_Amount = Total_Amount;
  ptr = &p;
}
void Delivary::dispaly_Details()
{
  cout << "The Package is Being Ordered BY the Address: " << endl
       << User_address << endl;
  cout << "Customer number :  " << User_phone_number << endl;
  cout << "The Package is Being Delivared from the Address : " << endl
       << Restaurant_address << endl;
  cout << "The Amount Needs to be paid is : $" << Total_Amount << endl;
  cout << ptr;
}

// 7. Delivary_Labour Working

bool Delivary_Labour ::isavailable()
{
  return isAvailable;
}
void Delivary_Labour ::display_Detalis()
{
  cout << "The Delivary boy Name : " << get_name() << endl;
  cout << "The Delivay boy Phone Number : " << get_number() << endl;
  cout << "The Avaliablity of the Delivay Boy is :" << isAvailable << endl;
}
void Delivary_Labour ::allocate_availability(bool a)
{
  this->isAvailable = a;
}
Delivary_Labour ::Delivary_Labour(string naam, string phonenumber, bool isAvailable) : Person(naam, phonenumber)
{
  this->isAvailable = isAvailable;
}
ostream &operator<<(ostream &s, Delivary_Labour *p) // -> Operator Overloading
{
  s << "Name of the delivary boy is " << p->get_name() << endl;
  s << "The deliavry boys phone number is " << p->get_number() << endl;
  return s;
}
//  8. Delivary Management
Delivary_Labour Delivary_Mangement ::Alloting_Delivary_Guy()
{
  for (int i = 0; i < Array_Available_Delivary.size(); i++)
  {
    if (Array_Available_Delivary[i].isavailable())
    {
      Array_Available_Delivary[i].allocate_availability(false);
      return Array_Available_Delivary[i];
    }
  }
  return Array_Available_Delivary[0];
}
void Delivary_Mangement ::add_delivary(Delivary_Labour D)
{
  Array_Available_Delivary.push_back(D);
}
void Delivary_Mangement ::end_allocation(Delivary_Labour D)
{
  for (int i = 0; i < Array_Available_Delivary.size(); i++)
  {
    if (D.get_name() == Array_Available_Delivary[i].get_name())
    {
      Array_Available_Delivary[i].allocate_availability(true);
    }
  }
}