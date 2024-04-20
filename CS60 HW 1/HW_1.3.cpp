#include <iostream>

using namespace std;

class Movie {
private:
  string name;
  string rating;
  double profit;

public:
  Movie();

  Movie(string movieName, string movieRating, double movieProfit);

  //Pre: None
  //Post: Returns the name of the movie
  string get_name(); //So I can access the movie name outside the class

  //Pre: None
  //Post: Returns the rating of the movie
  string get_rating(); //So I can access the rating outside the class

  //Pre: None
  //Post: Returns the current profit of the movie
  double get_profit(); //So I can access the profit outside the class

  //Pre: None
  //Post: Returns the total amount of money that was gained,
  //      after adding the profit from a showing.
  double movieShowing(int n);

  //Pre: None. This function is a helper to mergeMovie
  //Post: Returns the most restricted rating.
  string moreRestrict(Movie m);

  //Pre: None
  //Post: Returns a Movie. If the two movies merging are the same,
  //      the most restricted rating and combine the profits of both.
  //      If the movies don't match, returns a movie that's named "Could not combine".
  Movie mergeMovie(Movie m);
};

int main() {
  Movie m1;
  m1 = Movie("The Martian", "PG-13", 522.2);
  Movie m2 = Movie("Ender's Game", "PG-13", 15.5);
  Movie m3 = Movie("Deadpool", "PG-13", 50.0);
  Movie m4 = Movie("Deadpool", "R", 785.0);

  Movie test1 = Movie();
  test1 = m3.mergeMovie(m4);
  cout << test1.get_name() << " " << test1.get_rating() << " " << test1.get_profit() << endl;
  Movie test2 = Movie();
  test2 = m1.mergeMovie(m2);
  cout << test2.get_name() << " " << test2.get_rating() << " " << test2.get_profit() << endl;
  cout << m4.get_profit() << endl;
  m4.movieShowing(5);
  cout << m4.get_profit() << endl;
}


Movie::Movie() {
  name = "";
  rating = "";
  profit = 0.0;
}

Movie::Movie(string movieName, string movieRating, double movieProfit) {
  name = movieName;
  rating = movieRating;
  profit = movieProfit;
}

string Movie::get_name() {
  return name;
}

string Movie::get_rating() {
  return rating;
}

double Movie::get_profit() {
  return profit;
}

double Movie::movieShowing(int n) {
  profit += 12.0 * n;
  return profit;
}

string Movie::moreRestrict(Movie m) {
  int rate1;
  int rate2;
  if(rating.compare("G") == 0) {
    rate1 = 1;
  }
  if(rating.compare("PG") == 0) {
    rate1 = 2;
  }
  if(rating.compare("PG-13") == 0) {
    rate1 = 3;
  }
  if(rating.compare("R") == 0) {
    rate1 = 4;
  }
  if(m.rating.compare("G") == 0) {
    rate2 = 1;
  }
  if(m.rating.compare("PG") == 0) {
    rate2 = 2;
  }
  if(m.rating.compare("PG-13") == 0) {
    rate2 = 3;
  }
  if(m.rating.compare("R") == 0) {
    rate2 = 4;
  }
  if(rate1 > rate2) {
    return rating;
  }
  if(rate2 == rate1){
    return rating;
  }
  else {
    return m.rating;
  }
}

Movie Movie::mergeMovie(Movie m) {
  Movie combine = Movie();
  if(name.compare(m.name) == 0) {
    combine.name = name;
    combine.rating = moreRestrict(m);
    combine.profit = profit + m.profit;
    return combine;
  }
  else {
    combine.name = "Could not combine";
    return combine;
  }
}
