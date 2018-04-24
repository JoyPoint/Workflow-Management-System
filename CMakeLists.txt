cmake_minimum_required(VERSION 3.10)

project(WMS)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)
add_executable(WMS Code/Captcha.cpp 
		   Code/Captcha.h 
                   Code/Leave.cpp
                   Code/Leave.h 
		   Code/Finance.cpp 
		   Code/Finance.h 
                   Code/User.cpp 
                   Code/User.h
       		   Code/Student.cpp 
		   Code/Student.h 
                   Code/Undergrads.cpp 
                   Code/Undergrads.h
        	   Code/Research_scholar.cpp 
		   Code/Research_scholar.h 
		   Code/Employee.cpp
        	   Code/Employee.h 
		   Code/Faculty.cpp 
		   Code/Faculty.h 
		   Code/Hod.cpp
       		   Code/Hod.h 
		   Code/Director.cpp 
		   Code/Director.h
       		   Code/Administrator.cpp 
		   Code/Administrator.h
    	           Code/Database.cpp 
		   Code/Database.h 
	           Code/Supplementary.cpp
 		   Code/Supplementary.h
	           Code/Utility_class.cpp 
		   Code/Utility_class.h 
		   Code/File.cpp 
		   Code/File.h 
		   Code/main.cpp)
