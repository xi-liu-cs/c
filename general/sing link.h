#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buf_len = 256;

typedef struct node
{
    int val;
    struct node * next;
}node;

node * node_init(int val)
{
    node * n = malloc(sizeof(node));
    n->val = val;
    n->next = NULL;
    return n;
}

node * list_init_w()
{// input separated by whitespace 
    char str[buf_len]; // 2^8
    node * head = NULL, * prev_node = NULL, * cur_node = NULL;
    printf("enter node values separated by ' ':\n");
    // scanf("%s", str); // scanf scans for a string until any whitespace
    fgets(str, sizeof(str), stdin); // read until a newline
    strcat(str, " ");
    int i = 0;
    int prev_i = 0;
    int str_len = strlen(str);
    while(*(str + i) == ' ')
    {
        i++;
    }
    while(i < str_len
    && *(str + i))
    {
        char buf[buf_len];
        if(*(str + i) == ' ')
        {
            int len = i - prev_i;
            memcpy(buf, str + prev_i, len);
            *(buf + len) = '\0';
            prev_i = i + 1;

            int val = atoi(buf);
            if(!head)
            {
                head = node_init(val);
                prev_node = head;
            }
            else
            {
                cur_node = node_init(val);
                prev_node->next = cur_node;
                prev_node = cur_node;
            }
        }
        i++;
    }
    return head;
}

node * list_init_l()
{//input separated by newline
    int len;
    printf("enter list length: \n");
    scanf("%d", &len);
    node * head = NULL, * prev = NULL, * cur = NULL;
    for(int i = 0; i < len; i++)
    {
        int val;
        printf("node%d->val = ", i);
        scanf("%d", &val);
        if(!head)
        {
            head = node_init(val);
            prev = head;
        }
        else
        {
            cur = node_init(val);
            prev->next = cur;
            prev = cur;
        }
    }
    return head;
}

void print_list(node * head)
{
    if(!head)
        printf("head is null\n");
    while(head)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}
