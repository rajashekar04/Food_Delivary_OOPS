#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
# include <string>
#include "declarations.h"
#include "def.cpp"
using namespace std;
struct My_Exception:exception{
  string str;
  My_Exception(string s){
    str = s;
  }
  void what() throw(){
    cout << endl << str << endl;
    cout << "Please enter a valid entry" << endl << endl;
  }
};
void Database(vector<User> &usr_array, vector<Restaurant> &rest_array, Delivary_Mangement &DM)
{
  Dish D1(true, "Manchurian", "Starter", "Manchurian is a class of Indian Chinese dishes made by roughly chopping and deep-frying ingredients", 150);
  Dish D2(false, "chicken_handi", "Main_course", "Chicken Handi in a black bowl on a grey towel.", 200);
  Dish D3(true, "Biriyani", "Main_course", "Veg biryani is an aromatic rice dish made with basmati rice, spices & mixed veggies.", 300);
  Dish D4(false, "haleem", "starter", "Haleem is a stew composed of meat, lentils, and pounded wheat made into a thick paste.", 250);
  Dish D5(true, "sheer_khurma", "desert", "Sheer Khurma is an elegant dessert often made during Eid.", 350);
  Dish D6(false, "Mutton_biriyani", "Main_course", "Hyderabadi mutton biryani is a dish made by layering rice over slow cooked mutton gravy.", 400);
  Dish D7(true, "Dal_makhani", "Main_Course", "dal are dried, split pulses that do not require soaking before cooking.", 350);
  Dish D8(true, "Naan", "Main_course", "Naan is a leavened, oven-baked or tawa-fried flatbread", 75);

  Restaurant R1("Quality", 1023, "Hyderabad");
  Restaurant R2("Mehfil", 1223, "Chennai");
  Restaurant R3("Seven_stars", 1123, "Banglore");
  R1.add_Dish(D1);
  R1.add_Dish(D2);
  R1.add_Dish(D3);
  R2.add_Dish(D4);
  R2.add_Dish(D5);
  R2.add_Dish(D6);
  R3.add_Dish(D7);
  R3.add_Dish(D4);
  R3.add_Dish(D8);
  R3.add_Dish(D5);

  User U1(true, "Roy", "+912357318935", "Gwalior", "Hello");
  User U2(false, "Rick", "+917194582430", "Patna", "World");
  User U3(true, "Morty", "+916280180900", "Jaipur", "Helloworld");

  Delivary_Labour L1("Prashanth", "+919390026751", true);
  Delivary_Labour L2("Sheaker", "+919492189828", false);

  DM.add_delivary(L1);
  DM.add_delivary(L2);

  usr_array.push_back(U1);
  usr_array.push_back(U2);
  usr_array.push_back(U3);

  rest_array.push_back(R1);
  rest_array.push_back(R2);
  rest_array.push_back(R3);
}
int main()
{
  //  Part-1 : Database
  Delivary_Mangement DM;
  vector<User> usr_array;
  vector<Restaurant> rest_array;
  Database(usr_array, rest_array, DM);

  // Part -2 : Implementation
  while (true)
  {
    int s;
    string usr, pw;

    // we add few restaurants here
    cout
        << "Enter 1 to login, 2 to signup , other number  to exit " << endl;
    cin >> s;
    switch (s)
    {
    case 1:
    {
      int i;
      cout << "Enter the username and password ";
      cin >> usr >> pw;
      for (i = 0; i < usr_array.size(); i++)
      {
        if (usr_array[i].get_name() == usr && usr_array[i].get_pw() == pw)
        {
          break;
        }
      }
      try{
        if (i >= usr_array.size())
        {
          throw My_Exception("Wrong Password");
        }
      }
      catch(My_Exception &e)
      {
        e.what();
        break;
      }
        system("cls");
        string rest;
        User u = usr_array[i];
        cout << endl
             << "The available restaurants are -- :" << endl;
        for (i = 0; i < rest_array.size(); i++)
        {
          cout << rest_array[i].get_name() << endl;
        }
        while(true){
          try{
            cout << "enter the name of the restaurant from which you want to order :" << endl;
            cin >> rest;
            for (i = 0; i < rest_array.size(); i++)
            {
              if (rest_array[i].get_name() == rest)
              {
                break;
              }
            }
            if(i>=rest_array.size())
            {
              throw My_Exception("Invalid restaurant name");
            }
            break;
          }
          catch(My_Exception &e){
            e.what();
          }
        }
        system("cls");
        Restaurant r = rest_array[i];
        r.display_Details();
        Cart c;
        int no, pick;
        cout << "Enter the number of dishes to be added into the cart :" << endl;
        cin >> no;
        for (int k = 0; k < no; k++)
        {
          cout << "Enter your pick ";
          cin >> pick;
          int m = c.add_dish(pick, r);
          if (m == 0)
          {
            k--;
          }
        }
        c.dispaly_BILL();
        float price = c.Payment();
        if (u.is_Perimum())
        {
          price = price * 95 / 100;
          cout << endl
               << "As you are a premium member you were offered a 5 percent discount!!!" << endl;
          cout << endl
               << "Effective price to be paid is " << price << endl << endl;
          system("pause");
        }
        system("cls");
        Delivary_Labour d = DM.Alloting_Delivary_Guy();
        Delivary del(u.get_address(), r.get_Address(), u.get_number(), price, d);
        del.dispaly_Details();
        int checker;
        cout << endl
             << "-------------------Enter a number after you received your parcel----------" << endl;
        cin >> checker;
        DM.end_allocation(d);
        cout << "Thank You for using our Application!! " << endl << endl;
        system("pause");
        system("cls");
      break;
    }
    case 2:
    {
      int r;
      string add, ph;
      bool pre;
      cout << "Enter the username and password ";
      cin >> usr >> pw;
      while(1){
        try{
          cout << "Enter your phone number ";
          cin >> ph;
          if (ph.length()!=13)
          {
            throw My_Exception("Invalid Phone Number...");
          }
          int k = stoi(ph.substr(2,10));
          break;
        }
        catch(My_Exception e)
        {
          e.what();
        }
        catch(...){
          cout<<endl<<"Invalid characters entered"<<endl<<endl;
        }
      }
      cout << "Enter your address ";
      cin >> add;
      cout << "enter 1 if your a premium member ,else 0 ";
      cin >> r;
      pre = (r == 1) ? true : false;
      User u(pre, usr, ph, add, pw);
      usr_array.push_back(u);
      system("cls");
      break;
    }
    default:
      cout << "Program exited ...";
      exit(0);
      break;
    }
  }
  return 0;
}