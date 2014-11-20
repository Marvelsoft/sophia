#ifndef SI_PLANNER_H_
#define SI_PLANNER_H_

/*
 * sophia database
 * sphia.org
 *
 * Copyright (c) Dmitry Simonenko
 * BSD License
*/

typedef struct siplanner siplanner;
typedef struct siplan siplan;

struct siplanner {
	srrb branch;
	srrb compact;
};

/* plan */
#define SI_BRANCH        1
#define SI_COMPACT       2

/* condition */
#define SI_BRANCH_FORCE  1
#define SI_BRANCH_SIZE   2
#define SI_BRANCH_LSN    4
#define SI_COMPACT_FORCE 1
#define SI_COMPACT_DEEP  2

struct siplan {
	int plan;
	int condition;
	uint64_t a; /* deep, size */
	uint64_t b; /* timediff, lsn */
	sinode *node;
};

int si_plannerinit(siplanner*);
int si_plannertrace(siplan*, srtrace*);
int si_plannerupdate(siplanner*, int, sinode*);
int si_plannerremove(siplanner*, int, sinode*);
sinode *si_planner(siplanner*, siplan*);

#endif
