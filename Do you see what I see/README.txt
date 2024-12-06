Ashly Galvan Perez

CPSC 350
PA3: Do You See What I See?

Files:
- MonoStack.h
- SpeakerView.h
- main.cpp
- input.txt
- README.txt

Code Limitations:
- I tried implementing continue and break when trying to skip the lines for BEGIN and END
but for some reason it wouldn't let me so in the end I decided to implemnt the isdigit()
to ignore the alphabet since isalpha() also wasn't working with stod(). Also I tried to set precision to 2, but 
since height got converted to a string it wasn't able to.

References:
- https://www.geeksforgeeks.org/introduction-to-monotonic-stack-2/
- https://www.tutorialspoint.com/isalpha-and-isdigit-in-c-cplusplus
- https://www.geeksforgeeks.org/stdstod-stdstof-stdstold-c/
- https://stackoverflow.com/questions/21182791/isalpha-function-returns-false-for-character-in-string
- https://www.geeksforgeeks.org/read-a-file-line-by-line-in-cpp/
- https://stackoverflow.com/questions/48673601/i-cant-get-the-set-precision-to-work-in-c
- ChatGPT

Instructions:
compile: g++ -o test main.cpp
run: ./test
when prompted: input.txt

