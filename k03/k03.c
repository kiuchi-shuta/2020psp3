#include <stdio.h>

#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
    //  ここを実装する

    int text_len,key_len,start,pos;
    text_len,key_len=0;
    while(1){
      if(text[text_len]=='\0'){
          break;
      }
     
      text_len++;
    } 
    text_len=text_len-1; 
     while(1)
     {
      if(key[key_len]=='\0'){
          break;
      }  
      key_len++;
    }
    key_len=key_len-1;
   
    
for (start = 0; start+key_len<=text_len; start++)
{
   
    for(pos=0;pos!=key_len;pos++)
 {
  if(  text[start+pos]!=key[pos])
  {

    break;
  }
 }
if (pos=key_len&&text[start+pos]==key[pos])
{
return &text[start];
}
}
return NULL;
}


char* BMSearch(char text[], char key[])
{
    //  ここを実装する

    int text_len,key_len,index,pos,t,i,z=0;
        text_len=0;
        i=0;
        t=0;
    while(1)
    {
      if(text[text_len]=='\0')
      {
          break;
      }
      text_len++;
    } 
    text_len=text_len-1;

    key_len=0;
    while(1)
    {
      if(key[key_len]=='\0')
      {
          break;
      }  
      key_len++;
    }

        char table[256];
        for(z=0;z<256;z++)
        {
          table[z]=key_len;
        }
        for(z=key_len;z>0;z--)
        {
          table[key[z-1]]=i;
          i++;
        }
           index=key_len-1;
          
    while (index<=text_len)
    {
      for(pos=key_len-1;pos>=0;pos--)
      {
      
        if (text[index]==key[pos] )
        {
         
          if (pos==0&&text[index]==key[pos])
          {
            return &text[index];
          }
        }
        else
        {
          break;      
        }
        index--;
      }
          if(index+table[text[index]]<i)
            {
              index=index+1;
            }    
          else
            {
              index=index+table[text[index]];
            } 
          t=index;
    }
  return NULL;
}

int main(void)
{
    char*   str;
    str = ForceSearch(StrOriginal, StrKey);
    printf("Force Search. Find keyword at:%s\n", str);

    str = BMSearch(StrOriginal, StrKey);
    printf("BM Search. Find keyword at:%s\n", str);

    return 0;
}