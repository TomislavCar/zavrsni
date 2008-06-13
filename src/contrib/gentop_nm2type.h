/*
 * $Id$
 * 
 *                This source code is part of
 * 
 *                 G   R   O   M   A   C   S
 * 
 *          GROningen MAchine for Chemical Simulations
 * 
 *                        VERSION 3.2.0
 * Written by David van der Spoel, Erik Lindahl, Berk Hess, and others.
 * Copyright (c) 1991-2000, University of Groningen, The Netherlands.
 * Copyright (c) 2001-2004, The GROMACS development team,
 * check out http://www.gromacs.org for more information.

 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * If you want to redistribute modifications, please consider that
 * scientific software is very special. Version control is crucial -
 * bugs must be traceable. We will be happy to consider code for
 * inclusion in the official distribution, but derived work must not
 * be called official GROMACS. Details are found in the README & COPYING
 * files - if they are missing, get the official version at www.gromacs.org.
 * 
 * To help us fund GROMACS development, we humbly ask that you cite
 * the papers on the package - you can find them in the top README file.
 * 
 * For more info, check our website at http://www.gromacs.org
 * 
 * And Hey:
 * Gallium Rubidium Oxygen Manganese Argon Carbon Silicon
 */

#ifndef _gentop_nm2type_h
#define _gentop_nm2type_h
	
#include <stdio.h>
#include "grompp.h"
#include "gpp_atomtype.h"
	
typedef struct gentop_nm2type *gentop_nm2t;

extern gentop_nm2t rd_nm2type(char *ff,void *atomprop);
/* Read the name 2 type database. nnm is the number of entries 
 * ff is the force field.
 */

extern void dump_nm2type(FILE *fp,gentop_nm2t nm2t);
/* Dump the database for debugging. Can be reread by the program */

extern int nm2type(gentop_nm2t nm2t,t_symtab *tab,t_atoms *atoms,
		   t_atomtype atype,int *nbonds,t_params *bond,
		   void *atomprop);
/* Try to determine the atomtype (force field dependent) for the atoms 
 * with help of the bond list 
 */
extern bool is_bond(gentop_nm2t nmt,t_atoms *atoms,int ai,int aj,
		    real blen,real tol);
#endif