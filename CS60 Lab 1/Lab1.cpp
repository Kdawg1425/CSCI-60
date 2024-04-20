
#include <iostream>
using namespace std;

struct Time
{
  int hour;
  int minute;
};

class Carpool{
public:
  string names[5];
  int numOfPeople;
  Time arrivalTime;

  void printNames()
  {
    for(int i=0; i<numOfPeople; i++)
    {
      cout << names[i] << " ";
    }
    cout << endl;
  }
};

Carpool combineCarpool(Carpool car1, Carpool car2)
{
  int totalNumOfPeople = car1.numOfPeople + car2.numOfPeople;
  Carpool newCar;
  newCar.numOfPeople = 0;
  if(totalNumOfPeople <= 5)
  {
    newCar.numOfPeople = totalNumOfPeople;
    //newCar includes all members of both carpools
    int index = 0;
    for(int i=0; i<car1.numOfPeople; i++)
    {
      newCar.names[index] = car1.names[i];
      index++;
    }
    for(int i=0; i<car2.numOfPeople; i++)
    {
      newCar.names[index] = car2.names[i];
      index++;
    }

    //newCar's arrivalTime is the earlier of the two carpools
    if(car1.arrivalTime.hour < car2.arrivalTime.hour)
    {
      newCar.arrivalTime.hour = car1.arrivalTime.hour;
      newCar.arrivalTime.minute = car1.arrivalTime.minute;
    }
    else if(car2.arrivalTime.hour < car1.arrivalTime.hour)
    {
      newCar.arrivalTime.hour = car2.arrivalTime.hour;
      newCar.arrivalTime.minute = car2.arrivalTime.minute;
    }
    //if above two conditions are not met, the hours are equal, so the minute determines which time is earlier
    else if (car1.arrivalTime.minute < car2.arrivalTime.minute)
    {
      newCar.arrivalTime.hour = car1.arrivalTime.hour;
      newCar.arrivalTime.minute = car1.arrivalTime.minute;
    }
    else
    {
      newCar.arrivalTime.hour = car2.arrivalTime.hour;
      newCar.arrivalTime.minute = car2.arrivalTime.minute;
    }
  }
  return newCar;
}

int main()
{
  Carpool c1;
  c1.names[0] = "Adam";
  c1.names[1] = "Bob";
  c1.names[2] = "Cathy";
  c1.numOfPeople = 3;
  c1.arrivalTime.hour = 6;
  c1.arrivalTime.minute = 30;

  Carpool c2;
  c2.names[0] = "Doug";
  c2.names[1] = "Eve";
  c2.numOfPeople = 2;
  c2.arrivalTime.hour = 7;
  c2.arrivalTime.minute = 15;

  Carpool c3;
  c3 = combineCarpool(c1,c2);
  c3.printNames();
  cout << "numOfPeople: " << c3.numOfPeople << endl;
  cout << "arrivalTime: " << c3.arrivalTime.hour << ":" << c3.arrivalTime.minute << endl;
  cout << endl;

  return 0;
}
