#include "push_swap.c"

void swap(T_Stack *s)
{
	T_Node *aux;
	
	aux = (*s)->next;
	aux->next->before = (*s);
	(*s)->next = aux->next;
	aux->next = (*s);
	aux->before = NULL;
	(*s)->before = aux;
	(*s) = aux;
}

void push(T_Stack *s1, T_Stack *s2)
{
	T_Node *aux;

	aux = (*s1);
	(*s1) = aux->next;
	(*s1)->before = NULL;
	aux->next = (*s2);
	(*s2) = aux;
	if (aux->next)
		aux->next->before = aux;
}

void rotate(T_Stack *s)
{
	T_Node *aux;
	T_Node *iter;

	aux = (*s);
	aux->next->before = NULL;
	(*s) = aux->next;
	aux->next = NULL;
	iter = (*s);
	while (iter->next)
		iter = iter->next;
	aux->before = iter;
	iter->next = aux;
}

void reverse_rotate(T_Stack *s)
{
	T_Node *aux;

	aux = (*s);
	while (aux->next)
		aux = aux->next;
	aux->before->next = NULL;
	aux->before = NULL;
	(*s)->before = aux;
	aux->next = (*s);
	(*s) = aux;
}
