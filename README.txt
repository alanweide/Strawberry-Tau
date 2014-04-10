Strawberry-Tau README
About:
This .zip file contains all the source and header files for the Strawberry Tau project.  All of these files are in C++ and can be compiled using the C++ compiler of your choice.
Execution:
Once the executable is run, the console will prompt you to enter a valid instruction.  Enter a valid instruction for the instruction set below.
Instruction Set:
ALU operations
add reg# reg# reg#
addi reg# reg# long
sub reg# reg# reg#
subi reg# reg# long
div reg# reg# reg#
divi reg# reg# long
mul reg# reg# reg#
muli reg# reg# long

FPU operations
fadd freg# freg# freg#
faddi freg# freg# double
fsub freg# freg# freg#
fsubi freg# freg# double
fdiv freg# freg# freg#
fdivi freg# freg# double
fmul freg# freg# freg#
fmuli freg# freg# double
sqrt freg# freg#
sin freg# freg#
exp freg# freg#

MEM operations
ld reg# reg#
st reg# reg#
fld freg# freg#
fst freg# reg#

Notes:
reg# - these are the registers that hold the integer values. '#' can be replaced with an integer between 0-15 
freg# - these are the registers that hold the floating point values. '#' can be replaced with an integer between 0-15 

After a valid instruction is entered, the computer will execute the instruction and then print the current state of all of the registers and fregisters to the console.  The program will then prompt for another instruction to be entered.  Once you are done using the program, enter "endprogram" when prompted for an instruction and the computer will end execution.