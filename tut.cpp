#include <iostream>
using namespace std;


double square (double x)
{
  return x*x;
}

void print_square(double x)
{
  cout << "Square of: " << x << " is " << square(x) << "\n";
}


void pointer_test()
{
  char v[4] {'a', 'b', 'c', 'd'};
  
  char* im_a_pointer = &v[0];
  char im_a_char = *im_a_pointer;
  char& im_a_reference = v[1];
  char im_ref_char = im_a_reference;

  cout << im_a_pointer << " is a memory address that points to a\n";
  cout << im_a_char << " is a\n";
  cout << im_a_reference << " is b\n";
  cout << im_ref_char << " is b\n";

  for (auto x : v)
    cout << x;
  cout << "\n";
  
  for (auto& x : v)
    cout << x;
  cout << "\n";

  if (im_a_pointer != nullptr)
    cout << "not null\n";
}

class Vector {
public:
  Vector (int s) :elem{new double[s]}, sz {s}{ } //construct a vector
  double& operator[] (int i) {return elem[i];} //element access : subscripting
  int size() {return sz;}
private:
  double* elem; //pointer to elements
  int sz; //number of elements
};

double read_and_sum(int s)
{
  Vector v(s);
  cout << "Enter vector elements\n";
  for (int i = 0; i!=v.size(); ++i)
    cin>>v[i];

  double sum {0};
  for (int i = 0; i!=v.size(); ++i)
    sum+=v[i];
  return sum;
}

int main ()
{
  auto value_0 {2};
  auto value_1 {4};

  cout << read_and_sum (3) << " is Sum of vector \n";
  
  cout << "Hi there\n";
  print_square(value_0);
  print_square(value_1);
  pointer_test();
  return 0;
}
