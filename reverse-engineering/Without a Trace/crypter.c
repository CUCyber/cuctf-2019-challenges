#include <stdio.h>
#include <stdlib.h>

#include "encrypt.h"

int main (int argc, char **argv){
    if (argc != 4){
        fprintf (stderr, "Invalid Number of parameters\n");
        fprintf (stderr, "%s key section file\n", argv[0]);
        exit (1);
    }

    set_key(argv[1]);
    encrypt(argv[2], argv[3]);

    return 0;
}
