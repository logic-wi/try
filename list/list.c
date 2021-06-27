#include <node.h>
#include <stdlib.h>
#include <stdio.h>
// typedef struct _node
// {
//     int value;
//     struct _node *next;
// } Node;
typedef struct _list
{
    Node *head;
} List;
void print(List *pList);
Node *add(List *pList, int number);
int main()
{
    List list;
    int number();
    list.head = NULL;
    do
    {
        scanf("%d", &number);
        if (number != -1)
        {
            list.head = add(&list, number);
        }
    } while (number != -1);
    print(&list);
    scanf("%d", &number);
    //搜索链表
    Node *p;
    int isFound;
    for (p = list.head; p; p = p->next)
    {
        if (p->value == number)
        {
            printf("找到了\n");
            isFound = 1;
            break;
        }
    }
    if (!isFound)
        printf("没找到\n");
    //删除链表中的节点
    Node *q;
    for (q = NULL, p = list.head; p; q = p, p = p->next)
    {
        if (p->value == number)
        {
            if (q)
            {
                q->next = p->next;
            }
            else
            {
                list.head = p->next;
            }
            free(p);
            break;
        }
    }

    //删除整个链表
    for (p = list.head; p; p = q)
    {
        q = p->next;
        free(p);
    }

    return 0;
}
Node *add(List *pList, int number)
{
    //加入链表
    Node *p = (Node *)malloc(sizeof(Node)); //创造一个节点
    p->value = number;                      //存储数据
    p->next = NULL;                         //初始化下一个节点(令其在链表中的节点排序数为零)
    //找到链表
    Node *last = pList->head; //令上一个节点为头(为NULL)
    if (last)
    {
        while (last->next)
        {
            last = last->next;
        }
        //attch(写入，填写)
        last->next = p;
    }
    else
    {
        pList = p;
    }
}
void print(List *pList)
{
    Node *p;
    for (p = pList->head; p; p = p->next)
    {
        printf("%d\t", p->value);
    }
}

/*
_FILE_ 文件路径
_LINE_ 当前行数
_DATE_ 日期
_TIME_ 时间
*/