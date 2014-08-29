
    /*+-----------------------------------------------------------------**
     **                       OpenScop Library                          **
     **-----------------------------------------------------------------**
     **                     extensions/symbol_rank.h                   **
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


#ifndef OSL_SYMBOL_RANK_H
# define OSL_SYMBOL_RANK_H

# include <stdio.h>
# include <osl/interface.h>

# if defined(__cplusplus)
extern "C"
  {
# endif


# define OSL_URI_SYMBOL_SCOPE "symbol_rank"


/**
 * The osl_symbol_rank structure contains information about the a variable's
 * rank.
 * For an Iterator, the rank contains the iterator's depth
 * For a Parameter, the rank contains the parameter's position
 */
struct osl_symbol_rank{
  int   rank;       /**< Symbol rank (loop depth or parameter pos) */
};
typedef struct osl_symbol_rank  osl_symbol_rank_t;
typedef struct osl_symbol_rank* osl_symbol_rank_p;


/*+***************************************************************************
 *                          Structure display function                       *
 *****************************************************************************/
void              osl_symbol_rank_idump(FILE*, osl_symbol_rank_p, int);
void              osl_symbol_rank_dump(FILE*, osl_symbol_rank_p);
char*             osl_symbol_rank_sprint(osl_symbol_rank_p);


/*****************************************************************************
 *                               Reading function                            *
 *****************************************************************************/
osl_symbol_rank_p osl_symbol_rank_sread(char**);


/*+***************************************************************************
 *                    Memory allocation/deallocation function                *
 *****************************************************************************/
osl_symbol_rank_p osl_symbol_rank_malloc();
void              osl_symbol_rank_free(osl_symbol_rank_p);


/*+***************************************************************************
 *                            Processing functions                           *
 *****************************************************************************/
osl_symbol_rank_p osl_symbol_rank_clone(osl_symbol_rank_p);
int               osl_symbol_rank_equal(osl_symbol_rank_p, osl_symbol_rank_p);
osl_interface_p   osl_symbol_rank_interface();
int               osl_symbol_rank_get_rank(osl_symbol_rank_p);
void              osl_symbol_rank_set_rank(osl_symbol_rank_p, int);


# if defined(__cplusplus)
  }
# endif

#endif /* define OSL_SYMBOL_RANK_H */
