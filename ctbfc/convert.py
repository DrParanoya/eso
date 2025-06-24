path = input("Enter the full path to your file:\n")
file = open(path, 'r')
content = file.read()
file.close()
file = open(path + ".c", 'w')
file.write("""
#include <stdint.h>
#include <stdio.h>
#define p c[t]++;
#define m c[t]--;
#define l t--;
#define r t++;
#define o printf("%c",c[t]);
#define i scanf("%c",c[t]);
#define s while(c[t]!=0){
#define e }
char c[30000]={};uint16_t t=0;int main(){ 
""")
for c in content:
    match c:
        case '+':
            file.write("p ")
        case '-':
            file.write("m ")
        case '>':
            file.write("r ")
        case '<':
            file.write("l ")
        case '.':
            file.write("o ")
        case ',':
            file.write("i ")
        case '[':
            file.write("s ")
        case ']':
            file.write("e ")
file.write("return 0;}")
file.close()
print("Converted successfully!\n")
