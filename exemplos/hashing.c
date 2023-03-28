#include <string.h>
#define HASH_SIZE=100

unsigned int hashing(char *value){
  unsigned int hash=0;
  for(i=0;i<strlen[value];i++){
      hash=(unsigned int) value[i]+hash;
  }
  return (hash % mod[HASH_SIZE]);   
}

int main(){
  char *value;
  printf("Digite algum texto: "):
  scanf(%s,value);
  prinft("\n simple hash of : %s is %d",value,hashing(value));
}
  
    
