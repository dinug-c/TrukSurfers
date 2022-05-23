while(number){
  mod = number % 10;
  drawStrokeChar(mod+48,1.2+tmp,0,0);
  number = number / 10;
  tmp += 0.2;
}

char skor2[100];
int skor3 = sprintf(skor2,"SKOR: %d",skor);
drawStrokeText3(skor2,3,0,0);
