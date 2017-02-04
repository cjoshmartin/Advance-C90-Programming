/*
Program Name: Lab 4
Name: Josh Martin
Class Date: ????
Description: Read a text file and output some info using scanf
Side note: this lab was stupid an too hard! I probly could not do it anyother way then how I have done it below
*/

#include <stdio.h>
#include <string.h>

/* constants for use in your code */
enum { YN = 2, DOB = 11, SS = 12, NM = 32 };

typedef struct {
    char last[NM], first[NM], ss[SS], dob[DOB], yn[YN];
    double qavg, lavg, ex1, ex2, fex;
} stnt;

int main (int argc, char **argv) {

	system("CLS"); //clears screen on windows

    stnt s[8] = {{ .first = "" }};
    int i,cnv = 0, n = 0;
    char *fmt = " %*[^\"]\"%[^,], %[^\"]\" %s %s %[YN] %lf %lf %lf %lf %lf";
    FILE *fp = argc > 1 ? fopen (argv[1], "r") : stdin;

    if (!fp) {  /* validate file open for reading */
        fprintf (stderr, "error: file open failed '%s'.\n", argv[1]);
        return 1;
    }

    /* read each line, if the match-count is 10 increment index */
    while ((cnv=fscanf (fp, fmt, s[n].last, s[n].first, s[n].ss, s[n].dob, s[n].yn,
                &s[n].qavg, &s[n].lavg, &s[n].ex1, &s[n].ex2, &s[n].fex)) != EOF)
        if (cnv == 10) n++;

    if (fp != stdin) fclose (fp);     /* close file if not stdin */

    printf("\n\n  |%5s | %5s | %3d |\n","SSN","Average", 263);
		printf("--------------------------\n");
    for ( i = 0; i < n; i++) /* output the student information */
    {

        printf (" %1i| %3s"
                " | %6.3lf%% |%3s  | \n",i+1,&s[i].ss[strlen(s[i].ss) - 4],(s[i].qavg*.07)+ (s[i].lavg*.24) + (s[i].ex1*.185)+ (s[i].ex2*.185) + (s[i].fex*.32), s[i].yn);
}
    return 0;
}
