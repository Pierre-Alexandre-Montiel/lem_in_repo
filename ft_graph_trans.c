#include "my_lemin.h"


void DFS(t_p **root, t_matrix *g , int src, int dest, bool *v, int *path, int pathLen)
{
	if (src == dest)
	{
		//printf("SRC=DEST = %i %i\n", src, dest);
		nb++;
		for (int i = 0; i < pathLen; i++)
        {
            printf("%i -> ", path[i]);
        }
        printf("%i\n", dest);
		v[dest] = false;
		//printf("NB value = %i\n", nb);
		//printf("%i -> ", src);
		//printf("\n");
		return;
	}
    //v[src] = true;
	v[src] = true;
    path[pathLen] = src;
    pathLen++;
    for (int i = 0; i < g->room_nums; i++) 
	{
        if (v[i] == false && g->m[src][i] == true) 
		{
            //addNode_path(root, src);

			//v[i] = true;
        	//addNode_path(root, i);
			//printf("v[i] = %i\n", i);
            DFS(root, g, i, dest, v, path, pathLen);
        }
    }
	//printf("SOURCE = %i\n", src);
	v[src]= false;
    pathLen--;
}

int nbpaths(t_p **root, t_matrix *g, int src, int dest, bool *v)
{
 	int *path = (int *)malloc(g->room_nums * sizeof(int));
    int pathLen = 0;
    for (int i = 0; i < g->room_nums; i++) 
	{
        if (i == src) 
		{
			//printf("SRC = %i\n", i);
			v[src] = true;
            DFS(root, g, src, dest, v, path, pathLen);
			//printf("NB value oput = %i\n", nb);
        }
    }
	return nb;
}