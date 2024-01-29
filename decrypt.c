#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_screen()
{
    printf("\033[H\033[J");
}

void encrypt_phrase(char *str)
{
    char chr_lst[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!,";
    char cry_lst[] = "qzwxecrvbtynumisokplhjgfdaTQZWXRVCBYNUMISOKPLHJGFDAE!,";
    int len = strlen(str);
    char *new_str = (char *)malloc(len + 1);
    if (!new_str)
        return ;
    memset(new_str, 0, len + 1);
    int i = 0;
    int x;

    while (i < len)
    {
            if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 33 && str[i] <= 64))
            {
                x = 0;
                while (chr_lst[x])
                {
                    new_str[i] = chr_lst[x];
                    new_str[i + 1] = '\0';
                    printf("Encrypt Running...\n");
                    printf("%s\n", new_str);
                   if (i < len - 1 || new_str[i] != str[i])
                    clear_screen();
                    usleep(20000);
                    if (new_str[i] == str[i])
                    {
                        new_str[i] = cry_lst[x];
                        break;
                    }
                    x++;
                }
            }
            else if ((str[i] >= 9 && str[i] <= 13) || str[i] >= 32)
            {
                 new_str[i] = ' ';
                 printf("%s\n", new_str);
                 if (i < len - 1 )
                    clear_screen();
            }
            else
            {
                new_str[i] = str[i];
                printf("%s\n", new_str);
                if (i < len - 1 )
                    clear_screen();
            }
            i++;
    }
    free(new_str);
}

void decrypt_phrase(char *str)
{
    char chr_lst[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!,?@#$&*()_+=-{}[];:\'";
    char cry_lst[] = "qzwxecrvbtynumisokplhjgfdaTQZWXRVCBYNUMISOKPLHJGFDAE!,?@#$&*()_+=-{}[];:\'";
    int len = strlen(str);
    char *new_str = (char *)malloc(len + 1);
    if (!new_str)
        return ;
    memset(new_str, 0, len + 1);
    int i = 0;
    int x;

    while (i < len)
    {
            if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 33 && str[i] <= 64))
            {
                x = 0;
                while (chr_lst[x])
                {
                    new_str[i] = cry_lst[x];
                    new_str[i + 1] = '\0';
                    printf("Decrypt Running...\n");
                    printf("%s\n", new_str);
                   if (i < len - 1 || new_str[i] != str[i])
                    clear_screen();
                    usleep(20000);
                    if (new_str[i] == str[i])
                    {
                        new_str[i] = chr_lst[x];
                        break;
                    }
                    x++;
                }
            }
            else if ((str[i] >= 9 && str[i] <= 13) || str[i] >= 32)
            {
                 new_str[i] = ' ';
                 printf("%s\n", new_str);
                 if (i < len - 1 || new_str[i] != str[i])
                    clear_screen();
            }
            else
            {
                new_str[i] = str[i];
                printf("%s\n", new_str);
                if (i < len - 1 || new_str[i] != str[i])
                    clear_screen();
            }
            i++;
    }
    free(new_str);
}

int main(int argc, char *argv[])
{
    if(argc > 1)
    {
        if (argv[1][0] == 'e')
            encrypt_phrase(argv[2]);
        else if (argv[1][0] == 'd')
            decrypt_phrase(argv[2]);
    }
    else
        printf ("Invalid Input (1st-'d'(for decrypting) OR 'e'(for encryting) 2nd-'String')\n");
    return (0);
}
