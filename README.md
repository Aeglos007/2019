# Lexical Analyzer and Interpreter 2020
1) 

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.001.jpeg)

First, we define the variables we use. We have defined the variable list and file as address. We calculated the length of the character string using strlen in the isVariable function and provided the condition that the character length should not be greater than 20. We have provided a control according to the characters in it. 

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.002.jpeg)

In the parse function, we opened the file with w+ and created a text file for reading and writing. The character "." We provided and assigned reading until it happened. We then provided the bottom line and reading until there was a space. 

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.003.jpeg)

We detected the words “int, move, add, sub, out, loop” with if commands and printed them as keywords in our file. Then we assigned it to the list we prepared according to the variable type and increased the number of characters in the list. 

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.004.jpeg)We printed the result, which we provided with the control of the “.” character, to the file as the end of line and checked for errors. 

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.005.jpeg)

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.006.jpeg)

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.007.png)

Using the switch-case command, we printed whether case1 is an integer or not. We print whether it is Variable or not. We compared the character in the file with the character we wrote with the strcmp function. When it is the same, we assign it to the list. Then we did the line break check again. 

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.008.jpeg)

In Case2, we determine whether it is an integer or a variable. And we print to file. We compare it with strcmp, assign it to the list and increase the value. 

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.009.jpeg)

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.010.png)

We do error checks and print it as a keyword when "to". If the To assignment is not made, we provide this control and print it. Then we do the line break check again. 

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.011.jpeg)

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.012.jpeg)

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.013.png)

In Case3, we used the atoi function differently. This function first skips spaces until it finds the first character that does not contain a space character. It then converts characters similar to int value content to numeric values, starting with that character. Then we did the same operations again. 

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.014.jpeg)

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.015.png)

In Case4, we checked and printed whether it was an integer variable or a string. Then we printed it by making error checks. 

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.016.jpeg)

We did similar operations in Case5 and used the atoi function again. 

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.017.png)

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.018.jpeg)

We controlled it with strcmp and controlled the times keyword. We returned the newCode array that we defined with the strcat function. We returned the converted number with the parse method and removed the spaces in the loop. We finished by doing the line break checks. 

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.019.png)

With the isKeyword function, we provided the control of the words “int, move, to, add, sub, from, loop, times, out” with strcmp. 

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.020.png)

With the isInteger function, we provided the assignment with the values in the file using strlen and checked for the error of the "-" sign. 

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.021.png)

With this function, we compared the variable values in the list with those in the file. It returns true or false because it is a bool function. 

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.022.jpeg)

We created the control of the comment line with the isComment function. We calculated the length with strlen and created a loop and determined whether there is a comment line in this loop. We assigned it to the new variable with Substring and created a copy. We've made sure it's not overwritten in our new file. 

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.023.jpeg)

The substring function we created opens the new file we created and checks it by taking the rest of the word. 

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.024.jpeg)

In our main function, we first define the current file and open the binary file for reading with rb. We print the error messages to our new file with pererror. The Fseek function specifies the location for the reminder. Returns the active file location of the stream indicated by the stream parameter with the ftell function. With the Rewind function, it takes the active file location of the stream indicated by the Stream parameter to the top. We used calloc function for dynamic memory usage and control file closure. Then we performed the operations and closed the file. 

2) 

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.025.jpeg)

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.026.jpeg)

3) 

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.027.jpeg)

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.028.jpeg)

We determine the operation we will perform by navigating as an index. then we assign the value of the process and print it to the file. 

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.029.jpeg)


![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.030.jpeg)

After the add keyword detection, we determine the value to be added and the added value. We find the parameters with the loop and add them to the high school. Then the other value is determined and added on. 

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.031.jpegg)

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.032.jpeg)

we find out which value we will do the operation we will do by looping around Then we find the subtracted number. We perform the extraction process and print it to the screen and to the nature. 

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.033.jpeg)

The loops go through all the indexes and then detect the operation to be done and perform the operation. 

Operations are performed sequentially. index is assigned to value. prints to the screen and to the file. 

A period must be placed at the end of each line in the input. Otherwise this is detected as an error. 

When the loop keyword is detected, a single operation in square brackets can be detected. otherwise the code does not continue to run. 

4) 

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.034.jpeg)

![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.035.jpeg)


![](https://github.com/Aeglos007/proje2020/blob/main/images/Aspose.Words.b74e66cf-18f3-44a1-b641-866a926645ae.036.jpeg)
