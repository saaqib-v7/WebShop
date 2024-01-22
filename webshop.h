#ifndef WEBSHOP_H
#define WEBSHOP_H

struct Product
{
    char* name;
    int price;
    int quantity;
};

struct Store
{
    struct Product* product;
    int number;
};

int LC(char* filename);
void WriteF(struct Store* cart, char* filename);
void Load(struct Store* webshop,char* filename);
void Inserter(struct Store* cart, struct Store* webshopStore, char* name, int quantity);
void Price(struct Store* cart);
void Bought(struct Store* cart, struct Store* webshopStore);
int Exit(struct Store* cart, struct Store* webshopStore);
void init(struct Store* cart);

#endif