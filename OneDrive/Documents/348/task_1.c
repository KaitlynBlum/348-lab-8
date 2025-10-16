#include <stdio.h>

int main(void) {
    int score;

    while (1) {
        printf("Enter the NFL score (Enter 1 to stop): ");
        scanf("%d", &score);

        if (score <= 1) break;

        printf("Possible combinations of scoring plays if a team's score is %d:\n", score);

        // Loop through all combinations of scoring plays
        for (int td2 = 0; td2 * 8 <= score; td2++) {              // TD + 2pt (8)
            for (int td1 = 0; td1 * 7 + td2 * 8 <= score; td1++) { // TD + FG (7)
                for (int td = 0; td * 6 + td1 * 7 + td2 * 8 <= score; td++) { // TD (6)
                    for (int fg = 0; fg * 3 + td * 6 + td1 * 7 + td2 * 8 <= score; fg++) { // FG (3)
                        for (int safety = 0; safety * 2 + fg * 3 + td * 6 + td1 * 7 + td2 * 8 <= score; safety++) { // Safety (2)
                            if (td2 * 8 + td1 * 7 + td * 6 + fg * 3 + safety * 2 == score) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                    td2, td1, td, fg, safety);
                            }
                        }
                    }
                }
            }
        }

        printf("\n");
    }

    printf("Program ended.\n");
    return 0;
}
