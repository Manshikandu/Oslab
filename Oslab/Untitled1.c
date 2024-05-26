#include<stdio.h>
#include<conio.h>
void q0(char);
void q1(char);
void q2(char);
void q3(char);
void q4(char);
int current=0;
void q0(char c){
	if(c=='0'){
		
		current=1;
	}
	else if(c=='1'){
		current=4;
	}
	else{
		current=-1;
	}
}
void q1(char c){
	if(c=='0'){
		
		current=2;
	}
	else if(c=='1'){
		current=4;
	}
	else{
		current=-1;
	}
}
void q2(char c){
	if(c=='0'){
		current=1;
	}
	else if(c=='1'){
		current=3;
	}
	else{
		current=-1;
	}
}
void q3(char c){
	if(c=='0'){
		current=4;
	}
	else if(c=='1'){
		current=4;
	}
	else{
		current=-1;
	}
}
void q4(char c){
	if(c=='0'||c=='1'){
		current=4;
	}
	
	else{
		current=-1;
	}
}
int main(){
	char inputstring[20],c;
	int i=0;
	printf("Enter an input string:");
	gets(inputstring);
	c=inputstring[i];
	while(c!='\0'){
		switch(current){
			case 0: q0(c);
			break;
			
			case 1: q1(c);
			break;
			
			case 2: q2(c);
			break;
			case 3: q3(c);
			break;
			case 4: q4(c);
			break;
		}
	}
	c=inputstring[++i];

if(current==3){
	printf("Accepted");
}
	else
	{
	
	printf("Rjected");
	
}
return 0;
}

