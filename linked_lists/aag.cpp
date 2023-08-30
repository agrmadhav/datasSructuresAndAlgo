#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
} *first = NULL, *second = NULL, *third = NULL;

void create1(int A[], int n)
{
    int i;
    struct node *t, *last;

    first = new node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void create2(int A[], int n)
{
    int i;
    struct node *t, *last;

    second = new node;
    second->data = A[0];
    second->next = NULL;
    last = second;

    for (int i = 1; i < n; i++)
    {
        t = new node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct node *p)
{
    while (p != 0)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void rec_display(struct node *p)
{
    if (p != NULL)
    {
        cout << p->data;
        rec_display(p->next);
    }
}

void rec_rev_display(struct node *p)
{
    if (p != NULL)
    {
        rec_rev_display(p->next);
        cout << p->data << " ";
    }
}
int count(struct node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

int rec_count(struct node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        return rec_count(p->next) + 1;
    }
}

int sum(struct node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}

int rec_sum(struct node *p)
{
    if (p == 0)
    {
        return 0;
    }
    else
    {
        return rec_sum(p->next) + p->data;
    }
}

int max(struct node *p)
{
    int max = INT32_MIN;
    while (p != NULL)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int rec_max(struct node *p)
{
    int x = 0;
    if (p == 0)
    {
        return INT32_MIN;
    }
    else
    {
        x = max(p->next);
        if (x > p->data)
        {
            return x;
        }
        else
        {
            return p->data;
        }
    }
}

struct node *search(struct node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

struct node *rec_search(struct node *p, int key)
{
    if (p == NULL)
    {
        return NULL;
    }
    if (key == p->data)
    {
        return p;
    }
    return rec_search(p->next, key);
}

struct node *improve_search(struct node *p, int key)
{
    struct node *q = NULL;
    while (p != NULL)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;

            return first;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

void insert(struct node *p, int index, int x)
{
    if (index < 0 || index > count(p))
    {
        return;
    }

    struct node *t = new node;
    t->data = x;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void insert_last(struct node *p, int x) // may be wrong
{
    struct node *last = NULL;
    struct node *t = new node;

    t->data = x;
    t->next = NULL;

    if (first == NULL)
    {
        first = last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}

void insert_sorted(struct node *p, int x)
{
    struct node *t, *q = NULL;
    t = new node;
    t->data = x;
    t->next = NULL;

    if (first == NULL) // if linked list is empty
    {
        first = t;
    }
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int Delete(struct node *p, int index)
{
    struct node *q;
    int x = -1;
    if (index < 1 || index > count(p))
    {
        return -1;
    }

    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        delete q;
        return x;
    }

    for (int i = 0; i < index - 1; i++)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    x = p->data;
    delete p;
    return x;
}

int check_sorted(struct node *p)
{
    int x = INT32_MIN;

    while (p != NULL)
    {
        if (p->data < x)
        {
            return 0;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
}

void remove_duplicates(struct node *p)
{
    struct node *q = p->next;
    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

void reverse_arr(struct node *p)
{
    int *A;
    int i = 0;
    struct node *q;
    A = new int[count(p)];
    while (q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while (q != NULL)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

void reverse_sliding_pointers(struct node *p)
{
    struct node *q = NULL, *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}
void recursive_reverse(struct node *q, struct node *p)
{
    if (p != NULL)
    {
        recursive_reverse(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

void concatenate(struct node *p, struct node *q)
{
    third = p;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
}

void merge(struct node *p, struct node *q)
{
    struct node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p != NULL)
    {
        last->next = p;
    }
    else
    {
        last->next = q;
    }
}

int is_loop(struct node *f)
{
    struct node *p, *q;
    p = q = f;

    do
    {
        p = p->next;
        q = q->next;
        if (q != NULL)
        {
            q = q->next;
        }
    } while (p && q && p != q);

    if (p == q)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int A[] = {3, 5, 7, 9, 11};
    // int B[] = {2, 4, 6, 8, 10};

    create1(A, 5);
    // create2(B, 5);
    display(first);

    // struct node *t1, *t2;
    // t1 = first->next->next;
    // t2 = first->next->next->next->next;
    // t2->next = t1;
    return 0;
}