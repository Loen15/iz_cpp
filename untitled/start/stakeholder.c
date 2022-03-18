#include <stdio.h>
#include <stdlib.h>
#include "stakeholder.h"

int start(char* name, size_t count)
{
    stakeholder* stakeholders=NULL;
    stakeholders= read_data(name, stakeholders, count);
    if(stakeholders == NULL)
        return 0;
    print_stakeholders(stakeholders, count);
    stakeholder criter;
    criter= info_select();
    int buf = find_stakeholders(stakeholders, criter, count);
    free(stakeholders);
    }
stakeholder* read_data(char* name, stakeholder * stakeholders, size_t count)
{
    FILE *initial_data;
    initial_data = fopen(name, "r");
    if (initial_data == NULL)
    {
        printf("Don't open file!\n");
        return NULL;
    }
    stakeholders=malloc(sizeof(stakeholder) * count);
    for(int i=0;i<count;i++) {
        stakeholders[i] = read_stakeholder(initial_data);
        }
    fclose(initial_data);
    return stakeholders;
}
char* read_string(FILE *file)
{
    char* str;
    char buff;
    size_t length =1;
    str=malloc(length* sizeof(char));
    str[0]='\0';
    buff=(char)fgetc(file);

    while (buff !='\n')
    {
        str=realloc(str,sizeof(char)*(++length));
        str[length-2]=buff;
        str[length-1]='\0';
        buff=(char)fgetc(file);
    }

    return str;
}
stakeholder read_stakeholder(FILE *file)
{
    stakeholder buf_stake;
    char* str;
    str= read_string(file);
    buf_stake.role=malloc(sizeof(str));
    buf_stake.role=str;
    str= read_string(file);
    buf_stake.name=malloc(sizeof(str));
    buf_stake.name=str;
    free(str);
    buf_stake.influence_lvl=(char)fgetc(file);
    while (fgetc(file) !='\n'){}
    buf_stake.interest_lvl=(char)fgetc(file);
    while (fgetc(file) !='\n'){}
    return buf_stake;
}
void print_stakeholders(stakeholder * stakeholders, size_t count)
{
    for (int i=0;i<count;i++)
    {
        printf("stakeholder %d\n", i+1);
        print_stakeholder(stakeholders[i]);
    }

}
void print_stakeholder(stakeholder curr_stake)
{
    printf("\trole: %s !\n", curr_stake.role);
    printf("\tname: %s !\n", curr_stake.name);
    printf("\tInfluence: %c !\n", curr_stake.influence_lvl);
    printf("\tInterest: %c !\n", curr_stake.interest_lvl);

}
stakeholder info_select()
{
    stakeholder criter={NULL, NULL};
    char *buf= NULL;
    int point=0;
    size_t length;
    while (point!=54)
    {
        printf("Select required criterion point\n1-role\n2-name\n3-Influence\n4-Interest\n5-Print entered criteria\n6-Continue\n");
        scanf("\n");
        point=getchar();
        while (point!=49 && point!=50 && point!=51 && point!=52 && point!=53 && point!=54)
        {
            printf("Incorrect data %d\n",point);
            scanf("\n");
            point=getchar();
        }

        switch (point) {
            case 49:
                printf("Enter a role of stakeholder\n");
                buf= info_read(buf);
                for(length=0;buf[length]!='\0';length++){}
                criter.role= malloc(length + 1);
                for(int i=0;i<length+1;i++)
                    criter.role[i]=buf[i];
                break;
            case 50:
                printf("Enter a name of stakeholder\n");
                buf= info_read(buf);
                for(length=0;buf[length]!='\0';length++){}
                criter.name= malloc(length + 1);
                for(int i=0;i<length+1;i++)
                    criter.name[i]=buf[i];
                break;
            case 51:
                printf("Enter a influence of stakeholder (High, Medium or Low)\n");
                do {
                   printf(" in uppercase\n");
                   scanf("%ms",&buf);
                } while ((buf[0]!='H')&&(buf[0]!='M')&&(buf[0]!='L'));

                criter.influence_lvl=buf[0];
                break;
            case 52:
                printf("Enter a interest of stakeholder (High, Medium or Low)");
                do {
                    printf(" in uppercase\n");
                    scanf("%ms",&buf);
                } while ((buf[0]!='H')&&(buf[0]!='M')&&(buf[0]!='L'));

                criter.interest_lvl=buf[0];
                break;
            case 53:
                print_stakeholder(criter);
                break;
            default:
                break;
        }
    }
    free(buf);

    return criter;
}
char* info_read(char* buf)
{
    size_t length=20;
    buf= malloc(sizeof(char)*length);
    int i=0;
    int ch;
    scanf("\n");
    ch=getchar();
    buf[i]=(char)ch;
    i++;
    while ((ch=getchar())!='\n')
    {
        if (ch==' ')
        {
            buf[i] =' ';
        }
        else
        {
            buf[i] = (char) ch;
        }
        i++;
        if(i==(length-1))
        {
            length+=20;
            buf= realloc(buf,length);
        }
    }
    buf[i]='\0';
    return buf;
}
int find_stakeholders(stakeholder * Stakeholders, stakeholder criter, size_t count)
{
    int relevant[4][count];
    for(int i=0;i<count;i++)
    {
        if(criter.role != NULL)
        {

            int j;
            for(j=0; Stakeholders[i].role[j] != '\0' && Stakeholders[i].role[j] == criter.role[j]; j++){
            }
            if (Stakeholders[i].role[j] == '\0')
                relevant[0][i] = 0;
            else
                relevant[0][i] = 1;
        }
        if(criter.name != NULL)
        {
            int j;
            for(j=0; Stakeholders[i].name[j] != '\0' && Stakeholders[i].name[j] == criter.name[j]; j++){
            }
            if (Stakeholders[i].name[j] == '\0')
                relevant[1][i] = 0;
            else
                relevant[1][i] = 1;
        }
        if ((criter.influence_lvl == 'H') || (criter.influence_lvl == 'M') || (criter.influence_lvl == 'L'))
        {
            if (Stakeholders[i].influence_lvl == criter.influence_lvl)
                relevant[2][i]=0;
            else
                relevant[2][i]=1;
        }
        if ((criter.interest_lvl == 'H') || (criter.interest_lvl == 'M') || (criter.interest_lvl == 'L'))
        {
            if (Stakeholders[i].interest_lvl == criter.interest_lvl)
                relevant[3][i]=0;
            else
                relevant[3][i]=1;
        }
    }
    int relev[count];
    for(int i=0;i<count;i++)
    {
        if((relevant[0][i]!=1)&&(relevant[1][i]!=1)&&(relevant[2][i]!=1)&&(relevant[3][i]!=1))
            relev[i]=1;
        else
            relev[i]=0;
    }
    char key =0;
    for(int i=0;i<count;i++)
    {
        if (relev[i]==1)
        {
            key=1;
            printf("stakeholder %d\n", i+1);
            print_stakeholder(Stakeholders[i]);
        }
    }
    if (key==0)
        printf("there are no relevant stakeholders");
    return 1;
}