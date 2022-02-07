#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

const char* program_name;

void print_usage(FILE* stream, int exit_code)
{
    fprintf(stream, "Usage:  %s options [ inputfile ... ]\n", program_name);
    fprintf(stream,
        "  -h  --help             Display this usage information.\n"
        "  -o  --output filename  Write output to file.\n"
        "  -v  --verbose          Print verbose messages.\n");
    exit(exit_code);
}

int main(int argc, char* argv[])
{
    /* A string listing valid short options letters.  */
    const char* const short_options = "ho:v";
    /* An array describing valid long options.  */
    const struct option long_options[] = {
        { "help", 0, NULL, 'h' },
        { "output", 1, NULL, 'o' },
        { "verbose", 0, NULL, 'v' },
        { NULL, 0, NULL, 0 } /* Required at end of array.  */
    };

    const char* output_filename = NULL;
    int verbose = 0;
    program_name = argv[0];

    int next_option;
    do {
        next_option = getopt_long(argc, argv, short_options, long_options, NULL);
        switch (next_option) {
        case 'h': /* -h or --help */
            /* User has requested usage information.  Print it to standard
                   output, and exit with exit code zero (normal termination).  */
            print_usage(stdout, 0);

        case 'o': /* -o or --output */
            /* This option takes an argument, the name of the output file.  */
            output_filename = optarg;
            break;

        case 'v': /* -v or --verbose */
            verbose = 1;
            break;

        case '?': /* The user specified an invalid option.  */
            /* Print usage information to standard error, and exit with exit
                   code one (indicating abonormal termination).  */
            print_usage(stderr, 1);

        case -1: /* Done with options.  */
            break;

        default: /* Something else: unexpected.  */
            abort();
        }
    } while (next_option != -1);

    /* Done with options.  OPTIND points to first non-option argument.
       For demonstration purposes, print them if the verbose option was
       specified.  */
    if (verbose) {
        int i;
        for (i = optind; i < argc; ++i)
            printf("Argument: %s\n", argv[i]);
    }

    /* The main program goes here.  */
    return 0;
}
