#include <iostream>

using namespace std;

struct Animal {
  string name;
  string gender;
  int age;
  double price;
  string type;
};

//Pre: None (But in this case that I have implemented, type has to be Cat or Dog).
//Post: Returns the cheapest animal of "type"
Animal cheapest(string type, Animal a[], int size);

//Pre: None
//Post: Returns true or false depending if the two animals' types are the same.
//      If they are the same, function returns true. If not, returns false.
bool livetogether(Animal a, Animal b);

int main() {
  Animal a1 = {"Fighto", "Male", 3, 725.0, "Dog"};
  Animal a2 = {"Troubles", "Female", 1, 400.0, "Cat"};
  Animal a3 = {"Jinx", "Female", 1, 300.0, "Cat"};
  Animal a4 = {"Kato", "Male", 4, 1000.0, "Dog"};
  Animal a5 = {"Pixi", "Female", 7, 750.0, "Dog"};
  Animal a6 = {"Pebble", "Female", 5, 700.0, "Dog"};
  Animal shelter[6] = {a1, a2, a3, a4, a5, a6};
  Animal result;

  result = cheapest("Dog", shelter, 6);
  cout << result.name << endl;
  result = cheapest("Cat", shelter, 6);
  cout << result.name << endl;
  cout << livetogether(shelter[0], shelter[1]) << endl;
  cout << livetogether(shelter[0], shelter[3]) << endl;

}

Animal cheapest(string type, Animal a[], int size) {
  double cost = 10000.0;
  int index = 0;
  for(int i = 0; i < size; i++) {
    if(a[i].type.compare(type) == 0) {
      if(a[i].price < cost) {
        cost = a[i].price;
        index = i;
      }
    }
  }
    return a[index];
}

bool livetogether(Animal a, Animal b) {
  if(a.type.compare(b.type) == 0) {
    return true;
  }
  else {
    return false;
  }
}
