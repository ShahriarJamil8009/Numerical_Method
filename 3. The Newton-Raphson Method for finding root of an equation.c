#include<stdio.h>
#include<math.h>
int fixed_a,fixed_b,i=0,j,count,count1,count2;  //Globally declaration
float a,b,x=0,x_n,f_x,f__x,arr[50],less_or_greater_then_zero,zero;

/*(user-define-function) Calculating the equation*/
//start
float calculating_equation()
{
    f_x=(x*x*x)-x-11;
}
//end

/*(user-define-function) value of f'(x)*/
//start
float equations_derivative()
{
    f__x=3*(x*x)-1; //Value of f'(x)
}
//end

/*(user-define-function) Calculating the formula of root*/
//start
float formula()
{
    x_n=x-(f_x/f__x);
}
//end

/*(user-define-function) To find two values with opposite sign*/
//start
int two_values()
{
    while(1)
    {
        a=calculating_equation();
        ++x;    //increase the value of 'x' , such as f(0),f(1),---,f(x)
        b=calculating_equation();

        if((a>0 && b<0)||(a<0 && b>0))
        {
            fixed_a=a;
            fixed_b=b;
            a=x-1;
            b=x;
            break;
        }
    }
}
//end

/*(user-define-function) Find the value of x from a and b which is nearby of zero(0)*/
//start
int nearly_of_zero()
{
    if(fixed_a<0)
    {
        fixed_a=fixed_a*(-1);
        ++count2;
    }
    else    fixed_b=fixed_b*(-1);

    if(fixed_a>fixed_b) x=b;
    else    x=a;

    if(count2!=0)    fixed_a=fixed_a*(-1);
    else    fixed_b=fixed_b*(-1);
}
//end

/*(user-define-function) finding the root of the given equation*/
//start
int calculation_for_root()
{
    while(1)
    {
        calculating_equation(); //value of f(Xn)
        equations_derivative(); //value of f'(Xn)
        formula();    //value of root (Xn+1)
        less_or_greater_then_zero=f_x;
        count1=0;

        if(f_x<0)   //if f_x is negative, then convert it to positive to check twice in next for loop
        {
            f_x=f_x*(-1);
            less_or_greater_then_zero=f_x;
            ++count1;
        }

        for(i; i<50; )
        {
            arr[i]=f_x;
            count=0;
            for(j=i-1; j>=0; j--)
                if(f_x==arr[j]) ++count;
            ++i;
            break;
        }

        if(count1!=0)    f_x=f_x*(-1);

        printf("  %d          %.3f      %.3f       %.3f        %.3f\n",i,x,f_x,f__x,x_n);
        x=x_n;

        if(f_x==0  || less_or_greater_then_zero<=zero || count==1) return 0;
    }
}
//end

/*main function*/
//start
int main()
{
    two_values();//To find two values with opposite sign

    printf("As f(%d) and f(%d) are opposite sign\n",(int)a,(int)b);
    printf("Therefore, the root lies between (%d,%d)\n\n",(int)a,(int)b);
    zero=0.001;
    printf("Assume approximately zero ~ %.3f\n\n",zero);
    printf("Interval       x         f(x)       f'(x)        x(n+1)\n");
    printf("--------------------------------------------------------\n");

    nearly_of_zero();   //Find the value of x from a and b which is nearby of zero(0)
    calculation_for_root(); //Finding the root of the given equation

    printf("The root is : %.3f\n",x);
    return 0;
}
//end
