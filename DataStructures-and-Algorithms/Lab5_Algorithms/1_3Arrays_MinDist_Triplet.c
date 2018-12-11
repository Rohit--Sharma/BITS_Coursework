#include <stdio.h>
#include <math.h>

int main()
{
	int a[10] = {1,2,3};
	int b[10] = {4,5,6};
	int c[10] = {11,12,13};
	
	int i = 0, j = 0, k = 0, m = 0;
	int min, diff;
	int mini = 32767;
	while(i <= 2 && j <= 2 && k <= 2)
	{
		diff = abs(a[i] - b[j]) + abs(a[i] - c[k]) + abs(b[j] - c[k]);
		//x[m] = diff;
		//m++;
		//
		if(diff < mini)
		mini=diff;
		//
		//printf("%d\n",x[m]);
		
		min = ((a[i] < b[j]) ? ((a[i] < c[k]) ? a[i] : c[k]) : ((b[j] < c[k]) ? b[j] : c[k]));
		if(min == a[i])
			i++;
		else if(min == b[j])
			j++;
		else
			k++;
	}
	
	
	printf("%d",mini);
	/*min = x[0];
	for(i = 0; i <= m; i++)
	{
		if(x[i] < min)
			min = x[i];
	}
	//printf("%d\n", min);*/
}
