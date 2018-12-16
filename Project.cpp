/*tejas jambhale 17BCE0861*/
#include <iostream>
#include <math.h>
using namespace std;

struct poly{
    float coeff;
    int pow;
    poly *next;
};

void create(poly *node)
{
 char ch;
 cout<<"Enter the polynomial"<<endl;
  cout<<"Enter coefficient and exponent of each term"<<endl;
 do
 {

  cout<<"\n enter coeff:";
  cin>>node->coeff;
  cout<<"\n enter power:";
  cin>>node->pow;
  node->next=new poly;
  node=node->next;
  node->next=NULL;
  cout<<"\n continue(y/n):";
  cin>>ch;
 }
 while(ch=='y' || ch=='Y');
}

void show(poly *node,int flag)
{
    if (flag==0)
cout<<"The entered polynomial is"<<endl;
 while(node->next!=NULL)
 {
     if (node->pow!=0)
  cout<<node->coeff<<"x^"<<node->pow;
  else
    cout<<node->coeff;
  node=node->next;
  if(node->next!=NULL)
   cout<<"+";
 }
 cout<<endl;
}

void polyadd(poly *poly1, poly *poly2, poly *poly3)
{
while(poly1->next && poly2->next)
    {
        if(poly1->pow > poly2->pow)
        {
            poly3->pow = poly1->pow;
            poly3->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        else if(poly1->pow < poly2->pow)
        {
            poly3->pow = poly2->pow;
            poly3->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        else
        {
            poly3->pow = poly1->pow;
            poly3->coeff = poly1->coeff+poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        poly3->next = new poly;
        poly3 = poly3->next;
        poly3->next = NULL;
    }
while(poly1->next || poly2->next)
    {
        if(poly1->next)
        {
            poly3->pow = poly1->pow;
            poly3->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if(poly2->next)
        {
            poly3->pow = poly2->pow;
            poly3->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        poly3->next = new poly;
        poly3 = poly3->next;
        poly3->next = NULL;
    }
}

void  multiply(poly* poly3, poly* poly1, poly* poly2)
{
  poly*temp=poly2;
   while(poly1 != NULL)
   {
      while(poly2 != NULL)
      {
         poly3->coeff = (poly1->coeff) * (poly2->coeff);
         poly3->pow = poly1->pow + poly2->pow;
         poly2 = poly2->next;
if (poly1->next==NULL)
    break;
         if(poly2!=NULL)
         {
           poly3->next = new poly;
           poly3 = poly3->next;
           poly3->next = NULL;
         }

      }poly2 =  temp;
      poly1 = poly1->next;
   }

   }

void Evaluate(poly *poly1,float x)

{
poly *Temp;
Temp= new poly;
float result = 0.0 ;

Temp = poly1;

while(Temp->next!= NULL)
{
result = result+Temp->coeff * pow(x, Temp->pow);
Temp = Temp->next;

}
cout<<result<<endl;
}

void derivative(poly* poly2, poly* deri)
{
  poly* ptr;
  ptr = poly2;
  while(ptr->next!=NULL)
  {
     deri->coeff = (ptr->coeff)*(ptr->pow);
     if(ptr->pow == 0)
     {
        deri->pow = 0;
     }
     else
        deri->pow = (ptr->pow)-1;
     deri->next = NULL;
     ptr = ptr->next;
     deri->next = new poly;
     deri = deri->next;
     deri->next = NULL;
  }
}

void degree(poly *poly1)
{
    int deg;
    deg=poly1->pow;
    cout<<"The degree is"<<endl;
   cout<<deg<<endl;
}


int searchterm(poly *poly1,int exp)
{
    while(poly1->next!=NULL)
    {
        if(poly1->pow==exp)
           {
               cout<<poly1->coeff<<"x^"<<poly1->pow<<endl;
               return poly1->coeff;
                break;
           }
        else
            poly1=poly1->next;

    }
    cout<<"The term is not present in entered polynomial"<<endl;
}

void multconst(poly *poly1,int num)
{
    while(poly1->next!=NULL)
    {
        poly1->coeff=poly1->coeff*num;
        poly1=poly1->next;
    }
}

void numterms(poly*poly1)
{int count=0;
    while(poly1->next!=NULL)
    {
        count=count+1;
        poly1=poly1->next;
    }
    cout<<"The number of terms are"<<endl;
    cout<<count<<endl;
}

void extrema(poly *poly1)
{
    float a,b,ext;
    poly *temp;
    temp=poly1;
    a=poly1->coeff;
    b=poly1->next->coeff;
    ext=((-1)*b)/(2*a);
    if (a>0)
    {
        cout<<"The entered quadratic equation has minima at x ="<<ext<<endl;
        cout<<"The minimum value of quadratic is ";
        Evaluate(temp,ext);
        cout<<"The graph of the polynomial is decreasing from +inf to x = "<<ext<<" and then starts increasing till -inf"<<endl;
    }
    else
    {
        cout<<"The entered quadratic equation has maxima at x = "<<ext<<endl;
        cout<<"The maximum value of quadratic is ";
        Evaluate(temp,ext);
        cout<<"The graph of the polynomial is increasing from -inf to x = "<<ext<<" and then starts decreasing till +inf"<<endl;
    }

}

void linear(poly *poly1)
{
    float a,b,sol;
    if (poly1->pow!=1)
        cout<<"Please enter correct linear equation";
    else
        {
    a=poly1->coeff;
    b=poly1->next->coeff;
    if (a!=0)
    sol=((-1)*b)/a;
    else
        sol=0;
    cout<<"The solution of the linear equation is x = "<<sol<<endl;
    }
}

void quadratic(poly *poly1)
{
    int a,b,c;
    float sol1,sol2,Det;
a=poly1->coeff;
b=poly1->next->coeff;
c=poly1->next->next->coeff;
Det=(b*b)-(4*a*c);
if (Det<0)
    cout<<"Roots of the equation are imaginary"<<endl;
else
{
    sol1=((-1)*b+sqrt(Det))/2*a;
    sol2=((-1)*b-sqrt(Det))/2*a;
    cout<<"The roots are x = "<<sol1<<" and x = "<<sol2<<endl;
}
}

void integral(poly* poly2, poly* inte)
{
  poly* ptr;
  ptr = poly2;
  while(ptr->next!=NULL)
  {

     if(ptr->pow != 0)
      inte->coeff = (ptr->coeff)/(ptr->pow);
      else
        inte->coeff=ptr->coeff;
    inte->pow = (ptr->pow)+1;
     inte->next = NULL;
     ptr = ptr->next;
     inte->next = new poly;
     inte = inte->next;
     inte->next = NULL;
  }
}
int main()
{
    do
    {
        int option;
        poly *poly1,*poly2,*poly3;
          poly1=new poly;
        poly2=new poly;
        poly3=new poly;
        cout<<"****************POLYNOMIAL IMPLEMENTATION****************"<<endl<<endl;
        cout<<"Choose an option"<<endl<<endl;
        cout<<" 1. Addition of two polynomials"<<endl;
        cout<<" 2. Subtraction of two polynomials"<<endl;
        cout<<" 3. Multiplication of two polynomials"<<endl;
        cout<<" 4. Evaluating a Polynomial"<<endl;
        cout<<" 5. Derivative of a Polynomial"<<endl;
        cout<<" 6. Integral of a polynomial"<<endl;
        cout<<" 7. Find Degree of Polynomial"<<endl;
        cout<<" 8. To Search for a term in a Polynomial"<<endl;
        cout<<" 9. Find negation of a polynomial"<<endl;
        cout<<" 10. Multiply the polynomial with a constant"<<endl;
        cout<<" 11. Count the number of terms in the polynomial"<<endl;
        cout<<" 12. Find Extrema (MAX or MIN) and Monotonicity of Quadratic Polynomial"<<endl;
        cout<<" 13. Solve a linear Polynomial"<<endl;
        cout<<" 14. Solve a Quadratic polynomial"<<endl;
        cout<<" 15. Exit"<<endl<<endl;
        cin>>option;
        switch(option)
        {
        case 1:
            create(poly1);
            show(poly1,0);
            create(poly2);
            show(poly2,0);
            polyadd(poly1,poly2,poly3);
            cout<<"Sum of two polynomials entered is"<<endl;
            show(poly3,1);
            break;

        case 2:
            create(poly1);
            show(poly1,0);
            create(poly2);
            show(poly2,0);
            multconst(poly2,-1);
            polyadd(poly1,poly2,poly3);
            cout<<"Difference of two polynomials entered is"<<endl;
            show(poly3,1);
            break;
        case 3:
            create(poly1);
            show(poly1,0);
            create(poly2);
            show(poly2,0);
            multiply(poly3,poly2,poly1);
            cout<<"Product of two polynomials entered is"<<endl;
            show(poly3,1);
            break;
        case 4:
            create(poly1);
            show(poly1,0);
            float num;
            cout<<"Enter value at which polynomial is to be evaluated"<<endl;
            cin>>num;
            cout<<"The value of the polynomial at x = "<<num<<" is ";
            Evaluate(poly1,num);
            break;
        case 5:
            create(poly1);
            show(poly1,0);
            derivative(poly1,poly3);
            cout<<"The derivative of entered polynomial is"<<endl;
            show(poly3,1);
            break;
        case 6:
            create(poly1);
            show(poly1,0);
            integral(poly1,poly3);
            cout<<"The integral of the entered polynomial is"<<endl;
            show(poly3,1);
            break;
        case 7:
            create(poly1);
            show(poly1,0);
            degree(poly1);
            break;
        case 8:
            create(poly1);
            show(poly1,0);
            int exp;
            cout<<"Enter exponent of term to be searched"<<endl;
            cin>>exp;
            searchterm(poly1,exp);
            break;
        case 9:
            create(poly1);
            show(poly1,0);
            multconst(poly1,-1);
            cout<<"The negation is"<<endl;
            show(poly1,1);
            break;
        case 10:
            create(poly1);
            show(poly1,0);
            cout<<"Enter constant to be multiplied"<<endl;
            int num1;
            cin>>num1;
            multconst(poly1,num1);
            cout<<"The result is"<<endl;
            show(poly1,1);
            break;
        case 11:
            create(poly1);
            show(poly1,0);
            numterms(poly1);
            break;
        case 12:
            create(poly1);
            show(poly1,0);
            extrema(poly1);
            break;
        case 13:
            create(poly1);
            show(poly1,0);
            linear(poly1);
            break;
        case 14:
            create(poly1);
            show(poly1,0);
            quadratic(poly1);
            break;
        case 15:
            return 0;
        }
        cout<<endl<<endl;
    }
    while(1);
}

