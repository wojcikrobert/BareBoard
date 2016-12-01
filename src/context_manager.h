#ifndef CONTEXT_MANAGER_H
#define CONTEXT_MANAGER_H

	typedef struct {
		char R1;
		char R2;
		char R3;
	} CONTEXT;


	CONTEXT ctx[255];

void SaveContext(void);

#endif
