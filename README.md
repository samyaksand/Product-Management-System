# Product-Management-System

## Introduction
The program is a management tool to access and modify data. It maintains data of food stock and allows the user to access and modify the details and manipulates data according to the option chosen by the user. It stores all of this data in a binary file.

The program allows the user to add Food stock details, update a food stock detail, display a specific food stock detail by product code, display the entire food stock information and delete the database.

The program also calculates the price the customer has to pay according to the quantity ordered.

## Functions used

      1. main() - This function is the heart of the program. It contains the main menu which leads to all other functions.
      2. enterdata() - This function gets input from the user for the various details.
      3. putdata() - This function displays the product information.
      4. calculate() - This function calculates the price depending upon the quantity ordered and makes the necessary change to the product stock.
      5. locatedata() -This function returns the pcode as the datamembers are private.
      6. add() - This function adds Product items to the existing information.
      7. update() - This function updates an existing product item details by the pcode given by the user.
      8. order() - This function takes the pcode of the product which is to be ordered and calls the calculate() function.
      9. pdisplay() - This function displays specific product details.
      10. display() - This function displays all the product’s details.
      11. del() - This function deletes the entire product.

## Output

<img width="326" alt="output1" src="https://user-images.githubusercontent.com/62803746/158943067-07eec1b5-e523-476a-ba7d-8b1484c36e20.PNG">

<img width="324" alt="output 3" src="https://user-images.githubusercontent.com/62803746/158943018-3b93da58-d247-43a3-a326-ae813742d671.PNG">

<img width="328" alt="output2" src="https://user-images.githubusercontent.com/62803746/158943045-c8a42ff8-a3ac-4f14-bb04-fdc1eca95a68.PNG">


## Challenges I ran into

- [x] When calculating the discount rate, it was zero. This was fixed by assigning the discount rate as a float type.
- [x] The member functions could not be accessed. This was because they were declared private.This was fixed by the function locatedata() which returns pcode.
- [x] After taking the input for ptype, the program went into a loop. The error was that the ptype had only 1 char size assigned. This was fixed by increasing the char size.

## Future Modifications

* More options can be offered to the user.
* It can be password protected. It will ask for user credentials before granting them access.
* To give it a better user interface for the application.
* To implement graphics in the program to make it user-friendly so that he/she can interpret the data easily.
