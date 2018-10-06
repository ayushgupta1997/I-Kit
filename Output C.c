1.
#include<stdio.h>
#define pxx(a,v) printf("val=%d",a##v)
main(){int x1=12,x2=24,x3=35;
pxx(x,1);
pxx(x,2);
pxx(x,2+1);
}

2.
#include<stdio.h>
#define fun(k) a+b/*d-bc*/c
int main()
{
  int a,b,c,*d,bc;
  a =  6 ;
  b =  5 ;
  c =  4 ;
  bc =  2 ;
  d = &c;
 printf("%d",fun(k));
 getch();
}


#include<stdio.h>
int main()
{
   printf("%%dd\n",12);
   system("PAUSE");
}

#include<stdio.h>
main()
{
    int num[] = {1,2,3};
    int i = 2;    
    printf( "%d  %d",++i[num],--i[num]);
    return 0;
}

#include<stdio.h>
int main()
{
    char a,b;
    printf("%d ",12);
    printf("%d ",143);
    printf("%d ",scanf("%d%d",&a,&b));
}
