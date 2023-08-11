#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
};

struct Product products[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount < MAX_PRODUCTS) {
        struct Product newProduct;
        newProduct.id = productCount + 1;

        printf("Enter product name: ");
        scanf("%s", newProduct.name);

        printf("Enter product price: ");
        scanf("%f", &newProduct.price);

        printf("Enter initial quantity: ");
        scanf("%d", &newProduct.quantity);

        products[productCount] = newProduct;
        productCount++;

        printf("Product added successfully.\n");
    } else {
        printf("Maximum product limit reached.\n");
    }
}

void performSale() {
    int productId, quantity;
    printf("Enter product ID: ");
    scanf("%d", &productId);

    if (productId <= 0 || productId > productCount) {
        printf("Invalid product ID.\n");
        return;
    }

    printf("Enter quantity sold: ");
    scanf("%d", &quantity);

    if (products[productId - 1].quantity >= quantity) {
        products[productId - 1].quantity -= quantity;
        printf("Sale completed successfully.\n");
    } else {
        printf("Insufficient stock.\n");
    }
}

void viewProducts() {
    printf("Product List:\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%-15s%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
}

int main() {
    int choice;

    do {
        printf("Supermarket Inventory Management System\n");
        printf("1. Add Product\n");
        printf("2. Perform Sale\n");
        printf("3. View Products\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                performSale();
                break;
            case 3:
                viewProducts();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
