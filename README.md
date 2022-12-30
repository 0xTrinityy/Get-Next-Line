In Get_Next_line, a 42 school project, we have to make a programm that can return lines from a file.

The programm have to work no matter the buffer Size used. By default, the programm run with a Buffer_Size equal 42 (defined in .h file).
The main purpose of GNL is to discover the notion of 'Static variable.

My programm can be easily explained, using 3 steps :
  - Getting characters in a Buffer
  - Read characters until we found a '\n' (line return), and return it.
  - Checking if there is some characters left in the buffer, and keeping them if so, for the next line.
