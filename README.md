1. Project Introduction 
Typing Master in C++ is a console-based program designed to test and improve typing speed and 
accuracy. It applies Object-Oriented Programming (OOP) principles and file handling to manage 
user registration, login, and leaderboard functionality. The project helps users track their typing 
performance in an offline environment using a simple and efficient design. 

2. Problem Statement / Understanding the Problem 
Many users want to measure their typing speed and accuracy without relying on online tools. 
Existing tools require an internet connection and lack personal tracking. This project aims to 
build an offline C++ typing application that allows users to: 
 Register and log in 
 Take typing tests at different difficulty levels 
 Automatically calculate speed, accuracy, and time 
 Save results for future reference 

3. Design the Solution 
The solution is built using OOP concepts for modularity and reusability. 
 User Class: Handles registration and login using file handling. 
 Abstract Test Class: Defines structure and functions for tests. 
 Derived Classes (EasyTest, HardTest): Implement difficulty-specific test logic. 
 File Handling: Stores user and leaderboard data permanently. 

Flow of Control :  
User -> Signup/Login -> Choose Test Level -> Type Text -> 
Calculate Speed & Accuracy -> Display & Save Results

4. Pseudocode 
BEGIN 
DISPLAY main menu 
IF user selects SIGNUP THEN 
ASK username & password 
SAVE user in file 
ELSE IF user selects LOGIN THEN 
VERIFY credentials 
IF valid THEN 
SHOW typing test options 
IF Easy Test THEN 
DISPLAY easy text 
ELSE IF Hard Test THEN 
DISPLAY hard text 
ENDIF 
START timer 
TAKE user input 
STOP timer 
CALCULATE speed, accuracy, time 
SAVE in leaderboard 
ENDIF 
ENDIF 
END 

5. Develop Algorithm 
1. Start program 
2. Display menu (Signup, Login, View Leaderboard, Exit) 
3. If Signup selected → Save user credentials 
4. If Login selected → Validate user
5. If successful login → Display test menu 
6. Start typing test timer 
7. Take input → Stop timer 
8. Calculate: 
8. Speed = (characters / 5) / (time / 60) 
9. Accuracy = (correct characters / total characters) * 100 
10. Display and save results 
End program 

6. Flowchart Diagram
<img width="607" height="412" alt="image" src="https://github.com/user-attachments/assets/888feac2-266a-4b86-b7b6-e225361e4b47" />

7. Main Modules 
Module                                                                
User                                         
Test (Abstract)                        
EasyTest                                 
HardTest                                 
File Handling                         
Menu System                         
Description 
Manages signup, login, and file storage of users 
Base class defining test logic 
Implements easy-level test 
Implements hard-level test 
Reads/writes user and leaderboard data 
Handles navigation and input

9. OOP Concepts Used 
Concept                                                 
Class & Object                         
Usage 
Used for User, Test, Easy Test, and Hard Test 
Inheritance                               
Polymorphism                          
Encapsulation                           
Abstraction                               
Easy Test & Hard Test inherit from Test 
Virtual function start Test() overridden in derived classes 
Private data with getter/setter methods 
Test class hides test details

11. Conclusion 
The Typing Master in C++ project successfully demonstrates the power of OOP and file 
handling in developing practical console applications. It allows users to practice typing, analyze 
performance, and track progress. The modular, reusable, and efficient code design meets all 
academic and functional objectives for a C++ OOP project.

Author:
Mesum Mukhtar

GitHub: https://github.com/codewithMeesum 

Portfolio: https://codewithMeesum.github.io

⭐ Star this repo if you found it helpful!



## 🌐 Socials:
[![Instagram](https://img.shields.io/badge/Instagram-%23E4405F.svg?logo=Instagram&logoColor=white)](https://instagram.com/meesummukhtar) [![LinkedIn](https://img.shields.io/badge/LinkedIn-%230077B5.svg?logo=linkedin&logoColor=white)](www.linkedin.com/in/mesummukhtar) [![email](https://img.shields.io/badge/Email-D14836?logo=gmail&logoColor=white)](mailto:mesummukhtar47@gmail.com) 

# 💻 Tech Stack:
![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white) ![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)






