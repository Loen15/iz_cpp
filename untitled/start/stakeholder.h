
#ifndef UNTITLED_STAKEHOLDER_H
#define UNTITLED_STAKEHOLDER_H
#include <stdio.h>
typedef struct stakeholder stakeholder;
struct  stakeholder{
    char* role;
    char* name;
    char influence_lvl;
    char interest_lvl;
};
int start(char* name, size_t count);
stakeholder* read_data(char* name, stakeholder * stakeholders, size_t count);
char* read_string(FILE* file);
stakeholder read_stakeholder(FILE *file);
void print_stakeholders(stakeholder * stakeholders, size_t count);
void print_stakeholder(stakeholder curr_stake);
stakeholder info_select();
char* info_read(char* buf);
int find_stakeholders(stakeholder * Stakeholders, stakeholder criter, size_t count);
#endif //UNTITLED_STAKEHOLDER_H
