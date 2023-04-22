#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

typedef struct s_node
{
	int				data; //dato effettivo del nodo
	struct s_node	*next;
}	t_node;

static int	ft_atoi(const char *str)
{
    int	res;
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		res = (str[i++] - '0') + (res * 10);
	return (res * sign);
}

// stampa dei nodi
static void	print_list(t_node *node)
{
	while (node != NULL)
	{
		if (node->next != NULL)
			printf("|%d|->",node->data);
		else
			printf("|%d|",node->data);
		node = node->next;
	}

}
// funzioni per la gestione delle mie linked list:
// funzione per inserire un nodo nella prima posizione della nostra lista
static void	list_insert(t_node **first, int data)
{
	t_node	*new;
	printf("data ricevuto valore: %d\n",data);
	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
	{
		printf("Qualcosa e' andato storto problemi di allocazione\n");
		free(new);
		exit(0);
	}
	new->data = data;
	new->next = NULL;  // Imposta il valore di next a NULL se il nodo è il primo
	if (*first != NULL)
	{
		new->next = *first;
	}
	//visto che la variabile new è stata creata qui
	//per fare in modo che che non perdiamo il suo valore e contenuto
	//dobbiamo darle il ruolo di nuova testa cosìcché non rischiamo di perdere
	//il lavoro che abbiamo fatto
	// se prima avevo un nodo la vecchia testa sarà in next
	//quindi anche se la testa cambia il valore nella lista rimane
	// perché è in next
	// abbiamo usato due ** perché abbiamo passato per riferimento il puntatore alla testa della nostra lista
	// e passandolo per riferimento lo possiamo modificare
	// visto che prendiamo il suo indirizzo
	*first = new;
	printf("The node was created succsesfully\n");
	printf("Value %d\n", new->data);
}

// nuova funzione per gestire la stampa dei nodi
// è una versione semplificata e migliore di quella implementata
// precedentemente
static void	list_display(t_node *p)
{
	printf("\n");
	while (p != NULL)
	{
		printf("|%d|->", p->data);
		p = p->next;
	}
	printf("NULL");
}

// funzione per cercare un valore numerico all'interno della nostra lista
static int	find_data_list(t_node **first, int find)
{
	// creiamo un valore di tipo t_list per
	// scorrere la nostra lista partendo dal primo valore
	t_node	*current;

	current = *first;
	while (current != NULL)
	{
		if (current->data == find)
			return (1);
		current = current->next;
	}
	return (0);
}

//funzione per cancellare un nodo nella mia lista
static void	list_delete(t_node **first, int key)
{
	t_node	*tmp;
	t_node	*prev;

	tmp = *first;
	prev = NULL;
	//sto eliminando la testa (caso in cui la key è nel contenuto di first)
	if (tmp != NULL && tmp->data == key)
	{
		*first = tmp->next; //cambio testa della lista
		free(tmp);
	}

	//caso in cui key si trova da qualche parte nella lista
	//ricerco il nodo da eliminare tenendo traccia del precedente (per poter modificare prev->next)
	while (tmp != NULL && tmp->data != key)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	//caso 1: non ho trovato la key quindi non elimino nulla
	//il controllo è semplice visto che alla fine del while sopra
	//se non ho trovato nulla tmp varrà NULL
	if (tmp == NULL)
	{
		printf("Nessun nodo corrisponde al valore cercato\n");
		return ;
	}
	//caso 2: ho trovato il valore di conseguenza lo devo eliminare
	//e settare il nodo precedente e successivo in modo che siano collegati
	//visto che quello corrente è stato eliminato
	prev->next = tmp->next;
	free(tmp);
}

// MAIN FOR THE NEW FUNCTIONS
int	main(int ac, char **av)
{
	t_node	*node;
	int		i;

	i = -1;
	srand(time(NULL));
	node = NULL;
	while (++i < 6)
		list_insert(&node, rand() % 501);
	list_display(node);
	return (0);

}

// BASIC MAIN
/*
int	main(void)
{
	// inizializzo i nodi
	t_node	*head;
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;

	srand(time(NULL));
	node1 = NULL;
	node2 = NULL;
	node3 = NULL;

	//Alloco la memoria
	node1 = malloc(sizeof(t_node));
	node2 = malloc(sizeofi (t_node));
	node3 = malloc(sizeof(t_node));

	//assegno a i nodi numeri casuali
	node1->data = rand() % 501;
	node2->data = rand() % 501;
	node3->data = rand() % 501;

	//collego tra di loro i nodi
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	//collego head al primo nodo
	head = node1; //da capire come mai qua non abbiamo puntato all'indirizzo ma proprio abbiamo fatto diventare head come node1

	print_list(node1);
	return (0);
}
*/
