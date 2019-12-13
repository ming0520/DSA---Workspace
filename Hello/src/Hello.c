#include <stdio.h>

int a[1000010];

int main(){

	int i, n, x, y, cnt;

	while(~scanf("%d", &n)){
		cnt = 0;

		for(i=0; i<n; i++)
		{
			scanf("%d", &a[i]);
		}

		x = y = a[0];

		for(i=1; i<n; i++)
		{
			if(a[i] > x)
			{
				y = x;
				x = a[i];
			}
			else if(a[i]<x && a[i]>y)
			{
				y = a[i];
			}
		}

		for(i=0; i<n; i++)
		{
			if(a[i] == x)
			{
				cnt++;
			}
		}

		for(i=0; i<n; i++)
		{
			if(a[i]==x && cnt==1)
			{
				printf("%d ", y);
			}
			else
			{
				printf("%d ", x);
			}
		}

		printf("\n");
	}

	return 0;

}
