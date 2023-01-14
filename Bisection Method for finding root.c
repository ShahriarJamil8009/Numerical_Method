// Total line of this code is (75)
#include<stdio.h>
#include<math.h>
int a,b,fixed_a,fixed_b,i=0,j,count,count1;  //Globally declaration
float x=0,result,positive,negative,f_x,arr[50],less_or_greater_then_zero,zero;

/*(user-define-function) Calculating the equation*/
//start
float calculating_equation()
{
    result=(x*x*x)-x-11;
    return result;
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

/*(user-define-function) Checking a and b are positive or negative*/
//start
void positive_negative_values()
{
    if(fixed_a>0)   positive=a;
    else    positive=b;
    if(fixed_a<0)   negative=a;
    else    negative=b;
}
//end

/*(user-define-function) finding the root of the given equation*/
//start
int calculation_for_root()
{
    while(1)
    {
        x=(positive+negative)/2;
        f_x=calculating_equation();
        less_or_greater_then_zero=f_x;
        count1=0;
        if(less_or_greater_then_zero<0)   //if f_x is negative, then convert it to positive to check twice in next for loop
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
        printf("  %d          %.3f      %.3f       %.3f        %.3f\n",i,negative,positive,x,f_x);
        if(f_x==0  || less_or_greater_then_zero<=zero || count==1) return 0;
        else if(f_x>0)  positive=x;
        else if(f_x<0)  negative=x;
    }
}
//end

/*main function*/
//start
int main()
{
    two_values();   //To find two values with opposite sign

    positive_negative_values(); //checking a and b are positive or negative

    zero=0.001;
    printf("Assume approximately zero ~ %.3f\n\n",zero);

    printf("Interval       a          b           x           f(x)\n");
    printf("--------------------------------------------------------\n");
    calculation_for_root(); //finding the root of the given equation
    printf("The root is : %.3f\n",x);
    return 0;
}
//end
