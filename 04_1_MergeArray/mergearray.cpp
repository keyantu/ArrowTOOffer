#include<iostream.h>
#include <stdio.h>

void Merge(int array1[],int array2[],int length,int i,int j)
{
	if(array1==NULL || array2==NULL || length <=0)
		return;

    int newlength=i+j;
	if(newlength>length)
		return;

	int k=newlength-1;
	i--;
	j--;

	while(i>=0 && j>=0 && k>=i)
	{
		if(array1[i]>array2[j])
		{
			array1[k]=array1[i];
			k--;
			i--;
		}
		else
		{
			array1[k]=array2[j];
			k--;
			j--;
		}
	}
	if(i>=0)
	{
		while(i>=0)
		{
			array1[k--]=array1[i--];
		}
	}
	if(j>=0)
	{
		while(j>=0)
		{
			array1[k--]=array2[j--];
		}
	}
}

bool isSame(int a[], int b[], int i, int j)
{
	if(i!=j)
		return false;
	if(a==NULL || b==NULL)
		return false;
	
	for(int k=0;k<i;k++)
	{
		if(a[k]!=b[k])
			return false; 
	}
	return true;
}
void Test(char * testName,int array1[], int array2[], int length, int i,int j,int expected[], int k)
{
	if(testName!=NULL)
		printf("%s begins: \n",testName);

	Merge(array1,array2,length,i,j);
    for(int h=0; h<k; h++)
		cout<<expected[h];
	cout<<endl;
	
	int newlength=i+j;
	for( h=0; h<newlength; h++)
		cout<<array1[h];
	cout<<endl;


    if(isSame(array1,expected,i+j,k))
		printf("passed.\n");
	else
		printf("failed.\n");

}

void Test1()
{
	int array1[20]={1,3,5};
	int array2[]={2,4,6};
	int expected[]={1,2,3,4,5,6};
	Test("Test1", array1, array2, 20, 3, 3, expected, 6);
}
void Test2()
{
	int array1[20]={1,2,3};
	int array2[]={4,5,6};
	int expected[]={1,2,3,4,5,6};
	Test("Test2", array1, array2, 20, 3, 3, expected, 6);
}
void Test3()
{
	int array1[20]={0};
	int array2[]={1,2,3};
	int expected[]={1,2,3};
	Test("Test3", array1, array2, 20, 0, 3, expected, 3);
}
void Test4()
{
	int array1[20]={1,2,3};
	int array2[]={0};
	int expected[]={1,2,3};
	Test("Test4", array1, array2, 20, 3, 0, expected, 3);
}
void Test5()
{
	int array1[20]={0};
	int array2[]={0};
	int expected[]={0};

	

	Test("Test5", array1, array2, 20, 0, 0, expected, 0);
}

void main()
{
	Test1();
	cout<<"==========="<<endl;
	Test2();
    cout<<"==========="<<endl;
	Test3();
	cout<<"==========="<<endl;
	Test4();
    cout<<"==========="<<endl;
	Test5();
}

