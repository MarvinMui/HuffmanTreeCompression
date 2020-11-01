#ifndef __HUFFMAN_H_V1__
#define __HUFFMAN_H_V1__

typedef unsigned char uchar;
typedef long Frequencies[256];

typedef struct _NodeL {
	void* a_value;
	struct _NodeL* next;
} NodeL;

typedef struct _Node {
	char value;
	struct _Node* next;
} Node;

typedef struct _Tnode {
	uchar value;
	long frequency;
	struct _Tnode* left;
	struct _Tnode* right;
} Tnode;

Node* add_node(Node* tail, char value);
void destroy_nodes(Node* head);
void destroy_tree(Tnode** root);
Node* topology_reader(char* filename);
int write_nodes(Node* head, char* filename);
Tnode* build_tree_from_topology(Node** head);
long decode_from_tree(char* read_file, char* write_file, Tnode* root, Frequencies freqs);
int write_freqs(char* filename, Frequencies freqs);
void add_node_in_order(NodeL** a_head, void* a_value, int (*comp_funct)(const void*, const void*));
int tree_comp_func(const void* head, const void* new);
NodeL* make_huffman_list(Frequencies freqs);
Tnode* make_huffman_tree(NodeL* head);
void write_tree(FILE* fp, Tnode* root);
void count_huff_bits(Frequencies freqs, Tnode* root, long stacks);
int write_bits(char* filename, long bits, long huff_bits);
long add_up_bits(Frequencies freqs, Frequencies num_of_bits);

#endif
