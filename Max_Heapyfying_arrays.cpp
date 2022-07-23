#include <bits/stdc++.h>
using namespace std;

void heapify (int *arr, int i, int n)
{ 
    
    int x = 2*i ;
    int y=  2*i +1 ;
  if (y <= n)
  {
    if (arr[i] < arr[x] || arr[i] < arr[y])
	{
	  if (arr[x] >= arr[y])
	  {
	      swap (arr[i], arr[x]);
	      heapify (arr, x, n);
	  }
	  else
	  {
	      swap (arr[i], arr[y]);
	      heapify (arr, y, n);
	  }
    }
  }

  else if(x<=n)
  {
     if (arr[i] < arr[x])
	{
	    swap (arr[i], arr[x]);
	    heapify (arr, x, n);
    } 
  }

}

int main ()
{
  int n;
  cout << "enter the size of array\n";
  cin >> n;

  int arr[n];
  cout << "enter the content of the array\n";
  for (int i = 1; i <= n; i++)
    {
      cin >> arr[i];
    }

  for (int i = n; i >= 1; i--)
    {
      heapify (arr, i, n);
    }

  for (int i = 1; i <= n; i++)
    {
      cout << arr[i] << " ";
    }

  return 0;
}
