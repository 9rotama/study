#include <stdio.h>
#include <math.h>
#define TRUE 1
#define FALSE 0

char grade_char(int);
int char_point(char);

int main(){
 int status=1,score,tani,tani_sum=0,gp_sum=0;
 double gpa;
 char c;
 while(1){
  printf("評点と単位数を入力してください (Ctrl+Dで終了): ");
  status = scanf("%d %d",&score,&tani);
  if(status == EOF) break;
  tani_sum += tani;
  c = grade_char(score);
  gp_sum += char_point(c)*tani;
  printf("%d 点の評価は %c で、Grade Point(GP) は %d です。(%d 単位)\n",score,grade_char(score),char_point(c),tani);
 }
 gpa = (double)gp_sum/(double)tani_sum;
 printf("Grade Point Average(GPA): %1.3f, 単位数: %d\n",round(gpa*1000)/1000,tani_sum);
 return 0;
}

char grade_char(int score){
 char grade;
 if(score >= 0 && score <= 34){
  grade = 'F';
 }else if(score >= 35 && score <= 49){
  grade = 'D';
 }else if(score >= 50 && score <= 64){
  grade = 'C';
 }else if(score >= 65 && score <= 79){
  grade = 'B';
 }else if(score >= 80 && score <= 100){
  grade = 'A';
 }
 return grade;
}

int char_point(char grade){
 int point;
 if(grade=='A'){
  point = 4;
 }else if(grade == 'B'){
  point = 3;
 }else if(grade == 'C'){
  point = 2;
 }else if(grade == 'D'){
  point = 0;
 }else if(grade == 'F'){
  point = 0;
 }
 return point;
}
