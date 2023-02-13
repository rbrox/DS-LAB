// Linkers
#include<stdio.h>
#include<stdlib.h>

// Global

#define VERTEX 2

int graph[VERTEX][VERTEX];
int stack[VERTEX];
int order[VERTEX];

// Prototypes
void bredth_first_traverse();

void graph_read()
{
    // Empty the graph
    for (int i = 0; i < VERTEX; ++i)
    {
        for (int j = 0; j < VERTEX; j++)
        {
            graph[i][j] = 0;
        }
    
    }

    // Enter connections
    for (int i = 0; i < VERTEX; ++i)
    {
        for (int j = 0; j < VERTEX; j++)
        {
            int boolean;
            printf("Enter whether %d & %d are connected: ", i + 1, j + 1 );
            scanf("%d", &boolean);

            if (boolean == 0)
            {
                graph[i][j] = 0;
            }
            else{
                graph[i][j] = 1;
            }
        }
    
    }

}

// Main
void main()
{
    graph_read();
    bredth_first_traverse();

    for (int i = 0; i < VERTEX; i++)
    {
        printf("%d\t", order[i]);
    }
   
    
}


// Declarations

void bredth_first_traverse()
{   
    // Pointers to keep track of the stack position 
    // and the graph position and the vertex visit count respectively
    int stack_ptr = -1;
    int graph_ptr = 0;
    int visit_rem = VERTEX;
    int visit_ptr = 0;
    // array keeping track of visited vertices
    int traversed[VERTEX];
    for (int i = 0; i < VERTEX; i++, traversed[i] = 0);
    // Going to the first vertice & updating traversed array
    stack[++stack_ptr] = graph_ptr;
    traversed[graph_ptr] = 1;
    order[visit_ptr] = graph_ptr;

    // Now while any adjascent vertices arent visited , visit them

    while(visit_rem)
    {
        // A switch variable which checks whether this pass found a new vertex
        int swt = 0;
        for(int i = 0; i < VERTEX; ++i)
        {
            // Cheking for a vertex which is connected to the graph_ptr and hasnt been visited
            if(graph[graph_ptr][i] == 1 && traversed[i] == 0)
            {
                // New vertex is added to stack, graph_ptr updated, visit_rem decreased
                graph_ptr = i;
                stack[++stack_ptr] = graph_ptr;
                traversed[graph_ptr] = 1;
                order[++visit_ptr] = graph_ptr;
                -- visit_rem;
                // We have reached a new vertex hence break out
                swt = 1;
                break;
            }
        }

        // pass didnt find new vertex, all adjascent vertices are travelled too
        if(!swt)
        {
            // pop ele from stack, go back to last element
            graph_ptr = stack[--stack_ptr];
        }
    }

}