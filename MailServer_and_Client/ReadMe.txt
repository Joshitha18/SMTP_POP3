1) compile Client.c

   gcc Client.c

2) run Client.c

   ./a.out (hostname)

   example: ./a.out debian

3) For Manage Mail,

	compile POP3Server.c
	gcc POP3Server.c
	
	run POP3Server.c
	./a.out POP3Server.c (portnumber)
	example, ./a.out POP3Server.c 1122

	Enter '1' in Client.c
	Enter Username,Password and Port number

	Enter '1' or '2' or '3' or '4' or '5' for stat, list, retr, dele, quit respectevely.

	For RETR and DELE, enter S.No of email you want to retrieve or delete.

4) For Send Mail,
	
	compile SMTPServer.c
	gcc SMTPServer.c

	run SMTPServer.c
	./a.out SMTPServer.c (port number)
	example, ./a.out SMTPServer.c 1112

	Enter '2' in Client.c
	Enter from, to, subject, email (ending with '.' in new line) and port number

5) Enter '3' to Quit.

















//Client.c//


sysad@sysad-XPS-13-9380:~/Desktop/180020009$ gcc Client.c 
Client.c: In function ‘main’:
Client.c:192:1: warning: implicit declaration of function ‘write’; did you mean ‘fwrite’? [-Wimplicit-function-declaration]
 write(sockfd,h,sizeof(h));
 ^~~~~
 fwrite
Client.c:195:1: warning: implicit declaration of function ‘read’; did you mean ‘fread’? [-Wimplicit-function-declaration]
 read(sockfd,hh,sizeof(hh));
 ^~~~
 fread
sysad@sysad-XPS-13-9380:~/Desktop/180020009$ ./a.out sysad-XPS-13-9380
Select 1)Manage Mail 2)Send Mail 3)Quit
2
FROM:
j@l
TO:
j@w
SUBJECT:
mail1
EMAIL: 
.
PORT NUMBER:
4211

250 OK Hello l
250 j@l... Sender ok
250 root... Recipient ok
OK Message accepted for delivery
Select 1)Manage Mail 2)Send Mail 3)Quit
2
FROM:
j@e
TO:
j@w
SUBJECT:
mail2
EMAIL: 
.
PORT NUMBER:
4111

250 OK Hello e
250 j@e
... Sender ok
250 root... Recipient ok
OK Message accepted for delivery
Select 1)Manage Mail 2)Send Mail 3)Quit
1
USER:
j
PASS:
j
authentication successful
PORT NUMBER:
4114
+OK POP3 Server ready.

list of emails:

1 From: j@l
Time: Tue Mar 10 02:00:49 2020
SUBJECT: mail1
2 From: j@e
Time: Tue Mar 10 02:01:13 2020
SUBJECT: mail2

1)STAT 2)LIST 3)RETR 4)DELE 5)QUIT
4
1
deleted

list of emails:

1 From: j@e
Time: Tue Mar 10 02:01:13 2020
SUBJECT: mail2

1)STAT 2)LIST 3)RETR 4)DELE 5)QUIT
2

From: j@e
Time: Tue Mar 10 02:01:13 2020
SUBJECT: mail2
.


list of emails:

1 From: j@e
Time: Tue Mar 10 02:01:13 2020
SUBJECT: mail2

1)STAT 2)LIST 3)RETR 4)DELE 5)QUIT
5


















//SMTPServer.c//



sysad@sysad-XPS-13-9380:~/Desktop/180020009$ gcc SMTPServer.c
SMTPServer.c:16:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(int argc,char*argv[])
 ^~~~
SMTPServer.c: In function ‘main’:
SMTPServer.c:62:1: warning: implicit declaration of function ‘inet_ntoa’ [-Wimplicit-function-declaration]
 inet_ntoa(their_addr.sin_addr));
 ^~~~~~~~~
SMTPServer.c:98:1: warning: implicit declaration of function ‘read’; did you mean ‘fread’? [-Wimplicit-function-declaration]
 read(new_fd,h,sizeof(h));
 ^~~~
 fread
SMTPServer.c:103:1: warning: implicit declaration of function ‘write’; did you mean ‘fwrite’? [-Wimplicit-function-declaration]
 write(new_fd,hh,sizeof(hh));
 ^~~~~
 fwrite
SMTPServer.c:154:1: warning: implicit declaration of function ‘close’; did you mean ‘pclose’? [-Wimplicit-function-declaration]
 close(new_fd);
 ^~~~~
 pclose
sysad@sysad-XPS-13-9380:~/Desktop/180020009$ ./a.out 1119
server: got connection from -947506032

HELO iit
MAIL FROM: joshitha@iit
RCPT TO: joshi@iit
data joshi
iit
QUIT

















//POP3Server,c//

sysad@sysad-XPS-13-9380:~/Desktop/180020009$ gcc POP3Server.c
POP3Server.c:15:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(int argc,char*argv[])
 ^~~~
POP3Server.c: In function ‘main’:
POP3Server.c:61:1: warning: implicit declaration of function ‘inet_ntoa’ [-Wimplicit-function-declaration]
 inet_ntoa(their_addr.sin_addr));
 ^~~~~~~~~
POP3Server.c:69:1: warning: implicit declaration of function ‘write’; did you mean ‘fwrite’? [-Wimplicit-function-declaration]
 write(new_fd,"+OK POP3 Server ready.",100);
 ^~~~~
 fwrite
POP3Server.c:71:1: warning: implicit declaration of function ‘read’; did you mean ‘fread’? [-Wimplicit-function-declaration]
 read(new_fd,li,sizeof(li));
 ^~~~
 fread
POP3Server.c:201:1: warning: implicit declaration of function ‘close’; did you mean ‘pclose’? [-Wimplicit-function-declaration]
 close(new_fd);
 ^~~~~
 pclose
sysad@sysad-XPS-13-9380:~/Desktop/180020009$ ./a.out 1117
server: got connection from 989975696

