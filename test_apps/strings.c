#include <stdio.h>
#include <stdlib.h>

int strlen(char str[]);
void toLower(char str[]);
void toUpper(char str[]);
void toTitle(char str[]);
char* lowercase(char str[]);
char* uppercase(char str[]);
char* titlecase(char str[]);
char* substr(char str[], int from, int to);
char* concat(char str[], char str2[]);
int compare(char str1[], char str2[]);
int compareIgnoreCase(char str1[], char str2[]);
char* trim(char str[]);

int main ()
{
	char str1[] = "Hello there world!";
	char str2[] = "   Test Message...";
	printf("String 1: %s\n", str1);
	printf("String 2: %s\n", str2);
	printf("Length of String 1: %i\n", strlen(str1));
	printf("Length of String 2: %i\n", strlen(str2));
	printf("Upper Case String 1: %s\n", lowercase(str1));
	printf("Lower Case String 1: %s\n", uppercase(str1));
	printf("Title Case String 1: %s\n", titlecase(str1));
	printf("Substring of String 1: %s\n", substr(str1, 1, strlen(str1) - 2));
	printf("Concat of String 1 and 2: %s\n", concat(str1, str2));
	printf("String 1 Compared to String 1: %i\n", compare(str1, str1));
	printf("String 1 Compared to String 2: %i\n", compare(str1, str2));
	printf("String 2 Compared to String 1: %i\n", compare(str2, str1));
	printf("String 1 Compared to String 1 Ignoring Case: %i\n", compare(lowercase(str1), uppercase(str1)));
	printf("String 1 Trim: %i\n", trim(str1));
	
	return 0;
}

int strlen(char str[])
{
	int x = 0;
	
	while (str[x] != 0)
	{
		x++;
	}
	
	return x;
}

void toLower(char str[])
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] >= 65 && str[i] <= 90)
		{
			str[i] += 32;
		}
	}
}

void toUpper(char str[])
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] >= 97 && str[i] <= 122)
		{
			str[i] -= 32;
		}
	}
}

void toTitle(char str[])
{
	toLower(str);
	int x = 1;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] >= 97 && str[i] <= 122 && x == 1)
		{
			str[i] -= 32;
			x = 0;
		}
		else if (x == 0 && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'))
		{
			x = 1;
		}
	}
}

char* lowercase(char str[])
{
	char* ret = str;
	
	for (int i = 0; i < strlen(ret); i++)
	{
		if (ret[i] >= 65 && ret[i] <= 90)
		{
			ret[i] += 32;
		}
	}
	
	return ret;
}

char* uppercase(char str[])
{
	char* ret = str;
	
	for (int i = 0; i < strlen(ret); i++)
	{
		if (ret[i] >= 97 && ret[i] <= 122)
		{
			ret[i] -= 32;
		}
	}
	
	return ret;
}

char* titlecase(char str[])
{
	char* ret = lowercase(str);
	
	int x = 1;
	for (int i = 0; i < strlen(ret); i++)
	{
		if (ret[i] >= 97 && ret[i] <= 122 && x == 1)
		{
			ret[i] -= 32;
			x = 0;
		}
		else if (x == 0 && (ret[i] == ' ' || ret[i] == '\n' || ret[i] == '\t'))
		{
			x = 1;
		}
	}
	
	return ret;
}

char* substr(char str[], int from, int to)
{
	if (from < 0)
	{
		return "ERROR: 'from' cannot be less than zero.";
	}
	else if (from > to)
	{
		return "ERROR: the 'from' must be less than or equal to 'to'";
	}
	else if (to > strlen(str) - 1)
	{
		return "ERROR: 'to' cannot be larger than the string.";
	}
	
	char* ret = (char*) malloc(to - from);
	
	for (int i = from; i <= to; i++)
	{
		ret[i - from] = str[i];
	}
	
	return ret;
}

char* concat(char str1[], char str2[])
{
	char* ret = (char*) malloc(strlen(str1) + strlen(str2) + 1);
	int k = strlen(str1);
	int l = strlen(str2);
	
	for (int i = 0; i < k; i++)
	{
		ret[i] = str1[i];
	}

	for (int j = 0; j < l; j++)
	{
		ret[j + k] = str2[j]; 
	}
	
	return ret;
}

int compare(char str1[], char str2[])
{
	int n = (strlen(str1) < strlen(str2) ? strlen(str1) : strlen(str2));
	
	for (int i = 0; i < n; i++)
	{
		if (str1[i] > str2[i])
		{
			return 1;
		}
		else if (str1[i] < str2[i])
		{
			return -1;
		}
	}
	
	return 0;
}

int compareIgnoreCase(char str1[], char str2[])
{
	char* temp1 = (char*) malloc(strlen(str1));
	temp1 = lowercase(str1);
	char* temp2 = (char*) malloc(strlen(str2));
	temp2 = lowercase(str2);
	
	int n = (strlen(temp1) < strlen(temp2) ? strlen(temp1) : strlen(temp2));
	
	for (int i = 0; i < n; i++)
	{
		if (temp1[i] > temp2[i])
		{
			return 1;
		}
		else if (temp1[i] < temp2[i])
		{
			return -1;
		}
	}
	
	free(temp1);
	free(temp2);
	
	return 0;
}

char* trim(char str[]) // not working lol
{
	char* ret = (char*) malloc(strlen(str));
	int n = 0;
	
	while (str[n] == ' ' && str[n] == '\n' && str[n] == '\t') n++;
	
	for (int i = n; i < strlen(str); i++)
	{
		ret[i - n] = str[i];
	}

	return ret;
}