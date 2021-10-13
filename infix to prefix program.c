#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
strrev (char *str)
{
  int n = strlen (str);

  for (int i = 0; i < n / 2; i++)
    {
      int temp = str[i];
      str[i] = str[n - i - 1];
      str[n - i - 1] = temp;
    }

  for (int i = 0; str[i] != '\0'; i++)
    {
      if (str[i] == ')')
	{
	  str[i] = '(';
	}
      else if (str[i] == '(')
	{
	  str[i] = ')';
	}
    }

}


  int checkop (char n)
  {
    if (n == '+' || n == '-' || n == '*' || n == '/' || n == '^')
      {
	return 1;
      }
    else if (n == '(' || n == ')')
      {
	return 3;
      }
    else
      {
	return 0;
      }
  }

  int precedence (char n)
  {
    if (n == '^')
      {
	return 3;
      }
    if (n == '/' || n == '*')
      {
	return 2;
      }
    if (n == '+' || n == '-')
      {
	return 1;
      }
  }

  int main ()
  {

    int i, k = 0, top = -1;
    char str1[100];
    char str2[100];
    char str3[100];

    printf ("give the expression\n");
    scanf ("%s", str1);

    strrev (str1);

    for (i = 0; str1[i] != '\0'; i++)
      {
	if (checkop (str1[i]) == 0)
	  {
	    str3[k] = str1[i];
	    k++;
	  }
	else if (checkop (str1[i]) == 3)
	  {
	    if (str1[i] == '(')
	      {
		top = top + 1;
		str2[top] = str1[i];

	      }
	    else if (str1[i] == ')')
	      {
		while (str2[top] != '(')
		  {
		    str3[k] = str2[top];
		    top = top - 1;
		    k++;
		  }
		top = top - 1;
	      }
	  }
	else if (checkop (str1[i]) == 1)
	  {
	    if ((precedence (str1[i]) > precedence (str2[top])) || top == -1
		|| str2[top] == '(')
	      {
		top = top + 1;
		str2[top] = str1[i];

	      }
	    else if (precedence (str1[i]) <= precedence (str2[top]))
	      {
		while (precedence (str1[i]) <= precedence (str2[top]))
		  {
		    str3[k] = str2[top];
		    top = top - 1;
		    k++;
		    if (str2[top] == '(')
		      {
			break;
		      }
		  }

		top = top + 1;
		str2[top] = str1[i];

	      }
	  }
      }
    for (i = top; i > -1; i--)
      {
	str3[k] = str2[top];
	top = top - 1;
	k++;
      }
    str3[k] = '\0';

    strrev (str3);
    printf ("%s", str3);

    return 0;
  }

