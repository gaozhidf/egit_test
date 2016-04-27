#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
   FILE *fp;

   fp = fopen("./tmp/test.txt", "w+");
   fprintf(fp, "This is testing for fprintf...\n");
   fputs("This is testing for fputs...\n", fp);
   fclose(fp);
   
   time_t t = time(0);
   char tstamp[64],filepath[32];
   strftime(tstamp, sizeof(tstamp), "%Y-%m-%d-%H-%M-%S", localtime(&t));
   printf("%s\n", tstamp);
   sprintf(filepath, "./tmp/%s.log", tstamp);

   printf("%s\n", "dajiahao");

   // fp = fopen(filepath, "a+");
   if((fp = fopen(filepath, "a+")) == NULL)
   {
   		printf("Cannot Open LogFile\n");
   		exit(-1);
   }

   fprintf(fp, "%s\n", "dajiahao");
   printf("%s\n", "dajiahao0");
   fprintf(fp, "| Num | Current Timestamp | Time Difference | Range Between Modems |\n");
 
   
   return 0;
}
