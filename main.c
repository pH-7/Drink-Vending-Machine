/**
 * Example of an algorithm for a drink vending.
 *
 * Licensed under The MIT License
 * Redistributions of files must retain the above copyright notice.
 *
 * @author      SORIA Pierre-Henry
 * @email       pierrehs@hotmail.com
 * @link        http://github.com/pH-7
 * @license     MIT License (http://www.opensource.org/licenses/mit-license.php)
 */

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(void) {
    int status = 0; // False
    char q[4] = "quit";
    char* currency = "$";
    char i;
    int bill = 0, to_pay = 0, price = 0, rendering = 0; // Default Price

    do {
        printf("----- Vending Machine -----\n");
        printf("Choose and confirm, please...\n");
        printf(" - Coke (Cola) (Coca-Cola ®) -  <A>\n");
        printf(" - Diet Coke (Cola) (Coca-Cola ®) -  <B>\n");
        printf(" - Pepsi® (Cola) -  <C>\n");
        printf(" - Pepsi Max® (Cola) -  <D>\n");
        printf(" - Red Bull® Energy -  <E>\n");
        printf(" - Monster (Energy Drink®) -  <F>\n");
        printf(" - Beer -  <G>\n");
        printf(" - Orange Juice -  <H>\n");
        printf(" - Milk -  <I>\n");
        printf(" - Water -  <J>\n");

        i = scanf("%c", &i);
        i = tolower(i); // Case-insensitive

        price = get_price(i);

        printf("\nPlease pay: %s%i\n", currency, price);
        scanf("%i", &bill);

        if (bill == price) status = 1;

        while (status != 1) {

            if (i == NULL) {
                printf("\nPlease take your drink!\n");
            }

            if (bill < price) {
                to_pay = (price - bill);
                printf("\nYou must still pay: %s %f", currency, to_pay);
            }

            if (bill > price) {
                status = 1;
                rendering = (bill - price);
                printf("\nRendering: %s %f0\n", currency, rendering);
            }
        }

        if (status == 1) {
            printf("\nThank you\n");
            printf("See you soon!\n");
        }


        system("pause");
    } while(i != q);

    printf("----- End of program -----\n");

    //system("pause");

    return 0;
}

int get_price(char input) {
    int amount;

    switch (input) {
            // Price List
        case 'a':
            amount = 1;
            break;

        case 'b':
            amount = 2;
            break;

        case 'c':
            amount = 2;
            break;

        case 'd':
            amount = 2;
            break;

        case 'e':
            amount = 1;
            break;

        case 'f':
            amount = 1;
            break;

        case 'g':
            amount = 2;
            break;

        case 'h':
            amount = 2;
            break;

        case 'i':
            amount = 1;
            break;

        case 'j':
            amount = 1;
            break;

        default:
            amount = 0;
    }

    return amount;
}
