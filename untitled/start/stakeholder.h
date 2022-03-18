
#ifndef UNTITLED_START_STAKEHOLDER_H_
#define UNTITLED_START_STAKEHOLDER_H_
#include <stdio.h>
typedef struct stakeholder stakeholder;
struct  stakeholder{
    char* role;
    char* name;
    char influence_lvl;
    char interest_lvl;
};
// initialization
int start(char* name, size_t count);
stakeholder* read_data(char* name, stakeholder * stakeholders, size_t count);
char* read_string(FILE* file);
stakeholder read_stakeholder(FILE *file);
// client_part
void print_stakeholders(stakeholder * stakeholders, size_t count);
void print_stakeholder(stakeholder curr_stake);
stakeholder info_select(char* name);
char* info_read(char* buf, FILE* file);
int find_stakeholders(stakeholder * Stakeholders, stakeholder criter, size_t count);
#endif  // UNTITLED_START_STAKEHOLDER_H
