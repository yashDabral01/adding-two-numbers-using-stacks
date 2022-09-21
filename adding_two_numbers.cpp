#include<bits/stdc++.h>
using namespace std;
class number{
   private:
   string s1;
   string s2;
   stack <int> st1;
   stack <int> st2;
   stack <int> temp;
   public:
   number(string s1 , string s2){
    this->s1 = s1;
    this->s2= s2;
    getNumFromString(s1,st1);
    getNumFromString(s2,st2);
    addition();
    display(temp);
   }
   void getNumFromString(string s ,stack<int>& st){
    for ( int i = 0; i < s.length(); i++)
    {
        st.push(s[i]-'0');
    }
   }
   void addition(){
      int carry = 0;
      while(!st1.empty()&& !st2.empty()){
        int sum =  st1.top() + st2.top() + carry;
        temp.push(sum%10);
        carry = sum/10;
        st1.pop();
        st2.pop();
      }
      while (!st1.empty())
      {
        temp.push(st1.top()+carry);
        carry = st1.top()/10;
        st1.pop();
      }
      while (!st2.empty())
      {
        temp.push(st2.top()+carry);
        carry = st2.top()/10;
        st2.pop();
      }
      while(carry>0){
        temp.push(carry);
      }
   }
   void display(stack<int>& s){
    while(!s.empty()){
       cout<< s.top() ;
       s.pop();
        
    }
   }
};
int main(){
    string number1 ,number2;
    cout<<"Enter the first number : ";
    cin>>number1;
    cout<<"Enter the second number : ";
    cin>>number2;
    number obj(number1,number2);
    return 0;
}