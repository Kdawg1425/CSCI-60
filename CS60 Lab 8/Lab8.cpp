#include <iostream>
using namespace std;

struct Date{
  int day;
  int month;
  int year;
};

struct Item{
  string name;
  string author;
  double price;
  int size;
  string chapters[1000];
  Date releaseDate;
};

void printItem(Item it){
  cout<< "=====================================================================" << endl;
  cout<< "Item: " << it.name << endl;
  cout<< "Author: " << it.author << endl;
  cout<< "Price: " << it.price << endl;
  cout<< "Chapters: ";
  for(int i = 0; i < it.size; i++){
    cout << it.chapters[i] << ",";
  }
  cout<< endl;
  cout<< "Release Date: " << it.releaseDate.month << "/" << it.releaseDate.day << "/" <<it.releaseDate.year<< endl;
  cout<< "=====================================================================" << endl;
}

void initializeItem(Item& it){
  int num;
  string dum;
  cout<< "Enter name of item: " << endl;
  getline(cin, it.name);
  cout<< "Enter Author/Artist: " << endl;
  getline(cin, it.author);
  cout<< "Enter price: " << endl;
  cin>> it.price;
  cout<< "How many chapters/tracks? " << endl;
  cin >> it.size;
  getline(cin, dum);
  for(int i = 0; i < it.size; i++) {
    cout << "Enter track/chapter " << i+1 << endl;
    getline(cin,it.chapters[i]);
  }
  cout<< "What is the release month?" << endl;
  cin >> it.releaseDate.month;
  cout<< "What is the release day?" << endl;
  cin >> it.releaseDate.day;
  cout<< "What is the release year?" << endl;
  cin >> it.releaseDate.year;
}

double fillCart(Item a[], int size){
  string userinput;
  double total = 0;
  for(int i = 0; i < size; i++){
    cout << "Item: " << a[i].name << " By: " << a[i].author <<endl;
    cout <<  "Would you like to \"purchase\", see more \"details\", or \"pass\"?" << endl;
    cin>>userinput;
    if(userinput.compare("purchase") == 0){
      total += a[i].price;
    }
    else if(userinput.compare("details") == 0){
      printItem(a[i]);
      cout<< "Would you like to \"purchase\" or \"pass\"?"<<endl;
      cin >> userinput;
      if(userinput.compare("purchase") == 0){
        total += a[i].price;
      }
    }
  }
  return total;
}

int main(){
  Item temp;
  //initializeItem(temp);
  //printItem(temp);
  Item amazon[3] = {{"Slaughterhouse 5", "Kurt Vonnegut", 7.99},
   {"Let it Be", "The Replacements", 11.49,{"I Will Dare", "Favorite Thing", "We're Comin' Out",
           "Tommy Gets His Tonsils Out","Androgynous","Black Diamond","Unsatisfied",
           "Seen Your Video","Gary's Got","Sixteen Blue","Answering Machine"}, 11, {10, 2, 1984}},
   {"Let it Be", "The Beatles", 16.29, {"Two Of Us", "Dig A Pony","Across The Universe",
           "I Me Mine","Dig It","Let It Be","Maggie Mae","I've Got A Feeling","One After 909",
           "The Long And Winding Road","For You Blue","Get Back"}, 12, {5, 11, 1970}}};
   double cost = fillCart(amazon, 3);
   cout<<"Total cost: $"<<cost << endl;;
    return 1;
}
