/*
regex mayb?:
only escape sequence im going to process is ;
letter = 'A'|...|'Z'|'a'|...|'z'
digit  = '0'|'1'|'2'|'3'|'4'|'5'|'6'|'7'|'8'|'9'
number = digit digit*
identifier = letter (letter|digit)*
operator = '='
keyword = '+'|'-'|'*'|'/'|'='
escape sign = ';'
openPar='('
closePar=')'
statement = identifier operator identifier keyword 
closedStatement= openPar statement closedPar



*/
#include<stdio.h>
#include<stdlib.h>
#include "Line.h"




int main(int argc,char* argv[]){
    int countChar=0;
    FILE* ptr;
   // FILE* outp;

    
    Line* daHead;
    daHead=(Line*)malloc(sizeof(Line));
    initLine(daHead);

    Line* line=daHead;
    

    
 

    ptr=fopen(argv[1],"r");
    //outp=fopen("outLex.tokens","w");

    if(NULL==ptr){
        printf("file cant be open sadge");
    }

    while ((countChar=getc(ptr)) != EOF){
        
       


        if (countChar == ' '){
            continue;
        }else if(countChar=='\n'){
            if(line==NULL){
                continue;
            }
            if(line!=NULL){
                Line* hold;
                hold=(Line*)malloc(sizeof(Line));
                initLine(hold);
                line->nextLine=hold;
                line = hold;
                
                
            }
            



        }else{
            if(line != NULL){
                appendCharToLine(line,countChar);

            }else{
                line=(Line*)malloc(sizeof(Line));
                initLine(line);
                appendCharToLine(line,countChar);
            }
        }   
        
    }
    
   
    
        
  /*  Token* head= (Token*) malloc(sizeof(Token));
    Token* tracker=head;
    

    while(daHead!=NULL){
       
        tracker=makeTokens(daHead);
        printToken(tracker,outp);
        Line* copy=daHead->nextLine;
        daHead=copy;
  
        
        
        
        
        
    }
    
    freeToken(head);
 */   
    printLines(daHead);
    freeLines(daHead);
    fclose(ptr);
    //fclose(outp);

}