#include <stdio.h>
#include <stdlib.h>
#include "support.h"
#include "phases.h"

FILE *infile;

int main(int argc, char *argv[])
{

    char *input;

    if (argc == 1)
    {
        infile = stdin;
    }

    /* Saat dijalankan dengan argumen berupa file, program akan membaca file sampai
    	EOF, kemudian akan membaca dari standar input. Jadi, setiap sudah berhasil menyelesaikan
    	satu level, password untuk memecahkan level tersebut dapat ditaruh ke dalam suatu file 
    	dan dapat menghindari untuk mengetik ulang */
    else if (argc == 2)
    {
        if (!(infile = fopen(argv[1], "r")))
        {
            printf("%s: Error: Couldn't open %s\n", argv[0], argv[1]);
            exit(8);
        }
    }

    else
    {
        printf("Usage: %s [<input_file>]\n", argv[0]);
        exit(8);
    }

    init_eva();

    printf("Welcome Pilot, there are 6 major sectors that needs to be repaired after angel's attack. We wish you best of luck.\n");

    input = read_line();
    Tokyo3Gate(input);
    sector_repaired();
    printf("The Tokyo3 Gate has been repaired. On to the next one, Pilot.\n");

    input = read_line();
    HQ(input);
    sector_repaired();
    printf("The Headquarter is now fully functional. Well done, Pilot. The next section awaits.\n");

    input = read_line();
    Pyramid(input);
    sector_repaired();
    printf("The Pyramid is looking sturdier than ever, Pilot. How about the next section?\n");

    input = read_line();
    CommandCenter(input);
    sector_repaired();
    printf("Reparation of the Command Center is done. Start working on the next one, Pilot.\n");

    input = read_line();
    MAGI(input);
    sector_repaired();
    printf("The MAGI looks even better than before. Can you fix the last section, Pilot?\n");

    input = read_line();
    TerminalDogma(input);
    sector_repaired();
    printf("The NERV HQ is fully repaired. We expect nothing less from you, Pilot.\n");
    printf("By the way, we heard something down Terminal Dogma, can you check down there?");

    return 0;
}
