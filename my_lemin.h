#ifndef MY_LEMIN_H_
# define MY_LEMIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define COUNT 10

int pos;
int nb;

typedef struct  s_matrix
{
    int room_nums;
	bool **m;
}		            t_matrix;

typedef struct s_parsing
{
	bool start;
	bool end;
	bool ants;
	bool rooms;
	bool empty;
}	             t_parsing;

typedef struct s_node
{
	int val;
    char pos;
    int key;
    char x;
    char y;
    int *neighboors;
    struct s_node *left;
    struct s_node *right;
}              t_node;

typedef struct s_p
{
	int val;
    char *room;
    struct s_p *next;
    struct s_p *prev;
}              t_p;

typedef struct s_store
{
	char   *line;
    struct s_store *next;
    struct s_store *prev;
}              t_store;

int	ft_putstr(char *s);
int	ft_strcmp(char *s1, char *s2);
int ft_strlen(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strrchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
size_t	word_count(char const *s, char c);
size_t	move_ptr(char const *s, size_t n, size_t *index, char c);
char	*word_dup(const char *str, int size);
char	**free_all(char **ptr, size_t count);
char	**ft_split(char const *s, char c);
t_matrix* create_matrix(int room_nums);
void	print_matrix(t_matrix *g);
bool add_link(t_matrix *g, int x, int y);
void addNode(t_node **tree, int key, char x, char y, char pos);
void addNode_path(t_p **tree, int key, char *room);
void printTree(t_node *tree);
void printTree_path(t_p *tree);
void print2D(t_node* root, int space);
int isin(char *str, char c);
int find_node(t_node* root, int key);
void DFS(t_p **root, t_matrix *g , int src, int dest, bool *v, int *path, int pathLen);
int nbpaths(t_p **root, t_matrix *g, int src, int dest, bool *v);
void find_rooms(t_node *root, char **stock, int room_num);
void find_links(t_p *rooms, t_matrix *g, char **stock);
int fill_rooms_start(t_parsing *par, t_p **rooms, char **stock, int room_num);
int fill_rooms(t_parsing *par, t_p **rooms, char **stock, int room_num);
int    print_map(char **stock);
void    pars_init(t_parsing *par);
void    init_room_val(t_p *rooms);
void    storage(t_store **store);
void addNode_store(t_store **tree, char *line);
void print_store(t_store *store);
#endif