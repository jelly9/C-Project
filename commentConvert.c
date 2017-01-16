#include "commentConvert.h"

status_t gStatus = NORMAL_STATUS;

//处理正常状态
static void doNormalStatus(FILE* in, FILE* out)
{
	int first = fgetc(in);
	int second = 0;

	assert(in);
	assert(out);

	switch(first){
	case '/' :
		second = fgetc(in);
		if( '*'== second){
			fputc('/', out);
			fputc('/', out);
			gStatus = C_STATUS;
		}else
			if('/' == first){
				fputc(first, out);
				fputc(first, out);
				gStatus = CPP_STATUS;
			}
			else{
				fputc(first, out);
				fputc(first, out);
			}
		break;
	case EOF:
		gStatus = END_STATUS;
		break;
	default:
		fputc(first, out);
		break;
	}

}

//处理c状态
static void doCStatus(FILE* in, FILE* out)
{
	int first = fgetc(in);
	int second = 0;
	int third = 0;

	assert(in);
	assert(out);

	switch(first){
	case '*' :
		second = fgetc(in);
		if('/' == second){
			third = fgetc(in);
			if('\n' == third){
				fputc('\n', out);
			}else{
				fputc('\n', out);
				ungetc(third, in);
			}
			gStatus = NORMAL_STATUS;
		}
		else{
			fputc(first, out);
			ungetc(second, in);
		}

		break;
	case EOF :
		gStatus = END_STATUS;
		break;
	case '\n':
		fputc(first, out);
		fputc('/', out);
		fputc('/', out);
		break;
	default:
		fputc(first, out);
		break;
	}
}

//处理cpp状态
static void doCppStatus(FILE* in, FILE* out)
{
	int first = fgetc(in);

	assert(in);
	assert(out);
	switch(first){
	case '\n' :
		fputc(first, out);
		gStatus = NORMAL_STATUS;
		break;
	case EOF :
		gStatus = END_STATUS;
		break;
	default:
		fputc(first, out);
		break;
	}
}

//状态机
static void statusMachine(FILE* in, FILE* out)
{
	assert(in);
	assert(out);

	while(END_STATUS != gStatus){
		switch(gStatus){
		case NORMAL_STATUS:
			doNormalStatus(in, out);
			break;
		case C_STATUS :
			doCStatus(in, out);
			break;
		case CPP_STATUS :
			doCppStatus(in, out);
			break;
		case END_STATUS :
			break;
		default:
			break;
		}
	}
}

//注释转换开始
void convertBagin()
{
	FILE* in = fopen(INPUT_FILE, "r");
	FILE* out = fopen(OUTPUT_FILE, "w");

	if(NULL == in){
		perror("fopen");
		exit(1);
	}
	
	if(NULL == out){
		perror("fopen");
		exit(2);
	}

	statusMachine(in, out);

	fclose(in);
	fclose(out);
}
















