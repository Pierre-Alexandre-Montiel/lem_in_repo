#include "my_lemin.h"
#include "get_next_line.h"

t_matrix* create_matrix(int room_nums)
{
	t_matrix *g = malloc(sizeof(*g));
	if (g == NULL)
		return NULL;
	g->room_nums = room_nums;
	g->m = malloc(sizeof(bool*) * g->room_nums);
	for (int i = 0; i < g->room_nums; i++)
	{
		g->m[i] = malloc(sizeof(bool) * g->room_nums);
		if (g->m[i] == NULL)
		{
			free(g);
			return NULL;
		}
	}
	return g;	
}

int	ft_putstr(char *s)
{
    int res = 0;
	res = write(1, s, ft_strlen(s));
    return res;
}

int    print_map(char **stock)
{
    int i = 0;
    int res = 0;
    while (stock[i] != NULL)
    {
        ft_putstr(stock[i]);
        res = write(1, "\n", 1);
        i++;
    }
    return res;
}

void	print_matrix(t_matrix *g)
{
	printf("  0 1 2 3 4 5 6 7\n");
	for (int i = 0; i < g->room_nums; i++)
	{
		printf("%i ", i);
		for (int j = 0; j < g->room_nums; j++)
		{
			printf("%i ", g->m[i][j]);
		}
		printf("\n");
	}
}

bool add_link(t_matrix *g, int x, int y)
{
    printf("%i, %i\n", x, y);
	g->m[x][y] = true;
	return true;
}

void addNode(t_node **tree, int key, char x, char y, char pos)
{
    t_node *tmpNode;
    t_node *tmpTree = *tree;

    t_node *elem = malloc(sizeof(t_node));
    elem->key = key;
    elem->x = x;
    elem->y = y;
    elem->pos = pos;
    elem->left = NULL;
    elem->right = NULL;

    if(tmpTree)
    do
    {
        tmpNode = tmpTree;
        if(key > tmpTree->key)
        {
            tmpTree = tmpTree->right;
            if(!tmpTree)
            {
                printf("Hello\n");
                tmpNode->right = elem;
            }
        }
        else
        {
            tmpTree = tmpTree->left;
            if(!tmpTree) 
            {
                printf("IS\n");
                tmpNode->left = elem;
            }
        }
    }
    while(tmpTree);
    else  *tree = elem;
}

void addNode_path(t_p **tree, int key, char *room)
{
    t_p *element = malloc(sizeof(t_p));
    /*if(!element) 
        return(NULL);*/     /* Si l'allocation a échoué. */
    element->val = key;
    element->room = room;
    element->next = *tree;
    *tree = element;
}

void addNode_store(t_store **tree, char *line)
{
    printf("LINE = %s\n", line);
    t_store *element = malloc(sizeof(t_store));
    if(!element) 
        exit(1);    /* Si l'allocation a échoué. */
    element->line = line;
    element->next = *tree;
    *tree = element;
}

void printTree(t_node *tree)
{
    printf("PRINTTREE\n");
    if(!tree)
    {
        printf("return\n");
        return;
    }
    if(tree->left)
    {
        printf("left\n");
        printTree(tree->left);
    }
    printf("key = %i\n", tree->key);
    //printf("Coor x = %c\n", tree->x);
    //printf("Coor y = %c\n", tree->y);
    //printf("Pos = %c\n", tree->pos);
    if(tree->right)
    {
        printf("right\n");
        printTree(tree->right);
    }
}

void printTree_path(t_p *tree)
{
    /*if(!tree)
    {
        return;
    }*/
    while (tree != NULL)
    {
        printf("val = %i\n", tree->val);
        printf("room = %s\n", tree->room);
        tree = tree->next;
    }
}

void print_store(t_store *store)
{
    /*if(!tree)
    {
        return;
    }*/
    while (store != NULL)
    {
        printf("store = %s\n", store->line);
        store = store->next;
    }
}

void print2D(t_node* root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    space += COUNT;
 
    print2D(root->left, space);
 
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%i\n", root->key);
    print2D(root->right, space);
}

int isin(char *str, char c)
{
    int i= 0;
    while (str[i] != '\0')
    {
        if (str[i] == c)
            return 1;
        i++;
    }
    return 0;
}

int find_node(t_node* root, int key)
{
    if (root == NULL)
        return 0;
    if (root->key == key)
        return pos;
    find_node(root->left, key);
    find_node(root->right, key);
	pos++;
    return pos;
}

void find_rooms(t_node *root, char **stock, int room_num)
{
    int i = 1;
    while (stock[i] != NULL)
    {
        printf("%s\n", stock[i]);
        if (isin(stock[i], '-') == 0 && isin(stock[i], '#') == 0)
        {
            char **tmp = ft_split(stock[i], ' ');
            addNode(&root, i, tmp[1][0], tmp[2][0], 'm');
			room_num++;
        }
        i++;
    }
}

int find_val_room(t_p *rooms, char *str)
{
    while (rooms != NULL)
    {            
        printf("ROOM name = %s\n", rooms->room);
        printf("STR = %s\n", str);
        printf("strcmp = %i\n", ft_strcmp(str, rooms->room));
        if (ft_strcmp(str, rooms->room) == 0)
        {

            return rooms->val;
        }
        rooms = rooms->next;
    }
    return 0;
}

void    init_room_val(t_p *rooms)
{
    int i = 1;
    while (rooms != NULL)
    {
        if (rooms->val)
            rooms->val = i;
        rooms = rooms->next;
        i++;
    }
}

void find_links(t_p *rooms, t_matrix *g, char **stock)
{
    int i = 1;
    while (stock[i] != NULL)
	{
		if (isin(stock[i], '-') == 1)
        {
            char **tiret = ft_split(stock[i], '-');
            printf("tiret0 = %s\n", tiret[0]);
            printf("tiret1 = %s\n", tiret[1]);
            int x = find_val_room(rooms, tiret[0]);
            int y = find_val_room(rooms, tiret[1]);
            printf("x = %i\n", x);
            printf("y = %i\n", y);
			add_link(g, x, y);
			add_link(g, y, x);
        }
		i++;
	}
}

void    pars_init(t_parsing *par)
{
    par->ants = false;
    par->rooms = false;
    par->start = false;
    par->end = false;
    par->empty = false;
}

int fill_rooms_start(t_parsing *par, t_p **rooms, char **stock, int room_num)
{
    int i = 1;
	while (stock[i] != NULL)
	{
		if (isin(stock[i], '-') == 0 && isin(stock[i], '#') == 1) 
		{
            // faire un strcmp plutot 
			if (isin(stock[i], 's') == 1)
			{
				char **s = ft_split(stock[i + 1], ' ');
				addNode_path(rooms, 0, s[0]);
				stock[i + 1] = "#";
				room_num++;
                par->start = true;
			}
        }
		i++;
	}
	return room_num;
}

int fill_rooms(t_parsing *par, t_p **rooms, char **stock, int room_num)
{
    int i = 1;
	while (stock[i] != NULL)
	{
		if (isin(stock[i], '-') == 0 && isin(stock[i], '#') == 1) 
		{
            // faire un strcmp plutot 
            if (isin(stock[i], 'e') == 1)
			{
				char **s = ft_split(stock[i + 1], ' ');
				addNode_path(rooms, 1, s[0]);
				stock[i + 1] = "#";
				room_num++;
                par->end = true;
			}
        }
        else if (isin(stock[i], '-') == 0 && isin(stock[i], '#') == 0)
        {
            char **tmp = ft_split(stock[i], ' ');
			addNode_path(rooms, 1, tmp[0]);
		    room_num++;
            par->rooms = true;
        }
		i++;
	}
	return room_num;
}

void storage(t_store **store)
{
    int i = 0;
    int ret = 0;
    char *buff;
    char *res;
	while ((ret = get_next_line(STDIN_FILENO, &buff)) > 0)
	{
        res = buff;
		addNode_store(store, res);
        i++;
		free(buff);
	}
}