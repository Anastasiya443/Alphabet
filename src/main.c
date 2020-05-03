#include <heading.h>
int main()
{
    char ch, sl[200];
    FILE *input, *output;
    input = fopen("words.txt", "w");
if((input=fopen("words.txt","w")==NULL){
        printf("Cannot open file.\n");
        exit(1);
}
scanf("%s",sl);
fputs(sl,input);
fclose(input);
input = fopen("words.txt", "r");
output = fopen("output.txt", "w");
if((output=fopen("output.txt","w")==NULL){
        printf("Cannot open file.\n");
        exit(1);
}
while((ch=getc(input))!=EOF)
{
        if (ch != ' ') {
            putc(ch, output);
        } else
            putc('\n', output);
}
fclose(input);
fclose(output);
    return 0;
}
