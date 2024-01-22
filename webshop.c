#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "webshop.h"

int LC(char* filename)
{
    FILE* fptr = fopen(filename,"r");
    int lines = 0;
    char line[1000];
    while (fgets(line,1000,fptr) != NULL)
    {
        lines++;
    }
    return lines;
    fclose(fptr);
}

void WriteF(struct Store* cart, char* filename)
{
    FILE* file = fopen(filename,"w");
    if (file == NULL)
    {
        printf("File not found!");
    }
    else
    {
        for (int i = 0; i < cart->number; i++)
        {
            fprintf(file, "%s %d %d\n", cart->product[i].name, cart->product[i].price, cart->product[i].quantity);
        }
        printf("Content written to the file!\n");
    }
    fclose(file);
    
}

void Load(struct Store* webshop,char* filename)
{
    int lc = LC(filename);
    FILE* filer = fopen(filename,"r");

    if (filer == NULL)
    {
        printf("File not found!\n");
    }
    else
    {
        webshop->number = lc;
        webshop->product = (struct Product*)malloc(lc*sizeof(struct Product));
        for(int i = 0; i < lc; i++)
        {
            webshop->product[i].name = (char*)malloc(100 * sizeof(char));
            fscanf(filer,"%s %d %d", webshop->product[i].name, &(webshop->product[i].price), &(webshop->product[i].quantity));
        }
        printf("Loading done!\n");
    }
    fclose(filer);
    
    
}

void Inserter(struct Store* cart, struct Store* webshopStore, char* name, int quantity)
{ 
    int ind = 0;
    int oldQ;
    for (int i = 0; i < cart->number; i++)
    {
        if (strcmp(cart->product[i].name,name)==0)
        {
            oldQ = cart->product[i].quantity;
            cart->product[i].quantity += quantity;
            ind++;
            break;
        }
    }
    int index;
    if (ind == 0)
    {
        cart->product = realloc(cart->product, (cart->number + 1) * sizeof(struct Product));
        cart->number += 1;
        cart->product[cart->number-1].name = (char*)malloc((strlen(name) + 1) * sizeof(char));
        strcpy(cart->product[cart->number-1].name, name);
        for (int i = 0; i < webshopStore->number; i++)
        {
            if (strcmp(webshopStore->product[i].name, name) == 0)
            {
                index = i;
                break;
            }
        }
        if (quantity <= webshopStore->product[index].quantity)
        {
            cart->product[cart->number-1].quantity = quantity;
        }
        else
        {
            cart->product[cart->number-1].quantity = webshopStore->product[index].quantity;
        }
        cart->product[cart->number-1].price = webshopStore->product[index].price;
        webshopStore->product[index].quantity -= quantity;
    }
    else
    {
        webshopStore->product[index].quantity -= quantity + oldQ;
    }
    printf("Insertion done!\nNumber of items in the cart: %d\n",cart->number);
}

void Price(struct Store* cart)
{
    int sum = 0;
    for (int i = 0; i < cart->number; i++)
    {
        sum += cart->product[i].price * cart->product[i].quantity;
    }
    printf("The price of the cart is: %d\n",sum);
}

void Bought(struct Store* cart, struct Store* webshopStore)
{
    for (int i = 0; i < cart->number; i++)
    {
        for (int j = 0; j < webshopStore->number; j++)
        {
            if (strcmp(cart->product[i].name, webshopStore->product[j].name)==0)
            {
                webshopStore->product[j].quantity -= cart->product[i].quantity;
                if (webshopStore->product[j].quantity < 0)
                {
                    webshopStore->number--;
                    printf("%d %s are missing\n", (cart->product[i].quantity+webshopStore->product[j].quantity)*(-1), cart->product[i].name);
                    webshopStore->product[j].quantity = 0;
                }
            }
        }
    }
    printf("Purchased!\n");
}

int Exit(struct Store* cart, struct Store* webshopStore)
{
    for (int i = 0; i < webshopStore->number; i++)
    {
        free(webshopStore->product[i].name);
    }
    free(webshopStore->product);
    webshopStore->number = 0;
    for (int i = 0; i < cart->number; i++)
    {
        free(cart->product[i].name);
    }
    free(cart->product);
    cart->number = 0;
    printf("THANK YOU FOR SHOPPING! GOODBYE!\n");
    return 0;
}

void init(struct Store* cart)
{
    cart->product = (struct Product*)malloc(0*sizeof(struct Product));
    cart->number = 0;
}
