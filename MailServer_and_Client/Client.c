#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

//#define PORT 3456 /* the port client will be connecting to */
#define MAXDATASIZE 1000

int main(int argc, char *argv[]) {
int z=0;
	char from[51],to[51],sub[2000],email[501],d,dm[100];
	int cc=0;
	int n;
while(1){n=0;

	while(1){

	printf("Select 1)Manage Mail 2)Send Mail 3)Quit\n");


	scanf("%d",&n);
	char ch;
	scanf("%c",&ch);

		if(n==1){break;}
		if(n==3){break;}

		if(n==2){
		//fgets(dm,50,stdin);
		printf("FROM:\n");
		fgets(from,50,stdin);
		printf("TO:\n");
		fgets(to,50,stdin);
		printf("SUBJECT:\n");
		fgets(sub,150,stdin);
		printf("EMAIL: ");
		fgets(email,500,stdin);
		scanf("%c",&d);

//printf("%c",d);

		int f,t,s,e,f1=0,t1=0,s1=0,e1=0;
		f=strlen(from);
		t=strlen(to);
		s=strlen(sub);
		e=strlen(email);

		int i,c=0;

		for(i=0;i<f;i++) {cc++;
			if(from[i]=='@') {f1++;}
			
		}

		for(i=0;i<t;i++) {
			if(to[i]=='@') {t1++;}
		}

		if(f1 ==0 || t1 ==0 || d != '.'){printf("Incorrect format\n");}

		if(f1 >0 && t1 >0 && d == '.'){z=1;break;}
	
		}
	}

	//printf("hi");
	//printf("z %d\n",z);

	if(z==1){int PORT;
printf("PORT NUMBER:\n");
scanf("%d",&PORT);

		int sockfd, numbytes;
		char buf[MAXDATASIZE];
		struct hostent *he;
		struct sockaddr_in their_addr; /* client's address information */

		if (argc != 2)
		{
			fprintf(stderr,"usage: client hostname\n");
			exit(1);
		}

		if ((he=gethostbyname(argv[1])) == NULL)
		{
			herror("gethostbyname");
			exit(1);
		}
//printf("he %d\n",he);

		/* get the host info */

		if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		{
			perror("socket");
			exit(1);
		}

		their_addr.sin_family = AF_INET;
		their_addr.sin_port = htons(PORT);
		their_addr.sin_addr = *((struct in_addr *)he->h_addr);
		bzero(&(their_addr.sin_zero), 8);
			
		if (connect(sockfd,(struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1)
		{
			perror("connect");
			exit(1);
		}
/*
		printf("enter paragraph\n");
		char para[10000];
		scanf("%s", para);
		int len;
		len=strlen(para);
		printf("len %d\n",len);

		if (send(sockfd, para, len, 0) == -1)
			perror("send");

		int sen,w,c,tmp,temp,tmpr;

	read(sockfd, &tmp, sizeof(tmp));
	sen=ntohl(tmp);
	printf("\nsentences: %d\n",sen);

	read(sockfd, &temp, sizeof(temp));
	w=ntohl(temp);
	printf("words: %d\n",w);

	read(sockfd, &tmpr, sizeof(tmpr));
	c=ntohl(tmpr);
	printf("characters: %d\n",c);
*/
/*
char y[]="^";

	printf("\nHELO %s\n\n",argv[1]);
	printf("MAIL FROM: %s\n",from);
	printf("RCPT TO: %s\n",to);
	printf("%s\n",sub);
	printf("%s\n",email);
	printf("QUIT\n");

	if (send(sockfd, argv[1], strlen(argv[1]), 0) == -1)
		perror("send");

	if (send(sockfd, y, strlen(y), 0) == -1)
		perror("send");
    
	if (send(sockfd, from, strlen(from), 0) == -1)
		perror("send");

	if (send(sockfd, y, strlen(y), 0) == -1)
		perror("send");

	if (send(sockfd, to, strlen(to), 0) == -1)
		perror("send");

	if (send(sockfd, y, strlen(y), 0) == -1)
		perror("send");

	if (send(sockfd, sub, strlen(sub), 0) == -1)
		perror("send");

	if (send(sockfd, y, strlen(y), 0) == -1)
		perror("send");

	if (send(sockfd, email, strlen(email), 0) == -1)
		perror("send");
*/
char h[100]="HELO ",hh[1000],aa[100]="MAIL FROM: ",ff[100],rc[100]="RCPT TO: ",rr[100],ok[100];

char *ptr;
strcpy(dm,from);
strtok_r(dm, "@",&ptr);
//printf("%s,%s\n",from,ptr);
char newline[100];
strcat(newline,"\n");

strcat(h,ptr);
strcat(aa,from);
strcat(rc,to);

if(strcmp(email,newline)!=0){
strcat(sub,email);}

bzero(newline,100);

printf("\n");
write(sockfd,h,sizeof(h));
write(sockfd,dm,sizeof(dm));
write(sockfd,ptr,sizeof(ptr));
read(sockfd,hh,sizeof(hh));
printf("%s",hh);

  //  printf("Current Time : %s\n", time_str);

//write(sockfd, time_str, sizeof(time_str));

write(sockfd,aa,sizeof(aa));
write(sockfd,from,cc-1);
read(sockfd,ff,sizeof(ff));
printf("%s\n",ff);
write(sockfd,rc,sizeof(rc));
write(sockfd,to,sizeof(to));
read(sockfd,rr,sizeof(rr));
printf("%s\n",rr);
write(sockfd,sub,sizeof(sub));
//printf("%s",email);
//write(sockfd,email,sizeof(email));
read(sockfd,ok,100);
printf("%s\n",ok);
write(sockfd,"QUIT",4);
z=0;
}



	if(n==1) {

	char user[100],pass[100],lin[300],li[100];
	while(1){
printf("USER:\n");

	scanf("%s",user);

printf("PASS:\n");
	scanf("%s",pass);

strcpy(lin,user);
strcpy(li,lin);
strcat(lin," ");
strcat(lin,pass);
strcat(lin,"\n");
strcat(li,"/MyMailBox.txt");

    FILE* file = fopen("User.txt", "r"); 
    char line[256];
	int res,cout=0;;

    while (fgets(line, sizeof(line), file)) {
	//printf("line %s",line);
	//printf("lin %s",lin);
	res=strcmp(line,lin);
	if(res == 0){cout=1;}
        
    }
if(cout == 0){printf("authentication not succesful\n");}
else if(cout==1){printf("authentication successful\n");break;}

    fclose(file);}
int MYPORT;

printf("PORT NUMBER:\n");
scanf("%d",&MYPORT);

		int sockfd, numbytes;
		char buf[MAXDATASIZE];
		struct hostent *he;
		struct sockaddr_in their_addr; /* client's address information */

		if (argc != 2)
		{
			fprintf(stderr,"usage: client hostname\n");
			exit(1);
		}

		if ((he=gethostbyname(argv[1])) == NULL)
		{
			herror("gethostbyname");
			exit(1);
		}

		/* get the host info */

		if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		{
			perror("socket");
			exit(1);
		}

		their_addr.sin_family = AF_INET;
		their_addr.sin_port = htons(MYPORT);
		their_addr.sin_addr = *((struct in_addr *)he->h_addr);
		bzero(&(their_addr.sin_zero), 8);
			
		if (connect(sockfd,(struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1)
		{
			perror("connect");
			exit(1);
		}

char ok[100];


read(sockfd,ok,sizeof(ok));
printf("%s\n",ok);
write(sockfd,li,sizeof(li));

while(1){
printf("\nlist of emails:\n\n");
char list[5000];

read(sockfd,list,sizeof(list));
printf("%s",list);
printf("\n");

int m,cout;

printf("1)STAT 2)LIST 3)RETR 4)DELE 5)QUIT\n");
scanf("%d",&m);

write(sockfd,&m,sizeof(m));

if(m==5){break;}

if(m==1){
read(sockfd,&cout,sizeof(cout));
printf("number of emails %d\n\n",cout);
}

if(m==2){char all[10000];
read(sockfd,all,sizeof(all));
printf("%s",all);
}

if(m==3){char ret[1000];
int f;
scanf("%d",&f);
write(sockfd,&f,sizeof(f));
read(sockfd,ret,sizeof(ret));
printf("\n%s",ret);
}
if(m==4){int f;
scanf("%d",&f);
write(sockfd,&f,sizeof(f));
printf("deleted\n");
}

	}
}

if(n==3){exit(0);}

}

return 0;
}
