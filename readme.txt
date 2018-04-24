========================================================= Workflow Management System ================================================================



************************************************************* System Requirements ******************************************************************* 

To run this code just type cmake CMakeLists.txt make in the terminal.



*************************************************************** Introduction ************************************************************************

This software manages the workflow in an Academic Institute. It allows the users(non-administrative) to apply for leaves. The students of the 
institute can apply for financial assistance based on their family income. These applications are then processed and approved following a certain
hierarchy. Further, it allows the users to keep track of their applications.


 
********************************************************* Instruction for Basic use *****************************************************************

1) The non-administrative users must register themselves into the database before they can use the system.

2) As a part of the registration process, the users will be directed for captcha verifcation.

3) The director and administrator are created by default. The director may register himself using the default id to set his name and password.

4) The following hierarchy is assumed for leave and financial assistance approval.
   • An undergraduate’s leave request is processed directly by the Administrator .i.e. Undergrads --> Administrator.
   • A research scholar’s leave request is processed by his faculty advisor before it is sent to the office of academics for its approval.
    .i.e. Research Scholar --> Faculty (Supervisor) --> Administrator.
   • A faculty’s leave request is processed following the hierarchy below: Faculty --> Head of the Department --> Director --> Administrator.
   • A H.O.D’s request is processed through the Director before it is sent to the Administrator for implementation.
    .i.e. Head of a Department --> Director --> Administrator.
   • The Director may directly send his leave application to the Administrator for implementation.
   • The Students (Undergraduates and Research scholars) may apply for financial assistance.
   • Their applications are processed following the same hierarchy as described above.

5) A user may approve the leave and financial applications of the others below him in the hierarchy chain.

6) In case the user types the password wrong thrice, he may quit or register himself again with a different id.



*************************************************************** Development Team *********************************************************************

Group 5
Chitraksh Sadayat (B16CS007)
Vishakh.S (B16CS038)
