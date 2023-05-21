#include "my_lemin.h"
#include "get_next_line.h"

int main()
{
    //char buffer[1024];
    //char **stock;
    /*penser a initialiser tout les bool a false*/
	t_parsing par;
    pars_init(&par);
    //t_node *root = NULL;
    //t_p *path = NULL;
   // t_p *rooms = NULL;
    t_store *store = NULL;
    //int head;
    storage(&store);
    print_store(store);
   // head = read(STDIN_FILENO, buffer, 1024);
    //printf("HEAD = %i\n", head);
    //stock = ft_split(buffer, '\n');
    //print_map(stock);
    printf("#########\n");
	//gestion d'erreur input a prevoir
    //int ants = stock[0][0] - '0';
    //par.ants = true;
	//int room_num = 0;
    //room_num += fill_rooms_start(&par, &rooms, stock, room_num);
    //room_num += fill_rooms(&par, &rooms, stock, room_num);
    //init_room_val(rooms);
    //printTree_path(rooms);
    //printf("nb rooms = %i\n", room_num);
    //find_start_end(&rooms, stock, room_num, "##start\n");
    //printTree_path(rooms);
    //find_start_end(root, stock, room_num, 's');
    //find_start_end(root, stock, room_num, 'e');
    //find_rooms(root, stock, room_num);
    //printTree(root);
    /*room_num--;
	t_matrix *g = create_matrix(room_num);
    find_links(rooms, g, stock);
	print_matrix(g);
	int p = find_node(root, 0);
	printf("%i \n", p);
	bool *visited = malloc(sizeof(bool) * room_num);
	int res = 0;
	res = nbpaths(&path, g, 0, 7, visited);
	printf("NB of paths = %i\n", res);
    //printf("path val = %i\n", path->val);
	printf("#########\n");
    printTree_path(path);
    int nb_paths = ants / res;
	printf("Rapport Ants / Rooms = %i\n", nb_paths);
	printf("NB of paths = %i\n", res);*/
    return (0);
}