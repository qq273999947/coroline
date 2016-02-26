# include <stdio.h>
# include<stdlib.h>
# include<string.h>
typedef enum
{
	nostate,
	cstate,  //定义一个枚举类型，列举所用到的所有类型
	cppstate,
	endstate
}STATEENUM;
typedef struct state_machine//定义状态机变量
{
	FILE *inputfile;
	FILE *outputfile;
	STATEENUM state;  
}STATE_MACHINE;
STATE_MACHINE go_state={0};
void eventpro(char ch);
void eventproatno(char ch);//全局函数申明
void eventproatc(char ch);
void eventproatcpp(char ch);
int covert(FILE *fin,FILE *fout);
int main ()
{	FILE *fin,*fout;
    char p[50];
	printf("请输入要转换的文件路径：\n");
	scanf("%s",&p);
	if((fin=fopen(p,"r"))==NULL)
	{
		printf("无法打开此文件：\n");
		exit(0);
	}
    if((fout=fopen("C:\\Users\\Administrator\\Desktop\\output.txt","w"))==NULL)
	{
		printf("无法打开此文件：\n");
		exit(0);
	}
	covert(fin,fout); //在主函数中调用状态转换函数
	fclose(fin);
	fclose(fout);
return(0);

}

int covert (FILE *fin,FILE *fout)
{
	if(fin==NULL || fout==NULL)
	{
		printf("Error: Argument Invalid!\n");//状态转换函数
		return -1;
	}
	char ch;
	go_state.inputfile=fin;
	go_state.outputfile=fout;
	go_state.state=nostate;
	while(go_state.state!=endstate)
	{
		ch=fgetc(go_state.inputfile);
		eventpro(ch);
	}
}
void eventpro(char ch)//状态处理函数
{
	switch(go_state.state)
	{
	case nostate:
		eventproatno(ch);
		break;
    case cstate:
		eventproatc(ch);
		break;
	case cppstate:
		eventproatcpp(ch);
		break;
	case endstate:
		printf("运行结束");
		break;
	default :
		break;
	}
}
void eventproatno(char ch)//无状态函数
{
	char nextch;
	switch(ch)
	{
	case '/':
		nextch=fgetc(go_state.inputfile);
		if(nextch=='/')
		{	
			fputc(ch,go_state.outputfile);
		    fputc('*',go_state.outputfile);
			go_state.state=cppstate;
			break;
		}
		
		else if(nextch=='*')
		{
			fputc(ch,go_state.outputfile);
			fputc(nextch,go_state.outputfile);
			go_state.state=cstate;
			
		}
		else
		{
			fputc(ch,go_state.outputfile);
		    fputc(nextch,go_state.outputfile);
		}
		break;
	case EOF:
		go_state.state=endstate;
		break;
	default:
		fputc(ch,go_state.outputfile);
		break;

	}
}
void eventproatcpp(char ch)//Cpp状态函数
{
	char nextch;
	switch(ch)
	{
	case'*':
		nextch=fgetc(go_state.inputfile); 
		if(nextch=='/')
		{
			fputc(' ',go_state.outputfile);
			fputc(' ',go_state.outputfile);
		}
		else 
		{ 
			fputc(ch,go_state.outputfile);
			fputc(nextch,go_state.outputfile);
		}
	break;
	case'/':
		nextch=fgetc(go_state.inputfile); 
	if(nextch=='/'||nextch=='*')
	{
        fputc(' ',go_state.outputfile);
        fputc(' ',go_state.outputfile);
	}
	else 
	{ 
	  fputc(ch,go_state.outputfile);
	   fputc(nextch,go_state.outputfile);
	}
    break;
    case'\n':
		{
		   fputc('*',go_state.outputfile);
	       fputc('/',go_state.outputfile);
           fputc('\n',go_state.outputfile);
		   go_state.state=nostate;
		}
		break;

	case EOF:
		{
			fputc('*',go_state.outputfile);
			fputc('/',go_state.outputfile);
			go_state.state=endstate;
		}
		break;
	default:
    fputc(ch,go_state.outputfile);
	break;	
	}
}
void eventproatc(char ch)//C状态函数
{
   char nextch;
   switch(ch)
   {
   case '*':
	   nextch=fgetc(go_state.inputfile);
	   if(nextch=='/')
	   {
		   fputc('*',go_state.outputfile);
	       fputc('/',go_state.outputfile);
		   go_state.state=nostate;
	   }
	   else 
	   {
         fputc(ch,go_state.outputfile);
	       fputc(nextch,go_state.outputfile);
	   }
	   break;
   case EOF:
	   {
		   go_state.state=endstate;
	   }
	   break;
   case'/':
	   nextch=fgetc(go_state.inputfile);
	   if(nextch=='/')
	   {
            fputc(' ',go_state.outputfile);
            fputc(' ',go_state.outputfile);
	   }
       else if(nextch=='*')
	   {
		   fputc(' ',go_state.outputfile);
           fputc(' ',go_state.outputfile);
	   }
	   else
	   {
           fputc(ch,go_state.outputfile);
	       fputc(nextch,go_state.outputfile);
		}	   
	   break;
   default :
	   fputc(ch,go_state.outputfile); 
	   break;
   }
}
