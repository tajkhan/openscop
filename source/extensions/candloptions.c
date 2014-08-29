    /*+-----------------------------------------------------------------**
     **                       OpenScop Library                          **
     **-----------------------------------------------------------------**
     **                     extensions/candloptions.c                   **
     **-----------------------------------------------------------------**
     **                   First version: 29/08/2014                     **
     **-----------------------------------------------------------------**


 *****************************************************************************
 * OpenScop: Structures and formats for polyhedral tools to talk together    *
 *****************************************************************************
 *    ,___,,_,__,,__,,__,,__,,_,__,,_,__,,__,,___,_,__,,_,__,                *
 *    /   / /  //  //  //  // /   / /  //  //   / /  // /  /|,_,             *
 *   /   / /  //  //  //  // /   / /  //  //   / /  // /  / / /\             *
 *  |~~~|~|~~~|~~~|~~~|~~~|~|~~~|~|~~~|~~~|~~~|~|~~~|~|~~~|/_/  \            *
 *  | G |C| P | = | L | P |=| = |C| = | = | = |=| = |=| C |\  \ /\           *
 *  | R |l| o | = | e | l |=| = |a| = | = | = |=| = |=| L | \# \ /\          *
 *  | A |a| l | = | t | u |=| = |n| = | = | = |=| = |=| o | |\# \  \         *
 *  | P |n| l | = | s | t |=| = |d| = | = | = | |   |=| o | | \# \  \        *
 *  | H | | y |   | e | o | | = |l|   |   | = | |   | | G | |  \  \  \       *
 *  | I | |   |   | e |   | |   | |   |   |   | |   | |   | |   \  \  \      *
 *  | T | |   |   |   |   | |   | |   |   |   | |   | |   | |    \  \  \     *
 *  | E | |   |   |   |   | |   | |   |   |   | |   | |   | |     \  \  \    *
 *  | * |*| * | * | * | * |*| * |*| * | * | * |*| * |*| * | /      \* \  \   *
 *  | O |p| e | n | S | c |o| p |-| L | i | b |r| a |r| y |/        \  \ /   *
 *  '---'-'---'---'---'---'-'---'-'---'---'---'-'---'-'---'          '--'    *
 *                                                                           *
 * Copyright (C) 2008 University Paris-Sud 11 and INRIA                      *
 *                                                                           *
 * (3-clause BSD license)                                                    *
 * Redistribution and use in source  and binary forms, with or without       *
 * modification, are permitted provided that the following conditions        *
 * are met:                                                                  *
 *                                                                           *
 * 1. Redistributions of source code must retain the above copyright notice, *
 *    this list of conditions and the following disclaimer.                  *
 * 2. Redistributions in binary form must reproduce the above copyright      *
 *    notice, this list of conditions and the following disclaimer in the    *
 *    documentation and/or other materials provided with the distribution.   *
 * 3. The name of the author may not be used to endorse or promote products  *
 *    derived from this software without specific prior written permission.  *
 *                                                                           *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR      *
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES *
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.   *
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,          *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, *
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY     *
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT       *
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  *
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.         *
 *                                                                           *
 * OpenScop Library, a library to manipulate OpenScop formats and data       *
 * structures. Written by:                                                   *
 * Cedric Bastoul     <Cedric.Bastoul@u-psud.fr> and                         *
 * Louis-Noel Pouchet <Louis-Noel.pouchet@inria.fr>                          *
 *                                                                           *
 *****************************************************************************/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <osl/macros.h>
#include <osl/util.h>
#include <osl/interface.h>
#include <osl/scop.h>
#include <osl/extensions/candloptions.h>


/*+***************************************************************************
 *                          Structure display function                       *
 *****************************************************************************/

/**
 * osl_candloptions_idump function:
 * this function displays an osl_candloptions_t structure  into a
 * file (file, possibly stdout) in a way that tends to be understandable. It
 * includes an indentation level (level) in order to work with others
 * idump functions.
 *
 * \param file         The file where the information has to be printed.
 * \param candloptions The candloptions structure to print.
 * \param level        Number of spaces before printing, for each line.
 */
void osl_candloptions_idump(FILE* file, osl_candloptions_p candloptions,
                           int level) {
  int j;

  // Go to the right level.
  for (j = 0; j < level; j++)
    fprintf(file, "|\t");

  if (candloptions != NULL)
    fprintf(file, "+-- osl_candloptions_t\n");
  else
    fprintf(file, "+-- NULL candloptions\n");

  if (candloptions != NULL) {
    // Go to the right level.
    for (j = 0; j <= level; j++)
      fprintf(file, "|\t");
    fprintf(file, "waw: %d\n", candloptions->waw);

    for (j = 0; j <= level; j++)
      fprintf(file, "|\t");
    fprintf(file, "raw: %d\n", candloptions->raw);


    for (j = 0; j <= level; j++)
      fprintf(file, "|\t");
    fprintf(file, "war: %d\n", candloptions->war);

    for (j = 0; j <= level; j++)
      fprintf(file, "|\t");
    fprintf(file, "rar: %d\n", candloptions->rar);

    for (j = 0; j <= level; j++)
      fprintf(file, "|\t");
    fprintf(file, "commute: %d\n", candloptions->commute);

    for (j = 0; j <= level; j++)
      fprintf(file, "|\t");
    fprintf(file, "fullcheck: %d\n", candloptions->fullcheck);

    for (j = 0; j <= level; j++)
      fprintf(file, "|\t");
    fprintf(file, "scalren: %d\n", candloptions->scalar_renaming);

    for (j = 0; j <= level; j++)
      fprintf(file, "|\t");
    fprintf(file, "scalpriv: %d\n", candloptions->scalar_privatization);

    for (j = 0; j <= level; j++)
      fprintf(file, "|\t");
    fprintf(file, "scalexp: %d\n", candloptions->scalar_expansion);

    for (j = 0; j <= level; j++)
      fprintf(file, "|\t");
    fprintf(file, "lastwriter: %d\n", candloptions->lastwriter);

    for (j = 0; j <= level; j++)
      fprintf(file, "|\t");
    fprintf(file, "autocorrect: %d\n", candloptions->autocorrect);

    for (j = 0; j <= level; j++)
      fprintf(file, "|\t");
    fprintf(file, "view: %d\n", candloptions->view);

    for (j = 0; j <= level; j++)
      fprintf(file, "|\t");
    fprintf(file, "verbose: %d\n", candloptions->verbose);

    for (j = 0; j <= level; j++)
      fprintf(file, "|\t");
    fprintf(file, "outscop: %d\n", candloptions->outscop);

    for (j = 0; j <= level; j++)
      fprintf(file, "|\t");
    fprintf(file, "prune-dups: %d\n", candloptions->prune_dups);

    for (j = 0; j <= level; j++)
      fprintf(file, "|\t");
    fprintf(file, "struct: %d\n", candloptions->structure);

  }

  // The last line.
  for (j = 0; j <= level; j++)
    fprintf(file, "|\t");
  fprintf(file, "\n");
}



/**
 * osl_candloptions_dump function:
 * this function prints the content of an osl_candloptions_t structure
 * (*candloptions) into a file (file, possibly stdout).
 *
 * \param file         The file where the information has to be printed.
 * \param candloptions The candloptions structure to print.
 */
void osl_candloptions_dump(FILE* file, osl_candloptions_p candloptions) {
  osl_candloptions_idump(file, candloptions, 0);
}




/**
 * osl_candloptions_sprint function:
 * this function prints the content of an osl_candloptions_t structure
 * (*candloptions) into a string (returned) in the OpenScop textual format.
 *
 * \param  candloptions The candloptions structure to be printed.
 * \return              A string containing the OpenScop dump of the
 *                      candloptions structure.
 */
char* osl_candloptions_sprint(osl_candloptions_p candloptions) {
  int   high_water_mark = OSL_MAX_STRING;
  char* string = NULL;
  char  buffer[OSL_MAX_STRING];

  if (candloptions != NULL) {
    OSL_malloc(string, char*, high_water_mark * sizeof(char));
    string[0] = '\0';

    // Print the candloptions content.
    if (candloptions->waw_set) {
      sprintf(buffer, "waw %d # write after write (output)"
                      "dependences matter\n", candloptions->waw);
      osl_util_safe_strcat(&string, buffer, &high_water_mark);
    }

    if (candloptions->raw_set) {
      sprintf(buffer, "raw %d # read  after write (flow)"
                      "dependences matter\n", candloptions->raw);
      osl_util_safe_strcat(&string, buffer, &high_water_mark);
    }

    if (candloptions->war_set) {
      sprintf(buffer,"war %d # write after read  (anti)"
                     "dependences matter\n", candloptions->war);
      osl_util_safe_strcat(&string, buffer, &high_water_mark);
    }

    if (candloptions->rar_set) {
      sprintf(buffer,"rar %d # read  after read  (input)"
                     "dependences matter\n", candloptions->rar);
      osl_util_safe_strcat(&string, buffer, &high_water_mark);
    }

    if (candloptions->commute_set) {
      sprintf(buffer,"commute %d # use commutativity to simplify dependences\n",
                     candloptions->commute);
      osl_util_safe_strcat(&string, buffer, &high_water_mark);
    }

    if (candloptions->fullcheck_set) {
      sprintf(buffer,"fullcheck %d # compute all dependence violations\n",
                     candloptions->fullcheck);
      osl_util_safe_strcat(&string, buffer, &high_water_mark);
    }

    if (candloptions->scalar_renaming_set) {
      sprintf(buffer,"scalren %d # enable scalar renaming\n",
                     candloptions->scalar_renaming);
      osl_util_safe_strcat(&string, buffer, &high_water_mark);
    }

    if (candloptions->scalar_privatization_set) {
      sprintf(buffer,"scalpriv %d # enable scalar privatization\n",
                     candloptions->scalar_privatization);
      osl_util_safe_strcat(&string, buffer, &high_water_mark);
    }

    if (candloptions->scalar_expansion_set) {
      sprintf(buffer,"scalexp %d # enable scalar expansion\n",
                    candloptions->scalar_expansion);
      osl_util_safe_strcat(&string, buffer, &high_water_mark);
    }

    if (candloptions->lastwriter_set) {
      sprintf(buffer,"lastwriter %d # compute last writer\n",
                     candloptions->lastwriter);
      osl_util_safe_strcat(&string, buffer, &high_water_mark);
    }

    if (candloptions->verbose_set) {
      sprintf(buffer,"verbose %d # enable verbose output\n",
                     candloptions->verbose);
      osl_util_safe_strcat(&string, buffer, &high_water_mark);
    }

    if (candloptions->outscop_set) {
      sprintf(buffer,"outscop %d # print the scop with dependences\n",
                     candloptions->outscop);
      osl_util_safe_strcat(&string, buffer, &high_water_mark);
    }

    if (candloptions->autocorrect_set) {
      sprintf(buffer,"autocorrect %d # correct violations.\n",
                     candloptions->autocorrect);
      osl_util_safe_strcat(&string, buffer, &high_water_mark);
    }

    if (candloptions->view_set) {
      sprintf(buffer,"view %d # call dot and gv to visualize the graphs\n",
                     candloptions->view);
      osl_util_safe_strcat(&string, buffer, &high_water_mark);
    }

    if (candloptions->structure_set) {
      sprintf(buffer,"struct %d # print internal dependence structure\n",
                     candloptions->structure);
      osl_util_safe_strcat(&string, buffer, &high_water_mark);
    }

    if (candloptions->prune_dups_set) {
      sprintf(buffer,"prune-dups %d # use experimental dependence"
                     " pruning algorithm\n", candloptions->prune_dups);
      osl_util_safe_strcat(&string, buffer, &high_water_mark);
    }

    // Keep only the memory space we need.
    OSL_realloc(string, char*, (strlen(string) + 1) * sizeof(char));
  }

  return string;
}



/*****************************************************************************
 *                               Reading function                            *
 *****************************************************************************/


/**
 * osl_candloptions_read_args function:
 * this function reads CandlOptions passed to the main on the command line.
 * These options have the format "--candl-option argument". This function will
 * only read options belonging to Candl. It will then update the passed
 * array of strings by removing the options that it has read. It will also
 * update the pointer to the number of arguments accordingly.
 *
 * \param[in,out] argc_ptr Pointer to argument count.
 * \param[in,out] argv_ptr Pointer to array of strings containing arguments.
 * \return osl_candloptions_p structure constructed from arguments.
 */
osl_candloptions_p osl_candloptions_read_args(int *argc_ptr, char***argv_ptr){

  int argc = *argc_ptr;
  char** argv = *argv_ptr;
  char** newargv = NULL;
  int i = 0;
  int new_i = 0;
  int unused_cnt = 0;
  int *used = (int*)malloc(sizeof(int)*argc);

  osl_candloptions_p clops = osl_candloptions_malloc();
  for(i=0; i< argc; i++)
    used[i] = 0;

  for (i=0; i< argc; i++) {
    if (!strcmp(argv[i], "--candl-waw")) {
      used[i++] = 1;
      clops->waw_set = osl_util_read_arg_int(i, argv, &clops->waw);
      used[i] = 1;  // incremented by loop
    }

    if (!strcmp(argv[i], "--candl-raw")) {
      used[i++] = 1;
      clops->raw_set = osl_util_read_arg_int(i, argv, &clops->raw);
      used[i] = 1;  // incremented by loop
    }

    if (!strcmp(argv[i], "--candl-war")) {
      used[i++] = 1;
      clops->war_set = osl_util_read_arg_int(i, argv,
                                &clops->war);
      used[i] = 1;  // incremented by loop
    }

    if (!strcmp(argv[i], "--candl-rar")) {
      used[i++] = 1;
      clops->rar_set = osl_util_read_arg_int(i, argv,
                                &clops->rar);
      used[i] = 1;  // incremented by loop
    }

    if (!strcmp(argv[i], "--candl-commute")) {
      used[i++] = 1;
      clops->commute_set = osl_util_read_arg_int(i, argv,
                                &clops->commute);
      used[i] = 1;  // incremented by loop
    }

    if (!strcmp(argv[i], "--candl-fullcheck")) {
      used[i++] = 1;
      clops->fullcheck_set = osl_util_read_arg_int(i, argv,
                                &clops->fullcheck);
      used[i] = 1;  // incremented by loop
    }

    if (!strcmp(argv[i], "--candl-scalren")) {
      used[i++] = 1;
      clops->scalar_renaming_set = osl_util_read_arg_int(i, argv,
                                &clops->scalar_renaming);
      used[i] = 1;  // incremented by loop
    }

    if (!strcmp(argv[i], "--candl-scalpriv")) {
      used[i++] = 1;
      clops->scalar_privatization_set = osl_util_read_arg_int(i, argv,
                                &clops->scalar_privatization);
      used[i] = 1;  // incremented by loop
    }

    if (!strcmp(argv[i], "--candl-scalexp")) {
      used[i++] = 1;
      clops->scalar_expansion_set = osl_util_read_arg_int(i, argv,
                                &clops->scalar_expansion);
      used[i] = 1;  // incremented by loop
    }

    if (!strcmp(argv[i], "--candl-lastwriter")) {
      used[i++] = 1;
      clops->lastwriter_set = osl_util_read_arg_int(i, argv,
                                &clops->lastwriter);
      used[i] = 1;  // incremented by loop
    }

    if (!strcmp(argv[i], "--candl-verbose")) {
      used[i++] = 1;
      clops->verbose_set = osl_util_read_arg_int(i, argv,
                                &clops->verbose);
      used[i] = 1;  // incremented by loop
    }

    if (!strcmp(argv[i], "--candl-outscop")) {
      used[i++] = 1;
      clops->outscop_set = osl_util_read_arg_int(i, argv,
                                &clops->outscop);
      used[i] = 1;  // incremented by loop
    }

    if (!strcmp(argv[i], "--candl-autocorrect")) {
      used[i++] = 1;
      clops->autocorrect_set = osl_util_read_arg_int(i, argv,
                                &clops->autocorrect);
      used[i] = 1;  // incremented by loop
    }

    if (!strcmp(argv[i], "--candl-view")) {
      used[i++] = 1;
      clops->view_set = osl_util_read_arg_int(i, argv,
                                &clops->view);
      used[i] = 1;  // incremented by loop
    }

    if (!strcmp(argv[i], "--candl-struct")) {
      used[i++] = 1;
      clops->structure_set = osl_util_read_arg_int(i, argv,
                                &clops->structure);
      used[i] = 1;  // incremented by loop
    }

    if (!strcmp(argv[i], "--candl-prune-dups")) {
      used[i++] = 1;
      clops->prune_dups_set = osl_util_read_arg_int(i, argv,
                                &clops->prune_dups);
      used[i] = 1;  // incremented by loop
    }

  }


  //Remove the consumed arguments from the list
  for (i=0; i< argc; i++)
    if (used[i]==0)
      unused_cnt++;

  newargv = (char**)malloc(sizeof(char*)*unused_cnt);

  for (i=0; i< argc; i++)
    if (used[i]==0)
      OSL_strdup(newargv[new_i++], argv[i]);

  for (i=0; i< argc; i++)
    free(argv[i]);
  free(argv);
  free(used);

  *argc_ptr = unused_cnt;
  *argv_ptr = newargv;

  return clops;
}


/**
 * osl_candloptions_sread function:
 * this function reads a candloptions structure from a string complying to the
 * OpenScop textual format and returns a pointer to this structure.
 * The input parameter is updated to the position in the input string this
 * function reaches right after reading the candloptions structure.
 *
 * \param[in,out] input The input string where to find candloptions.
 *                      Updated to the position after what has been read.
 * \return              A pointer to the candloptions structure that has
 *                      been read.
 */
osl_candloptions_p osl_candloptions_sread(char** input) {
  osl_candloptions_p candloptions;
  char* line = NULL;
  char* line_bk = NULL;
  char* option = NULL;

  if (*input == NULL) {
    OSL_debug("no candloptions optional tag");
    return NULL;
  }

  // Build the candloptions structure.
  candloptions = osl_candloptions_malloc();

  // Read the candloptions.
  line_bk = line = osl_util_read_line(NULL, input);
  while (line[0]) {

    if (option)
      free(option);
    option = osl_util_read_string(NULL, &line);

    if (strcmp(option, "waw")==0) {
      candloptions->waw = osl_util_read_int(NULL, &line);
      candloptions->waw_set = 1;
    }

    if (strcmp(option, "raw")==0) {
      candloptions->raw = osl_util_read_int(NULL, &line);
      candloptions->raw_set = 1;
    }

    if (strcmp(option, "war")==0) {
      candloptions->war = osl_util_read_int(NULL, &line);
      candloptions->war_set = 1;
    }

    if (strcmp(option, "rar")==0) {
      candloptions->rar = osl_util_read_int(NULL, &line);
      candloptions->rar_set = 1;
    }

    if (strcmp(option, "commute")==0) {
      candloptions->commute = osl_util_read_int(NULL, &line);
      candloptions->commute_set = 1;
    }

    if (strcmp(option, "fullcheck")==0) {
      candloptions->fullcheck = osl_util_read_int(NULL, &line);
      candloptions->fullcheck_set = 1;
    }

    if (strcmp(option, "scalren")==0) {
      candloptions->scalar_renaming = osl_util_read_int(NULL, &line);
      candloptions->scalar_renaming_set = 1;
    }

    if (strcmp(option, "scalpriv")==0) {
      candloptions->scalar_privatization = osl_util_read_int(NULL, &line);
      candloptions->scalar_privatization_set = 1;
    }

    if (strcmp(option, "scalexp")==0) {
      candloptions->scalar_expansion = osl_util_read_int(NULL, &line);
      candloptions->scalar_expansion_set = 1;
    }

    if (strcmp(option, "lastwriter")==0) {
      candloptions->lastwriter = osl_util_read_int(NULL, &line);
      candloptions->lastwriter_set = 1;
    }

    if (strcmp(option, "verbose")==0) {
      candloptions->verbose = osl_util_read_int(NULL, &line);
      candloptions->verbose_set = 1;
    }

    if (strcmp(option, "outscop")==0) {
      candloptions->outscop = osl_util_read_int(NULL, &line);
      candloptions->outscop_set = 1;
    }

    if (strcmp(option, "autocorrect")==0) {
      candloptions->autocorrect = osl_util_read_int(NULL, &line);
      candloptions->autocorrect_set = 1;
    }

    if (strcmp(option, "view")==0) {
      candloptions->view = osl_util_read_int(NULL, &line);
      candloptions->view_set = 1;
    }

    if (strcmp(option, "struct")==0) {
      candloptions->structure = osl_util_read_int(NULL, &line);
      candloptions->structure_set = 1;
    }

    if (strcmp(option, "prune-dups")==0) {
      candloptions->prune_dups = osl_util_read_int(NULL, &line);
      candloptions->prune_dups_set = 1;
    }

    if (line)
      free(line_bk);
    line_bk = line = osl_util_read_line(NULL, input);
  }

  if(line)
    free(line);
  if(option)
    free(option);
  return candloptions;
}



/*+***************************************************************************
 *                    Memory allocation/deallocation function                *
 *****************************************************************************/


/**
 * osl_candloptions_malloc function:
 * This function allocates the memory space for a osl_candloptions structure and
 * fills its fields with the default values. It returns a pointer to the
 * allocated structure.
 *
 * \return    A pointer to the candloptions structure that has been allocated.
 */
osl_candloptions_p osl_candloptions_malloc()
{ osl_candloptions_p options ;

  /* Memory allocation for the CandlOptions structure. */
  OSL_malloc(options, osl_candloptions_p, sizeof(osl_candloptions_t));

  /* We set the various fields with default values. */
  /* OPTIONS FOR DEPENDENCE COMPUTATION */
  options->waw = 1;       /* WAW (output) dependences matter. */
  options->waw_set = 1;
  options->raw = 1;       /* RAW (flow)   dependences matter. */
  options->raw_set = 1;
  options->war = 1;       /* WAR (anti)   dependences matter. */
  options->war_set = 1;
  options->rar = 0;       /* RAR (input)  dependences don't matter. */
  options->rar_set = 0;
  options->commute = 0;   /* Don't use commutativity to simplify dependences.*/
  options->commute_set = 0;
  options->fullcheck = 0; /* Don't compute all violations.*/
  options->fullcheck_set = 0;
  options->scalar_renaming = 0; /* Don't enable scalar renaming. */
  options->scalar_renaming_set = 0;
  options->scalar_privatization = 0; /* Don't enable scalar privatization. */
  options->scalar_privatization_set = 0;
  options->scalar_expansion = 0; /* Don't enable scalar expansion. */
  options->scalar_expansion_set = 0;
  options->lastwriter = 0; /* Compute the last writer for RAW and WAW dependences */
  options->lastwriter_set = 0;
  options->verbose = 0; /* Don't be verbose. */
  options->verbose_set = 0;
  options->outscop = 0; /* Don't print the scop. */
  options->outscop_set = 0;
  options->autocorrect = 0; /* Don't correct violations. */
  options->autocorrect_set = 0;
  /* UNDOCUMENTED OPTIONS FOR THE AUTHOR ONLY */
  options->view = 0;      /* Do not visualize the graph with dot and gv.*/
  options->view_set = 0;
  options->structure = 0; /* Don't print internal dependence structure. */
  options->structure_set = 0;
  options->prune_dups = 0; /**< 1 to use experimental dependence pruning algorithm. */
  options->prune_dups_set = 0;

  return options ;
}



/**
 * osl_candloptions_free function:
 * This functions frees the memory space for a osl_candloptions structure
 *
 * \param[in] input Pointer to osl_candloptions_t to free
 */
void osl_candloptions_free(osl_candloptions_p options){

  free(options);
}



/*+***************************************************************************
 *                            Processing functions                           *
 *****************************************************************************/


/**
 * osl_candloptions_clone function:
 * This function makes a hard copy of the osl_candloptions structure passed
 * to it and returns a pointer to the newly formed copy.
 *
 * \param[in] options   Pointer to osl_candloptions_t structure to clone
 * \return              Pointer to newly created clone.
 */
osl_candloptions_p osl_candloptions_clone(osl_candloptions_p options)
{ osl_candloptions_p candloptions ;

  /* Memory allocation for the CandlOptions structure. */
  candloptions = osl_candloptions_malloc();

  candloptions->waw_set       = options->waw_set;
  candloptions->waw           = options->waw;
  candloptions->raw_set       = options->raw_set;
  candloptions->raw           = options->raw;
  candloptions->war_set       = options->war_set;
  candloptions->war           = options->war;
  candloptions->rar_set       = options->rar_set;
  candloptions->rar           = options->rar;
  candloptions->commute_set       = options->commute_set;
  candloptions->commute           = options->commute;
  candloptions->fullcheck_set       = options->fullcheck_set;
  candloptions->fullcheck           = options->fullcheck;
  candloptions->scalar_renaming_set       = options->scalar_renaming_set;
  candloptions->scalar_renaming           = options->scalar_renaming;
  candloptions->scalar_privatization_set       = options->scalar_privatization_set;
  candloptions->scalar_privatization           = options->scalar_privatization;
  candloptions->scalar_expansion_set       = options->scalar_expansion_set;
  candloptions->scalar_expansion           = options->scalar_expansion;
  candloptions->lastwriter_set       = options->lastwriter_set;
  candloptions->lastwriter           = options->lastwriter;
  candloptions->verbose_set       = options->verbose_set;
  candloptions->verbose           = options->verbose;
  candloptions->outscop_set       = options->outscop_set;
  candloptions->outscop           = options->outscop;
  candloptions->autocorrect_set       = options->autocorrect_set;
  candloptions->autocorrect           = options->autocorrect;
  candloptions->view_set       = options->view_set;
  candloptions->view           = options->view;
  candloptions->structure_set       = options->structure_set;
  candloptions->structure           = options->structure;
  candloptions->prune_dups_set       = options->prune_dups_set;
  candloptions->prune_dups           = options->prune_dups;

  return candloptions ;
}



/**
 * osl_candloptions_equal function:
 * This functions compares two osl_candloptions_t structures and returns 1
 * if the two are equal, 0 otherwise
 *
 * \param[in] candloptions Pointer to osl_candloptions_t structure to compare
 * \param[in] options      Pointer to osl_candloptions_t structure to compare
 * \return                 1 if both structures are equal, 0 otherwise
 */
int osl_candloptions_equal(osl_candloptions_p candloptions,
                           osl_candloptions_p options)
{

  if (candloptions == options)
    return 1;

  if ((candloptions->waw_set != options->waw_set)
      || (candloptions->waw != options->waw))
    return 0;
  if ((candloptions->raw_set != options->raw_set)
      || (candloptions->raw != options->raw))
    return 0;
  if ((candloptions->war_set != options->war_set)
      || (candloptions->war != options->war))
    return 0;
  if ((candloptions->rar_set != options->rar_set)
      || (candloptions->rar != options->rar))
    return 0;
  if ((candloptions->commute_set != options->commute_set)
      || (candloptions->commute != options->commute))
    return 0;
  if ((candloptions->fullcheck_set != options->fullcheck_set)
      || (candloptions->fullcheck != options->fullcheck))
    return 0;
  if ((candloptions->scalar_renaming_set != options->scalar_renaming_set)
      || (candloptions->scalar_renaming != options->scalar_renaming))
    return 0;
  if ((candloptions->scalar_privatization_set != options->scalar_privatization_set)
      || (candloptions->scalar_privatization != options->scalar_privatization))
    return 0;
  if ((candloptions->scalar_expansion_set != options->scalar_expansion_set)
      || (candloptions->scalar_expansion != options->scalar_expansion))
    return 0;
  if ((candloptions->lastwriter_set != options->lastwriter_set)
      || (candloptions->lastwriter != options->lastwriter))
    return 0;
  if ((candloptions->verbose_set != options->verbose_set)
      || (candloptions->verbose != options->verbose))
    return 0;
  if ((candloptions->outscop_set != options->outscop_set)
      || (candloptions->outscop != options->outscop))
    return 0;
  if ((candloptions->autocorrect_set != options->autocorrect_set)
      || (candloptions->autocorrect != options->autocorrect))
    return 0;
  if ((candloptions->view_set != options->view_set)
      || (candloptions->view != options->view))
    return 0;
  if ((candloptions->structure_set != options->structure_set)
      || (candloptions->structure != options->structure))
    return 0;
  if ((candloptions->prune_dups_set != options->prune_dups_set)
      || (candloptions->prune_dups != options->prune_dups))
    return 0;

  return 1;
}


/**
 * osl_candloptions_interface function:
 * this function creates an interface structure corresponding the candloptions
 * extension and returns it.
 *
 * \return An interface structure for the candloptions extension.
 */
osl_interface_p osl_candloptions_interface() {
  osl_interface_p interface = osl_interface_malloc();

  interface->URI    = strdup(OSL_URI_CANDLOPTIONS);
  interface->idump  = (osl_idump_f)osl_candloptions_idump;
  interface->sprint = (osl_sprint_f)osl_candloptions_sprint;
  interface->sread  = (osl_sread_f)osl_candloptions_sread;
  interface->malloc = (osl_malloc_f)osl_candloptions_malloc;
  interface->free   = (osl_free_f)osl_candloptions_free;
  interface->clone  = (osl_clone_f)osl_candloptions_clone;
  interface->equal  = (osl_equal_f)osl_candloptions_equal;

  return interface;
}
