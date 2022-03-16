#include <stdio.h>
#include <stdlib.h>

typedef struct _tree
{
    struct _tree *left;
    struct _tree *right;
    char    item;
} tree;

tree    *newnode(char s)
{
    tree *node;

    node = malloc(sizeof(tree));
    node->left = 0;
    node->right = 0;
    node->item = s;
    return (node);
}

tree *search_node(tree *node, char c)
{

    if (node)
    {
        if (node->item == c)
            return (node);
        else
        {
            tree *tmp;
            tmp = search_node(node->left, c);
            if (tmp)
                return tmp;
            return search_node(node->right, c);
        }
    }
    return 0;
}

void    insert_node(tree *node, char c, char left, char right)
{
    node->item = c;
    if (left != '.')
        node ->left = newnode(left);
    if (right != '.')
        node->right = newnode(right);
}

void    prefix(tree *node)
{
    if (!node)
        return;
    printf("%c", node->item);
    prefix(node->left);
    prefix(node->right);
}
void    infix(tree *node)
{
    if (!node)
        return;
    infix(node->left);
    printf("%c", node->item);
    infix(node->right);
}

void    suffix(tree *node)
{
    if (!node)
    return;
    suffix(node->left);
    suffix(node->right);
    printf("%c", node->item);
}

int main()
{
    tree *node;
    tree *tmp;
    int cnt;

    node = newnode(0);
    scanf("%d", &cnt);
    getchar();
    while (cnt--)
    {
    char c, left, right;
        scanf("%c %c %c", &c, &left, &right);
        getchar();
        tmp = search_node(node, c);
        if (tmp)
            insert_node(tmp, c, left, right);
        else
            insert_node(node, c, left, right);
    }
    prefix(node);
    printf("\n");
    infix(node);
    printf("\n");
    suffix(node);
    return 0;
}
