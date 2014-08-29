
    /*+-----------------------------------------------------------------**
     **                       OpenScop Library                          **
     **-----------------------------------------------------------------**
     **                     extensions/candloptions.h                   **
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


#ifndef OSL_CANDLOPTIONS_H
# define OSL_CANDLOPTIONS_H

# include <stdio.h>
# include <osl/interface.h>

# if defined(__cplusplus)
extern "C"
  {
# endif


# define OSL_URI_CANDLOPTIONS "candloptions"



struct osl_candloptions {
  /* OPTIONS FOR DEPENDENCE COMPUTATION */
  int waw;       /**< 1 if write after write (output) dependences matter. */
  int waw_set;
  int raw;       /**< 1 if read  after write (flow)   dependences matter. */
  int raw_set;
  int war;       /**< 1 if write after read  (anti)   dependences matter. */
  int war_set;
  int rar;       /**< 1 if read  after read  (input)  dependences matter. */
  int rar_set;
  int commute;   /**< 1 to use commutativity to simplify dependences. */
  int commute_set;
  int fullcheck; /**< 1 to compute all dependence violations. */
  int fullcheck_set;
  int scalar_renaming; /**< 1 to enable scalar renaming. */
  int scalar_renaming_set;
  int scalar_privatization; /**< 1 to enable scalar privatization. */
  int scalar_privatization_set;
  int scalar_expansion; /**< 1 to enable scalar privatization. */
  int scalar_expansion_set;
  int lastwriter; /**< 1 to compute last writer */
  int lastwriter_set;
  int verbose; /**< 1 to enable verbose output. */
  int verbose_set;
  int outscop; /**< 1 to print the scop with dependences. */
  int outscop_set;
  int autocorrect; /**< 1 to correct violations. fullcheck is set to 1 and 
                     * the -test is required.
                    */
  int autocorrect_set;
  /* UNDOCUMENTED OPTIONS FOR THE AUTHOR ONLY */
  int view;      /**< 1 to call dot and gv to visualize the graphs. */
  int view_set;
  int structure; /**< 1 to print internal dependence structure. */
  int structure_set;
  int prune_dups; /**< 1 to use experimental dependence pruning algorithm. */
  int prune_dups_set;
};

typedef struct osl_candloptions  osl_candloptions_t;
typedef struct osl_candloptions* osl_candloptions_p;
/*+***************************************************************************
 *                          Structure display function                       *
 *****************************************************************************/
void osl_candloptions_idump(FILE *, osl_candloptions_p, int);
void osl_candloptions_dump(FILE *, osl_candloptions_p);
char* osl_candloptions_sprint(osl_candloptions_p);


/*****************************************************************************
 *                               Reading function                            *
 *****************************************************************************/
osl_candloptions_p osl_candloptions_sread(char **);

/*+***************************************************************************
 *                    Memory allocation/deallocation function                *
 *****************************************************************************/
osl_candloptions_p osl_candloptions_malloc();
void osl_candloptions_free(osl_candloptions_p);


/*+***************************************************************************
 *                            Processing functions                           *
 *****************************************************************************/
osl_candloptions_p osl_candloptions_clone(osl_candloptions_p);
int osl_candloptions_equal(osl_candloptions_p, osl_candloptions_p);
osl_interface_p   osl_candloptions_interface();


# if defined(__cplusplus)
  }
# endif

#endif /* define OSL_CANDLOPTIONS_H */
