#include <stdio.h>
#include <string.h>

// Structure to represent an item in the store
struct Item {
    char name[50];
    float price;
    int quantity;
};

// Function to print the final bill
void printBill(struct Item items[], int itemCount, float discountPercent) {
    float total = 0, discountedTotal = 0, discountAmount = 0;
    
    printf("\n\n--- Final Bill ---\n");
    printf("No.\tItem Name\tQuantity\tPrice\t\tTotal\n");
    printf("--------------------------------------------------------\n");
    
    for (int i = 0; i < itemCount; i++) {
        float itemTotal = items[i].price * items[i].quantity;
        printf("%d\t%s\t\t%d\t\t%.2f\t\t%.2f\n", i + 1, items[i].name, items[i].quantity, items[i].price, itemTotal);
        total += itemTotal;
    }
    
    if (discountPercent > 0) {
        discountAmount = (discountPercent / 100) * total;
    }
    
    discountedTotal = total - discountAmount;
    
    printf("--------------------------------------------------------\n");
    printf("Subtotal: %.2f\n", total);
    if (discountPercent > 0) {
        printf("Discount (%.2f%%): -%.2f\n", discountPercent, discountAmount);
    }
    printf("Total Payable: %.2f\n", discountedTotal);
    printf("--------------------------------------------------------\n");
}

// Main function to handle billing
int main() {
    struct Item items[100];
    int itemCount = 0, option, quantity;
    char itemName[50];
    float price, discountPercent = 0;
    
    printf("Welcome to the Billing System\n");
    
    while (1) {
        printf("\n1. Add item\n2. Generate Bill\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                // Add an item
                printf("Enter item name: ");
                scanf("%s", itemName);
                printf("Enter item price: ");
                scanf("%f", &price);
                printf("Enter item quantity: ");
                scanf("%d", &quantity);
                
                strcpy(items[itemCount].name, itemName);
                items[itemCount].price = price;
                items[itemCount].quantity = quantity;
                itemCount++;
                
                printf("Item added successfully!\n");
                break;
            
            case 2:
                // Generate bill
                if (itemCount == 0) {
                    printf("No items added yet!\n");
                    break;
                }
                
                printf("Enter discount percentage (if any): ");
                scanf("%f", &discountPercent);
                
                printBill(items, itemCount, discountPercent);
                break;
            
            case 3:
                // Exit the program
                printf("Exiting the billing system. Thank you!\n");
                return 0;
            
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    
    return 0;
}
