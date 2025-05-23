#include "../head.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_strcpy(char *str, char *dest)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
}

int	ft_strncmp(char *avec_quoi, char *comparer, int nbr)
{
	int	i;

	i = 0;
	while (avec_quoi[i] != '\0' && avec_quoi[i] == comparer[i] && i != nbr)
		i++;
	if (comparer[i] == '\0')
		return (0);
	return (1);
}

void	ft_strncpy(char *str, char *dest, int index, int taille)
{
	int	i;

	i = 0;
	while (i != taille && str[index] != '\0')
	{
		dest[i] = str[index];
		i++;
		index++;
	}
	dest[i] = '\0';
}

void	ft_strcat(char *dest, char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (dest[i] != '\0')
		i++;
	while (str[c] != '\0')
	{
		dest[i] = str[c];
		c++;
		i++;
	}
	dest[i] = '\0';
}

int	ft_comparer(char *str, char *str2) // renvoie 1 si faux et 0 si juste
{
	int	i;

	i = 0;
	while (str2[i] != '\0' && str[i] != '\0' && str[i] == str2[i])
		i++;
	if (str[i] == '\0')
		return (0);
	if (str2[i] == '\0')
		return (0);
	return (1);
}

char	*create_string(char *str)
{
	int	i;
	char	*dest;

	i = 0;
	while (str[i] != '\0')
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
