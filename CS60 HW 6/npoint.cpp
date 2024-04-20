
template<typename T>
NPoint<T>::NPoint(){
    size_=0;
    for(int i=0;i<10;i++){
        data_[i]=T();
    }
}

template<typename T>
NPoint<T>::NPoint(int size){
    size_=size;
    for(int i=0;i<10;i++){
        data_[i]=T();
    }
}

template<typename T>
NPoint<T>::NPoint(int size,T arr[]){
    size_=size;
    for(int i=0;i<size_;i++){
        data_[i]=arr[i];
    }
}

template<typename T>
int NPoint<T>::size()const{
  return size_;
}

template<typename T>
T NPoint<T>::get_item(int index)const{
    if(index>=size_) {
      return T();
    }
    return data_[index];
}

template<typename T>
void NPoint<T>::operator = (const NPoint<T> p){
    size_=p.size();
    for(int i=0;i<p.size();i++){
        data_[i]=p.get_item(i);
    }
}

//Pre: None
//Post: Updates NPoint to the sum of the original and the NPoint added to it.
// Type variables need to support += operator
template<typename T>
void NPoint<T>::operator += (const NPoint<T> p) {
  int s_temp;
  if(size_ < p.size()) {
    for(int i = 0; i < p.size(); i++)  {
      data_[i] += p.get_item(i);
    }
    size_ = p.size();
  }
  else {
    for(int j = 0; j < size_; j++) {
      data_[j] += p.get_item(j);
    }
  }
}

//Pre: None
//Post: Returns a type T that is the result of the two NPoints added together.
// Type variables needs to support += operator
template<typename T>
NPoint<T> operator + (const NPoint<T> p1, const NPoint<T> p2) {
  NPoint<T> result = NPoint<T>();
  result += p1;
  result += p2;
  return result;
}

//Pre: None
//Post: Returns a boolean. True if bool NPoint are the same. False if not.
// Type variables nees to support != operator
template<typename T>
bool operator ==(const NPoint<T> p1, const NPoint<T> p2) {
  if(p1.size() != p2.size()) {
    return false;
  }
  for(int i = 0; i < p1.size(); i++) {
    if(p1.get_item(i) != p2.get_item(i)) {
      return false;
    }
  }
  return true;
}

//Pre: Type variables can only be numerical type. Cannot be strings or chars
//Post: Returns a type T that is the distance between two coordinate points
// Type variables needs to support pow and sqrt
template<typename T>
T distance(const NPoint<T> p1, const NPoint<T> p2) {
  T result;
  result = pow(p1.get_item(0) - p2.get_item(0), 2) + pow(p1.get_item(1) - p2.get_item(1), 2);
  result = sqrt(result);
  return result;
}
