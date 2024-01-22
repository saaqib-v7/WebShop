# WebShop
Webshop Project Description

This project is a simplified grocery webshop implementation with various features. The primary components of the project include a webshop store, a shopping cart, and functionalities to manipulate these structures. The main menu is displayed to the user until they choose to exit, offering the following options:

Load Webshop Store from File:
Reads the content of the store from a text file, where each line represents a product with its name, price, and quantity.
The filename is provided by the user through keyboard input.

Write Store Content to File:
Takes a filename from the user and writes the content of the store to that file, using a specified format (product name, price, quantity).

Insert Item to Cart:
Allows users to add items to the cart by entering the product name and quantity via keyboard input.
The price of the product is fetched from the store.

Get Cart Price:
Prints the sum of the prices of products in the cart.

Buy Products:
Subtracts the content of the cart from the store.
Displays an error message if a certain quantity of a product is not available in the store.

Exit the Program:
Terminates the program execution.

Implementation Details:
The program utilizes a structure to represent products, containing information such as name, price, and quantity.
Two instances of this structure are created: one for the webshop store and the other for the cart.
Both the store and the cart content are stored in dynamic arrays on the heap memory.
The program continuously displays a menu, and users can perform operations until they choose to exit.
Operations are implemented as separate functions, enhancing code modularity and readability.
The program is divided into multiple translation units. The main unit manages program control, while others contain the implemented types and their corresponding operations.
To handle array overflow, the program dynamically allocates a larger array and removes the previous one when needed.
This project showcases practical skills in C programming, file I/O, dynamic memory allocation, and modular code design. The separation of concerns and the implementation of core functionalities make it a comprehensive example of a simple webshop application.





