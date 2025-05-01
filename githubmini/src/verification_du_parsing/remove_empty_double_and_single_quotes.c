#include "../head.h"

int  remove_node(t_line **head, t_line *node)
{
  t_line *prev;
  t_line *next;

	if (head == NULL || *head == NULL || node == NULL)
		return (1);
  else if (node->prev == NULL && node->next != NULL)
	{
		next = node->next;
		next->prev = NULL;
		*head = next;
	}
	else if(node->next == NULL && node->prev != NULL)
	{
		prev = node->prev;
		prev->next = NULL;
	}
	else if (node->next != NULL && node->prev != NULL)
  {
		next = node->next;
		prev = node->prev;
		prev->next = next;
		next->prev = prev;
	}
	else if (node->next == NULL && node->prev == NULL)
		return (2);
	free(node->valeur);
	node->valeur = NULL;
  free(node);
	return (0);
}

//On va enlver les double quotes qui sont vides donc free ce noeud et coller les noeuds qui sont a coter
int remove_empty_double_and_single_quotes(t_line **head)
{
	t_line *prev;
  t_line *node;
	int	cas;

  node = *head;
  if (*head == NULL)
		return (1);
	while (node != NULL)
  {
    if (node->valeur[0] == '\0' && (node->type == TOKEN_DOUBLE_QUOTES || node->type == TOKEN_SINGLE_QUOTES))
    {
			prev = node->prev;
      cas = remove_node(head, node);
			if (cas == 1)
			{
				printf("ERROR : Probleme de *head ou head ou node qu ils sont NULL normalement jamais doit arriver\n");
				return (1);
			}
			if (cas == 2)
			{
				printf("zch: permission denier:\n");
				return (1);
			}
			node = prev;
		}
		else
			node = node->next;
	}
	return (0);
}
