#README
##Server-Client Extended Chat

This code works on Linux

Open two terminals. Compile in one .cpps of "Server" file and in the other .cpp of "Client" file.
First, run the exe for the server with any port number that is accesable (for example 8080).
After, run the exe for a client with an IP address (as I work on the same computer, I use localHost 127.0.0.1) and port number (definitely the same as you gave to server).

When everything is done well, you will see blinking cursor waiting fo your request.
You are enabled to create an employee, delete an employee or see the list of created employees.

Here is the available commands list
***
CREATE EMPLOYEE { [name], [department], [salary] }
LIST EMPLOYEE { * }
LIST EMPLOYEE { DEPARTMENT = [dep] }
DELETE EMPLOYEE { ID = [id] }
***
Don't forget to put a space after every statement

NOTE!
As the program is under development you are allowed to cin only a word in the fields of [name] and [department].

Enjoy the experience! 

