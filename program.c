
#include <stdio.h>

int getDiscountedPrice(int subTotal);
int addToCart(char item[], int qty, int price);
int countSubTotal();
void getSingleOrder();
void printBill();

#define MAX_PRODUCTS 5

static int IN_CART = 0; 
static char CART_ITEMS[5][256];
static int CART_ITEM_QTY[5];
static int CART_ITEM_PRICE[5];

int main(){    
    int choice;
    do{
        printf("\n\n-------------------------------------------");
        printf("\n\tCart [%d] | Sub Total [%d]", IN_CART,countSubTotal());
        printf("\n-------------------------------------------");
        if(IN_CART == MAX_PRODUCTS)
            printf("\n[1] Add Product (Can't add more products!)");
        else
            printf("\n[1] Add Product");        
        printf("\n[2] Checkout/Print Bill");
        printf("\n[0] Exit");
        printf("\nI want to ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                getSingleOrder();
            break;
            case 2:
                printBill();
            break;
            default:
                continue;
            break;
        }
    }while(choice != 0);  

    return 0;
}

//Get Single Order
void getSingleOrder(){   
    if(IN_CART == MAX_PRODUCTS){
        printf("\n\n #### Warning: Product limit riched! Please proceed to checkout/Print Bill! \n\n");
        return;
    }
        
    int qty = 1;
    int price = 0;
    printf("\nEnter Product Name:");
    //Added below exp(%[^\n]) for accepting space
    scanf(" %[^\n]", CART_ITEMS[IN_CART]);
    printf("Product QTY: ");
    scanf("%d", &qty);
    printf("Product Price: ");
    scanf("%d", &price);
    addToCart(CART_ITEMS[IN_CART], qty, price);
}

//Add product to cart
int addToCart(char item[], int qty, int price){
    CART_ITEM_QTY[IN_CART] = qty;
    CART_ITEM_PRICE[IN_CART] = price;
    IN_CART = IN_CART + 1;
    printf("* %s added successfully! *",item);
    return 0;
}

int countSubTotal(){
    int SUB_TOTAL = 0;
    for(int i = 0; i < IN_CART; i++){
        SUB_TOTAL =  SUB_TOTAL + (CART_ITEM_QTY[i] * CART_ITEM_PRICE[i]);
    }
    return SUB_TOTAL;
}

// Will return total discount in numbers
int getDiscountedPrice(int subTotal){
    if(subTotal>=1000 && subTotal<=2500)
        return (5 * subTotal)/100;         
    else if (subTotal>2500 && subTotal<=5000)
        return (10 * subTotal)/100;  
    else if (subTotal>5000 && subTotal<=10000)
        return (15 * subTotal)/100;  
    else if (subTotal>10000)
        return (20 * subTotal)/100;  
    else
        return 0;
}

//Get discount Number
int getDiscount(int subTotal){
    if(subTotal>=1000 && subTotal<=2500)
        return 5;         
    else if (subTotal>2500 && subTotal<=5000)
        return 10;  
    else if (subTotal>5000 && subTotal<=10000)
        return 15; 
    else if (subTotal>10000)
        return 20;  
    else
        return 0;
}

//Print Detailed Bill
void printBill(){
    printf("\n*-------------+----------+-----------+------------*");
    printf("\n| ## 1 Invoice                                    |");
    printf("\n|-------------+----------+-----------+------------|");
    printf("\n|     Item    | Quantity |   Price   |   Subtotal |");  
    for(int i = 0; i < IN_CART; i++){
        printf("\n|-------------+----------+-----------+------------|");
        printf("\n| %s       |    %d    |     %d    |     %d   |",CART_ITEMS[i], CART_ITEM_QTY[i], CART_ITEM_PRICE[i], (CART_ITEM_QTY[i] * CART_ITEM_PRICE[i]));       
    }
    int subTotal = countSubTotal();
    int discountPrice = getDiscountedPrice(subTotal);
    int grandTotal = subTotal - discountPrice;
    printf("\n|-------------+----------+-----------+------------|");
    printf("\n| Sub Total   |                      |     %d   |", subTotal);
    printf("\n|-------------+----------+-----------+------------|");
    printf("\n|             | Discount |     %d %s   |     -%d   |",getDiscount(subTotal),  "%", discountPrice);
    printf("\n|-------------+----------+-----------+------------|");
    printf("\n| Grand Total |                      |     %d   |", grandTotal);
    printf("\n|-------------+----------+-----------+------------|");
    printf("\n|                        -Thanks For Shoping :)   |");
    printf("\n*-------------+----------------------+------------*\n\n");
}





