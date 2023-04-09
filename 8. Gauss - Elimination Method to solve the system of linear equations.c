#include<stdio.h>
int main()
{
    int n,i,j,k;
    float arr[4][5],a,x[3],sum=0.0;

    printf("Enter the order of matrix: ");
    scanf("%d",&n);

    printf("\nEnter the elements of augmented matrix row-wise:\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=(n+1); j++)
        {
            printf("arr[%d][%d] : ",i,j);
            scanf("%f",&arr[i][j]);
        }
    }

    //for upper triangular matrix
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(i>j)
            {
                a=arr[i][j]/arr[j][j];
                for(k=1; k<=n+1; k++)
                {
                    arr[i][k]=arr[i][k]-a*arr[j][k];
                }
            }
        }
    }

    //for backward substitution
    x[n]=arr[n][n+1]/arr[n][n];
    for(i=n-1; i>=1; i--)
    {
        sum=0;
        for(j=i+1; j<=n; j++)
        {
            sum=sum+arr[i][j]*x[j];
        }
        x[i]=(arr[i][n+1]-sum)/arr[i][i];
    }

    //showing final result
    printf("\nThe solution is: \n");
    for(i=1; i<=n; i++)
    {
        if(i==1)         printf("x = %.1f\n",x[i]);
        else if(i==2)    printf("y = %.1f\n",x[i]);
        else             printf("z = %.1f\n",x[i]);
    }
    return(0);
}
