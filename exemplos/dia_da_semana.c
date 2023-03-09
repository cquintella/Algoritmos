char *dia_semana(int n) {
 static char *d[] = {
 "erro",
 "domingo",
 "segunda-feira",
 "terça-feira",
 "quarta-feira",
 "quinta-feira",
 "sexta-feira",
 "sábado"
 };
 return d[1<=n && n<=7 ? n : 0];
}

int main(void){
  
  printf("%s.\n",dia_semana(2));
  return 0;
}
