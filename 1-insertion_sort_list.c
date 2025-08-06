#include "sort.h"

/**
 * swap - swap a node with another
 * @node: a node to swap
 * @next: with the next one
 * @list: pointer to the head of the list
 *
 * Return:
 */
void swap(listint_t *node, listint_t *next, listint_t **list)
{
	/*swap fait avancer node et reculer next*/
	/*next sera à la place de node et inversement*/
	listint_t *temp_prev;

	temp_prev = node->prev;
	if (node->prev != NULL)/*s'il y a bien un noeud qui précède node (on est pas à la tête)*/
		node->prev->next = next;/*ce noeud précédent devra pointer vers next à la fin du swap*/
	else
		*list = next;/*si on est à la tête, alors il faut que next soit la nouvelle tête de liste*/
	if (next->next != NULL)/*si next est suivi d'un autre noeud (next n'est pas la tail)*/
		next->next->prev = node;/*le champ prev de ce noeud qui suit next devra pointer vers node*/
	node->next = next->next;/*node remplacera next, il prend ses valeurs de champs next*/
	node->prev = next;/*next le précèdera, puisqu'il aura reculé*/
	next->next = node;/*next aura reculé, le noeud qui le suivra sera node qui aura avancé*/
	next->prev = temp_prev;/*le prev de next sera anciennement le prev de node*/
}

/**
 * insertion_sort_list - sort data in a
 * doubly linked list
 * @list: pointer to the head of the list
 *
 * Return:
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head_f = *list;/*on prend une tête qui va en avant*/
	listint_t *head_b;/*une qui ira en arrière*/
	listint_t *next;/*le noeud suivant d'une head_f*/
	listint_t *prev;/*le noeud précédant d'une head_b*/
	/*ce tri fait : quand le noeud lu est plus grand, l'échanger avec le suivant.
	Puis, le noeud qui a reculé, le comparer au précédent.
	Si le précédent est plus grand, faire reculer le neoud qui a reculé en premier lieu.
	On le recompare au noeud qui le précède.
	Quand le noeud qui recule est plus grand que celui qui le précède, il a trouvé sa place.
	On reprends à partir de la tête qui avance, pour la comparer au noeud qui suit...
	Avoir deux têtes me permet de garder la tête avant en place. 
	Et garder un pointeur sur le noeud que je vais faire reculer itérativement
	jusqu'à ce qu'il soit plus grand que celui qui le précède. (fiou)
	*/

	while (head_f->next != NULL)
	{
		next = head_f->next;
		if (head_f->n > next->n)/*si la valeur de mon noeud
								est plus grande que celle du noeud suivant*/
		{
			swap(head_f, next, list);/*on échange les noeuds*/
			print_list(*list);/*on imprime*/
			head_b = next;/*next a reculé, on doit le comparer à ses prédécésseurs
						on se cale sur lui désormais*/
			while (head_b->prev != NULL)/*tant qu'il y a un noeud précédent on peu comparer*/
			{
				prev = head_b->prev; 
				if (prev->n > head_b->n)/*si la valeur du noeud précédent est plus grande
										que le noeud qu'on lit*/
				{
					swap(prev, head_b, list);/*on les échange*/
					/*la fonction swap fait avancer le premier noeud, donc on change juste l'ordre*/
					/*list est important car le noeud qui recule devra peut être devenir la nouvelle tête !*/
					print_list(*list);
				}
				else
					break;/*si le noeud précédent est plus petit, il faut arrêter cette sous boucle
					et reprendre la première qui reprendra à la tête de lecture*/
			}
		}
		else
		{
			head_f = head_f->next;
		}
	}
}
