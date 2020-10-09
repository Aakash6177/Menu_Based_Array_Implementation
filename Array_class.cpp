#include<iostream>
#include<algorithm>
using namespace std;

class Array{

private:
  double *a;
  int n;
public:
  Array(){
    n = 0;
    a = nullptr;
  }
  Array(int n){
    this->n = n;
    a = new double[n];
    cout<<"Enter the elements in the Array"<<endl;
    for(int i=0;i<n;i++){
      cin>>a[i];
    }
  }
  void enterElement(){
    cout<<"Enter the elements in the Array"<<endl;
    for(int i=0;i<n;i++){
      cin>>a[i];
    }
  }
  void setElement(int i, double x){
    a[i] = x;
  }

  double getElement(){
    for(int i=0;i<n;i++){
      return a[i];
    }
    return 0;
  }
  Array(Array &b){ // Array obj2(obj1 // b);
    this->n = b.n;
    for(int i=0;i<n;i++){
        a[i] = b.getElement();
    }

  }

  ~Array(){
    delete []a;
  }
  void insertBegining(double x){
    double * temp = new double[n+1];
    temp[0] = x;
    for(int i=0;i<n;i++){
      temp[i+1] = a[i];
    }
    delete [] a;
    a = temp;
    n = n+1;

  }
  void insertEnd(double x){
    double *temp = new double[n+1];
    temp[n] = x;
    for(int i=0;i<n;i++){
      temp[i] = a[i];
    }
    delete [] a;
    a = temp;
    n = n+1;

  }
  void removeBegining(){
    double * temp = new double[n-1];
    for(int i=0;i<n;i++){
      temp[i] = a[i+1];
    }

    delete []a;
    a = temp;
    n = n-1;

  }
  void removeEnd(){
    double * temp = new double[n-1];
    for(int i=0;i<n;i++){
      temp[i] = a[i];
    }

    delete []a;
    a = temp;
    n = n-1;

  }
  void invert(){
    int start = 0, end = n-1;
    while(start < end){
      double temp = a[start];
      a[start] = a[end];
      a[end] = temp;
      start++;
      end--;
    }
  }
  double Max(){
    double max = a[0];
    for(int i=0;i<n;i++){
      if(a[i]>max){
        max = a[i];
      }
    }
    return max;
  }
  double Min(){
    double min = a[0];
    for(int i=0;i<n;i++){
      if(min>a[i]){
        min = a[i];
      }
    }
    return min;
  }
  double Average(){

    double avg = 0;
    for(int i=0;i<n;i++){
      avg = avg + a[i];
    }
    return avg/2;
  }
  void display(){
    for(int i=0;i<n;i++){
      cout<<a[i]<<" ";
    }
  }
  // FIXME
  // Array operator +(Array val){
  //   Array temp;
  //   for(int i=0;i<n;i++){
  //     temp.a[i] = a[i] + val.a[i];
  //   }
  //
  //   return temp;
  // }
  // Array operator +(Array val){
  //   Array temp;
  //   temp.n = n + val.n;
  //   return temp.n;
  // }
  // Array operator *(Array val){
  //   Array temp;
  //   temp.a[i]=
  // }


};

int main(){

Array a1(4);
// FIXME
// a1.enterElement();
// Array a2(3);
// for(int i=0;i<3;i++){
//   a2.setElement(i,i*2);
// }
// Array a3(3);
// for(int i=0;i<3;i++){
//   a3.setElement(i,i*3);
// }
// Array a4(3);
// a4 = a2 + a3;
// a4.display();
int option, value;
double input;

do {

  cout<<"Which operqtion do you want to perform? Enter 0 to exit."<<endl;
  cout<<"1. InsertBegining()"<<endl;
  cout<<"2. InsertEnd()"<<endl;
  cout<<"3. RemoveBegining()"<<endl;
  cout<<"4. RemoveEnd()"<<endl;
  cout<<"5. InvertArray()"<<endl;
  cout<<"6. MaxElement()"<<endl;
  cout<<"7. MinElement()"<<endl;
  cout<<"8. Average()"<<endl;
  cout<<"9. Display()"<<endl;
  cout<<"10. Clear Screen"<<endl;
  
  cin>>option;
  switch(option){
      case 0:
      cout<<"YOU ARE NOW OUT OF THE PROGRAM"<<endl;
        break;
      case 1:
        cout<<"Insert function called \n";
        cout<<"Enter the element to be inserted: ";
        cin>>input;
        a1.insertBegining(input);
        break;
      case 2:
        cout<<"Insert End function called \n";
        cout<<"Enter the element to be inserted: ";
        cin>>input;
        a1.insertEnd(input);
        break;
      case 3:
        cout<<"Remove Begining function called "<<endl;
        a1.removeBegining();
        break;
      case 4:
        cout<<"Remove End function called "<<endl;
        a1.removeEnd();
        break;
      case 5:
        cout<<"Invert Array fiunction called "<<endl;
        a1.invert();
        break;
      case 6:
        cout<<"Max Element in the Array is: "<<a1.Max()<<endl;
        break;
      case 7:
        cout<<"Min Element in the Array is: "<<a1.Min()<<endl;
        break;
      case 8:
        cout<<"Average of all the elements is: "<<a1.Average()<<endl;
        break;
      case 9:
        a1.display();
        break;
      case 10:
        system("clear");
        break;
      default:
        cout<<"Enter a valid option"<<endl;


  }

}
while(option!=0);

  return 0;
}
