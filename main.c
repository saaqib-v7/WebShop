#include <stdio.h>
#include "webshop.h"

int main()
{
    int choice;
    struct Store webshopStore;
    struct Store cart;
    init(&cart);
    do
    {
        printf("1. Load webshop store from a file\n2. Write the content of the store to a file\n3. Insert an item to cart\n4. Get the price of cart\n5. Buy the products\n6. Exit the program\nChoose a number between 1-6\n");
        scanf("%d",&choice);
        if (choice == 1)
        {
            printf("Give the name of the textfile: ");
            char filename[100];
            scanf("%s",filename);
            Load(&webshopStore, filename);
        }
        else if (choice == 2)
        {
            printf("Give the name of the textfile: ");
            char filename[100];
            scanf("%s",filename);
            WriteF(&webshopStore, filename);
        }
        else if (choice == 3)
        {
            printf("Give the name of the product: ");
            char name[100];
            scanf("%s",name);
            printf("\nGive the quantity of the item: ");
            int quantity;
            scanf("%d",&quantity);
            Inserter(&cart, &webshopStore, name, quantity);
        }
        else if (choice == 4)
        {
            Price(&cart);
        }
        else if (choice == 5)
        {
            Bought(&cart, &webshopStore);
        }
        else if (choice == 6)
        {
            Exit(&cart, &webshopStore);
        }
    } while(choice != 6);

    return 0;
}