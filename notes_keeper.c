#include <stdio.h>
#include <stdlib.h>
typedef struct notebook
{
    FILE *p;
    char s[15];
    struct notebook *next;
} book;
book *b;
void first()
{
    char note[3000];
    b = (book *)malloc(sizeof(book));
    printf("\nNAME OF FILE:");
    scanf("%s", b->s);
    b->p = fopen(b->s, "w");
    printf("\n------start--------\n");
    getchar();
    gets(note);
    fprintf(b->p, note);
    fclose(b->p);
    b->next = NULL;
}
book *write(book *h)
{
    book *ptr = h;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    char note[3000];
    book *new = (book *)malloc(sizeof(book));
    printf("\nNAME OF FILE:");
    scanf("%s", new->s);
    new->p = fopen(new->s, "w");
    printf("\n------start--------\n");
    getchar();
    gets(note);
    fprintf(new->p, note);
    fclose(new->p);
    new->next = NULL;
    ptr->next = new;
    return ptr;
}
void add()
{
    printf("nknknsg");
}
void search()
{
    printf("nknknsg");
}
int open(book *p)
{
    int i = 1;
    printf("\nBELOW IS LIST OF FILES THAT HAS BEEN CREATED:\n");
    while (p != NULL)
    {
        printf("\n%d----->%s\n", i, p->s);
        p = p->next;
        i++;// incomplete
    }
    return 0;
}
void delete()
{
    book * p;
    p=(book *)malloc(sizeof(book));
    p=b;
    int choice;
    open(b);
    printf("%d", &choice);
    while (choice-1 >= 0)
    {
        if (choice == 0 && p!=NULL)
        {
            free(p);
            printf("NO FILES REMAINING");
        }
        else
        {
            p=p->next;
            choice--;
        }
    }
}
void create()
{
    char d;
    printf("\na.FIRST FILE:");
    printf("\nb.WANT TO WRITE");
    printf("\nc.ADD IMAGE");
    printf("\nd.SEARCH");
    printf("\nSELECT AN OPTION:");
    scanf(" %c", &d);
    switch (d)
    {
    case 'a':
        first();
        break;
    case 'b':
        b = write(b);
        break;
    case 'c':
        add();
        break;
    case 'd':
        search();
        break;
    default:
        break;
    }
}
int main()
{
    int n, c = 0;
    do
    {
        printf("1.CREATE NEW");
        printf("\n2.OPEN A FILE");
        printf("\n3.DELETE");
        printf("\n4.EXIT");
        printf("\nENTER YOUR CHOICE:");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            create();
            break;
        case 2:
            open(b);
            break;
        case 3:
            delete ();
            break;
        case 4:
            exit(0);
        default:
            printf("\nWRONG CHOICE");
            break;
        }
        c++;
        if (c == 6 || c == 5)
        {
            printf("\nPRESS 4 TO EXIT");
        }
    } while (1);
    return 0;
}