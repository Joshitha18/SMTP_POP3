#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>

//#define MYPORT 3456
#define BACKLOG 10
#define MAXDATASIZE 10000
/* the port users will be connecting to */
/* number of pending connections */
main(int argc,char*argv[])
{
int MYPORT;
MYPORT=atoi(argv[1]);
//printf("%d\n",MYPORT);
int sockfd, new_fd,numbytes;
char buf[MAXDATASIZE];
char buff[MAXDATASIZE];
char buffe[MAXDATASIZE];
char buffer[MAXDATASIZE];
/* listen on sock_fd,
new connection on new_fd */
struct sockaddr_in my_addr;
/* my address information */
struct sockaddr_in their_addr; /* client's address info */
int sin_size;
if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
{
perror("socket");
exit(1);
}
my_addr.sin_family = AF_INET;
my_addr.sin_port = htons(MYPORT);
my_addr.sin_addr.s_addr = INADDR_ANY; /* auto-fill with my IP */
bzero(&(my_addr.sin_zero), 8);
/* zero the rest */
if (bind(sockfd,(struct sockaddr *)&my_addr, sizeof(struct sockaddr)) == -1)
{
perror("bind");
exit(1);
}
if (listen(sockfd, BACKLOG) == -1)
{
perror("listen");
exit(1);
}

/* main accept() loop */

sin_size = sizeof(struct sockaddr_in);
if ((new_fd = accept(sockfd,(struct sockaddr *)&their_addr,&sin_size)) ==
-1)
{
perror("accept");
}
printf("server: got connection from %d\n",
inet_ntoa(their_addr.sin_addr));



char li[100],lin[100]="\n";

//strcat(lin,"\n");

write(new_fd,"+OK POP3 Server ready.",100);

read(new_fd,li,sizeof(li));

while(1){

    FILE* f = fopen(li, "r"); 
    char line2[256];

	int res1,cout1=4,nu=1,b;
char list[5000],lis[100];
    while (fgets(line2, sizeof(line2), f)) {if(cout1>0){cout1--;}
	if(cout1>0 )
	{
		//if(cout1==3){printf("%d %s",nu,line2);nu++;}
		//else{printf("%s",line2);}

		if(cout1==3){
			sprintf(lis,"%d ",nu);
			strcat(list,lis);
			strcat(list,line2);
			nu++;
			}
		else {
		strcat(list,line2);
		}

	}
	res1=strcmp(line2,lin);
	//printf("res1 %d\n",res1);

	if(cout1==0 && res1==0){cout1=4;}
	
    }
fclose(f);
//printf("%s",list);
write(new_fd,list,sizeof(list));
bzero(list,5000);


int m;
//printf("1)STAT 2)LIST 3)RETR 4)DELE 5)QUIT\n");
//scanf("%d",&m);
read(new_fd,&m,sizeof(m));

if(m==1){
    FILE* file = fopen(li, "r"); 
    char line[256];

	int res,cout=0;;

    while (fgets(line, sizeof(line), file)) {
	res=strcmp(line,lin);
	if(res == 0){cout++;}
    }
fclose(file);
//printf("number of emails %d\n\n",cout);
write(new_fd,&cout,sizeof(cout));
}

if(m==2){char all[10000];
    FILE* file = fopen(li, "r"); 
    char line[256];

	int res,cout=0;;

    while (fgets(line, sizeof(line), file)) {
	//printf("%s",line);
strcat(all,line);
    }
fclose(file);
write(new_fd,all,sizeof(all));
bzero(all,10000);
}

if(m==3){int f;char ret[1000];
read(new_fd,&f,sizeof(f));
    FILE* file = fopen(li, "r"); 
    char line[256];

	int res,cout=1;

    while (fgets(line, sizeof(line), file)) {
	if(cout==f){strcat(ret,line);
	//printf("%s",line);
	}
	
	res=strcmp(line,lin);
	if(res == 0){cout++;}
    }
fclose(file);
write(new_fd,ret,sizeof(ret));
bzero(ret,1000);
}

if(m==4){int f;

    FILE* file = fopen(li, "r"); 
	FILE *fptr=fopen("rep.txt","w");
    char line[256];


    while (fgets(line, sizeof(line), file)) {
	fprintf(fptr,"%s",line);
    }
fclose(file);
fclose(fptr);

read(new_fd,&f,sizeof(f));

    file = fopen(li, "w"); 
	fptr=fopen("rep.txt","r");
    char line1[256];

	int res,cout=1;

    while (fgets(line1, sizeof(line1), fptr)) {
	if(cout!=f){
	fprintf(file,"%s",line1);}
	
	res=strcmp(line1,lin);
	if(res == 0){cout++;}
    }
fclose(file);
fclose(fptr);
}

if(m==5){exit(0);}
}

while(waitpid(-1,NULL,WNOHANG) > 0); /* clean up child processes */

close(new_fd);
}

/*
sysad@sysad-XPS-13-9380:~/Downloads/180020009$ ./a.out
server: got connection from -1766271856
Received: Hello. how are you doing.
sysad@sysad-XPS-13-9380:~/Downloads/180020009$ 
*/
