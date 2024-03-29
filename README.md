# FunAlg
## How to download and use this package:
1. Open R in a prefered way of your choice, an example would be R studio, or in jupyter lab.
   
2. If the package devtools in not already downloaded in R, first download it using:

   ```
   install.packages("devtools")
   ```

3. Load the devtools library using

   ```
   library(devtools)
   ```
4. Download the package directly from github
   ```
   devtools::install_github("KajalDodhia/FunAlg",force=TRUE)
   ```
   It should download this into the working directory of your R file.
5. Load the package
    ```
   library(FunAlg)
    ```
6. You can now use the stable_marriage function. It takes two preference tables in a data frame from and ouputs a stable matching. 

   
### How to download it by putting everything in repository into a folder (locally):

1. Download all the contents from the repository and store it in a folder named FunAlg.
2. Open R and make sure you are working in the directory where the folder is stored.
3. Do the same steps 2 and 3 from the previous set of instructions
4. Locally install the package by running:
```
install_local("FunAlg",force=TRUE)
```
5. Follow the same steps as previous set of instructions from line 5.

A step by step example of this is provided under the heading Task 4 in the jupyter file named "Question 3 and 4" via this link: [https://github.com/KajalDodhia/STOR601-Assessment-3-Q3-4/blob/main/Question%203%20and%204.ipynb].

Improvements to my ReadMe file:
To make it easier to follow these steps I have added the feature which I was trying to do in my last assignment but didn't realise the spaces I needed between the code and the acute marks. In this README file this can allow the code to be easily copied and pasted by the user.
