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
    char i = NULL;
    float bill = 0.0, to_pay = 0.0, price = 0.0, rendering = 0.0; // Default Price

    while (i != q) {
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

        printf("\nPlease pay: %s %f\n", currency, price);
        scanf("%lf", &bill);

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
    }

    printf("----- End of program -----\n");

    //system("pause");

    return 0;
}

float get_price(char input) {
	float price;

    switch (input) {
            // Price List
        case 'a':
            price = 1.4;
            break;

        case 'b':
            price = 1.4;
            break;

        case 'c':
            price = 1.2;
            break;

        case 'd':
            price = 1.2;
            break;

        case 'e':
            price = 1.5;
            break;

        case 'f':
            price = 1.6;
            break;

        case 'g':
            price = 1.4;
            break;

        case 'h':
            price = 2.0;
            break;

        case 'i':
            price = 1.2;
            break;

        case 'j':
            price = 1.0;
            break;

        default:
            price = 0.0;
    }

    return price;
}
