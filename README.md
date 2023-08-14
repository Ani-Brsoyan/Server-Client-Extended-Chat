# README
## Server-Client Extended Chat

This code works on Linux

Open two terminals. Compile in one .cpps of the "Server" file and in the other .cpp of the "Client" file.
First, run the exe for the server with any port number that is accessible (for example 8080).
After, run the exe for a client with an IP address (as I work on the same computer, I use localHost 127.0.0.1) and port number (definitely the same as you gave to the server).

When everything is done well, you will see a blinking cursor waiting for your request.
You are enabled to create an employee, delete an employee, or see the list of created employees.

Here is the list of the available commands
***
CREATE EMPLOYEE { [name], [department], [salary] } <br />
LIST EMPLOYEE { * } <br />
LIST EMPLOYEE { DEPARTMENT = [dep] } <br />
DELETE EMPLOYEE { ID = [id] } 
***
Don't forget to put a space after every statement.
Type "exit" if you want to end the session.

NOTE!
As the program is under development you are allowed to cin only a word in the fields of [name] and [department].

Enjoy the experience! 

