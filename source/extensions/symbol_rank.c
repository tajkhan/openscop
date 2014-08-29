
    /*+-----------------------------------------------------------------**
     **                       OpenScop Library                          **
     **-----------------------------------------------------------------**
     **                    extensions/symbol_rank.c                    **
     **-----------------------------------------------------------------**
     **                   First version: 14/03/2014                     **
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
#include <osl/extensions/symbol_rank.h>


/*+***************************************************************************
 *                          Structure display function                       *
 *****************************************************************************/


/**
 * osl_symbol_rank_idump function:
 * this function displays an osl_symbol_rank_t structure (*srank) into a
 * file (file, possibly stdout) in a way that trends to be understandable. It
 * includes an indentation level (level) in order to work with other
 * idump functions.
 * \param file        The file where the information has to be printed.
 * \param srank       The srank structure to print.
 * \param level       Number of spaces before printing, for each line.
 */
void osl_symbol_rank_idump(FILE* file, osl_symbol_rank_p srank,
                           int level) {
  int j;

  // Go to the right level.
  for (j = 0; j < level; j++)
    fprintf(file, "|\t");

  if (srank != NULL)
    fprintf(file, "+-- osl_symbol_rank_t\n");
  else
    fprintf(file, "+-- NULL osl_symbol_rank\n");

  if (srank != NULL) {
    // Display the rank.
    fprintf(file, "Rank: %d\n", srank->rank);
  }

  // The last line.
  for (j = 0; j <= level; j++)
    fprintf(file, "|\t");
  fprintf(file, "\n");
}


/**
 * osl_symbol_rank_dump function:
 * this function prints the content of an osl_symbol_rank_t structure
 * (*srank) into a file (file, possibly stdout).
 * \param file        The file where the information has to be printed.
 * \param srank       The srank structure to print.
 */
void osl_symbol_rank_dump(FILE* file, osl_symbol_rank_p srank) {
  osl_symbol_rank_idump(file, srank, 0);
}


/**
 * osl_symbol_rank_sprint function:
 * this function prints the content of an osl_symbol_rank_t structure
 * (*srank) into a string (returned) in the OpenScop textual format.
 * \param  srank The srank structure to print.
 * \return A string containing the OpenScop dump of the srank structure.
 */
char* osl_symbol_rank_sprint(osl_symbol_rank_p srank) {
  int high_water_mark = OSL_MAX_STRING;
  char* string = NULL;
  char buffer[OSL_MAX_STRING];

  if (srank != NULL) {
    OSL_malloc(string, char*, high_water_mark * sizeof(char));
    string[0] = '\0';
   
    sprintf(buffer, "# Rank\n%d\n", srank->rank);
    osl_util_safe_strcat(&string, buffer, &high_water_mark);
  
    // Keep only the memory space we need.
    OSL_realloc(string, char*, (strlen(string) + 1) * sizeof(char));
  }

  return string;
}


/*****************************************************************************
 *                               Reading function                            *
 *****************************************************************************/


/**
 * osl_symbol_rank_sread function:
 * this function reads a srank structure from a string complying to the
 * OpenScop textual format and returns a pointer to this structure.
 * The input parameter is updated to the position in the input string this
 * function reach right after reading the srank structure.
 * \param[in,out] input The input string where to find srank.
 *                      Updated to the position after what has been read.
 * \return A pointer to the srank structure that has been read.
 */
osl_symbol_rank_p osl_symbol_rank_sread(char** input) {
  osl_symbol_rank_p srank;

  if (*input == NULL) {
    OSL_debug("no srank optional tag");
    return NULL;
  }

  // Build the srank structure.
  srank = osl_symbol_rank_malloc();
  
  // Read the rank.
  srank->rank = osl_util_read_int(NULL, input);
  
  return srank;
}


/*+***************************************************************************
 *                    Memory allocation/deallocation function                *
 *****************************************************************************/


/**
 * osl_symbol_rank_malloc function:
 * this function allocates the memory space for an osl_symbol_rank_t
 * structure and sets its fields with default values. Then it returns a
 * pointer to the allocated space.
 * \return A pointer to an empty srank structure with fields set to
 *         default values.
 */
osl_symbol_rank_p osl_symbol_rank_malloc() {
  osl_symbol_rank_p srank;
  
  OSL_malloc(srank, osl_symbol_rank_p, sizeof(osl_symbol_rank_t));
  srank->rank = OSL_UNDEFINED;

  return srank;
}


/**
 * osl_symbol_rank_free function:
 * this function frees the allocated memory for an osl_symbol_rank_t
 * structure.
 * \param srank The pointer to the srank structure to free.
 */
void osl_symbol_rank_free(osl_symbol_rank_p srank) {
  if (srank != NULL) {
    free(srank);
  }
}


/*+***************************************************************************
 *                            Processing functions                           *
 *****************************************************************************/


/**
 * osl_symbol_rank_clone function:
 * this function builds and returns a "hard copy" (not a pointer copy) of an
 * osl_symbol_rank_t data structure.
 * \param srank The pointer to the srank structure to clone.
 * \return A pointer to the clone of the srank structure.
 */
osl_symbol_rank_p osl_symbol_rank_clone(osl_symbol_rank_p srank) {
  osl_symbol_rank_p clone;

  if (srank == NULL)
    return NULL;

  clone = osl_symbol_rank_malloc();
  clone->rank = srank->rank;

  return clone;
}


/**
 * osl_symbol_rank_equal function:
 * this function returns true if the two srank structures are the same
 * (content-wise), false otherwise.
 * \param c1  The first srank structure.
 * \param c2  The second srank structure.
 * \return 1 if c1 and c2 are the same (content-wise), 0 otherwise.
 */
int osl_symbol_rank_equal(osl_symbol_rank_p c1, osl_symbol_rank_p c2) {
  if (c1 == c2)
    return 1;

  if (((c1 == NULL) && (c2 != NULL)) || ((c1 != NULL) && (c2 == NULL)))
    return 0;

  if (c1->rank != c2->rank) {
    OSL_info("symbol ranks are not the same");
    return 0;
  }

  return 1;
}

/**
 * osl_symbol_rank_get_rank function:
 * this function returns rank of the symbol in osl_symbol_rank 
 * \param srank  The osl_symbol_rank structure.
 * \return The rank of the symbol
 */
int osl_symbol_rank_get_rank(osl_symbol_rank_p srank) {
  if(srank)
    return srank->rank;
  else
    return OSL_UNDEFINED;
}

/**
 * osl_symbol_rank_set_rank function:
 * this function sets the rank of the symbol in osl_symbol_rank 
 * \param srank  The osl_symbol_rank structure.
 * \param rank    The value of rank
 * \return
 */
void osl_symbol_rank_set_rank(osl_symbol_rank_p srank, int rank) {
  if(srank)
    srank->rank = rank;
}

/**
 * osl_symbol_rank_interface function:
 * this function creates an interface structure corresponding to the 
 * osl_symbol_rank extension and returns it.
 * \return An interface structure for the srank extension.
 */
osl_interface_p osl_symbol_rank_interface() {
  osl_interface_p interface = osl_interface_malloc();
  
  OSL_strdup(interface->URI, OSL_URI_SYMBOL_SCOPE);
  interface->idump  = (osl_idump_f)osl_symbol_rank_idump;
  interface->sprint = (osl_sprint_f)osl_symbol_rank_sprint;
  interface->sread  = (osl_sread_f)osl_symbol_rank_sread;
  interface->malloc = (osl_malloc_f)osl_symbol_rank_malloc;
  interface->free   = (osl_free_f)osl_symbol_rank_free;
  interface->clone  = (osl_clone_f)osl_symbol_rank_clone;
  interface->equal  = (osl_equal_f)osl_symbol_rank_equal;

  return interface;
}
