#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

#define SIZE 2000

char sesli[] = "aeoui";
char sessiz[] = "bcdfghjklmnpqrstvwxyz";

bool sessiz_kontrol(char text[]);
bool sesli_kontrol(char text[]);
void heceleme(char text1[]);

int main()
{
    char text[SIZE];
    
 	while(true)
	{	
		printf("cumle giriniz = ");
	    gets(text);
	    heceleme(text);
	    printf("%s\n",text); 
	}

    return 0;
}

bool kontrol(char dizi[],char temp)
{
	int i;
	for(i = 0; i < strlen(dizi) ; i++)
	{
		if(dizi[i] == temp)
		{
			return true;
		}
	}
	return false;
}

void heceleme(char text1[SIZE]) {
  int i, j, n;
  char textcpy[SIZE];
  
  for (i = 0; i < SIZE; i++) {
    if ((kontrol(sesli,text1[i]) == true) && (kontrol(sesli,text1[i+2]) == true) && (kontrol(sessiz,text1[i+1]) == true)){
		
      int p;
      for (p = i + 1; p < SIZE; p++) {
        textcpy[p - i - 1] = text1[p];
	  }
		
      text1[i + 1] = '-';

      for (n = i + 2; n < SIZE; n++) {
        text1[n] = textcpy[n - i - 2];
      }

    }
    else if((kontrol(sesli,text1[i]) == true) && (kontrol(sessiz,text1[i+1]) == true) && (kontrol(sessiz,text1[i+2]) == true) && (kontrol(sessiz,text1[i+3]) == true) && (kontrol(sesli,text1[i+4]) == true))
	{
	  int p;
      for (p = i + 3; p < SIZE; p++) {
        textcpy[p - i - 3] = text1[p];
	  }
		
      text1[i + 3] = '-';

      for (n = i + 4; n < SIZE; n++) {
        text1[n] = textcpy[n - i - 4];
    }
	}
    else if((kontrol(sesli,text1[i]) == true) && (kontrol(sessiz,text1[i+1]) == true) && (kontrol(sessiz,text1[i+2]) == true) && (kontrol(sesli,text1[i+3]) == true))
	{
	  int p;
      for (p = i + 2; p < SIZE; p++) {
        textcpy[p - i - 2] = text1[p];
	  }
		
      text1[i + 2] = '-';

      for (n = i + 3; n < SIZE; n++) {
        text1[n] = textcpy[n - i - 3];
      }
	}
	else if((kontrol(sesli,text1[i]) == true) && (kontrol(sesli,text1[i+1]) == true))
	{
	  int p;
      for (p = i + 1; p < SIZE; p++) {
        textcpy[p - i - 1] = text1[p];
	  }
		
      text1[i + 1] = '-';

      for (n = i + 2; n < SIZE; n++) {
        text1[n] = textcpy[n - i - 2];
      }
	}
	
	
  }
}
