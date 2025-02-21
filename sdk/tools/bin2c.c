/*
 * COPYRIGHT:       See COPYING in the top level directory
 * PROJECT:         classicOS bin2c
 * FILE:            tools/bin2c.c
 * PURPOSE:         Converts a binary file into a byte array
 * PROGRAMMER:      Herm�s B�lusca - Ma�to
 */

#include <stdio.h>

#ifdef _WIN32
#include <string.h>         // Required for _stricmp()
#else
#include <strings.h>        // Required for strcasecmp()
#define _stricmp strcasecmp
#endif

static size_t dumpHex(FILE* inFile, FILE* outCFile, char nullTerminate)
{
    size_t bufLen = 0;
    unsigned char ch;

    fprintf(outCFile, "\n{");
    do
    {
        /* Read the next byte */
        ch = fgetc(inFile);

        if (feof(inFile) && nullTerminate)
            ch = 0x00;

        if (!feof(inFile) || nullTerminate)
        {
            /* Start a new line if needed */
            if ((bufLen % 16) == 0)
                fprintf(outCFile, "\n   ");

            /* Write the byte or the optional NULL terminator */
            fprintf(outCFile, " 0x%02x,", (unsigned int)ch);

            ++bufLen;
        }
    } while (!feof(inFile));
    fprintf(outCFile, "\n}");

    return bufLen;
}

static size_t dumpStr(FILE* inFile, FILE* outCFile)
{
    size_t bufLen = 0;
    unsigned char ch;

    /* Always start the first line */
    fprintf(outCFile, "\n    \"");
    do
    {
        /* Read the next byte */
        ch = fgetc(inFile);

        /* If a byte is available... */
        if (!feof(inFile))
        {
            /* ... do we need to start a new line? */
            if ((bufLen != 0) && (bufLen % 16) == 0)
            {
                /* Yes, end the current line and start a new one */
                fprintf(outCFile, "\"");
                fprintf(outCFile, "\n    \"");
            }

            /* Now write the byte */
            fprintf(outCFile, "\\x%02x", (unsigned int)ch);
        }
        /* ... otherwise, end the current line... */
        else
        {
            fprintf(outCFile, "\"");
            /* We break just after */
        }

        ++bufLen; // This takes also the final NULL terminator into account.

    } while (!feof(inFile));

    return bufLen;
}

static void usage(char* name)
{
    fprintf(stdout, "Usage: %s infile.bin outfile.c outfile.h [BIN|BINSTR|STR] array_name [array_attribute [header_for_attribute]]\n", name);
}

int main(int argc, char* argv[])
{
    FILE* inFile;
    FILE* outCFile;
    FILE* outHFile;
    size_t bufLen;

    /* Validate the arguments */
    if (argc < 6)
    {
        usage(argv[0]);
        return -1;
    }

    /* Verify the output format */
    if (_stricmp(argv[4], "BIN"   ) != 0 &&
        _stricmp(argv[4], "BINSTR") != 0 &&
        _stricmp(argv[4], "STR"   ) != 0)
    {
        usage(argv[0]);
        return -1;
    }

    /* Open the input and output files */
    inFile = fopen(argv[1], "rb");
    if (!inFile)
    {
        fprintf(stderr, "ERROR: Couldn't open data file '%s'.\n", argv[1]);
        return -1;
    }
    outCFile = fopen(argv[2], "w");
    if (!outCFile)
    {
        fclose(inFile);
        fprintf(stderr, "ERROR: Couldn't create output source file '%s'.\n", argv[2]);
        return -1;
    }
    outHFile = fopen(argv[3], "w");
    if (!outHFile)
    {
        fclose(outCFile);
        fclose(inFile);
        fprintf(stderr, "ERROR: Couldn't create output header file '%s'.\n", argv[3]);
        return -1;
    }

    /* Generate the source file and close it */
    fprintf(outCFile, "/* This file is autogenerated, do not edit. */\n\n");
    if (argc >= 8)
    {
        /* Include needed header for defining the array attribute */
        fprintf(outCFile, "#include \"%s\"\n", argv[7]);
    }
    fprintf(outCFile, "#include \"%s\"\n\n", argv[3]);

    /* Generate the data array */
    if (argc >= 7)
    {
        /* Add the array attribute */
        fprintf(outCFile, "%s ", argv[6]);
    }
    fprintf(outCFile, "unsigned char %s[] =", argv[5]);

    /* Output the bytes in the chosen format */
    if (_stricmp(argv[4], "BIN") == 0)
        bufLen = dumpHex(inFile, outCFile, 0);
    else if (_stricmp(argv[4], "BINSTR") == 0)
        bufLen = dumpHex(inFile, outCFile, 1);
    else // (_stricmp(argv[4], "STR") == 0)
        bufLen = dumpStr(inFile, outCFile);

    fprintf(outCFile, ";\n");
    fclose(outCFile);

    /* Generate the header file and close it */
    fprintf(outHFile, "/* This file is autogenerated, do not edit. */\n\n");
    fprintf(outHFile, "#define %s_SIZE %lu\n"          , argv[5], (unsigned long)bufLen);
    fprintf(outHFile, "extern unsigned char %s[%lu];\n", argv[5], (unsigned long)bufLen);
    fclose(outHFile);

    /* Close the input file */
    fclose(inFile);

    return 0;
}

/* EOF */
